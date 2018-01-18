


#include"ThreadsActions.cpp"

#include"GraphicModels.cpp"
#include"OpenGL.cpp"
#include"Sounds.cpp"
#include"Physics.cpp"

#include"Inputs.cpp"
#include"SettingUp.cpp"

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
	
	ScreenLoadTextures();
	
	glLineWidth( 10.0f );
	
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	
	glEnable( GL_DEPTH );
	
	glutReshapeFunc( Reshape__ );
	glutDisplayFunc ( Renderer__ );
	glutTimerFunc ( CWBMT_FRAMEINMS, FrameFunction__, 0 );
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




Engine::Engine()
{
	sprintf( WindowName, "Engine" );
	WindowPossition [0] = 0;
	WindowPossition [1] = 0;
	WindowSize	  [0] = 1074;
	WindowSize	  [1] = 604;
	WindowFullScreen = FALSE;
	
	GraphicFPS[0] = 0;
	GraphicFPS[1] = 0;
	GraphicFPS[2] = 0;
	PhysicFPS[0] = 0;
	PhysicFPS[1] = 0;
	PhysicFPS[2] = 0;
	
	HideMouse = false;
	
	GraphicThreadStopped	= false;	// if graphic thread are stopped
	PhysicThreadStopped		= false;	// if physic thread are stopped
	AskingPause				= false;	// something asking about pause working engine
	AskingEnd				= false;	// something asking about stop working engine
	OrderContinue			= false;	// one of the threads can order that, to extort continue work
	
	GraphicTime = 0.0f;
	BeginGraphicTime = 0;
	
	KeyboardFunction = NULL;
	GUIFunction = NULL;
	
	MaximumNumberOfPhysicsThreads = 10;
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
	WindowSize	  [0] = 640;
	WindowSize	  [1] = 480;
	WindowFullScreen = FALSE;
	
	GraphicFPS[0] = 0;
	GraphicFPS[1] = 0;
	GraphicFPS[2] = 0;
	PhysicFPS[0] = 0;
	PhysicFPS[1] = 0;
	PhysicFPS[2] = 0;
	
	GraphicThreadStopped	= FALSE;	// if graphic thread are stopped
	PhysicThreadStopped		= FALSE;	// if physic thread are stopped
	AskingPause				= FALSE;	// something asking about pause working engine
	AskingEnd				= FALSE;	// something asking about stop working engine
	OrderContinue			= FALSE;	// one of the threads can order that, to extort continue work
	
	KeyboardFunction = NULL;
	GUIFunction = NULL;
	
	MaximumNumberOfObjects = 0;
	MaximumNumberOfPhysicsThreads = 0;
	if( ThreadsInfo != NULL )
	{
		delete[] ThreadsInfo;
	}
}


