#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_API __declspec(dllexport)
#else
#define GAMEENGINE_API __declspec(dllimport)
#endif

#include <set>

#include "Object.h"
#include "Camera.h"

namespace GameEngine {
	namespace Graphics {

		class GAMEENGINE_API Scene {
			
			public:
				Scene();
				~Scene();
				void add(Object *object);
				void remove(Object *object);
				void draw();
				void setCamera(Camera *camera);
				Camera *getCamera();

			protected:
				Camera *camera;
				std::set<Object *> objects;
				int timesDrawn = 0;

		};

	}
}