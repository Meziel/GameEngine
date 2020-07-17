#include "Mesh.h"

#include <algorithm>

namespace GameEngine {
	namespace Graphics {
		
		Mesh::Mesh() {
			this->vertices = new float[0];
			this->normals = new float[0];
		}

		Mesh::Mesh(const Mesh &mesh) {
			this->setVertices(mesh.vertices, mesh.normals, mesh.verticesSize);
		}

		Mesh &Mesh::operator=(const Mesh &mesh) {
			this->setVertices(mesh.vertices, mesh.normals, mesh.verticesSize);
			return *this;
		}

		Mesh::~Mesh() {
			delete[] this->vertices;
		}

		void Mesh::getVertices(float *verticesBuffer, int bufferSize) {

			int fillSize = std::min(bufferSize, this->getVerticesSize());

			for (int i = 0; i<fillSize; i++) {
				verticesBuffer[i] = this->vertices[i];
			}

		}

		void Mesh::getNormals(float *normalsBuffer, int bufferSize) {

			int fillSize = std::min(bufferSize, this->getVerticesSize());

			for (int i = 0; i<fillSize; i++) {
				normalsBuffer[i] = this->normals[i];
			}

		}

		void Mesh::setVertices(float *vertices, float *normals, int size) {

			delete[] this->vertices;
			delete[] this->normals;

			this->vertices = new float[size];
			this->normals = new float[size];
			this->verticesSize = size;

			for (int i = 0; i<size; i++) {
				this->vertices[i] = vertices[i];
				this->normals[i] = normals[i];
			}

		}

		int Mesh::getVerticesSize() {
			return this->verticesSize;
		}

	}
}
