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
#include<conio.h>

/*
    My C++ libraries:
*/

#include"lib\LodePNG\LodePNG.h"

#include"lib\GetSthFromString.h"
#include"lib\BMP.h"						// for load bitmaps
#include"lib\FontDisplay.cpp"			// font display
#include"lib\VMatrix\Vector.h"       	// vectors, modeling matrices
#include"lib\VMatrix\VMatrix.h"       	// vectors, modeling matrices
#include"lib\MaxMin.h"					// Maximum and Minimum values from src

#include"lib\Delay.h"                 	// Microseconds sleep

using namespace MaxAndMin;

/*
    Engine source code:
*/

#include"Informations.h"

// Defines:

#include"otr\Macros.h"
#include"otr\TypeDefs.hpp"

// Class:

#include"css\SoundEngine.h"

#include"css\Texture.h"

#include"css\VBOcolored.h"
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
#include"css\GraphicObject.h"
#include"css\PhysicModelStatic.h"

#include"css\Collision.h"

#include"css\Collider.h"
#include"css\Map.h"
#include"css\Engine.h"





#include"otr\GlobalFunctions.h"

