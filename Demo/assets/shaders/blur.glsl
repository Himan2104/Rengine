uniform sampler2D texture;
uniform float blur_radius;

void main()
{
    vec2 offx = vec2(blur_radius, 0.0);
    vec2 offy = vec2(0.0, blur_radius);

    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy)                       * 10.0 +
                 texture2D(texture, gl_TexCoord[0].xy - offx/4.0 - offy/4.0) * 8.0 +
                 texture2D(texture, gl_TexCoord[0].xy - offx/4.0 + offy/4.0) * 8.0 +
                 texture2D(texture, gl_TexCoord[0].xy + offx/4.0 - offy/4.0) * 8.0 +
                 texture2D(texture, gl_TexCoord[0].xy + offx/4.0 + offy/4.0) * 8.0 +
                 texture2D(texture, gl_TexCoord[0].xy - offx/2.0 - offy/2.0) * 6.0 +
                 texture2D(texture, gl_TexCoord[0].xy - offx/2.0 + offy/2.0) * 6.0 +
                 texture2D(texture, gl_TexCoord[0].xy + offx/2.0 - offy/2.0) * 6.0 +
                 texture2D(texture, gl_TexCoord[0].xy + offx/2.0 + offy/2.0) * 6.0 +
                 texture2D(texture, gl_TexCoord[0].xy - offx - offy)         * 4.0 +
                 texture2D(texture, gl_TexCoord[0].xy - offx + offy)         * 4.0 +
                 texture2D(texture, gl_TexCoord[0].xy + offx - offy)         * 4.0 +
                 texture2D(texture, gl_TexCoord[0].xy + offx + offy)         * 4.0 +
                 texture2D(texture, gl_TexCoord[0].xy - offx*1.2 - offy*1.2) * 2.0 +
                 texture2D(texture, gl_TexCoord[0].xy - offx*1.2 + offy*1.2) * 2.0 +
                 texture2D(texture, gl_TexCoord[0].xy + offx*1.2 - offy*1.2) * 2.0 +
                 texture2D(texture, gl_TexCoord[0].xy + offx*1.2 + offy*1.2) * 2.0 +
                 texture2D(texture, gl_TexCoord[0].xy - offx*1.4 - offy*1.4) * 1.0 +
                 texture2D(texture, gl_TexCoord[0].xy - offx*1.4 + offy*1.4) * 1.0 +
                 texture2D(texture, gl_TexCoord[0].xy + offx*1.4 - offy*1.4) * 1.0 +
                 texture2D(texture, gl_TexCoord[0].xy + offx*1.4 + offy*1.4) * 1.0;

    gl_FragColor =  gl_Color * (pixel / 16.0);
}