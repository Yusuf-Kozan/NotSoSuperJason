#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/events.h>
#include <allegro5/keycodes.h>
#include <allegro5/altime.h>
#include "journey.h"

/**
 * Exits the application if specified allegro initialiser
 * fails.
 */
void initialise(bool initialised, const char *name)
{
    if (initialised)
        return;

    printf(
        "ERROR: %s could not be initialised.\n",
        name
    );
    exit(1);
}


int main()
{
    DisplayInfo* dinfo = newDisplayInfo(1290, 720, 30, 60.0);

    initialise(al_init(), "Allegro");

    initialise(al_install_keyboard(), "Keyboard");

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / dinfo->Frames);
    initialise(timer, "Timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    initialise(queue, "Queue");

    ALLEGRO_DISPLAY* display = al_create_display(dinfo->Width, dinfo->Height);
    initialise(display, "Display");

    ALLEGRO_FONT* font_builtin = al_create_builtin_font();
    initialise(font_builtin, "Built-in font");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    double last_time = al_get_time();

    Player* jason = newPlayer();

    #define KEY_SEEN     1
    #define KEY_DOWN     2

    unsigned char key[ALLEGRO_KEY_MAX];
    memset(key, 0, sizeof(key));

    al_start_timer(timer);
    while(1)
    {
        double current_time = al_get_time();
        double delta_time = current_time - last_time;
        last_time = current_time;

        UpdateLocation(jason, delta_time);
        
        al_wait_for_event(queue, &event);

        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                // game logic goes here.
                if (key[ALLEGRO_KEY_LEFT])
                {
                    if (jason->LocationX > 2)
                        jason->LocationX -= 2;
                }
                if (key[ALLEGRO_KEY_RIGHT])
                    jason->LocationX += 2;

                if (key[ALLEGRO_KEY_ESCAPE])
                    done = true;

                for (int i = 0; i < ALLEGRO_KEY_MAX; i++)
                    key[i] &= ~KEY_SEEN;

                redraw = true;
                break;

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;

            case ALLEGRO_EVENT_KEY_DOWN:
                key[event.keyboard.keycode] = KEY_SEEN | KEY_DOWN;
                if (key[ALLEGRO_KEY_SPACE])
                {
                    //printf("jump\n");
                    if (jason->LocationY <= 20)
                    {
                        jason->VelocityUp = 800;
                        redraw = true;
                    }
                }
                break;

            case ALLEGRO_EVENT_KEY_UP:
                key[event.keyboard.keycode] &= ~KEY_DOWN;
                break;
        }
        

        if(done)
            break;

        int left = vw_ToPixels(10.0, dinfo);
        int width = vw_ToPixels(12.5, dinfo);
        int top = vh_ToPixels(10.0, dinfo);
        int height = vw_ToPixels(25.0, dinfo);

        if(redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(253, 239, 237));
            //al_draw_filled_rounded_rectangle(left, top, left+width, top+height, 48, 48, al_map_rgb(148, 112, 132));
            //al_draw_text(font_builtin, al_map_rgb(255, 255, 255), 0, 0, 0, "Hello world!");
            DrawPlayer(jason, dinfo);

            al_flip_display();

            redraw = false;
        }
    }

    al_destroy_font(font_builtin);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    free(dinfo);
    free(jason);

    return 0;
}