

inline unsigned int Collision::AABBTriangle( AABB * object, Vector * offset1, TrianglePX * tri, float time )
{
	int i;
	unsigned int collision = 0;
	Vector pointfast;
	
	Vector begin = (object -> pos) + *offset1;
	Vector end = begin + object -> size;
	
	if( (tri->min <= (end)) && (tri->max >= begin) )
	{
		Vector point_1 = (object->MaxWithVector(tri->normal))-(tri->vertex[0])+(*offset1);
		Vector point_2 = (object->MaxWithVector(0.0f-(tri->normal)))-(tri->vertex[0])+(*offset1);
		if( ( ( point_1.Dot(tri->normal) >= 0.0f && point_2.Dot(tri->normal) <= 0.0f ) || ( point_1.Dot(tri->normal) <= 0.0f && point_2.Dot(tri->normal) >= 0.0f ) ) )
			return COLLISION_NO;
		
		/*
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
		
		return COLLISION_NO;
		*/
		
		for( i = 0; i < 3; i++ )
		{
			if( RayAABB( tri->vertex[i], tri->vertex[(i+1)%3], offset1, object ) )
				goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
		}
		if( (tri->min >= begin) && (tri->max <= (end)) )
			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
		
		Vector vertex[2][2][2];
		vertex[0][0][0] = object->GetVertex(0) + (*offset1);
		vertex[1][0][0] = object->GetVertex(1) + (*offset1);
		vertex[1][0][1] = object->GetVertex(2) + (*offset1);
		vertex[0][0][1] = object->GetVertex(3) + (*offset1);
		vertex[0][1][0] = object->GetVertex(4) + (*offset1);
		vertex[1][1][0] = object->GetVertex(5) + (*offset1);
		vertex[1][1][1] = object->GetVertex(6) + (*offset1);
		vertex[0][1][1] = object->GetVertex(7) + (*offset1);
		bool vertexpos[2][2][2];
		vertexpos[0][0][0] = ( ((vertex[0][0][0] - (tri->vertex[0])).Dot( tri->normal )) < 0.0f ) ? false : true;
		vertexpos[0][0][1] = ( ((vertex[0][0][1] - (tri->vertex[0])).Dot( tri->normal )) < 0.0f ) ? false : true;
		vertexpos[0][1][0] = ( ((vertex[0][1][0] - (tri->vertex[0])).Dot( tri->normal )) < 0.0f ) ? false : true;
		vertexpos[0][1][1] = ( ((vertex[0][1][1] - (tri->vertex[0])).Dot( tri->normal )) < 0.0f ) ? false : true;
		vertexpos[1][0][0] = ( ((vertex[1][0][0] - (tri->vertex[0])).Dot( tri->normal )) < 0.0f ) ? false : true;
		vertexpos[1][0][1] = ( ((vertex[1][0][1] - (tri->vertex[0])).Dot( tri->normal )) < 0.0f ) ? false : true;
		vertexpos[1][1][0] = ( ((vertex[1][1][0] - (tri->vertex[0])).Dot( tri->normal )) < 0.0f ) ? false : true;
		vertexpos[1][1][1] = ( ((vertex[1][1][1] - (tri->vertex[0])).Dot( tri->normal )) < 0.0f ) ? false : true;
		
		int x,y,z;
		for( x = 0; x < 2; x++ )
		{
			for( y = 0; y < 2; y++ )
			{
				for( z = 0; z < 2; z++ )
				{
					if( vertexpos[x][y][z] == true )
					{
						if( vertexpos[(x+1)%2][y][z] != vertexpos[x][y][z] )
						{
							if( tri -> PointIn( vertex[(x+1)%2][y][z], vertex[x][y][z] ) )
								goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
						}
						if( vertexpos[x][(y+1)%2][z] != vertexpos[x][y][z] )
						{
							if( tri -> PointIn( vertex[x][(y+1)%2][z], vertex[x][y][z] ) )
								goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
						}
						if( vertexpos[x][y][(z+1)%2] != vertexpos[x][y][z] )
						{
							if( tri -> PointIn( vertex[x][y][(z+1)%2], vertex[x][y][z] ) )
								goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
						}
					}
				}
			}
		}
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


