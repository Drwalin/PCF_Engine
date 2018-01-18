/*
    Standard C libraries:
*/

#include<cmath>
#include<cstdarg>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<iostream>
#include<limits>
#include<string>
#include<vector>

using namespace std;

//////////////////////////////////
//////// Fast Libraries: /////////
//////////////////////////////////
#include"lib\PerlinNoise2.cpp"

/*
    OpenGL C libraries:
*/

#include<gl\glut.h>
#include"OpenGL\glext.h"

#ifndef WIN32
    #define GLX_GLXEXT_LEGACY
    #include <gl\glx.h>
    #define wglGetProcAddress glXGetProcAddressARB
#endif

/*
	IrrKlang v1.3 C++ libraries:
*/
#include <irrKlang.h>
#pragma comment(lib, "irrKlang.lib")



/*
    Windows-specific C libraries:
*/

#include<Mmsystem.h>
#include<process.h>
#include<windows.h>

/*
    My C++ libraries:
*/

#include"lib\LodePNG\LodePNG.cpp"

#include"lib\BMP.cpp"					// for load bitmaps
#include"lib\ScriptsDLL.cpp"            // Conversations script
#include"lib\Keyboards.cpp"				// use keyboard class
#include"lib\FontDisplay.cpp"			// font display
#include"lib\VMatrix\VMatrix.cpp"       // vectors, modeling matrices
#include"lib\MaxMin.cpp"				// Maximum and Minimum values from src
#include"lib\GetSthFromString.cpp"
#include"lib\ConvertMSDNKeyCode.cpp"
//#include"lib\A3DSL\A3DSL.cpp"			// 3D sounds library
//#include"lib\S3DGL\S3DGL.cpp"			// 3D graphic lirary (unused)
#include"lib\PrintStringFaster.cpp"		//

#include"lib\Delay.cpp"                 // Microseconds sleep
using namespace MaxAndMin;

/*
    Engine source code:
*/

#include"Informations.h"

// Defines:

#include"otr\Macros.h"
#include"otr\TypeDefs.hpp"

unsigned long long int debugiteratorvalue = 0;

//#define DEBUG__FUNCTION cout<<debugiteratorvalue<<"\n";getch();debugiteratorvalue++;

// Class:

#include"css\SoundEngine.h"

#include"css\Texture.h"

#include"css\VBOcollored.h"
#include"css\VBOtextured.h"

#include"css\PointParticle.h"
#include"css\Lightning.h"

#include"css\TrianglePX.h"
#include"css\TriangleGX.h"

#include"css\AABB.h"
#include"css\OBB.h"
#include"css\Sphere.h"

#include"css\AnimatedModels.h"	////////// -
#include"css\StaticGraphicModel.h"
#include"css\PhysicModelStatic.h"

#include"css\Collision.h"

#include"css\Collider.h"
#include"css\Map.h"
#include"css\Engine.h"





#include"otr\GlobalFunctions.cpp"





#include"mtd\SoundEngine\SoundEngine.cpp"

#include"mtd\Texture\Texture.cpp"

#include"mtd\VBOcollored\VBOcollored.cpp"
#include"mtd\VBOtextured\VBOtextured.cpp"

#include"mtd\PointParticle\PointParticle.cpp"
#include"mtd\Lightning\Lightning.cpp"

#include"mtd\TrianglePX\TrianglePX.cpp"
#include"mtd\TriangleGX\TriangleGX.cpp"

#include"mtd\AABB\AABB.cpp"
#include"mtd\OBB\OBB.cpp"
#include"mtd\Sphere\Sphere.cpp"

#include"mtd\AnimatedModels\AnimatedModels.cpp"	///////// -
#include"mtd\StaticGraphicModel\StaticGraphicModel.cpp"
#include"mtd\PhysicModelStatic\PhysicModelStatic.cpp"

#include"mtd\Collision\Collision.cpp"

#include"mtd\Collider\Collider.cpp"
#include"mtd\Map\Map.cpp"
#include"mtd\Engine\Engine.cpp"


