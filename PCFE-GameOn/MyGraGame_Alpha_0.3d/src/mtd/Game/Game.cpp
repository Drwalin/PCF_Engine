


inline void Game::AddItem()
{
	object.resize( object.size() + 1 );
	object.back() = new Object;
	object.back() -> item = NULL;
	engine.AddObject();
	object.back() -> object = engine.BackObject();
	engine.BackObject() -> SetGameLogicObject( (void*)object.back() );
}

inline void Game::AddPlayer()
{
	object.resize( object.size() + 1 );
	object.back() = new Object;
	object.back() -> player = new Player;
	object.back() -> player -> Init();
	engine.AddObject();
	object.back() -> object = engine.BackObject();
	object.back() -> player -> object = engine.BackObject();
	object.back() -> player -> parent = object.back();
	engine.BackObject() -> SetGameLogicObject( (void*)object.back() );
}

inline void Game::AddBot()
{
	object.resize( object.size() + 1 );
	object.back() = new Object;
	object.back() -> player = new Player;
	object.back() -> player -> Init();
	object.back() -> player -> ai = new AI;
	engine.AddObject();
	object.back() -> object = engine.BackObject();
	object.back() -> player -> object = engine.BackObject();
	object.back() -> player -> ai -> parent = object.back() -> player;
	object.back() -> player -> parent = object.back();
	engine.BackObject() -> SetGameLogicObject( (void*)object.back() );
}

inline void Game::ReadSettingsFile( char * src )
{
	ifstream file;
	file.open( src );
	if( file.good() )
	{
		char * command = new char[10024];
		
		while( !file.eof() )
		{
			file.getline( command, 10023 );
			SetCommand( command );
		}
		delete[] command;
	}
	file.close();
}

inline int Game::GameInit( int * argc, char ** argv )
{
	SensitivityX = 100;
	SensitivityY = 100;
	UseMouse = true;
	
	SetEngineInstantiation( &engine );
	
	InitKeyCodes( "cfg\\MSDNKey.ini" );
	
	MoveForward =		GetKeyCode( "BUTTON_W" );
	MoveBackward =		GetKeyCode( "BUTTON_S" );
	StrafeLeft =		GetKeyCode( "BUTTON_A" );
	StrafeRight =		GetKeyCode( "BUTTON_D" );
	Jump =				GetKeyCode( "SPACE" );
	Crouch =			GetKeyCode( "LEFT_CTRL" );
	LookLeft =			GetKeyCode( "LEFT_ARROW" );
	LookUp =			GetKeyCode( "UP_ARROW" );
	LookRight =			GetKeyCode( "RIGHT_ARROW" );
	LookDown =			GetKeyCode( "DOWN_ARROW" );
	PrimaryAttack =		GetKeyCode( "LEFT_MOUSE" );
	SecondaryAttack =	GetKeyCode( "RIGHT_MOUSE" );
	Zoom =				GetKeyCode( "MIDDLE_MOUSE" );
	Run =				GetKeyCode( "LEFT_SHIFT" );
	Sneak =				GetKeyCode( "LEFT_ALT" );
	Reload =			GetKeyCode( "BUTTON_R" );
	
	ReadSettingsFile( "cfg\\config.cfg" );
	ReadSettingsFile( "cfg\\controlls.cfg" );
	
	engine.Init( argc, argv );
	
	ReadSettingsFile( "cfg\\settings.cfg" );
}

Game::Game()
{
	fpsCooldown = 0;
	SensitivityX = 100;
	SensitivityY = 100;
	UseMouse = true;
}


