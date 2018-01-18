


#define EPSILON 0.01f

inline int Map::SegmentCollision( Vector p1, Vector p2, PhysicModelStatic ** object, TrianglePX ** triangle )
{
	/*
	*object = NULL;
	*triangle = NULL;
	Collision collision;
	
	Vector direction = p2 - p1;
	float lenght = direction.Lenght();
	lenght += EPSILON;
	direction.Normalize();
	
	float t;
	
	int bxt[2] = { -6666, -6666 };
	int bxo[2] = { -6666, -6666 };
	int nxt[2];
	int nxo[2];
	
	int i;
	
	for( t = 0.0f; t < lenght; t += EPSILON )
	{
		nxt[0] = int( ( (p1 + ( direction * t ))[0] - moveColliderTerrain[0] ) / sizeColliderTerrain[0] );
		nxt[0] = int( ( (p1 + ( direction * t ))[2] - moveColliderTerrain[1] ) / sizeColliderTerrain[1] );
		
		nxo[0] = int( ( (p1 + ( direction * t ))[0] - moveColliderObject[0] ) / sizeColliderObject[0] );
		nxo[0] = int( ( (p1 + ( direction * t ))[2] - moveColliderObject[1] ) / sizeColliderObject[1] );
		
		if( ( nxt[0] != bxt[0] || nxt[1] != bxt[1] ) && nxt[0] >= 0 && nxt[1] >= 0 && nxt[0] < maxiumumnumberoftrianglescolliders[0] && nxt[1] < maxiumumnumberoftrianglescolliders[1] )
		{
			bxt[0] = nxt[0];
			bxt[1] = nxt[1];
			
			for( i = 0; i < colliderter[nxt[0]][nxt[1]].tri.size(); i++ )
			{
				if( (*triangle) == NULL )
				{
					if( colliderter[nxt[0]][nxt[1]].tri[i] -> PointIn( p1, p2 ) )
					{
						*triangle = colliderter[nxt[0]][nxt[1]].tri[i];
					}
				}
				else
				{
					if( colliderter[nxt[0]][nxt[1]].tri[i] -> PointIn( p1, p2 ) )
					{
////////////////////	t = (-d-N*b) / (N*v)
						
						if( 
							( ( - colliderter[nxt[0]][nxt[1]].tri[i]->det - ( colliderter[nxt[0]][nxt[1]].tri[i]->normal.Dot( p1 ) ) ) / ( colliderter[nxt[0]][nxt[1]].tri[i]->normal.Dot( direction ) ) )
							<
							( ( - (*triangle)->det - ( (*triangle)->normal.Dot( p1 ) ) ) / ( (*triangle)->normal.Dot( direction ) ) )
						)
						{
							*triangle = colliderter[nxt[0]][nxt[1]].tri[i];
						}
					}
				}
			}
		}
		
		if( *triangle != NULL )
		{
			return 1;
		}
//		if( *object != NULL )
//		{
//			return 1;
//		}
	}
	
	return 0;
}
	
	*/
	
	
	
	
	
	*object = NULL;
	*triangle = NULL;
	Collision collision;
	
	Vector fastv1, fastv2;
	float dot;
	
	Vector direction = (p2-p1);
	float lenght = direction.Lenght();
	direction.Normalize();
	int i, j;
	
	float t;
	
	lenght += EPSILON;
	
	int objs[2] = { -666, -666 };
	int tris[2] = { -666, -666 };
	
	int pobjs[2];
	int ptris[2];
	
	
	for( t = 0.0f; t < lenght; t += EPSILON )
	{
		pobjs[0] = int(float((((p1+(direction*t))[0]) - (moveColliderObject[0])) / (sizeColliderObject[0])));
		pobjs[1] = int(float((((p1+(direction*t))[2]) - (moveColliderObject[1])) / (sizeColliderObject[1])));
		
		ptris[0] = int(float((((p1+(direction*t))[0]) - (moveColliderTerrain[0])) / (sizeColliderTerrain[0])));
		ptris[1] = int(float((((p1+(direction*t))[2]) - (moveColliderTerrain[1])) / (sizeColliderTerrain[1])));
		
		
		if( ( ptris[0] != tris[0] || ptris[1] != tris[1] ) && ptris[0] < maxiumumnumberoftrianglescolliders[0] && ptris[1] < maxiumumnumberoftrianglescolliders[1] && ptris[0] >= 0 && ptris[1] >= 0 )
		{	// Check triangles
			tris[0] = ptris[0];
			tris[1] = ptris[1];
			
//			printf( "\n %i %i", tris[0], tris[1] );
			
			for( i = 0; i < colliderter[tris[0]][tris[1]].tri.size(); i++ )
			{
//				if( colliderter[tris[0]][tris[1]].tri[i] != *triangle )
				{
					if( colliderter[tris[0]][tris[1]].tri[i] -> PointIn( p1, p2 ) == true )//collision.RayTriangle( p1, p2, colliderter[tris[0]][tris[1]].tri[i] ) == true )
					{
						if( *triangle == NULL )
						{
//							if( colliderter[tris[0]][tris[1]].tri[i] -> normal.Dot( direction ) != 0.0f )
							{
								*triangle = colliderter[tris[0]][tris[1]].tri[i];
							}
							continue;
						}
						else
						{
							dot = colliderter[tris[0]][tris[1]].tri[i]->normal.Dot( direction );
							if( dot != 0.0f )
							{
								dot = ( ( - colliderter[tris[0]][tris[1]].tri[i]->det - colliderter[tris[0]][tris[1]].tri[i]->normal.Dot( p1 ) ) / dot );
								
								if( dot < ( ( - (*triangle)->det - (*triangle)->normal.Dot( p1 ) ) / ( (*triangle)->normal.Dot( direction ) ) ) )
								{
									*triangle = colliderter[tris[0]][tris[1]].tri[i];
								}
							}
						}
					}
				}
			}
		}
		
		if( *triangle != NULL )
		{
			return COLLISION_WITH_TRIANGLE;
		}
		if( *object != NULL )
		{
			return COLLISION_WITH_OBJECT;
		}
	}
	return COLLISION_NO;
}


#undef EPSILON


