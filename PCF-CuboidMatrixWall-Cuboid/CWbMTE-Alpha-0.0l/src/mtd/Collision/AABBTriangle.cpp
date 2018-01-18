

inline unsigned int Collision::AABBTriangle( AABB * object, Vector * offset1, TrianglePX * tri, float time )
{
	
	unsigned int collision = 0;
	Vector pointfast;
	
	Vector begin = (object -> pos) + *offset1;
	Vector end = begin + (object -> size);
	
	if( (tri->min <= end) && (tri->max >= begin) )
	{
//		Vector point_1 = (object->MaxWithVector(tri->normal))-(tri->vertex[0]);
//		Vector point_2 = (object->MaxWithVector(0.0f-(tri->normal)))-(tri->vertex[0]);
//		if( ( ( point_1.Dot(tri->normal) >= 0.0f && point_2.Dot(tri->normal) <= 0.0f ) || ( point_1.Dot(tri->normal) <= 0.0f && point_2.Dot(tri->normal) >= 0.0f ) ) )
//			return COLLISION_NO;
		
		Vector e = ((end + begin) * 0.5f) + (*offset1);
		
		Vector v0 = tri->vertex[0] - ( e );//*offset1 + object->pos );
		Vector v1 = tri->vertex[1] - ( e );//*offset1 + object->pos );
		Vector v2 = tri->vertex[2] - ( e );//*offset1 + object->pos );
		
		Vector f0 = v1 - v0, f1 = v2 - v1, f2 = v0 - v2;
		
		float p0, p1, p2, r;
		Vector a;
		
		{
			/*
			{
				a.Set( 0.0f, -f0[2], f0[1] );
				p0 = v0.Dot( a );
				p1 = v1.Dot( a );
				p2 = v2.Dot( a );
				r = e[0]*abs(a[0]) + e[1]*abs(a[1]) + e[2]*abs(a[2]);
				if( Max( -Max( p0, p1, p2 ), Min( p0, p1, p2 ) ) > r ) return COLLISION_NO;
			}
			*/
			{
				a.Set( 0.0f, -f0[2], f0[1] );
				p1 = v1.Dot( a );
				p2 = v2.Dot( a );
				r = e[1]*abs(a[1]) + e[2]*abs(a[2]);
				if( Max( -Max( p1, p2 ), Min( p1, p2 ) ) > r ) return COLLISION_NO;
			}
			{
				a.Set( 0.0f, -f1[2], f1[1] );
				p1 = v1.Dot( a );
				p2 = v2.Dot( a );
				r = e[1]*abs(a[1]) + e[2]*abs(a[2]);
				if( Max( -Max( p1, p2 ), Min( p1, p2 ) ) > r ) return COLLISION_NO;
			}
			{
				a.Set( 0.0f, -f2[2], f2[1] );
				p1 = v1.Dot( a );
				p2 = v2.Dot( a );
				r = e[1]*abs(a[1]) + e[2]*abs(a[2]);
				if( Max( -Max( p1, p2 ), Min( p1, p2 ) ) > r ) return COLLISION_NO;
			}
			{
				a.Set( f0[2], 0.0f, -f0[0] );
				p0 = v0.Dot( a );
				p2 = v2.Dot( a );
				r = e[0]*abs(a[0]) + e[2]*abs(a[2]);
				if( Max( -Max( p0, p2 ), Min( p0, p2 ) ) > r ) return COLLISION_NO;
			}
			{
				a.Set( f1[2], 0.0f, -f1[0] );
				p0 = v0.Dot( a );
				p2 = v2.Dot( a );
				r = e[0]*abs(a[0]) + e[2]*abs(a[2]);
				if( Max( -Max( p0, p2 ), Min( p0, p2 ) ) > r ) return COLLISION_NO;
			}
			{
				a.Set( f2[2], 0.0f, -f2[0] );
				p0 = v0.Dot( a );
				p2 = v2.Dot( a );
				r = e[0]*abs(a[0]) + e[2]*abs(a[2]);
				if( Max( -Max( p0, p2 ), Min( p0, p2 ) ) > r ) return COLLISION_NO;
			}
			{
				a.Set( -f0[1], f0[0], 0.0f );
				p0 = v0.Dot( a );
				p1 = v1.Dot( a );
				r = e[0]*abs(a[0]) + e[1]*abs(a[1]);
				if( Max( -Max( p0, p1 ), Min( p0, p1 ) ) > r ) return COLLISION_NO;
			}
			{
				a.Set( -f1[1], f1[0], 0.0f );
				p0 = v0.Dot( a );
				p1 = v1.Dot( a );
				r = e[0]*abs(a[0]) + e[1]*abs(a[1]);
				if( Max( -Max( p0, p1 ), Min( p0, p1 ) ) > r ) return COLLISION_NO;
			}
			{
				a.Set( -f2[1], f2[0], 0.0f );
				p0 = v0.Dot( a );
				p1 = v1.Dot( a );
				r = e[0]*abs(a[0]) + e[1]*abs(a[1]);
				if( Max( -Max( p0, p1 ), Min( p0, p1 ) ) > r ) return COLLISION_NO;
			}
		}
		
		goto CALC_REACTION_FORCES_AND_VELOCITY_REFLECTION;
	}
	else
	{
		return COLLISION_NO;
	}
	
	
	
	
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


