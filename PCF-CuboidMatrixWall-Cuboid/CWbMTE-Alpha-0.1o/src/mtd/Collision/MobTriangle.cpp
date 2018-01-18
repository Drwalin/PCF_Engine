


inline unsigned int Collision::MobTriangle( NPC * object, Vector * offset1, TrianglePX * tri, float time )
{
	Vector vertex[9];
	Vector point[2];
	Vector begin = (object -> pos) + *offset1;
	Vector end = begin + object -> size;
	Vector size_ = object -> size;
	
	{	// vertex 1 : [0;0;0]
		vertex[0] = tri -> ClosestPoint( begin );
		if( vertex[0] < end && vertex[0] > begin ){ goto CLAC_REACTION_FORCES_AND_VELOCITY_REFLECTION; }
	}
	{	// vertex 1 : [0;0;1]
		vertex[1] = tri -> ClosestPoint( begin + SetVector( 0.0f, 0.0f, size_[2] ) );
		if( vertex[1] < end && vertex[1] > begin ){ goto CLAC_REACTION_FORCES_AND_VELOCITY_REFLECTION; }
	}
	{	// vertex 1 : [0;1;0]
		vertex[2] = tri -> ClosestPoint( begin + SetVector( 0.0f, size_[1], 0.0f ) );
		if( vertex[2] < end && vertex[2] > begin ){ goto CLAC_REACTION_FORCES_AND_VELOCITY_REFLECTION; }
	}
	{	// vertex 1 : [0;1;1]
		vertex[3] = tri -> ClosestPoint( begin + SetVector( 0.0f, size_[1], size_[2] ) );
		if( vertex[3] < end && vertex[3] > begin ){ goto CLAC_REACTION_FORCES_AND_VELOCITY_REFLECTION; }
	}
	{	// vertex 1 : [1;0;0]
		vertex[4] = tri -> ClosestPoint( begin + SetVector( size_[0], 0.0f, 0.0f ) );
		if( vertex[4] < end && vertex[4] > begin ){ goto CLAC_REACTION_FORCES_AND_VELOCITY_REFLECTION; }
	}
	{	// vertex 1 : [1;0;1]
		vertex[5] = tri -> ClosestPoint( begin + SetVector( size_[0], 0.0f, size_[2] ) );
		if( vertex[5] < end && vertex[5] > begin ){ goto CLAC_REACTION_FORCES_AND_VELOCITY_REFLECTION; }
	}
	{	// vertex 1 : [1;1;0]
		vertex[6] = tri -> ClosestPoint( begin + SetVector( size_[0], size_[1], 0.0f ) );
		if( vertex[6] < end && vertex[6] > begin ){ goto CLAC_REACTION_FORCES_AND_VELOCITY_REFLECTION; }
	}
	{	// vertex 1 : [1;1;1]
		vertex[7] = tri -> ClosestPoint( begin + size_ );
		if( vertex[7] < end && vertex[7] > begin ){ goto CLAC_REACTION_FORCES_AND_VELOCITY_REFLECTION; }
	}
	{	// vertex 1 : [0.5;0.5;0.5]
		vertex[8] = tri -> ClosestPoint( begin + (size_ * 0.5f) );
		if( vertex[8] < end && vertex[8] > begin ){ goto CLAC_REACTION_FORCES_AND_VELOCITY_REFLECTION; }
	}
	
	if( false )
	{
		CLAC_REACTION_FORCES_AND_VELOCITY_REFLECTION:
		
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
		
		vertex[0] = object -> MaxWithVector( 0.0f - tri -> normal );
		
		float VelocityDistance = tri -> normal.Dot( (object -> vel) );
		float PossitionDistance = ( tri -> normal ).Dot( vertex[0] - ( tri -> vertex[0] ) );
		float ForceDistance = tri -> normal.Dot( (object -> force) );
		
		if( VelocityDistance < 0.0f )
		{
			(object -> vel) -= tri -> normal * ( VelocityDistance * 2.0f );
		}
		if( ForceDistance < 0.0f )
		{
			(object -> force) -= tri -> normal * ForceDistance;
			//*(object -> resistanceforce) = (*(object -> resistanceforce)) - ( ((tri -> normal && (*(object -> vel))) && tri -> normal).Versor() * abs(ForceDistance) );
		}
		
		return COLLISION_IS;
	}
	return COLLISION_NO;
}


