#include "Bird.h"

namespace flappybird
{
	namespace game
	{

		float animationTimer = 0;

		void BirdUpdate(Bird& player)
		{
			float texturePos1 = player.texture.width / 4.0f;
			float texturePos2 = player.texture.width / 4.0f * 2.0f;

			const float animationCooldown = 0.3f;

			animationTimer += GetFrameTime();

			if (player.hitBox.y - player.hitBox.height > 0)
			{
				if (IsKeyPressed(KEY_UP) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT) )
				{
					player.velocity.y = (player.aceleration);
					player.rotation = player.TOP_ROTATION;

					if (animationTimer >= animationCooldown)
					{
						if (player.source.x == texturePos1)
						{
							player.source = { texturePos2,0,static_cast<float>(player.texture.width / 4),static_cast<float>(player.texture.height) };
						}

						animationTimer = 0;
					}
				}
				else
				{
					player.velocity.y += player.gravity * GetFrameTime();

					player.rotation += player.ROTATION_GRAVITY * GetFrameTime();

					if (player.rotation > player.LOWEST_ROTATION)
					{
						player.rotation = player.LOWEST_ROTATION;
					}

					if (player.velocity.y > player.TERMINAL_VELOCITY)
					{
						player.velocity.y = player.TERMINAL_VELOCITY;
					}

					if (animationTimer >= animationCooldown)
					{
						player.source = { texturePos1,0,static_cast<float>(player.texture.width / 4),static_cast<float>(player.texture.height) };
					}
				}
			}
			else
			{
				player.velocity.y += player.gravity * GetFrameTime();

				player.rotation += player.ROTATION_GRAVITY * GetFrameTime();
				
				if (player.rotation > player.LOWEST_ROTATION)
				{
					player.rotation = player.LOWEST_ROTATION;
				}

				if (player.velocity.y > player.TERMINAL_VELOCITY)
				{
					player.velocity.y = player.TERMINAL_VELOCITY;
				}
			}

			player.hitBox.y += player.velocity.y * GetFrameTime();
			player.dest = { player.hitBox.x + 20, player.hitBox.y, player.SPRITE_SIZE, player.SPRITE_SIZE};
		}

		void BirdDraw(Bird player)
		{
			DrawRectangleRec(player.hitBox, RED);
			DrawTexturePro(player.texture,player.source,player.dest,player.origin,player.rotation,player.color);
		}

		void InitBird(Bird& player)
		{
			Texture2D playerTexture = LoadTexture("res/game/bird/BirdMovement.png");

			player.hitBox = { static_cast<float>(GetScreenWidth()) / 2 - 160, static_cast<float>(GetScreenHeight()) / 2 , 30, 30 };
			player.velocity = {0,0};

			player.texture = playerTexture;
			player.rotation = 0;

			player.dest = { player.hitBox.x, player.hitBox.y, player.SPRITE_SIZE, player.SPRITE_SIZE };
			player.origin = { player.hitBox.width, player.hitBox.height};
			player.source = { player.texture.width / 4.0f, 0, static_cast<float>(player.texture.width) / 4, static_cast<float>(player.texture.height)};
		}
	}
}