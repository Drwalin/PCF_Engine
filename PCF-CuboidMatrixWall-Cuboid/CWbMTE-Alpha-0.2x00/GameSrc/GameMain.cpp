


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
	
	game.ReadSettings( "cfg\\settings.cfg" );
	
	// Load textures:
	game.engine.AddTexture( "..\\MediaPNG\\Textures\\textmodel.png",	GL_LINEAR );
	game.engine.AddTexture( "..\\MediaPNG\\Textures\\Tree.png",			GL_LINEAR );
	game.engine.AddTexture( "..\\MediaPNG\\Textures\\Herobrine.png",	GL_NEAREST );
	game.engine.AddTexture( "..\\MediaPNG\\Textures\\House.png",		GL_LINEAR );
	game.engine.AddTexture( "..\\MediaPNG\\Textures\\Barrel.png",		GL_LINEAR );
	game.engine.AddTexture( "..\\MediaPNG\\Textures\\Bow.png",			GL_LINEAR );
	game.engine.AddTexture( "..\\MediaPNG\\Textures\\Weed.png",			GL_LINEAR );
	game.engine.AddTexture( "..\\MediaPNG\\Textures\\Flower1.png",		GL_LINEAR );
	game.engine.AddTexture( "..\\MediaPNG\\Textures\\glasstext.png",	GL_LINEAR );
	game.engine.AddTexture( "..\\MediaPNG\\Textures\\clorox.png",		GL_LINEAR );
	
	
	game.engine.AddVBO( game.engine.TextureId( "textmodel" ) );
	
	// load models:
	game.engine.AddGraphicModel( "..\\MediaPNG\\StaticModels\\Tree.obj",			game.engine.TextureId( "Tree" ),				Vector(3.0f,0.8f,3.0f) );
	game.engine.AddGraphicModel( "..\\MediaPNG\\StaticModels\\Herobrine.obj",		game.engine.TextureId( "Herobrine" ),			Vector(1.5f,1.0f,1.0f) );
	game.engine.AddGraphicModel( "..\\MediaPNG\\StaticModels\\House.obj",			game.engine.TextureId( "House" ),				Vector(1.0f,1.0f,1.0f) );
	game.engine.AddGraphicModel( "..\\MediaPNG\\StaticModels\\Barrel.obj",			game.engine.TextureId( "Barrel" ),				Vector(1.0f,1.0f,1.0f) );
	game.engine.AddGraphicModel( "..\\MediaPNG\\StaticModels\\BowWithArrow3.obj",	game.engine.TextureId( "Bow" ),					Vector(1.0f,1.0f,1.0f) );
	game.engine.AddGraphicModel( "..\\MediaPNG\\StaticModels\\Weed.obj",			game.engine.TextureId( "Weed" ),				Vector(1.0f,1.0f,1.0f) );
	game.engine.AddGraphicModel( "..\\MediaPNG\\StaticModels\\Flower1.obj",			game.engine.TextureId( "Flower1" ),				Vector(1.0f,1.0f,1.0f) );
	game.engine.AddGraphicModel( "..\\MediaPNG\\StaticModels\\glasstest.obj",		game.engine.TextureId( "glasstext" ),			Vector(1.0f,1.0f,1.0f) );
	game.engine.AddGraphicModel( "..\\MediaPNG\\StaticModels\\clorox.obj",		game.engine.TextureId( "clorox" ),			Vector(1.0f,1.0f,1.0f) );
	
	srand( time( NULL ) );
	
	game.engine.SetLightningLimit( 5 );
	
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
				game.engine.Object(i)->aabb[0].size.Set( 0.1f, 0.1f, 0.1f );
				game.engine.Object(i)->GraphicModelScale = 1.3f;
				break;
			default:
				game.engine.Object(i)->model = game.engine.GetStaticModelHandle( "Herobrine" );
				game.engine.Object(i)->aabb[0].size.Set( 0.6f, 1.75f, 0.6f );
				game.engine.Object(i)->GraphicModelScale = 1.75f;
			}
		}
	}
	
	float x, z;
	float minx = -200.0f, minz = -200.0f, maxx = 50.0f, maxz = 50.0f;
	
	float size = 2.0f;
	
	printf( " minx: " );
	scanf( "%f", &minx );
	printf( " minz: " );
	scanf( "%f", &minz );
	printf( " maxx: " );
	scanf( "%f", &maxx );
	printf( " maxz: " );
	scanf( "%f", &maxz );
	
	printf( " size: " );
	scanf( "%f", &size );
	
	wsl[0] = minx + 1;
	wsl[2] = minz + 1;
	wsh[0] = maxx - 1;
	wsh[2] = maxz - 1;
	
	Vector a, b, c, normal;
	
	srand( time( NULL ) );
	
	PerlinNoise hmap, hmap2;
	hmap.Set(  0.125, 0.25, 4.0, 4, rand() );
	hmap2.Set( 0.125, 0.01, 128.0, 4, rand() );
	
	for( x = minx; x < maxx; x += size )
	{
		for( z = minz; z < maxz; z += size )
		{
			#define getheight(x,z) ((hmap.GetHeight( x+500.0f, z+500.0f )+1.0f))+((hmap2.GetHeight( (x+500.0f), (z+500.0f) )+1.0f))
			game.engine.AddVertexToLastVBO( x,      getheight(x,z), z,					(x)*0.1f,		(z)*0.1f );
			game.engine.AddVertexToLastVBO( x+size, getheight(x+size,z), z,				(x+size)*0.1f,	(z)*0.1f );
			game.engine.AddVertexToLastVBO( x+size, getheight(x+size,z+size), z+size,	(x+size)*0.1f,	(z+size)*0.1f );
			game.engine.CreateTriangleWithLastThreeVertices();
			
			game.engine.AddVertexToLastVBO( x,      getheight(x,z), z,					(x)*0.1f,		(z)*0.1f );
			game.engine.AddVertexToLastVBO( x,      getheight(x,z+size), z+size,		(x)*0.1f,		(z+size)*0.1f );
			game.engine.AddVertexToLastVBO( x+size, getheight(x+size,z+size), z+size,	(x+size)*0.1f,	(z+size)*0.1f );
			game.engine.CreateTriangleWithLastThreeVertices();
			
			a.Set( x,      getheight(x,z), z );
			b.Set( x+size, getheight(x+size,z), z );
			c.Set( x+size, getheight(x+size,z+size), z+size );
			normal = ( a - b ) && ( a - c );
			if( normal[1] < 0.0f )
				normal = 0.0f - normal;
			normal.Normalize();
			game.engine.AddPhysicTriangle( a, b, c, normal );
			
			a.Set( x,      getheight(x,z), z );
			b.Set( x,      getheight(x,z+size), z+size );
			c.Set( x+size, getheight(x+size,z+size), z+size );
			normal = ( a - b ) && ( a - c );
			if( normal[1] < 0.0f )
				normal = 0.0f - normal;
			normal.Normalize();
			game.engine.AddPhysicTriangle( a, b, c, normal );
		}
	}
	
	PerlinNoise hmap3;
	hmap3.Set( 0.125, 0.011, 128.0, 1, rand() );
	
	int numb = 0;
	
	int mingen = 0;
	printf( "\n Flowers percentage: " );
	scanf( "%i", &mingen );
	
	for( x = minx; x < maxx; x += size*0.05f )
	{
		for( z = minz; z < maxz; z += size*0.05f )
		{
			if( rand() < mingen && hmap3.GetHeight( x, z ) > 0.0f )
			{
				game.engine.AddGraphicObject();
				game.engine.LastGraphicObject() -> SetModel( game.engine.GetStaticModelHandle( "Flower1" ) );
				game.engine.LastGraphicObject() -> SetScale( float((rand()%1000)+500)/500.0f );
				game.engine.LastGraphicObject() -> SetPos( SetVector( x, getheight(x,z), z ) );
				game.engine.LastGraphicObject() -> SetRotate( 0, rand()%1000, 0 );
				numb++;
			}
		}
	}
	
	printf( "\n flowers number: %i", numb );
	getch();
	
	game.engine.map.vbotex[0].Generate();
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
