#include "Object.h"

//#include <assimp/Importer.hpp>
//#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>
#include <vector>

#include "ShaderProgram.h"

namespace GameEngine {
	namespace Graphics {

		Object::Object() : shaderProgram("shaders/phong.vert", "shaders/phong.frag") {}

		Object::Object(const Object& object) : shaderProgram("shaders/phong.vert", "shaders/phong.frag") {}

		Object& Object::operator=(const Object& object) {
			this->shaderProgram = ShaderProgram("shaders/phong.vert", "shaders/phong.frag");
			return *this;
		}

		Object::~Object() {}

		Position Object::getPosition() {
			return this->position;
		}

		void Object::setPosition(Position position) {
			this->position = position;
		}

		Rotation Object::getRotation() {
			return this->rotation;
		}

		void Object::setRotation(Rotation rotation) {
			this->rotation = rotation;
		}

		Scale Object::getScale() {
			return this->scale;
		}

		void Object::setScale(Scale scale) {
			this->scale = scale;
		}

		Material Object::getMaterial() {
			return this->material;
		}

		void Object::setMaterial(Material material) {
			this->material = material;
		}

		Mesh Object::getMesh() {
			return this->mesh;
		}

		void Object::setMesh(Mesh mesh) {
			this->mesh = mesh;
		}

		ShaderProgram *Object::getShaderProgram() {
			return &this->shaderProgram;
		}

		/*
		int processNode(const aiScene *scene, aiNode *node, std::vector<float> *vertices, std::vector<float> *normals) {

			int size = 0;

			for (int i = 0; i < node->mNumMeshes; i++) {

				aiMesh *aiMesh = scene->mMeshes[node->mMeshes[i]];

				for (GLuint j = 0; j < aiMesh->mNumVertices; j++) {
					vertices->push_back(aiMesh->mVertices[j].x);
					vertices->push_back(aiMesh->mVertices[j].y);
					vertices->push_back(aiMesh->mVertices[j].z);

					//normals->push_back(aiMesh->mNormals[j].x);
					//normals->push_back(aiMesh->mNormals[j].y);
					//normals->push_back(aiMesh->mNormals[j].z);

					normals->push_back(1);
					normals->push_back(0);
					normals->push_back(0);

					size += 3;
				}

			}

			for (int i = 0; i<node->mNumChildren; i++) {
				size += processNode(scene, node->mChildren[i], vertices, normals);
			}

			return size;
		}

		void Object::loadModel(std::string modelPath) {

			Assimp::Importer importer;
			const aiScene* scene = importer.ReadFile(modelPath, aiProcess_Triangulate | aiProcess_FlipUVs);

			if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
				std::cout << "Assimp error: " << importer.GetErrorString() << std::endl;
				return;
			}

			std::vector<float> vertices;
			std::vector<float> normals;

			int size = processNode(scene, scene->mRootNode, &vertices, &normals);

			std::cout << size << std::endl;

			Mesh mesh;
			vertices.shrink_to_fit();
			normals.shrink_to_fit();
			mesh.setVertices((float *)&vertices, (float *)&normals, size);

			this->mesh = mesh;

			for (int i = 0; i<vertices.size(); i+=3) {
				std::cout << vertices[i];
				std::cout << " ";
				std::cout << vertices[i + 1];
				std::cout << " ";
				std::cout << vertices[i + 2];
				std::cout << std::endl;
			}


		}
		*/
	}
}
