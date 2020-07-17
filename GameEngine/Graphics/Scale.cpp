#include "Scale.h"

namespace GameEngine {
	namespace Graphics {

		Scale::Scale() {
			Scale(1.0f, 1.0f, 1.0f);
		}

		Scale::Scale(float x, float y, float z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		Scale::~Scale() {
		}

		float Scale::getX() {
			return this->x;
		}

		float Scale::getY() {
			return this->y;
		}

		float Scale::getZ() {
			return this->z;
		}

		void Scale::setX(float x) {
			this->x = x;
		}

		void Scale::setY(float y) {
			this->y = y;
		}

		void Scale::setZ(float z) {
			this->z = z;
		}

	}
}


