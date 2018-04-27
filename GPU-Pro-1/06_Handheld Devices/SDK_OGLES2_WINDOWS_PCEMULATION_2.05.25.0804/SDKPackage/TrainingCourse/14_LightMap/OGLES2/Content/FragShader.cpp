// This file was created by Filewrap 1.1
// Little endian mode
// DO NOT EDIT

#include "../PVRTMemoryFileSystem.h"

// using 32 bit to guarantee alignment.
#ifndef A32BIT
 #define A32BIT static const unsigned int
#endif

// ******** Start: FragShader.fsh ********

// File data
static const char _FragShader_fsh[] = 
	"uniform sampler2D  sBasetex;\r\n"
	"uniform sampler2D  sReflect;\r\n"
	"uniform sampler2D  sShadow;\r\n"
	"\r\n"
	"varying mediump vec2   TexCoord;\r\n"
	"varying mediump vec3   ShadowCoord;\r\n"
	"varying mediump vec2   ReflectCoord;\r\n"
	"varying lowp    float  LightIntensity;\r\n"
	"\r\n"
	"const lowp float  cReflect = 0.2;\r\n"
	"\r\n"
	"void main()\r\n"
	"{\r\n"
	"\tlowp vec3 baseColor = texture2D(sBasetex, TexCoord).rgb;\r\n"
	"\tbaseColor *= 0.2 + 0.8 * texture2DProj(sShadow, ShadowCoord).r * LightIntensity;\r\n"
	"\t\r\n"
	"\tlowp vec3 reflectColor = texture2D(sReflect, ReflectCoord).rgb;\r\n"
	"\r\n"
	"\tgl_FragColor = vec4(baseColor +  reflectColor * cReflect, 1.0);\r\n"
	"}";

// Register FragShader.fsh in memory file system at application startup time
static CPVRTMemoryFileSystem RegisterFile_FragShader_fsh("FragShader.fsh", _FragShader_fsh, 575);

// ******** End: FragShader.fsh ********

// This file was created by Filewrap 1.1
// Little endian mode
// DO NOT EDIT

#include "../PVRTMemoryFileSystem.h"

// using 32 bit to guarantee alignment.
#ifndef A32BIT
 #define A32BIT static const unsigned int
#endif

// ******** Start: FragShader.fsc ********

