// Author:
// Title:

#ifdef GL_ES
precision mediump float;
#endif

#define OCTAVES 6

uniform vec2 u_resolution;
uniform float u_time;

float random (in vec2 st) {
  return fract(sin(dot(st.xy, vec2(12.9898,78.233)))*43758.5453123);
}

// Based on Morgan McGuire @morgan3d
// https://www.shadertoy.com/view/4dS3Wd
float noise (in vec2 st) {
  vec2 i = floor(st);
  vec2 f = fract(st);

  // Four corners in 2D of a tile
  float a = random(i);
  float b = random(i + vec2(1.0, 0.0));
  float c = random(i + vec2(0.0, 1.0));
  float d = random(i + vec2(1.0, 1.0));

  vec2 u = f * f * (3.0 - 2.0 * f);

  return mix(a, b, u.x) +
      (c - a)* u.y * (1.0 - u.x) +
      (d - b) * u.x * u.y;
}

float fbm (in vec2 st) {
  // Initial values
  float value = 0.0;
  float amplitude = .5;
  float frequency = 0.;
  //
  // Loop of octaves
  for (int i = 0; i < OCTAVES; i++) {
    value += amplitude * noise(st);
    st *= 2.;
    amplitude *= .5;
  }
  return value;
}

vec3 blue_nebulae (in vec2 st) {
  float fb = fbm(st*3.0) / 20.0;
  return vec3(fb / 4.0, fb / 4.0, fb / 2.0);
}

vec3 green_nebulae (in vec2 st) {
  float fb = fbm(st*3.0) / 20.0;
  return vec3(fb / 4.0, fb / 2.0, fb / 4.0);
}

vec3 red_nebulae (in vec2 st) {
  float fb = fbm(st*3.0) / 20.0;
  return vec3(fb / 2.0, fb / 4.0, fb / 4.0);
}

vec2 tile(vec2 _st, float _zoom) {
_st *= _zoom;
return fract(_st);
}

vec3 starfield(in vec2 pos) {
  return vec3(step(0.999, random(fract(pos))));
}

void main() {
  vec2 st = gl_FragCoord.xy/u_resolution.xy;
  vec3 color = vec3(0.0);

  // color += starfield(st*3.000);

  st.x += u_time*0.01;
  color += blue_nebulae(st*1.0);

  st.x += u_time*0.01;
  color += green_nebulae(st*2.0);

  st.x += u_time*0.01;
  color += red_nebulae(st*3.0);

  gl_FragColor = vec4(color,1.0);
}