#include <stdbool.h>
#include "responsive.h"

typedef struct Player
{
    /**
     * Horizontal location of player on the journey (not display).
     */
    int LocationX;
    /**
     * Vertical location of player on the journey (not display).
     */
    int LocationY;
} Player;

Player* newPlayer();

void DrawPlayer(const Player *player, const DisplayInfo *display);

bool InitialiseJourney();

