#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_API __declspec(dllexport)
#else
#define GAMEENGINE_API __declspec(dllimport)
#endif

#include "Position.h"

namespace GameEngine {
	namespace Graphics {
		
		class GAMEENGINE_API Camera {
			public:

				Camera(float FOV, float aspect, float near, float far);
				~Camera();

				void setPosition(Position position);
				void setLookAt(Position position);

				Position getPosition();
				Position getUp();
				Position getForward();

				float getFOV();
				float getAspect();
				float getNear();
				float getFar();

				void setFOV(float FOV);
				void setAspect(float aspect);
				void setNear(float near);
				void setFar(float far);

			protected:
				float FOV;
				float aspect;
				float near;
				float far;

				Position position;
				Position lookAt;
				Position up = Position(0.0f, -1.0f, 0.0f);
				Position forward = Position(0.0f, 0.0f, 1.0f);
		};

	}
}

