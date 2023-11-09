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

		static void GameColitions();

		void GameUpdate()
		{
			BirdUpdate(player);
			ObstacleUpdate(obstacle);
			GameColitions();
		}

		void DrawGame()
		{
			BirdDraw(player);
			ObstacleDraw(obstacle);
			DrawText("0.1", 20, 20, 40, WHITE);
		}

		void InitGame()
		{
			InitBird(player);
			InitObstacle(obstacle);
		}


		static void GameColitions()
		{

			if (CheckCollisionRecs(player.hitBox, obstacle.hitBox))
			{
				InitGame();
			}

		}
	}
}