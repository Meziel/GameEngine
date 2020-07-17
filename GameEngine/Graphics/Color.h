#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_API __declspec(dllexport)
#else
#define GAMEENGINE_API __declspec(dllimport)
#endif

namespace GameEngine {
	namespace Graphics {

		class GAMEENGINE_API Color {

			public:
				Color();
				Color(float red, float green, float blue,  float alpha = 1.0f);
				~Color();

				void setRed(float red);
				void setGreen(float green);
				void setBlue(float blue);
				void setAlpha(float alpha);

				float getRed();
				float getGreen();
				float getBlue();
				float getAlpha();

			protected:
				float red;
				float blue;
				float green;
				float alpha;
		};


	}
}

