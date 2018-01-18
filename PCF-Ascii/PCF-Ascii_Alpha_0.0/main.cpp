/*  -lalleg_s
    link do kursu allegro 5.0:
    http://allegro5kurs.blogspot.de/
    
    ALLEGRO_BITMAP *kwadrat, *prostokat = NULL;  //  wskaŸniki do bitmap 
    kwadrat  = al_create_bitmap(50,50);          //  rozmiar bitmapy
    prostokat= al_create_bitmap(100,50);         //  rozmiar bitmapy
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


#include <cmath>        // M_PI, sin(), cos(), asin(), acos(), pow(x,^n), sqrt()
#include <conio.h>      // getch()
#include <cstdlib>      // system("...");
#include <ctime>        // clock(), rand()
#include <fstream>      // fstrem >>
#include <iostream>     // cout<<, cin>>
#include <limits>
#include <math.h>
#include <Mmsystem.h>
#include <process.h>    // w¹tki
#include <stdio.h>
#include <string>       // string
#include <vector>       // vector<>
#include <windows.h>    // dll, Sleep()

using namespace std;

#include "Libraries\S3DGL\S3DGL.cpp"

#include "Libraries\DrawWrites.cpp"
#include "Libraries\ScriptsDLL.cpp"

#include "Libraries\Math\Trygonometry.cpp"

////////////////

#include "Source\Definer.h"

#include "Source\PreValues.cpp"
#include "Libraries\Keyboard.cpp"

////////////////

#include "Source\ClassBuildings.h"
#include "Source\ClassNPC.h"
#include "Source\ClassPlayer.h"
#include "Source\ClassMap.h"

#include "Source\Values.cpp"

#include "Source\WallCollision.cpp"

#include "Source\DefinerBuildings.cpp"
#include "Source\DefinerNPC.cpp"
#include "Source\DefinerPlayer.cpp"
#include "Source\DefinerMap.cpp"

////////////////

#include "Source\DrawCursor.cpp"
#include "Source\Renderer.cpp"

////////////////

#include "Source\LoadTextures.cpp"
#include "Source\Load.cpp"

#include "Source\DeInit.cpp"
#include "Source\Init.cpp"

#include "Source\MainLoop.cpp"

#include "Source\Main.cpp"


        //    al_show_native_message_box( display, "Blad", "NULL", "Nie moge utworzyc okna!", NULL, ALLEGRO_MESSAGEBOX_ERROR );
        //    al_draw_scaled_bitmap( bitmapa, sx, sy, sw, sh, dx, dy, dw, dh, 0 );
        //    al_draw_bitmap( bitmapa, 0, 0, 0 );
        //    al_set_target_bitmap( bitmapa );                          // ustawia "bitmapa" jako buffor podstawowy do którego bêdzie sie zapisywaæ powyzsza funkcj¹
        //    al_set_target_bitmap( al_get_backbuffer( display ) );     // ustawia buffor podstawowy na domyœly
        //    al_get_bitmap_width( bitmapa );                           //pobiera szerokosc "bitmapa"
        //    al_get_bitmap_height( bitmapa );                          //pobiera wysokosc  "bitmapa"
        //    al_rest( 0.2 );                                           //sleep w sekundach podany
        //    prymitywy:    http://allegro5kurs.blogspot.de/2012/10/lekcja-105-allegro5-kurs-prymitywy.html
        //    al_draw_line( x,   y-17, x,   y+17, al_map_rgb( 16, 16,  255 ), 1 );
        //    al_draw_rectangle( x-1, y-1, x+1, y+1, al_map_rgb( 192, 32, 32 ), 1 );
        //    al_draw_filled_rectangle( 3, 3, width-3, height-3, al_map_rgb( 32, 32, 32 ) );
        //    klawiatura:   http://allegro5kurs.blogspot.de/2012/06/lekcja-104-allegro5-kurs-klawiatura-i.html
        //    al_destroy_display( display );                            //usuwa okno