// File data
A32BIT _FragShader_fsc[] = {
0x10fab438,0x2899c4ed,0x30050100,0x2101,0xa9142cc2,0x0,0x0,0x1a060000,0x1000000,0x4000000,0x0,0x78000000,0x2020203,0x0,0x2020000,0x102,0x0,0x74020000,0x55535020,0x17,0x268,0x1,0x0,0x848,0x0,0x2,0x79,0x0,0x8,0x0,0xffffffff,0x0,0x770009,0xffff,0x5,0x0,0x30004,0x0,0x0,0x0,0x0,0xfffc0000,0x20003,0x10004,0x0,0x20000,0xffffffff,0x30000,0x40000,0x10000,0x20003,0x0,0x2,0x60000,0x40000,0x30001,0x20000,0x3,0x30000,0x3,0x30000,0x10007,0x30000,0x2000b,
0x40000,0x20000,0x2,0x20001,0x80018001,0x80018001,0x0,0x0,0x1000004,0x0,0x5fd10,0x10000,0x80010002,0x80018001,0x8001,0x0,0x0,0x70000,0x60a0007,0x30003,0x30003,0x20002,0x20002,0x40004,0x40004,0x10000,0x30002,0x1,0x20002,0x2,0x20003,0x80018001,0x80018001,0x0,0x0,0x40004,0x800004,0x10868020,0x810800,0x1b7ea020,0xb04000,0x10069000,0x53001,0x0,0x80010002,0x80018001,0x8001,0x0,0x0,0x40001,0x60a0004,0x30003,0x30003,0x0,0x0,0x40004,0x40004,0x10000,0x30002,0x1,0xa0000000,0xe003140c,0x2,0x20004,
0x80018001,0x80018001,0x0,0x0,0x0,0x10001,0xa0020000,0x40811022,0xb0000049,0x90887983,0xa0208003,0x408a1fff,0xf01f6540,0x89894023,0x5,0x20001,0x80018001,0x80018001,0x0,0x0,0x20001,0x70007,0x3060a,0x30003,0x40003,0x40004,0x40004,0x40004,0x4,0x20001,0x10003,0x30000,0x20002,0x30000,0x80010002,0x80018001,0x8001,0x0,0x10000,0x120001,0xb800024b,0x908079c2,0xb8100140,0xc8810816,0x90402038,0x81810006,0x6,0x74020000,0x55535020,0x17,0x268,0x1,0x0,0x948,0x0,0x2,0x79,0x0,0x8,0x0,0xffffffff,0x0,0x770009,0xffff,
0x10005,0x0,0x30004,0x0,0x0,0x0,0x0,0xfffc0000,0x1,0x10004,0x0,0x20000,0xffffffff,0x30000,0x40000,0x10000,0x20003,0x0,0x2,0x40000,0x40000,0x30001,0x20000,0x3,0x30000,0x3,0x30000,0x10007,0x30000,0x2000b,0x40000,0x20000,0x2,0x20001,0x80018001,0x80018001,0x0,0x0,0x1000004,0x0,0x5fd10,0x10000,0x80010002,0x80018001,0x8001,0x0,0x0,0x70000,0x60a0007,0x30003,0x30003,0x20002,0x20002,0x40004,0x40004,0x10000,0x30002,0x10001,0x20002,0x2,0x20003,0x80018001,0x80018001,0x0,
0x0,0x40004,0x800004,0x10848000,0x800,0x1b7c0000,0x304000,0x10041000,0x53001,0x0,0x80010002,0x80018001,0x8001,0x0,0x0,0x40001,0x60a0004,0x10001,0x10001,0x0,0x0,0x40004,0x40004,0x10000,0x30002,0x10001,0xa0000000,0xe0031408,0x2,0x20004,0x80018001,0x80018001,0x0,0x0,0x0,0x10001,0x20020000,0x40811020,0x30000049,0x90887983,0xa0208003,0x408a1fff,0xf01f6540,0x89894023,0x5,0x20001,0x80018001,0x80018001,0x0,0x0,0x20001,0x70007,0x3060a,0x30003,0x40003,0x40004,0x40004,0x40004,0x4,0x20001,0x10003,0x30001,0x20002,0x30000,
0x80010002,0x80018001,0x8001,0x0,0x10000,0x120001,0xb800024b,0x908079c0,0xb8100140,0xc8810810,0x10002038,0x81810004,0x6,0x1000,0x0,0x0,0x4c3f0000,0xcdcc,0x0,0x0,0x4c3e0000,0xcdcc,0x0,0x0,0x4c3e0000,0xcdcc,0x0,0x0,0x803f0000,0x7000000,0x73614273,0x78657465,0x18000000,0x1000003,0x20000,0x1000100,0x65540000,0x6f6f4378,0x6472,0x50300,0x100,0x2040001,0x300,0x61685373,0x776f64,0x3180000,0x10000,0x1000200,0x10001,0x61685300,0x43776f64,0x64726f6f,0x4000000,0x1000005,0x10000,0x7000300,0x694c0000,0x49746867,0x6e65746e,0x79746973,0x2000000,0x1000005,0x10000,0x100010c,
0x52730000,0x656c6665,0x7463,0x31800,0x100,0x1020002,0x100,0x6c666552,0x43746365,0x64726f6f,0x3000000,0x1000005,0x10000,0x3000208,0x0,
};

// Register FragShader.fsc in memory file system at application startup time
static CPVRTMemoryFileSystem RegisterFile_FragShader_fsc("FragShader.fsc", _FragShader_fsc, 1594);

// ******** End: FragShader.fsc ********

