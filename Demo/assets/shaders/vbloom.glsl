uniform sampler2D sourceTexture;
uniform float sigma;
uniform float glowMultiplier;
uniform float height;

const int KERNEL_SIZE = 10;
float glow = glowMultiplier / (sigma * sqrt(2.0 * 3.14159));

float blurWeight(float x)
{
    return (glow * exp(-(x*x) / (2.0 * sigma * sigma)));
}

void main()
{
    vec4 color = vec4(0.0);
    vec2 texCoord = gl_TexCoord[0].xy;

    for (int i = -KERNEL_SIZE; i <= KERNEL_SIZE; i++)
    {
        texCoord.y = gl_TexCoord[0].y + (i / height);
        color += texture2D(sourceTexture, texCoord) * blurWeight(i);
    }

    gl_FragColor = color;
}
