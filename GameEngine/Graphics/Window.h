#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_API __declspec(dllexport)
#else
#define GAMEENGINE_API __declspec(dllimport)
#endif

#include <stdlib.h>
#include <iostream>
#include <SDL2/SDL.h>

#ifdef main
#undef main
#endif

namespace GameEngine {
	namespace Graphics {

		class GAMEENGINE_API Window {

			public:
				Window(std::string title, int width, int height);
				~Window();
				void keyDownFunc(void(*keyUpCallback)(void));
				void keyUpFunc(void(*keyDownCallback)(void));
				void drawFunc(void (*drawCallback)(void));
				void init();

			protected:
				SDL_Window *window;
				SDL_GLContext context;

				void (*keyUpCallback)(void) = NULL;
				void (*keyDownCallback)(void) = NULL;
				void (*drawCallback)(void) = NULL;

		private:
			Window(const Window& window);
			Window &operator=(const Window&);
		};

	}
}