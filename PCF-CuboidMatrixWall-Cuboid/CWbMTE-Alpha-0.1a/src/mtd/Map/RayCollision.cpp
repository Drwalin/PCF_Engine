


#define EPSILON 0.5f

inline int Map::SegmentCollision( Vector p1, Vector p2, PhysicModelStatic ** object, TrianglePX ** triangle )
{
	*object = NULL;
	*triangle = NULL;
	Collision collision;
	
	Vector fastv1, fastv2;
	float dot;
	
	Vector direction = (p2-p1);
	Vector actualpoint;
	float lenght = direction.Lenght();
	direction *= 1.0f/lenght;
	int i, j;
	
	float t;
	
	lenght += EPSILON;
	
	int objs[2] = { -666, -666 };
	int tris[2] = { -666, -666 };
	
	int pobjs[2];
	int ptris[2];
	
	for( t = 0.0f; t < lenght; t += EPSILON )
	{
		
		
		pobjs[0] = int((((p1+(direction*t))[0]) - (moveColliderObject[0])) / (sizeColliderObject[0]));
		pobjs[1] = int((((p1+(direction*t))[2]) - (moveColliderObject[1])) / (sizeColliderObject[1]));
		
		ptris[0] = int((((p1+(direction*t))[0]) - (moveColliderTerrain[0])) / (sizeColliderTerrain[0]));
		ptris[1] = int((((p1+(direction*t))[2]) - (moveColliderTerrain[1])) / (sizeColliderTerrain[1]));
		
		/*
		if( ( pobjs[0] != objs[0] || pobjs[1] != objs[1] ) && objs[0] < maxiumumnumberofobjectcolliders[0] && objs[1] < maxiumumnumberofobjectcolliders[1] && objs[0] >= 0 && objs[1] >= 0 )
		{	// Check objects
			objs[0] = pobjs[0];
			objs[1] = pobjs[1];
			for( i = 0; i < colliderobj[objs[0]][objs[1]].staticmodel.size(); i++ )
			{
				for( j = 0; j < colliderobj[objs[0]][objs[1]].staticmodel[i] -> aabb.size(); j++ )
				{
					if( collision.RayAABB( p1, p2, &(colliderobj[objs[0]][objs[1]].staticmodel[i] -> pos), &(colliderobj[objs[0]][objs[1]].staticmodel[i] -> aabb[j]) ) == COLLISION_IS )
					{
						if( *object == NULL )
						{
							*object = colliderobj[objs[0]][objs[1]].staticmodel[i];
							continue;
						}
						else if( *object != colliderobj[objs[0]][objs[1]].staticmodel[i] );
						{
							fastv1 = (*object) -> aabb[0].ClosesPoint( p1 - (*object) -> pos );
							fastv2 = colliderobj[objs[0]][objs[1]].staticmodel[i] -> aabb[0].ClosesPoint( p1 - colliderobj[objs[0]][objs[1]].staticmodel[i] -> pos );
							
							if( (fastv1+(*object) -> pos).Lenght() > (fastv2+colliderobj[objs[0]][objs[1]].staticmodel[i] -> pos).Lenght() )
							{
								*object = colliderobj[objs[0]][objs[1]].staticmodel[i];
							}
						}
					}
				}
			}
		}
		*/
		
		if( ( ptris[0] != tris[0] || ptris[1] != tris[1] ) && tris[0] < maxiumumnumberoftrianglescolliders[0] && tris[1] < maxiumumnumberoftrianglescolliders[1] && tris[0] >= 0 && tris[1] >= 0 )
		{	// Check triangles
			tris[0] = ptris[0];
			tris[1] = ptris[1];
			for( i = 0; i < colliderter[tris[0]][tris[1]].tri.size(); i++ )
			{
				if( collision.RayTriangle( p1, p2, (TrianglePX*)(colliderter[tris[0]][tris[1]].tri[i]) ) == true )
				{
					if( *triangle == NULL )
					{
						printf("A");
						if( colliderter[tris[0]][tris[1]].tri[i] -> normal.Dot( direction ) )
							*triangle = colliderter[tris[0]][tris[1]].tri[i];
						continue;
					}
					else
					{
						dot = colliderter[tris[0]][tris[1]].tri[i]->normal.Dot( direction );
						if( dot != 0.0f )
							dot = ( colliderter[tris[0]][tris[1]].tri[i]->normal.Dot( p1-(colliderter[tris[0]][tris[1]].tri[i]->vertex[0]) ) / dot );
						
						if( dot < ( (*triangle)->normal.Dot( p1-((*triangle)->vertex[0]) ) / ( (*triangle)->normal.Dot( direction ) ) ) )
							*triangle = colliderter[tris[0]][tris[1]].tri[i];
					}
				}
			}
		}
		
		if( *object != NULL )
		{
			return COLLISION_WITH_OBJECT;
		}
		if( *triangle != NULL )
		{
			return COLLISION_WITH_TRIANGLE;
		}
	}
	return COLLISION_NO;
}

#undef EPSILON


