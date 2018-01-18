


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


inline void Map::UpdateObjectsCollisions( float FrameTime, int begin, int end )
{
	Collision collision;
    int i = 0;
    int j = 0;
    int k = 0;
    int x, z;
    float x_min, y_min, z_min, x_max, y_max, z_max;
    for( i = begin; i < staticobject.size() && i < end; i++ )
    {
		for( k = 0; k < staticobject[i].aabb.size(); k++ )
		{
			vector < TrianglePX* > tab = colliderter.GetFrom( staticobject[i].aabb[k].pos, staticobject[i].aabb[k].pos+staticobject[i].aabb[k].size+0.1f );
			
			for( j = 0; j < tab.size(); j++ )
			{
				collision.AABBTriangle( &(staticobject[i].aabb[k]), &staticobject[i].pos, (TrianglePX*)(tab[j]), FrameTime );
			}
		}
		if( staticobject[i].aabb[0].CollisionUp || staticobject[i].aabb[0].CollisionDown || staticobject[i].aabb[0].CollisionSide )
		{
			staticobject[i].vel.GoToLenght( 0.0f, 8.0f*FrameTime );
		}
	}
}


