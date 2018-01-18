


inline void Chunk::Draw( Vector * cameraSrc )
{
	float length = SetVector( (x*X_CHUNK_SIZE)+(X_CHUNK_SIZE/2)-cameraSrc[0], 0.0f, (z*Z_CHUNK_SIZE)+(Z_CHUNK_SIZE/2)-cameraSrc[2] ).Lenght();
	if( length < renderDistance )
	{
		vbotex.Draw();
		vbocol.Draw();
		if( lenght < renderGraphicObjects )
		{
			int i;
			for( i = 0; i < graphicObjects.size(); i++ )
			{
				graphicObjects[i].Draw();
			}
		}
	}
}

inline void Chunk::ClearObjectCollider()
{
	if( colliderobj != NULL )
	{
		int x, z;
		for( x = 0; x < X_COLLIDERS_NUMBER; x++ )
		{
			if( colliderobj[x] != NULL )
			{
				for( z = 0; z < Z_COLLIDERS_NUMBER; z++ )
				{
					colliderobj[x][z].Clear();
				}
			}
		}
	}
}

inline void Chunk::GenerateDrawing()
{
	vbotex.Generate();
	vbocol.Generate();
}

inline void Chunk::GenerateColliders()
{
	int i;
	if( colliderter == NULL )
	{
		colliderter = new ColliderTerrain*[X_COLLIDERS_NUMBER];
		for( i = 0; i < X_COLLIDERS_NUMBER; i++ )
		{
			colliderter[i] = new ColliderTerrain[Z_COLLIDERS_NUMBER];
		}
	}
	if( colliderobj == NULL )
	{
		colliderobj = new ColliderObjects*[X_COLLIDERS_NUMBER];
		for( i = 0; i < X_COLLIDERS_NUMBER; i++ )
		{
			colliderobj[i] = new ColliderTerrain[Z_COLLIDERS_NUMBER];
		}
	}
}

inline void Chunk::Delete()
{
	int i;
	if( colliderter != NULL )
	{
		for( i = 0; i < X_COLLIDERS_NUMBER; i++ )
		{
			delete[] (colliderter[i]);
		}
		delete[] colliderter;
	}
	if( colliderobj != NULL )
	{
		for( i = 0; i < X_COLLIDERS_NUMBER; i++ )
		{
			delete[] (colliderobj[i]);
		}
		delete[] colliderobj;
	}
	vbotex.Delete();
	vbocol.Delete();
	triPHYS.resize( 0 );
	graphicObjects.resize( 0 );
}

Chunk::Chunk()
{
	colliderter = NULL;
	colliderobj = NULL;
	x = 0;
	z = 0;
}

Chunk::~Chunk()
{
	Delete();
}


