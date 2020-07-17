#include "Rotation.h"

namespace GameEngine {
	namespace Graphics {

		Rotation::Rotation() {
			Rotation(0, 0, 0);
		}

		Rotation::Rotation(float x, float y) {
			Rotation(x, y, 0);
		}

		Rotation::Rotation(float x, float y, float z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		Rotation::~Rotation() {
		}

		float Rotation::getX() {
			return this->x;
		}

		float Rotation::getY() {
			return this->y;
		}

		float Rotation::getZ() {
			return this->z;
		}

		void Rotation::setX(float x) {
			this->x = x;
		}

		void Rotation::setY(float y) {
			this->y = y;
		}

		void Rotation::setZ(float z) {
			this->z = z;
		}

	}
}
