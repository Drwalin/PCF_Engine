

Engine::Engine()
{
    sprintf( WindowName, "Engine" );
    WindowPossition [0] = 0;
    WindowPossition [1] = 0;
    WindowSize      [0] = 640;
    WindowSize      [1] = 480;
    WindowFullScreen = FALSE;
    
    GraphicFPS[0] = 0;
    GraphicFPS[1] = 0;
    GraphicFPS[2] = 0;
    PhysicFPS[0] = 0;
    PhysicFPS[1] = 0;
    PhysicFPS[2] = 0;
    
    GraphicThreadStopped    = false;    // if graphic thread are stopped
    PhysicThreadStopped     = false;    // if physic thread are stopped
    AskingPause             = false;    // something asking about pause working engine
    AskingEnd               = false;    // something asking about stop working engine
    OrderContinue           = false;    // one of the threads can order that, to extort continue work
    
//    GraphicMode = CMT_GRAPHIC_MODE_OPENGL;            // OpenGL / DirectX      (implicitly OpenGL mode (only yet))
    
//    MEMORYSavingMode = CMT_MEMORY_MAXIMUM_USAGE;       // Maximum nuber of maps (implicitly maximmum mode)
//    CPUSavingMode    = CMT_CPU_MAXIMUM_USAGE;          // Collision precision   (implicitly maximmum mode)
//    GPUSavingMode    = CMT_GPU_MAXIMUM_USAGE;          // Graphic library mode  (implicitly maximmum mode)
    
    GraphicMode = 1;            // OpenGL / DirectX      (implicitly OpenGL mode (only yet))
    
    //MEMORYSavingMode = 1;       	// Maximum nuber of maps (implicitly maximmum mode)
    //CPUSavingMode    = 1;          	// Collision precision   (implicitly maximmum mode)
    //GPUSavingMode    = 1;         	// Graphic library mode  (implicitly maximmum mode)
    
    GraphicTime = 0.0f;
    BeginGraphicTime = 0;
    
    KeyboardFunction = NULL;
    GUIFunction = NULL;
    
    MaximumNumberOfObjects = 500;
    MaximumNumberOfPhysicsThreads = 50;
    ThreadsInfo = NULL;
}

Engine::~Engine()
{
    WindowName[0] = 0;
    WindowPossition [0] = 0;
    WindowPossition [1] = 0;
    WindowSize      [0] = 640;
    WindowSize      [1] = 480;
    WindowFullScreen = FALSE;
    
    GraphicFPS[0] = 0;
    GraphicFPS[1] = 0;
    GraphicFPS[2] = 0;
    PhysicFPS[0] = 0;
    PhysicFPS[1] = 0;
    PhysicFPS[2] = 0;
    
    GraphicThreadStopped    = FALSE;    // if graphic thread are stopped
    PhysicThreadStopped     = FALSE;    // if physic thread are stopped
    AskingPause             = FALSE;    // something asking about pause working engine
    AskingEnd               = FALSE;    // something asking about stop working engine
    OrderContinue           = FALSE;    // one of the threads can order that, to extort continue work
    
    GraphicMode = 0;
    
    //GraphicMode = CMT_GRAPHIC_MODE_OPENGL;            // OpenGL / DirectX      (implicitly OpenGL mode (only yet))
    
    //MEMORYSavingMode = CMT_MEMORY_MAXIMUM_USAGE;       // Maximum nuber of maps (implicitly maximmum mode)
    //CPUSavingMode    = CMT_CPU_MAXIMUM_USAGE;          // Collision precision   (implicitly maximmum mode)
    //GPUSavingMode    = CMT_GPU_MAXIMUM_USAGE;          // Graphic library mode  (implicitly maximmum mode)
    
    
    
    KeyboardFunction = NULL;
    GUIFunction = NULL;
    
    MaximumNumberOfObjects = 0;
    MaximumNumberOfPhysicsThreads = 0;
    if( ThreadsInfo != NULL )
    {
		delete[] ThreadsInfo;
	}
}


