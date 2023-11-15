#pragma once

#include "ProgramUtilities/Utilities.h"

#include "ScreenManagements/Screens.h"

namespace flappybird
{
	namespace credits
	{
		void InitCredits();
		void CreditsUpdate(Screen& currentScene);
		void CreditsDrawing();
	}
}