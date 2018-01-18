


inline float PhysicModelStatic::GetMass()
{
	float mass = 0.0f;
	unsigned int i = 0;
	for( i = 0; i < aabb.size(); i++ )
		mass += aabb[i].mass;
	for( i = 0; i < obb.size(); i++ )
		mass += obb[i].mass;
	for( i = 0; i < sphere.size(); i++ )
		mass += sphere[i].mass;
	return mass;
}

inline Vector PhysicModelStatic::GetMin()
{
	return min;
}

inline Vector PhysicModelStatic::GetMax()
{
	return max;
}

inline float PhysicModelStatic::GetMinX()
{
	return min[0];
}

inline float PhysicModelStatic::GetMinY()
{
	return min[1];
}

inline float PhysicModelStatic::GetMinZ()
{
	return min[2];
}

inline float PhysicModelStatic::GetMaxX()
{
	return max[0];
}

inline float PhysicModelStatic::GetMaxY()
{
	return max[1];
}

inline float PhysicModelStatic::GetMaxZ()
{
	return max[2];
}



inline void PhysicModelStatic::UpdatePossition( float time )
{
	bpos = pos;
	pos += vel * time;
	int i = 0;
	min.Set(  10000000.0f,  10000000.0f,  10000000.0f );
	max.Set( -10000000.0f, -10000000.0f, -10000000.0f );
		
	for( i = 0; i < aabb.size(); i++ )
	{
		if( aabb[i].pos[0] < min[0] )
			min[0] = aabb[i].pos[0];
		if( aabb[i].pos[1] < min[1] )
			min[1] = aabb[i].pos[1];
		if( aabb[i].pos[2] < min[2] )
			min[2] = aabb[i].pos[2];
		
		if( aabb[i].pos[0]+aabb[i].size[0] > max[0] )
			max[0] = aabb[i].pos[0]+aabb[i].size[0];
		if( aabb[i].pos[1]+aabb[i].size[1] > max[1] )
			max[1] = aabb[i].pos[1]+aabb[i].size[1];
		if( aabb[i].pos[2]+aabb[i].size[2] > max[2] )
			max[2] = aabb[i].pos[2]+aabb[i].size[2];
	}
	for( i = 0; i < obb.size(); i++ )
	{
		
	}
	for( i = 0; i < sphere.size(); i++ )
	{
		if( sphere[i].pos[0]-sphere[i].radian < min[0] )
			min[0] = sphere[i].pos[0]-sphere[i].radian;
		if( sphere[i].pos[1]-sphere[i].radian < min[1] )
			min[1] = sphere[i].pos[1]-sphere[i].radian;
		if( sphere[i].pos[2]-sphere[i].radian < min[2] )
			min[2] = sphere[i].pos[2]-sphere[i].radian;
		
		if( sphere[i].pos[0]+sphere[i].radian > max[0] )
			max[0] = sphere[i].pos[0]+sphere[i].radian;
		if( sphere[i].pos[1]+sphere[i].radian > max[1] )
			max[1] = sphere[i].pos[1]+sphere[i].radian;
		if( sphere[i].pos[2]+sphere[i].radian > max[2] )
			max[2] = sphere[i].pos[2]+sphere[i].radian;
	}
	min = min + pos;
	max = max + pos;
}

inline void PhysicModelStatic::UpdateVelocity( float time )
{
	float mass = GetMass();
	vel += force * time / mass;
	vel += resistanceforce * time / mass;
}

inline void PhysicModelStatic::IdentityForce()
{
	force.Set( 0.0f, 0.0f, 0.0f );
	resistanceforce.Set( 0.0f, 0.0f, 0.0f );
	for( int i = 0; i < aabb.size(); i++ )
	{
		aabb[i].CollisionDown = false;
		aabb[i].CollisionUp = false;
		aabb[i].CollisionSide = false;
	}
}



PhysicModelStatic::PhysicModelStatic()
{
	bpos.Set( 0.0f, 0.0f, 0.0f );
	pos.Set( 0.0f, 0.0f, 0.0f );
	vel.Set( 0.0f, 0.0f, 0.0f );
	force.Set( 0.0f, 0.0f, 0.0f );
	resistanceforce.Set( 0.0f, 0.0f, 0.0f );
	
	see[0] = 0.0f;
	see[1] = 0.0f;
	seeaspect = 90.0f;
	
	CollisionUse = true;
	Draw = false;
	MoveUse = true;
	
	aabb.resize( 1 );
	obb.resize( 0 );
	sphere.resize( 0 );
	
	model = NULL;
}

PhysicModelStatic::~PhysicModelStatic()
{
	bpos.Set( 0.0f, 0.0f, 0.0f );
	pos.Set( 0.0f, 0.0f, 0.0f );
	vel.Set( 0.0f, 0.0f, 0.0f );
	force.Set( 0.0f, 0.0f, 0.0f );
	resistanceforce.Set( 0.0f, 0.0f, 0.0f );
	
	see[0] = 0.0f;
	see[1] = 0.0f;
	seeaspect = 0.0f;
	
	CollisionUse = false;
	Draw = false;
	MoveUse = false;
	
	aabb.resize( 0 );
	obb.resize( 0 );
	sphere.resize( 0 );
	
	model = NULL;
}


