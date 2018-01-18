#include<iostream>
#include<conio.h>

char NameSaveMap[64];

using namespace std;

void Keyboard(unsigned int time);
void DrawGameGUI();


unsigned int mouse[2];
float aspectshow = 60.0f;
unsigned int objectgrab=0;

unsigned int objectsettype = 0;
float PLAYERFORCEMOVING = 1.0f;
float wallradianplayer = 3.0f;


#include"ENGINE\Main.cpp"

#include"ENGINE\INPUTS\Keyboards.cpp"

#include"Menu.cpp"




bool playercrouch = false;

int main(int argc, char** argv)
{
    ScreenClear();
//    humanoid.resize(1);
//    EngineEnable( ENGINE_DRAWNORMAL );
    EngineEnable( ENGINE_PHISIC );
    EngineEnable( ENGINE_FULLSCREEN );
    EngineDisable( ENGINE_FIRSTPEARSON );
    
    object.resize(1);
    
//    char namemap[64];
    
    cout<<"Name of map: ";
    cin>>NameSaveMap;
    system("cls");
	Menu();

    ChangeInputsFunction( Keyboard );
    ChangeRendererGameFunction( DrawGameGUI );
    
    
    SetCursorPos( 400, 300 );
    
    LoadEngine(&argc, argv);
    
    return 0;
}


