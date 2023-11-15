#include "Menu.h"

#include "ProgramUtilities/Utilities.h"

#include "Game.h"
#include "Credits.h"

namespace flappybird
{
	namespace menu
	{
		static Sprite title;
		static Sprite play;
		static Sprite exit;
		static Sprite credits;

		void InitMenu()
		{
			title.position = { static_cast<float>(GetScreenWidth()) / 2 -240, 60 };
			title.scale = 0.7f;
			title.texture = LoadTexture("res/menu/Title.png");

			play.position = { static_cast<float>(GetScreenWidth()) / 2 - 80 , 400};
			play.scale = 0.5f;
			play.texture = LoadTexture("res/menu/PlayButton.png");

			exit.position = { static_cast<float>(GetScreenWidth()) / 2 - 80, 640 };
			exit.scale = 0.5f;
			exit.texture = LoadTexture("res/menu/ExitButton.png");

			credits.position = { static_cast<float>(GetScreenWidth()) / 2 - 80, 510};
			credits.scale = 0.5f;
			credits.texture = LoadTexture("res/menu/CreditsButton.png");
		}

		void MenuUpdate(Screen& currentScene)
		{
			if (MouseColision(play))
			{
				play.color = GRAY;

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScene = Screen::Game;
					game::InitGame();
				}
			}
			else
			{
				play.color = WHITE;
			}

			if (MouseColision(exit))
			{
				exit.color = GRAY;

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScene = Screen::Exit;
				}
			}
			else
			{
				exit.color = WHITE;
			}

			if (MouseColision(credits))
			{
				credits.color = GRAY;

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScene = Screen::Credits;
					credits::InitCredits();
				}
			}
			else
			{
				credits.color = WHITE;
			}
		}
		

		void MenuDrawing()
		{
			DrawSprite(title);
			DrawSprite(play);
			DrawSprite(credits);
			DrawSprite(exit);
		}
	}
}