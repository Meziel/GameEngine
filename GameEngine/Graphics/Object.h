#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_API __declspec(dllexport)
#else
#define GAMEENGINE_API __declspec(dllimport)
#endif

#include <stdlib.h>

#include "ShaderProgram.h"
#include "Position.h"
#include "Rotation.h"
#include "Scale.h"
#include "Meshes/Mesh.h"
#include "Materials/Material.h"

namespace GameEngine {
	namespace Graphics {

		class GAMEENGINE_API Object {

			public:

				Object();
				Object(const Object& object);
				Object& operator=(const Object& object);
				~Object();
				
				Position		getPosition();
				Rotation		getRotation();
				Scale			getScale();
				Mesh			getMesh();
				Material		getMaterial();
				ShaderProgram	*getShaderProgram();

				void setPosition(Position position);
				void setRotation(Rotation rotation);
				void setScale(Scale scale);		
				void setMesh(Mesh mesh);
				void setMaterial(Material material);

				//void loadModel(std::string modelPath);

			protected:
				Position		position = Position(0.0f, 0.0f, 0.0f);
				Rotation		rotation = Rotation(0.0f, 0.0f, 0.0f);
				Scale			scale = Scale(1.0f, 1.0f, 1.0f);
				Mesh			mesh;
				Material		material;
				
				ShaderProgram   shaderProgram;
		};

	}
}


