




int main( int argc, char *argv[] )
{
    //Engine engine;
    engine.WindowFullScreen = true;
    
    engine.KeyboardFunction = KeyboardFunction;
    engine.GUIFunction = GUIFunction;
    
    engine.Init( &argc, argv );
    
    engine.map.texture.resize( 1 );
    engine.map.texture[0].LoadInit( "Media\\texture1.bmpx" );
    /*
    	load textures and models:
    */
    engine.AddGraphicModel( "TestModel.mdl" );
    
	engine.map.staticobject.resize( 5 );
	for( int i = 0; i < engine.map.staticobject.size(); i++ )
	{
		engine.map.staticobject[i].aabb.resize( 1 );
		engine.map.staticobject[i].aabb[0].size.Set( 0.6f, 1.75f, 0.6f );
		engine.map.staticobject[i].aabb[0].vel = &engine.map.staticobject[i].vel;
		engine.map.staticobject[i].aabb[0].force = &engine.map.staticobject[i].force;
		engine.map.staticobject[i].aabb[0].resistanceforce = &engine.map.staticobject[i].resistanceforce;
		engine.map.staticobject[i].pos.Set( 0.0f, 0.0f, 0.0f );
		engine.map.staticobject[i].see[1] = -90.0f;
		engine.map.staticobject[i].see[0] = -90.0f;
	}
    
    PerlinNoise noise;
    for( int dudwa = 1; dudwa < 2; dudwa++ )
    {
    noise.Set( 0.125, 0.5, 2.0, 4, 69*dudwa );
    
    #define SIZEEEE 20.0f
    #define HEIGHT 15.0f
    
    for( float x = -SIZEEEE; x < SIZEEEE; x+=1.0f )
	{
    	for( float z = -SIZEEEE; z < SIZEEEE; z+=1.0f )
		{
			#undef SIZEEEE
			
			#define triangles engine.map.triTEXT
				
			triangles.resize( triangles.size()+2 );
			
			triangles[ triangles.size()-1 ].vertex[0][0] = x;
			triangles[ triangles.size()-1 ].vertex[0][1] = noise.GetHeight( (double)(x)/4.0, (double)(z)/4.0 ) * HEIGHT;
			triangles[ triangles.size()-1 ].vertex[0][2] = z;
			triangles[ triangles.size()-1 ].vertex[1][0] = x+1.0f;
			triangles[ triangles.size()-1 ].vertex[1][1] = noise.GetHeight( (double)(x+1.0)/4.0, (double)(z)/4.0 ) * HEIGHT;
			triangles[ triangles.size()-1 ].vertex[1][2] = z;
			triangles[ triangles.size()-1 ].vertex[2][0] = x+1.0f;
			triangles[ triangles.size()-1 ].vertex[2][1] = noise.GetHeight( (double)(x+1.0)/4.0, (double)(z+1.0)/4.0 ) * HEIGHT;
			triangles[ triangles.size()-1 ].vertex[2][2] = z+1.0f;
			triangles[ triangles.size()-1 ].texcoord[0][0] = 0.0f;
			triangles[ triangles.size()-1 ].texcoord[0][1] = 0.0f;
			triangles[ triangles.size()-1 ].texcoord[1][0] = 1.0f;
			triangles[ triangles.size()-1 ].texcoord[1][1] = 0.0f;
			triangles[ triangles.size()-1 ].texcoord[2][0] = 1.0f;
			triangles[ triangles.size()-1 ].texcoord[2][1] = 1.0f;
			triangles[ triangles.size()-1 ].texture = engine.map.texture[0].GetID();
			
			triangles[ triangles.size()-2 ].vertex[0][0] = x;
			triangles[ triangles.size()-2 ].vertex[0][1] = noise.GetHeight( (double)(x)/4.0, (double)(z)/4.0 ) * HEIGHT;
			triangles[ triangles.size()-2 ].vertex[0][2] = z;
			triangles[ triangles.size()-2 ].vertex[1][0] = x+1.0f;
			triangles[ triangles.size()-2 ].vertex[1][1] = noise.GetHeight( (double)(x+1.0)/4.0, (double)(z+1.0)/4.0 ) * HEIGHT;
			triangles[ triangles.size()-2 ].vertex[1][2] = z+1.0f;
			triangles[ triangles.size()-2 ].vertex[2][0] = x;
			triangles[ triangles.size()-2 ].vertex[2][1] = noise.GetHeight( (double)(x)/4.0, (double)(z+1.0)/4.0 ) * HEIGHT;
			triangles[ triangles.size()-2 ].vertex[2][2] = z+1.0f;
			triangles[ triangles.size()-2 ].texcoord[0][0] = 0.0f;
			triangles[ triangles.size()-2 ].texcoord[0][1] = 0.0f;
			triangles[ triangles.size()-2 ].texcoord[1][0] = 1.0f;
			triangles[ triangles.size()-2 ].texcoord[1][1] = 1.0f;
			triangles[ triangles.size()-2 ].texcoord[2][0] = 0.0f;
			triangles[ triangles.size()-2 ].texcoord[2][1] = 1.0f;
			triangles[ triangles.size()-2 ].texture = engine.map.texture[0].GetID();
			
			#undef triangles
			#define triangles engine.map.triPHYS
				
			triangles.resize( triangles.size()+2 );
			
			triangles[ triangles.size()-1 ].vertex[0][0] = x;
			triangles[ triangles.size()-1 ].vertex[0][1] = noise.GetHeight( (double)(x)/4.0, (double)(z)/4.0 ) * HEIGHT;
			triangles[ triangles.size()-1 ].vertex[0][2] = z;
			triangles[ triangles.size()-1 ].vertex[1][0] = x+1.0f;
			triangles[ triangles.size()-1 ].vertex[1][1] = noise.GetHeight( (double)(x+1.0)/4.0, (double)(z)/4.0 ) * HEIGHT;
			triangles[ triangles.size()-1 ].vertex[1][2] = z;
			triangles[ triangles.size()-1 ].vertex[2][0] = x+1.0f;
			triangles[ triangles.size()-1 ].vertex[2][1] = noise.GetHeight( (double)(x+1.0)/4.0, (double)(z+1.0)/4.0 ) * HEIGHT;
			triangles[ triangles.size()-1 ].vertex[2][2] = z+1.0f;
			triangles[ triangles.size()-1 ].normal = ( triangles[ triangles.size()-1 ].vertex[0] - triangles[ triangles.size()-1 ].vertex[1] ) && ( triangles[ triangles.size()-1 ].vertex[0] - triangles[ triangles.size()-1 ].vertex[2] );
			if( triangles[ triangles.size()-1 ].normal[1] < 0.0f )
				triangles[ triangles.size()-1 ].normal = 0.0f - triangles[ triangles.size()-1 ].normal;
			triangles[ triangles.size()-1 ].normal.Normalize();
			
			triangles[ triangles.size()-2 ].vertex[0][0] = x;
			triangles[ triangles.size()-2 ].vertex[0][1] = noise.GetHeight( (double)(x)/4.0, (double)(z)/4.0 ) * HEIGHT;
			triangles[ triangles.size()-2 ].vertex[0][2] = z;
			triangles[ triangles.size()-2 ].vertex[1][0] = x+1.0f;
			triangles[ triangles.size()-2 ].vertex[1][1] = noise.GetHeight( (double)(x+1.0)/4.0, (double)(z+1.0)/4.0 ) * HEIGHT;
			triangles[ triangles.size()-2 ].vertex[1][2] = z+1.0f;
			triangles[ triangles.size()-2 ].vertex[2][0] = x;
			triangles[ triangles.size()-2 ].vertex[2][1] = noise.GetHeight( (double)(x)/4.0, (double)(z+1.0)/4.0 ) * HEIGHT;
			triangles[ triangles.size()-2 ].vertex[2][2] = z+1.0f;
			triangles[ triangles.size()-2 ].normal = ( triangles[ triangles.size()-2 ].vertex[0] - triangles[ triangles.size()-2 ].vertex[1] ) && ( triangles[ triangles.size()-2 ].vertex[0] - triangles[ triangles.size()-2 ].vertex[2] );
			if( triangles[ triangles.size()-2 ].normal[1] < 0.0f )
				triangles[ triangles.size()-2 ].normal = 0.0f - triangles[ triangles.size()-2 ].normal;
			triangles[ triangles.size()-2 ].normal.Normalize();
		}
	}
	}
    engine.BeginLoop();
    
    while(1){Sleep(1100);}
    
    return 0;
}
