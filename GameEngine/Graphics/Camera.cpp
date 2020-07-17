#include "Camera.h"

namespace GameEngine {
	namespace Graphics {
		
		Camera::Camera(float FOV, float aspect, float near, float far) {
			this->FOV = FOV;
			this->aspect = aspect;
			this->near = near;
			this->far = far;
		}

		Camera::~Camera() {
		}

		void Camera::setPosition(Position position) {
			this->position = position;
		}

		void Camera::setLookAt(Position position) {
			this->lookAt = position;
		}

		Position Camera::getPosition() {
			return this->position;
		}

		Position Camera::getUp() {
			return this->up;
		}

		Position Camera::getForward() {
			return this->forward;
		}

		float Camera::getFOV() {
			return this->FOV;
		}

		float Camera::getAspect() {
			return this->aspect;
		}

		float Camera::getNear() {
			return this->near;
		}

		float Camera::getFar() {
			return this->far;
		}

		void Camera::setFOV(float FOV) {
			this->FOV = FOV;
		}

		void Camera::setAspect(float aspect) {
			this->aspect= aspect;
		}

		void Camera::setNear(float near) {
			this->near = near;
		}

		void Camera::setFar(float far) {
			this->far = far;
		}


	}
}
