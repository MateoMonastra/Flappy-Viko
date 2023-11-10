#pragma once

namespace flappybird
{
#include "raylib.h"
#include "raymath.h"

struct Sprite
{
	Texture2D texture = {};
	Vector2 position = {};
	float scale = {};
	float velocity = {};
	Color color = {WHITE};
};

void DrawSprite(Sprite sprite);

}
