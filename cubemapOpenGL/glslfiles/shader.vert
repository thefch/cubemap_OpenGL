#version 150

uniform mat4 ModelViewMatrix;
uniform mat4 ProjectionMatrix;
uniform mat3 NormalMatrix;
uniform mat4 ViewMatrix;

in  vec3 in_Position;  // Position coming in
in  vec3 in_TexCoord;  // texture coordinate coming in
in  vec3 in_Normal;    // vertex normal used for lighting

out vec3 ex_TexCoord;  // exiting texture coord
out vec3 ex_Normal;    // exiting normal transformed by the normal matrix
out vec3 ex_Position;

void main(void)
{
	gl_Position = ProjectionMatrix *ModelViewMatrix * vec4(in_Position, 1.0);
	ex_Position = vec3(ModelViewMatrix * vec4(in_Position,1.0));

	ex_Normal = vec3(NormalMatrix);

	ex_TexCoord = in_Position;
	
	//out_Position = in_Poisition;
}