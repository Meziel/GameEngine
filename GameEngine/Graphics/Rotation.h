#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_API __declspec(dllexport)
#else
#define GAMEENGINE_API __declspec(dllimport)
#endif

namespace GameEngine {
	namespace Graphics {

		class GAMEENGINE_API Rotation {
			public:
				Rotation();
				Rotation(float x, float y);
				Rotation(float x, float y, float z);
				~Rotation();

				float getX();
				float getY();
				float getZ();
				void setX(float x);
				void setY(float y);
				void setZ(float z);

			protected:
				float x;
				float y;
				float z;
		};
	}
}

