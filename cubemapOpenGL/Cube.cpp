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

	/*// First simple object
	float dim = 1.0;
	verts[0] = -dim;   verts[1] = -dim;  verts[2] = -dim;
	verts[3] = -dim;   verts[4] = dim;  verts[5] = -dim;
	verts[6] = dim;   verts[7] = dim;  verts[8] = -dim;
	verts[9] = dim;   verts[10] = -dim;  verts[11] = -dim;

	verts[12] = -dim;   verts[13] = -dim;  verts[14] = dim;
	verts[15] = -dim;   verts[16] = dim;  verts[17] = dim;
	verts[18] = dim;   verts[19] = dim;  verts[20] = dim;
	verts[21] = dim;   verts[22] = -dim;  verts[23] = dim;

	cols[0] = 0.0f;   cols[1] = 0.0f;  cols[2] = 0.0f;
	cols[3] = 0.0f;   cols[4] = 1.0f;  cols[5] = 0.0f;
	cols[6] = 0.0f;   cols[7] = 0.0f;  cols[8] = 1.0f;
	cols[9] = 1.0f;   cols[10] = 1.0f;  cols[11] = 1.0f;

	cols[12] = 1.0f;   cols[13] = 0.0f;  cols[14] = 0.0f;
	cols[15] = 0.0f;   cols[16] = 1.0f;  cols[17] = 0.0f;
	cols[18] = 0.0f;   cols[19] = 0.0f;  cols[20] = 1.0f;
	cols[21] = 1.0f;   cols[22] = 1.0f;  cols[23] = 0.0f;

	tris[0] = 0; tris[1] = 1; tris[2] = 2;
	tris[3] = 0; tris[4] = 2; tris[5] = 3;
	tris[6] = 4; tris[7] = 6; tris[8] = 5;
	tris[9] = 4; tris[10] = 7; tris[11] = 6;
	tris[12] = 1; tris[13] = 5; tris[14] = 6;
	tris[15] = 1; tris[16] = 6; tris[17] = 2;
	tris[18] = 0; tris[19] = 7; tris[20] = 4;
	tris[21] = 0; tris[22] = 3; tris[23] = 7;
	tris[24] = 0; tris[25] = 5; tris[26] = 1;
	tris[27] = 0; tris[28] = 4; tris[29] = 5;
	tris[30] = 3; tris[31] = 2; tris[32] = 7;
	tris[33] = 2; tris[34] = 6; tris[35] = 7;

	glGenVertexArrays(1, &cubeVAO);
	glGenBuffers(1, &cubeVBO);
	glBindVertexArray(cubeVAO);
	glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), &verts, GL_STATIC_DRAW);


	glGenBuffers(1, &ibo_cube);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_cube);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, numOfTris * 3 * sizeof(unsigned int), tris, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	*/
}

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

void Cube::create(std::string tex) {
	this->createCubeGeometry();
	this->loadTexture(tex); 
}

void Cube::render(Shader* shader) {
	ModelViewMatrix = glm::translate(glm::mat4(1.0), glm::vec3(0 , -40 , -120 ));	//viewing is simple translate
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