void Keyboard(unsigned int time)
{
    keyboardobiect.Update();
    
   
   
		if(keyboardobiect.upkeypressed[0xDD]) // ]}
		{
            PLAYERFORCEMOVING += 1.0f;
		}
		if(keyboardobiect.upkeypressed[0xDB]) // {[
		{
            PLAYERFORCEMOVING -= 1.0f;
            if( PLAYERFORCEMOVING < 1.0f )
            {
                PLAYERFORCEMOVING = 1.0f;
            }
		}
   
		if(keyboardobiect.upkeypressed[0xBE]) // .>
		{
            wallradianplayer += 1.0f;
		}
		if(keyboardobiect.upkeypressed[0xBC]) // <,
		{
            wallradianplayer -= 1.0f;
            if( wallradianplayer < 1.0f )
            {
                wallradianplayer = 1.0f;
            }
		}
   
   
   
   
		if(keyboardobiect.upkeypressed[0x31]) // 1
		{
            resize[0] -= 0.1f;
		}
		if(keyboardobiect.upkeypressed[0x32]) // 2
		{
            resize[0] += 0.1f;
		}
		
		if(keyboardobiect.upkeypressed[0x33]) // 3
		{
            resize[1] -= 0.1f;
		}
		if(keyboardobiect.upkeypressed[0x34]) // 4
		{
            resize[1] += 0.1f;
		}
		
		if(keyboardobiect.upkeypressed[0x35]) // 5
		{
            resize[2] -= 0.1f;
		}
		if(keyboardobiect.upkeypressed[0x36]) // 6
		{
            resize[2] += 0.1f;
		}
    
    
    
    
		if(keyboardobiect.upkeypressed[0x37]) // 7
		{
            resize[0] -= 10.0f;
		}
		if(keyboardobiect.upkeypressed[0x38]) // 8
		{
            resize[0] += 10.0f;
		}
		
		if(keyboardobiect.upkeypressed[0x39]) // 9
		{
            resize[1] -= 10.0f;
		}
		if(keyboardobiect.upkeypressed[0x30]) // 0
		{
            resize[1] += 10.0f;
		}
		
		if(keyboardobiect.upkeypressed[0xBB]) // '+'
		{
            resize[2] -= 10.0f;
		}
		if(keyboardobiect.upkeypressed[0xBD]) // '-'
		{
            resize[2] += 10.0f;
		}
		
		
		
		
		
		
		if( keyboardobiect.downkeypressed[VK_TAB] )
		{
			texture++;
			if( map.texture.size() <= texture )
				texture = 0;
		}
    
        if(keyboardobiect.upkeypressed[0x4C]) // 'L'
        {
            if(object[draw_object_id].phisicmove)
            {
    			object[draw_object_id].phisicmove = false;
    			object[draw_object_id].speed[0] = 0.0f;
    			object[draw_object_id].speed[1] = 0.0f;
    			object[draw_object_id].speed[2] = 0.0f;
    			object[draw_object_id].force[0] = 0.0f;
    			object[draw_object_id].force[1] = 0.0f;
    			object[draw_object_id].force[2] = 0.0f;
            }
            else
            {
			 object[draw_object_id].phisicmove = true;
            }
            
        }

/*    
		if(GetAsyncKeyState(0x4B) & 0x8000) // 'K'
		{
			object[draw_object_id].phisicmove = true;
		}
		
		if(GetAsyncKeyState(0x4C) & 0x8000) // 'L'
		{
			object[draw_object_id].phisicmove = false;
			object[draw_object_id].speed[0] = 0.0f;
			object[draw_object_id].speed[1] = 0.0f;
			object[draw_object_id].speed[2] = 0.0f;
			object[draw_object_id].force[0] = 0.0f;
			object[draw_object_id].force[1] = 0.0f;
			object[draw_object_id].force[2] = 0.0f;
			
		}
*/

		if(keyboardobiect.downkeypressed[0x01])// || GetAsyncKeyState(0x0D) & 0x8000) // LPM || ENTER
		{
            float point2[3] = { Xpoint( object[draw_object_id].lookxz ), Ypoint( object[draw_object_id].looky ), Zpoint( object[draw_object_id].lookxz ) };
            
            float rad_ian = sqrt( point2[0]*point2[0]+point2[1]*point2[1]+point2[2]*point2[2] );
                
            point2[0] = ( wallradianplayer * point2[0] / rad_ian );
            point2[1] = ( wallradianplayer * point2[1] / rad_ian );
            point2[2] = ( wallradianplayer * point2[2] / rad_ian );
            
            
            
            
            point2[0] += object[draw_object_id].pos[0];
            point2[1] += object[draw_object_id].pos[1];
            point2[2] += object[draw_object_id].pos[2];
            
            
            switch( objectsettype )
            {
                case 0:
                    wallsave[wallprinter]( point2, resize[0], resize[1], resize[2], texture );
                    break;
                case 1:
                    object.resize( object.size() + 1 );
                    object[object.size()-1].pos[0] = point2[0];
                    object[object.size()-1].pos[1] = point2[1];
                    object[object.size()-1].pos[2] = point2[2];
                    object[object.size()-1].mass = 75.0f;
                    object[object.size()-1].radian = 0.85f;
                    object[object.size()-1].modeltype = 0;
                    object[object.size()-1].model = 0;
                    object[object.size()-1].phisiccollision = 1;
                    object[object.size()-1].phisicmove = 1;
                    object[object.size()-1].phisicline = 1;
                    object[object.size()-1].phisicsee = 1;
                    break;
            }
            
		}
		if(GetAsyncKeyState(0x02) & 0x8000) // RPM
		{
			
		}
		if(keyboardobiect.downkeypressed[0x04]) // MPM
		{
            objectsettype++;
            if( objectsettype >= 2 )
            {
                objectsettype = 0;
            }
		}



		if( GetAsyncKeyState(0x57) & 0x8000 ) // 'W'
		{
              object[draw_object_id].pos[0] += PLAYERFORCEMOVING * Xpoint( object[draw_object_id].lookxz ) / 10.0f;
              object[draw_object_id].pos[2] += PLAYERFORCEMOVING * Zpoint( object[draw_object_id].lookxz ) / 10.0f;
		}
		if( GetAsyncKeyState(0x41) & 0x8000 ) // 'A'
		{
              object[draw_object_id].pos[0] += PLAYERFORCEMOVING * Xpoint( object[draw_object_id].lookxz + 90.0f ) / 10.0f;
              object[draw_object_id].pos[2] += PLAYERFORCEMOVING * Zpoint( object[draw_object_id].lookxz + 90.0f ) / 10.0f;
		}
		if( GetAsyncKeyState(0x53) & 0x8000 ) // 'S'
		{
              object[draw_object_id].pos[0] += PLAYERFORCEMOVING * Xpoint( object[draw_object_id].lookxz + 180.0f ) / 10.0f;
              object[draw_object_id].pos[2] += PLAYERFORCEMOVING * Zpoint( object[draw_object_id].lookxz + 180.0f ) / 10.0f;
		}
		if( GetAsyncKeyState(0x44) & 0x8000 ) // 'D'
		{
              object[draw_object_id].pos[0] += PLAYERFORCEMOVING * Xpoint( object[draw_object_id].lookxz + 270.0f ) / 10.0f;
              object[draw_object_id].pos[2] += PLAYERFORCEMOVING * Zpoint( object[draw_object_id].lookxz + 270.0f ) / 10.0f;
		}
		if( GetAsyncKeyState(0x20) & 0x8000 ) // SPACE
		{
            object[draw_object_id].pos[1] += PLAYERFORCEMOVING * 0.1f;
		}
		if( GetAsyncKeyState(0x11) & 0x8000 ) // CTRL
		{
            object[draw_object_id].pos[1] -= PLAYERFORCEMOVING * 0.1f;
		}












		if(GetAsyncKeyState(0x1B) & 0x8000) // esc
		{
            map.SaveMap(NameSaveMap);
            exit(0);
		}

		if(keyboardobiect.downkeypressed[0x51]) // 'Q'
		{
            wallprinter ++;
            resize[0] = 1.0f;
            resize[1] = 1.0f;
            resize[2] = 1.0f;
            if( wallprinter < 0 )
                wallprinter = 0;
            if( wallprinter >= 5 )
                wallprinter = 0;
		}
		if(GetAsyncKeyState(0x52) & 0x8000) // 'R'
		{
		}
		if(GetAsyncKeyState(0xC0) & 0x8000)	// '~'
		{
            Menu();
		}
		if(GetAsyncKeyState(0x4D) & 0x8000)	// 'M'
		{
		}
		else
		{
		}
		if(GetAsyncKeyState(0x4E) & 0x8000)	// 'N'
		{
		}
		
		if(keyboardobiect.downkeypressed[0x4B]) // 'K'
		{
            if( map.tri.size() > 0 )
                map.tri.resize( map.tri.size() - 1 );
		}
		if(GetAsyncKeyState(0x4C) & 0x8000) // 'L'
		{
		}
		else
		{
		}
		if(GetAsyncKeyState(0x42) & 0x8000) // 'B'
		{
		}
		if(GetAsyncKeyState(0x54) & 0x8000) // 'T'
		{
			cout<<endl<<map.tri.size();
		}

		if(GetAsyncKeyState(0x31) & 0x8000) // 1
		{
		}
		if(GetAsyncKeyState(0x32) & 0x8000) // 2
		{
		}
		if(GetAsyncKeyState(0x33) & 0x8000) // 3
		{
		}
		if(GetAsyncKeyState(0x34) & 0x8000) // 4
		{
		}
		if(GetAsyncKeyState(0x35) & 0x8000) // 5
		{
		}
		if(GetAsyncKeyState(0x36) & 0x8000) // 6
		{
		}

		if(keyboardobiect.downkeypressed[VK_F5]) // F5
		{
            map.SaveMap(NameSaveMap);
		}
		if(GetAsyncKeyState(VK_F6) & 0x8000) // F6
		{
		}
		
		if(GetAsyncKeyState(0x38) & 0x8000) // 8
		{
		}
		if(GetAsyncKeyState(0x39) & 0x8000) // 9
		{
		}
		if(GetAsyncKeyState(0x30) & 0x8000) // 0
		{
		}




}



