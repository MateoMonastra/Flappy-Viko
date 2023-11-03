#include "Obstacles.h"

namespace flappybird
{
	namespace game
	{
		void ObstacleUpdate(Obstacle& obstacle)
		{
			obstacle.hitBox.x -= 50 * GetFrameTime();

			if (obstacle.hitBox.x <= 0)
			{
				obstacle.hitBox.x = static_cast<float>(GetScreenWidth()) + 50;
				obstacle.hitBox.y = static_cast<float>(GetRandomValue(0, GetScreenHeight()));
			}
		}
		void ObstacleDraw(Obstacle obstacle)
		{
			DrawRectangleRec(obstacle.hitBox,obstacle.color);
		}
		void InitObstacle(Obstacle& obstacle)
		{
			obstacle.hitBox = { static_cast<float>(GetScreenWidth()) + 50, static_cast<float>(GetRandomValue(0,GetScreenHeight())) , 30, 80 };
		}
	}
}