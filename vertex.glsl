#version 410 core

layout(location=0) in vec3 vertex;




void main(){
gl_Position=vec4(vertex.x,vertex.y,vertex.z,1);
}