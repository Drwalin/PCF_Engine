


int main( int argc, char *argv[] )
{
	srand( time( NULL ) );
	
	ShowCursor( false );
	//DEBUG("before objects");
	
	Game game;
	GameInstance = &game;
	game.GameInit( &argc, argv );
	DEBUG("after init");
	
	game.engine.SetKeybordFunction( KeyboardFunction );
	game.engine.SetGUIFunction( GUIFunction );
	DEBUG("after setting keyboard & gui functions");
	
	game.LoadTextures( "cfg\\Textures.ini" );
	DEBUG("after Texture.ini");
	game.LoadModels( "cfg\\Models.ini" );
	DEBUG("after Models.ini");
	game.LoadSounds( "cfg\\Sounds.ini" );
	DEBUG("after Sounds.ini");
	game.LoadWeapons( "cfg\\Weapons.ini" );
	DEBUG("after Weapons.ini");
	
	game.engine.SetLightningLimit( 50 );
	
	game.engine.DestroyWorldInEngineThread();
	DEBUG("after destroy world");
	
	LoadMap();
	DEBUG("after load map");
	
	game.engine.AddDynamicLightSource( SetVector( -100, -100, -100), SetVector( 1, 1, 1 ), 200.0f, 90.0f, -1.0f );
	game.engine.AddDynamicLightSource( SetVector( 0, 2, 0 ), SetVector( 0, 0, -1 ), 200.0f, 90.0f, 1.0f );
	game.engine.AddDynamicLightSource( SetVector( 0, 2, 0 ), SetVector( 0, 0, -1 ), 200.0f, 90.0f, 1.0f );
	DEBUG("after adding dynamic light sources");
	
//	game.engine.PlaySound( "Red Army Choir Katyusha", Vector( 0.0f, 2.0f, 0.0f ), 0.38f );
//	game.engine.PlaySound( "Path of The Borealis", Vector( 0.0f, 1.0f, 0.0f ), 70.0f );
//	game.engine.PlaySound( "Morrowind Theme", Vector( 220.0f, 2.0f, -220.0f ), 0.08f );
//	game.engine.PlaySound( "Morrowind Theme", Vector( -220.0f, 2.0f, 220.0f ), 0.08f );
	
	DEBUG("after playing sounds");
	//_beginthread( GameThreadTestLoadingMap, 0, NULL );
	
	game.engine.map.DebugMode = true;
	
	game.engine.SetUseVBO();
	
	DEBUG("beffore loop");
	
	game.engine.BeginLoop();
	
	return 0;
}
