#version 410 core

layout(location=0) in vec3 vertex;
uniform float x_variable;
uniform float y_variable;
uniform float scaleX;
uniform float scaleY;
uniform vec4 color;

out vec4 out_color;

void main(){
gl_Position=vec4(vertex.x * scaleX + x_variable, vertex.y * scaleY + y_variable ,vertex.z,1);
out_color = color;
}