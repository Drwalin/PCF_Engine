


inline void Map::UpdateForces( float FrameTime )
{
    int i = 0;
    for( i = 0; i < staticobject.size(); i++ )
    {
		staticobject[i].UpdatePossition( FrameTime );
		staticobject[i].UpdateVelocity( FrameTime );
		staticobject[i].IdentityForce();
		switch( staticobject[i].type )
		{
		case PXMODEL_AABB:
			((AABB*)(staticobject[i].object))->force[1] = staticobject[i].GetMass() * Gravity;
			break;
		case PXMODEL_OBB:
			((OBB*)(staticobject[i].object))->force[1] = staticobject[i].GetMass() * Gravity;
			break;
		case PXMODEL_Sphere:
			((Sphere*)(staticobject[i].object))->force[1] = staticobject[i].GetMass() * Gravity;
			break;
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
	for( i = begin; i < staticobject.size() && i < end; i++ )
	{
		x_min = ( staticobject[i].GetMinX() - moveColliderTerrain[0] ) / sizeColliderTerrain[0];
		x_max = ( staticobject[i].GetMaxX() - moveColliderTerrain[0] ) / sizeColliderTerrain[0];
		x_max += 1.0f;
		z_min = ( staticobject[i].GetMinZ() - moveColliderTerrain[1] ) / sizeColliderTerrain[1];
		z_max = ( staticobject[i].GetMaxZ() - moveColliderTerrain[1] ) / sizeColliderTerrain[1];
		z_max += 1.0f;
		for( x = (int)x_min; x < (int)x_max; x++ )
		{
			for( z = (int)z_min; z < (int)z_max; z++ )
			{
				if( x >= 0 && x < maxiumumnumberoftrianglescolliders[0] && z >= 0 && z < maxiumumnumberoftrianglescolliders[1] )
				{
					for( j = 0; j < colliderter[x][z].tri.size(); j++ )
					{
						collision.ModelTriangle( &(staticobject[i]), (TrianglePX*)(( colliderter[x][z].tri[j] )), FrameTime );
					}
				}
				else
				{
					// ----
				}
			}
		}
		switch( staticobject[i].type )
		{
		case PXMODEL_AABB:
			if( ((AABB*)staticobject[i].object) -> CollisionUp || ((AABB*)staticobject[i].object) -> CollisionDown || ((AABB*)staticobject[i].object) -> CollisionSide )
			{
				((AABB*)staticobject[i].object) -> vel.GoToLenght( 0.0f, 8.0f*FrameTime );
			}
			break;
		case PXMODEL_OBB:
			if( ((OBB*)staticobject[i].object) -> Collision )
			{
				((OBB*)staticobject[i].object) -> vel.GoToLenght( 0.0f, 8.0f*FrameTime );
			}
			break;
		case PXMODEL_Sphere:
			if( ((Sphere*)staticobject[i].object) -> Collision )
			{
				((Sphere*)staticobject[i].object) -> vel.GoToLenght( 0.0f, 8.0f*FrameTime );
			}
			break;
		}
	}
}


