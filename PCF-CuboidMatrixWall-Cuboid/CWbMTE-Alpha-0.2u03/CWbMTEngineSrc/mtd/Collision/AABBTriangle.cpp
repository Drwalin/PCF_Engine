

inline unsigned int Collision::AABBTriangle( AABB * object, Vector * offset1, TrianglePX * tri, float time )
{
	int i;
	unsigned int collision = 0;
	Vector pointfast;
	
	Vector begin = (object -> pos) + *offset1;
	Vector end = begin + object -> size;
	
	if( (tri->min <= end) && (tri->max >= begin) )
	{
		{
			float p1dot = ((object->MaxWithVector(tri->normal))-(tri->vertex[0])+(*offset1)).Dot(tri->normal);
			float p2dot = ((object->MaxWithVector(0.0f-tri->normal))-(tri->vertex[0])+(*offset1)).Dot(tri->normal);
			if( ( ( p1dot >= 0.0f && p2dot <= 0.0f ) || ( p1dot <= 0.0f && p2dot >= 0.0f ) ) )
				return COLLISION_NO;
		}
		
		{
			if( RayAABB( tri->vertex[0], tri->vertex[1], offset1, object ) )
				goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
			if( RayAABB( tri->vertex[1], tri->vertex[2], offset1, object ) )
				goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
			if( RayAABB( tri->vertex[2], tri->vertex[0], offset1, object ) )
				goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
		}
		
		if( (tri->min >= begin) && (tri->max <= end) )
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
		
		
		
		
		
		{
			{	// [0,0,0]
				if( vertexpos[0][0][0] == true )
				{
					if( vertexpos[1][0][0] == false )
					{
						if( tri -> PointIn( vertex[1][0][0], vertex[0][0][0] ) )
							goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
					}
					if( vertexpos[0][1][0] == false )
					{
						if( tri -> PointIn( vertex[0][1][0], vertex[0][0][0] ) )
							goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
					}
					if( vertexpos[0][0][1] == false )
					{
						if( tri -> PointIn( vertex[0][0][1], vertex[0][0][0] ) )
							goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
					}
				}
			}
			{	// [0,0,1]
				if( vertexpos[0][0][1] == true )
				{
					if( vertexpos[1][0][1] == false )
					{
						if( tri -> PointIn( vertex[1][0][1], vertex[0][0][1] ) )
							goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
					}
					if( vertexpos[0][1][1] == false )
					{
						if( tri -> PointIn( vertex[0][1][1], vertex[0][0][1] ) )
							goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
					}
					if( vertexpos[0][0][0] == false )
					{
						if( tri -> PointIn( vertex[0][0][0], vertex[0][0][1] ) )
							goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
					}
				}
			}
			{	// [0,1,0]
				if( vertexpos[0][1][0] == true )
				{
					if( vertexpos[1][1][0] == false )
					{
						if( tri -> PointIn( vertex[1][1][0], vertex[0][1][0] ) )
							goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
					}
					if( vertexpos[0][0][0] == false )
					{
						if( tri -> PointIn( vertex[0][0][0], vertex[0][1][0] ) )
							goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
					}
					if( vertexpos[0][1][1] == false )
					{
						if( tri -> PointIn( vertex[0][1][1], vertex[0][1][0] ) )
							goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
					}
				}
			}
			{	// [0,1,1]
				if( vertexpos[0][1][1] == true )
				{
					if( vertexpos[1][1][1] == false )
					{
						if( tri -> PointIn( vertex[1][1][1], vertex[0][1][1] ) )
							goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
					}
					if( vertexpos[0][0][1] == false )
					{
						if( tri -> PointIn( vertex[0][0][1], vertex[0][1][1] ) )
							goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
					}
					if( vertexpos[0][1][0] == false )
					{
						if( tri -> PointIn( vertex[0][1][0], vertex[0][1][1] ) )
							goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
					}
				}
			}
			{	// [1,0,0]
				if( vertexpos[1][0][0] == true )
				{
					if( vertexpos[0][0][0] == false )
					{
						if( tri -> PointIn( vertex[0][0][0], vertex[1][0][0] ) )
							goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
					}
					if( vertexpos[1][1][0] == false )
					{
						if( tri -> PointIn( vertex[1][1][0], vertex[1][0][0] ) )
							goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
					}
					if( vertexpos[1][0][1] == false )
					{
						if( tri -> PointIn( vertex[1][0][1], vertex[1][0][0] ) )
							goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
					}
				}
			}
			{	// [1,0,1]
				if( vertexpos[1][0][1] == true )
				{
					if( vertexpos[0][0][1] == false )
					{
						if( tri -> PointIn( vertex[0][0][1], vertex[1][0][1] ) )
							goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
					}
					if( vertexpos[1][1][1] == false )
					{
						if( tri -> PointIn( vertex[1][1][1], vertex[1][0][1] ) )
							goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
					}
					if( vertexpos[1][0][0] == false )
					{
						if( tri -> PointIn( vertex[1][0][0], vertex[1][0][1] ) )
							goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
					}
				}
			}
			{	// [1,1,0]
				if( vertexpos[1][1][0] == true )
				{
					if( vertexpos[0][1][0] == false )
					{
						if( tri -> PointIn( vertex[0][1][0], vertex[1][1][0] ) )
							goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
					}
					if( vertexpos[1][0][0] == false )
					{
						if( tri -> PointIn( vertex[1][0][0], vertex[1][1][0] ) )
							goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
					}
					if( vertexpos[1][1][1] == false )
					{
						if( tri -> PointIn( vertex[1][1][1], vertex[1][1][0] ) )
							goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
					}
				}
			}
			{	// [1,1,1]
				if( vertexpos[1][1][1] == true )
				{
					if( vertexpos[0][1][1] == false )
					{
						if( tri -> PointIn( vertex[0][1][1], vertex[1][1][1] ) )
							goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
					}
					if( vertexpos[1][0][1] == false )
					{
						if( tri -> PointIn( vertex[1][0][1], vertex[1][1][1] ) )
							goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
					}
					if( vertexpos[1][1][0] == false )
					{
						if( tri -> PointIn( vertex[1][1][0], vertex[1][1][1] ) )
							goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
					}
				}
			}
		}
	}
	
	return COLLISION_NO;
	
	CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION:
	{
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
		
		//Vector vertex = object -> MaxWithVector( 0.0f - tri -> normal );
		float VelocityDistance = tri -> normal.Dot( *(object -> vel) );
		float PossitionDistance = ( tri -> normal.Versor() ).Dot( object -> MaxWithVector( 0.0f - tri -> normal ) + (*offset1) - ( tri -> vertex[0] ) );
		float ForceDistance = tri -> normal.Dot( *(object -> force) );
		
//		*offset1 += ( tri -> normal.Versor() ) * abs( tri->normal.Dot( object -> MaxWithVector(0.0f-tri->normal) + (*offset1) - (tri->vertex[0]) ) );
		
		if( VelocityDistance <= 0.0f && ( tri -> normal.Dot( *(object -> vel) ) < 0.0f ) )
		{
			*(object -> vel) -= tri -> normal * ( VelocityDistance );
		}
		if( ForceDistance <= 0.0f )
		{
			*(object -> force) -= tri -> normal * ForceDistance;
//			*(object -> resistanceforce) = (*(object -> resistanceforce)) - ( ((tri -> normal && (*(object -> vel))) && tri -> normal).Versor() * abs(ForceDistance) );
		}
		
		return COLLISION_IS;
	}
	return COLLISION_NO;
}


