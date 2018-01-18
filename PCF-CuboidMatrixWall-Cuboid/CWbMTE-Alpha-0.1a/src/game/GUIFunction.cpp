
int cool_down_graphic_fps = 0;
int frames_graphic_loop = 0;

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
	char velocitylenght3D[64];
	char velocitylenght2D[64];
	
	if( cool_down_physic_fps < clock() )
	{
		cout<< "\n Physic fps:" << frames_physic_loop;
		frames_physic_loop = 0;
		cool_down_physic_fps = clock() + 1000;
	}
	
	frames_graphic_loop++;
	if( cool_down_graphic_fps < clock() )
	{
		cout<< "\n Graphic fps:" << frames_graphic_loop;
		frames_graphic_loop = 0;
		cool_down_graphic_fps = clock() + 1000;
	}
	
	
	
	sprintf( possition[0], "X: %f", engineInstantiation->map.staticobject[0].pos.vector[0] );
	sprintf( possition[1], "Y: %f", engineInstantiation->map.staticobject[0].pos.vector[1] );
	sprintf( possition[2], "Z: %f", engineInstantiation->map.staticobject[0].pos.vector[2] );
	sprintf( speed[0], "X: %f", engineInstantiation->map.staticobject[0].vel.vector[0] );
	sprintf( speed[1], "Y: %f", engineInstantiation->map.staticobject[0].vel.vector[1] );
	sprintf( speed[2], "Z: %f", engineInstantiation->map.staticobject[0].vel.vector[2] );
	sprintf( look[0], "Y look: %f", engineInstantiation->map.staticobject[0].see[0] );
	sprintf( look[1], "Z look: %f", engineInstantiation->map.staticobject[0].see[1] );
	sprintf( velocitylenght3D, "vel 3D: %f", engineInstantiation->map.staticobject[0].vel.Lenght() );
	sprintf( velocitylenght2D, "vel 2D: %f", SetVector( engineInstantiation->map.staticobject[0].vel[0], 0.0f, engineInstantiation->map.staticobject[0].vel[2] ).Lenght() );
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
    
    ScreenGoTo( 0, 12 );
    ScreenWrite( velocitylenght3D );
    ScreenGoTo( 0, 13 );
    ScreenWrite( velocitylenght2D );
    
    
    
    
    ScreenDraw();
    
    glDisable( GL_BLEND );
    glDisable( GL_TEXTURE_2D );
    
    
    
	PhysicModelStatic * object;
	TrianglePX * triangle;
	
	VMatrix matrix;
	matrix.InitEmpty();
	matrix.RotateX( (engineInstantiation->map.staticobject[0].see[1]) );
	matrix.RotateY( -(engineInstantiation->map.staticobject[0].see[0]-90.0f) );
	engineInstantiation->SegmentCollision(
						engineInstantiation->map.staticobject[0].pos+(engineInstantiation->map.staticobject[0].aabb[0].size*SetVector(0.5f,0.9f,0.5f)),
						engineInstantiation->map.staticobject[0].pos+(engineInstantiation->map.staticobject[0].aabb[0].size*SetVector(0.5f,0.9f,0.5f)) + matrix.GetVertex( SetVector( 0.0f, 1.0f, 1000.0f ) ),
						&object, &triangle );
	
	if( triangle != NULL )
	{
		glLineWidth( 3.0f );
		glBegin( GL_LINES );
			glColor3f( 1.0f, 0.3f, 0.3f );
			glVertex3fv( &((triangle->vertex[0])[0]) );
			glVertex3fv( &((triangle->vertex[0]+(triangle->normal*3.0f))[0]) );
			glVertex3fv( &((triangle->vertex[1])[0]) );
			glVertex3fv( &((triangle->vertex[1]+(triangle->normal*3.0f))[0]) );
			glVertex3fv( &((triangle->vertex[2])[0]) );
			glVertex3fv( &((triangle->vertex[2]+(triangle->normal*3.0f))[0]) );
			glVertex3fv( &((engineInstantiation->map.staticobject[0].pos+(engineInstantiation->map.staticobject[0].aabb[0].size*SetVector(0.5f,0.9f,0.5f)) + matrix.GetVertex( SetVector( 0.0f, 1.0f, 1000.0f ) ))[0]) );
			glVertex3fv( &((engineInstantiation->map.staticobject[0].pos+(engineInstantiation->map.staticobject[0].aabb[0].size*SetVector(0.5f,0.5f,0.5f)) + matrix.GetVertex( SetVector( 0.0f, 1.0f, 1000.0f ) ))[0]) );
		glEnd();
	}
	
	
	
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
		
		if( GameInstantiation->UseMouse == true )
		{
			engineInstantiation->map.staticobject[0].see[0] -= float(point.x-400) * 360.0f * FrameTime * GameInstantiation->SensitivityX / (16.0f*1000.0f);
			engineInstantiation->map.staticobject[0].see[1] -= float(point.y-300) * 360.0f * FrameTime * GameInstantiation->SensitivityX / (16.0f*1000.0f);
			SetCursorPos( 400, 300 );
		}
    	
        
		if(GetAsyncKeyState(GameInstantiation->LookLeft) & 0x8000)
		{
            engineInstantiation->map.staticobject[0].see[0] += 360.0f * FrameTime / 2.0f;
		}		
		if(GetAsyncKeyState(GameInstantiation->LookUp) & 0x8000)
		{
            engineInstantiation->map.staticobject[0].see[1] += 180.0f * FrameTime / 1.0f;
		}
		if(GetAsyncKeyState(GameInstantiation->LookRight) & 0x8000)
		{
            engineInstantiation->map.staticobject[0].see[0] -= 360.0f * FrameTime / 2.0f;
		}
		if(GetAsyncKeyState(GameInstantiation->LookDown) & 0x8000)
		{
            engineInstantiation->map.staticobject[0].see[1] -= 360.0f * FrameTime / 1.0f;
		}
		
		if( engineInstantiation->map.staticobject[0].see[1] < -89.9f )
		{
            engineInstantiation->map.staticobject[0].see[1] = -89.9f;
        }
		else if( engineInstantiation->map.staticobject[0].see[1] > 89.9f )
		{
            engineInstantiation->map.staticobject[0].see[1] = 89.9f;
        }
}


