




int main( int argc, char *argv[] )
{
	ShowCursor( false );
	
	InitKeyCodes( "cfg\\MSDNKey.ini" );
	
    Engine engine;
    Game game;
    SetEngineInstantiation( &game.engine );
    GameInstantiation = &game;
	game.GameInit( "cfg\\controlls.cfg" );
    
    game.engine.WindowFullScreen = false;
    
    game.ReadSettings( "cfg\\config.cfg" );
    
    game.engine.KeyboardFunction = KeyboardFunction;
    game.engine.GUIFunction = GUIFunction;
    
    game.engine.Init( &argc, argv );
    
    game.engine.map.texture.resize( 1 );
    game.engine.map.texture[0].LoadInit( "Media\\texture1.bmpx" );
    game.engine.map.vbotex.resize( 1 );
    game.engine.map.vbotex[0].SetTexture( "Media\\texture1.bmpx" );
	/*
    	load textures and models:
    */
    game.engine.AddGraphicModel( "TestModel.mdl" );
    
    srand( time( NULL ) );
    
	game.engine.map.staticobject.resize( 100 );
	for( int i = 0; i < game.engine.map.staticobject.size(); i++ )
	{
		game.engine.map.staticobject[i].aabb.resize( 1 );
		game.engine.map.staticobject[i].aabb[0].size.Set( 0.6f, 1.75f, 0.6f );
		game.engine.map.staticobject[i].aabb[0].vel = &game.engine.map.staticobject[i].vel;
		game.engine.map.staticobject[i].aabb[0].force = &game.engine.map.staticobject[i].force;
		game.engine.map.staticobject[i].aabb[0].resistanceforce = &game.engine.map.staticobject[i].resistanceforce;
		game.engine.map.staticobject[i].pos.Set( 0.0f, 30.0f+float(i)*10.0f, 0.0f );
		game.engine.map.staticobject[i].see[1] = 0.0f;
		game.engine.map.staticobject[i].see[0] = 0.0f;
	}
    
    PerlinNoise noise;
    for( int dudwa = 1; dudwa < 2; dudwa++ )
    {
    noise.Set( 0.125, 0.5, 2.0, 4, 63*dudwa );
    
    #define ONETRIANGLESIZE 1.0f
    #define SIZEEEE_2 (100.0f*ONETRIANGLESIZE)
    #define SIZEEEE (100.0f*ONETRIANGLESIZE)
    #define HEIGHT 15.0f
    
    
    
	for( float z = -SIZEEEE_2; z < SIZEEEE_2+ONETRIANGLESIZE; z+=ONETRIANGLESIZE )
	{
    	for( float x = -SIZEEEE_2; x < SIZEEEE_2+ONETRIANGLESIZE; x+=ONETRIANGLESIZE )
		{
			#define VBO game.engine.map.vbotex[0].AddVertex
//				( float x, float y, float z, float texcoordx, float texcoordy )
				VBO( x, noise.GetHeight( (double)(x)/4.0, (double)(z)/4.0 ) * HEIGHT, z, (x+SIZEEEE_2)*32.0f/(SIZEEEE_2*2.0f), (z+SIZEEEE_2)*32.0f/(SIZEEEE_2*2.0f) );
			#undef VBO
		}
	}
    
    
	for( int z = 0; z < int(SIZEEEE*2.0f/ONETRIANGLESIZE); z++ )
	{
		for( int x = 0; x < int(SIZEEEE*2.0f/ONETRIANGLESIZE); x++ )
		{
			#define VBO game.engine.map.vbotex[0].AddTriangle
				
				VBO(
					x+((z)*int(1+(SIZEEEE*2.0f/ONETRIANGLESIZE))),
					x+1+((z)*int(1+(SIZEEEE*2.0f/ONETRIANGLESIZE))),
					x+1+((z+1)*int(1+(SIZEEEE*2.0f/ONETRIANGLESIZE)))
					);
				VBO(
					x+((z)*int(1+(SIZEEEE*2.0f/ONETRIANGLESIZE))),
					x+((z+1)*int(1+(SIZEEEE*2.0f/ONETRIANGLESIZE))),
					x+1+((z+1)*int(1+(SIZEEEE*2.0f/ONETRIANGLESIZE)))
					);
				
			#undef VBO
		}
	}
    
    
    
   	for( float z = -SIZEEEE_2; z < SIZEEEE_2; z+=ONETRIANGLESIZE )
	{
	    for( float x = -SIZEEEE_2; x < SIZEEEE_2; x+=ONETRIANGLESIZE )
		{
			#undef SIZEEEE
			#define triangles game.engine.map.triPHYS
			
			triangles.resize( triangles.size()+2 );
			
			triangles[ triangles.size()-1 ].vertex[0][0] = x;
			triangles[ triangles.size()-1 ].vertex[0][1] = noise.GetHeight( (double)(x)/4.0, (double)(z)/4.0 ) * HEIGHT;
			triangles[ triangles.size()-1 ].vertex[0][2] = z;
			triangles[ triangles.size()-1 ].vertex[1][0] = x+ONETRIANGLESIZE;
			triangles[ triangles.size()-1 ].vertex[1][1] = noise.GetHeight( (double)(x+ONETRIANGLESIZE)/4.0, (double)(z)/4.0 ) * HEIGHT;
			triangles[ triangles.size()-1 ].vertex[1][2] = z;
			triangles[ triangles.size()-1 ].vertex[2][0] = x+ONETRIANGLESIZE;
			triangles[ triangles.size()-1 ].vertex[2][1] = noise.GetHeight( (double)(x+ONETRIANGLESIZE)/4.0, (double)(z+ONETRIANGLESIZE)/4.0 ) * HEIGHT;
			triangles[ triangles.size()-1 ].vertex[2][2] = z+ONETRIANGLESIZE;
			triangles[ triangles.size()-1 ].normal = ( triangles[ triangles.size()-1 ].vertex[0] - triangles[ triangles.size()-1 ].vertex[1] ) && ( triangles[ triangles.size()-1 ].vertex[0] - triangles[ triangles.size()-1 ].vertex[2] );
			if( triangles[ triangles.size()-1 ].normal[1] < 0.0f )
				triangles[ triangles.size()-1 ].normal = 0.0f - triangles[ triangles.size()-1 ].normal;
			triangles[ triangles.size()-1 ].normal.Normalize();
			triangles[ triangles.size()-1 ].Calculate();
			
			triangles[ triangles.size()-2 ].vertex[0][0] = x;
			triangles[ triangles.size()-2 ].vertex[0][1] = noise.GetHeight( (double)(x)/4.0, (double)(z)/4.0 ) * HEIGHT;
			triangles[ triangles.size()-2 ].vertex[0][2] = z;
			triangles[ triangles.size()-2 ].vertex[1][0] = x+ONETRIANGLESIZE;
			triangles[ triangles.size()-2 ].vertex[1][1] = noise.GetHeight( (double)(x+ONETRIANGLESIZE)/4.0, (double)(z+ONETRIANGLESIZE)/4.0 ) * HEIGHT;
			triangles[ triangles.size()-2 ].vertex[1][2] = z+ONETRIANGLESIZE;
			triangles[ triangles.size()-2 ].vertex[2][0] = x;
			triangles[ triangles.size()-2 ].vertex[2][1] = noise.GetHeight( (double)(x)/4.0, (double)(z+ONETRIANGLESIZE)/4.0 ) * HEIGHT;
			triangles[ triangles.size()-2 ].vertex[2][2] = z+ONETRIANGLESIZE;
			triangles[ triangles.size()-2 ].normal = ( triangles[ triangles.size()-2 ].vertex[0] - triangles[ triangles.size()-2 ].vertex[1] ) && ( triangles[ triangles.size()-2 ].vertex[0] - triangles[ triangles.size()-2 ].vertex[2] );
			if( triangles[ triangles.size()-2 ].normal[1] < 0.0f )
				triangles[ triangles.size()-2 ].normal = 0.0f - triangles[ triangles.size()-2 ].normal;
			triangles[ triangles.size()-2 ].normal.Normalize();
			triangles[ triangles.size()-2 ].Calculate();
		}
	}
	}
	
	game.engine.map.vbotex[0].Generate();
	
    game.engine.BeginLoop();
    
    while(1){Sleep(1100);}
    
    return 0;
}
