/*
    Standard C libraries:
*/

#include<cmath>
#include<cstdarg>
#include<cstdio>
#include<cstdlib>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<iostream>
#include<limits>
#include<string>
#include<vector>

/*
    Allegro C libraries:
*/

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_color.h>
#include<allegro5/allegro_acodec.h>

/*
    OpenGL C libraries:
*/

#include<gl\gl.h>
#include<gl\glu.h> 
#include<gl\glut.h> 
#include<gl\GLAUX.h>
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

#include"src\lib\ScriptsDLL.cpp"        // conversations script
#include"src\lib\VMatrix\VMatrix.cpp"   // vectors, modeling matrices
#include"src\lib\A3DSL\A3DSL.cpp"       // 3D sounds library
#include"src\lib\S3DGL\S3DGL.cpp"       // 3D graphic lirary (unused)
#include"src\lid\Trygonometry.cpp"      // Trygonometry-modifier functions

/*
    Engine source code:
*/

#include"Informations.h"

// Defines:
    #include"src\otr\Macros.h"
    #include"src\otr\TypeDefs.hpp"

// Class:

#include"src\css\Wall.h"
#include"src\css\Object.h"
#include"src\css\Map.h"
#include"src\css\Engine.h"



#include"src\mtd\Engine\Engine.cpp"

/*
    Game source code:
*/

#include"src\game\GameMain.cpp"



