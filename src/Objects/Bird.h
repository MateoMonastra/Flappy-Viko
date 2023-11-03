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
		};
	
		void BirdUpdate(Bird& player);
		void BirdDraw(Bird player);
		void InitBird(Bird& player);
	
	}
}