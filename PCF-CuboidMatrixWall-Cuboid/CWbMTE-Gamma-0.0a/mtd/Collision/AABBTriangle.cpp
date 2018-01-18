

inline unsigned int Collision::AABBTriangle( PhysicModelStatic * object, TrianglePX * tri, float time )
{
	int i;
	Vector pointfast;
	Vector normal = tri -> normal;
	
	Vector begin = object -> pos;
	Vector end = begin + object -> size;
	
	if( (tri->min <= end) && (tri->max >= begin) )
	{
		{
			float p1dot = ((object->MaxWithVector(tri->normal))-(tri->vertex[0])).Dot(tri->normal);
			float p2dot = ((object->MaxWithVector(0.0f-tri->normal))-(tri->vertex[0])).Dot(tri->normal);
			if( ( ( p1dot >= 0.0f && p2dot <= 0.0f ) || ( p1dot <= 0.0f && p2dot >= 0.0f ) ) )
				return COLLISION_NO;
		}
		
		object->contact.AddDirection( tri -> normal );
		
		{
			if( RayAABB( tri->vertex[0], tri->vertex[1], object, &pointfast ) )
				object->contact.AddPoint( pointfast );
			if( RayAABB( tri->vertex[1], tri->vertex[2], object, &pointfast ) )
				object->contact.AddPoint( pointfast );
			if( RayAABB( tri->vertex[2], tri->vertex[0], object, &pointfast ) )
				object->contact.AddPoint( pointfast );
			if( RayAABB( tri->vertex[1], tri->vertex[0], object, &pointfast ) )
				object->contact.AddPoint( pointfast );
			if( RayAABB( tri->vertex[2], tri->vertex[1], object, &pointfast ) )
				object->contact.AddPoint( pointfast );
			if( RayAABB( tri->vertex[0], tri->vertex[2], object, &pointfast ) )
				object->contact.AddPoint( pointfast );
			if( tri->vertex[0] <= end && tri->vertex[0] >= begin )
				object->contact.AddPoint( tri->vertex[0] );
			if( tri->vertex[1] <= end && tri->vertex[1] >= begin )
				object->contact.AddPoint( tri->vertex[1] );
			if( tri->vertex[2] <= end && tri->vertex[2] >= begin )
				object->contact.AddPoint( tri->vertex[2] );
		}
		
		Vector vertex[2][2][2];
		bool vertexpos[2][2][2];
		
		vertex[0][0][0] = object->GetVertex(0);
		vertex[1][0][0] = object->GetVertex(1);
		vertex[1][0][1] = object->GetVertex(2);
		vertex[0][0][1] = object->GetVertex(3);
		vertex[0][1][0] = object->GetVertex(4);
		vertex[1][1][0] = object->GetVertex(5);
		vertex[1][1][1] = object->GetVertex(6);
		vertex[0][1][1] = object->GetVertex(7);
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
					if( x_ == 0 )
					{
						if( vertexpos[x_+1][y_][z_] != vertexpos[x_][y_][z_] )
						{
							fastVec = tri -> GetCrossPoint( vertex[x_+1][y_][z_], vertex[x_][y_][z_] );
							if( fastVec != SetVector( 0.0f, 0.0f, 0.0f ) )
								if( tri -> PointIn( fastVec ) )
									object->contact.AddPoint( fastVec );
						}
					}
					if( y_ == 0 )
					{
						if( vertexpos[x_][y_+1][z_] != vertexpos[x_][y_][z_] )
						{
							fastVec = tri -> GetCrossPoint( vertex[x_][y_+1][z_], vertex[x_][y_][z_] );
							if( fastVec != SetVector( 0.0f, 0.0f, 0.0f ) )
								if( tri -> PointIn( fastVec ) )
									object->contact.AddPoint(fastVec );
						}
					}
					if( z_ == 0 )
					{
						if( vertexpos[x_][y_][z_+1] != vertexpos[x_][y_][z_] )
						{
							fastVec = tri -> GetCrossPoint( vertex[x_][y_][z_+1], vertex[x_][y_][z_] );
							if( fastVec != SetVector( 0.0f, 0.0f, 0.0f ) )
								if( tri -> PointIn( fastVec ) )
									object->contact.AddPoint( fastVec );
						}
					}
				}
			}
		}
		
		
		
		//if( contact.size() == 0 ) return COLLISION_NO;
		return COLLISION_IS;
		/*
		float VelocityLenght = object -> vel -> Length();
		float VelocityDistance = normal.Dot( object -> vel );
		float ForceDistance = normal.Dot( object -> force );
		float PossitionDistanceMinus = ( normal.Versor() ).Dot( object -> MaxWithVector( 0.0f - normal ) + (object->pos) - ( tri -> vertex[0] ) );
		float PossitionDistancePlus = ( normal.Versor() ).Dot( object -> MaxWithVector( normal ) + (object->pos) - ( tri -> vertex[0] ) );
		
		//if( abs(PossitionDistancePlus) * 2.0f < abs(PossitionDistanceMinus) )
		if( VelocityDistance > 0.0f )
		{
//			return COLLISION_NO;
		}
		
		
		Vector contactBarycentric, contactMin = contact[0], contactMax = contact[0], contactSize, MinWithNormal;
		float currentDot = contact[0].Dot( *(object->vel) ), fastDot;
		for( i = 1 ; i < contact.size(); ++i )
		{
			if( contactMin[0] > contact[i][0] ) contactMin[0] = contact[i][0];
			if( contactMin[1] > contact[i][1] ) contactMin[1] = contact[i][1];
			if( contactMin[2] > contact[i][2] ) contactMin[2] = contact[i][2];
			if( contactMax[0] < contact[i][0] ) contactMax[0] = contact[i][0];
			if( contactMax[1] < contact[i][1] ) contactMax[1] = contact[i][1];
			if( contactMax[2] < contact[i][2] ) contactMax[2] = contact[i][2];
		}
		
		
		contactSize = contactMax - contactBarycentric;
		contactBarycentric = ( contactMin + contactMax ) * 0.5f;
		
		fastDot = ( contactBarycentric - ( tri -> vertex[0] ) ).Dot( normal );
		if( fastDot != 0.0f )
		{
			contactBarycentric -= ( normal ) * fastDot;
		}
		
		
		
		
		{	// Calc max defiation from outside to contact barycentric
			MinWithNormal = contactBarycentric - ( normal * 100.0f );
			if( RayAABB( MinWithNormal, contactBarycentric, offset1, object, &pointfast ) == 1 )
			{
//				*offset1 += contactBarycentric - pointfast;
			}
		}
		
		
		
		
		
		
		if( normal[1] < -0.7f )
		{
			object -> CollisionUp = true;
		}
		else if( normal[1] > 0.7f )
		{
			object -> CollisionDown = true;
		}
		else
		{
			object -> CollisionSide = true;
		}
		
		
		if( VelocityDistance <= 0.0f )
		{
			*(object -> vel) -= normal * ( VelocityDistance * 1.01f );
		}
		if( ForceDistance <= 0.0f )
		{
			*(object -> force) -= normal * ForceDistance;
		}
		*/
		
		return COLLISION_IS;
	}
	return COLLISION_NO;
}


