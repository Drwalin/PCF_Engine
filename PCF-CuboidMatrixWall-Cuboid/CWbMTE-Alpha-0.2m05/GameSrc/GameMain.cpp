




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
	
	
	
	game.engine.AddVBO( "Media\\Textures\\textmodel.bmpx", GL_LINEAR );
	
	
//	game.engine.map.vbotex.resize( 1 );
//	game.engine.map.vbotex[0].SetTexture( "Media\\Textures\\textmodel.bmpx", GL_LINEAR );
	
	
	
	game.engine.map.texture.resize( 1 );
	game.engine.map.texture[0].LoadInit( "Media\\Textures\\texture1.bmpx", GL_LINEAR );
	
	
	
	/*
		load textures and models:
	*/
	game.engine.AddGraphicModel( "Media\\StaticModels\\Tree.obj",			"Media\\Textures\\Tree.bmpx",			Vector(3.0f,0.8f,3.0f),			GL_LINEAR );
	game.engine.AddGraphicModel( "Media\\StaticModels\\Herobrine.obj",		"Media\\Textures\\Herobrine.bmpx",		Vector(1.5f,1.0f,1.0f),			GL_NEAREST );
	game.engine.AddGraphicModel( "Media\\StaticModels\\House.obj",			"Media\\Textures\\House.bmpx",			Vector(1.0f,1.0f,1.0f),			GL_NEAREST );
	game.engine.AddGraphicModel( "Media\\StaticModels\\Barrel.obj",			"Media\\Textures\\Barrel.bmpx",			Vector(1.0f,1.0f,1.0f),			GL_NEAREST );
	
	srand( time( NULL ) );
	
	game.engine.SetLightningLimit( 1000 );
	
	game.engine.map.staticobject.resize( 50 );
	for( int i = 0; i < game.engine.map.staticobject.size(); i++ )
	{
		game.engine.map.staticobject[i].aabb.resize( 1 );
		game.engine.map.staticobject[i].aabb[0].mass = 75.0f;
		game.engine.map.staticobject[i].aabb[0].size.Set( 0.6f, 1.75f, 0.6f );
		game.engine.map.staticobject[i].aabb[0].vel = &game.engine.map.staticobject[i].vel;
		game.engine.map.staticobject[i].aabb[0].force = &game.engine.map.staticobject[i].force;
		game.engine.map.staticobject[i].aabb[0].resistanceforce = &game.engine.map.staticobject[i].resistanceforce;
		
		game.engine.map.staticobject[i].pos.Set( (float(i/45)*10.0f) - 248.0f, 6.0f+float(i)*0.01f, (float(i%45)*10.0f) - 248.0f );
		game.engine.map.staticobject[i].see[1] = 0.0f;
		game.engine.map.staticobject[i].see[0] = 0.0f;
		
		game.engine.map.staticobject[i].model = NULL;
		if( i != 0 )
		{
			switch( i )
			{
			case 3:
				game.engine.map.staticobject[i].model = game.engine.GetStaticModelHandle( "Barrel" );
				game.engine.map.staticobject[i].aabb[0].size.Set( 0.6f, 1.0f, 0.6f );
				break;
			case 4:
				game.engine.map.staticobject[i].model = game.engine.GetStaticModelHandle( "Tree" );
				game.engine.map.staticobject[i].aabb[0].size.Set( 0.6f, 5.0f, 0.6f );
				break;
			case 5:
				game.engine.map.staticobject[i].model = game.engine.GetStaticModelHandle( "House" );
				game.engine.map.staticobject[i].aabb[0].size.Set( 4.0f, 4.75f, 4.0f );
				break;
			default:
				game.engine.map.staticobject[i].model = game.engine.GetStaticModelHandle( "Herobrine" );
			}
		}
	}
	game.engine.map.staticobject[0].pos.Set( (float(1/45)*10.0f) - 248.0f, 60.0f+float(1)*0.01f, (float(1%45)*10.0f) - 248.0f );
	
	PerlinNoise noise;
	noise.Set( 0.125, 0.5, 2.0, 4, 63*354 );
	
	#define ONETRIANGLESIZE 1.0f
	#define SIZEEEE_2 (250.0f*ONETRIANGLESIZE)
	#define SIZEEEE (250.0f*ONETRIANGLESIZE)
	#define HEIGHT 7.0f
	
	
	
	#define VBO game.engine.map.vbotex[0].AddVertex
	VBO( -250.0f, 0.0f, -250.0f, 0.0f, 0.0f );
	VBO(  250.0f, 0.0f, -250.0f, 15.0f, 0.0f );
	VBO(  250.0f, 0.0f,  250.0f, 15.0f, 15.0f );
	VBO( -250.0f, 0.0f, -250.0f, 0.0f, 0.0f );
	VBO(  -250.0f, 0.0f, 250.0f, 0.0f, 15.0f );
	VBO(  250.0f, 0.0f,  250.0f, 15.0f, 15.0f );
	#undef VBO
	
	#define VBO game.engine.map.vbotex[0].AddTriangle
	VBO(
		game.engine.map.vbotex[0].vertices.size()-6,
		game.engine.map.vbotex[0].vertices.size()-5,
		game.engine.map.vbotex[0].vertices.size()-4
		);
	VBO(
		game.engine.map.vbotex[0].vertices.size()-1,
		game.engine.map.vbotex[0].vertices.size()-2,
		game.engine.map.vbotex[0].vertices.size()-3
		);
	#undef VBO
	
	#define triangles game.engine.map.triPHYS
	
	{
		triangles.resize( triangles.size()+1 );
		
		triangles[ triangles.size()-1 ].vertex[0][0] = -250.0f;
		triangles[ triangles.size()-1 ].vertex[0][1] =  0.0f;
		triangles[ triangles.size()-1 ].vertex[0][2] = -250.0f;
		triangles[ triangles.size()-1 ].vertex[1][0] =  250.0f;
		triangles[ triangles.size()-1 ].vertex[1][1] =  0.0f;
		triangles[ triangles.size()-1 ].vertex[1][2] = -250.0f;
		triangles[ triangles.size()-1 ].vertex[2][0] =  250.0f;
		triangles[ triangles.size()-1 ].vertex[2][1] =  0.0f;
		triangles[ triangles.size()-1 ].vertex[2][2] =  250.0f;
		triangles[ triangles.size()-1 ].normal = ( triangles[ triangles.size()-1 ].vertex[0] - triangles[ triangles.size()-1 ].vertex[1] ) && ( triangles[ triangles.size()-1 ].vertex[0] - triangles[ triangles.size()-1 ].vertex[2] );
		if( triangles[ triangles.size()-1 ].normal[1] < 0.0f )
			triangles[ triangles.size()-1 ].normal = 0.0f - triangles[ triangles.size()-1 ].normal;
		triangles[ triangles.size()-1 ].normal.Normalize();
		triangles[ triangles.size()-1 ].Calculate();
		
		triangles.resize( triangles.size()+1 );
		
		triangles[ triangles.size()-1 ].vertex[0][0] = -250.0f;
		triangles[ triangles.size()-1 ].vertex[0][1] =  0.0f;
		triangles[ triangles.size()-1 ].vertex[0][2] = -250.0f;
		triangles[ triangles.size()-1 ].vertex[1][0] = -250.0f;
		triangles[ triangles.size()-1 ].vertex[1][1] =  0.0f;
		triangles[ triangles.size()-1 ].vertex[1][2] =  250.0f;
		triangles[ triangles.size()-1 ].vertex[2][0] =  250.0f;
		triangles[ triangles.size()-1 ].vertex[2][1] =  0.0f;
		triangles[ triangles.size()-1 ].vertex[2][2] =  250.0f;
		triangles[ triangles.size()-1 ].normal = ( triangles[ triangles.size()-1 ].vertex[0] - triangles[ triangles.size()-1 ].vertex[1] ) && ( triangles[ triangles.size()-1 ].vertex[0] - triangles[ triangles.size()-1 ].vertex[2] );
		if( triangles[ triangles.size()-1 ].normal[1] < 0.0f )
			triangles[ triangles.size()-1 ].normal = 0.0f - triangles[ triangles.size()-1 ].normal;
		triangles[ triangles.size()-1 ].normal.Normalize();
		triangles[ triangles.size()-1 ].Calculate();
	}
	
	game.engine.map.vbotex[0].Generate();
	
	game.engine.UpdateWorld();
	
	game.engine.AddSoundSource( "..\\Media\\Sounds\\Music\\Morrowind Theme.mp3" );
	game.engine.AddSoundSource( "..\\Media\\Sounds\\Music\\Red Army Choir Katyusha.mp3" );
	game.engine.PlaySound( "Red Army Choir Katyusha", Vector( 0.0f, 2.0f, 0.0f ) );
	Sleep( 100 );
	game.engine.PlaySound( "Morrowind Theme", Vector( -220.0f, 2.0f, -220.0f ) );
	Sleep( 50 );
	game.engine.PlaySound( "Morrowind Theme", Vector( 220.0f, 2.0f, -220.0f ) );
	Sleep( 50 );
	game.engine.PlaySound( "Morrowind Theme", Vector( -220.0f, 2.0f, 220.0f ) );
	
	game.engine.BeginLoop();
	
	while(1){Sleep(1100);}
	
	return 0;
}
