// Fragment Shader

#version 150

in vec3 ex_Position;
in vec3 ex_TexCoord; //texture coord arriving from the vertex
in vec3 ex_Normal;  //normal arriving from the vertex
in vec3 out_Position;

out vec4 out_Color;   //colour for the pixel

uniform samplerCube  DiffuseMap;

uniform mat4 ModelViewMatrix;
uniform mat4 ProjectionMatrix;
uniform mat3 NormalMatrix;
uniform vec3 cameraPos;

void main(void)
{
    float ratio = 1.00 / 1.52;
    ratio = 1;
    mat3 invNormalM      = mat3(ModelViewMatrix);

    vec3 viewIncident    = normalize(ex_Position);
    vec3 viewNormal      = normalize(ex_Normal);

    //have either refract or reflect

    vec3 worldReflection = invNormalM * refract(viewIncident, viewNormal,ratio);

    //uncomment this for reflect instead refract
    //vec3 worldReflection = invNormalM * reflect(viewIncident, viewNormal);

    out_Color            = vec4(texture(DiffuseMap, worldReflection).rgb, 1.0);

}