inline void Engine::Init( int * argc, char **argv )
{
    srand(time(NULL));
    
    //al_init();
    //al_init_acodec_addon();
    //al_install_audio();
    
    glutInit( argc, argv );
    
	glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
	glutInitWindowSize( WindowSize[0], WindowSize[1] );
	glutInitWindowPosition( WindowPossition[0], WindowPossition[1] );
    glutCreateWindow( WindowName );
    
    glEnable( GL_DEPTH_TEST );
    
	glDepthMask( GL_TRUE );
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
    glEnable( GL_TEXTURE_2D );
	
    if( WindowFullScreen == true ){
        glutFullScreen();
    }
    
    /*
        There load textures, models and sounds
    */
    ScreenLoadTextures();
    
	
	glLineWidth( 10.0f );
	
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	
	glEnable( GL_DEPTH );
	
    glutReshapeFunc( Reshape__ );
    glutDisplayFunc ( Renderer__ );
    glutTimerFunc ( 15, FrameFunction__, 0 );
}





void Engine::Reshape( int width, int height )
{
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glViewport( 0, 0, (GLsizei)width, (GLsizei)height );
    GLint f = (GLint)width / (GLint)height;
    gluPerspective( 60.0f, 16.0f/9.0f, 0.01f, 1000000.0f );
}




void Engine::Renderer()
{
	// calculate frame time & fps
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
	
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
	
	while( clock() - BeginGraphicTime < 15 )
    {
        Delay( 1 );
    }
}

void Engine::CollisionLoop( int id )
{
	(*(ThreadsInfo+id)) = PXTHREAD_CLEAR;
	printf( "\nThread %i begin works.", id );
	while( true )
	{
		while( ( (*(ThreadsInfo+id)) & PXTHREAD_INWORK ) != PXTHREAD_INWORK ){ Delay( 1 ); }	// wait while calculate not start
		
		map.UpdateObjectsCollisions( FrameTime, (id*MaximumNumberOfObjects/MaximumNumberOfPhysicsThreads), ((id+1)*MaximumNumberOfObjects/MaximumNumberOfPhysicsThreads) );
		
		if( ( (*(ThreadsInfo+id)) & PXTHREAD_INWORK ) == PXTHREAD_INWORK )
			(*(ThreadsInfo+id)) -= PXTHREAD_INWORK;
	}
}

void Engine::PhisicLoop()
{
	int i;
    FrameTime = 0.0f;
    unsigned int BegginTime = 0;
    unsigned int EndTime = 0;
    
    map.UpdateTerrainColliders();
    
	for( i = 0; i < MaximumNumberOfPhysicsThreads; i++ )
	{
		(*(ThreadsInfo+i)) = PXTHREAD_CLEAR;
	}
    
    while( 1 )
    {
		frames_physic_loop++;
        FrameTime = BegginTime - clock();
        BegginTime = clock();
        if( FrameTime < 1 )
            FrameTime = 1;
        else if( FrameTime >= 20 )
            FrameTime = 20;
        
        FrameTime = FrameTime / 1000.0f;
        
        FrameTime *= GlobalPhisicTimeScale;
        
        map.UpdateForces( FrameTime );
        
        KeyboardFunction( FrameTime );
        
		for( i = 0; i < MaximumNumberOfPhysicsThreads; i++ )
		{
			(*(ThreadsInfo+i)) = PXTHREAD_INWORK;
		}
		
		while( true )
		{
			for( i = 0; i < MaximumNumberOfPhysicsThreads; i++ )
			{
				if( ( (*(ThreadsInfo+i)) & PXTHREAD_INWORK ) == PXTHREAD_INWORK )
					break;
			}
			if( i >= MaximumNumberOfPhysicsThreads )
				break;
			Delay( 1 );
		}
		
        
        while( clock() < BegginTime + 10 )
        {
            Delay( 1 ); // microsecconds delay
        }
	}
}




inline int Engine::AddGraphicModel( char * name )
{
	GraphicModels.resize( GraphicModels.size() + 1 );
	GraphicModels[ GraphicModels.size() - 1 ].LoadModel( name );
}



void Engine::FrameFunction( int arg )
{
    Renderer();
    Reshape( glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT) );
    glutTimerFunc ( 15, FrameFunction__, 0);
    glutPostRedisplay();
}

void Engine::BeginLoop()
{
	int i;
	
	ThreadsInfo = new unsigned char[MaximumNumberOfPhysicsThreads];
	int *tab = new int[MaximumNumberOfPhysicsThreads];
	
	for( i = 0; i < MaximumNumberOfPhysicsThreads; i++ )
	{
		(*(tab+i)) = i;
		_beginthread( PhisicObjectCollision__, 0, (void*)(tab+i) );
	}
	
	_beginthread( PhisicLoop__, 0, NULL );
	
	glutMainLoop();
}



