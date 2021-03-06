


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
    for( i = 0; i < staticobject.size(); i++ )
    {
		if( true )
		{	//	Collision with objects:
			fastifobjectdonecollideout = false;
			
			for( int x = int( (staticobject[i]->min[0]-moveColliderObject[0])/sizeColliderObject[0] ); x < int( 1.0f+((staticobject[i]->max[0]-moveColliderObject[0])/sizeColliderObject[0]) ); x++ )
			{
				for( int z = int( (staticobject[i]->min[2]-moveColliderObject[1])/sizeColliderObject[1] ); z < int( 1.0f+((staticobject[i]->max[2]-moveColliderObject[1])/sizeColliderObject[1]) ); z++ )
				{
					if( x >= 0 && z >= 0 && x < maxiumumnumberofobjectcolliders[0] && z < maxiumumnumberofobjectcolliders[1] )
					{
						for( k = 0; k < (*( colliderobj+x )+z) -> staticmodel.size(); k++ )
						{
							if( (*( colliderobj+x )+z)->staticmodel[k]->MainVectorId > i )
							{
								collision.ModelModel( staticobject[i], (*( colliderobj+x )+z) -> staticmodel[k], FrameTime );
							}
						}
					}
					else if( fastifobjectdonecollideout == false )
					{
						for( k = 0; k < colliderobjectout.staticmodel.size(); k++ )
						{
							if( colliderobjectout.staticmodel[k]->MainVectorId > i )
							{
								collision.ModelModel( staticobject[i], colliderobjectout.staticmodel[k], FrameTime );
							}
						}
						fastifobjectdonecollideout = true;
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
    for( i = begin; i < staticobject.size() && i < end; i++ )
    {
		
		for( k = 0; k < staticobject[i]->aabb.size(); k++ )
		{
			{	//	Collision with triangles:
				x_min = ( staticobject[i]->pos[0] + staticobject[i]->aabb[k].pos[0] - moveColliderTerrain[0] ) / sizeColliderTerrain[0];
				x_max = ( staticobject[i]->pos[0] + staticobject[i]->aabb[k].pos[0] + staticobject[i]->aabb[k].size[0] - moveColliderTerrain[0] ) / sizeColliderTerrain[0];
				z_min = ( staticobject[i]->pos[2] + staticobject[i]->aabb[k].pos[2] - moveColliderTerrain[1] ) / sizeColliderTerrain[1];
				z_max = ( staticobject[i]->pos[2] + staticobject[i]->aabb[k].pos[2] + staticobject[i]->aabb[k].size[2] - moveColliderTerrain[1] ) / sizeColliderTerrain[1];
				
				for( x = (int)x_min; x <= (int)x_max; x++ )
				{
					for( z = (int)z_min; z <= (int)z_max; z++ )
					{
						if( x >= 0 && x < maxiumumnumberoftrianglescolliders[0] && z >= 0 && z < maxiumumnumberoftrianglescolliders[1] )
						{
							for( j = 0; j < colliderter[x][z].tri.size(); j++ )
							{
								collision.AABBTriangle( &(staticobject[i]->aabb[k]), &(staticobject[i]->pos), colliderter[x][z].tri[j], FrameTime );
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


