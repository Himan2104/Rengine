uniform float sigma;
uniform float blurSize;
uniform sampler2D blurSampler;

const float pi = 3.14159265;
const float numBlurPixelsPerSide = 10.0;
const vec2  blurMultiplyVec      = vec2(1.0, 0.0);

void main() {

  // Incremental Gaussian Coefficent Calculation (See GPU Gems 3 pp. 877 - 889)
  vec3 incrementalGaussian;
  incrementalGaussian.x = 1.0f / (sqrt(2.0f * pi) * sigma);
  incrementalGaussian.y = exp(-0.5f / (sigma * sigma));
  incrementalGaussian.z = incrementalGaussian.y * incrementalGaussian.y;

  vec4 avgValue = vec4(0.0f, 0.0f, 0.0f, 0.0f);
  float coefficientSum = 0.0f;

  // Take the central sample first...
  avgValue += texture2D(blurSampler, gl_TexCoord[0].xy) * incrementalGaussian.x;
  coefficientSum += incrementalGaussian.x;
  incrementalGaussian.xy *= incrementalGaussian.yz;

  // Go through the remaining 8 vertical samples (4 on each side of the center)
  for (float i = 1.0f; i <= numBlurPixelsPerSide; i++) { 
    avgValue += texture2D(blurSampler, gl_TexCoord[0].xy - i * blurSize * 
                          blurMultiplyVec) * incrementalGaussian.x;         
    avgValue += texture2D(blurSampler, gl_TexCoord[0].xy + i * blurSize * 
                          blurMultiplyVec) * incrementalGaussian.x;         
    coefficientSum += 2 * incrementalGaussian.x;
    incrementalGaussian.xy *= incrementalGaussian.yz;
  }

  gl_FragColor = avgValue / coefficientSum;
}