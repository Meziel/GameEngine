#include "Color.h"

namespace GameEngine {
	namespace Graphics {

		Color::Color() {
			Color(0.0f, 0.0f, 0.0f, 1.0f);
		}

		Color::Color(float red, float green, float blue, float alpha) {
			this->red = red;
			this->green = green;
			this->blue = blue;
			this->alpha = alpha;
		}

		Color::~Color() {}

		void Color::setRed(float red) {
			this->red = red;
		}
		
		void Color::setGreen(float green) {
			this->green = green;
		}
		
		void Color::setBlue(float blue) {
			this->blue = blue;
		}
		
		void Color::setAlpha(float alpha) {
			this->alpha = alpha;
		}

		float Color::getRed() {
			return this->red;
		}
		
		float Color::getGreen() {
			return this->green;
		}
		
		float Color::getBlue() {
			return this->blue;
		}
		
		float Color::getAlpha() {
			return this->alpha;
		}

	}
}
