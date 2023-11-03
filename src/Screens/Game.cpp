#include "Game.h"

#include "ProgramUtilities/Utilities.h"

namespace flappybird
{
    namespace game
    {
        Vector2 ballPosition;

        void GameUpdate()
        {
            if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 200.0f * GetFrameTime();
            if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 200.0f * GetFrameTime();
            if (IsKeyDown(KEY_UP)) ballPosition.y -= 200.0f * GetFrameTime();
            if (IsKeyDown(KEY_DOWN)) ballPosition.y += 200.0f * GetFrameTime();
        }

        void DrawGame()
        {
            DrawCircleV(ballPosition, 50, MAROON);
        }

        void InitGame()
        {
            ballPosition = { static_cast<float>(GetScreenWidth()) / 2,static_cast<float>(GetScreenHeight()) / 2 };
        }
    }
}