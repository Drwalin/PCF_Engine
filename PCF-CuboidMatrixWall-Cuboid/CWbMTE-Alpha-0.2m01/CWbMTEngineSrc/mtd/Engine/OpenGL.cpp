


void Engine::Reshape( int width, int height )
{
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glViewport( 0, 0, (GLsizei)width, (GLsizei)height );
    GLint f = (GLint)width / (GLint)height;
    gluPerspective( 60.0f, float(width)/float(height), 0.01f, 100000.0f );
}


void Engine::Renderer()
{
	GraphicTime = clock() - BeginGraphicTime;
	BeginGraphicTime = clock();
	
	glEnable( GL_BLEND );
	
	glClearColor( 0.5f, 0.6f, 1.0f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glColorMask( GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	glEnable( GL_DEPTH_TEST );
	glDepthMask( GL_TRUE );
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
	glColor3f( 1.0f, 1.0f, 1.0f );
	
	map.Draw();
	
	GUIFunction( GraphicTime / 1000.0f );
	glFlush();
	glutSwapBuffers();
	
	while( clock() - BeginGraphicTime < 17 )
    {
        Delay( 0 );
    }
}

void Engine::FrameFunction( int arg )
{
    Renderer();
    Reshape( glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT) );
    glutTimerFunc ( CWBMT_FRAMEINMS, FrameFunction__, 0);
    glutPostRedisplay();
}


