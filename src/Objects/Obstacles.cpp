#include "Obstacles.h"



namespace flappybird
{
	namespace game
	{
		static void CreateObstacle(Obstacle  obstacle[]);

		bool noObstacles = true;
		int obstacleCounter = 0;
		int currentObstacle = 0;

		void ObstacleUpdate(Obstacle obstacle[])
		{

			for (int i = 0; i < obstacle[i].MAX_OBSTACLES; i++)
			{
				if (obstacle[i].isOnScreen)
				{
					obstacle[i].hitBox.x -= obstacle[i].velocity * GetFrameTime();

					if (obstacle[i].hitBox.x + obstacle[i].hitBox.width <= 0)
					{
						obstacle[i].isOnScreen = false;
					}
				}

				CreateObstacle(obstacle);
			}
		}




		void ObstacleDraw(Obstacle obstacle[])
		{
			for (int i = 0; i < obstacle[i].MAX_OBSTACLES; i++)
			{
				if (obstacle[i].isOnScreen)
				{
					DrawRectangleRec(obstacle[i].hitBox, obstacle[i].color);
				}
			}
		}

		void InitObstacle(Obstacle obstacle[])
		{
			for (int i = 0; i < obstacle[i].MAX_OBSTACLES; i++)
			{
				obstacle[i].isOnScreen = false;
			}

			CreateObstacle(obstacle);
		}
	
		static void CreateObstacle(Obstacle  obstacle[])
		{
			obstacleCounter = 0;

			for (int i = 0; i < obstacle[i].MAX_OBSTACLES; i++)
			{
				if (obstacle[i].isOnScreen)
				{
					obstacleCounter++;
				}
			}
			if (obstacleCounter == 0)
			{
				noObstacles = true;
			}
			else
			{
				noObstacles = false;
			}


			if (!obstacle[currentObstacle].isOnScreen && noObstacles)
			{

				obstacle[currentObstacle].hitBox = { static_cast<float>(GetScreenWidth()) + obstacle[currentObstacle].hitBox.width,  static_cast<float>(GetRandomValue(-400,-100) - static_cast<int>(obstacle[currentObstacle].hitBox.height)), 30, 500};
				obstacle[currentObstacle].isOnScreen = true;
				
				currentObstacle++;

				if (currentObstacle > obstacle[0].MAX_OBSTACLES - 1)
				{
					currentObstacle = 0;
				}

				int previus = currentObstacle - 1;
				
				obstacle[currentObstacle].hitBox = { obstacle[previus].hitBox.x ,obstacle[previus].hitBox.y + obstacle[previus].hitBox.height + static_cast<float>(GetRandomValue(100,140)),  30, 200 };
				obstacle[currentObstacle].isOnScreen = true;
				
				currentObstacle++;

				if (currentObstacle > obstacle[0].MAX_OBSTACLES - 1)
				{
					currentObstacle = 0;
				}
			}
		}
	
	}
}