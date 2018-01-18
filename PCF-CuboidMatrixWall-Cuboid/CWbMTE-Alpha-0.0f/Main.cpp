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

#include"src\lib\PerlinNoise2.cpp"

/*
    Allegro C libraries:
*/
/*
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_color.h>
#include<allegro5/allegro_acodec.h>
*/
/*
    OpenGL C libraries:
*/

#include<gl\gl.h>
#include<gl\glu.h> 
#include<gl\glut.h> 
//#include<gl\GLAUX.h>
#include<gl\glext.h>

/*
    Windows-specific C libraries:
*/

#include<conio.h>
#include<Mmsystem.h>
#include<process.h>
#include<windows.h>

/*
    My C++ libraries:
*/

#include"src\lib\BMP.cpp"					// for load bitmaps
#include"src\lib\ScriptsDLL.cpp"            // Conversations script
#include"src\lib\Keyboards.cpp"				// use keyboard class
#include"src\lib\FontDisplay.cpp"			// font display
#include"src\lib\VMatrix\VMatrix.cpp"       // vectors, modeling matrices
//#include"src\lib\A3DSL\A3DSL.cpp"           // 3D sounds library
//#include"src\lib\S3DGL\S3DGL.cpp"         // 3D graphic lirary (unused)

#include"src\lib\Delay.cpp"                 // Microseconds sleep

/*
    Engine source code:
*/

#include"Informations.h"

// Defines:

#include"src\otr\Macros.h"
#include"src\otr\TypeDefs.hpp"

unsigned long long int debugiteratorvalue = 0;

//#define DEBUG__FUNCTION cout<<debugiteratorvalue<<"\n";getch();debugiteratorvalue++;

// Class:

#include"src\css\Texture.h"

//#include"src\css\Particle.h"
//#include"src\css\FireParticle.h"
//#include"src\css\DustParticle.h"

#include"src\css\TrianglePX.h"
#include"src\css\TriangleGX.h"
#include"src\css\TriangleSTGX.h"

#include"src\css\AABB.h"
#include"src\css\OBB.h"
#include"src\css\Sphere.h"

#include"src\css\GraphicModel.h"
#include"src\css\PhysicModelStatic.h"

#include"src\css\Collision.h"

#include"src\css\Collider.h"
#include"src\css\Map.h"
#include"src\css\Engine.h"




Engine engine;
void Reshape__( int width, int height )
{
	engine.Reshape( width, height );
}
void Renderer__()
{
	engine.Renderer();
}
void FrameFunction__( int arg )
{
	engine.FrameFunction( arg );
}
__cdecl void PhisicLoop__( void * args )
{
	engine.PhisicLoop();
	_endthread();
}

long long int frames_physic_loop = 0;
long long int cool_down_physic_fps = 0;

#include"src\mtd\Texture\Texture.cpp"

//#include"src\mtd\Particle\FireParticle.cpp"
//#include"src\mtd\Particle\DustParticle.cpp"
//#include"src\mtd\Particle\Particle.cpp"

#include"src\mtd\TrianglePX\TrianglePX.cpp"
#include"src\mtd\TriangleGX\TriangleGX.cpp"
#include"src\mtd\TriangleSTGX\TriangleSTGX.cpp"

#include"src\mtd\AABB\AABB.cpp"
#include"src\mtd\OBB\OBB.cpp"
#include"src\mtd\Sphere\Sphere.cpp"

#include"src\mtd\GraphicModel\GraphicModel.cpp"
#include"src\mtd\PhysicModelStatic\PhysicModelStatic.cpp"

#include"src\mtd\Collision\Collision.cpp"

#include"src\mtd\Collider\Collider.cpp"
#include"src\mtd\Map\Map.cpp"
#include"src\mtd\Engine\Engine.cpp"

/*
    Game source code:
*/

#include"src\game\KeyboardFunction.cpp"
#include"src\game\GUIFunction.cpp"
#include"src\game\GameMain.cpp"


