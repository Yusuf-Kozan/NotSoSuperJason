#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include "responsive.h"

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
    DisplayInfo* dinfo = newDisplayInfo(1290, 720, 60.0);

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

    al_start_timer(timer);
    while(1)
    {
        al_wait_for_event(queue, &event);

        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                // game logic goes here.
                redraw = true;
                break;

            case ALLEGRO_EVENT_KEY_DOWN:
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }

        if(done)
            break;

        int left = vw_ToPixels(10.0, dinfo);
        int width = vw_ToPixels(25.0, dinfo);
        int top = vh_ToPixels(10.0, dinfo);
        int bottom = vh_ToPixels(35.0, dinfo);

        if(redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(253, 239, 237));
            al_draw_filled_rounded_rectangle(left, top, left+width, top+width, 48, 48, al_map_rgb(148, 112, 132));
            //al_draw_text(font_builtin, al_map_rgb(255, 255, 255), 0, 0, 0, "Hello world!");
            
            al_flip_display();

            redraw = false;
        }
    }

    al_destroy_font(font_builtin);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    free(dinfo);

    return 0;
}