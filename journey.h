#include <stdbool.h>
#include "responsive.h"

/**
 * A struct for keeping track of information specific to a player.
 */
typedef struct Player
{
    /**
     * Horizontal location of player on the journey (not display).
     */
    int LocationX;
    /**
     * Vertical location of player on the journey (not display).
     */
    double LocationY;

    /**
     * Jumping velocity (px/s) of player while jumping.
     * Positive values move upwards.
     */
    double VelocityUp;
} Player;

/**
 * Constructs a new player.
 */
Player* newPlayer();

/**
 * Draws the specified player on the window.
 */
void DrawPlayer(const Player * const player, const DisplayInfo * const display);

/**
 * Updates player's location based on velocity and gravity.
 */
void UpdateLocation(Player * const player, const double delta_seconds);

