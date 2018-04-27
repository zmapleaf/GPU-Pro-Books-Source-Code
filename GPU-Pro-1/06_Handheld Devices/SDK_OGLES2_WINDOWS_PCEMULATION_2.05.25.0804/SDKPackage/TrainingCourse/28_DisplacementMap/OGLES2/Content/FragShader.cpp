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
	"uniform sampler2D  sTexture;\r\n"
	"\r\n"
	"varying lowp    float  LightIntensity;\r\n"
	"varying mediump vec2   TexCoord;\r\n"
	"\r\n"
	"void main()\r\n"
	"{\r\n"
	"    gl_FragColor = texture2D(sTexture, TexCoord) * LightIntensity;\r\n"
	"}\r\n";

// Register FragShader.fsh in memory file system at application startup time
static CPVRTMemoryFileSystem RegisterFile_FragShader_fsh("FragShader.fsh", _FragShader_fsh, 195);

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
0x10fab438,0xcb8f9404,0x30050100,0x2101,0xa9142cc2,0x0,0x0,0xe4020000,0x1000000,0x4000000,0x0,0x18000000,0x10202,0x2a0008,0x1020100,0xa200,0x91301,0x30010000,0x55535020,0x17,0x124,0x1,0x0,0x848,0x0,0x2,0x79,0x0,0x0,0x0,0xffffffff,0x0,0x770009,0xffff,0x2,0x0,0x2,0x0,0x0,0x0,0x0,0xfffc0000,0x10003,0x10004,0x0,0x20000,0xffffffff,0x0,0x40000,0x20000,0x30001,0x0,0x1,0x40000,0x20000,0x2,0x20001,0x80018001,0x80018001,0x0,0x0,0x1000004,0x0,0x5fd10,
0x10000,0x80010002,0x80018001,0x8001,0x0,0x0,0xf0000,0x60a000f,0x30003,0x30003,0x10001,0x10001,0x40004,0x40004,0x10000,0x30002,0x1,0x20001,0x2,0x20002,0x80018001,0x80018001,0x0,0x0,0x130000,0xa0028000,0x408a1fff,0xb02000c0,0x908179c2,0x6,0x30010000,0x55535020,0x17,0x124,0x1,0x0,0x948,0x0,0x2,0x79,0x0,0x0,0x0,0xffffffff,0x0,0x770009,0xffff,0x10002,0x0,0x2,0x0,0x0,0x0,0x0,0xfffc0000,0x1,0x10004,0x0,0x20000,0xffffffff,0x0,0x40000,0x20000,0x30001,
0x0,0x1,0x40000,0x20000,0x2,0x20001,0x80018001,0x80018001,0x0,0x0,0x1000004,0x0,0x5fd10,0x10000,0x80010002,0x80018001,0x8001,0x0,0x0,0xf0000,0x60a000f,0x30003,0x30003,0x10001,0x10001,0x40004,0x40004,0x10000,0x30002,0x10001,0x20001,0x2,0x20002,0x80018001,0x80018001,0x0,0x0,0x130000,0xa0028000,0x408a1fff,0xb00000c0,0x908179c0,0x6,0x3000000,0x78655473,0x65727574,0x18000000,0x1000003,0x20000,0x1000100,0x65540000,0x6f6f4378,0x6472,0x50300,0x100,0x2000001,0x300,0x6867694c,0x746e4974,0x69736e65,0x7974,0x50200,0x100,0x1040001,
0x100,0x0,
};

// Register FragShader.fsc in memory file system at application startup time
static CPVRTMemoryFileSystem RegisterFile_FragShader_fsc("FragShader.fsc", _FragShader_fsc, 772);

// ******** End: FragShader.fsc ********

