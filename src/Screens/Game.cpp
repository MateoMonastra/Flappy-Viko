#include "Game.h"

#include "ProgramUtilities/Utilities.h"

#include "Objects/Bird.h"
#include "Objects/Obstacles.h"

namespace flappybird
{
    namespace game
    {
        Bird player;
        Obstacle obstacle;

        void GameUpdate()
        {
            BirdUpdate(player);
            ObstacleUpdate(obstacle);
        }

        void DrawGame()
        {
            BirdDraw(player);
            ObstacleDraw(obstacle);
        }

        void InitGame()
        {
            InitBird(player);
            InitObstacle(obstacle);
        }
    }
}