#include "Utilities.h"

namespace flappybird
{
	void DrawSprite(Sprite sprite)
	{
		DrawTexture(sprite.texture, sprite.x, sprite.y, sprite.color);
	}
}