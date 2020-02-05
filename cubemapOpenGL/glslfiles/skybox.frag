#version 150

in vec3 ex_TexCoord; //texture coord arriving from the vertex
in vec3 ex_Normal;  //normal arriving from the vertex
in vec3 ex_PositionEye;
in vec3 ex_Position;

out vec4 out_Color;   //colour for the pixel

uniform samplerCube DiffuseMap;

void main(void)
{
  
   out_Color = texture(DiffuseMap, ex_TexCoord); //show texture and lighting

}