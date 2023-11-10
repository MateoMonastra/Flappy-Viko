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
		Sprite BackgroundLayer3;
		Sprite BackgroundLayer4;
		Sprite BackgroundLayer5;


		static void GameColitions();
		static void DrawParallax();
		/*static void UpdateParallax();*/

		void GameUpdate()
		{
			BirdUpdate(player);
			ObstacleUpdate(obstacle);
			GameColitions();
		}

		void DrawGame()
		{
			DrawParallax();
			BirdDraw(player);
			ObstacleDraw(obstacle);
			DrawText("0.1", GetScreenWidth() - 60, GetScreenHeight() - 60, 40, WHITE);
		}

		void InitGame()
		{
			InitBird(player);
			InitObstacle(obstacle);

			BackgroundLayer1.texture = LoadTexture("res/background/layer_1");
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
		}

		/*static void UpdateParallax()
		{
		
		}*/
	}
}