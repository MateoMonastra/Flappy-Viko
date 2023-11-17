#pragma once

#include "ProgramUtilities/Utilities.h"

namespace flappybird
{
	namespace game
	{
		struct Obstacle
		{
			Rectangle topPart = {};
			Rectangle middleSpace = {};
			Rectangle lowPart = {};

			Color color = { RED };

			float velocity = { 160 };

			bool isOnScreen = false;

			const float MAX_OBSTACLES = 10.0f;
			const float MAX_PIPES_IN_SCREEN = 1.0f;
		};
	
		void ObstacleUpdate(Obstacle obstacle[]);
		void ObstacleDraw(Obstacle obstacle[]);
		void InitObstacle(Obstacle obstacle[]);
	}
}

