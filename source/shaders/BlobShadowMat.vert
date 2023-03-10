attribute vec3 aPosition;

varying vec3 vPositionLocal;
varying vec3 vPositionWorld;

uniform mat4 uMVP;
uniform mat4 uModel;

void main() {
	vec4 vertexPos = vec4(aPosition, 1.0);
	gl_Position = uMVP * vertexPos;
	vPositionLocal = aPosition;
	vPositionWorld = (uModel * vertexPos).xyz;
}