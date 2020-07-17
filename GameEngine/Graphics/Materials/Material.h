#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_API __declspec(dllexport)
#else
#define GAMEENGINE_API __declspec(dllimport)
#endif

#include "../Color.h"

namespace GameEngine {
	namespace Graphics {

		class GAMEENGINE_API Material {
			public:
				Material();
				~Material();
		
				Color getDiffuse();
				Color getSpecular();

				void setDiffuse(Color diffuse);
				void setSpecular(Color specular);

			protected:
				Color diffuse;
				Color specular;
		};

	}
}