unsigned int frametimegraphic = 0;;


void DrawGameGUI()
{
     
	if(GetAsyncKeyState(0x1B) & 0x8000) // esc
	{
//        exit(0);
	}
    
char possition[6][32];
char speed[6][32];
char FPS[2][64];
char playerspeed[32];
char wallradian[32];




sprintf( possition[0], "X: %f", object[draw_object_id].pos[0] );
sprintf( possition[1], "Y: %f", object[draw_object_id].pos[1] );
sprintf( possition[2], "Z: %f", object[draw_object_id].pos[2] );
sprintf( possition[3], "X: %f", object[2].pos[0] );
sprintf( possition[4], "Y: %f", object[2].pos[1] );
sprintf( possition[5], "Z: %f", object[2].pos[2] );
sprintf( speed[0], "X: %f", object[draw_object_id].speed[0] );
sprintf( speed[1], "Y: %f", object[draw_object_id].speed[1] );
sprintf( speed[2], "Z: %f", object[draw_object_id].speed[2] );
sprintf( FPS[0], "Graphic FPS: %f", timefps[1] );
sprintf( FPS[1], "Physic FPS:  %f", timefps[2] );
sprintf( playerspeed, "objectgrab:  %f", PLAYERFORCEMOVING );
sprintf( wallradian, "objectgrab:  %f", wallradianplayer );
    
    
	glDepthFunc( GL_ALWAYS );
    ScreenClear();
    glLoadIdentity();
    
    
    float poss[3];
    poss[0] = object[draw_object_id].pos[0];
    poss[1] = object[draw_object_id].pos[1] + object[draw_object_id].radian*0.7f;
    poss[2] = object[draw_object_id].pos[2];
    
    unsigned int objectlook = CollisionLineObiect( object[draw_object_id].lookxz, object[draw_object_id].looky, 1000.0f, draw_object_id, poss );
    
    char objectsee[32];
    sprintf( objectsee, "Object: %i", objectlook );
    
    
    char aim[4] = { '\\', 0, '/', 0 };
    
    
    ScreenGoTo( 0, 1 );
    ScreenWrite( possition[0] );
    ScreenGoTo( 0, 2 );
    ScreenWrite( possition[1] );
    ScreenGoTo( 0, 3 );
    ScreenWrite( possition[2] );
    
    ScreenGoTo( 0, 8 );
    ScreenWrite( speed[0] );
    ScreenGoTo( 0, 9 );
    ScreenWrite( speed[1] );
    ScreenGoTo( 0, 10 );
    ScreenWrite( speed[2] );
    
    
    ScreenGoTo( 0, 5 );
    ScreenWrite( FPS[0] );
    ScreenGoTo( 0, 6 );
    ScreenWrite( FPS[1] );
    
    
    ScreenGoTo( 35, 1 );
    ScreenWrite( objectsee );
    
    ScreenGoTo( 64, 3 );
    ScreenWrite( playerspeed );
    ScreenGoTo( 64, 4 );
    ScreenWrite( wallradian );
    
    
    
    ScreenDraw();
    
    glDisable( GL_BLEND );
    
    glLineWidth(1.0);
    
    	glBegin( GL_LINES );
        	glColor3f( 1.0f, 0.0f, 0.0f );
        		glVertex3f( -1.0f, 0.0f,  -40.0f );
        		glVertex3f( 1.0f,  0.0f,  -40.0f );
        		glVertex3f( 0.0f,  -1.0f, -40.0f );
        		glVertex3f( 0.0f,  1.0f,  -40.0f );
        glEnd();
    
    
    glEnable( GL_BLEND );
    
    
        unsigned int time = clock() - frametimegraphic;
        
        
        
		POINT point;
		GetCursorPos( & point );

        object[draw_object_id].lookxz -= float(point.x-400) * 360.0f * float( time ) / 16000.0f;
        object[draw_object_id].looky -= float(point.y-300) * 360.0f * float( time ) / 16000.0f;
    SetCursorPos( 400, 300 );
    
        
    Keyboard(time);
    
		if(GetAsyncKeyState(0x25) & 0x8000) // LEFTARROW
		{
            object[draw_object_id].lookxz += 360.0f * float( time ) / 2000.0f;
		}		
		if(GetAsyncKeyState(0x26) & 0x8000) // UPARROW
		{
            object[draw_object_id].looky += 180.0f * float( time ) / 1000.0f;
		}
		if(GetAsyncKeyState(0x27) & 0x8000) // RIGHTARROW
		{
            object[draw_object_id].lookxz -= 360.0f * float( time ) / 2000.0f;
		}
		if(GetAsyncKeyState(0x28) & 0x8000) // DOWNARROW
		{
            object[draw_object_id].looky -= 360.0f * float( time ) / 1000.0f;
		}
		if( object[draw_object_id].looky < -87.9f )
		{
            object[draw_object_id].looky = -87.9f;
        }
		else if( object[draw_object_id].looky > 87.9f )
		{
            object[draw_object_id].looky = 87.9f;
        }
        
        frametimegraphic = clock();
    
}
















