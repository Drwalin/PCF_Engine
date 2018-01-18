


inline int Game::GameInit( char * src )
{
	SensitivityX = 100;
	SensitivityY = 100;
	UseMouse = true;
	
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
	
	ifstream file;
	file.open( src );
	char * fast = new char[2048];
	while( !file.eof() )
	{
		file.getline( fast, 2047 );
		//console.SetCommand( fast );
		console.Set( fast );
	}
	
	
}

Game::Game()
{
	SensitivityX = 100;
	SensitivityY = 100;
	UseMouse = true;
}


