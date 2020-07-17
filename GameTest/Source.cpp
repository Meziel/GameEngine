#include "GameEngine/Graphics/Window.h"
#include "GameEngine/Graphics/Scene.h"
#include "GameEngine/Graphics/Camera.h"
#include "GameEngine/Graphics/Primitives/Cube.h"

#include <iostream>
#include <string>
#include <time.h>
#include <vector>

const int DEFAULT_WIDTH = 800;
const int DEFAULT_HEIGHT = 800;

using namespace GameEngine::Graphics;

Scene *scene;
Camera *camera;
Cube *cube1;
Cube *cube2;
float rotation = 0;

void render() {

	rotation += (float)(0.5 * M_PI / 180);

	cube1->setRotation(Rotation(rotation, 0.0f, 0.0f));
	cube1->setPosition(Position(cos(rotation)*3,sin(rotation)*3, 0));

	scene->draw();
	
}

int main(int argc, char **argv) {

	int width;
	int height;

	if (argc < 3) {
		width = DEFAULT_WIDTH;
		height = DEFAULT_HEIGHT;
	}
	else {
		argv++;
		width = std::stoi(*argv);
		argv++;
		height = std::stoi(*argv);
	}

	Window window("Tort Tort", width, height);

	camera = new Camera(45.0f, (float)(width/height), 0.1f, 100.0f);
	scene = new Scene();

	Material material;
	material.setDiffuse(Color(1.0f, 0.0f, 0.0f, 1.0f));
	material.setSpecular(Color(0.0f, 0.0f, 0.0f, 0.0f));
	cube1 = new Cube();
	cube2 = new Cube();

	scene->add(cube1);
	scene->add(cube2);
	scene->setCamera(camera);

	camera->setPosition(Position(0.0f, 0.0f, -10.0f));
	
	cube1->setPosition(Position(1.0f, 0.0f, 0.0f));
	cube1->setMaterial(material);
	cube1->setScale(Scale(2.0f, 2.0f, 2.0f));
	//cube1->loadModel("C:/Users/Michael/Documents/Visual Studio 2013/Projects/GameEngine/Debug/object.obj");

	cube2->setMaterial(material);

	window.drawFunc(render);
	window.init();

	delete cube1;
	delete cube2;
	delete camera;
	delete scene;

	return 0;
}