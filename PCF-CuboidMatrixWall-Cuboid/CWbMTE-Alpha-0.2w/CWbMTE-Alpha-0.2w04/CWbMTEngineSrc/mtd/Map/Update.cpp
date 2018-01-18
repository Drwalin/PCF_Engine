


inline void Map::UpdateForces( float FrameTime )
{
    int i = 0;
    for( i = 0; i < staticobject.size(); i++ )
    {
		staticobject[i]->UpdatePossition( FrameTime );
		staticobject[i]->UpdateVelocity( FrameTime );
		staticobject[i]->IdentityForce();
		staticobject[i]->force[1] = staticobject[i]->GetMass() * Gravity;
	}
}



inline void Map::UpdateAllObjectsCollisions( float FrameTime )
{
	Collision collision;
    int i = 0;
    int j = 0;
    int k = 0;
    int x, z;
    float x_min, z_min, x_max, z_max;
    bool fastifobjectdonecollideout = false;
    ColliderTerrain * fastColliderter = NULL;
    for( i = 0; i < staticobject.size(); i++ )
    {
		if( true )
		{	//	Collision with objects:
			fastifobjectdonecollideout = false;
			
			for( int x = int( (staticobject[i]->min[0])/X_COLLIDER_SIZE ); x < int( 1.0f+((staticobject[i]->max[0])/X_COLLIDER_SIZE) ); x++ )
			{
				for( int z = int( (staticobject[i]->min[2])/Z_COLLIDER_SIZE ); z < int( 1.0f+((staticobject[i]->max[2])/Z_COLLIDER_SIZE) ); z++ )
				{
					fastColliderter = GetObjectCollider( x, z );
					if( fastColliderter != NULL )
					{
						for( k = 0; k < fastColliderter->staticmodel.size(); k++ )
						{
							if( fastColliderter->staticmodel[k]->MainVectorId > i )
							{
								collision.ModelModel( staticobject[i], fastColliderter -> staticmodel[k], FrameTime );
							}
						}
					}
				}
			}
		}
	}
}



inline void Map::UpdateObjectsCollisions( float FrameTime, int begin, int end )
{
	Collision collision;
    int i = 0;
    int j = 0;
    int k = 0;
    int x, z;
    float x_min, z_min, x_max, z_max;
    bool fastifobjectdonecollideout = false;
    ColliderTerrain * fastTerrainCollider = NULL;
    for( i = begin; i < staticobject.size() && i < end; i++ )
    {
		if( staticobject[i]->TerrainCollisionUse == true )
		{
			for( k = 0; k < staticobject[i]->aabb.size(); k++ )
			{
				{	//	Collision with triangles:
					x_min = ( staticobject[i]->pos[0] + staticobject[i]->aabb[k].pos[0] ) / X_COLLIDER_SIZE;
					x_max = ( staticobject[i]->pos[0] + staticobject[i]->aabb[k].pos[0] + staticobject[i]->aabb[k].size[0] ) / X_COLLIDER_SIZE;
					z_min = ( staticobject[i]->pos[2] + staticobject[i]->aabb[k].pos[2] ) / Z_COLLIDER_SIZE;
					z_max = ( staticobject[i]->pos[2] + staticobject[i]->aabb[k].pos[2] + staticobject[i]->aabb[k].size[2] ) / Z_COLLIDER_SIZE;
					
					for( x = (int)x_min; x <= (int)x_max; x++ )
					{
						for( z = (int)z_min; z <= (int)z_max; z++ )
						{
							fastTerrainCollider = GetTerrainCollider( x, z );
							if( fastTerrainCollider != NULL )
							{
								for( j = 0; j < fastTerrainCollider->tri.size(); j++ )
								{
									collision.AABBTriangle( &(staticobject[i]->aabb[k]), &(staticobject[i]->pos), fastTerrainCollider->tri[j], FrameTime );	
								}
							}
						}
					}
				}
			}
			
			{	//	Resistance force:
				for( k = 0; k < staticobject[i]->aabb.size(); k++ )
				{
					if( staticobject[i]->aabb[k].CollisionDown || staticobject[i]->aabb[k].CollisionUp || staticobject[i]->aabb[k].CollisionSide )
					{
						staticobject[i]->vel.GoToLenght( 0.0f, 9.0f*FrameTime );
						break;
					}
				}
			}
		}
	}
}


