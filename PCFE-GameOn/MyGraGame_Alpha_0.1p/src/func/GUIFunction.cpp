


int cool_down_graphic_fps = 0;
int frames_graphic_loop = 0;

void GUIFunction( float FrameTime )
{
	if(GetAsyncKeyState(0x1B) & 0x8000) // esc
	{
		exit(0);
	}
	
	{
		TrianglePX * triangle;
		PhysicModelStatic * object;
		VMatrix matrix;
		
		GameInstance->engine.Object(1)->see[0] += 0.1f;
		
		matrix.InitEmpty();
		matrix.RotateY( (GameInstance->engine.Object(1)->see[0]+90.0f) );
		matrix.RotateX( -(GameInstance->engine.Object(1)->see[1]) );
		GameInstance->engine.SegmentCollision(
							GameInstance->engine.Object(1)->GetEyePos(),
							GameInstance->engine.Object(1)->GetEyePos() + matrix.GetVertex( SetVector( 0.0f, 0.0f, 300.0f ) ),
							&object, &triangle, GameInstance->engine.Object(1), SIGHT );
		glDepthFunc( GL_LESS );
		glLineWidth( 5.0f );
		glBegin( GL_LINES );
			glColor3f( 1.0f, 0.1f, 0.1f );
			glVertex3fv( &( GameInstance->engine.Object(1)->GetEyePos()[0] ) );
			glVertex3fv( &( ( GameInstance->engine.Object(1)->GetEyePos() + matrix.GetVertex( SetVector( 0.0f, 0.0f, 300.0f ) ) )[0] ) );
		glEnd();
		
		matrix.InitEmpty();
		matrix.RotateY( (GameInstance->engine.Object(0)->see[0]+90.0f) );
		matrix.RotateX( -(GameInstance->engine.Object(0)->see[1]) );
		GameInstance->engine.SegmentCollision(
							GameInstance->engine.Object(0)->GetEyePos(),
							GameInstance->engine.Object(0)->GetEyePos() + matrix.GetVertex( SetVector( 0.0f, 0.0f, 300.0f ) ),
							&object, &triangle, GameInstance->engine.Object(0), SIGHT );
		
		if( triangle != NULL )
		{
			glLineWidth( 45.0f );
			glColor3f( 1.0f, 0.2f, 0.2f );
			glBegin( GL_LINE_LOOP );
				glVertex3fv( &((triangle->vertex[0])[0]) );
				glVertex3fv( &((triangle->vertex[1])[0]) );
				glVertex3fv( &((triangle->vertex[2])[0]) );
			glEnd();
		}
	}
	
	
	
	
	// draw game translated meshes
	
	glLoadIdentity();
	
	GameInstance->engine.map.particles.AddParticle( SetVector(0.0f,-5.5f,0.0f), 0.5f, SetVector(0.0f,0.0f,0.0f), SetVector(0.0f,0.01f,0.0f), 1.8f, 0, 0, 0, 30, 30, 30, 20.0f, 5.0f, 1 );
	
	glDepthFunc( GL_ALWAYS );
	glAlphaFunc( GL_GEQUAL, 0.2 );
	
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
	
	sprintf( possition[0], "X: %f", GameInstance->engine.Object(0)->pos.vector[0] );
	sprintf( possition[1], "Y: %f", GameInstance->engine.Object(0)->pos.vector[1] );
	sprintf( possition[2], "Z: %f", GameInstance->engine.Object(0)->pos.vector[2] );
	sprintf( speed[0], "X: %f", GameInstance->engine.Object(0)->vel.vector[0] );
	sprintf( speed[1], "Y: %f", GameInstance->engine.Object(0)->vel.vector[1] );
	sprintf( speed[2], "Z: %f", GameInstance->engine.Object(0)->vel.vector[2] );
	sprintf( look[0], "Y look: %f", GameInstance->engine.Object(0)->see[0] );
	sprintf( look[1], "Z look: %f", GameInstance->engine.Object(0)->see[1] );
	sprintf( velocitylenght3D, "vel 3D: %f", GameInstance->engine.Object(0)->vel.Lenght() );
	sprintf( velocitylenght2D, "vel 2D: %f", SetVector( GameInstance->engine.Object(0)->vel[0], 0.0f, GameInstance->engine.Object(0)->vel[2] ).Lenght() );
	
	
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
	
	
	
	glEnable( GL_BLEND );
	glEnable( GL_TEXTURE_2D );
	
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
	
	if( GameInstance->UseMouse == true )
	{
		GameInstance->engine.Object(0)->see[0] -= float(point.x-(glutGet(GLUT_WINDOW_X)+(glutGet( GLUT_WINDOW_WIDTH ) / 2))) * GameInstance->SensitivityX / (1000.0f);
		GameInstance->engine.Object(0)->see[1] -= float(point.y-(glutGet(GLUT_WINDOW_Y)+(glutGet( GLUT_WINDOW_HEIGHT ) / 2))) * GameInstance->SensitivityY / (1000.0f);
		SetCursorPos( glutGet(GLUT_WINDOW_X)+(glutGet( GLUT_WINDOW_WIDTH ) / 2), glutGet(GLUT_WINDOW_Y)+(glutGet( GLUT_WINDOW_HEIGHT ) / 2) );
	}
	
	
	if(GetAsyncKeyState(GameInstance->LookLeft) & 0x8000)
	{
		GameInstance->engine.Object(0)->see[0] += 360.0f * FrameTime / 2.0f;
	}		
	if(GetAsyncKeyState(GameInstance->LookUp) & 0x8000)
	{
		GameInstance->engine.Object(0)->see[1] += 360.0f * FrameTime / 2.0f;
	}
	if(GetAsyncKeyState(GameInstance->LookRight) & 0x8000)
	{
		GameInstance->engine.Object(0)->see[0] -= 360.0f * FrameTime / 2.0f;
	}
	if(GetAsyncKeyState(GameInstance->LookDown) & 0x8000)
	{
		GameInstance->engine.Object(0)->see[1] -= 360.0f * FrameTime / 2.0f;
	}
	
	if( GameInstance->engine.Object(0)->see[1] < -89.9f )
	{
		GameInstance->engine.Object(0)->see[1] = -89.9f;
	}
	else if( GameInstance->engine.Object(0)->see[1] > 89.9f )
	{
		GameInstance->engine.Object(0)->see[1] = 89.9f;
	}
	
	VMatrix matrix;
	matrix.InitEmpty();
	matrix.RotateY( (GameInstance->engine.Object(0)->see[0]+90.0f) );
	matrix.RotateX( -GameInstance->engine.Object(0)->see[1] );
	Vector forward;
	forward.Set( 0.0f, 0.0f, 1.0f );
	
	if( keyboardobiect.keypressed[GameInstance->PrimaryAttack] )
	{
		GameInstance->engine.map.particles.AddParticle(  GameInstance->engine.Object(0)->GetEyePos(),
		0.05f, GameInstance->engine.Object(0)->vel + (matrix.GetVertex(forward) * 1.7f), SetVector(0.0f,0.1f,0.0f), 1.0f, 255, 60, 0, 1, 255, 1, 3.0f, 2.0f, 30 );
	}
	if( keyboardobiect.keypressed[GameInstance->SecondaryAttack] )
	{
		GameInstance->engine.AddLightning(
					GameInstance->engine.Object(0)->GetEyePos(),
					GameInstance->engine.Object(0)->GetEyePos() + ( matrix.GetVertex(forward) * ((float((rand()%10000)-5000)/100.0f)+70.0f) ),
					25.0f, 1.0f,
					0.4f, 0.4f, 1.0f,
					0.8f, 0.8f, 1.0f,
					10,
					0.5f,
					0.5f,
					0.5f,
					10.0f
					);
		AddLightings--;
	}
}


