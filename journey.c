#include <allegro5/color.h>
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include "journey.h"

Player* newPlayer()
{
    Player* new = malloc(sizeof(Player));
    new->LocationX = 0;
    new->LocationY = 0;
    return new;
}

void DrawPlayer(const Player *player, const DisplayInfo *display)
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

bool InitialiseJourney()
{
    
    return true;
}