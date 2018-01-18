


inline void Game::AddItem()
{
	object.resize( object.size() + 1 );
	object.back() = new Object;
	object.back() -> item = NULL;
	engine.AddObject();
	object.back() -> object = engine.BackObject();
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
}

inline void Game::AddBot()
{
	object.resize( object.size() + 1 );
	object.back() = new Object;
	object.back() -> player = new Player;
	object.back() -> player -> Init();
	engine.AddObject();
	object.back() -> object = engine.BackObject();
	object.back() -> player -> object = engine.BackObject();
	object.back() -> player -> ai = new AI;
}

inline void Game::AddBullet()
{
	object.resize( object.size() + 1 );
	object.back() = new Object;
	object.back() -> bullet = new Bullet;
}

inline void Game::LoadModels( char * src )
{
	ifstream file;
	file.open( src );
	if( !file.good() )
	{
		return;
	}
	else
	{
		char * data = new char[16000];
		char * fast1 = NULL;
		char * fast2 = NULL;
		int a,b,c;
		while( !file.eof() )
		{
			file.getline( data, 15999 );
			fast1 = GetStringBetweenCharacter( data, ' ', 0 );
			if( !strcmp( fast1, "Static:" ) )
			{
				if( fast1 != NULL )
					delete[] fast1;
				fast1 = NULL;
				
				a = GetIntFromString( data, 0 );
				b = GetIntFromString( data, 1 );
				c = GetIntFromString( data, 2 );
				fast1 = GetStringBetweenCharacter( data, '\"', 1 );	// path to model file
				fast2 = GetStringBetweenCharacter( data, '\"', 3 );	// texture name
				
				engine.AddGraphicModel( fast1, engine.TextureId( fast2 ), Vector( float(a)/100.0f, float(b)/100.0f, float(c)/100.0f ) );
				
				if( fast1 != NULL )
					delete[] fast1;
				fast1 = NULL;
				if( fast2 != NULL )
					delete[] fast2;
				fast2 = NULL;
			}
			else
			{
				if( fast1 != NULL )
					delete[] fast1;
				fast1 = NULL;
			}
		}
		delete[] data;
		file.close();
	}
}

inline void Game::LoadTextures( char * src )
{
	ifstream file;
	file.open( src );
	if( !file.good() )
	{
		return;
	}
	else
	{
		char * data = new char[16000];
		char * fast1 = NULL;
		char * fast2 = NULL;
		while( !file.eof() )
		{
			file.getline( data, 15999 );
			
			fast1 = GetStringBetweenCharacter( data, ' ', 0 );	// Linear  or Neares draw mode
			fast2 = GetStringBetweenCharacter( data, '\"', 1 );	// path to texture file
			
			if( !strcmp( fast1, "Linear:" ) )
			{
				engine.AddTexture( fast2, GL_LINEAR );
			}
			else
			{
				engine.AddTexture( fast2, GL_NEAREST );
			}
			
			if( fast1 != NULL )
//				delete[] fast1;
			fast1 = NULL;
			if( fast2 != NULL )
//				delete[] fast2;
			fast2 = NULL;
		}
		delete[] data;
		file.close();
	}
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


