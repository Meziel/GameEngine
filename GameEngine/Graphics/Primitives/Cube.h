#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_API __declspec(dllexport)
#else
#define GAMEENGINE_API __declspec(dllimport)
#endif

#include "../Object.h"

namespace GameEngine {
	namespace Graphics {

		class GAMEENGINE_API Cube : public Object {

			public:
				Cube();
				~Cube();

		};
	
	}
}

