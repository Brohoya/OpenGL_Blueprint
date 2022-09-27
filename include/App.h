#ifndef APP_H
#define APP_H

#include "utils.h"
#include "Camera.h"

class App
{
    public:
        static void		init();
        static void		checks_events(const SDL_Event& my_event);
        static void		update(glm::ivec2& mouse_pos);
        static void		draw();

};

#endif // !CAD_H
