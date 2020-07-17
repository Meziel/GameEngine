#pragma once

#include <glew.h>
#include <string>

namespace GameEngine {
	namespace Graphics {

		class ShaderProgram {
			public:
				ShaderProgram(const std::string vertexFilePath, const std::string fragmentFilePath);
				~ShaderProgram();

				GLuint getProgram();
				void use();

			protected:

				static std::string getShaderSource(const char *filePath);
				static bool createShader(GLenum type, GLchar *source, GLuint *shader);
				static void deleteShaders(GLuint vertexShader, GLuint fragmentShader);

				static void printShaderErrors(GLuint shader);
				static void printProgramErrors(GLuint program);

				bool createProgram(GLuint vertexShader, GLuint fragmentShader);
				GLuint program;
		
			private:
				ShaderProgram(const ShaderProgram& shaderProgram);
				//ShaderProgram &operator=(const ShaderProgram& shaderProgram);
		};

	}
}

