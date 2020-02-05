#pragma once
class CubeMap
{
private:
	const int numOfTris = 12;
	unsigned int tris[36];
	float verts[24];
	unsigned int cubemapVAO;		    // vertex array object
	unsigned int cubemapVBO;		// two VBOs - used for colours and vertex data
	GLuint ibo_cubemap = 0;

	float rot_incr = 0.1;
	float cubemap_spin = 0.0;


	void createCubemapGeometry();
	void loadCubeMapTextures(std::vector<std::string> faces);
public:
	CubeMap();
	~CubeMap();
	
	void create(std::vector<std::string> faces);

	void renderCubeMap(Shader* shader);

	GLuint textureID;

	glm::mat4 ModelViewMatrix;  // matrix for the modelling and viewing

};

