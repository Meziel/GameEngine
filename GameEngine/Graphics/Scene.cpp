#include "Scene.h"

#include <iostream>
#include <glew.h>
#include <SDL2/SDL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Object.h"

using namespace std;

namespace GameEngine {
	namespace Graphics {

		void createMVP(Object *object, Camera *camera) {

			glm::mat4 scaleMatrix = glm::mat4();
			scaleMatrix = glm::scale(scaleMatrix, glm::vec3(object->getScale().getX(), object->getScale().getY(), object->getScale().getZ()));

			glm::mat4 rotationMatrix;
			glm::mat4 rotationMatrixX;
			glm::mat4 rotationMatrixY;
			glm::mat4 rotationMatrixZ;
			rotationMatrixX = glm::rotate(rotationMatrix, object->getRotation().getX(), glm::vec3(1.0f, 0.0f, 0.0f));
			rotationMatrixY = glm::rotate(rotationMatrix, object->getRotation().getY(), glm::vec3(0.0f, 1.0f, 0.0f));
			rotationMatrixZ = glm::rotate(rotationMatrix, object->getRotation().getZ(), glm::vec3(0.0f, 0.0f, 1.0f));
			rotationMatrix = rotationMatrixZ * rotationMatrixY * rotationMatrixX;

			glm::mat4 translationMatrix = glm::mat4();
			translationMatrix = glm::translate(translationMatrix, glm::vec3(object->getPosition().getX(), object->getPosition().getY(), object->getPosition().getZ()));

			glm::mat4 viewMatrix = glm::lookAt(glm::vec3(camera->getPosition().getX(), camera->getPosition().getY(), camera->getPosition().getZ()),
				glm::vec3(camera->getPosition().getX(), camera->getPosition().getY(), camera->getPosition().getZ()) + glm::vec3(camera->getForward().getX(), camera->getForward().getY(), camera->getForward().getZ()),
				glm::vec3(camera->getUp().getX(), camera->getUp().getY(), camera->getUp().getZ()));

			glm::mat4 projectionMatrix = glm::mat4();
			projectionMatrix = glm::perspective(camera->getFOV(), camera->getAspect(), camera->getNear(), camera->getFar());

			glm::mat4 mvp = projectionMatrix * viewMatrix * translationMatrix * rotationMatrix * scaleMatrix;

			GLint mvpUniform;
			mvpUniform= glGetUniformLocation(object->getShaderProgram()->getProgram(), "mvp");
			glUniformMatrix4fv(mvpUniform, 1, GL_FALSE, glm::value_ptr(mvp));

			mvpUniform = glGetUniformLocation(object->getShaderProgram()->getProgram(), "vp");
			glUniformMatrix4fv(mvpUniform, 1, GL_FALSE, glm::value_ptr(projectionMatrix * viewMatrix));


		}

		Scene::Scene() {
		}

		Scene::~Scene() {

		}

		void Scene::add(Object *object) {
			this->objects.insert(object);
		}

		void Scene::remove(Object *object) {
			this->objects.erase(object);
		}

		void Scene::setCamera(Camera *camera) {
			this->camera = camera;
		}

		Camera *Scene::getCamera() {
			return this->camera;
		}

		void Scene::draw() {

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			if (this->camera != NULL) {

				for (Object *object : this->objects) {

					//load object shader
					object->getShaderProgram()->use();

					//================== ATTRIBUTEs BEGIN

					float *vertices = new float[object->getMesh().getVerticesSize()];
					object->getMesh().getVertices(vertices, object->getMesh().getVerticesSize());

					float *normals = new float[object->getMesh().getVerticesSize()];
					object->getMesh().getNormals(normals, object->getMesh().getVerticesSize());

					GLuint vbos[2];
					GLint attrib;

					//positions
					glGenBuffers(2, vbos);
					glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);
					glBufferData(GL_ARRAY_BUFFER, object->getMesh().getVerticesSize() * sizeof(GLfloat), (GLfloat *)(vertices), GL_STATIC_DRAW);

					attrib = glGetAttribLocation(object->getShaderProgram()->getProgram(), "vPosition");
					glVertexAttribPointer(attrib, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
					glEnableVertexAttribArray(attrib);

					//normals
					glBindBuffer(GL_ARRAY_BUFFER, vbos[1]);
					glBufferData(GL_ARRAY_BUFFER, object->getMesh().getVerticesSize() * sizeof(GLfloat), (GLfloat *)(normals), GL_STATIC_DRAW);

					attrib = glGetAttribLocation(object->getShaderProgram()->getProgram(), "vNormal");
					glEnableVertexAttribArray(attrib);
					glVertexAttribPointer(attrib, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
					glEnableVertexAttribArray(attrib);

					//================== ATTRIBUTES END 


					//================== UNIFORMS BEGIN

					createMVP(object, this->camera);

					GLint uniform; 

					uniform = glGetUniformLocation(object->getShaderProgram()->getProgram(), "material.diffuse");
					glUniform4f(uniform, object->getMaterial().getDiffuse().getRed(), object->getMaterial().getDiffuse().getGreen(), object->getMaterial().getDiffuse().getBlue(), object->getMaterial().getDiffuse().getAlpha());

					uniform = glGetUniformLocation(object->getShaderProgram()->getProgram(), "material.specular");
					glUniform4f(uniform, object->getMaterial().getSpecular().getRed(), object->getMaterial().getSpecular().getGreen(), object->getMaterial().getSpecular().getBlue(), object->getMaterial().getSpecular().getAlpha());

					uniform = glGetUniformLocation(object->getShaderProgram()->getProgram(), "dirLights[0].color");
					glUniform3f(uniform, 0.0f, 0.0f, 0.0f);

					uniform = glGetUniformLocation(object->getShaderProgram()->getProgram(), "dirLights[0].direction");
					glUniform3f(uniform, -1.0f, -1.0f, -1.0f);

					uniform = glGetUniformLocation(object->getShaderProgram()->getProgram(), "pointLights[0].color");
					glUniform3f(uniform, 1.0f, 1.0f, 1.0f);

					uniform = glGetUniformLocation(object->getShaderProgram()->getProgram(), "pointLights[0].position");
					glUniform3f(uniform, 0.0f, 0.0f, 0.0f);

					uniform = glGetUniformLocation(object->getShaderProgram()->getProgram(), "pointLights[0].constant");
					glUniform1f(uniform, 1.0f);

					uniform = glGetUniformLocation(object->getShaderProgram()->getProgram(), "pointLights[0].linear");
					glUniform1f(uniform, 0.05f);

					uniform = glGetUniformLocation(object->getShaderProgram()->getProgram(), "pointLights[0].quadratic");
					glUniform1f(uniform, 0.005f);

					uniform = glGetUniformLocation(object->getShaderProgram()->getProgram(), "ambientLight");
					glUniform3f(uniform, 0.0f, 0.0f, 0.0f);

					//================== UNIFORMS END

					glDrawArrays(GL_TRIANGLES, 0, object->getMesh().getVerticesSize());

					delete [] vertices;
					delete [] normals;
					glDeleteBuffers(2, vbos);

				}

			}

		}

	}

	
}