#include "Game.h"

#include "ProgramUtilities/Utilities.h"

#include "Objects/Bird.h"
#include "Objects/Obstacles.h"

namespace flappybird
{
	namespace game
	{
		Bird player;
		Obstacle obstacle;

		Sprite BackgroundLayer1;
		Sprite BackgroundLayer2;

		Sprite BackgroundLayer3_1;
		Sprite BackgroundLayer3_2;

		Sprite BackgroundLayer4_1;
		Sprite BackgroundLayer4_2;

		Sprite BackgroundLayer5_1;
		Sprite BackgroundLayer5_2;


		static void GameColitions();
		static void DrawParallax();
		static void UpdateParallax();
		static void UpdateLayer(Sprite& layer);

		void GameUpdate()
		{
			BirdUpdate(player);
			ObstacleUpdate(obstacle);
			GameColitions();
			UpdateParallax();
		}

		void DrawGame()
		{
			DrawParallax();
			BirdDraw(player);
			ObstacleDraw(obstacle);
			DrawText("0.2", GetScreenWidth() - 60, GetScreenHeight() - 60, 40, WHITE);
		}

		void InitGame()
		{
			InitBird(player);
			InitObstacle(obstacle);

			BackgroundLayer1.texture = LoadTexture("res/background/layer_1.png");
			BackgroundLayer1.scale = 0.5f;

			BackgroundLayer2.texture = LoadTexture("res/background/layer_2.png");
			BackgroundLayer2.scale = 0.5f;

			BackgroundLayer3_1.texture = LoadTexture("res/background/layer_3.png");
			BackgroundLayer3_1.scale = 0.5f;
			BackgroundLayer3_1.velocity = 30;

			BackgroundLayer3_2.texture = LoadTexture("res/background/layer_3.png");
			BackgroundLayer3_2.scale = 0.5f;
			BackgroundLayer3_2.velocity = 30;
			BackgroundLayer3_2.position.x += (static_cast<float>(BackgroundLayer3_1.texture.width) * BackgroundLayer3_1.scale) /2 + static_cast<float>(GetScreenWidth());

			BackgroundLayer4_1.texture = LoadTexture("res/background/layer_4.png");
			BackgroundLayer4_1.scale = 0.5f;
			BackgroundLayer4_1.velocity = 60;

			BackgroundLayer4_2.texture = LoadTexture("res/background/layer_4.png");
			BackgroundLayer4_2.scale = 0.5f;
			BackgroundLayer4_2.velocity = 60;
			BackgroundLayer4_2.position.x += (static_cast<float>(BackgroundLayer4_1.texture.width) * BackgroundLayer4_1.scale) / 2 + static_cast<float>(GetScreenWidth());

			BackgroundLayer5_1.texture = LoadTexture("res/background/layer_5.png");
			BackgroundLayer5_1.scale = 0.5f;
			BackgroundLayer5_1.velocity = 100;

			BackgroundLayer5_2.texture = LoadTexture("res/background/layer_5.png");
			BackgroundLayer5_2.scale = 0.5f;
			BackgroundLayer5_2.velocity = 100;
			BackgroundLayer5_2.position.x += (static_cast<float>(BackgroundLayer5_1.texture.width) * BackgroundLayer5_1.scale) / 2 + static_cast<float>(GetScreenWidth());
		}


		static void GameColitions()
		{

			if (CheckCollisionRecs(player.hitBox, obstacle.hitBox))
			{
				InitBird(player);
				InitObstacle(obstacle);
			}

		}

		static void DrawParallax()
		{
			DrawSprite(BackgroundLayer1);
			DrawSprite(BackgroundLayer2);
			DrawSprite(BackgroundLayer3_1);
			DrawSprite(BackgroundLayer3_2);
			DrawSprite(BackgroundLayer4_1);
			DrawSprite(BackgroundLayer4_2);
			DrawSprite(BackgroundLayer5_1);
			DrawSprite(BackgroundLayer5_2);
		}

		static void UpdateParallax()
		{
			UpdateLayer(BackgroundLayer3_1);
			UpdateLayer(BackgroundLayer3_2);
			UpdateLayer(BackgroundLayer4_1);
			UpdateLayer(BackgroundLayer4_2);
			UpdateLayer(BackgroundLayer5_1);
			UpdateLayer(BackgroundLayer5_2);
		}

		static void UpdateLayer(Sprite& layer)
		{
			layer.position.x -= layer.velocity * GetFrameTime();

			if (layer.position.x + layer.texture.width < 0)
			{
				layer.position.x = static_cast<float>(GetScreenWidth()) + (static_cast<float>(layer.texture.width) * layer.scale) / 2;
			}
		}
	}
}