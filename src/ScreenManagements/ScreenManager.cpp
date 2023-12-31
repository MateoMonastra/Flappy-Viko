#include "ScreenManager.h"

#include "ProgramUtilities/Utilities.h"

#include "Screens.h"
#include "Screens/Game.h"
#include "Screens/Menu.h"
#include "Screens/Credits.h"


namespace flappybird
{
	Screen currentScreen;

	static void InitProgram();
	static void Update();
	static void Draw();
	static void Close();


	void RunProgram()
	{
		InitProgram();

		while (!WindowShouldClose() && currentScreen != Screen::Exit)
		{
			Update();
			Draw();
		}

		Close();
	}

	static void InitProgram()
	{
		int windowH = 720;
		int windowW = 1080;

		InitWindow(windowW, windowH, "Flappy Viko by Mateo Viko Monastra");

		menu::InitMenu();
		currentScreen = Screen::Menu;
		SetRandomSeed(NULL);
		SetExitKey(NULL);
	}

	static void Update()
	{

		switch (currentScreen)
		{
		case Screen::Menu:
			menu::MenuUpdate(currentScreen);
			break;
		case Screen::Game:
			game::GameUpdate(currentScreen);
			break;
		case Screen::Credits:
			credits::CreditsUpdate(currentScreen);
			break;
		case Screen::Exit:
			Close();
			break;
		default:
			break;
		}

	}

	static void Draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);
		switch (currentScreen)
		{
		case Screen::Menu:
			menu::MenuDrawing();
			break;
		case Screen::Game:
			game::DrawGame();
			break;
		case Screen::Credits:
			credits::CreditsDrawing();
			break;
		default:
			break;
		}
		EndDrawing();
	}

	static void Close()
	{
		CloseWindow();
	}


}
