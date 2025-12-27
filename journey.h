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
    double LocationX;
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


enum obstacle_type
{
    /**
     * Player is able to jump onto this kind of obstacle.
     */
    HIGHER_GROUND,
    /**
     * Player will fall out of game if gets onto this kind of obstacle.
     */
    WELL,
    /**
     * Player will die if collides with this kind of obstacle.
     */
    SPIKE
};

typedef struct Obstacle
{
    /**
     * Kind of the obstacle.
     */
    enum obstacle_type Type;
    /**
     * Horizontal location of the obstacle on the journey (not display).
     */
    double LocationX;
    /**
     * Vertical location of the obstacle on the journey (not display).
     */
    double LocationY;
    /**
     * Base width of the obstacle in pixels.
     */
    double Width;
    /**
     * Height of the highest point of the obstacle.
     */
    double Height;
} Obstacle;

typedef struct ObstacleList
{
    Obstacle* obstacle;
    struct ObstacleList* next;
} ObstacleList;

ObstacleList* initialiseLevel1();

void freeObstacleList(ObstacleList* root);