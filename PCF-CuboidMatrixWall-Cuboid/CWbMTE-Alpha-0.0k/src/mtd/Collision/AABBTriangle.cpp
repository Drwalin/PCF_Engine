

inline unsigned int Collision::AABBTriangle( AABB * object, Vector * offset1, TrianglePX * tri, float time )
{
	int i;
	unsigned int collision = 0;
	Vector pointfast;
	
	Vector begin = (object -> pos) + *offset1;
	Vector end = begin + object -> size;
	
	if( (tri->min <= (end)) && (tri->max >= begin) )
	{
		if( tri -> PointIn( SetVector( end[0], begin[1], begin[2] ), SetVector( begin[0], begin[1], begin[2] ) ) )    // krawêdŸ 0
			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;  // przeniesienie do punktu obliczania kolizji
		
		if( tri -> PointIn( SetVector( end[0], begin[1], begin[2] ), SetVector( end[0], begin[1], end[2] ) ) )    // krawêdŸ 1
			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;  // przeniesienie do punktu obliczania kolizji
		
		if( tri -> PointIn( SetVector( begin[0], begin[1], end[2] ), SetVector( end[0], begin[1], end[2] ) ) )    // krawêdŸ 2
			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;  // przeniesienie do punktu obliczania kolizji
		
		if( tri -> PointIn( SetVector( begin[0], begin[1], end[2] ), SetVector( begin[0], begin[1], begin[2] ) ) )    // krawêdŸ 3
			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;  // przeniesienie do punktu obliczania kolizji
		
		
		
		if( tri -> PointIn( SetVector( begin[0], begin[1], begin[2] ), SetVector( begin[0], end[1], begin[2] ) ) )    // krawêdŸ 4
			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;  // przeniesienie do punktu obliczania kolizji
		
		if( tri -> PointIn( SetVector( end[0], begin[1], begin[2] ), SetVector( end[0], end[1], begin[2] ) ) )    // krawêdŸ 5
			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;  // przeniesienie do punktu obliczania kolizji
		
		if( tri -> PointIn( SetVector( end[0], begin[1], end[2] ), SetVector( end[0], end[1], end[2] ) ) )    // krawêdŸ 6
			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;  // przeniesienie do punktu obliczania kolizji
		
		if( tri -> PointIn( SetVector( begin[0], begin[1], end[2] ), SetVector( begin[0], end[1], end[2] ) ) )    // krawêdŸ 7
			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;  // przeniesienie do punktu obliczania kolizji
		
		
		
		if( tri -> PointIn( SetVector( end[0], end[1], begin[2] ), SetVector( begin[0], end[1], begin[2] ) ) )    // krawêdŸ 8
			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;  // przeniesienie do punktu obliczania kolizji
		
		if( tri -> PointIn( SetVector( end[0], end[1], begin[2] ), SetVector( end[0], end[1], end[2] ) ) )    // krawêdŸ 9
			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;  // przeniesienie do punktu obliczania kolizji
		
		if( tri -> PointIn( SetVector( begin[0], end[1], end[2] ), SetVector( end[0], end[1], end[2] ) ) )    // krawêdŸ 10
			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;  // przeniesienie do punktu obliczania kolizji
		
		if( tri -> PointIn( SetVector( begin[0], end[1], end[2] ), SetVector( begin[0], end[1], begin[2] ) ) )    // krawêdŸ 11
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


