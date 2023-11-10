#include "Utilities.h"

namespace flappybird
{
	void DrawSprite(Sprite sprite)
	{
		DrawTextureEx(sprite.texture, sprite.position, 0, sprite.scale, sprite.color);
	}
}