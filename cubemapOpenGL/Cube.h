#pragma once
class Cube
{
private:
	float cube_spin = 0, rot_incr = 0;

	GLuint ibo_cube;
	unsigned int cubeVAO;
	unsigned int cubeVBO;


	void loadTexture(std::string tex);
	void createCubeGeometry();

	glm::mat4 ModelViewMatrix;  // matrix for the modelling and viewing

public:
	Cube();
	~Cube();

	void create(std::string tex);
	
	void render(Shader* shader);

	GLuint textureID;
};

