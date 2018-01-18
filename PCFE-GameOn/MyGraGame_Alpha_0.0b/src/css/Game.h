


class Game
{
public:
	Engine engine;
	
	float SensitivityX;
	float SensitivityY;
	bool UseMouse;
	
	int MoveForward;
	int MoveBackward;
	int StrafeLeft;
	int StrafeRight;
	int Jump;
	int Crouch;
	int LookLeft;
	int LookUp;
	int LookRight;
	int LookDown;
	int PrimaryAttack;
	int SecondaryAttack;
	int Zoom;
	int Run;
	int Sneak;
	
	inline void ReadSettingsFile( char * src );
	
	inline int GameInit( int * argc, char ** argv );
	
	Game();
};


