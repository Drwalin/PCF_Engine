

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_acodec.h>




#include <gl\gl.h>
#include <gl\glu.h> 
#include <gl\glut.h> 
//#include <gl\GLAUX.h>
#include <gl\glext.h>
//#include "ENGINE\gl\glu_.h"

#include<vector>
#include<windows.h>
#include<ctime>
#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<process.h>
#include<iostream>
#include<cmath>
#include<math.h>
#include<conio.h>
#include<fstream>
#include<limits>
#include<string>

#include<Mmsystem.h>

class NameLine256 { public: char name[256];  };
class NameLine128 { public: char name[128];  };
class NameLine64  { public: char name[64];   };
class NameLine32  { public: char name[32];   };

#define Vertex Vector
#define vertex vector

#include"Math\VMatrix.cpp"              // biblioteka obsluguj¹ca wektory i macierze
    // By me

#include"Libraries\SoundsA3D.cpp"       // biblioteka obs³uguj¹ca dŸwiêk
    // By me


#include"BMP\BMP.cpp"                   // biblioteka obs³uguj¹ca wczytywanie plików bmpx (bmp 32-bit)
#include"LetterScreen\Functions.cpp"    // biblioteka obs³uguj¹ca rysowanie na ekranie opengl (pod k¹tem patrzenia fov=60)
    // By me

using namespace std;

#include"Informations.h"

#include"Definer.h"

#include"DefinerFunctions.h"

#include"Math\Trygonometry.cpp"

#include"PreviousValues.h"




#include"Classes\IncludeClasses.h"

#include"Math\Math.h"

#include"Values.h"
#include"Machine.hpp"

//#include"Graphic\HumanoidGraphicModelDraw.cpp"
//#include"Graphic\CubeGraphicModelDraw.cpp"

#include"Classes\IncludeDefinersMethods.h"



#include"MainLoop.cpp"

#include"Renderer.cpp"




#include"Main.cpp"
