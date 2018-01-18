#include<iostream>
#include<conio.h>


using namespace std;

void Keyboard(unsigned int time);
void DrawGameGUI();


unsigned int mouse[2];
float aspectshow = 60.0f;
unsigned int objectgrab=0;

#include"ENGINE\Libraries.h"

#include"ENGINE\INPUTS\Keyboards.cpp"



#define PLAYE_RFORCEMOVING 1500.0f



bool playercrouch = false;

int main(int argc, char** argv)
{
    
    SetWidnowName( "Gamen Alphen NULL point NULLEN" );
    SetMapNameToLoad( "map1.map" );
    
    ScreenClear();
//    EngineEnable( ENGINE_DRAWNORMAL );
    EngineDisable( ENGINE_PHISIC );
//    EngineEnable( ENGINE_FULLSCREEN );
    EngineDisable( ENGINE_FIRSTPEARSON );
    
    ChangeInputsFunction( Keyboard );
    ChangeRendererGameFunction( DrawGameGUI );
    
    
    SetCursorPos( 400, 300 );
    
    
    
    LoadEngine(argc, argv);
    
    return 0;
}


void Keyboard(unsigned int time)
{
    keyboardobiect.Update();
    
   
		if(keyboardobiect.upkeypressed[0x31]) // 1
		{
            aspectshow += 2.0f;
		}
		if(keyboardobiect.upkeypressed[0x32]) // 2
		{
            aspectshow -= 2.0f;
		}
		
		
		if(keyboardobiect.upkeypressed[0x33]) // 3
		{
            if( EngineGet( ENGINE_FIRSTPEARSON ) )
            {
                EngineDisable( ENGINE_FIRSTPEARSON );
            }
            else
            {
                EngineEnable( ENGINE_FIRSTPEARSON );
            }
		}
    
    
    
        if(keyboardobiect.upkeypressed[0x4C]) // 'L'
        {
            if(0)//PLAYER.phisicmove)
            {
    			//PLAYER.phisicmove = false;
    			PLAYER.speed.vertex[0] = 0.0f;
    			PLAYER.speed.vertex[1] = 0.0f;
    			PLAYER.speed.vertex[2] = 0.0f;
    			PLAYER.force.vertex[0] = 0.0f;
    			PLAYER.force.vertex[1] = 0.0f;
    			PLAYER.force.vertex[2] = 0.0f;
            }
            else
            {
			 //PLAYER.phisicmove = true;
            }
            
        }

/*    
		if(GetAsyncKeyState(0x4B) & 0x8000) // 'K'
		{
			PLAYER.phisicmove = true;
		}
		
		if(GetAsyncKeyState(0x4C) & 0x8000) // 'L'
		{
			PLAYER.phisicmove = false;
			PLAYER.speed[0] = 0.0f;
			PLAYER.speed[1] = 0.0f;
			PLAYER.speed[2] = 0.0f;
			PLAYER.force[0] = 0.0f;
			PLAYER.force[1] = 0.0f;
			PLAYER.force[2] = 0.0f;
			
		}
*/
/*
		if(GetAsyncKeyState(0x01) & 0x8000 || GetAsyncKeyState(0x0D) & 0x8000) // LPM || ENTER
		{
			values.lpm = TRUE;
		}
		else
		{
			values.lpm = FALSE;
		}
		if(GetAsyncKeyState(0x02) & 0x8000) // RPM
		{
			aspectshow=60.0f;
			values.rpm = TRUE;
		}
		else
		{
			if( (GetAsyncKeyState(0x04) & 0x8000) == 0 )
				aspectshow=90.0f;
			values.rpm = FALSE;
		}
		if(GetAsyncKeyState(0x04) & 0x8000) // MPM
		{
			aspectshow=30.0f;
			values.mpm = TRUE;
		}
		else
		{
			if( (GetAsyncKeyState(0x02) & 0x8000) == 0 )
				aspectshow=90.0f;
			values.mpm = FALSE;
		}

*/

if( 1 )//PLAYER.phisicmove == false )
{
		if( GetAsyncKeyState(0x57) & 0x8000 ) // 'W'
		{
              PLAYER.pos.vertex[0] += Xpoint( PLAYER.lookxz ) / 2.0f;
              PLAYER.pos.vertex[2] += Zpoint( PLAYER.lookxz ) / 2.0f;
		}
		if( GetAsyncKeyState(0x41) & 0x8000 ) // 'A'
		{
              PLAYER.pos.vertex[0] += Xpoint( PLAYER.lookxz + 90.0f ) / 2.0f;
              PLAYER.pos.vertex[2] += Zpoint( PLAYER.lookxz + 90.0f ) / 2.0f;
		}
		if( GetAsyncKeyState(0x53) & 0x8000 ) // 'S'
		{
              PLAYER.pos.vertex[0] += Xpoint( PLAYER.lookxz + 180.0f ) / 2.0f;
              PLAYER.pos.vertex[2] += Zpoint( PLAYER.lookxz + 180.0f ) / 2.0f;
		}
		if( GetAsyncKeyState(0x44) & 0x8000 ) // 'D'
		{
              PLAYER.pos.vertex[0] += Xpoint( PLAYER.lookxz + 270.0f ) / 2.0f;
              PLAYER.pos.vertex[2] += Zpoint( PLAYER.lookxz + 270.0f ) / 2.0f;
		}
		if( GetAsyncKeyState(0x20) & 0x8000 ) // SPACE
		{
            PLAYER.pos.vertex[1] += 0.5f;
		}
		if( GetAsyncKeyState(0x11) & 0x8000 ) // CTRL
		{
            PLAYER.pos.vertex[1] -= 0.5f;
		}
}
else
{
        /*
		if( GetAsyncKeyState(0x57) & 0x8000 ) // 'W'
		{
              PLAYER.speed[0] += Xpoint( PLAYER.lookxz ) * 16.0f * ( float(PLAYER.collision) + 0.3f ) * float(time/1000.0f);
              PLAYER.speed[2] += Zpoint( PLAYER.lookxz ) * 16.0f * ( float(PLAYER.collision) + 0.3f ) * float(time/1000.0f);
		}
		if( GetAsyncKeyState(0x41) & 0x8000 ) // 'A'
		{
              PLAYER.speed[0] += Xpoint( PLAYER.lookxz + 90.0f ) * 16.0f * ( float(PLAYER.collision) + 0.3f ) * float(time/1000.0f);
              PLAYER.speed[2] += Zpoint( PLAYER.lookxz + 90.0f ) * 16.0f * ( float(PLAYER.collision) + 0.3f ) * float(time/1000.0f);
		}
		if( GetAsyncKeyState(0x53) & 0x8000 ) // 'S'
		{
              PLAYER.speed[0] += Xpoint( PLAYER.lookxz + 180.0f ) * 16.0f * ( float(PLAYER.collision) + 0.3f ) * float(time/1000.0f);
              PLAYER.speed[2] += Zpoint( PLAYER.lookxz + 180.0f ) * 16.0f * ( float(PLAYER.collision) + 0.3f ) * float(time/1000.0f);
		}
		if( GetAsyncKeyState(0x44) & 0x8000 ) // 'D'
		{
              PLAYER.speed[0] += Xpoint( PLAYER.lookxz + 270.0f ) * 16.0f * ( float(PLAYER.collision) + 0.3f ) * float(time/1000.0f);
              PLAYER.speed[2] += Zpoint( PLAYER.lookxz + 270.0f ) * 16.0f * ( float(PLAYER.collision) + 0.3f ) * float(time/1000.0f);
		}
		*/
		
        
		if( GetAsyncKeyState(0x57) & 0x8000 ) // 'W'
		{
              PLAYER.force.vertex[0] += Xpoint( PLAYER.lookxz )          * PLAYE_RFORCEMOVING * ( float(PLAYER.collision)*0.75f + 0.25f + float(keyboardobiect.keypressed[0x10]&&PLAYER.collision)*2.0f + float(playercrouch==0) ) * 0.5f;
              PLAYER.force.vertex[2] += Zpoint( PLAYER.lookxz )          * PLAYE_RFORCEMOVING * ( float(PLAYER.collision)*0.75f + 0.25f + float(keyboardobiect.keypressed[0x10]&&PLAYER.collision)*2.0f + float(playercrouch==0) ) * 0.5f;
		}
		if( GetAsyncKeyState(0x41) & 0x8000 ) // 'A'
		{
              PLAYER.force.vertex[0] += Xpoint( PLAYER.lookxz + 90.0f )  * PLAYE_RFORCEMOVING * ( float(PLAYER.collision)*0.75f + 0.25f + float(keyboardobiect.keypressed[0x10]&&PLAYER.collision)*2.0f + float(playercrouch==0) ) * 0.5f;
              PLAYER.force.vertex[2] += Zpoint( PLAYER.lookxz + 90.0f )  * PLAYE_RFORCEMOVING * ( float(PLAYER.collision)*0.75f + 0.25f + float(keyboardobiect.keypressed[0x10]&&PLAYER.collision)*2.0f + float(playercrouch==0) ) * 0.5f;
                
		}
		if( GetAsyncKeyState(0x53) & 0x8000 ) // 'S'
		{
              PLAYER.force.vertex[0] += Xpoint( PLAYER.lookxz + 180.0f ) * PLAYE_RFORCEMOVING * ( float(PLAYER.collision)*0.75f + 0.25f + float(keyboardobiect.keypressed[0x10]&&PLAYER.collision)*2.0f + float(playercrouch==0) ) * 0.5f;
              PLAYER.force.vertex[2] += Zpoint( PLAYER.lookxz + 180.0f ) * PLAYE_RFORCEMOVING * ( float(PLAYER.collision)*0.75f + 0.25f + float(keyboardobiect.keypressed[0x10]&&PLAYER.collision)*2.0f + float(playercrouch==0) ) * 0.5f;
		}
		if( GetAsyncKeyState(0x44) & 0x8000 ) // 'D'
		{
              PLAYER.force.vertex[0] += Xpoint( PLAYER.lookxz + 270.0f ) * PLAYE_RFORCEMOVING * ( float(PLAYER.collision)*0.75f + 0.25f + float(keyboardobiect.keypressed[0x10]&&PLAYER.collision)*2.0f + float(playercrouch==0) ) * 0.5f;
              PLAYER.force.vertex[2] += Zpoint( PLAYER.lookxz + 270.0f ) * PLAYE_RFORCEMOVING * ( float(PLAYER.collision)*0.75f + 0.25f + float(keyboardobiect.keypressed[0x10]&&PLAYER.collision)*2.0f + float(playercrouch==0) ) * 0.5f;
              
		}

		
		if( keyboardobiect.downkeypressed[0x20] ) // SPACE
		{
            if( PLAYER.collision == true  )                                      
            {
            //    PLAYER.force[1] += 5.0f * PLAYER.mass / (float(time)/1000.0f);
                PLAYER.speed.vertex[1] += 3.0f;
                PLAYER.speed.vertex[0] += Xpoint( PLAYER.lookxz ) * 0.5f * ( 2.0f + float((GetAsyncKeyState(0x10) & 0x8000)%2) ) / 3.0f;
                PLAYER.speed.vertex[2] += Zpoint( PLAYER.lookxz ) * 0.5f * ( 2.0f + float((GetAsyncKeyState(0x10) & 0x8000)%2) ) / 3.0f;
            }
		}
		if( GetAsyncKeyState(0x11) & 0x8000 ) // CTRL
		{
              
            if( playercrouch == false )
            {
            //    PLAYER.radian /= 2.0f;
                PLAYER.speed.vertex[1] -= 0.5f;
                playercrouch = true;
            }
		}
		else
		{
            if( playercrouch == true )
            {
                if( PLAYER.collision == false )
                {
                //    PLAYER.radian *= 2.0f;
                    playercrouch = false;
                }
                PLAYER.speed.vertex[1] += 0.5f;
            }
        }
/*		if(GetAsyncKeyState(0x10) & 0x8000) // SHIFT
		{
			values.shift = TRUE;
		}
		else
		{
			values.shift = FALSE;
		}
*/
}












/*


		POINT point;
		GetCursorPos( & point );

        PLAYER.lookxz -= float(point.x-400) * 360.0f * float( time ) / 16000.0f;
        PLAYER.looky -= float(point.y-300) * 360.0f * float( time ) / 16000.0f;
    SetCursorPos( 400, 300 );
    */


/*
		if(GetAsyncKeyState(0x25) & 0x8000) // LEFTARROW
		{
            PLAYER.lookxz += 360.0f * float( time ) / 2000.0f;
		}		
		if(GetAsyncKeyState(0x26) & 0x8000) // UPARROW
		{
            PLAYER.looky += 180.0f * float( time ) / 1000.0f;
		}
		if(GetAsyncKeyState(0x27) & 0x8000) // RIGHTARROW
		{
            PLAYER.lookxz -= 360.0f * float( time ) / 2000.0f;
		}
		if(GetAsyncKeyState(0x28) & 0x8000) // DOWNARROW
		{
            PLAYER.looky -= 360.0f * float( time ) / 1000.0f;
		}
		if( PLAYER.looky < -87.9f )
		{
            PLAYER.looky = -87.9f;
        }
		else if( PLAYER.looky > 87.9f )
		{
            PLAYER.looky = 87.9f;
        }
*/

		if(GetAsyncKeyState(0x1B) & 0x8000) // esc
		{
            exit(0);
		}
/*
		if(GetAsyncKeyState(0x51) & 0x8000) // 'Q'
		{
			Player.ChangeWeapon( Player.weaponequiped + 1 );
		}
		if(GetAsyncKeyState(0x52) & 0x8000) // 'R'
		{
			Player.Reload();
		}
		if(GetAsyncKeyState(0xC0) & 0x8000)	// '~'
		{
			ShowCursor(TRUE);
			values.end = TRUE;
			menutype = CONSOLE;
			break;
		}
		if(GetAsyncKeyState(0x4D) & 0x8000)	// 'M'
		{
			values.m = true;
		}
		else
		{
			values.m = false;
		}
		if(GetAsyncKeyState(0x4E) & 0x8000)	// 'N'
		{
			if( COLLISION_IS == false )
				COLLISION_IS = true;
			else
				COLLISION_IS = false;
		}
		
		if(GetAsyncKeyState(0x4B) & 0x8000) // 'K'
		{
			Player.Dead(Player.Rank());
		}
		if(GetAsyncKeyState(0x4C) & 0x8000) // 'L'
		{
			values.l = true;
		}
		else
		{
			values.l = false;
		}
		if(GetAsyncKeyState(0x42) & 0x8000) // 'B'
		{
			CtObject(30.0f,20.0f,30.0f,BOT,rand()%3);
			object[ object.size()-1].Dead(object[ object.size()-1].Rank());
		}
		if(GetAsyncKeyState(0x54) & 0x8000) // 'T'
		{
			cout<<endl<<object.size();
		}

		if(GetAsyncKeyState(0x31) & 0x8000) // 1
		{
			Player.ChangeWeapon( 0 );
		}
		if(GetAsyncKeyState(0x32) & 0x8000) // 2
		{
			Player.ChangeWeapon( 1 );
		}
		if(GetAsyncKeyState(0x33) & 0x8000) // 3
		{
			Player.ChangeWeapon( 2 );
		}
		if(GetAsyncKeyState(0x34) & 0x8000) // 4
		{
			Player.ChangeWeapon( 3 );
		}
		if(GetAsyncKeyState(0x35) & 0x8000) // 5
		{
			Player.ChangeWeapon( 4 );
		}
		if(GetAsyncKeyState(0x36) & 0x8000) // 6
		{
			Player.ChangeWeapon( 5 );
		}

		if(GetAsyncKeyState(VK_F5) & 0x8000) // F5
		{
			LoadGame();
		}
		if(GetAsyncKeyState(VK_F6) & 0x8000) // F6
		{
			SaveGame();
		}
		
		if(GetAsyncKeyState(0x38) & 0x8000) // 8
		{
			CtObject(30.0f,20.0f,30.0f,BOT,0);
			object[ object.size()-1].Dead(object[ object.size()-1].Rank());
		}
		if(GetAsyncKeyState(0x39) & 0x8000) // 9
		{
			CtObject(30.0f,20.0f,30.0f,BOT,1);
			object[ object.size()-1].Dead(object[ object.size()-1].Rank());
		}
		if(GetAsyncKeyState(0x30) & 0x8000) // 0
		{
			CtObject(30.0f,20.0f,30.0f,BOT,2);
			object[ object.sze()-1].Dead(object[ object.size()-1].Rank());
		}



*/

/*
        if( objectgrab != 0 && objectgrab != draw_object_id )
		{
            cout<<"1 ";
    		if( keyboardobiect.downkeypressed[0x45] ) // || sqrt( pow(object[objectgrab].pos[0]-PLAYER.pos[0],2)+pow(object[objectgrab].pos[1]-PLAYER.pos[1],2)+pow(object[objectgrab].pos[2]-PLAYER.pos[2],2) ) > 17.0f ) // 'E'
    		{
            cout<<"2 ";
       //         objectgrab = 0;
            }
        }

		if( keyboardobiect.downkeypressed[0x45] ) // 'E'
		{
                objectgrab = 0;
            cout<<"3 ";
            float poss[3];
            poss[0] = PLAYER.pos[0];
            poss[1] = PLAYER.pos[1] + PLAYER.radian*0.7f;
            poss[2] = PLAYER.pos[2];
            objectgrab = CollisionLineObiect( PLAYER.lookxz, PLAYER.looky, 4.0f, draw_object_id, poss );
			if( object[objectgrab].mass >= 20.0f )
			{
            cout<<"4 ";
                objectgrab = 0;
            }
		}
		

        if( objectgrab != 0 && objectgrab != draw_object_id )
		{
            
            cout<<"5 ";
            if( (GetAsyncKeyState(0x01) & 0x8000) == false ) //LPM
            {   
            cout<<"6 ";
                float point1[3] = { object[objectgrab].pos[0], object[objectgrab].pos[1], object[objectgrab].pos[2] };
                float point2[3] = { Xpoint( PLAYER.lookxz ), Ypoint( PLAYER.looky ), Zpoint( PLAYER.lookxz ) };
                float rad_ian = sqrt( point2[0]*point2[0]+point2[1]*point2[1]+point2[2]*point2[2] );
                
                point2[0] = ( 3.0f * point2[0] / rad_ian ) + PLAYER.pos[0];
                point2[1] = ( 3.0f * point2[1] / rad_ian ) + PLAYER.pos[1]   +(PLAYER.radian*0.7f); //+(PLAYER.radian*0.7f)   -  z poziomu oczu musi to byc ;d
                point2[2] = ( 3.0f * point2[2] / rad_ian ) + PLAYER.pos[2];
                
                float movevector[3] = { point1[0] - point2[0], point1[1] - point2[1], point1[2] - point2[2] };
                
                object[objectgrab].speed[0] = - movevector[0] / float(time);
                object[objectgrab].speed[1] = - movevector[1] / float(time);
                object[objectgrab].speed[2] = - movevector[2] / float(time);
                
                object[objectgrab].speed[0] *= 100.0f;
                object[objectgrab].speed[1] *= 100.0f;
                object[objectgrab].speed[2] *= 100.0f;
                
                object[objectgrab].force[1] = - object[objectgrab].gravitation * object[objectgrab].mass;
            }
            else
            {
            cout<<"7 ";
                float point2[3] = { Xpoint( PLAYER.lookxz ), Ypoint( PLAYER.looky ), Zpoint( PLAYER.lookxz ) };
                float rad_ian = sqrt( point2[0]*point2[0]+point2[1]*point2[1]+point2[2]*point2[2] );
                
                point2[0] = ( point2[0] / rad_ian );
                point2[1] = ( point2[1] / rad_ian );
                point2[2] = ( point2[2] / rad_ian );
                
                point2[0] *= 100.0f/(object[objectgrab].mass);
                point2[1] *= 100.0f/(object[objectgrab].mass);
                point2[2] *= 100.0f/(object[objectgrab].mass);
                
                object[objectgrab].speed[0] = point2[0];
                object[objectgrab].speed[1] = point2[1];
                object[objectgrab].speed[2] = point2[2];
                
                objectgrab = 0;
            }
        }
*/












/*
        if( objectgrab != 0 && objectgrab != draw_object_id )
		{
            
    		if( keyboardobiect.downkeypressed[0x45] ) // 'E'
    		{
                objectgrab = 0;
            }
        }

		if( keyboardobiect.downkeypressed[0x45] ) // 'E'
		{
            float poss[3];
            poss[0] = PLAYER.pos[0];
            poss[1] = PLAYER.pos[1] + PLAYER.radian*0.7f;
            poss[2] = PLAYER.pos[2];
            objectgrab = CollisionLineObiect( PLAYER.lookxz, PLAYER.looky, 5.0f + PLAYER.radian, draw_object_id, poss );
			if( object[objectgrab].mass >= 20.0f )
			{
                objectgrab = 0;
            }
		}
		
        //if( objectgrab != 0 && objectgrab != draw_object_id )
		//{
    	//	if(  sqrt( pow(object[objectgrab].pos[0]-PLAYER.pos[0],2)+pow(object[objectgrab].pos[1]-PLAYER.pos[1],2)+pow(object[objectgrab].pos[2]-PLAYER.pos[2],2) ) > (6.0f + PLAYER.radian + object[objectgrab].radian) )
    	//	{
       //         objectgrab = 0;
       //     }
       // }
        if( objectgrab != 0 && objectgrab != draw_object_id )
		{
            if( (GetAsyncKeyState(0x01) & 0x8000) == false ) //LPM
            {   
                float point1[3] = { object[objectgrab].pos[0], object[objectgrab].pos[1], object[objectgrab].pos[2] };
                float point2[3] = { Xpoint( PLAYER.lookxz ), Ypoint( PLAYER.looky ), Zpoint( PLAYER.lookxz ) };
                float rad_ian = sqrt( point2[0]*point2[0]+point2[1]*point2[1]+point2[2]*point2[2] );
                
                point2[0] = ( 3.0f * point2[0] / rad_ian ) + PLAYER.pos[0];
                point2[1] = ( 3.0f * point2[1] / rad_ian ) + PLAYER.pos[1]   +(PLAYER.radian*0.7f); //+(PLAYER.radian*0.7f)   -  z poziomu oczu musi to byc ;d
                point2[2] = ( 3.0f * point2[2] / rad_ian ) + PLAYER.pos[2];
                
                float movevector[3] = { point1[0] - point2[0], point1[1] - point2[1], point1[2] - point2[2] };
                
                object[objectgrab].speed[0] = - movevector[0] / float(time);
                object[objectgrab].speed[1] = - movevector[1] / float(time);
                object[objectgrab].speed[2] = - movevector[2] / float(time);
                
                object[objectgrab].speed[0] *= 100.0f;
                object[objectgrab].speed[1] *= 100.0f;
                object[objectgrab].speed[2] *= 100.0f;
                
                object[objectgrab].force[1] = - object[objectgrab].gravitation * object[objectgrab].mass;
            }
            else
            {
                float point2[3] = { Xpoint( PLAYER.lookxz ), Ypoint( PLAYER.looky ), Zpoint( PLAYER.lookxz ) };
                float rad_ian = sqrt( point2[0]*point2[0]+point2[1]*point2[1]+point2[2]*point2[2] );
                
                point2[0] = ( point2[0] / rad_ian );
                point2[1] = ( point2[1] / rad_ian );
                point2[2] = ( point2[2] / rad_ian );
                
                point2[0] *= 100.0f/(object[objectgrab].mass);
                point2[1] *= 100.0f/(object[objectgrab].mass);
                point2[2] *= 100.0f/(object[objectgrab].mass);
                
                object[objectgrab].speed[0] = point2[0];
                object[objectgrab].speed[1] = point2[1];
                object[objectgrab].speed[2] = point2[2];
                
                objectgrab = 0;
            }
        }
*/


}



