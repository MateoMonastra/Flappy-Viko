#pragma once

#include "ProgramUtilities/Utilities.h"

namespace flappybird
{
	namespace game
	{
		struct Bird
		{
			Texture2D texture = {};
			Rectangle dest = {0,0,70,70};
			Rectangle source = {};
			Vector2 origin = {};

			float rotation = {};

			Rectangle hitBox = {};
			Color color = { WHITE };

			Vector2 velocity = { 0,0 };

			const float TERMINAL_VELOCITY = 400;
			float gravity = { 300 };

			float aceleration = {-250};
		};
	
		void BirdUpdate(Bird& player);
		void BirdDraw(Bird player);
		void InitBird(Bird& player);
	
	}
}