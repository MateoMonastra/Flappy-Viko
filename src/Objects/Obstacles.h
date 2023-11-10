#pragma once

#include "ProgramUtilities/Utilities.h"

namespace flappybird
{
	namespace game
	{
		struct Obstacle
		{
			Rectangle hitBox = {};
			Color color = { RED };

			float velocity = { 160 };

			bool isOnScreen = false;
		};
	
		void ObstacleUpdate(Obstacle& obstacle);
		void ObstacleDraw(Obstacle obstacle);
		void InitObstacle(Obstacle& obstacle);
	}
}

