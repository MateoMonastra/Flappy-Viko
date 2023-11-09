#pragma once

#include "ProgramUtilities/Utilities.h"

namespace flappybird
{
	namespace game
	{
		struct Bird
		{
			Rectangle hitBox = {};
			Color color = {RED};

			float speed = { 200 };
		};
	
		void BirdUpdate(Bird& player);
		void BirdDraw(Bird player);
		void InitBird(Bird& player);
	
	}
}