#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_API __declspec(dllexport)
#else
#define GAMEENGINE_API __declspec(dllimport)
#endif

namespace GameEngine {
	namespace Graphics {

		class GAMEENGINE_API Scale {

			public:
				Scale();
				Scale(float x, float y, float z);
				~Scale();

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

