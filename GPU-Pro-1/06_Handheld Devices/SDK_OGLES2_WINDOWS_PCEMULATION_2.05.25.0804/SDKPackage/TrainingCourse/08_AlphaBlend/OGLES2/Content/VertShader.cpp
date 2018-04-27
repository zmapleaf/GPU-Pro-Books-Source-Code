// This file was created by Filewrap 1.1
// Little endian mode
// DO NOT EDIT

#include "../PVRTMemoryFileSystem.h"

// using 32 bit to guarantee alignment.
#ifndef A32BIT
 #define A32BIT static const unsigned int
#endif

// ******** Start: VertShader.vsh ********

// File data
static const char _VertShader_vsh[] = 
	"attribute highp  vec2  inVertex;\r\n"
	"\r\n"
	"uniform highp vec2  LowerLeft;\r\n"
	"uniform highp mat2  ScaleMatrix; // width/height and screen rotation\r\n"
	"\r\n"
	"varying mediump vec2  TexCoord;\r\n"
	"\r\n"
	"void main()\r\n"
	"{\r\n"
	"\tgl_Position = vec4(ScaleMatrix * inVertex + LowerLeft, 0, 1);\r\n"
	"\t\r\n"
	"\tTexCoord = inVertex;\r\n"
	"}\r\n";

// Register VertShader.vsh in memory file system at application startup time
static CPVRTMemoryFileSystem RegisterFile_VertShader_vsh("VertShader.vsh", _VertShader_vsh, 284);

// ******** End: VertShader.vsh ********

// This file was created by Filewrap 1.1
// Little endian mode
// DO NOT EDIT

#include "../PVRTMemoryFileSystem.h"

// using 32 bit to guarantee alignment.
#ifndef A32BIT
 #define A32BIT static const unsigned int
#endif

// ******** Start: VertShader.vsc ********

// File data
A32BIT _VertShader_vsc[] = {
0x10fab438,0x56cabbaf,0x30050100,0x2101,0xa9142cc2,0x0,0x0,0xe1010000,0x0,0x4000000,0x0,0x9000000,0x2,0x0,0x20000,0x0,0x0,0xc010000,0x55535020,0x17,0x100,0x1,0x0,0x80c,0x0,0x2,0x79,0x0,0x8,0x0,0xffffffff,0x0,0x76000a,0xffff,0x2,0x0,0x60000,0x0,0x0,0x0,0x0,0xfffc0000,0x0,0x0,0x0,0x20000,0xffffffff,0x60000,0x10002,0x0,0x10000,0x10001,0x10000,0x20002,0x10000,0x30003,0x10000,0x40004,0x10000,0x50005,0x30000,0x40000,0x20000,0x2,
0x6,0x80018001,0x80018001,0x0,0x0,0x0,0x0,0x10001,0x60401800,0x28831001,0x60601a00,0x28831001,0xa0800000,0x28a11001,0xf000050b,0x38ab0606,0xf000460d,0x38820606,0x701f1a0e,0xa21001,0x6,0x800,0x0,0x0,0x0,0x0,0x0,0x0,0x803f0000,0x5000000,0x6c616353,0x74614d65,0x786972,0x30e0000,0x10000,0x100,0xf0004,0x566e6900,0x65747265,0x78,0x403,0x1000001,0x40000,0x4c000003,0x7265776f,0x7466654c,0x3000000,0x1000003,0x10000,0x3000204,0x6c670000,0x736f505f,0x6f697469,0x100006e,0x505,0x1000001,0x40000,0x5400000f,0x6f437865,0x64726f,0x5030000,0x10000,0x100,0x30002,
0x0,
};

// Register VertShader.vsc in memory file system at application startup time
static CPVRTMemoryFileSystem RegisterFile_VertShader_vsc("VertShader.vsc", _VertShader_vsc, 513);

// ******** End: VertShader.vsc ********

