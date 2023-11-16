#include "Game.h"

#include "ProgramUtilities/Utilities.h"

#include "Objects/Bird.h"
#include "Objects/Obstacles.h"

namespace flappybird
{
	namespace game
	{
		const int MAX_OBSTACLES = 10;

		Bird player;
		Obstacle obstacle[MAX_OBSTACLES];

		Sprite BackgroundLayer1;
		Sprite BackgroundLayer2;

		Sprite BackgroundLayer3_1;
		Sprite BackgroundLayer3_2;

		Sprite BackgroundLayer4_1;
		Sprite BackgroundLayer4_2;

		Sprite BackgroundLayer5_1;
		Sprite BackgroundLayer5_2;


		static void GameColitions(Screen& currentScene);
		static void DrawParallax();
		static void UpdateParallax();
		static void UpdateLayer(Sprite& layer);
		static void InitParallax();

		void GameUpdate(Screen& currentScene)
		{
			BirdUpdate(player);
			
			ObstacleUpdate(obstacle);
			
			GameColitions(currentScene);

			UpdateParallax();
			
			if (IsKeyDown(KEY_ESCAPE))
			{
				currentScene = Screen::Menu;
			}
		}

		void DrawGame()
		{
			DrawParallax();
			BirdDraw(player);
			ObstacleDraw(obstacle);
			DrawText("Press Esc to return Menu", GetScreenWidth() - 300, 20, 20, BLACK);
		}

		void InitGame()
		{
			InitBird(player);
			InitObstacle(obstacle);
			InitParallax();
		}

		
		void InitParallax()
		{
			float scale = 0.7f;
			int distanceBugFix = 6;

			BackgroundLayer1.texture = LoadTexture("res/game/background/layer_1.png");
			BackgroundLayer1.scale = scale;
			BackgroundLayer1.position = {0,0};

			BackgroundLayer2.texture = LoadTexture("res/game/background/layer_2.png");
			BackgroundLayer2.scale = scale;
			BackgroundLayer2.position = { 0,0 };

			BackgroundLayer3_1.texture = LoadTexture("res/game/background/layer_3.png");
			BackgroundLayer3_1.scale = scale;
			BackgroundLayer3_1.velocity = 30;
			BackgroundLayer3_1.position = { 0,0 };

			BackgroundLayer3_2.texture = LoadTexture("res/game/background/layer_3.png");
			BackgroundLayer3_2.scale = scale;
			BackgroundLayer3_2.velocity = 30;
			BackgroundLayer3_2.position.x = (static_cast<float>(BackgroundLayer3_1.texture.width) * BackgroundLayer3_1.scale) / distanceBugFix + static_cast<float>(GetScreenWidth());

			BackgroundLayer4_1.texture = LoadTexture("res/game/background/layer_4.png");
			BackgroundLayer4_1.scale = scale;
			BackgroundLayer4_1.velocity = 60;
			BackgroundLayer4_1.position = { 0,0 };

			BackgroundLayer4_2.texture = LoadTexture("res/game/background/layer_4.png");
			BackgroundLayer4_2.scale = scale;
			BackgroundLayer4_2.velocity = 60;
			BackgroundLayer4_2.position.x = (static_cast<float>(BackgroundLayer4_1.texture.width) * BackgroundLayer4_1.scale) / distanceBugFix + static_cast<float>(GetScreenWidth());

			BackgroundLayer5_1.texture = LoadTexture("res/game/background/layer_5.png");
			BackgroundLayer5_1.scale = scale;
			BackgroundLayer5_1.velocity = 100;
			BackgroundLayer5_1.position = { 0,0 };

			BackgroundLayer5_2.texture = LoadTexture("res/game/background/layer_5.png");
			BackgroundLayer5_2.scale = scale;
			BackgroundLayer5_2.velocity = 100;
			BackgroundLayer5_2.position.x = (static_cast<float>(BackgroundLayer5_1.texture.width) * BackgroundLayer5_1.scale) / distanceBugFix + static_cast<float>(GetScreenWidth());
		}


		static void GameColitions(Screen& currentScene)
		{
			for (int i = 0; i < obstacle[i].MAX_OBSTACLES; i++)
			{
				if (obstacle[i].isOnScreen)
				{
					if (CheckCollisionRecs(player.hitBox, obstacle[i].hitBox))
					{
						currentScene = Screen::Menu;
					}
				}
			}
			if (player.hitBox.y + player.hitBox.height > GetScreenHeight() - player.hitBox.height)
			{
				InitBird(player);
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

			if (layer.position.x + layer.texture.width * layer.scale < 0)
			{
				layer.position.x = static_cast<float>(GetScreenWidth());
			}
		}
	}
}