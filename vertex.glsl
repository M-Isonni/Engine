#version 410 core

layout(location=0) in vec3 vertex;

uniform float x_variable;
uniform float y_variable;

void main(){
gl_Position=vec4(vertex.x+x_variable,vertex.y+y_variable,vertex.z,1);
}