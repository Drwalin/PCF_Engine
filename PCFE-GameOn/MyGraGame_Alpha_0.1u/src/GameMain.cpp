


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
	
	game.engine.SetLightningLimit( 500 );
	
	printf( "\n\n   Load map here:\n\n" );
	
	GameInstance -> LoadMap( "..\\Media\\Maps\\testMap.map" );
	GameInstance -> engine.UpdateWorld();
	
	printf( "\n\n   End of loading map\n\n" );
	
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
	
	printf( "\n\n    End of loading\n\n" );
	
	game.engine.BeginLoop();
	
	while(1){Delay(1100);}
	
	return 0;
}
