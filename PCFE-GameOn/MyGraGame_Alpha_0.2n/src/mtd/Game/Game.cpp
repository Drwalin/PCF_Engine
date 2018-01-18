


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
	object.back() -> player -> ai -> parent = object.back() -> player;
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

inline void Game::InitWeapons()
{
	weapon.resize( 4 );
	weapon[0].SetName( "Hands" );
	weapon[0].model = NULL;
	weapon[0].magazineCapacity = 0;
	weapon[0].ammoCapacity = 0;
	weapon[0].changeingCooldown = 0.3f;
	weapon[0].shootingCooldown = 0.5f;
	weapon[0].reloadingCooldown = 0.0f;
	weapon[0].recoilUp = 3.0f;
	weapon[0].recoilSide = 7.0f;
	weapon[0].moveWeaponInHand.Set( -0.2f, -0.2f, 0.5f );
	weapon[0].moveWeaponAfterShot.Set( 0.0f, 0.0f, 0.3f );
	weapon[0].rotateWeaponAfterShot.Set( 0.0f, 0.0f, 180.0f );
	weapon[1].SetName( "Crowbar" );
	weapon[1].model = NULL;
	weapon[1].magazineCapacity = 0;
	weapon[1].ammoCapacity = 0;
	weapon[1].changeingCooldown = 0.3f;
	weapon[1].shootingCooldown = 1.0f;
	weapon[1].reloadingCooldown = 0.0f;
	weapon[1].recoilUp = 7.0f;
	weapon[1].recoilSide = 14.0f;
	weapon[1].moveWeaponInHand.Set( -0.2f, -0.2f, 0.5f );
	weapon[1].moveWeaponAfterShot.Set( 0.0f, 0.0f, 0.5f );
	weapon[1].rotateWeaponAfterShot.Set( 45.0f, 0.0f, 0.0f );
	weapon[2].SetName( "Glock 311" );
	weapon[2].model = engine.GetStaticModelHandle( "Glock311" );
	weapon[2].magazineCapacity = 18;
	weapon[2].ammoCapacity = 180;
	weapon[2].changeingCooldown = 0.3f;
	weapon[2].shootingCooldown = 0.3f;
	weapon[2].reloadingCooldown = 0.4f;
	weapon[2].recoilUp = 20.0f;
	weapon[2].recoilSide = 9.0f;
	weapon[2].moveWeaponInHand.Set( -0.18f, -0.17f, 0.311f );
	weapon[2].moveWeaponAfterShot.Set( 0.0f, 0.07f, -0.1f );
	weapon[2].rotateWeaponAfterShot.Set( 45.0f, 0.0f, 0.0f );
	weapon[2].SetShotSound( "shot_glock17" );
	weapon[2].SetReloadSound( "reload_glock17" );
	weapon[3].SetName( "SMG m45" );
	weapon[3].model = engine.GetStaticModelHandle( "SMG_m45" );
	weapon[3].magazineCapacity = 45;
	weapon[3].ammoCapacity = 225;
	weapon[3].changeingCooldown = 0.3f;
	weapon[3].shootingCooldown = 0.066f;
	weapon[3].reloadingCooldown = 0.7f;
	weapon[3].recoilUp = 9.0f;
	weapon[3].recoilSide = 4.0f;
	weapon[3].moveWeaponInHand.Set( -0.2f, -0.2f, 0.5f );
	weapon[3].moveWeaponAfterShot.Set( 0.0f, 0.0f, -0.113f );
	weapon[3].rotateWeaponAfterShot.Set( -3.0f, 0.0f, 0.0f );
	weapon[3].SetShotSound( "shot_m4a1" );
	weapon[3].SetReloadSound( "reload_m4a1" );
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


