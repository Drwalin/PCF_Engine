


inline void Engine::DeleteVBOs()
{
	int i;
	
	for( i = 0; i < map.vbotex.size(); ++i )
	{
		map.vbotex[i].Delete();
		map.vbotex[i].vertices.resize( 0 );
		map.vbotex[i].indices.resize( 0 );
	}
	
	for( i = 0; i < map.vbocol.size(); ++i )
	{
		map.vbocol[i].Delete();
		map.vbocol[i].vertices.resize( 0 );
		map.vbocol[i].indices.resize( 0 );
	}
	
	for( i = 0; i < map.graphicMapModels.size(); ++i )
	{
		if( map.graphicMapModels[i] != NULL )
		{
			map.graphicMapModels[i] -> Delete();
			delete map.graphicMapModels[i];
		}
		map.graphicMapModels[i] = NULL;
	}
	
	map.vbotex.resize( 0 );
	map.vbocol.resize( 0 );
	map.graphicMapModels.resize( 0 );
}

void Engine::Reshape( int width, int height )
{
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glViewport( 0, 0, (GLsizei)width, (GLsizei)height );
    gluPerspective( 60.0f, float(width)/float(height), 0.1f, 1000.0f );
}

void Engine::Renderer()
{
	CheckEngineThreadsInfoRendererThread();
	
	PhysicIteration();
	
	GraphicTime = clock() - BeginGraphicTime;
	BeginGraphicTime = clock();
	
	CalculateDynamicLight();
	
	glEnable( GL_BLEND );
	
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 60.0f, 4.0f/3.0f, 0.1f, 1000.0f );
	
	glClearColor( 0.5f, 0.6f, 1.0f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glColorMask( GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	glEnable( GL_DEPTH_TEST );
	glEnable( GL_ALPHA_TEST );
	glAlphaFunc( GL_GEQUAL, 0.7 );
	glDepthMask( GL_TRUE );
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
	glColor3f( 1.0f, 1.0f, 1.0f );
	
	GraphicTime /= 1000.0f;
	
	map.Draw( GraphicTime );
	
	GUIFunction( GraphicTime );
	
	glFlush();
	
	glutSwapBuffers();
	
//	if( true )	// update dynamic light sources
	{
		int i;
		for( i = 1; i < map.lightSourcesDynamic.size(); ++i )
		{
			map.lightSourcesDynamic[i] -> UpdateDepthBuffer( &map );
		}
	}
}

void Engine::FrameFunction( int arg )
{
    Renderer();
    Reshape( glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT) );
    glutTimerFunc( CWBMT_FRAMEINMS, FrameFunction__, 0);
    glutPostRedisplay();
}


