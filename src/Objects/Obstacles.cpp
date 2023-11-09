#include "Obstacles.h"

namespace flappybird
{
	namespace game
	{
		void ObstacleUpdate(Obstacle& obstacle)
		{
			obstacle.hitBox.x -= obstacle.speed * GetFrameTime();

			if (obstacle.hitBox.x + obstacle.hitBox.width <= 0)
			{

				obstacle.hitBox.x = { static_cast<float>(GetScreenWidth()) + 50 };
				obstacle.hitBox.y = {static_cast<float>(GetRandomValue(0, GetScreenHeight() - static_cast<int>(obstacle.hitBox.height)))};
			}
		}
		void ObstacleDraw(Obstacle obstacle)
		{
			DrawRectangleRec(obstacle.hitBox, obstacle.color);
		}
		void InitObstacle(Obstacle& obstacle)
		{
			obstacle.hitBox = { static_cast<float>(GetScreenWidth()) + 50, static_cast<float>(/*GetRandomValue(0,*/GetScreenHeight()) - /*static_cast<int>*/(obstacle.hitBox.height) , 30, 150 };
		}
	}
}