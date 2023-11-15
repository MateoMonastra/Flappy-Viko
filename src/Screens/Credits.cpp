#include "Credits.h"

#include "ProgramUtilities/Utilities.h"

namespace flappybird
{
	namespace credits
	{
		Sprite ShowCredits;
		Sprite BackGround;
		Sprite ReturnMenuButton;


		void InitCredits()
		{
			ShowCredits.position = { 140,100 };
			ShowCredits.scale = 1;
			ShowCredits.texture = LoadTexture("res/credits/ShowCredits.png");

			ReturnMenuButton.position = { 400,550 };
			ReturnMenuButton.scale = 0.6f;
			ReturnMenuButton.texture = LoadTexture("res/credits/ReturnMenuButton.png");
		}

		void CreditsUpdate(Screen& currentScene)
		{

			if (MouseColision(ReturnMenuButton))
			{
				ReturnMenuButton.color = GRAY;

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScene = Screen::Menu;
				}
			}
			else
			{
				ReturnMenuButton.color = WHITE;
			}

		}

		void CreditsDrawing()
		{
			DrawSprite(ShowCredits);
			DrawSprite(ReturnMenuButton);
		}
	}
}