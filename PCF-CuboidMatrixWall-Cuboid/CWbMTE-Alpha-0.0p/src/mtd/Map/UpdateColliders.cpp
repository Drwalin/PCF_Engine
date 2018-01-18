


inline void Map::UpdateTerrainColliders()
{
	//float xmin = -100.0f, zmin = -100.0f;
	//float xmax = 100.0f, zmax = 100.0f;
	float xmin = 0.0f, zmin = 0.0f;
	float xmax = 0.0f, zmax = 0.0f;
	
	unsigned int i;
	
	for( i = 0; i < triPHYS.size(); i++ )	// looking for lower and heigher possition of triangles
	{
		if( xmin > triPHYS[i].vertex[0][0] )
			xmin = triPHYS[i].vertex[0][0];
		if( xmin > triPHYS[i].vertex[1][0] )
			xmin = triPHYS[i].vertex[1][0];
		if( xmin > triPHYS[i].vertex[2][0] )
			xmin = triPHYS[i].vertex[2][0];
		
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
		
		if( zmax < triPHYS[i].vertex[0][2] )
			zmax = triPHYS[i].vertex[0][2];
		if( zmax < triPHYS[i].vertex[1][2] )
			zmax = triPHYS[i].vertex[1][2];
		if( zmax < triPHYS[i].vertex[2][2] )
			zmax = triPHYS[i].vertex[2][2];
	}
	
	moveColliderTerrain[0] = xmin;
	moveColliderTerrain[1] = zmin;
	
    sizeColliderTerrain[0] = (xmax-xmin)/maxiumumnumberoftrianglescolliders[0];
    sizeColliderTerrain[1] = (zmax-zmin)/maxiumumnumberoftrianglescolliders[1];
	
	colliderter = new ColliderTerrain*[maxiumumnumberoftrianglescolliders[0]];
	for( i = 0; i < maxiumumnumberoftrianglescolliders[0]; i++ )
		*(colliderter+i) = new ColliderTerrain[maxiumumnumberoftrianglescolliders[1]];
	
	for( i = 0; i < triPHYS.size(); i++ )
	{
		if( xmin > triPHYS[i].vertex[0][0] )
			xmin = triPHYS[i].vertex[0][0];
		if( xmin > triPHYS[i].vertex[1][0] )
			xmin = triPHYS[i].vertex[1][0];
		if( xmin > triPHYS[i].vertex[2][0] )
			xmin = triPHYS[i].vertex[2][0];
		
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
		
		if( zmax < triPHYS[i].vertex[0][2] )
			zmax = triPHYS[i].vertex[0][2];
		if( zmax < triPHYS[i].vertex[1][2] )
			zmax = triPHYS[i].vertex[1][2];
		if( zmax < triPHYS[i].vertex[2][2] )
			zmax = triPHYS[i].vertex[2][2];
		
		for( int x = int( (xmin-moveColliderTerrain[0])/sizeColliderTerrain[0] ); x < int( 1.0f+((xmax-moveColliderTerrain[0])/sizeColliderTerrain[0]) ); x++ )
		{
			for( int z = int( (zmin-moveColliderTerrain[1])/sizeColliderTerrain[1] ); z < int( 1.0f+((zmax-moveColliderTerrain[1])/sizeColliderTerrain[1]) ); z++ )
			{
				if( x >= 0 && z >= 0 && x < maxiumumnumberoftrianglescolliders[0] && z < maxiumumnumberoftrianglescolliders[1] )
				{
					(*( colliderter+x )+z) -> tri.push_back( &triPHYS[i] );
				}
				else
				{
					(*colliderter) -> tri.push_back( &triPHYS[i] );
				}
			}
		}
	}
}

inline void Map::UpdateObjectColliders()
{
	
}


