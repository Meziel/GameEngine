#include "Material.h"

namespace GameEngine {
	namespace Graphics {
		
		Material::Material() {
		}


		Material::~Material() {
		}

		Color Material::getDiffuse() {
			return this->diffuse;
		}

		Color Material::getSpecular() {
			return this->specular;
		}

		void Material::setDiffuse(Color diffuse) {
			this->diffuse = diffuse;
		}
		
		void Material::setSpecular(Color specular) {
			this->specular = specular;
		}

	}
}
