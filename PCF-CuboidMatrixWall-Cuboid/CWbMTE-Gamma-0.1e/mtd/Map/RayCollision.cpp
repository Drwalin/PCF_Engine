


#define EPSILON 0.1f

inline int Map::SegmentCollision( Vector p1, Vector p2, PhysicModelStatic ** object, TrianglePX ** triangle, PhysicModelStatic * decludingobject, unsigned int rayTypeSrc )
{
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
	
	int pobjs[2] = { -666, -666 };
	int ptris[2] = { -666, -666 };
	
	Vector ContactAABBPoint, FastPointContactAABB, FastPointContactTriangle, flatdirection;
	flatdirection.Set( direction[0], 0.0f, direction[2] );
	
	for( t = 0.0f; t < lenght; t += EPSILON )
	{
		pobjs[0] = int(float((((p1+(flatdirection*t))[0]) - (moveColliderObject[0])) / (sizeColliderObject[0])));
		pobjs[1] = int(float((((p1+(flatdirection*t))[2]) - (moveColliderObject[1])) / (sizeColliderObject[1])));
		
		ptris[0] = int(float((((p1+(flatdirection*t))[0]) - (moveColliderTerrain[0])) / (sizeColliderTerrain[0])));
		ptris[1] = int(float((((p1+(flatdirection*t))[2]) - (moveColliderTerrain[1])) / (sizeColliderTerrain[1])));
		
		if( ( ptris[0] != tris[0] || ptris[1] != tris[1] ) && ptris[0] < maximumnumberoftrianglescolliders[0] && ptris[1] < maximumnumberoftrianglescolliders[1] && ptris[0] >= 0 && ptris[1] >= 0 )
		{	// Check triangles
			tris[0] = ptris[0];
			tris[1] = ptris[1];
			
			for( i = 0; i < colliderter[tris[0]][tris[1]].tri.size(); i++ )
			{
				if( colliderter[tris[0]][tris[1]].tri[i] != *triangle )
				{
					dot = colliderter[tris[0]][tris[1]].tri[i]->normal.Dot( direction );
					dot = ( ( - colliderter[tris[0]][tris[1]].tri[i]->det - colliderter[tris[0]][tris[1]].tri[i]->normal.Dot( p1 ) ) / dot );
					if( int(float((((p1+(direction*dot))[0]) - (moveColliderTerrain[0])) / (sizeColliderTerrain[0]))) == tris[0] && int(float((((p1+(direction*dot))[2]) - (moveColliderTerrain[1])) / (sizeColliderTerrain[1]))) == tris[1] )
					{
						if( colliderter[tris[0]][tris[1]].tri[i] -> PointIn( p1, p2 ) == true )
						{
							if( *triangle == NULL )
							{
								*triangle = colliderter[tris[0]][tris[1]].tri[i];
								continue;
							}
							else
							{
								
								if( dot < ( ( - (*triangle)->det - (*triangle)->normal.Dot( p1 ) ) / (*triangle)->normal.Dot( direction ) ) )
								{
									*triangle = colliderter[tris[0]][tris[1]].tri[i];
								}
							}
						}
					}
				}
			}
		}
		
		if( ( pobjs[0] != objs[0] || pobjs[1] != objs[1] ) && pobjs[0] < maximumnumberofobjectcolliders[0] && pobjs[1] < maximumnumberofobjectcolliders[1] && pobjs[0] >= 0 && pobjs[1] >= 0 )
		{	// Check objects
			objs[0] = pobjs[0];
			objs[1] = pobjs[1];
			
			for( i = 0; i < colliderobj[objs[0]][objs[1]].staticmodel.size(); i++ )
			{
				if( colliderobj[objs[0]][objs[1]].staticmodel[i] != *object && decludingobject != colliderobj[objs[0]][objs[1]].staticmodel[i] )
				{
					if( colliderobj[objs[0]][objs[1]].staticmodel[i] -> RayCollisionUse == true )
					{
						if( colliderobj[objs[0]][objs[1]].staticmodel[i] -> CheckRayType( rayTypeSrc ) == true )
						{
							if( collision.RayAABB( p1, p2, colliderobj[objs[0]][objs[1]].staticmodel[i], &FastPointContactAABB ) == 1 )
							{
								if( *object == NULL )
								{
									*object = colliderobj[objs[0]][objs[1]].staticmodel[i];
									ContactAABBPoint = FastPointContactAABB;
								}
								else if( (p1-FastPointContactAABB).Lenght() < (p1-ContactAABBPoint).Lenght() )
								{
									*object = colliderobj[objs[0]][objs[1]].staticmodel[i];
									ContactAABBPoint = FastPointContactAABB;
								}
							}
						}
					}
				}
			}
		}
		
		if( *triangle != NULL && *object != NULL )
		{
			if( (p1-ContactAABBPoint).Lenght() < ( ( - (*triangle)->det - (*triangle)->normal.Dot( p1 ) ) / ( (*triangle)->normal.Dot( direction ) ) ) )
			{
				*triangle = NULL;
				return COLLISION_WITH_OBJECT;
			}
			else
			{
				*object = NULL;
				return COLLISION_WITH_TRIANGLE;
			}
		}
		else if( *triangle != NULL )
		{
//			Vector ff = p1 + ( direction * ( ( - ((*triangle)->det) - ( p1 ).Dot( direction ) ) / direction.Dot( (*triangle)->normal ) ) );
//			if( tris[0] == int(float(((ff[0]) - (moveColliderTerrain[0])) / (sizeColliderTerrain[0]))) )
			{
//				if( tris[1] == int(float(((ff[2]) - (moveColliderTerrain[1])) / (sizeColliderTerrain[1]))) )
				{
					return COLLISION_WITH_TRIANGLE;
				}
			}
		}
		else if( *object != NULL )
		{
			return COLLISION_WITH_OBJECT;
		}
	}
	return COLLISION_NO;
}







inline bool Map::SegmentCollideObject( Vector begin, Vector end, PhysicModelStatic ** object, PhysicModelStatic * decludingobject )
{
	PhysicModelStatic * object_;
	TrianglePX * triangle_;
	SegmentCollision( begin, end, &object_, &triangle_, decludingobject, 0 );
	if( object_ == *object )
		return true;
	return false;
}




#undef EPSILON


