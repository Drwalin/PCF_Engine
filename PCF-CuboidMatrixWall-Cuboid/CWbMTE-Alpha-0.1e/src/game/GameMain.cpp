




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
    /*
    	load textures and models:
    */
    game.engine.AddGraphicModel( "TestModel.mdl" );
    
	game.engine.map.staticobject.resize( 2 );
	for( int i = 0; i < game.engine.map.staticobject.size(); i++ )
	{
		game.engine.map.staticobject[i].aabb.resize( 1 );
		game.engine.map.staticobject[i].aabb[0].size.Set( 0.6f, 1.75f, 0.6f );
		game.engine.map.staticobject[i].aabb[0].vel = &game.engine.map.staticobject[i].vel;
		game.engine.map.staticobject[i].aabb[0].force = &game.engine.map.staticobject[i].force;
		game.engine.map.staticobject[i].aabb[0].resistanceforce = &game.engine.map.staticobject[i].resistanceforce;
		game.engine.map.staticobject[i].pos.Set( 0.0f, 30.0f+float(i)*0.2f, 0.0f );
		game.engine.map.staticobject[i].see[1] = 0.0f;
		game.engine.map.staticobject[i].see[0] = 0.0f;
	}
    
    PerlinNoise noise;
    for( int dudwa = 1; dudwa < 2; dudwa++ )
    {
    noise.Set( 0.125, 0.5, 2.0, 4, 63*dudwa );
    
    #define ONETRIANGLESIZE 1.0f
    #define SIZEEEE_2 100.0f*ONETRIANGLESIZE
    #define SIZEEEE 100.0f*ONETRIANGLESIZE
    #define HEIGHT 15.0f
    
    for( float x = -SIZEEEE_2; x < SIZEEEE_2; x+=ONETRIANGLESIZE )
	{
    	for( float z = -SIZEEEE_2; z < SIZEEEE_2; z+=ONETRIANGLESIZE )
		{
			
			if( x > SIZEEEE || x < -SIZEEEE || z > SIZEEEE || z < -SIZEEEE )
			goto PHYSX_TRIANGLES;
			
			#undef SIZEEEE
			
			#define triangles game.engine.map.triTEXT
			
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
			triangles[ triangles.size()-1 ].texcoord[0][0] = 0.0f;
			triangles[ triangles.size()-1 ].texcoord[0][1] = 0.0f;
			triangles[ triangles.size()-1 ].texcoord[1][0] = 1.0f;
			triangles[ triangles.size()-1 ].texcoord[1][1] = 0.0f;
			triangles[ triangles.size()-1 ].texcoord[2][0] = 1.0f;
			triangles[ triangles.size()-1 ].texcoord[2][1] = 1.0f;
			triangles[ triangles.size()-1 ].texture = game.engine.map.texture[0].GetID();
			
			triangles[ triangles.size()-2 ].vertex[0][0] = x;
			triangles[ triangles.size()-2 ].vertex[0][1] = noise.GetHeight( (double)(x)/4.0, (double)(z)/4.0 ) * HEIGHT;
			triangles[ triangles.size()-2 ].vertex[0][2] = z;
			triangles[ triangles.size()-2 ].vertex[1][0] = x+ONETRIANGLESIZE;
			triangles[ triangles.size()-2 ].vertex[1][1] = noise.GetHeight( (double)(x+ONETRIANGLESIZE)/4.0, (double)(z+ONETRIANGLESIZE)/4.0 ) * HEIGHT;
			triangles[ triangles.size()-2 ].vertex[1][2] = z+ONETRIANGLESIZE;
			triangles[ triangles.size()-2 ].vertex[2][0] = x;
			triangles[ triangles.size()-2 ].vertex[2][1] = noise.GetHeight( (double)(x)/4.0, (double)(z+ONETRIANGLESIZE)/4.0 ) * HEIGHT;
			triangles[ triangles.size()-2 ].vertex[2][2] = z+ONETRIANGLESIZE;
			triangles[ triangles.size()-2 ].texcoord[0][0] = 0.0f;
			triangles[ triangles.size()-2 ].texcoord[0][1] = 0.0f;
			triangles[ triangles.size()-2 ].texcoord[1][0] = 1.0f;
			triangles[ triangles.size()-2 ].texcoord[1][1] = 1.0f;
			triangles[ triangles.size()-2 ].texcoord[2][0] = 0.0f;
			triangles[ triangles.size()-2 ].texcoord[2][1] = 1.0f;
			triangles[ triangles.size()-2 ].texture = game.engine.map.texture[0].GetID();
			
			#undef triangles
			#define triangles game.engine.map.triPHYS
			
			PHYSX_TRIANGLES:
			
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
			#undef triangles
			#define triangles game.engine.map.triTEXT
				
			triangles.resize( triangles.size()+1 );
			
			triangles[ triangles.size()-1 ].vertex[0][0] = -30.0f;
			triangles[ triangles.size()-1 ].vertex[0][1] = 100.0f;
			triangles[ triangles.size()-1 ].vertex[0][2] = 30.0f;
			triangles[ triangles.size()-1 ].vertex[1][0] = -30.0f;
			triangles[ triangles.size()-1 ].vertex[1][1] = 100.0f;
			triangles[ triangles.size()-1 ].vertex[1][2] = -30.0f;
			triangles[ triangles.size()-1 ].vertex[2][0] = 30.0f;
			triangles[ triangles.size()-1 ].vertex[2][1] = 100.0f;
			triangles[ triangles.size()-1 ].vertex[2][2] = 0.0f;
			triangles[ triangles.size()-1 ].texcoord[0][0] = 0.0f;
			triangles[ triangles.size()-1 ].texcoord[0][1] = 0.0f;
			triangles[ triangles.size()-1 ].texcoord[1][0] = 1.0f;
			triangles[ triangles.size()-1 ].texcoord[1][1] = 0.0f;
			triangles[ triangles.size()-1 ].texcoord[2][0] = 1.0f;
			triangles[ triangles.size()-1 ].texcoord[2][1] = 1.0f;
			triangles[ triangles.size()-1 ].texture = game.engine.map.texture[0].GetID();
			
			#undef triangles
			#define triangles game.engine.map.triPHYS
			
			triangles.resize( triangles.size()+1 );
			
			triangles[ triangles.size()-1 ].vertex[0][0] = -30.0f;
			triangles[ triangles.size()-1 ].vertex[0][1] = 100.0f;
			triangles[ triangles.size()-1 ].vertex[0][2] = 30.0f;
			triangles[ triangles.size()-1 ].vertex[1][0] = -30.0f;
			triangles[ triangles.size()-1 ].vertex[1][1] = 100.0f;
			triangles[ triangles.size()-1 ].vertex[1][2] = -30.0f;
			triangles[ triangles.size()-1 ].vertex[2][0] = 30.0f;
			triangles[ triangles.size()-1 ].vertex[2][1] = 100.0f;
			triangles[ triangles.size()-1 ].vertex[2][2] = 0.0f;
			triangles[ triangles.size()-2 ].normal = ( triangles[ triangles.size()-2 ].vertex[0] - triangles[ triangles.size()-2 ].vertex[1] ) && ( triangles[ triangles.size()-2 ].vertex[0] - triangles[ triangles.size()-2 ].vertex[2] );
			if( triangles[ triangles.size()-2 ].normal[1] < 0.0f )
				triangles[ triangles.size()-2 ].normal = 0.0f - triangles[ triangles.size()-2 ].normal;
			triangles[ triangles.size()-2 ].normal.Normalize();
			triangles[ triangles.size()-2 ].Calculate();
	
	
	
    game.engine.BeginLoop();
    
    while(1){Sleep(1100);}
    
    return 0;
}
