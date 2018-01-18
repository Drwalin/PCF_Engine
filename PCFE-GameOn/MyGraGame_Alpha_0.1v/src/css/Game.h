
#ifndef GAME_H
#define GAME_H

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
	
	int fpsCooldown;
	int fpsCount;
	int fps;
		
	Weapon * weapon;
	ItemListed * item;
	
	vector < Object * > object;
	
	inline void AddItem();
	inline void AddPlayer();
	inline void AddBot();
	inline void AddBullet();
	
	inline void Update( float time );
	inline void Renderer( float time );
	
	inline void LoadModels( char * src );
	inline void LoadTextures( char * src );
	
	inline void ReadSettingsFile( char * src );
	
	inline int GameInit( int * argc, char ** argv );
	
	inline int LoadObjAsPhysic( char * src );
	
	inline int LoadMap( char * srcFile );
	
	Game();
	~Game(){}////////////////////////////////////
};

#endif
