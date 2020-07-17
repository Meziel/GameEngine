#include "Window.h"

#include <iostream>
#include <glew.h>

using namespace std;

namespace GameEngine {
	namespace Graphics {

		Window::Window(std::string title, int width, int height) {

			if (SDL_Init(SDL_INIT_VIDEO) != 0) {
				cerr << "Could not initialize SDL: " << SDL_GetError() << endl;
				return;
			}

			SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
			SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
			SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
			SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
			SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

			this->window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);

			if (this->window == NULL) {
				cerr << "Could not create window: " << SDL_GetError() << endl;
				return;
			}

			this->context = SDL_GL_CreateContext(this->window);

			//vsync
			SDL_GL_SetSwapInterval(1);

			glewExperimental = GL_TRUE;
			GLenum err = glewInit();
			if (GLEW_OK != err)
			{
				fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
			}

			glViewport(0, 0, width, height);
			glEnable(GL_DEPTH_TEST);
			glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glEnable(GL_BLEND);

			//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		}

		Window::~Window() {
			SDL_GL_DeleteContext(this->context);
			SDL_DestroyWindow(this->window);
			SDL_Quit();
		}

		void Window::keyDownFunc(void(*keyUpCallback)(void)) {
			this->keyDownCallback = keyUpCallback;
		}
		
		void Window::keyUpFunc(void(*keyUpCallback)(void)) {
			this->keyUpCallback = keyUpCallback;
		}

		void Window::drawFunc(void (*drawCallback)(void)) {
			this->drawCallback = drawCallback;
		}

		void Window::init() {
			
			SDL_Event event;
			bool quit = false;

			while (!quit) {

				if(SDL_PollEvent(&event)) {
					
					switch (event.type) {
						case SDL_KEYDOWN:
							printf("Key press detected\n");
							break;

						case SDL_KEYUP:
							printf("Key release detected\n");
							break;

						case SDL_QUIT:
							quit = true;
							break;

						default:
							break;
					}

				}

				if (this->drawCallback != NULL) {
					this->drawCallback();
					SDL_GL_SwapWindow(window);
				}
			}
		}

	}
}
