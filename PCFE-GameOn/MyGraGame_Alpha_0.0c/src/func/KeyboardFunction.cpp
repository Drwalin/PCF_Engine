



Vector wsl, wsh;

void GenerateMap___New()
{
	GameInstantiation->engine.AddVBO( GameInstantiation->engine.TextureId( "textmodel" ) );
	
	float x, z;
	float minx = -200.0f, minz = -200.0f, maxx = 200.0f, maxz = 200.0f;
	
	float size = 2.0f;
	/*
	printf( "\n minx: " );
	scanf( "%f", &minx );
	printf( " minz: " );
	scanf( "%f", &minz );
	printf( " maxx: " );
	scanf( "%f", &maxx );
	printf( " maxz: " );
	scanf( "%f", &maxz );
	
	printf( " size: " );
	scanf( "%f", &size );
	*/
	
	wsl[0] = minx + 1;
	wsl[2] = minz + 1;
	wsh[0] = maxx - 1;
	wsh[2] = maxz - 1;
	
	Vector a, b, c, normal;
	
	srand( time( NULL ) );
	
	PerlinNoise hmap, hmap2;
	hmap.Set(  0.125, 0.25, 4.0, 4, 124 );
	hmap2.Set( 0.125, 0.01, 32.0, 4, 241 );
	
	for( x = minx; x < maxx; x += size )
	{
		for( z = minz; z < maxz; z += size )
		{
			#define getheight(x,z) ((hmap.GetHeight( x+500.0f, z+500.0f )+1.0f))+((hmap2.GetHeight( (x+500.0f), (z+500.0f) )+1.0f))
			GameInstantiation->engine.AddVertexToLastVBO( x,      getheight(x,z), z,					(x)*0.1f,		(z)*0.1f );
			GameInstantiation->engine.AddVertexToLastVBO( x+size, getheight(x+size,z), z,				(x+size)*0.1f,	(z)*0.1f );
			GameInstantiation->engine.AddVertexToLastVBO( x+size, getheight(x+size,z+size), z+size,	(x+size)*0.1f,	(z+size)*0.1f );
			GameInstantiation->engine.CreateTriangleWithLastThreeVertices();
			
			GameInstantiation->engine.AddVertexToLastVBO( x,      getheight(x,z), z,					(x)*0.1f,		(z)*0.1f );
			GameInstantiation->engine.AddVertexToLastVBO( x,      getheight(x,z+size), z+size,		(x)*0.1f,		(z+size)*0.1f );
			GameInstantiation->engine.AddVertexToLastVBO( x+size, getheight(x+size,z+size), z+size,	(x+size)*0.1f,	(z+size)*0.1f );
			GameInstantiation->engine.CreateTriangleWithLastThreeVertices();
			
			a.Set( x,      getheight(x,z), z );
			b.Set( x+size, getheight(x+size,z), z );
			c.Set( x+size, getheight(x+size,z+size), z+size );
			normal = ( a - b ) && ( a - c );
			if( normal[1] < 0.0f )
				normal = 0.0f - normal;
			normal.Normalize();
			GameInstantiation->engine.AddPhysicTriangle( a, b, c, normal );
			
			a.Set( x,      getheight(x,z), z );
			b.Set( x,      getheight(x,z+size), z+size );
			c.Set( x+size, getheight(x+size,z+size), z+size );
			normal = ( a - b ) && ( a - c );
			if( normal[1] < 0.0f )
				normal = 0.0f - normal;
			normal.Normalize();
			GameInstantiation->engine.AddPhysicTriangle( a, b, c, normal );
		}
	}
	
	PerlinNoise hmap3;
	hmap3.Set( 0.125, 0.011, 32.0, 1, 898 );
	
/*	int numb = 0;
	
	int mingen = 0;
	printf( "\n Flowers percentage: " );
	scanf( "%i", &mingen );
	
	GameInstantiation->engine.AddVBO( GameInstantiation->engine.TextureId( "Flower1" ) );
	
	VMatrix matrix;
	Vector pos;
	float rotatex;
	float scale;
	
	StaticGraphicModel * pointer = GameInstantiation->engine.GetStaticModelHandle( "Flower1" );
	
	int i;
	
	for( x = minx; x < maxx; x += size*0.05f )
	{
		for( z = minz; z < maxz; z += size*0.05f )
		{
			if( rand() < mingen && hmap3.GetHeight( x, z ) > 0.0f )
			{
				scale = float((rand()%1000)+500)/500.0f;
				rotatex = rand()%1000;
				
				pos.Set( x, getheight(x,z)+scale*0.49f, z );
				
				GameInstantiation->engine.AddGraphicObject( pointer, pos, SetVector( 0.0f, rotatex, 0.0f ), scale );
				
				numb++;
			}
		}
	}
	
	printf( "\n flowers number: %i", numb );
//	getch();
	*/
	
	GameInstantiation->engine.UpdateWorld();
//	printf( "\n done updating: %i" );
}















