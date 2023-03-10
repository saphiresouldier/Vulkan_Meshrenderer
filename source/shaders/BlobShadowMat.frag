#version 140

#ifdef USE_PRECISION
precision highp float;
#endif

#include "common.glsl"

varying vec3 vPositionLocal;
varying vec3 vPositionWorld;

uniform int uMaskEnabled;
uniform mat4 uInverseTransformationMask;
uniform vec2 uMaskSize;
uniform sampler2D uMask;
uniform float uShadowIntensity;
uniform vec3 uShadowColor;
uniform float uShadowHardness;

void main()
{
	float distance = clamp(length(vec2(0.0, 0.0) - vPositionLocal.xy) / 0.5, 0.0, 1.0);
	//float alpha = 1.0 - distance;
	float alpha = distance < uShadowHardness ? 1.0 : (cos(((distance - uShadowHardness) / (1.0 - uShadowHardness)) * M_PI) + 1.0) * 0.5;
	if(uMaskEnabled > 0) {
	  vec2 positionImage = (uInverseTransformationMask * vec4(vPositionWorld, 1.0)).xy;
	  vec2 uv = vec2(positionImage.x / uMaskSize.x, 1.0 - (-positionImage.y / uMaskSize.y));
	  vec4 maskAlpha = texture2D(uMask, uv);
	  alpha = alpha * maskAlpha.w;
}

gl_FragColor = vec4(uShadowColor, alpha * uShadowIntensity);
}