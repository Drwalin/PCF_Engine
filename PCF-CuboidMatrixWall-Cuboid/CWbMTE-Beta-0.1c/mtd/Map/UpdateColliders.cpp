


inline void Map::UpdateTerrainColliders()
{
	float xmin = 10000000.0f, zmin = 1000000.0f;
	float xmax = -1000000.0f, zmax = -100000.0f;
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
	
    sizeColliderTerrain[0] = ((float)(xmax-xmin)/(float)maximumnumberoftrianglescolliders[0]);
    sizeColliderTerrain[1] = ((float)(zmax-zmin)/(float)maximumnumberoftrianglescolliders[1]);
	
	if( colliderter != NULL )
	{
		for( i = 0; i < maximumnumberoftrianglescolliders[0]; i++ )
		{
			if( *(colliderter+i) != NULL )
			{
				delete[] (*(colliderter+i));
			}
		}
		delete[] colliderter;
	}
	
	{
		colliderter = new ColliderTerrain*[maximumnumberoftrianglescolliders[0]];
		for( i = 0; i < maximumnumberoftrianglescolliders[0]; i++ )
		{
			*(colliderter+i) = new ColliderTerrain[maximumnumberoftrianglescolliders[1]];
		}
	}
	
	////////////////////////////////////////////////
	////////////////////////////////////////////////
	if( colliderobj != NULL )
	{
		for( i = 0; i < maximumnumberofobjectcolliders[0]; i++ )
		{
			if( *(colliderobj+i) != NULL )
			{
				delete[] (*(colliderobj+i));
			}
		}
		delete[] colliderobj;
	}
	
	{	// creating objects colliders:
		moveColliderObject[0] = moveColliderTerrain[0] - 10.0f;
		moveColliderObject[1] = moveColliderTerrain[1] - 10.0f;
		sizeColliderObject[0] = ((float)(20.0f+xmax-xmin)/(float)maximumnumberofobjectcolliders[0]);
		sizeColliderObject[1] = ((float)(20.0f+zmax-zmin)/(float)maximumnumberofobjectcolliders[1]);
		
		colliderobj = new ColliderObjects*[maximumnumberofobjectcolliders[0]];
		for( i = 0; i < maximumnumberofobjectcolliders[0]; i++ )
			*(colliderobj+i) = new ColliderObjects[maximumnumberofobjectcolliders[1]];
	}
	////////////////////////////////////////////////
	////////////////////////////////////////////////
	
	for( i = 0; i < triPHYS.size(); i++ )
	{
		//if( xmin > triPHYS[i].vertex[0][0] )
			xmin = triPHYS[i].vertex[0][0];
		if( xmin > triPHYS[i].vertex[1][0] )
			xmin = triPHYS[i].vertex[1][0];
		if( xmin > triPHYS[i].vertex[2][0] )
			xmin = triPHYS[i].vertex[2][0];
		
		//if( zmin > triPHYS[i].vertex[0][2] )
			zmin = triPHYS[i].vertex[0][2];
		if( zmin > triPHYS[i].vertex[1][2] )
			zmin = triPHYS[i].vertex[1][2];
		if( zmin > triPHYS[i].vertex[2][2] )
			zmin = triPHYS[i].vertex[2][2];
		
		//if( xmax < triPHYS[i].vertex[0][0] )
			xmax = triPHYS[i].vertex[0][0];
		if( xmax < triPHYS[i].vertex[1][0] )
			xmax = triPHYS[i].vertex[1][0];
		if( xmax < triPHYS[i].vertex[2][0] )
			xmax = triPHYS[i].vertex[2][0];
		
		//if( zmax < triPHYS[i].vertex[0][2] )
			zmax = triPHYS[i].vertex[0][2];
		if( zmax < triPHYS[i].vertex[1][2] )
			zmax = triPHYS[i].vertex[1][2];
		if( zmax < triPHYS[i].vertex[2][2] )
			zmax = triPHYS[i].vertex[2][2];
		
		for( int x = int( (xmin-moveColliderTerrain[0])/sizeColliderTerrain[0] ); x < int( 1.0f+((xmax-moveColliderTerrain[0])/sizeColliderTerrain[0]) ); x++ )
		{
			for( int z = int( (zmin-moveColliderTerrain[1])/sizeColliderTerrain[1] ); z < int( 1.0f+((zmax-moveColliderTerrain[1])/sizeColliderTerrain[1]) ); z++ )
			{
				if( x >= 0 && z >= 0 && x < maximumnumberoftrianglescolliders[0] && z < maximumnumberoftrianglescolliders[1] )
				{
					(*( colliderter+x )+z) -> tri.push_back( &triPHYS[i] );
				}
			}
		}
	}
}

inline void Map::UpdateObjectColliders()
{
	int x, z, i;
	
	for( x = 0; x < maximumnumberofobjectcolliders[0]; x++ )
	{
		for( z = 0; z < maximumnumberofobjectcolliders[1]; z++ )
		{
			(*( colliderobj+x )+z) -> staticmodel.resize( 0 );
		}
	}
	
	for( i = 0; i < staticobject.size(); i++ )
	{
		staticobject[i]->MainVectorId = i;
		for( int x = int( (staticobject[i]->min[0]-moveColliderObject[0])/sizeColliderObject[0] ); x < int( 1.0f+((staticobject[i]->max[0]-moveColliderObject[0])/sizeColliderObject[0]) ); x++ )
		{
			for( int z = int( (staticobject[i]->min[2]-moveColliderObject[1])/sizeColliderObject[1] ); z < int( 1.0f+((staticobject[i]->max[2]-moveColliderObject[1])/sizeColliderObject[1]) ); z++ )
			{
				if( x >= 0 && z >= 0 && x < maximumnumberofobjectcolliders[0] && z < maximumnumberofobjectcolliders[1] )
				{
					(*( colliderobj+x )+z) -> staticmodel.push_back( staticobject[i] );
				}
				else
				{
					colliderobjectout.staticmodel.push_back( staticobject[i] );
				}
			}
		}
	}
}

inline void Map::DestroyColliders()
{
	int i;
	
	if( colliderter != NULL )
	{
		for( i = 0; i < maximumnumberoftrianglescolliders[0]; i++ )
		{
			if( *(colliderter+i) != NULL )
			{
				delete[] (*(colliderter+i));
			}
		}
		delete[] colliderter;
		colliderter = NULL;
	}
	
	if( colliderobj != NULL )
	{
		for( i = 0; i < maximumnumberofobjectcolliders[0]; i++ )
		{
			if( *(colliderobj+i) != NULL )
			{
				delete[] (*(colliderobj+i));
			}
		}
		delete[] colliderobj;
		colliderobj = NULL;
	}
	
	triPHYS.resize( 0 );
}


