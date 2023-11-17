#include "Obstacles.h"


namespace flappybird
{
	namespace game
	{
		static void CreateObstacle(Obstacle  obstacle[]);

		int obstacleCounter = 0;
		int currentObstacle = 0;

		void ObstacleUpdate(Obstacle obstacle[])
		{

			for (int i = 0; i < obstacle[i].MAX_OBSTACLES; i++)
			{
				if (obstacle[i].isOnScreen)
				{
					obstacle[i].topPart.x -= obstacle[i].velocity * GetFrameTime();
					obstacle[i].lowPart.x -= obstacle[i].velocity * GetFrameTime();
					obstacle[i].middleSpace.x -= obstacle[i].velocity * GetFrameTime();

					if (obstacle[i].middleSpace.x + obstacle[i].middleSpace.width < 0)
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
					DrawRectangleRec(obstacle[i].topPart, obstacle[i].color);
					DrawRectangleRec(obstacle[i].lowPart, obstacle[i].color);
					DrawRectangleRec(obstacle[i].middleSpace, obstacle[i].color);
				}
			}
		}

		void InitObstacle(Obstacle obstacle[])
		{
			for (int i = 0; i < obstacle[i].MAX_OBSTACLES; i++)
			{
				obstacle[i].isOnScreen = false;
			}
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
		
			for (int i = 0; i < obstacle[i].MAX_OBSTACLES; i++)
			{
				if (!obstacle[i].isOnScreen && obstacle[i].MAX_PIPES_IN_SCREEN > obstacleCounter)
				{

					obstacle[i].middleSpace = { static_cast<float>(GetScreenWidth()) + obstacle[i].middleSpace.width,  static_cast<float>(GetRandomValue(300,500)), 30,  static_cast<float>(GetRandomValue(80,100))};
					
					obstacle[i].topPart = { obstacle[i].middleSpace.x , 0, 30, obstacle[i].middleSpace.y };

					obstacle[i].lowPart = { obstacle[i].middleSpace.x , obstacle[i].middleSpace.y + obstacle[i].middleSpace.height, 30, static_cast<float>(GetScreenHeight())};

					obstacle[i].isOnScreen = true;
				}
			}
		}
	
	}
}