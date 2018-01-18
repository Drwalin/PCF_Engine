


void GUIFunction( float FrameTime )
{
	if(GetAsyncKeyState(0x1B) & 0x8000) // esc
	{
		exit(0);
	}
	
	char possition[6][32];
	char speed[6][32];
	char FPS[2][64];
	char objectgrabed[32];
	char look[2][64];
	
	if( cool_down_physic_fps < clock() )
	{
		cout<< "\n" << frames_physic_loop;
		frames_physic_loop = 0;
		cool_down_physic_fps = clock() + 1000;
	}
	
	sprintf( possition[0], "X: %f", engine.map.staticobject[0].pos.vector[0] );
	sprintf( possition[1], "Y: %f", engine.map.staticobject[0].pos.vector[1] );
	sprintf( possition[2], "Z: %f", engine.map.staticobject[0].pos.vector[2] );
	sprintf( speed[0], "X: %f", engine.map.staticobject[0].vel.vector[0] );
	sprintf( speed[1], "Y: %f", engine.map.staticobject[0].vel.vector[1] );
	sprintf( speed[2], "Z: %f", engine.map.staticobject[0].vel.vector[2] );
	sprintf( look[0], "Y: %f", engine.map.staticobject[0].see[0] );
	sprintf( look[1], "Z: %f", engine.map.staticobject[0].see[1] );
//	sprintf( FPS[0], "Graphic FPS: %f", timefps[1] );
//	sprintf( FPS[1], "Physic FPS:  %f", timefps[2] );
    
    //cout<<look[0]<<" "<<look[1]<<"\n";
    
	glDepthFunc( GL_ALWAYS );
    ScreenClear();
    glLoadIdentity();
    
    
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
    ScreenWrite( look[0] );
    ScreenGoTo( 0, 6 );
    ScreenWrite( look[1] );
    
    
    
    ScreenDraw();
    
    glDisable( GL_BLEND );
    glDisable( GL_TEXTURE_2D );
    
    glLineWidth(1.0);
    
    	glBegin( GL_LINES );
        	glColor3f( 1.0f, 0.0f, 0.0f );
        		glVertex3f( -1.0f, 0.0f,  -40.0f );
        		glVertex3f( 1.0f,  0.0f,  -40.0f );
        		glVertex3f( 0.0f,  -1.0f, -40.0f );
        		glVertex3f( 0.0f,  1.0f,  -40.0f );
        glEnd();
    
    glEnable( GL_BLEND );
    glEnable( GL_TEXTURE_2D );
    
    
        
        
        
		POINT point;
		GetCursorPos( & point );

//        engine.map.staticobject[0].see[0] -= float(point.x-400) * 360.0f * FrameTime / 16.0f;
//        engine.map.staticobject[0].see[1] -= float(point.y-300) * 360.0f * FrameTime / 16.0f;
//    SetCursorPos( 400, 300 );
    
        
    
		if(GetAsyncKeyState(0x25) & 0x8000) // LEFTARROW
		{
            engine.map.staticobject[0].see[0] += 360.0f * FrameTime / 2.0f;
		}		
		if(GetAsyncKeyState(0x26) & 0x8000) // UPARROW
		{
            engine.map.staticobject[0].see[1] += 180.0f * FrameTime / 1.0f;
		}
		if(GetAsyncKeyState(0x27) & 0x8000) // RIGHTARROW
		{
            engine.map.staticobject[0].see[0] -= 360.0f * FrameTime / 2.0f;
		}
		if(GetAsyncKeyState(0x28) & 0x8000) // DOWNARROW
		{
            engine.map.staticobject[0].see[1] -= 360.0f * FrameTime / 1.0f;
		}
		if( engine.map.staticobject[0].see[1] < -89.9f )
		{
            engine.map.staticobject[0].see[1] = -89.9f;
        }
		else if( engine.map.staticobject[0].see[1] > 89.9f )
		{
            engine.map.staticobject[0].see[1] = 89.9f;
        }
}


