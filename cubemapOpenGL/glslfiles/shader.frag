// Fragment Shader

#version 150
in vec3 ex_PositionEye;
in vec3 ex_Position;

in  vec3 ex_TexCoord; //texture coord arriving from the vertex
in  vec3 ex_Normal;  //normal arriving from the vertex

out vec4 out_Color;   //colour for the pixel

uniform samplerCube  DiffuseMap;

void main(void)
{
    float ratio = 1.00 / 1.52;
    //vec3 I = normalize(ex_Position - ex_PositionEye);
    vec3 I = normalize(ex_TexCoord-ex_PositionEye);
    
	vec3 R = refract(I, normalize(ex_Normal),0.1);
    out_Color =  vec4(texture(DiffuseMap, R).rgb,1.0) ;

//	out_Color = texture(DiffuseMap, ex_TexCoord);
	
}