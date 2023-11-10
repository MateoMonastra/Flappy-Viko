#pragma once

namespace flappybird
{
#include "raylib.h"
#include "raymath.h"

struct Sprite
{
	Texture2D texture = {};
	int y = {};
	int x = {};
	Color color = {WHITE};


};

void DrawSprite(Sprite sprite);

}
