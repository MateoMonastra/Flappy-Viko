#include "Game.h"

#include "ProgramUtilities/Utilities.h"

#include "Objects/Bird.h"
#include "Objects/Obstacles.h"

namespace flappybird
{
    namespace game
    {
        Bird player;

        void GameUpdate()
        {
            BirdUpdate(player);
        }

        void DrawGame()
        {
            BirdDraw(player);
        }

        void InitGame()
        {
            InitBird(player);
        }
    }
}