

inline unsigned int Collision::AABBTriangle( AABB * object, Vector * offset1, Vector backOffset1, TrianglePX * tri, float time )
{
	int i;
	unsigned int collision = 0;
	Vector pointfast;
	
	Vector begin = (object -> pos) + *offset1;
	Vector end = begin + object -> size;
	
	vector < Vector > contact;
	
	if( (tri->min <= end) && (tri->max >= begin) )
	{
		{
			float p1dot = ((object->MaxWithVector(tri->normal))-(tri->vertex[0])+(*offset1)).Dot(tri->normal);
			float p2dot = ((object->MaxWithVector(0.0f-tri->normal))-(tri->vertex[0])+(*offset1)).Dot(tri->normal);
			if( ( ( p1dot >= 0.0f && p2dot <= 0.0f ) || ( p1dot <= 0.0f && p2dot >= 0.0f ) ) )
				return COLLISION_NO;
		}
		
		{
			if( RayAABB( tri->vertex[0], tri->vertex[1], offset1, object, &pointfast ) )
				contact.push_back( pointfast );
			if( RayAABB( tri->vertex[1], tri->vertex[2], offset1, object, &pointfast ) )
				contact.push_back( pointfast );
			if( RayAABB( tri->vertex[2], tri->vertex[0], offset1, object, &pointfast ) )
				contact.push_back( pointfast );
			if( tri->vertex[0] <= end && tri->vertex[0] >= begin )
				contact.push_back( tri->vertex[0] );
			if( tri->vertex[1] <= end && tri->vertex[1] >= begin )
				contact.push_back( tri->vertex[1] );
			if( tri->vertex[2] <= end && tri->vertex[2] >= begin )
				contact.push_back( tri->vertex[2] );
		}
		
//		if( (tri->min >= begin) && (tri->max <= end) )
//			goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
		
		Vector vertex[2][2][2];
		bool vertexpos[2][2][2];
		
		vertex[0][0][0] = object->GetVertex(0) + (*offset1);
		vertex[1][0][0] = object->GetVertex(1) + (*offset1);
		vertex[1][0][1] = object->GetVertex(2) + (*offset1);
		vertex[0][0][1] = object->GetVertex(3) + (*offset1);
		vertex[0][1][0] = object->GetVertex(4) + (*offset1);
		vertex[1][1][0] = object->GetVertex(5) + (*offset1);
		vertex[1][1][1] = object->GetVertex(6) + (*offset1);
		vertex[0][1][1] = object->GetVertex(7) + (*offset1);
		vertexpos[0][0][0] = ( ((vertex[0][0][0] - (tri->vertex[0])).Dot( tri->normal )) < 0.0f ) ? false : true;
		vertexpos[0][0][1] = ( ((vertex[0][0][1] - (tri->vertex[0])).Dot( tri->normal )) < 0.0f ) ? false : true;
		vertexpos[0][1][0] = ( ((vertex[0][1][0] - (tri->vertex[0])).Dot( tri->normal )) < 0.0f ) ? false : true;
		vertexpos[0][1][1] = ( ((vertex[0][1][1] - (tri->vertex[0])).Dot( tri->normal )) < 0.0f ) ? false : true;
		vertexpos[1][0][0] = ( ((vertex[1][0][0] - (tri->vertex[0])).Dot( tri->normal )) < 0.0f ) ? false : true;
		vertexpos[1][0][1] = ( ((vertex[1][0][1] - (tri->vertex[0])).Dot( tri->normal )) < 0.0f ) ? false : true;
		vertexpos[1][1][0] = ( ((vertex[1][1][0] - (tri->vertex[0])).Dot( tri->normal )) < 0.0f ) ? false : true;
		vertexpos[1][1][1] = ( ((vertex[1][1][1] - (tri->vertex[0])).Dot( tri->normal )) < 0.0f ) ? false : true;
		
		Vector fastVec;
		int x_, y_, z_;
		
		for( x_ = 0; x_ < 2; ++x_ )
		{	
			for( y_ = 0; y_ < 2; ++y_ )
			{
				for( z_ = 0; z_ < 2; ++z_ )
				{
//					if( vertexpos[x_][y_][z_] == true )
					{
						if( x_ == 0 )
						{
							if( vertexpos[x_+1][y_][z_] != vertexpos[x_][y_][z_] )
							{
								fastVec = tri -> GetCrossPoint( vertex[x_+1][y_][z_], vertex[x_][y_][z_] );
								if( fastVec != SetVector( 0.0f, 0.0f, 0.0f ) )
									if( tri -> PointIn( fastVec ) )
										contact.push_back( fastVec );
							}
						}
						if( y_ == 0 )
						{
							if( vertexpos[x_][y_+1][z_] != vertexpos[x_][y_][z_] )
							{
								fastVec = tri -> GetCrossPoint( vertex[x_][y_+1][z_], vertex[x_][y_][z_] );
								if( fastVec != SetVector( 0.0f, 0.0f, 0.0f ) )
									if( tri -> PointIn( fastVec ) )
										contact.push_back( fastVec );
							}
						}
						if( z_ == 0 )
						{
							if( vertexpos[x_][y_][z_+1] != vertexpos[x_][y_][z_] )
							{
								fastVec = tri -> GetCrossPoint( vertex[x_][y_][z_+1], vertex[x_][y_][z_] );
								if( fastVec != SetVector( 0.0f, 0.0f, 0.0f ) )
									if( tri -> PointIn( fastVec ) )
										contact.push_back( fastVec );
							}
						}
					}
				}
			}
		}
		
		if( contact.size() == 0 ) return COLLISION_NO;
		
		float VelocityLenght = object -> vel -> Lenght();
		float VelocityDistance = tri -> normal.Dot( *(object -> vel) );
		float ForceDistance = tri -> normal.Dot( *(object -> force) );
		float PossitionDistanceMinus = ( tri -> normal.Versor() ).Dot( object -> MaxWithVector( 0.0f - tri -> normal ) + (*offset1) - ( tri -> vertex[0] ) );
		float PossitionDistancePlus = ( tri -> normal.Versor() ).Dot( object -> MaxWithVector( tri -> normal ) + (*offset1) - ( tri -> vertex[0] ) );
		
		Vector contactBarycentric, contactMin = contact[0], contactMax = contact[0], contactSize, backBegin, backEnd;
		int i;
		int MinWithVelInt = 0;
		Vector MinWithVel = contact[0], MaxWithVel = SetVector( 0.0f, 0.0f, 0.0f );
		float currentDot = contact[0].Dot( *(object->vel) ), fastDot;
		for( i = 1 ; i < contact.size(); ++i )
		{
			if( contactMin[0] > contact[i][0] ) contactMin[0] = contact[i][0];
			if( contactMin[1] > contact[i][1] ) contactMin[1] = contact[i][1];
			if( contactMin[2] > contact[i][2] ) contactMin[2] = contact[i][2];
			if( contactMax[0] < contact[i][0] ) contactMax[0] = contact[i][0];
			if( contactMax[1] < contact[i][1] ) contactMax[1] = contact[i][1];
			if( contactMax[2] < contact[i][2] ) contactMax[2] = contact[i][2];
			fastDot = contact[i].Dot( *(object->vel) );
			if( fastDot < currentDot )
			{
				currentDot = fastDot;
				MinWithVelInt = i;
				MinWithVel = contact[i];
			}
		}
		
		printf( "\n     Contact size: %i", (int)contact.size() );
		
		contactBarycentric = ( contactMin + contactMax ) * 0.5f;
		contactSize = contactMax - contactBarycentric;
		backBegin = backOffset1;
		backEnd = backBegin + object -> size;
		
		{	// Calc MaxWithVel from MinWithVel
			MaxWithVel = MinWithVel + ((*(object->vel))*100.0f);
			pointfast = MaxWithVel;
			if( RayAABB( pointfast, MinWithVel, offset1, object, &MaxWithVel ) == 1 )
				*offset1 += MinWithVel - MaxWithVel;
		}
		
		
		
		
		
		/*
		if( VelocityDistance / VelocityLenght > 0.2f )
		{
			return COLLISION_NO;
		}
		else if( VelocityDistance / VelocityLenght < 0.5f && VelocityDistance > -0.5f )
		{
			
		}
		if( abs(PossitionDistancePlus) < abs(PossitionDistanceMinus) )
		{
			return COLLISION_NO;
		}
		*/
		
		
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
		
		
		
		if( VelocityDistance <= 0.0f )
		{
			*(object -> vel) -= tri -> normal * ( VelocityDistance ) * 1.2f;
		}
		if( ForceDistance <= 0.0f )
		{
			*(object -> force) -= tri -> normal * ForceDistance;
		}
		
		
		
		return COLLISION_IS;
	}
	return COLLISION_NO;
}


