#include "utils.h"

std::mutex		lock;

SDL_Window*		Window::window = NULL;
SDL_GLContext	Window::context = NULL;
glm::ivec2		Window::size = glm::ivec2(10, 10);
glm::ivec2		Window::center = glm::ivec2(5, 5);

// Initialise la fen�tre

bool Window::init()
{
	// Initialize SDL2
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0)
	{
		// SHADER_ERROR("The initialization of the SDL failed : %s\n", SDL_GetError());
		return false;
	}

	SDL_DisplayMode screen;
	SDL_GetCurrentDisplayMode(0, &screen);

	size.x = screen.w * (3.f / 4.f);
	size.y = screen.h * (3.f / 4.f);
	center.x = size.x / 2;
	center.y = size.y / 2;

	// Create a Window
	window = SDL_CreateWindow("OpenGL window",	    // Titre
		SDL_WINDOWPOS_UNDEFINED,					// X Position
		SDL_WINDOWPOS_UNDEFINED,					// Y Position
		size.x, size.y,								// Resolution
		SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);		// Flags (OpenGL + Show)

	// Initialize OpenGL Version (version 3.0)
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

	// Initialize the OpenGL Context (where OpenGL resources (Graphics card resources) lives)
	context = SDL_GL_CreateContext(window);

	// Tells GLEW to initialize the OpenGL function with this version
	glewExperimental = GL_TRUE;
	glewInit();

	// Start using OpenGL to draw something on screen
	glViewport(0, 0, size.x, size.y); // Draw on ALL the screen

	// The OpenGL background color (RGBA, each component between 0.f and 1.f)
	glClearColor(0.f, 0.f, 0.f, 1.f);

	glEnable(GL_DEPTH_TEST); // Active the depth test
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Active le clipping plane
	glEnable(GL_CLIP_DISTANCE0);

	// Active les faces visibles uniquement dans un sens
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);

	return true;
}

// Supprime la fen�tre

void Window::clear()
{
	if (context != NULL)
		SDL_GL_DeleteContext(Window::context);

	if (window != NULL)
		SDL_DestroyWindow(Window::window);
}

