#version 150

uniform mat4 ModelViewMatrix;
uniform mat4 ProjectionMatrix;
uniform mat3 NormalMatrix;
uniform vec3 cameraPos;

//uniform mat4 ViewMatrix;

in  vec3 in_Position;  // Position coming in
in  vec3 in_TexCoord;  // texture coordinate coming in
in  vec3 in_Normal;    // vertex normal used for lighting

out vec3 ex_TexCoord;  // exiting texture coord
out vec3 ex_Normal;    // exiting normal transformed by the normal matrix
out vec3 ex_Position;
out vec3 ex_PositionEye;
out vec3 out_Position;

void main(void)
{

	ex_Position = vec3(ModelViewMatrix * vec4(in_Position,1.0)); //eye position

    ex_Normal= vec3(NormalMatrix);
	gl_Position = ProjectionMatrix * ModelViewMatrix * vec4(in_Position, 1.0);


}