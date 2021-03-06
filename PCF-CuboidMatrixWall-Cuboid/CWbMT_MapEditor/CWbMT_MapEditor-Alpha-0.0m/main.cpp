/*  -lalleg_s
    link do kursu allegro 5.0:
    http://allegro5kurs.blogspot.de/
*/

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_acodec.h>

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

#include "src\lib\VMatrix\VMatrix.cpp"
#include "src\lib\DrawWrites.cpp"

////////////////

#include "src\Definer.h"

#include "src\PreValues.cpp"
#include "src\lib\Keyboard.cpp"

////////////////

#include "src\css\Window3D.h"
#include "src\css\SeeAspect.h"
#include "src\css\Button.h"
#include "src\css\Triangle.h"
#include "src\css\Vertex.h"

#include "src\Values.cpp"

#include "src\mtd\Window3D.cpp"
#include "src\mtd\SeeAspect.cpp"
#include "src\mtd\Button.cpp"
#include "src\mtd\Triangle.cpp"

////////////////

#include "src\DrawCursor.cpp"
#include "src\Renderer.cpp"

////////////////

#include "src\LoadTextures.cpp"

#include "src\DeInit.cpp"
#include "src\Init.cpp"


#include "src\SaveProject.cpp"
#include "src\LoadProject.cpp"
#include "src\SetTextureCoordinates.cpp"

#include "src\AddVertexCoordinates.cpp"
#include "src\CollidePoint.cpp"
#include "src\OperateVertex.cpp"
#include "src\MoveWindow.cpp"
#include "src\CreateVertex.cpp"

#include "src\MainLoop.cpp"

#include "src\Main.cpp"

        //    	al_show_native_message_box( display, "Blad", "NULL", "Nie moge utworzyc okna!", NULL, ALLEGRO_MESSAGEBOX_ERROR );
        //    	al_draw_scaled_bitmap( bitmapa, sx, sy, sw, sh, dx, dy, dw, dh, 0 );
        //    	al_draw_bitmap( bitmapa, 0, 0, 0 );
        //    	al_set_target_bitmap( bitmapa );                          // ustawia "bitmapa" jako buffor podstawowy do kt�rego b�dzie sie zapisywa� powyzsza funkcj�
        //    	al_set_target_bitmap( al_get_backbuffer( display ) );     // ustawia buffor podstawowy na domy�ly
        //    	al_get_bitmap_width( bitmapa );                           //pobiera szerokosc "bitmapa"
        //    	al_get_bitmap_height( bitmapa );                          //pobiera wysokosc  "bitmapa"
        //    	al_rest( 0.2 );                                           //sleep w sekundach podany
        //    	prymitywy:    http://allegro5kurs.blogspot.de/2012/10/lekcja-105-allegro5-kurs-prymitywy.html
        //    	al_draw_line( x,   y-17, x,   y+17, al_map_rgb( 16, 16,  255 ), 1 );
        //    	al_draw_rectangle( x-1, y-1, x+1, y+1, al_map_rgb( 192, 32, 32 ), 1 );
        //    	al_draw_filled_rectangle( 3, 3, width-3, height-3, al_map_rgb( 32, 32, 32 ) );
        //    	klawiatura:   http://allegro5kurs.blogspot.de/2012/06/lekcja-104-allegro5-kurs-klawiatura-i.html
        //    	al_destroy_display( display );                            //usuwa okno
        //		al_show_native_message_box( display, "Blad", "NULL", "Nie moge utworzyc okna!", NULL, ALLEGRO_MESSAGEBOX_ERROR );
