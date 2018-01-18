


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
	
	for( t = 0.0f; t < lenght; t += EPSILON )
	{
		pobjs[0] = int(float((((p1+(direction*t))[0]) - (moveColliderObject[0])) / (sizeColliderObject[0])));
		pobjs[1] = int(float((((p1+(direction*t))[2]) - (moveColliderObject[1])) / (sizeColliderObject[1])));
		
		ptris[0] = int(float((((p1+(direction*t))[0]) - (moveColliderTerrain[0])) / (sizeColliderTerrain[0])));
		ptris[1] = int(float((((p1+(direction*t))[2]) - (moveColliderTerrain[1])) / (sizeColliderTerrain[1])));
		
		
		if( ( ptris[0] != tris[0] || ptris[1] != tris[1] ) && ptris[0] < maximumnumberoftrianglescolliders[0] && ptris[1] < maximumnumberoftrianglescolliders[1] && ptris[0] >= 0 && ptris[1] >= 0 )
		{	// Check triangles
			tris[0] = ptris[0];
			tris[1] = ptris[1];
			
			
			for( i = 0; i < colliderter[tris[0]][tris[1]].tri.size(); i++ )
			{
				if( colliderter[tris[0]][tris[1]].tri[i] != *triangle )
				{
					if( colliderter[tris[0]][tris[1]].tri[i] -> PointIn( p1, p2 ) == true )
					{
						if( *triangle == NULL )
						{
							*triangle = colliderter[tris[0]][tris[1]].tri[i];
							continue;
						}
						else// if( false )
						{
							dot = colliderter[tris[0]][tris[1]].tri[i]->normal.Dot( direction );
							dot = ( ( - colliderter[tris[0]][tris[1]].tri[i]->det - colliderter[tris[0]][tris[1]].tri[i]->normal.Dot( p1 ) ) / dot );
							
							if( dot < ( ( - (*triangle)->det - (*triangle)->normal.Dot( p1 ) ) / (*triangle)->normal.Dot( direction ) ) )
							{
								*triangle = colliderter[tris[0]][tris[1]].tri[i];
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
					for( j = 0; j < colliderobj[objs[0]][objs[1]].staticmodel[i] -> aabb.size(); j++ )
					{
						if( collision.RayAABB( p1, p2, &(colliderobj[objs[0]][objs[1]].staticmodel[i] -> pos), &(colliderobj[objs[0]][objs[1]].staticmodel[i] -> aabb[j]), &FastPointContactAABB ) == 1 )
						{
							if( *object == NULL )
							{
								*object = colliderobj[objs[0]][objs[1]].staticmodel[i];
								ContactAABBPoint = FastPointContactAABB;
								break;
							}
							else if( (p1-FastPointContactAABB).Lenght() < (p1-ContactAABBPoint).Lenght() )
							{
								*object = colliderobj[objs[0]][objs[1]].staticmodel[i];
								ContactAABBPoint = FastPointContactAABB;
								break;
							}
						}
					}
				}
			}
		}
		
		if( *triangle != NULL && *object != NULL )
		{
			/*{
				glDisable( GL_TEXTURE_2D );
				glEnable( GL_BLEND );
				glPointSize( 30.0f );
				glColor3f( 1.0f, 1.0f, 1.0f );
				glBegin( GL_POINTS );
				glVertex3fv( &(ContactAABBPoint[0]) );
				glEnd();
				glDisable( GL_BLEND );
				glEnable( GL_TEXTURE_2D );
			}*/
			
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
			if( tris[0] == int(float(((ff[0]) - (moveColliderTerrain[0])) / (sizeColliderTerrain[0]))) )
			{
				if( tris[1] == int(float(((ff[2]) - (moveColliderTerrain[1])) / (sizeColliderTerrain[1]))) )
				{
					return COLLISION_WITH_TRIANGLE;
				}
			}
		}
		else if( *object != NULL )
		{
			/*{
				glDisable( GL_TEXTURE_2D );
				glEnable( GL_BLEND );
				glPointSize( 30.0f );
				glColor3f( 1.0f, 1.0f, 1.0f );
				glBegin( GL_POINTS );
				glVertex3fv( &(ContactAABBPoint[0]) );
				glEnd();
				glDisable( GL_BLEND );
				glEnable( GL_TEXTURE_2D );
			}*/
			
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


