#include "Bird.h"

namespace flappybird
{
	namespace game
	{
		void BirdUpdate(Bird& player)
		{
			if (player.hitBox.y - player.hitBox.height > 0)
			{
				if (IsKeyPressed(KEY_UP))
				{
					player.velocity.y = (player.aceleration);
				}
				else
				{
					player.velocity.y += player.gravity * GetFrameTime();

					if (player.velocity.y > player.TERMINAL_VELOCITY)
					{
						player.velocity.y = player.TERMINAL_VELOCITY;
					}
				}
			}
			else
			{
				player.velocity.y += player.gravity * GetFrameTime();

				if (player.velocity.y > player.TERMINAL_VELOCITY)
				{
					player.velocity.y = player.TERMINAL_VELOCITY;
				}
			}

			player.hitBox.y += player.velocity.y * GetFrameTime();
		}

		void BirdDraw(Bird player)
		{
			DrawRectangleRec(player.hitBox, player.color);
		}

		void InitBird(Bird& player)
		{
			player.hitBox = { static_cast<float>(GetScreenWidth()) / 2 - 100, static_cast<float>(GetScreenHeight()) / 2 , 30, 30 };
		}
	}
}