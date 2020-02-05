#version 150

uniform mat4 ModelViewMatrix;
uniform mat4 ProjectionMatrix;
uniform mat3 NormalMatrix;
uniform mat4 ViewMatrix;

in  vec3 in_Position;  // Position coming in
in  vec3 in_TexCoord;  // texture coordinate coming in
in  vec3 in_Normal;    // vertex normal used for lighting

out vec3 ex_TexCoord;  // exiting texture coordW
out vec3 ex_PositionEye; 
out vec3 ex_LightDir; 
out vec3 ex_Normal;    // exiting normal transformed by the normal matrix
out vec3 ex_Position;

void main(void)
{
	gl_Position = ProjectionMatrix * ModelViewMatrix * vec4(in_Position, 1.0);
	
	ex_TexCoord = in_Position;

	//ex_Normal = mat3(transpose(inverse(ModelViewMatrix))) * in_Normal;
	/*ex_Normal = NormalMatrix*in_Normal; 

	ex_PositionEye = vec3((ModelViewMatrix * vec4(in_Position, 1.0)));

	ex_Position = in_Position;
	//ex_LightDir = vec3(ViewMatrix * LightPos);
	*/
}