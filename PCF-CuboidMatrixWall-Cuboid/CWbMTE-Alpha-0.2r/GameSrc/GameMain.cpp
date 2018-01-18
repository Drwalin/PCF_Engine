




int main( int argc, char *argv[] )
{
	ShowCursor( false );
	
	InitKeyCodes( "cfg\\MSDNKey.ini" );
	
	Engine engine;
	Game game;
	SetEngineInstantiation( &game.engine );
	GameInstantiation = &game;
	game.GameInit( "cfg\\controlls.cfg" );
	
	game.ReadSettings( "cfg\\config.cfg" );
	
	game.engine.SetKeybordFunction( KeyboardFunction );
	game.engine.SetGUIFunction( GUIFunction );
	
	game.engine.Init( &argc, argv );
	
	game.engine.AddVBO( "..\\MediaPNG\\Textures\\textmodel.png", GL_LINEAR );
	
	/*
		load textures and models:
	*/
	game.engine.AddGraphicModel( "..\\MediaPNG\\StaticModels\\Tree.obj",			"..\\MediaPNG\\Textures\\Tree.png",			Vector(3.0f,0.8f,3.0f),			GL_LINEAR );
	game.engine.AddGraphicModel( "..\\MediaPNG\\StaticModels\\Herobrine.obj",		"..\\MediaPNG\\Textures\\Herobrine.png",		Vector(1.5f,1.0f,1.0f),			GL_NEAREST );
	game.engine.AddGraphicModel( "..\\MediaPNG\\StaticModels\\House.obj",			"..\\MediaPNG\\Textures\\House.png",			Vector(1.0f,1.0f,1.0f),			GL_NEAREST );
	game.engine.AddGraphicModel( "..\\MediaPNG\\StaticModels\\Barrel.obj",			"..\\MediaPNG\\Textures\\Barrel.png",			Vector(1.0f,1.0f,1.0f),			GL_NEAREST );
	
	srand( time( NULL ) );
	
	game.engine.SetLightningLimit( 1000 );
	
	game.engine.AddObjects( 50 );
	for( int i = 0; i < game.engine.ObjectsNumber(); i++ )
	{
		game.engine.Object(i)->aabb.resize( 1 );
		game.engine.Object(i)->aabb[0].mass = 75.0f;
		game.engine.Object(i)->aabb[0].size.Set( 0.6f, 1.75f, 0.6f );
		game.engine.Object(i)->aabb[0].vel = &game.engine.map.staticobject[i]->vel;
		game.engine.Object(i)->aabb[0].force = &game.engine.map.staticobject[i]->force;
		game.engine.Object(i)->aabb[0].resistanceforce = &game.engine.map.staticobject[i]->resistanceforce;
		
		game.engine.Object(i)->pos.Set( (float(i/45)*10.0f) - 248.0f, 6.0f+float(i)*0.01f, (float(i%45)*10.0f) - 248.0f );
		game.engine.Object(i)->see[1] = 0.0f;
		game.engine.Object(i)->see[0] = 0.0f;
		
		game.engine.Object(i)->model = NULL;
		if( i != 0 )
		{
			switch( i )
			{
			case 3:
				game.engine.Object(i)->model = game.engine.GetStaticModelHandle( "Barrel" );
				game.engine.Object(i)->aabb[0].size.Set( 0.6f, 1.0f, 0.6f );
				break;
			case 4:
				game.engine.Object(i)->model = game.engine.GetStaticModelHandle( "Tree" );
				game.engine.Object(i)->aabb[0].size.Set( 0.6f, 5.0f, 0.6f );
				break;
			case 5:
				game.engine.Object(i)->model = game.engine.GetStaticModelHandle( "House" );
				game.engine.Object(i)->aabb[0].size.Set( 4.0f, 4.75f, 4.0f );
				break;
			default:
				game.engine.Object(i)->model = game.engine.GetStaticModelHandle( "Herobrine" );
			}
		}
	}
	
	game.engine.Object(0)->pos.Set( (float(1/45)*10.0f) - 248.0f, 60.0f+float(1)*0.01f, (float(1%45)*10.0f) - 248.0f );
	
	
	
	game.engine.AddVertexToLastVBO( -250.0f, 0.0f, -250.0f, 0.0f, 0.0f );
	game.engine.AddVertexToLastVBO(  250.0f, 0.0f, -250.0f, 15.0f, 0.0f );
	game.engine.AddVertexToLastVBO(  250.0f, 0.0f,  250.0f, 15.0f, 15.0f );
	game.engine.CreateTriangleWithLastThreeVertices();
	
	game.engine.AddVertexToLastVBO( -250.0f, 0.0f, -250.0f, 0.0f, 0.0f );
	game.engine.AddVertexToLastVBO(  -250.0f, 0.0f, 250.0f, 0.0f, 15.0f );
	game.engine.AddVertexToLastVBO(  250.0f, 0.0f,  250.0f, 15.0f, 15.0f );
	game.engine.CreateTriangleWithLastThreeVertices();
	
	game.engine.map.vbotex[0].Generate();
	
	{
		Vector a, b, c, normal;
		
		a.Set( -250.0f, 0.0f, -250.0f );
		b.Set(  250.0f, 0.0f, -250.0f );
		c.Set(  250.0f, 0.0f,  250.0f );
		normal = ( a - b ) && ( a - c );
		if( normal[1] < 0.0f )
			normal = 0.0f - normal;
		normal.Normalize();
		game.engine.AddPhysicTriangle( a, b, c, normal );
		
		a.Set( -250.0f, 0.0f, -250.0f );
		b.Set( -250.0f, 0.0f,  250.0f );
		c.Set(  250.0f, 0.0f,  250.0f );
		normal = ( a - b ) && ( a - c );
		if( normal[1] < 0.0f )
			normal = 0.0f - normal;
		normal.Normalize();
		game.engine.AddPhysicTriangle( a, b, c, normal );
	}
	
	game.engine.UpdateWorld();
	
	game.engine.AddSoundSource( "..\\MediaPNG\\Sounds\\Music\\Morrowind Theme.mp3" );
	game.engine.AddSoundSource( "..\\MediaPNG\\Sounds\\Music\\Red Army Choir Katyusha.mp3" );
	game.engine.PlaySound( 1.0f, "Red Army Choir Katyusha", Vector( 0.0f, 2.0f, 0.0f ) );
	Delay( 100 );
	game.engine.PlaySound( 1.0f, "Morrowind Theme", Vector( -220.0f, 2.0f, -220.0f ) );
	Delay( 50 );
	game.engine.PlaySound( 1.0f, "Morrowind Theme", Vector( 220.0f, 2.0f, -220.0f ) );
	Delay( 50 );
	game.engine.PlaySound( 1.0f, "Morrowind Theme", Vector( -220.0f, 2.0f, 220.0f ) );
	
	game.engine.BeginLoop();
	
	while(1){Delay(1100);}
	
	return 0;
}
