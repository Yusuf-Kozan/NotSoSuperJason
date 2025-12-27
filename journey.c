#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include "journey.h"

/**
 * Gravitational accelaration in px/s.
 */
const double GRAVITY = 1500;

Player* newPlayer()
{
    Player* new = malloc(sizeof(Player));
    new->LocationX = 0;
    new->LocationY = 0;
    new->VelocityUp = 0.0;
    return new;
}

void DrawPlayer(const Player *player, const DisplayInfo * const display)
{
    int stature = vh_ToPixels(15, display);
    float width = stature * 0.35;

    const int midway = display->Width / 2;
    int x_on_window = player->LocationX + display->Padding + width/2;
    if (x_on_window >= midway)
    {
        x_on_window = midway;
    }
    int y_on_window = display->Height - display->Padding - player->LocationY;


    ALLEGRO_COLOR colour = al_map_rgb(148, 112, 132);

    al_draw_filled_rectangle(x_on_window - width/2, y_on_window-stature, x_on_window+width/2, y_on_window, colour);
}

void UpdateLocation(Player * const player, const double delta_seconds)
{
    //printf("%lf\t", player->VelocityUp);
    //printf("%lf\t", GRAVITY*delta_seconds);
    player->VelocityUp -= GRAVITY * delta_seconds;
    //printf("%lf\t", player->VelocityUp);
    //printf("%lf\t", player->VelocityUp*delta_seconds);
    player->LocationY += player->VelocityUp * delta_seconds;
    //printf("%lf\n", player->LocationY);

    if (player->LocationY <= 0)
    {
        player->LocationY = 0;
        player->VelocityUp = 0;
    }
}