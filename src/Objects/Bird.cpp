#include "Bird.h"

namespace flappybird
{
	namespace game
	{
		void BirdUpdate(Bird& player)
		{
			if (IsKeyDown(KEY_UP)) player.hitBox.y -= player.speed * GetFrameTime();
			if (IsKeyDown(KEY_DOWN)) player.hitBox.y += player.speed * GetFrameTime();
		}

		void BirdDraw(Bird player)
		{
			DrawRectangleRec(player.hitBox,player.color);
		}

		void InitBird(Bird& player)
		{
			player.hitBox = { static_cast<float>(GetScreenWidth()) / 2 - 400, static_cast<float>(GetScreenHeight()) / 2 , 30, 30};
		}
	}
}