#pragma once

#include "ProgramUtilities/Utilities.h"

namespace flappybird
{
	namespace game
	{
		struct Bird
		{
			const float SPRITE_SIZE = 70;
			Texture2D texture = {};
			Rectangle dest = { 0, 0, SPRITE_SIZE, SPRITE_SIZE };
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