#include "Obstacles.h"

namespace flappybird
{
	namespace game
	{
		void ObstacleUpdate(Obstacle& obstacle)
		{
			obstacle.hitBox.x -= obstacle.speed * GetFrameTime();

			if (obstacle.hitBox.x <= 0)
			{
				float randomY = static_cast<float>(GetRandomValue(0, GetScreenHeight()));

				while (randomY < obstacle.hitBox.height)
				{
					randomY = static_cast<float>(GetRandomValue(0, GetScreenHeight()));
				}

				obstacle.hitBox.x = {static_cast<float>(GetScreenWidth()) + 50};
				obstacle.hitBox.y = randomY;
			}
		}
		void ObstacleDraw(Obstacle obstacle)
		{
			DrawRectangleRec(obstacle.hitBox, obstacle.color);
		}
		void InitObstacle(Obstacle& obstacle)
		{
			obstacle.hitBox = { static_cast<float>(GetScreenWidth()) + 50, static_cast<float>(GetRandomValue(0,GetScreenHeight())) , 30, 150 };
		}
	}
}