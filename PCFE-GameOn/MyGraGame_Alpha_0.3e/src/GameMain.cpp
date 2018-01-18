


int main( int argc, char *argv[] )
{
	srand( time( NULL ) );
	
	ShowCursor( false );
	
	Game game;
	GameInstance = &game;
	game.GameInit( &argc, argv );
	
	game.engine.SetKeybordFunction( KeyboardFunction );
	game.engine.SetGUIFunction( GUIFunction );
	
	game.LoadTextures( "cfg\\Textures.ini" );
	game.LoadModels( "cfg\\Models.ini" );
	game.LoadSounds( "cfg\\Sounds.ini" );
	game.LoadWeapons( "cfg\\Weapons.ini" );
	
	game.engine.SetLightningLimit( 50 );
	
	game.engine.DestroyWorldInEngineThread();
	LoadMap();
	
//	float a, b, c, d;
//	cin >> a >> b >> c;
	
	game.engine.AddDynamicLightSource( SetVector( -100, -100, -100), SetVector( 1, 1, 1 ), 200.0f, 360.0f, 1.0f );
	game.engine.AddDynamicLightSource( SetVector( 0, 70, 0 ), SetVector( 1, 0, 0 ), 200.0f, 360.0f, 1.0f );
		
//	game.engine.PlaySound( 0.0f, "Path of The Borealis" );
	
//	game.engine.PlaySound( "Red Army Choir Katyusha", Vector( 0.0f, 2.0f, 0.0f ), 0.38f );
	game.engine.PlaySound( "Path of The Borealis", Vector( 0.0f, 1.0f, 0.0f ), 70.0f );
//	game.engine.PlaySound( "Morrowind Theme", Vector( 220.0f, 2.0f, -220.0f ), 0.08f );
//	game.engine.PlaySound( "Morrowind Theme", Vector( -220.0f, 2.0f, 220.0f ), 0.08f );
	
	_beginthread( GameThreadTestLoadingMap, 0, NULL );
	
	game.engine.map.DebugMode = false;
	
	game.engine.SetUseVBO();
	
	game.engine.BeginLoop();
	
	return 0;
}
