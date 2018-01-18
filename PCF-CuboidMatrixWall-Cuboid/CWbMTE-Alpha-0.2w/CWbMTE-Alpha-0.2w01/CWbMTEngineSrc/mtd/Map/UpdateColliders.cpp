


inline void Map::WaitWhileOperatingChunks()
{
	while( OperatingOnChunks == true ){ Sleep( 0 ); }
}

inline ColliderTerrain * Map::GetTerrainCollider( int x, int z )
{
	if( x < 0 || z < 0 || x >= NumberOfChunks[0]*X_COLLIDERS_NUMBER || z >= NumberOfChunks[1]*Z_COLLIDERS_NUMBER )
	{
		return NULL;
	}
	if( chunk[x/X_COLLIDERS_NUMBER][z/Z_COLLIDERS_NUMBER] != NULL )
	{
		return &( chunk[x/X_COLLIDERS_NUMBER][z/Z_COLLIDERS_NUMBER] -> colliderter[x%X_COLLIDERS_NUMBER][z%Z_COLLIDERS_NUMBER] );
	}
	return NULL;
}

inline ColliderObjects * Map::GetObjectCollider( int x, int z )
{
	if( x < 0 || z < 0 || x >= NumberOfChunks[0]*X_COLLIDERS_NUMBER || z >= NumberOfChunks[1]*Z_COLLIDERS_NUMBER )
	{
		return NULL;
	}
	if( chunk[x/X_COLLIDERS_NUMBER][z/Z_COLLIDERS_NUMBER] != NULL )
	{
		return &( chunk[x/X_COLLIDERS_NUMBER][z/Z_COLLIDERS_NUMBER] -> colliderobj[x%X_COLLIDERS_NUMBER][z%Z_COLLIDERS_NUMBER] );
	}
	return NULL;
}

inline bool Map::AddObjectToColliders( PhysicModelStatic * src )
{
	int i;
	ColliderObjects * collider = NULL;
	
	for( int x = int( (staticobject[i]->min[0])/sizeColliderObject[0] ); x < int( 1.0f+((staticobject[i]->max[0])/sizeColliderObject[0]) ); x++ )
	{
		for( int z = int( (staticobject[i]->min[2])/sizeColliderObject[1] ); z < int( 1.0f+((staticobject[i]->max[2])/sizeColliderObject[1]) ); z++ )
		{
			collider = GetObjectCollider( x, z );
			if( collider != NULL )
			{
				collider -> staticmodel.push_back( staticobject[i] );
			}
		}
	}	
}

inline void Map::UpdateObjectColliders()
{
	int i;
	
	WaitWhileOperatingChunks();
	OperatingOnChunks = true;
	
	for( i = 0; i < chunksContainer.size(); i++ )
	{
		if( chunksContainer[i] != NULL )
		{
			chunksContainer[i] -> ClearObjectCollider();
		}
	}
	
	for( i = 0; i < staticobject.size(); i++ )
	{
		if( staticobject[i] == NULL )
		{
			continue;
		}
		
		staticobject[i]->MainVectorId = i;
		
		AddObjectToColliders( staticobject[i] );
	}
	
	OperatingOnChunks = false;
}

inline void Map::DeleteChunk( int x, int z )
{
	WaitWhileOperatingChunks();
	OperatingOnChunks = true;
	
	if( chunk[x][z] != NULL )
	{
		chunk[x][z] -> Delete();
		int i;
		for( i = 0; i < chunksContainer.size(); i++ )
		{
			if( chunk[x][z] == chunksContainer[i] )
			{
				chunksContainer[i] = NULL;
				chunksContainer.erase( chunksContainer.begin() + i );
				i--;
			}
		}
		delete chunk[x][z];
		chunk[x][z] = NULL;
	}
	
	OperatingOnChunks = false;
}

inline bool Map::AddChunk( Chunk * src )
{
	if( src == NULL )
	{
		return false;
	}
	
	WaitWhileOperatingChunks();
	OperatingOnChunks = true;
	
	if( chunk[src->x][src->z] == NULL )
	{
		chunk[src->x][src->z] = src;
		chunksContainer.push_back( src );
	}
	else
	{
		OperatingOnChunks = false;
		return false;
	}
	
	OperatingOnChunks = false;
	return true;
}


