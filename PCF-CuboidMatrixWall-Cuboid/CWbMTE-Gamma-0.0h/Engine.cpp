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

#include"lib\LodePNG\LodePNG.cpp"

#include"lib\GetSthFromString.cpp"
#include"lib\BMP.cpp"					// for load bitmaps
#include"lib\FontDisplay.cpp"			// font display
#include"lib\VMatrix\VMatrix.cpp"       // vectors, modeling matrices
#include"lib\MaxMin.cpp"

#include"lib\Delay.cpp"                 // Microseconds sleep

using namespace MaxAndMin;

/*
	Friend Ship Definition:

	friend class SoundSampleSources;
	friend class OneSample;
	friend class SoundEngine;
	friend class Texture;
	friend class VBOvertexColored;
	friend class VBOcolored;
	friend class VBOvertexTexture;
	friend class VBOtextured;
	friend class ONEPointParticle;
	friend class PointParticle;
	friend class LightningVertex;
	friend class Lightning;
	friend class TrianglePX;
	friend class StaticGraphicModel;
	friend class Contact;
	friend class PhysicModelStatic;
	friend class Collision;
	friend class ColliderTerrain;
	friend class ColliderObjects;
	friend class Map;
	friend class Engine;
*/

/*
    Engine source code:
*/

#include"Informations.h"

// Defines:

#include"otr\Macros.h"
#include"otr\TypeDefs.hpp"
#include"otr\ClassDefinition.h"

// Class:

#include"css\SoundEngine.h"

#include"css\Texture.h"

#include"css\VBOcolored.h"
#include"css\VBOtextured.h"

#include"css\PointParticle.h"
#include"css\Lightning.h"

#include"css\TrianglePX.h"

#include"css\Contact.h"

#include"css\StaticGraphicModel.h"
#include"css\PhysicModelStatic.h"

#include"css\Collision.h"

#include"css\Collider.h"
#include"css\Map.h"
#include"css\Engine.h"





#include"otr\GlobalFunctions.cpp"





#include"mtd\SoundEngine\SoundEngine.cpp"

#include"mtd\Texture\Texture.cpp"

#include"mtd\VBOcolored\VBOcolored.cpp"
#include"mtd\VBOtextured\VBOtextured.cpp"

#include"mtd\PointParticle\PointParticle.cpp"
#include"mtd\Lightning\Lightning.cpp"

#include"mtd\TrianglePX\TrianglePX.cpp"

#include"mtd\Contact\Contact.cpp"

#include"mtd\StaticGraphicModel\StaticGraphicModel.cpp"
#include"mtd\PhysicModelStatic\PhysicModelStatic.cpp"

#include"mtd\Collision\Collision.cpp"

#include"mtd\Collider\Collider.cpp"
#include"mtd\Map\Map.cpp"
#include"mtd\Engine\Engine.cpp"


