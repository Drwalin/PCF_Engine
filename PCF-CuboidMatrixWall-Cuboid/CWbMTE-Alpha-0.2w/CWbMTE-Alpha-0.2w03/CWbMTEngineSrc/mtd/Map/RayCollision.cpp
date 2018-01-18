


#define EPSILON 0.1f

inline int Map::SegmentCollision( Vector p1, Vector p2, PhysicModelStatic ** object, TrianglePX ** triangle, PhysicModelStatic * decludingobject )
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
	
	int pobjs[2];
	int ptris[2];
	
	Vector ContactAABBPoint;
	Vector FastPointContactAABB;
	
	ColliderTerrain * fastTerrColider = NULL;
	ColliderObjects * fastObjColider = NULL;
	
	for( t = 0.0f; t < lenght; t += EPSILON )
	{
		pobjs[0] = int(float((((p1+(direction*t))[0])) / (X_COLLIDER_SIZE)));
		pobjs[1] = int(float((((p1+(direction*t))[2])) / (Z_COLLIDER_SIZE)));
		
		ptris[0] = int(float((((p1+(direction*t))[0])) / (X_COLLIDER_SIZE)));
		ptris[1] = int(float((((p1+(direction*t))[2])) / (X_COLLIDER_SIZE)));
		
		
		
		if( ( ptris[0] != tris[0] || ptris[1] != tris[1] ) && ptris[0] < maximumnumberofcolliders[0] && ptris[1] < maximumnumberofcolliders[1] && ptris[0] >= 0 && ptris[1] >= 0 )
		{	// Check triangles
			tris[0] = ptris[0];
			tris[1] = ptris[1];
			
			fastTerrColider = GetTerrainCollider( tris[0], tris[1] );
			
			if( fastTerrColider != NULL )
			{
				
				for( i = 0; i < fastTerrColider->tri.size(); i++ )
				{
					if( fastTerrColider->tri[i] != *triangle )
					{
						if( fastTerrColider->tri[i] -> PointIn( p1, p2 ) == true )
						{
							if( *triangle == NULL )
							{
								*triangle = fastTerrColider->tri[i];
								continue;
							}
							else// if( false )
							{
								dot = fastTerrColider->tri[i]->normal.Dot( direction );
								dot = ( ( - fastTerrColider->tri[i]->det - fastTerrColider->tri[i]->normal.Dot( p1 ) ) / dot );
								
								if( dot < ( ( - (*triangle)->det - (*triangle)->normal.Dot( p1 ) ) / (*triangle)->normal.Dot( direction ) ) )
								{
									*triangle = fastTerrColider->tri[i];
								}
							}
						}
					}
				}
			}
		}
		
		
		if( ( pobjs[0] != objs[0] || pobjs[1] != objs[1] ) && pobjs[0] < maximumnumberofcolliders[0] && pobjs[1] < maximumnumberofcolliders[1] && pobjs[0] >= 0 && pobjs[1] >= 0 )
		{	// Check objects
			objs[0] = pobjs[0];
			objs[1] = pobjs[1];
			
			fastObjColider = GetObjectCollider( objs[0], objs[1] );
			
			if( fastObjColider != NULL )
			{
				
				for( i = 0; i < fastObjColider->staticmodel.size(); i++ )
				{
					if( fastObjColider->staticmodel[i] != *object && decludingobject != fastObjColider->staticmodel[i] )
					{
						if( fastObjColider->staticmodel[i] -> RayCollisionUse == true )
						{
							for( j = 0; j < fastObjColider->staticmodel[i] -> aabb.size(); j++ )
							{
								if( collision.RayAABB( p1, p2, &(fastObjColider->staticmodel[i] -> pos), &(fastObjColider->staticmodel[i] -> aabb[j]), &FastPointContactAABB ) == 1 )
								{
									if( *object == NULL )
									{
										*object = fastObjColider->staticmodel[i];
										ContactAABBPoint = FastPointContactAABB;
										break;
									}
									else if( (p1-FastPointContactAABB).Lenght() < (p1-ContactAABBPoint).Lenght() )
									{
										*object = fastObjColider->staticmodel[i];
										ContactAABBPoint = FastPointContactAABB;
										break;
									}
								}
							}
						}
					}
				}
			}
		}
		
		if( *triangle != NULL && *object != NULL )
		{
			
			if( (p1-ContactAABBPoint).Lenght() < ( ( - (*triangle)->det - (*triangle)->normal.Dot( p1 ) ) / (*triangle)->normal.Dot( direction ) ) )
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
			Vector ff = p1 + ( direction * ( ( - ((*triangle)->det) - ( p1 ).Dot( direction ) ) / direction.Dot( (*triangle)->normal ) ) );
			if( tris[0] == int(float(((ff[0])) / (X_COLLIDER_SIZE))) )
			{
				if( tris[1] == int(float(((ff[2])) / (Z_COLLIDER_SIZE))) )
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
	SegmentCollision( begin, end, &object_, &triangle_, decludingobject );
	if( object_ == *object )
		return true;
	return false;
}




#undef EPSILON


