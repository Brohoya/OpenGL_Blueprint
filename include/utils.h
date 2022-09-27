#ifndef UTILS_H
#define UTILS_H

#include "libraries.h"

constexpr float						pi					= 3.14159265359f;			// Pi
constexpr float						framerate			= 60.f;						// Nombre max d'images par seconde
constexpr float						frame_duration		= 1.f / framerate;			// Dur�e min d'une frame
constexpr float						frame_duration_ms	= 1.f / framerate * 1e3;	// Dur�e min d'une frame en seconde

extern std::mutex lock;

struct Window
{
	static SDL_Window*		window;		// Fen�tre
	static SDL_GLContext	context;	// Contexte
	static glm::ivec2		size;		// Taille de la fen�tre
	static glm::ivec2		center;		// Centre de la fen�tre

	static bool				init();
	static void				clear();
};



#endif