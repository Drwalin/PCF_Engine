


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
	
	game.engine.AddObjects( 20 );
	for( int i = 0; i < game.engine.ObjectsNumber(); i++ )
	{
		game.engine.Object(i)->mass = 75.0f;
		game.engine.Object(i)->size.Set( 0.6f, 1.75f, 0.6f );
		game.engine.Object(i)->vel.Set( 0.0f, 0.0f, 0.0f );
		game.engine.Object(i)->force.Set( 0.0f, 0.0f, 0.0f );
		
		game.engine.Object(i)->pos.Set( (float(i/20)*10.0f) - 148.0f, 50.0f+float(i)*0.01f, (float(i%20)*10.0f) - 148.0f );
		game.engine.Object(i)->see[1] = 0.0f;
		game.engine.Object(i)->see[0] = 0.0f;
		
		game.engine.Object(i)->AddRayType( SIGHT );
		game.engine.Object(i)->AddRayType( SHOOT );
		game.engine.Object(i)->AddRayType( INTERACTION );
		
		game.engine.Object(i)->model = NULL;
		game.engine.Object(i)->GraphicModelScale = 1.0f;
		if( i > 0 )
		{
			switch( i%2 )
			{
			case 0:
				game.engine.Object(i)->model = game.engine.GetStaticModelHandle( "SMG_m45" );
				break;
			case 1:
				game.engine.Object(i)->model = game.engine.GetStaticModelHandle( "Glock311" );
				break;
			}
		}
	}
	game.engine.Object(0)->pos.Set( -148.0f, 10.0f, -148.0f );
	
	LoadMap();
	game.engine.UpdateWorld();
	
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
	
	game.engine.BeginLoop();
	
	while(1){Delay(1100);}
	
	return 0;
}
