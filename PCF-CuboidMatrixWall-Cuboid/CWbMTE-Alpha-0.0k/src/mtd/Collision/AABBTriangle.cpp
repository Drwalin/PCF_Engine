

inline unsigned int Collision::AABBTriangle( AABB * object, Vector * offset1, TrianglePX * tri, float time )
{
	int i;
	unsigned int collision = 0;
	Vector pointfast;
	
	Vector begin = (object -> pos) + *offset1;
	Vector end = begin + object -> size;
	
	if( (tri->min <= (end)) && (tri->max >= begin) )
	{
		if( tri -> PointIn( SetVector( end[0], begin[1], begin[2] ), SetVector( begin[0], begin[1], begin[2] ) ) )    // kraw�d� 0
			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;  // przeniesienie do punktu obliczania kolizji
		
		if( tri -> PointIn( SetVector( end[0], begin[1], begin[2] ), SetVector( end[0], begin[1], end[2] ) ) )    // kraw�d� 1
			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;  // przeniesienie do punktu obliczania kolizji
		
		if( tri -> PointIn( SetVector( begin[0], begin[1], end[2] ), SetVector( end[0], begin[1], end[2] ) ) )    // kraw�d� 2
			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;  // przeniesienie do punktu obliczania kolizji
		
		if( tri -> PointIn( SetVector( begin[0], begin[1], end[2] ), SetVector( begin[0], begin[1], begin[2] ) ) )    // kraw�d� 3
			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;  // przeniesienie do punktu obliczania kolizji
		
		
		
		if( tri -> PointIn( SetVector( begin[0], begin[1], begin[2] ), SetVector( begin[0], end[1], begin[2] ) ) )    // kraw�d� 4
			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;  // przeniesienie do punktu obliczania kolizji
		
		if( tri -> PointIn( SetVector( end[0], begin[1], begin[2] ), SetVector( end[0], end[1], begin[2] ) ) )    // kraw�d� 5
			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;  // przeniesienie do punktu obliczania kolizji
		
		if( tri -> PointIn( SetVector( end[0], begin[1], end[2] ), SetVector( end[0], end[1], end[2] ) ) )    // kraw�d� 6
			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;  // przeniesienie do punktu obliczania kolizji
		
		if( tri -> PointIn( SetVector( begin[0], begin[1], end[2] ), SetVector( begin[0], end[1], end[2] ) ) )    // kraw�d� 7
			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;  // przeniesienie do punktu obliczania kolizji
		
		
		
		if( tri -> PointIn( SetVector( end[0], end[1], begin[2] ), SetVector( begin[0], end[1], begin[2] ) ) )    // kraw�d� 8
			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;  // przeniesienie do punktu obliczania kolizji
		
		if( tri -> PointIn( SetVector( end[0], end[1], begin[2] ), SetVector( end[0], end[1], end[2] ) ) )    // kraw�d� 9
			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;  // przeniesienie do punktu obliczania kolizji
		
		if( tri -> PointIn( SetVector( begin[0], end[1], end[2] ), SetVector( end[0], end[1], end[2] ) ) )    // kraw�d� 10
			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;  // przeniesienie do punktu obliczania kolizji
		
		if( tri -> PointIn( SetVector( begin[0], end[1], end[2] ), SetVector( begin[0], end[1], begin[2] ) ) )    // kraw�d� 11
			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;  // przeniesienie do punktu obliczania kolizji
	}
	
	return COLLISION_NO;
	
	
	
	
	//if( false )
	{
		CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION:
		
		if( tri -> normal[1] < -0.7f )
		{
			object -> CollisionUp = true;
		}
		else if( tri -> normal[1] > 0.7f )
		{
			object -> CollisionDown = true;
		}
		else
		{
			object -> CollisionSide = true;
		}
		
		Vector vertex = object -> MaxWithVector( 0.0f - tri -> normal );
		
		float VelocityDistance = tri -> normal.Dot( *(object -> vel) );
		float PossitionDistance = ( tri -> normal ).Dot( vertex - ( tri -> vertex[0] ) );
		float ForceDistance = tri -> normal.Dot( *(object -> force) );
		
		if( VelocityDistance < 0.0f )
		{
			*(object -> vel) -= tri -> normal * ( VelocityDistance );
		}
		if( ForceDistance < 0.0f )
		{
			*(object -> force) -= tri -> normal * ForceDistance;
			*(object -> resistanceforce) = (*(object -> resistanceforce)) - ( ((tri -> normal && (*(object -> vel))) && tri -> normal).Versor() * abs(ForceDistance) );
		}
		
		return COLLISION_IS;
	}
	return COLLISION_NO;
}


