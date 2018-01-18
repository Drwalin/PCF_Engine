


class Game
{
public:
	
	float SensitivityX;
	float SensitivityY;
	bool UseMouse;
	
	Engine engine;
	
	Command console;
	
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
	
	
	inline void ReadSettings( char * src );
	
	GameInit();
	
	Game();
};