unsigned int frametimegraphic = 0;;


void DrawGameGUI()
{
     
		if(GetAsyncKeyState(0x1B) & 0x8000) // esc
		{
            exit(0);
		}
    
char possition[6][32];
char speed[6][32];
char FPS[2][64];
char objectgrabed[32];


sprintf( possition[0], "X: %f", PLAYER.pos.vertex[0] );
sprintf( possition[1], "Y: %f", PLAYER.pos.vertex[1] );
sprintf( possition[2], "Z: %f", PLAYER.pos.vertex[2] );
//sprintf( possition[3], "X: %f", object[2].pos.vertex[0] );
//sprintf( possition[4], "Y: %f", object[2].pos.vertex[1] );
//sprintf( possition[5], "Z: %f", object[2].pos.vertex[2] );
sprintf( speed[0], "X: %f", PLAYER.speed.vertex[0] );
sprintf( speed[1], "Y: %f", PLAYER.speed.vertex[1] );
sprintf( speed[2], "Z: %f", PLAYER.speed.vertex[2] );
sprintf( FPS[0], "Graphic FPS: %f", timefps[1] );
sprintf( FPS[1], "Physic FPS:  %f", timefps[2] );
sprintf( objectgrabed, "objectgrab:  %i %i", objectgrab, int(keyboardobiect.downkeypressed[0x45]) );
    
    
	glDepthFunc( GL_ALWAYS );
    ScreenClear();
    glLoadIdentity();
    
    
    float poss[3];
    poss[0] = PLAYER.pos.vertex[0];
    poss[1] = PLAYER.pos.vertex[1];// + PLAYER.radian*0.7f;
    poss[2] = PLAYER.pos.vertex[2];
    
    //unsigned int objectlook = CollisionLineObiect( PLAYER.lookxz, PLAYER.looky, 1000.0f, draw_object_id, poss );
    
    //char objectsee[32];
    //sprintf( objectsee, "Object: %i", objectlook );
    
    
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
    
    
    //ScreenGoTo( 35, 1 );
    //ScreenWrite( objectsee );
    
    //ScreenGoTo( 64, 3 );
    //ScreenWrite( objectgrabed );
    
    
    
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

        PLAYER.lookxz -= float(point.x-400) * 360.0f * float( time ) / 16000.0f;
        PLAYER.looky -= float(point.y-300) * 360.0f * float( time ) / 16000.0f;
    SetCursorPos( 400, 300 );
    
        
    
		if(GetAsyncKeyState(0x25) & 0x8000) // LEFTARROW
		{
            PLAYER.lookxz += 360.0f * float( time ) / 2000.0f;
		}		
		if(GetAsyncKeyState(0x26) & 0x8000) // UPARROW
		{
            PLAYER.looky += 180.0f * float( time ) / 1000.0f;
		}
		if(GetAsyncKeyState(0x27) & 0x8000) // RIGHTARROW
		{
            PLAYER.lookxz -= 360.0f * float( time ) / 2000.0f;
		}
		if(GetAsyncKeyState(0x28) & 0x8000) // DOWNARROW
		{
            PLAYER.looky -= 360.0f * float( time ) / 1000.0f;
		}
		if( PLAYER.looky < -87.9f )
		{
            PLAYER.looky = -87.9f;
        }
		else if( PLAYER.looky > 87.9f )
		{
            PLAYER.looky = 87.9f;
        }
        
        frametimegraphic = clock();
    
}
















