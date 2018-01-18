


inline void Map::UpdateTerrainColliders()
{
//	colliderter.Clear();
	
	float xmin = 0.0f, zmin = 0.0f;
	float xmax = 0.0f, zmax = 0.0f;
	float ymin = 0.0f, ymax = 0.0f;
	unsigned int i;
	
	for( i = 0; i < triPHYS.size(); i++ )	// looking for lower and heigher possition of triangles
	{
		if( xmin > triPHYS[i].vertex[0][0] )
			xmin = triPHYS[i].vertex[0][0];
		if( xmin > triPHYS[i].vertex[1][0] )
			xmin = triPHYS[i].vertex[1][0];
		if( xmin > triPHYS[i].vertex[2][0] )
			xmin = triPHYS[i].vertex[2][0];
			
		if( ymin > triPHYS[i].vertex[0][1] )
			ymin = triPHYS[i].vertex[0][1];
		if( ymin > triPHYS[i].vertex[1][1] )
			ymin = triPHYS[i].vertex[1][1];
		if( ymin > triPHYS[i].vertex[2][1] )
			ymin = triPHYS[i].vertex[2][1];
		
		if( zmin > triPHYS[i].vertex[0][2] )
			zmin = triPHYS[i].vertex[0][2];
		if( zmin > triPHYS[i].vertex[1][2] )
			zmin = triPHYS[i].vertex[1][2];
		if( zmin > triPHYS[i].vertex[2][2] )
			zmin = triPHYS[i].vertex[2][2];
		
		if( xmax < triPHYS[i].vertex[0][0] )
			xmax = triPHYS[i].vertex[0][0];
		if( xmax < triPHYS[i].vertex[1][0] )
			xmax = triPHYS[i].vertex[1][0];
		if( xmax < triPHYS[i].vertex[2][0] )
			xmax = triPHYS[i].vertex[2][0];
		
		if( ymax < triPHYS[i].vertex[0][1] )
			ymax = triPHYS[i].vertex[0][1];
		if( ymax < triPHYS[i].vertex[1][1] )
			ymax = triPHYS[i].vertex[1][1];
		if( ymax < triPHYS[i].vertex[2][1] )
			ymax = triPHYS[i].vertex[2][1];
		
		if( zmax < triPHYS[i].vertex[0][2] )
			zmax = triPHYS[i].vertex[0][2];
		if( zmax < triPHYS[i].vertex[1][2] )
			zmax = triPHYS[i].vertex[1][2];
		if( zmax < triPHYS[i].vertex[2][2] )
			zmax = triPHYS[i].vertex[2][2];
	}
	xmin -= 1.0f;
	ymin -= 1.0f;
	zmin -= 1.0f;
	xmax += 1.0f;
	ymax += 1.0f;
	zmax += 1.0f;
	
	colliderter.Init( SetVector( -127.0f, -100.0f, -127.0f ) );
/*	
	moveColliderTerrain[0] = xmin;
	moveColliderTerrain[1] = zmin;
	
    sizeColliderTerrain[0] = (xmax-xmin)/maxiumumnumberoftrianglescolliders[0];
    sizeColliderTerrain[1] = (zmax-zmin)/maxiumumnumberoftrianglescolliders[1];
	
	colliderter = new ColliderTerrain*[maxiumumnumberoftrianglescolliders[0]];
	for( i = 0; i < maxiumumnumberoftrianglescolliders[0]; i++ )
		*(colliderter+i) = new ColliderTerrain[maxiumumnumberoftrianglescolliders[1]];
*/	
	for( i = 0; i < triPHYS.size(); i++ )
	{
		#define V0 triPHYS[i].vertex[0]
		#define V1 triPHYS[i].vertex[1]
		#define V2 triPHYS[i].vertex[2]
		
		colliderter.Add(
							SetVector(
										Min( V0[0], V1[0], V2[0] ),
										Min( V0[1], V1[1], V2[1] ),
										Min( V0[2], V1[2], V2[2] )
									 ),
							SetVector(
										Max( V0[0], V1[0], V2[0] ),
										Max( V0[1], V1[1], V2[1] ),
										Max( V0[2], V1[2], V2[2] )
									 ),
							&(triPHYS[i])
						 );
		
		#undef V0
		#undef V1
		#undef V2
	}
}

inline void Map::UpdateObjectColliders()
{
	
}


