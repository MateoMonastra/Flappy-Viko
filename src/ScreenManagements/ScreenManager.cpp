#include "ScreenManager.h"

#include "ProgramUtilities/Utilities.h"

#include "Screens.h"
#include "Screens/Game.h"
#include "Screens/Menu.h"


namespace flappybird
{
	Scene currentScreen;

	static void InitProgram();
	static void Update();
	static void Draw();
	static void Close();


	void RunProgram()
	{
		InitProgram();

		while (!WindowShouldClose() && currentScreen != Scene::Exit)
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
		currentScreen = Scene::Menu;
		SetRandomSeed(NULL);
	}

	static void Update()
	{

		switch (currentScreen)
		{
		case Scene::Menu:
			menu::MenuUpdate(currentScreen);
			break;
		case Scene::Game:
			game::GameUpdate();
			break;
		case Scene::Credits:
			/*credits::CreditsUpdate(currentScreen);*/
			break;
		case Scene::Exit:
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
		case Scene::Menu:
			menu::MenuDrawing();
			break;
		case Scene::Game:
			game::DrawGame();
			break;
		case Scene::Credits:
			/*credits::CreditsDrawing();*/
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
