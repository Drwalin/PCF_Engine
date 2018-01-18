


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
		if( staticobject[i] -> ObjectsCollisionUse == true )
		{	//	Collision with objects:
			fastifobjectdonecollideout = false;
			
			for( int x = int( (staticobject[i]->min[0]-moveColliderObject[0])/sizeColliderObject[0] ); x < int( 1.0f+((staticobject[i]->max[0]-moveColliderObject[0])/sizeColliderObject[0]) ); x++ )
			{
				for( int z = int( (staticobject[i]->min[2]-moveColliderObject[1])/sizeColliderObject[1] ); z < int( 1.0f+((staticobject[i]->max[2]-moveColliderObject[1])/sizeColliderObject[1]) ); z++ )
				{
					if( x >= 0 && z >= 0 && x < maximumnumberofobjectcolliders[0] && z < maximumnumberofobjectcolliders[1] )
					{
						for( k = 0; k < (*( colliderobj+x )+z) -> staticmodel.size(); k++ )
						{
							if( (*( colliderobj+x )+z)->staticmodel[k] -> ObjectsCollisionUse == true )
							{
								if( (*( colliderobj+x )+z)->staticmodel[k]->MainVectorId > i )
								{
									collision.AABBAABB( staticobject[i], (*( colliderobj+x )+z) -> staticmodel[k], FrameTime );
								}
							}
						}
					}
					else if( fastifobjectdonecollideout == false )
					{
						for( k = 0; k < colliderobjectout.staticmodel.size(); k++ )
						{
							if( colliderobjectout.staticmodel[k] -> ObjectsCollisionUse == true )
							{
								if( colliderobjectout.staticmodel[k]->MainVectorId > i )
								{
									collision.AABBAABB( staticobject[i], colliderobjectout.staticmodel[k], FrameTime );
								}
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
    int i = 0, j = 0;
    int x, z;
    float x_min, z_min, x_max, z_max;
    bool fastifobjectdonecollideout = false;
    for( i = begin; i < staticobject.size() && i < end; i++ )
    {
		if( staticobject[i]->TerrainCollisionUse == true )
		{
			x_min = ( staticobject[i]->pos[0] + staticobject[i]->pos[0] - moveColliderTerrain[0] ) / sizeColliderTerrain[0];
			x_max = ( staticobject[i]->pos[0] + staticobject[i]->pos[0] + staticobject[i]->size[0] - moveColliderTerrain[0] ) / sizeColliderTerrain[0];
			z_min = ( staticobject[i]->pos[2] + staticobject[i]->pos[2] - moveColliderTerrain[1] ) / sizeColliderTerrain[1];
			z_max = ( staticobject[i]->pos[2] + staticobject[i]->pos[2] + staticobject[i]->size[2] - moveColliderTerrain[1] ) / sizeColliderTerrain[1];
			
			for( x = (int)x_min; x <= (int)x_max; x++ )
			{
				for( z = (int)z_min; z <= (int)z_max; z++ )
				{
					if( x >= 0 && x < maximumnumberoftrianglescolliders[0] && z >= 0 && z < maximumnumberoftrianglescolliders[1] )
					{
						for( j = 0; j < colliderter[x][z].tri.size(); j++ )
						{
							collision.AABBTriangle( staticobject[i], colliderter[x][z].tri[j], FrameTime );	
						}
					}
				}
			}
			
			if( staticobject[i]->CollisionDown || staticobject[i]->CollisionUp || staticobject[i]->CollisionSide )
			{
				staticobject[i]->vel.GoToLength( 0.0f, 9.0f*FrameTime );
				break;
			}
		}
	}
}


