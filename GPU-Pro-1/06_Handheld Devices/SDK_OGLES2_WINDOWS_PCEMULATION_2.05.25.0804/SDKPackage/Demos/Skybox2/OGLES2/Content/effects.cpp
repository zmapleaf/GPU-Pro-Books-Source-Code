// This file was created by Filewrap 1.1
// Little endian mode
// DO NOT EDIT

#include "../PVRTMemoryFileSystem.h"

// using 32 bit to guarantee alignment.
#ifndef A32BIT
 #define A32BIT static const unsigned int
#endif

// ******** Start: effects.pfx ********

// File data
static const char _effects_pfx[] = 
	"[HEADER]\r\n"
	"\tVERSION\t\t01.00.00.00\r\n"
	"\tDESCRIPTION texture example\r\n"
	"\tCOPYRIGHT\tImg Tec\r\n"
	"[/HEADER]\r\n"
	"\r\n"
	"// Define the textures that we'll be using\r\n"
	"[TEXTURES] \r\n"
	"\tFILE Balloon \t Balloon.pvr\t\tLINEAR-LINEAR-LINEAR\r\n"
	"\tFILE Balloon_pvr Balloon_pvr.pvr\tLINEAR-LINEAR-LINEAR\r\n"
	"\tFILE Noise \t \t Noise.pvr\t\t\tLINEAR-LINEAR-LINEAR\r\n"
	"\tFILE Skybox  \t Skybox.pvr\t\t\tLINEAR-LINEAR-LINEAR CLAMP-CLAMP\r\n"
	"\tFILE SkyboxMidnight SkyboxMidnight.pvr\tLINEAR-LINEAR-LINEAR CLAMP-CLAMP\r\n"
	"[/TEXTURES]\r\n"
	"\r\n"
	"//Effect 0//////////////////////////////////////////////////////////////////////\r\n"
	"//\r\n"
	"// This effect is used for the skybox. The inverse of the vertex positions for \r\n"
	"// the skybox are used as texture coordinates for accessing the skybox texture.\r\n"
	"//\r\n"
	"\r\n"
	"[VERTEXSHADER]\r\n"
	"\tNAME \t\tskybox_vert\r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\tattribute highp   vec3\tmyVertex;\r\n"
	"\t\tuniform   mediump mat4\tmyMVPMatrix;\r\n"
	"\t\tvarying   highp   vec3  EyeDir;\r\n"
	"\r\n"
	"\t\tvoid main(void)\r\n"
	"\t\t{             \r\n"
	"\t\t\tEyeDir = -myVertex;\r\n"
	"\t\t\tgl_Position = myMVPMatrix * vec4(myVertex,1.0);\r\n"
	"\t\t}\r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/VERTEXSHADER]\r\n"
	"\r\n"
	"[FRAGMENTSHADER] \r\n"
	"\tNAME \t\tskybox_frag\r\n"
	"\t\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\tvarying highp vec3  EyeDir;\r\n"
	"\t\tuniform samplerCube myCubeMap;\r\n"
	"\t\t\r\n"
	"\t\tvoid main (void)\r\n"
	"\t\t{\r\n"
	"\t\t    gl_FragColor = textureCube(myCubeMap, EyeDir);\r\n"
	"\t\t}\r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/FRAGMENTSHADER]\r\n"
	"\r\n"
	"[EFFECT] \r\n"
	"\tNAME \tskybox_effect\r\n"
	"\t\t\r\n"
	"\t// GLOBALS UNIFORMS\r\n"
	"\tUNIFORM myMVPMatrix \t\tWORLDVIEWPROJECTION\r\n"
	"\tUNIFORM\tmyCubeMap\t\t\tTEXTURE0\r\n"
	"\r\n"
	"\t// ATTRIBUTES\r\n"
	"\tATTRIBUTE \tmyVertex\tPOSITION\r\n"
	"\r\n"
	"\tVERTEXSHADER \tskybox_vert\r\n"
	"\tFRAGMENTSHADER \tskybox_frag\r\n"
	"\tTEXTURE 0 Skybox\r\n"
	"[/EFFECT]\r\n"
	"\r\n"
	"//Effect 1 /////////////////////////////////////////////////////////////////////\r\n"
	"//\r\n"
	"// This effect displays a textured balloon with some simple lighting.\r\n"
	"//\r\n"
	"\r\n"
	"[VERTEXSHADER]\r\n"
	"\tNAME \t\tballoon_vert1\r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\tattribute highp vec3\tmyVertex;\r\n"
	"\t\tattribute mediump vec3\tmyNormal;\r\n"
	"\t\tattribute mediump vec2\tmyUV;\r\n"
	"\t\tuniform mediump mat4\tmyMVPMatrix;\r\n"
	"\t\tuniform mediump mat3\tmyModelViewIT;\r\n"
	"\t\tuniform mediump vec3\tmyLightDirection;\r\n"
	"\t\tuniform mediump float\tfAnim;\r\n"
	"\t\tvarying mediump float\tfDot;\r\n"
	"\t\tvarying lowp vec2\tfTexCoord;\r\n"
	"\t\t\r\n"
	"\t\tvoid main(void)\r\n"
	"\t\t{\r\n"
	"\t\t\tgl_Position = myMVPMatrix * vec4(myVertex,1);\r\n"
	"\t\t\tfTexCoord = myUV;\r\n"
	"\t\t\tmediump vec3 fTransNormal = myModelViewIT * myNormal;\r\n"
	"\t\t\tfDot = 0.1 * dot(fTransNormal, myLightDirection) + 0.9;\r\n"
	"\t\t}\r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/VERTEXSHADER]\r\n"
	"\r\n"
	"[FRAGMENTSHADER] \r\n"
	"\tNAME \t\tballoon_frag1\r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\tuniform \t\tsampler2D \tsampler2d;\r\n"
	"\t\tvarying mediump float\t\tfDot;\r\n"
	"\t\tvarying lowp vec2\t\tfTexCoord;\r\n"
	"\t\t\r\n"
	"\t\tvoid main (void)\r\n"
	"\t\t{\r\n"
	"\t\t    gl_FragColor = texture2D(sampler2d,fTexCoord) * fDot;\r\n"
	"\t\t}\r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/FRAGMENTSHADER]\r\n"
	"\r\n"
	"[EFFECT] \r\n"
	"\tNAME \tballoon_effect1\r\n"
	"\t\t\r\n"
	"\t// GLOBALS UNIFORMS\r\n"
	"\tUNIFORM myModelViewIT \t\tWORLDVIEWIT\r\n"
	"\tUNIFORM myMVPMatrix \t\tWORLDVIEWPROJECTION\r\n"
	"\tUNIFORM\tmyLightDirection\tLIGHTDIRECTION\r\n"
	"\tUNIFORM\tsampler2d\t\t\tTEXTURE0\r\n"
	"\r\n"
	"\t// ATTRIBUTES\r\n"
	"\tATTRIBUTE \tmyVertex\tPOSITION\r\n"
	"\tATTRIBUTE\tmyNormal\tNORMAL\r\n"
	"\tATTRIBUTE\tmyUV\t\tUV\r\n"
	"\r\n"
	"\tVERTEXSHADER \tballoon_vert1\r\n"
	"\tFRAGMENTSHADER \tballoon_frag1\r\n"
	"\tTEXTURE 0 Balloon_pvr\r\n"
	"[/EFFECT]\r\n"
	"\r\n"
	"//Effect 2 /////////////////////////////////////////////////////////////////////\r\n"
	"//\r\n"
	"// This effect creates a burning effect that burns the balloon from the basket \r\n"
	"// up. It does this by calculating whether a pixel is below at least one of \r\n"
	"// three thresholds (which rise over time). If it is not then the balloon \r\n"
	"// is textured and lit in the same way as effect 1 otherwise the burn effect is \r\n"
	"// applied according to the threshold it is below.\r\n"
	"//\r\n"
	"\r\n"
	"[VERTEXSHADER]\r\n"
	"\tNAME \t\tballoon_vert2\r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\tattribute vec3\tmyVertex;\r\n"
	"\t\tattribute vec3\tmyNormal;\r\n"
	"\t\tattribute vec2\tmyUV;\r\n"
	"\t\t\r\n"
	"\t\tuniform mat4\tmyMVPMatrix;\r\n"
	"\t\tuniform mat3\tmyModelViewIT;\r\n"
	"\t\t\r\n"
	"\t\tuniform mediump vec3\tmyLightDirection;\r\n"
	"\t\tuniform highp float fAnim;\r\n"
	"\t\t\r\n"
	"\t\tvarying float\tfDiffuse;\r\n"
	"\t\tvarying lowp   vec2 fTexCoord;\r\n"
	"\t\tvarying lowp   vec2 fTexCoord2;\r\n"
	"\t\t\r\n"
	"\t\tvarying highp vec3  fPosition;\r\n"
	"\t\tvarying highp float fBurn;\r\n"
	"\t\t\r\n"
	"\t\tvoid main(void)\r\n"
	"\t\t{\r\n"
	"\t\t\tgl_Position = myMVPMatrix * vec4(myVertex,1);\r\n"
	"\t\t\t\r\n"
	"\t\t\tfDiffuse = 0.1 * dot(myModelViewIT * myNormal, myLightDirection) + 0.9;\r\n"
	"\t\t\t\r\n"
	"\t\t\tfPosition =  myVertex * 0.05;\r\n"
	"\t\t\t\r\n"
	"\t\t\thighp float fOffset = fract(0.999 * fAnim) * 2.1;\r\n"
	"\t\t\tfBurn = fOffset - 0.53 * (fPosition.y + 0.2);\t\r\n"
	"\t\t    fBurn = clamp(fBurn, 0.0, 1.0);\r\n"
	"\t\t    \r\n"
	"\t\t    fTexCoord = myUV;\r\n"
	"\t\t    fTexCoord2 = vec2(fPosition.x + fPosition.z * fPosition.z, fPosition.y + 0.5 * fPosition.z + 0.5 * fPosition.x * fPosition.x);\r\n"
	"\t\t}\r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/VERTEXSHADER]\r\n"
	"\r\n"
	"[FRAGMENTSHADER] \r\n"
	"\tNAME \t\tballoon_frag2\r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\tvarying highp float\tfDiffuse;\r\n"
	"\t\tvarying lowp vec2\tfTexCoord;\r\n"
	"\t\tvarying lowp vec2  fTexCoord2;\r\n"
	"\r\n"
	"\t\tuniform sampler2D sampler2d;\r\n"
	"\t\tuniform sampler2D Noise;\r\n"
	"\t\t\r\n"
	"\t\tvarying highp float fBurn;\r\n"
	"\t\t\r\n"
	"\t\thighp vec3 reflect (void)\r\n"
	"\t\t{\t\r\n"
	"\t\t\treturn texture2D(sampler2d,fTexCoord).rgb * fDiffuse;\r\n"
	"\t\t}\r\n"
	"\t\t\r\n"
	"\t\tvoid main (void)\r\n"
	"\t\t{\r\n"
	"\t\t    highp vec4  noisevec;\r\n"
	"\t\t    highp vec3  color;\r\n"
	"\t\t    highp float intensity;\r\n"
	"\t\t\r\n"
	"\t\t    noisevec = texture2D(Noise, fTexCoord2);\r\n"
	"\t\t \r\n"
	"\t\t    intensity = 0.6 * (noisevec.x + noisevec.y + noisevec.z + noisevec.w);\r\n"
	"\t\t    intensity = abs(intensity - 1.0);\r\n"
	"\t\t    intensity = clamp(intensity, 0.0, 1.0);\r\n"
	"\t\t\r\n"
	"\t\t    if (intensity < fBurn)\r\n"
	"\t\t\t\tcolor = vec3(0.0);\r\n"
	"\t\t    else if(intensity < 1.5 * fBurn)\r\n"
	"\t\t\t\tcolor = vec3(0.1);\r\n"
	"\t\t    else if(intensity < 1.7 * fBurn)\r\n"
	"\t\t\t\tcolor = vec3(1.0, 10.0 * (-intensity + 1.7 * fBurn) ,0.0);\r\n"
	"\t\t    else\r\n"
	"\t\t\t\tcolor = reflect();\r\n"
	"\t\t\r\n"
	"\t\t    gl_FragColor = vec4(color, 1);\r\n"
	"\t\t}\r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/FRAGMENTSHADER]\r\n"
	"\t\r\n"
	"[EFFECT] \r\n"
	"\tNAME \tballoon_effect2\r\n"
	"\t\t\r\n"
	"\t// GLOBALS UNIFORMS\r\n"
	"\tUNIFORM myModelViewIT \t\tWORLDVIEWIT\r\n"
	"\tUNIFORM myMVPMatrix \t\tWORLDVIEWPROJECTION\r\n"
	"\tUNIFORM\tmyLightDirection\tLIGHTDIRECTION\r\n"
	"\tUNIFORM\tsampler2d\t\t\tTEXTURE0\r\n"
	"\tUNIFORM\tNoise\t\t\t\tTEXTURE1\r\n"
	"\r\n"
	"\t// ATTRIBUTES\r\n"
	"\tATTRIBUTE \tmyVertex\tPOSITION\r\n"
	"\tATTRIBUTE\tmyNormal\tNORMAL\r\n"
	"\tATTRIBUTE\tmyUV\t\tUV\r\n"
	"\r\n"
	"\tVERTEXSHADER \tballoon_vert2\r\n"
	"\tFRAGMENTSHADER \tballoon_frag2\r\n"
	"\tTEXTURE 0 Balloon_pvr\r\n"
	"\tTEXTURE 1 Noise\r\n"
	"[/EFFECT]\r\n"
	"\r\n"
	"//Effect 3 /////////////////////////////////////////////////////////////////////\r\n"
	"//\r\n"
	"// Effect 3 is very similar to effect 1 in that it displays a textured \r\n"
	"// balloon with diffuse lighting. However, it applies two textures to the \r\n"
	"// balloon. The second texture is the skybox cube map which is applied using a \r\n"
	"// reflection vector as texture coordinates. This makes it look like the balloon \r\n"
	"// is reflecting the skybox.\r\n"
	"//\r\n"
	"\r\n"
	"[VERTEXSHADER]\r\n"
	"\tNAME \t\tballoon_vert3\r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\tattribute vec3\tmyVertex;\r\n"
	"\t\tattribute vec3\tmyNormal;\r\n"
	"\t\tattribute vec2\tmyUV;\r\n"
	"\t\t\r\n"
	"\t\tuniform mat4\tmyMVPMatrix;\r\n"
	"\t\tuniform mat3\tmyModelViewIT;\r\n"
	"\t\tuniform mat4\tmyModelView;\r\n"
	"\t\tuniform mat3 \tmyViewIT;\r\n"
	"\t\t\r\n"
	"\t\tuniform mediump vec3\tmyLightDirection;\r\n"
	"\t\tvarying highp\tfloat\tfDiffuse;\r\n"
	"\t\tvarying lowp\tvec2\tfTexCoord;\r\n"
	"\r\n"
	"\t\tuniform mediump float myFrame;\r\n"
	"\t\tuniform mediump float fAnim;\r\n"
	"\t\tvarying lowp vec3 fReflectVec;\r\n"
	"\t\t\r\n"
	"\t\tvoid main(void)\r\n"
	"\t\t{\r\n"
	"\t\t\tmediump vec4 myVertex4 = vec4(myVertex, 1);\r\n"
	"\t\t\t\r\n"
	"\t\t\tgl_Position = myMVPMatrix * myVertex4;\r\n"
	"\t\t\tmediump vec3 fTransNormal = myModelViewIT * myNormal;\r\n"
	"\t\t\t\r\n"
	"\t\t\tfDiffuse = (0.05 * dot(fTransNormal, myLightDirection) + 0.95) * fAnim * 0.5;\r\n"
	"\t\t\t\r\n"
	"\t\t\tmediump vec3 EyeDir = vec3(0.0,-1.0,0.0) - vec3(myModelView * myVertex4);\t\r\n"
	"\t\t\tfReflectVec = myViewIT * reflect(EyeDir, normalize(fTransNormal) );\r\n"
	"\t\t\t\r\n"
	"\t\t\tfTexCoord\t= myUV.st;\r\n"
	"\t\t}\r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/VERTEXSHADER]\r\n"
	"\r\n"
	"[FRAGMENTSHADER] \r\n"
	"\tNAME \t\tballoon_frag3\r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\tvarying highp \tfloat\tfDiffuse;\r\n"
	"\t\tvarying lowp \tvec2\tfTexCoord;\r\n"
	"\t\tvarying lowp \tvec3 \tfReflectVec;\r\n"
	"\t\t\t\r\n"
	"\t\tuniform sampler2D \tsampler2d;\r\n"
	"\t\tuniform samplerCube myCubeMap;\r\n"
	"\t\t\r\n"
	"\t\tvoid main (void)\r\n"
	"\t\t{    \r\n"
	"\t\t\tgl_FragColor = textureCube(myCubeMap, fReflectVec) + texture2D(sampler2d, fTexCoord);\r\n"
	"\t\t\tgl_FragColor *= fDiffuse;\r\n"
	"\t\t}\r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/FRAGMENTSHADER]\r\n"
	"\r\n"
	"[EFFECT] \r\n"
	"\tNAME \tballoon_effect3\r\n"
	"\t\t\r\n"
	"\t// GLOBALS UNIFORMS\r\n"
	"\tUNIFORM myModelViewIT \t\tWORLDVIEWIT\r\n"
	"\tUNIFORM myMVPMatrix \t\tWORLDVIEWPROJECTION\r\n"
	"\tUNIFORM myModelView\t\t\tWORLDVIEW\r\n"
	"\tUNIFORM myViewIT\t\t\tVIEWIT\r\n"
	"\tUNIFORM\tmyLightDirection\tLIGHTDIRECTION\r\n"
	"\tUNIFORM\tsampler2d\t\t\tTEXTURE0\r\n"
	"\tUNIFORM\tmyCubeMap\t\t\tTEXTURE1\r\n"
	"\r\n"
	"\t// ATTRIBUTES\r\n"
	"\tATTRIBUTE \tmyVertex\tPOSITION\r\n"
	"\tATTRIBUTE\tmyNormal\tNORMAL\r\n"
	"\tATTRIBUTE\tmyUV\t\tUV\r\n"
	"\r\n"
	"\tVERTEXSHADER \tballoon_vert3\r\n"
	"\tFRAGMENTSHADER \tballoon_frag3\r\n"
	"\tTEXTURE 0 Balloon\r\n"
	"\tTEXTURE 1 Skybox\r\n"
	"[/EFFECT]\r\n"
	"\r\n"
	"//Effect 4 /////////////////////////////////////////////////////////////////////\r\n"
	"//\r\n"
	"// This effect alters the transparency of the balloon based on an external \r\n"
	"// variable calculated in the app. The basket isn't affected as much as the \r\n"
	"// balloon as pixels over the height of 0.1 are given a lower alpha value.\r\n"
	"//\r\n"
	"\r\n"
	"[VERTEXSHADER]\r\n"
	"\tNAME \t\tballoon_vert4\r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\tattribute vec3\tmyVertex;\r\n"
	"\t\tattribute vec3\tmyNormal;\r\n"
	"\t\tattribute vec2\tmyUV;\r\n"
	"\t\t\r\n"
	"\t\tuniform mat4\tmyMVPMatrix;\r\n"
	"\t\tuniform mat3\tmyModelViewIT;\r\n"
	"\t\tuniform mediump vec3\tmyLightDirection;\r\n"
	"\t\tuniform mediump float fAnim;\r\n"
	"\t\t\r\n"
	"\t\tvarying float\tfDiffuse;\r\n"
	"\t\tvarying lowp vec2\tfTexCoord;\r\n"
	"\r\n"
	"\t\tvarying mediump float fHeight;\r\n"
	"\t\tvarying mediump float fAlteredAnim;\r\n"
	"\t\t\r\n"
	"\t\tvoid main(void)\r\n"
	"\t\t{\r\n"
	"\t\t\tgl_Position = myMVPMatrix * vec4(myVertex, 1);\r\n"
	"\t\t\t\r\n"
	"\t\t\tmediump vec3 fTransNormal = myModelViewIT * myNormal;\r\n"
	"\t\t\tfDiffuse = (0.05 * dot(fTransNormal, myLightDirection) + 0.95) * 0.5;\r\n"
	"\t\t\r\n"
	"\t\t\tfTexCoord = myUV;\r\n"
	"\r\n"
	"\t\t\tfHeight = myVertex.y;\r\n"
	"\t\t\t\r\n"
	"\t\t\tfAlteredAnim = (1.0 - fAnim) + fAnim;\r\n"
	"\t\t}\r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/VERTEXSHADER]\r\n"
	"\r\n"
	"[FRAGMENTSHADER] \r\n"
	"\tNAME \t\tballoon_frag4\r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\tvarying highp \tfloat\tfDiffuse;\r\n"
	"\t\tvarying lowp \tvec2\tfTexCoord;\r\n"
	"\t\tvarying mediump float \tfHeight;\r\n"
	"\t\tvarying mediump float \tfAlteredAnim;\r\n"
	"\t\t\r\n"
	"\t\tuniform sampler2D sampler2d;\r\n"
	"\r\n"
	"\t\tuniform bool bBackFace;\r\n"
	"\t\t\r\n"
	"\t\tvoid main (void)\r\n"
	"\t\t{\r\n"
	"\t\t\tgl_FragColor.rgb = texture2D(sampler2d, fTexCoord).rgb * fDiffuse;\r\n"
	"\t\t\r\n"
	"\t\t\tif(fHeight > -0.1)\r\n"
	"\t\t\t{\r\n"
	"\t\t\t\tif(bBackFace)\r\n"
	"\t\t\t\t\tgl_FragColor.a = fAlteredAnim * 0.3;\r\n"
	"\t\t\t\telse\r\n"
	"\t\t\t\t\tgl_FragColor.a = 0.0;\r\n"
	"\t\t\t}\r\n"
	"\t\t\telse \r\n"
	"\t\t\t{\r\n"
	"\t\t\t\tgl_FragColor.a = fAlteredAnim;\r\n"
	"\t\t\t}\r\n"
	"\t\t}\r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/FRAGMENTSHADER]\r\n"
	"\r\n"
	"[EFFECT] \r\n"
	"\tNAME \tballoon_effect4\r\n"
	"\t\t\r\n"
	"\t// GLOBALS UNIFORMS\r\n"
	"\tUNIFORM myModelViewIT \t\tWORLDVIEWIT\r\n"
	"\tUNIFORM myMVPMatrix \t\tWORLDVIEWPROJECTION\r\n"
	"\tUNIFORM\tmyLightDirection\tLIGHTDIRECTION\r\n"
	"\tUNIFORM\tsampler2d\t\t\tTEXTURE0\r\n"
	"\r\n"
	"\t// ATTRIBUTES\r\n"
	"\tATTRIBUTE \tmyVertex\tPOSITION\r\n"
	"\tATTRIBUTE\tmyNormal\tNORMAL\r\n"
	"\tATTRIBUTE\tmyUV\t\tUV\r\n"
	"\r\n"
	"\tVERTEXSHADER balloon_vert4\r\n"
	"\tFRAGMENTSHADER balloon_frag4\r\n"
	"\tTEXTURE 0 Balloon\r\n"
	"[/EFFECT]\r\n"
	"\r\n"
	"//Effect 5 /////////////////////////////////////////////////////////////////////\r\n"
	"//\r\n"
	"// This effect gives a sort of liquid metal effect by only using the skybox \r\n"
	"// cubemap as the source for texturing and manipulating the vertex position in \r\n"
	"// the vertex shader.\r\n"
	"//\r\n"
	"\r\n"
	"[VERTEXSHADER]\r\n"
	"\tNAME \t\tballoon_vert5\r\n"
	"\r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\tattribute vec3\tmyVertex;\r\n"
	"\t\tattribute vec3\tmyNormal;\r\n"
	"\t\t\r\n"
	"\t\tuniform mat4\tmyMVPMatrix;\r\n"
	"\t\tuniform mat3\tmyModelViewIT;\r\n"
	"\t\tuniform mat4\tmyModelView;\r\n"
	"\t\t\r\n"
	"\t\tuniform mediump mat3 myViewIT;\r\n"
	"\t\t\r\n"
	"\t\tvarying mediump vec3 Normal;\r\n"
	"\t\tvarying mediump vec3 EyeDir;\r\n"
	"\t\t\r\n"
	"\t\tvarying highp vec3 CubeUVs;\r\n"
	"\t\t\r\n"
	"\t\tuniform mediump float myFrame;\r\n"
	"\t\tuniform mediump float fAnim;\r\n"
	"\t\t\r\n"
	"\t\tvoid main(void)\r\n"
	"\t\t{\r\n"
	"\t\t\thighp vec3  tVertex = myVertex;\r\n"
	"\t\t\thighp float fValue  = 3.0 * myFrame * radians(360.0/500.0) - 0.1 * myVertex.y;\r\n"
	"\t\t\t\r\n"
	"\t\t\tif(myVertex.y > -0.1)\r\n"
	"\t\t\t{\r\n"
	"\t\t\t\tmediump float fValue2 = fAnim * (1.0 + 0.3 * cos(fValue));\r\n"
	"\t\t\t\t\r\n"
	"\t\t\t\ttVertex.x *= fValue2;\r\n"
	"\t\t\t\ttVertex.z *= fValue2;\r\n"
	"\t\t\t\ttVertex.y *= fAnim * fAnim;\r\n"
	"\t\t\t}\r\n"
	"\t\t\t\r\n"
	"\t\t\tmediump vec4 tVertex4 = vec4(tVertex,1);\r\n"
	"\t\t\t\r\n"
	"\t\t\tEyeDir = vec3(0.0,-1.0,0.0) - vec3(myModelView * tVertex4);\r\n"
	"\t\t\t\r\n"
	"\t\t\tif(myVertex.y > -0.1)\r\n"
	"\t\t\t\tNormal = normalize(myModelViewIT * (myNormal+ sin(fValue))) ;\r\n"
	"\t\t\telse\r\n"
	"\t\t\t\tNormal = normalize(myModelViewIT * myNormal) ;\r\n"
	"\t\t\r\n"
	"\t\t\tmediump vec3 n;\r\n"
	"\t\t\tn = 0.7 * (dot(EyeDir , Normal) * Normal - EyeDir);\r\n"
	"\t\t\tCubeUVs = myViewIT * normalize(-1.0 * (EyeDir + n));\r\n"
	"\t\t\t\r\n"
	"\t\t\tgl_Position = myMVPMatrix * tVertex4;\r\n"
	"\t\t}\r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/VERTEXSHADER]\r\n"
	"\r\n"
	"[FRAGMENTSHADER] \r\n"
	"\tNAME \t\tballoon_frag5\r\n"
	"\r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\tuniform samplerCube myCubeMap;\r\n"
	"\t\tvarying highp vec3 CubeUVs;\r\n"
	"\t\t\r\n"
	"\t\tvoid main (void)\r\n"
	"\t\t{\r\n"
	"\t\t\tgl_FragColor = textureCube(myCubeMap, CubeUVs);\t\t\r\n"
	"\t\t}\r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/FRAGMENTSHADER]\r\n"
	"\r\n"
	"[EFFECT] \r\n"
	"\tNAME \tballoon_effect5\r\n"
	"\t\t\r\n"
	"\t// GLOBALS UNIFORMS\r\n"
	"\tUNIFORM myModelViewIT \t\tWORLDVIEWIT\r\n"
	"\tUNIFORM myMVPMatrix \t\tWORLDVIEWPROJECTION\r\n"
	"\tUNIFORM myModelView\t\t\tWORLDVIEW\r\n"
	"\tUNIFORM myViewIT\t\t\tVIEWIT\r\n"
	"\tUNIFORM\tmyCubeMap\t\t\tTEXTURE0\r\n"
	"\r\n"
	"\t// ATTRIBUTES\r\n"
	"\tATTRIBUTE \tmyVertex\tPOSITION\r\n"
	"\tATTRIBUTE\tmyNormal\tNORMAL\r\n"
	"\r\n"
	"\tVERTEXSHADER balloon_vert5\r\n"
	"\tFRAGMENTSHADER balloon_frag5\r\n"
	"\tTEXTURE 0 Skybox\r\n"
	"[/EFFECT]\r\n"
	"\r\n"
	"//Effect 6 /////////////////////////////////////////////////////////////////////\r\n"
	"//\r\n"
	"// Effect 6 is a sort of bouncy cartoon shaded balloon. Once again the vertex \r\n"
	"// positions are manipulated to make the balloon bounce. The cartoon effect is \r\n"
	"// done by altering the lighting so it can only have 3 possible values. This \r\n"
	"// gives it the banded style of shading.\r\n"
	"//\r\n"
	"\r\n"
	"[VERTEXSHADER]\r\n"
	"\tNAME \t\tballoon_vert6\r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\tattribute vec3\tmyVertex;\r\n"
	"\t\tattribute vec3\tmyNormal;\r\n"
	"\t\tattribute vec2\tmyUV;\r\n"
	"\t\t\r\n"
	"\t\tuniform mat4\tmyMVPMatrix;\r\n"
	"\t\tuniform mat3\tmyModelViewIT;\r\n"
	"\t\t\r\n"
	"\t\tuniform mediump vec3\tmyLightDirection;\r\n"
	"\t\tuniform mediump float fAnim;\r\n"
	"\t\tuniform mediump float myFrame;\r\n"
	"\t\t\r\n"
	"\t\tvarying float\tfDiffuse;\r\n"
	"\t\tvarying lowp vec2 fTexCoord;\r\n"
	"\t\t\r\n"
	"\t\tvoid main(void)\r\n"
	"\t\t{\r\n"
	"\t\t\tmediump float anim2 = sin(3.0*myFrame * radians(360.0/500.0))*0.5 + 0.5;\r\n"
	"\t\t\tanim2 *= 0.5;\r\n"
	"\t\t\r\n"
	"\t\t\tmediump vec3 center = vec3(0.0,30.0,0.0);\r\n"
	"\t\t\tmediump vec3 tVertex =((30.0*normalize(myVertex-center)*anim2 + myVertex)*(1.0-anim2)) * fAnim ;\r\n"
	"\t\t\ttVertex\t\t+=\t  30.0*normalize(myVertex) * (1.0-fAnim);\r\n"
	"\t\t\r\n"
	"\t\t\tmediump vec3 fTransNormal = normalize( myModelViewIT * myNormal );\r\n"
	"\t\t\t\r\n"
	"\t\t\tgl_Position = myMVPMatrix * vec4(tVertex,1.0);\r\n"
	"\t\t\t\r\n"
	"\t\t\tfDiffuse = dot(fTransNormal, myLightDirection);\r\n"
	"\t\t\tfTexCoord= myUV;\r\n"
	"\t\t}\r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/VERTEXSHADER]\r\n"
	"\r\n"
	"[FRAGMENTSHADER] \r\n"
	"\tNAME \t\tballoon_frag6\r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\tvarying highp float\tfDiffuse;\r\n"
	"\t\tvarying lowp vec2\tfTexCoord;\r\n"
	"\t\t\r\n"
	"\t\tuniform sampler2D sampler2d;\r\n"
	"\t\t\r\n"
	"\t\t\r\n"
	"\t\tvoid main (void)\r\n"
	"\t\t{\r\n"
	"\t\t\tlowp vec4 texColor = texture2D(sampler2d,fTexCoord);\r\n"
	"\t\t\t\r\n"
	"\t\t\tmediump float intensity;\r\n"
	"\t\t\t\r\n"
	"\t\t\tif(fDiffuse > 0.67)\r\n"
	"\t\t\t\tintensity = 1.0;\r\n"
	"\t\t\telse if(fDiffuse > 0.33)\r\n"
	"\t\t\t\tintensity = 0.67;\r\n"
	"\t\t\telse\r\n"
	"\t\t\t\tintensity = 0.33;\r\n"
	"\t\t\t\t\r\n"
	"\t\t    gl_FragColor = texColor * intensity;;\r\n"
	"\t\t}\r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/FRAGMENTSHADER]\r\n"
	"\r\n"
	"[EFFECT] \r\n"
	"\tNAME \tballoon_effect6\r\n"
	"\t\t\r\n"
	"\t// GLOBALS UNIFORMS\r\n"
	"\tUNIFORM myModelViewIT \t\tWORLDVIEWIT\r\n"
	"\tUNIFORM myMVPMatrix \t\tWORLDVIEWPROJECTION\r\n"
	"\tUNIFORM\tmyLightDirection\tLIGHTDIRECTION\r\n"
	"\tUNIFORM\tsampler2d\t\t\tTEXTURE0\r\n"
	"\r\n"
	"\t// ATTRIBUTES\r\n"
	"\tATTRIBUTE \tmyVertex\tPOSITION\r\n"
	"\tATTRIBUTE\tmyNormal\tNORMAL\r\n"
	"\tATTRIBUTE\tmyUV\t\tUV\r\n"
	"\r\n"
	"\tVERTEXSHADER balloon_vert6\r\n"
	"\tFRAGMENTSHADER balloon_frag6\r\n"
	"\tTEXTURE 0 Balloon\r\n"
	"[/EFFECT]\r\n"
	"\r\n"
	"//Effect 7 /////////////////////////////////////////////////////////////////////\r\n"
	"//\r\n"
	"// This effect gives impression that the balloon is slightly transparent and \r\n"
	"// being affected by wind. This is done by using a noise texture to alter the \r\n"
	"// alpha and texture coordinates in the fragment shader. \r\n"
	"//\r\n"
	"\r\n"
	"[VERTEXSHADER]\r\n"
	"\tNAME \t\tballoon_vert7\r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\tattribute vec3\tmyVertex;\r\n"
	"\t\tattribute vec3\tmyNormal;\r\n"
	"\t\tattribute vec2\tmyUV;\r\n"
	"\t\t\r\n"
	"\t\tuniform mat4\tmyMVPMatrix;\r\n"
	"\t\tuniform mat3\tmyModelViewIT;\r\n"
	"\t\t\r\n"
	"\t\tuniform mediump vec3\tmyLightDirection;\r\n"
	"\t\tuniform mediump float\tfAnim;\r\n"
	"\t\tuniform mediump float myFrame;\r\n"
	"\t\t\r\n"
	"\t\tvarying float\tfDiffuse;\r\n"
	"\t\tvarying lowp vec2 fTexCoord;\r\n"
	"\r\n"
	"\t\tvarying highp   float fAlpha;\r\n"
	"\t\tvarying mediump float frame;\r\n"
	"\t\t\r\n"
	"\t\tvoid main(void)\r\n"
	"\t\t{\r\n"
	"\t\t\r\n"
	"\t\t\tgl_Position = myMVPMatrix * vec4(myVertex,1);\r\n"
	"\t\t\tmediump vec3 fTransNormal = myModelViewIT * myNormal;\r\n"
	"\t\t\t\r\n"
	"\t\t\tfDiffuse = 0.1 * dot(fTransNormal, myLightDirection) + 0.9;\r\n"
	"\t\t\tfTexCoord\t= 0.7 * myUV;\r\n"
	"\t\t\tfAlpha = fAnim * dot(normalize(fTransNormal), vec3(0.0,0.0,0.5)) * 2.0;\r\n"
	"\t\t\tframe = myFrame * 0.02;\r\n"
	"\t\t}\r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/VERTEXSHADER]\r\n"
	"\r\n"
	"[FRAGMENTSHADER] \r\n"
	"\tNAME \t\tballoon_frag7\r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\tvarying highp float\tfDiffuse;\r\n"
	"\t\tvarying lowp vec2\tfTexCoord;\r\n"
	"\t\tvarying highp float\tfAlpha;\r\n"
	"\t\tvarying mediump float frame;\r\n"
	"\t\t\r\n"
	"\t\tuniform sampler2D sampler2d;\r\n"
	"\t\tuniform sampler2D Noise;\r\n"
	"\t\t\r\n"
	"\t\tvoid main (void)\r\n"
	"\t\t{    \r\n"
	"\t\t    mediump vec2 noisevec = texture2D(Noise,  fTexCoord + frame).xy;\r\n"
	"\t\t    mediump vec2 coord2D  = fTexCoord + 0.3 * noisevec;\r\n"
	"\t\t\r\n"
	"\t\t    gl_FragColor.rgb = texture2D(sampler2d, coord2D).rgb * fDiffuse;\r\n"
	"\t\t    gl_FragColor.a   = fAlpha * noisevec.x;\r\n"
	"\t\t}\r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/FRAGMENTSHADER]\r\n"
	"\r\n"
	"\r\n"
	"[EFFECT] \r\n"
	"\tNAME \tballoon_effect7\r\n"
	"\t\t\r\n"
	"\t// GLOBALS UNIFORMS\r\n"
	"\tUNIFORM myModelViewIT \t\tWORLDVIEWIT\r\n"
	"\tUNIFORM myMVPMatrix \t\tWORLDVIEWPROJECTION\r\n"
	"\tUNIFORM\tmyLightDirection\tLIGHTDIRECTION\r\n"
	"\tUNIFORM\tsampler2d\t\t\tTEXTURE0\r\n"
	"\tUNIFORM\tNoise\t\t\t\tTEXTURE1\r\n"
	"\r\n"
	"\t// ATTRIBUTES\r\n"
	"\tATTRIBUTE \tmyVertex\tPOSITION\r\n"
	"\tATTRIBUTE\tmyNormal\tNORMAL\r\n"
	"\tATTRIBUTE\tmyUV\t\tUV\r\n"
	"\r\n"
	"\tVERTEXSHADER \tballoon_vert7\r\n"
	"\tFRAGMENTSHADER \tballoon_frag7\r\n"
	"\tTEXTURE 0 Balloon_pvr\r\n"
	"\tTEXTURE 1 Noise\r\n"
	"[/EFFECT]\r\n";

// Register effects.pfx in memory file system at application startup time
static CPVRTMemoryFileSystem RegisterFile_effects_pfx("effects.pfx", _effects_pfx, 17065);

// ******** End: effects.pfx ********

