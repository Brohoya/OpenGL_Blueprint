#include <iostream>
#include "app.h"


int main(int argc, char* argv[])
{
	// cout << "Hello CMake." << endl;

    bool running = true;

    // Initiation des librairies
	if (!Window::init()) return EXIT_FAILURE;

    // Boucle principale
    while (running) {
        uint32_t time_begin = SDL_GetTicks();

        SDL_Event sdl_event;

        while (SDL_PollEvent(&sdl_event))
		{
			switch (sdl_event.type)
			{
			case SDL_WINDOWEVENT:
				switch (sdl_event.window.event)
				{
				case SDL_WINDOWEVENT_CLOSE:
					lock.lock();
					running = false;
					lock.unlock();
					break;

				default:
					break;
				}
				break;

			default:
				lock.lock();
				// app::checks_events(sdl_event);
				lock.unlock();
			}
		}


        uint32_t time_end = SDL_GetTicks();

        if (time_end - time_begin < frame_duration_ms)
			SDL_Delay(frame_duration_ms - (time_end - time_begin));
        
    }

	return 0;
}
