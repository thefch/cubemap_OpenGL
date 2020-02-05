#include "Header.h"

CubeMap::CubeMap()
{
}


CubeMap::~CubeMap()
{
}


void CubeMap::createCubemapGeometry()
{

	// First simple object
	float dim = 30.0;
	verts[0] = -dim;   verts[1] = -dim;  verts[2] = -dim;
	verts[3] = -dim;   verts[4] = dim;  verts[5] = -dim;
	verts[6] = dim;   verts[7] = dim;  verts[8] = -dim;
	verts[9] = dim;   verts[10] = -dim;  verts[11] = -dim;

	verts[12] = -dim;   verts[13] = -dim;  verts[14] = dim;
	verts[15] = -dim;   verts[16] = dim;  verts[17] = dim;
	verts[18] = dim;   verts[19] = dim;  verts[20] = dim;
	verts[21] = dim;   verts[22] = -dim;  verts[23] = dim;

	/*cols[0] = 0.0f;   cols[ 1] = 0.0f;  cols[ 2] = 0.0f;
	cols[3] = 0.0f;   cols[ 4] = 1.0f;  cols[ 5] = 0.0f;
	cols[6] = 0.0f;   cols[ 7] = 0.0f;  cols[ 8] = 1.0f;
	cols[9] = 1.0f;   cols[10] = 1.0f;  cols[11] = 1.0f;

	cols[12] = 1.0f;   cols[13] = 0.0f;  cols[14] = 0.0f;
	cols[15] = 0.0f;   cols[16] = 1.0f;  cols[17] = 0.0f;
	cols[18] = 0.0f;   cols[19] = 0.0f;  cols[20] = 1.0f;
	cols[21] = 1.0f;   cols[22] = 1.0f;  cols[23] = 0.0f;*/

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


	glGenVertexArrays(1, &cubemapVAO);
	glGenBuffers(1, &cubemapVBO);
	glBindVertexArray(cubemapVAO);
	glBindBuffer(GL_ARRAY_BUFFER, cubemapVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), &verts, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);




	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &ibo_cubemap);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_cubemap);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, numOfTris * 3 * sizeof(unsigned int), tris, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

	cout << "CubeMap Geometry created" << endl;
}

void CubeMap::loadCubeMapTextures(vector<std::string> faces) {
	GLenum axis[6] = {
		GL_TEXTURE_CUBE_MAP_POSITIVE_X , GL_TEXTURE_CUBE_MAP_NEGATIVE_X ,
		GL_TEXTURE_CUBE_MAP_POSITIVE_Y , GL_TEXTURE_CUBE_MAP_NEGATIVE_Y ,
		GL_TEXTURE_CUBE_MAP_POSITIVE_Z , GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
	};

	GLuint texID;
	glGenTextures(1, &texID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texID);
	std::cout << "     " << "Loading Cubemap's textures" << endl;
	for (int i = 0; i < 6; i++) {
		int width, height, nrChannels;
		unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(axis[i], 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
			std::cout << "		" << i << "  Image loaded: " << faces[i] << endl;
		}
		else
		{
			std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
		}
		stbi_image_free(data);

	}

	this->textureID = texID;
}

void CubeMap::create(std::vector<std::string> faces) {
	this->createCubemapGeometry();
	this->loadCubeMapTextures(faces);
}

void CubeMap::renderCubeMap(Shader* shader) {
	glDepthMask(GL_FALSE);
	//ModelViewMatrix = glm::mat4(1.0);
	ModelViewMatrix = glm::translate(glm::mat4(1.0), glm::vec3(0.0, 0.0, -5.0));	//viewing is simple translate
	//ModelViewMatrix = glm::rotate(ModelViewMatrix, cubemap_spin, glm::vec3(0, 1, 0)); //rotation about y axis

	glUniformMatrix4fv(glGetUniformLocation(shader->handle(), "ModelViewMatrix"), 1, GL_FALSE, &ModelViewMatrix[0][0]);

	glm::mat3 normalMatrix = glm::inverseTranspose(glm::mat3(ModelViewMatrix));
	glUniformMatrix3fv(glGetUniformLocation(shader->handle(), "NormalMatrix"), 1, GL_FALSE, &normalMatrix[0][0]);

	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
	glBindVertexArray(cubemapVAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_cubemap);
	glDrawElements(GL_TRIANGLES, numOfTris * 3, GL_UNSIGNED_INT, 0);


	glDepthMask(GL_TRUE);

	cubemap_spin += rot_incr;
	if (cubemap_spin > 360) cubemap_spin = 0;
}