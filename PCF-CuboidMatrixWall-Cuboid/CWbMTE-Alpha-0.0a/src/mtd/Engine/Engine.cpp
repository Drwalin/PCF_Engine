

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
    
    GraphicThreadStopped    = FALSE;    // if graphic thread are stopped
    PhysicThreadStopped     = FALSE;    // if physic thread are stopped
    AskingPause             = FALSE;    // something asking about pause working engine
    AskingEnd               = FALSE;    // something asking about stop working engine
    OrderContinue           = FALSE;    // one of the threads can order that, to extort continue work
    
    GraphicMode = CMT_GRAPHIC_MODE_OPENGL;            // OpenGL / DirectX      (implicitly OpenGL mode (only yet))
    
    MEMORYSavingMode = CMT_MEMORY_MAXIMUM_USAGE;       // Maximum nuber of maps (implicitly maximmum mode)
    CPUSavingMode    = CMT_CPU_MAXIMUM_USAGE;          // Collision precision   (implicitly maximmum mode)
    GPUSavingMode    = CMT_GPU_MAXIMUM_USAGE;          // Graphic library mode  (implicitly maximmum mode)
    
    ActuallyMapUsing = 0;       // Iterator / Id to actually map, which are in used
    
    CameraObject = 1;
    
    textures.resize( 0 );
    models.resize( 0 );
    map.resize( 0 );

    
    
    KeyboardFunction = NULL;
    GUIFunction = NULL;
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
    
    GraphicMode = CMT_GRAPHIC_MODE_OPENGL;            // OpenGL / DirectX      (implicitly OpenGL mode (only yet))
    
    MEMORYSavingMode = CMT_MEMORY_MAXIMUM_USAGE;       // Maximum nuber of maps (implicitly maximmum mode)
    CPUSavingMode    = CMT_CPU_MAXIMUM_USAGE;          // Collision precision   (implicitly maximmum mode)
    GPUSavingMode    = CMT_GPU_MAXIMUM_USAGE;          // Graphic library mode  (implicitly maximmum mode)
    
    ActuallyMapUsing = 0;       // Iterator / Id to actually map, which are in used
    
    CameraObject = 1;
    
    textures.resize( 0 );
    models.resize( 0 );
    map.resize( 0 );

    
    
    KeyboardFunction = NULL;
    GUIFunction = NULL;
}


inline void Engine::Init( int * argc, char *argv[] )
{
    srand(time(NULL));
    
    al_init();
    al_init_acodec_addon();
    al_install_audio();
    
    glutInit( argc, argv );
    
	glutInitDisplayMode( GLUT_RGBA );
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
    
    glLineWidth( 1.0 );
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
    glEnable( GL_DEPTH );
    glEnable( GL_AUTO_NORMAL );
    glEnable( GL_BLEND );
    glDepthMask (GL_TRUE );
    
    /*
        There load textures, models and sounds
    */
    
    
    
    glutReshapeFunc( Reshape );
    glutDisplayFunc ( Renderer );
    glutTimerFunc ( 10, FrameFunction, 0 );
}





void Engine::Reshape( int width, int height )
{
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glViewport( 0, 0, (GLsizei)width, (GLsizei)height );
    GLint f=(GLint)w/(GLint)h;
    gluPerspective( 60.0f, float(width)/float(height), 0.01f, 100000000000.0f );
}




inline void Engine::Renderer()
{
    // calculate frame time & fps
    
    
    
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glClearColor( 0.5f, 0.6f, 1.0f, 1.0f );
    glColorMask( GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE );
	glLoadIdentity();
	glColor3f( 1.0f, 1.0f, 1.0f );
	
	map[ ActuallyMapUsing ].Draw();
	
	GUIFunction( 
	
	glFlush();
	glutSwapBuffers();
}


inline __cdecl void Engine::PhisicLoop()
{
    while( 1 )
    {
        map[ ActuallyMapUsing ].UpdateForces( FrameTime );
        
        KeyboardFunction( FrameTime );
        
        map[ ActuallyMapUsing ].UpdateObjects( FrameTime );
        map[ ActuallyMapUsing ].UpdateColliders();
    }
    _endthread();
}


inline void Engine::FrameFunction( int arg )
{
    Renderer();
    Reshape( glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT) );
    glutTimerFunc ( 10, Bez_Zegara, 0);
    glutPostRedisplay();
}

#include"Engine.Set.cpp"
#include"Engine.Add.cpp"
#include"Engine.Get.cpp"
#include"Engine.Do.cpp"
#include"Engine.LineCollision.cpp"




