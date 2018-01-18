


inline void Game::Update( float time )
{
	keyboardobiect.Update();
	
	if(GetAsyncKeyState(0x1B) & 0x8000) // esc
	{
		exit(0);
	}
	
	int i;
	for( i = 0; i < object.size(); ++i )
	{
		object[i] -> Update( time );
	}
}

inline void Game::Renderer( float time )
{
	{
		TrianglePX * triangle;
		PhysicModelStatic * object;
		VMatrix matrix;
		
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
	
	/*
	
	Begin of drawing game translated meshes
	
	*/
	
	/*
	
	 End of drawing game translated meshes
	
	*/
	
	GameInstance->engine.map.particles.AddParticle( SetVector(0.0f,-5.5f,0.0f), 0.5f, SetVector(0.0f,0.0f,0.0f), SetVector(0.0f,0.01f,0.0f), 1.8f, 0, 0, 0, 30, 30, 30, 20.0f, 5.0f, 1 );
	
	fpsCount++;
	if( fpsCooldown < clock() )
	{
		fps = fpsCount;
		fpsCount = 0;
		fpsCooldown = clock() + 1000;
	}
	
	char velocitylenght2D[64];
	char FPS[64];
	sprintf( FPS, "fps: %i", fps );
	sprintf( velocitylenght2D, "Velocity 2D: %f", SetVector( GameInstance->engine.Object(0)->vel[0], 0.0f, GameInstance->engine.Object(0)->vel[2] ).Lenght() );
	
	glLoadIdentity();
	glDepthFunc( GL_ALWAYS );
	glAlphaFunc( GL_GEQUAL, 0.1 );
	glEnable( GL_BLEND );
	glEnable( GL_TEXTURE_2D );
	
	ScreenClear();
	
	ScreenGoTo( 1, 1 );
	ScreenWrite( FPS );
	ScreenGoTo( 1, 3 );
	ScreenWrite( velocitylenght2D );
	
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
}