void KeyboardFunction( float FrameTime )
{
	int i;
	
	for( i = 0; i < engineInstantiation->ObjectsNumber(); i++ )
	{
		if( engineInstantiation->Object(i)->pos[0] < wsl[0] )
			engineInstantiation->Object(i)->pos[0] = wsl[0];
		if( engineInstantiation->Object(i)->pos[2] < wsl[2] )
			engineInstantiation->Object(i)->pos[2] = wsl[2];
		if( engineInstantiation->Object(i)->pos[0] > wsh[0] )
			engineInstantiation->Object(i)->pos[0] = wsh[0];
		if( engineInstantiation->Object(i)->pos[2] > wsh[2] )
			engineInstantiation->Object(i)->pos[2] = wsh[2];
	}
	
	keyboardobiect.Update();
	
	VMatrix matrix;
	matrix.InitEmpty();
	matrix.RotateY( (engineInstantiation->Object(0)->see[0]+90.0f) );
//	matrix.RotateX( engineInstantiation->Object(0)->see[1] );
	Vector forward;
	#define FORCE_DEFINE 3000.0f
	#define MAX_VELOCITY_DEFINE 2.5f
	forward.Set( 0.0f, 0.0f, FORCE_DEFINE );// * (float( engineInstantiation->Object(0)->aabb[0].CollisionDown ? 1.0f : 0.1f )) );
	
	/*
	GameInstantiation->LookLeft;
	GameInstantiation->LookUp;
	GameInstantiation->LookRight;
	GameInstantiation->LookDown;
	GameInstantiation->PrimaryAttack;
	GameInstantiation->SecondaryAttack;
	GameInstantiation->Zoom;
	GameInstantiation->Run;
	GameInstantiation->Sneak;
	*/
	
	
	if( keyboardobiect.downkeypressed[ 'P' ] )		// 'P'
	{
		GameInstantiation->UseMouse = !GameInstantiation->UseMouse;
	}
	
	if( keyboardobiect.downkeypressed[ 0x02 ] )//GameInstantiation->SecondaryAttack] )
	{
		AddLightings++;
	}
	
	
	if( keyboardobiect.keypressed[GameInstantiation->MoveForward] ) // 'W'
	{
		if( engineInstantiation->Object(0)->vel.Dot( matrix.GetVertex( forward )/(forward.Lenght()) ) <= MAX_VELOCITY_DEFINE )
			engineInstantiation->Object(0)->force += matrix.GetVertex( forward );
	}
	if( keyboardobiect.keypressed[GameInstantiation->MoveBackward] ) // 'S'
	{
		if( engineInstantiation->Object(0)->vel.Dot( 0.0f-matrix.GetVertex( forward )/(forward.Lenght()) ) <= MAX_VELOCITY_DEFINE )
			engineInstantiation->Object(0)->force -= matrix.GetVertex( forward );
	}
	if( keyboardobiect.keypressed[GameInstantiation->StrafeLeft] ) // 'A'
	{
		if( engineInstantiation->Object(0)->vel.Dot( matrix.GetVertex( SetVector( +FORCE_DEFINE, 0.0f, 0.0f ) )/(forward.Lenght()) ) <= MAX_VELOCITY_DEFINE )
		{
			engineInstantiation->Object(0)->force[0] += cos( (engineInstantiation->Object(0)->see[0] + 90.0f) *M_PI/180.0f) * FORCE_DEFINE;
			engineInstantiation->Object(0)->force[2] += -sin( (engineInstantiation->Object(0)->see[0] + 90.0f) *M_PI/180.0f) * FORCE_DEFINE;
		}
	}
	if( keyboardobiect.keypressed[GameInstantiation->StrafeRight] ) // 'D'
	{
		if( engineInstantiation->Object(0)->vel.Dot( matrix.GetVertex( SetVector( -FORCE_DEFINE, 0.0f, 0.0f ) )/(forward.Lenght()) ) <= MAX_VELOCITY_DEFINE )
		{
			engineInstantiation->Object(0)->force[0] += cos( (engineInstantiation->Object(0)->see[0] + 270.0f) *M_PI/180.0f) * FORCE_DEFINE;
			engineInstantiation->Object(0)->force[2] += -sin( (engineInstantiation->Object(0)->see[0] + 270.0f) *M_PI/180.0f) * FORCE_DEFINE;
		}
	}
	if( engineInstantiation->Object(0)->aabb[0].CollisionDown && keyboardobiect.keypressed[GameInstantiation->Jump] )
	{
		engineInstantiation->Object(0)->vel[1] = 4.5f;
	}
	if( keyboardobiect.keypressed[GameInstantiation->Crouch] || engineInstantiation->Object(0)->aabb[0].CollisionUp )
	{
		if( keyboardobiect.downkeypressed[GameInstantiation->Crouch] )
			engineInstantiation->Object(0)->vel[1] += 1.5f;
		engineInstantiation->Object(0)->aabb[0].size[1] = 1.0f;
	}
	else
	{
		if( keyboardobiect.upkeypressed[GameInstantiation->Crouch] )
			engineInstantiation->Object(0)->vel[1] -= 1.5f;
		engineInstantiation->Object(0)->aabb[0].size[1] = 1.75f;
	}
}


