#include "Header.h"


Cube::Cube()
{
}


Cube::~Cube()
{
}

void Cube::createCubeGeometry()
{
	float dim = 20.0f;

	float cubeVertices[] = {
		// positions          // texture Coords
		-dim, -dim, -dim,  0.0f, 0.0f,
		dim, -dim, -dim,  1.0f, 0.0f,
		dim,  dim, -dim,  1.0f, 1.0f,
		dim,  dim, -dim,  1.0f, 1.0f,
		-dim,  dim, -dim,  0.0f, 1.0f,
		-dim, -dim, -dim,  0.0f, 0.0f,

		-dim, -dim,  dim,  0.0f, 0.0f,
		dim, -dim,  dim,  1.0f, 0.0f,
		dim,  dim,  dim,  1.0f, 1.0f,
		dim,  dim,  dim,  1.0f, 1.0f,
		-dim,  dim,  dim,  0.0f, 1.0f,
		-dim, -dim,  dim,  0.0f, 0.0f,

		-dim,  dim,  dim,  1.0f, 0.0f,
		-dim,  dim, -dim,  1.0f, 1.0f,
		-dim, -dim, -dim,  0.0f, 1.0f,
		-dim, -dim, -dim,  0.0f, 1.0f,
		-dim, -dim,  dim,  0.0f, 0.0f,
		-dim,  dim,  dim,  1.0f, 0.0f,

		dim,  dim,  dim,  1.0f, 0.0f,
		dim,  dim, -dim,  1.0f, 1.0f,
		dim, -dim, -dim,  0.0f, 1.0f,
		dim, -dim, -dim,  0.0f, 1.0f,
		dim, -dim,  dim,  0.0f, 0.0f,
		dim,  dim,  dim,  1.0f, 0.0f,

		-dim, -dim, -dim,  0.0f, 1.0f,
		dim, -dim, -dim,  1.0f, 1.0f,
		dim, -dim,  dim,  1.0f, 0.0f,
		dim, -dim,  dim,  1.0f, 0.0f,
		-dim, -dim,  dim,  0.0f, 0.0f,
		-dim, -dim, -dim,  0.0f, 1.0f,

		-dim,  dim, -dim,  0.0f, 1.0f,
		dim,  dim, -dim,  1.0f, 1.0f,
		dim,  dim,  dim,  1.0f, 0.0f,
		dim,  dim,  dim,  1.0f, 0.0f,
		-dim,  dim,  dim,  0.0f, 0.0f,
		-dim,  dim, -dim,  0.0f, 1.0f
	};

	glGenVertexArrays(1, &cubeVAO);
	glGenBuffers(1, &cubeVBO);
	glBindVertexArray(cubeVAO);
	glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), &cubeVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	cout << "Cube Geometry created" << endl;

	
}

//load texture for cube
// tex: image path
void Cube::loadTexture(std::string tex) {

	GLuint texID;
	glGenTextures(1, &texID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texID);
	cout << "     " << "Loading Cubemap's textures" << endl;
	int width, height, nrChannels;
	unsigned char* data = stbi_load(tex.c_str(), &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
		cout << "		" << "  Image loaded: " << tex << endl;
	}
	else
	{
		std::cout << "Cubemap texture failed to load at path: " << tex << std::endl;
	}
	stbi_image_free(data);
	textureID = texID;
}

//create cube
//construct and load texture
void Cube::create(std::string tex) {
	this->createCubeGeometry();
	this->loadTexture(tex); 
}

void Cube::render(Shader* shader, float x, float y, float z) {
	ModelViewMatrix = glm::mat4(1.0);
	ModelViewMatrix = glm::translate(ModelViewMatrix, glm::vec3(x, y, z));
	//ModelViewMatrix = glm::rotate(ModelViewMatrix, cube_spin, glm::vec3(0, 1, 0)); //rotation about y axis

	glUniformMatrix4fv(glGetUniformLocation(shader->handle(), "ModelViewMatrix"), 1, GL_FALSE, &ModelViewMatrix[0][0]);

	glm::mat3 normalMatrix = glm::inverseTranspose(glm::mat3(ModelViewMatrix));
	glUniformMatrix3fv(glGetUniformLocation(shader->handle(), "NormalMatrix"), 1, GL_FALSE, &normalMatrix[0][0]);

	glBindVertexArray(cubeVAO);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
	glDrawArrays(GL_TRIANGLES, 0, 36);

	cube_spin += rot_incr;
	if (cube_spin > 360) cube_spin = 0;
}