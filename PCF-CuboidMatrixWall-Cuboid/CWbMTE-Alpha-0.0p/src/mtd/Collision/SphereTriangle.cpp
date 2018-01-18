


inline unsigned int Collision::SphereTriangle( Sphere * object, TrianglePX * tri, float time )
{
	if( (tri -> ClosestPoint( object -> pos ) - object -> pos).Lenght() <= object -> radian )
	{
		object -> Collision = true;
		
		float VelocityDistance = tri -> normal.Dot( object -> vel );
		float PossitionDistance = ( tri -> normal ).Dot( object -> MaxWithVector( 0.0f - tri -> normal ) - object -> pos );
		float ForceDistance = tri -> normal.Dot( object -> force );
		
		if( VelocityDistance < 0.0f )
		{
			object -> vel -= tri -> normal * VelocityDistance;
		}
		if( ForceDistance < 0.0f )
		{
			object -> force -= tri -> normal * ForceDistance;
			object -> resistanceforce = object -> resistanceforce - ( ((tri -> normal && object -> vel) && tri -> normal).Versor() * abs(ForceDistance) );
		}
		
		return COLLISION_IS;
	}
	return COLLISION_NO;
}


