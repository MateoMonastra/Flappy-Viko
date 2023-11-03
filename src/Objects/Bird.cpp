#include "Bird.h"

namespace flappybird
{
	namespace game
	{
		void BirdUpdate(Bird& player)
		{
			if (IsKeyDown(KEY_RIGHT)) player.hitBox.x += 200.0f * GetFrameTime();
			if (IsKeyDown(KEY_LEFT)) player.hitBox.x -= 200.0f * GetFrameTime();
			if (IsKeyDown(KEY_UP)) player.hitBox.y -= 200.0f * GetFrameTime();
			if (IsKeyDown(KEY_DOWN)) player.hitBox.y += 200.0f * GetFrameTime();
		}

		void BirdDraw(Bird player)
		{
			DrawRectangleRec(player.hitBox,player.color);
		}

		void InitBird(Bird& player)
		{
			player.hitBox = { static_cast<float>(GetScreenWidth()) / 2, static_cast<float>(GetScreenHeight()) / 2 , 30, 30};
		}
	}
}