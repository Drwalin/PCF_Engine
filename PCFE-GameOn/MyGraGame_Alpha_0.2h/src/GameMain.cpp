


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
//	game.LoadSounds( "cfg\\Sounds.ini" );
	game.engine.AddSoundSource( "..\\Media\\Sounds\\Music\\reload_glock17.mp3" );
	game.engine.AddSoundSource( "..\\Media\\Sounds\\Music\\reload_m4a1.mp3" );
	game.engine.AddSoundSource( "..\\Media\\Sounds\\Music\\shot_glock17.mp3" );
	game.engine.AddSoundSource( "..\\Media\\Sounds\\Music\\shot_m4a1.mp3" );
	
	game.InitWeapons();
	
	game.engine.SetLightningLimit( 50 );
	
	game.engine.DestroyWorldInEngineThread();
	LoadMap();
	
	game.engine.AddSoundSource( "..\\Media\\Sounds\\Music\\Morrowind Theme.mp3" );
	game.engine.AddSoundSource( "..\\Media\\Sounds\\Music\\Red Army Choir Katyusha.mp3" );
	game.engine.PlaySound( 1.0f, "Red Army Choir Katyusha", Vector( 0.0f, 2.0f, 0.0f ) );
	Delay( 100 );
	game.engine.PlaySound( 1.0f, "Morrowind Theme", Vector( -220.0f, 2.0f, -220.0f ) );
	Delay( 50 );
	game.engine.PlaySound( 1.0f, "Morrowind Theme", Vector( 220.0f, 2.0f, -220.0f ) );
	Delay( 50 );
	game.engine.PlaySound( 1.0f, "Morrowind Theme", Vector( -220.0f, 2.0f, 220.0f ) );
	
	_beginthread( GameThreadTestLoadingMap, 0, NULL );
	
	game.engine.map.DebugMode = false;
	
	
	game.engine.BeginLoop();
	
	while(1){Delay(1100);}
	
	return 0;
}
