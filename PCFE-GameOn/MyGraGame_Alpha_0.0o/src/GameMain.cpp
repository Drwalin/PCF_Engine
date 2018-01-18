


int main( int argc, char *argv[] )
{
	ShowCursor( false );
	
	Game game;
	GameInstantiation = &game;
	game.GameInit( &argc, argv );
	
	game.engine.SetKeybordFunction( KeyboardFunction );
	game.engine.SetGUIFunction( GUIFunction );
	
	// Load textures:
	game.LoadTextures( "cfg\\Textures.ini" );
	/*
	game.engine.AddTexture( "..\\Media\\Textures\\textmodel.png",		GL_LINEAR );
	game.engine.AddTexture( "..\\Media\\Textures\\Tree.png",			GL_LINEAR );
	game.engine.AddTexture( "..\\Media\\Textures\\Herobrine.png",		GL_NEAREST );
	game.engine.AddTexture( "..\\Media\\Textures\\House.png",			GL_LINEAR );
	game.engine.AddTexture( "..\\Media\\Textures\\Barrel.png",			GL_LINEAR );
	game.engine.AddTexture( "..\\Media\\Textures\\Bow.png",				GL_LINEAR );
	game.engine.AddTexture( "..\\Media\\Textures\\Weed.png",			GL_LINEAR );
	game.engine.AddTexture( "..\\Media\\Textures\\Flower1.png",			GL_NEAREST );
	game.engine.AddTexture( "..\\Media\\Textures\\glasstext.png",		GL_LINEAR );
	game.engine.AddTexture( "..\\Media\\Textures\\clorox.png",			GL_LINEAR );
	*/
	
	// load models:
	game.LoadModels( "cfg\\Models.ini" );
	/*
	game.engine.AddGraphicModel( "..\\Media\\StaticModels\\Tree.obj",			game.engine.TextureId( "Tree" ),				Vector(3.0f,0.8f,3.0f) );
	game.engine.AddGraphicModel( "..\\Media\\StaticModels\\Herobrine.obj",		game.engine.TextureId( "Herobrine" ),			Vector(1.5f,1.0f,1.0f) );
	game.engine.AddGraphicModel( "..\\Media\\StaticModels\\House.obj",			game.engine.TextureId( "House" ),				Vector(1.0f,1.0f,1.0f) );
	game.engine.AddGraphicModel( "..\\Media\\StaticModels\\Barrel.obj",			game.engine.TextureId( "Barrel" ),				Vector(1.0f,1.0f,1.0f) );
	game.engine.AddGraphicModel( "..\\Media\\StaticModels\\BowWithArrow3.obj",	game.engine.TextureId( "Bow" ),					Vector(1.0f,1.0f,1.0f) );
	game.engine.AddGraphicModel( "..\\Media\\StaticModels\\Weed.obj",			game.engine.TextureId( "Weed" ),				Vector(1.0f,1.0f,1.0f) );
	game.engine.AddGraphicModel( "..\\Media\\StaticModels\\Flower1.obj",		game.engine.TextureId( "Flower1" ),				Vector(1.0f,1.0f,1.0f) );
	game.engine.AddGraphicModel( "..\\Media\\StaticModels\\glasstest.obj",		game.engine.TextureId( "glasstext" ),			Vector(1.0f,1.0f,1.0f) );
	game.engine.AddGraphicModel( "..\\Media\\StaticModels\\clorox.obj",			game.engine.TextureId( "clorox" ),				Vector(1.0f,1.0f,1.0f) );
	*/
	
	
	srand( time( NULL ) );
	
	game.engine.SetLightningLimit( 500 );
	
	game.engine.AddObjects( 20 );
	for( int i = 0; i < game.engine.ObjectsNumber(); i++ )
	{
		game.engine.Object(i)->aabb.resize( 1 );
		game.engine.Object(i)->aabb[0].mass = 75.0f;
		game.engine.Object(i)->aabb[0].size.Set( 0.6f, 1.75f, 0.6f );
		game.engine.Object(i)->aabb[0].vel = &game.engine.map.staticobject[i]->vel;
		game.engine.Object(i)->aabb[0].force = &game.engine.map.staticobject[i]->force;
		game.engine.Object(i)->aabb[0].resistanceforce = &game.engine.map.staticobject[i]->resistanceforce;
		
		game.engine.Object(i)->pos.Set( (float(i/20)*10.0f) - 148.0f, 50.0f+float(i)*0.01f, (float(i%20)*10.0f) - 148.0f );
		game.engine.Object(i)->see[1] = 0.0f;
		game.engine.Object(i)->see[0] = 0.0f;
		
		game.engine.Object(i)->AddRayType( SIGHT );
		game.engine.Object(i)->AddRayType( SHOOT );
		game.engine.Object(i)->AddRayType( INTERACTION );
		
		game.engine.Object(i)->model = NULL;
		if( i != 0 )
		{
			switch( i )
			{
			case 2:
				game.engine.Object(i)->model = game.engine.GetStaticModelHandle( "BowWithArrow3" );
				game.engine.Object(i)->aabb[0].size.Set( 1.3f, 1.3f, 1.3f );
				game.engine.Object(i)->GraphicModelScale = 1.3f;
				break;
			case 3:
				game.engine.Object(i)->model = game.engine.GetStaticModelHandle( "Barrel" );
				game.engine.Object(i)->aabb[0].size.Set( 0.6f, 1.0f, 0.6f );
				game.engine.Object(i)->GraphicModelScale = 1.0f;
				break;
			case 4:
				game.engine.Object(i)->model = game.engine.GetStaticModelHandle( "Tree" );
				game.engine.Object(i)->aabb[0].size.Set( 1.0f, 5.0f, 1.0f );
				game.engine.Object(i)->GraphicModelScale = 5.0f;
				break;
			case 5:
				game.engine.Object(i)->model = game.engine.GetStaticModelHandle( "clorox" );
				game.engine.Object(i)->aabb[0].size.Set( 4.0f, 4.75f, 4.0f );
				game.engine.Object(i)->GraphicModelScale = 4.75f;
				break;
			case 6:
				game.engine.Object(i)->model = game.engine.GetStaticModelHandle( "Weed" );
				game.engine.Object(i)->aabb[0].size.Set( 1.3f, 4.3f, 1.3f );
				game.engine.Object(i)->GraphicModelScale = 4.3f;
				break;
			case 7:
			case 8:
			case 9:
			case 10:
			case 11:
			case 12:
			case 13:
				game.engine.Object(i)->model = game.engine.GetStaticModelHandle( "Flower1" );
				game.engine.Object(i)->aabb[0].size.Set( 0.1f, 0.5f, 0.1f );
				game.engine.Object(i)->GraphicModelScale = 1.3f;
				game.engine.Object(i)->ObjectsCollisionUse = false;
				break;
			default:
				game.engine.Object(i)->model = game.engine.GetStaticModelHandle( "Herobrine" );
				game.engine.Object(i)->aabb[0].size.Set( 0.6f, 1.75f, 0.6f );
				game.engine.Object(i)->GraphicModelScale = 1.75f;
			}
		}
	}
	
	
	GenerateMap___New();
	GameInstantiation->engine.UpdateWorld();
	
	
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
