

Engine::Engine()
{
    sprintf( WindowName, "Engine" );
    WindowPossition [0] = 0;
    WindowPossition [1] = 1000;
    WindowSize      [0] = 1074;
    WindowSize      [1] = 604;
    WindowFullScreen = FALSE;
    
    GraphicFPS[0] = 0;
    GraphicFPS[1] = 0;
    GraphicFPS[2] = 0;
    PhysicFPS[0] = 0;
    PhysicFPS[1] = 0;
    PhysicFPS[2] = 0;
    
    HideMouse = false;
    
    GraphicThreadStopped    = false;    // if graphic thread are stopped
    PhysicThreadStopped     = false;    // if physic thread are stopped
    AskingPause             = false;    // something asking about pause working engine
    AskingEnd               = false;    // something asking about stop working engine
    OrderContinue           = false;    // one of the threads can order that, to extort continue work
    
    GraphicMode = 1;            // OpenGL / DirectX      (implicitly OpenGL mode (only yet))
    
    GraphicTime = 0.0f;
    BeginGraphicTime = 0;
    
    KeyboardFunction = NULL;
    GUIFunction = NULL;
    
    MaximumNumberOfPhysicsThreads = 50;
    ThreadsInfo = NULL;
}

Engine::~Engine()
{
	if( soundEngineInstantiation != NULL )
	{
		soundEngineInstantiation -> DeInit();
		delete[] soundEngineInstantiation;
	}
	
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
    soundEngineInstantiation = new SoundEngine;
    soundEngineInstantiation -> Init();
    
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
    glutTimerFunc ( CWBMT_FRAMEINMS, FrameFunction__, 0 );
}





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
//	glPopMatrix();
	glFlush();
	glutSwapBuffers();
	
	while( clock() - BeginGraphicTime < 17 )
    {
        Delay( 1 );
    }
}


inline int Engine::SegmentCollision( Vector p1, Vector p2, PhysicModelStatic ** object, TrianglePX ** triangle, PhysicModelStatic * decludingobject )
{
	return map.SegmentCollision( p1, p2, object, triangle, decludingobject );
}


void Engine::CollisionLoop( int id )
{
	(*(ThreadsInfo+id)) = PXTHREAD_CLEAR;
	printf( "\nThread %i begin works.", id );
	while( true )
	{
		while( ( (*(ThreadsInfo+id)) & PXTHREAD_INWORK ) != PXTHREAD_INWORK ){ Delay( 0 ); }	// wait while calculate not start
		
		map.UpdateObjectsCollisions( FrameTime, (id*map.staticobject.size()/MaximumNumberOfPhysicsThreads), ((id+1)*map.staticobject.size()/MaximumNumberOfPhysicsThreads) );
		
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
        
        map.UpdateObjectColliders();
        
        for( i = 0; i < map.staticobject.size(); i++ )
        {
			map.staticobject[i].IdentityCollisions();
			if( map.staticobject[i].pos[0] < -248.0f )
				map.staticobject[i].pos[0] = -248.0f;
			if( map.staticobject[i].pos[2] < -248.0f )
				map.staticobject[i].pos[2] = -248.0f;
			if( map.staticobject[i].pos[0] > 248.0f )
				map.staticobject[i].pos[0] = 248.0f;
			if( map.staticobject[i].pos[2] > 248.0f )
				map.staticobject[i].pos[2] = 248.0f;
		}
        
        map.UpdateAllObjectsCollisions( FrameTime );
        
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
			Delay( 0 );
		}
		
        soundEngineInstantiation -> Update();
        
        while( clock() < BegginTime + 10 )
        {
            Delay( 0 ); // microsecconds delay
        }
	}
}




inline int Engine::AddGraphicModel( char * name, char * texture, int type )
{
	GraphicModels.resize( GraphicModels.size() + 1 );
	GraphicModels[ GraphicModels.size() - 1 ].Init( name, texture, type );
}



void Engine::FrameFunction( int arg )
{
    Renderer();
    Reshape( glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT) );
    glutTimerFunc ( CWBMT_FRAMEINMS, FrameFunction__, 0);
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
	delete[] tab;
}

inline StaticGraphicModel * Engine::GetStaticModelHandle( char * src )
{
	int i;
	for( i = 0; i < GraphicModels.size(); i++ )
	{
		if( !strcmp( src, GraphicModels[i].name ) )
		{
			return &(GraphicModels[i]);
		}
	}
	return NULL;
}

inline void Engine::AddSoundSource( char * src )
{
	soundEngineInstantiation -> AddSound( src );
}

inline void Engine::PlaySound( char * src )
{
	soundEngineInstantiation -> PlaySound( src );
}

inline void Engine::PlaySound( char * src, Vector origin )
{
	soundEngineInstantiation -> PlaySound( src, origin );
}


