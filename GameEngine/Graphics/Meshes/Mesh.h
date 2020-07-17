#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_API __declspec(dllexport)
#else
#define GAMEENGINE_API __declspec(dllimport)
#endif

#include <stdlib.h>

namespace GameEngine {
	namespace Graphics {


		class GAMEENGINE_API Mesh {
			public:
				Mesh();
				Mesh::Mesh(const Mesh &mesh);
				Mesh &Mesh::operator=(const Mesh &mesh);
				~Mesh();

				void setVertices(float *vertices, float *normals, int size);

				void			getVertices(float *verticesBuffer, int bufferSize);
				void			getNormals(float *normalsBuffer, int bufferSize);
				int				getVerticesSize();

			protected:

				float			*vertices = NULL;
				float			*normals = NULL;
				int				verticesSize = 0;
		};

	}
}

