


inline void Map::UpdateForces( float FrameTime )
{
    int i = 0;
    for( i = 0; i < staticobject.size(); i++ )
    {
		staticobject[i].UpdatePossition( FrameTime );
		staticobject[i].UpdateVelocity( FrameTime );
		staticobject[i].IdentityForce();
		staticobject[i].force[1] = staticobject[i].GetMass() * Gravity;
	}
}


inline void Map::UpdateObjectsCollisions( float FrameTime )
{
	Collision colision;
    int i = 0;
    int j = 0;
    int x, z;
    float x_min, z_min, x_max, z_max;
    for( i = 0; i < staticobject.size(); i++ )
    {
		x_min = ( staticobject[i].min[0] - moveColliderTerrain[0] ) / sizeColliderTerrain[0];
		x_max = ( staticobject[i].max[0] - moveColliderTerrain[0] ) / sizeColliderTerrain[0];
		x_max += 1;
		z_min = ( staticobject[i].min[2] - moveColliderTerrain[1] ) / sizeColliderTerrain[1];
		z_max = ( staticobject[i].max[2] - moveColliderTerrain[1] ) / sizeColliderTerrain[1];
		z_max += 1;
		for( x = (int)x_min; x < (int)x_max; x++ )
		{
			for( z = (int)z_min; z < (int)z_max; z++ )
			{
				if( x >= 0 && x < maxiumumnumberoftrianglescolliders[0] && z >= 0 && z < maxiumumnumberoftrianglescolliders[1] )
				{
					for( j = 0; j < colliderter[x][z].tri.size(); j++ )
					{
						colision.ModelTriangle( &staticobject[i], (TrianglePX*)(( colliderter[x][z].tri[j] )), FrameTime );
					}
				}
				else
				{
					for( j = 0; j < colliderter[0][0].tri.size(); j++ )
					{
						colision.ModelTriangle( &staticobject[i], (TrianglePX*)(( colliderter[0][0].tri[j] )), FrameTime );
					}
				}
			}
		}
	}
}


