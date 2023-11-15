#include "Utilities.h"

namespace flappybird
{
	void DrawSprite(Sprite sprite)
	{
		DrawTextureEx(sprite.texture, sprite.position, 0, sprite.scale, sprite.color);
	}

	bool MouseColision(Sprite rec)
	{
		Vector2 mousePosition = GetMousePosition();

		if (mousePosition.x >= rec.position.x &&
			mousePosition.x <= rec.position.x + rec.texture.width * rec.scale &&
			mousePosition.y >= rec.position.y &&
			mousePosition.y <= rec.position.y + rec.texture.height * rec.scale)
		{
			return true;
		}
		return false;
	}
}