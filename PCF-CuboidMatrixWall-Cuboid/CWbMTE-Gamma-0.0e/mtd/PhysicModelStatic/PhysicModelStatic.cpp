


inline Vector PhysicModelStatic::MaxWithVector( Vector dst )
{
	Vector p = pos + (size*0.5f);
	if( dst[0] < 0.0f )
		p[0] = pos[0];
	else if( dst[0] > 0.0f )
		p[0] = pos[0] + size[0];
	if( dst[1] < 0.0f )
		p[1] = pos[1];
	else if( dst[1] > 0.0f )
		p[1] = pos[1] + size[1];
	if( dst[2] < 0.0f )
		p[2] = pos[2];
	else if( dst[2] > 0.0f )
		p[2] = pos[2] + size[2];
	return p;
}

inline Vector PhysicModelStatic::ClosesPoint( Vector dst )
{
	Vector point = dst;
	if( dst[0] < pos[0] )					point[0] = pos[0];
	else if( dst[0] > pos[0]+size[0] )		point[0] = pos[0] + size[0];
	if( dst[1] < pos[1] )					point[1] = pos[1];
	else if( dst[1] > pos[1]+size[1] )		point[1] = pos[1] + size[1];
	if( dst[2] < pos[2] )					point[2] = pos[2];
	else if( dst[2] > pos[2]+size[2] )		point[2] = pos[2] + size[2];
	return point;
}

inline Vector PhysicModelStatic::GetVertex( int id )
{
	switch( ((unsigned int)id)%8 )
	{
	case 0:
		return SetVector( pos[0], pos[1], pos[2] );
	case 1:
		return SetVector( pos[0]+size[0], pos[1], pos[2] );
	case 2:
		return SetVector( pos[0]+size[0], pos[1], pos[2]+size[2] );
	case 3:
		return SetVector( pos[0], pos[1], pos[2]+size[2] );
	case 4:
		return SetVector( pos[0], pos[1]+size[1], pos[2] );
	case 5:
		return SetVector( pos[0]+size[0], pos[1]+size[1], pos[2] );
	case 6:
		return SetVector( pos[0]+size[0], pos[1]+size[1], pos[2]+size[2] );
	case 7:
		return SetVector( pos[0], pos[1]+size[1], pos[2]+size[2] );
	}
	return SetVector( 0.0f, 0.0f, 0.0f );
}








inline Vector PhysicModelStatic::GetMin()
{
	return min;
}

inline Vector PhysicModelStatic::GetMax()
{
	return max;
}

inline float PhysicModelStatic::GetMass()
{
	return mass;
}

inline void PhysicModelStatic::UpdatePossition( float time )
{
	bpos = pos;
	pos += vel * time;
	min = pos;
	max = pos + size;
}

inline void PhysicModelStatic::UpdateVelocity( float time )
{
	vel += force * time / mass;
}

inline void PhysicModelStatic::IdentityForce()
{
	force.Set( 0.0f, 0.0f, 0.0f );
}

inline void PhysicModelStatic::IdentityCollisions()
{
	CollisionUp = false;
	CollisionSide = false;
	CollisionDown = false;
	contact.Clear();
}

inline void PhysicModelStatic::SetGameLogicObject( void * src )
{
	GameLogicObject = src;
}

inline void * PhysicModelStatic::GetGameLogicObject()
{
	return GameLogicObject;
}

inline void PhysicModelStatic::AddRayType( unsigned int src )
{
	if( src == 0 )
		return;
	int i;
	for( i = 0; i < rayType.size(); i++ )
		if( rayType[i] == src )
			return;
	rayType.push_back( src );
}

inline bool PhysicModelStatic::CheckRayType( unsigned int src )
{
	if( src == 0 )
		return true;
	int i;
	for( i = 0; i < rayType.size(); i++ )
		if( rayType[i] == src )
			return true;
	return false;
}

PhysicModelStatic::PhysicModelStatic()
{
	bpos.Set( 0.0f, 0.0f, 0.0f );
	pos.Set( 0.0f, 0.0f, 0.0f );
	vel.Set( 0.0f, 0.0f, 0.0f );
	force.Set( 0.0f, 0.0f, 0.0f );
	
	mass = 75.0f;
	
	see[0] = 0.0f;
	see[1] = 0.0f;
	seeaspect = 90.0f;
	
	TerrainCollisionUse = true;
	RayCollisionUse = true;
	ObjectsCollisionUse = true;
	Draw = false;
	MoveUse = true;
	
	GameLogicObject = NULL;
	
	model = NULL;
	
	MainVectorId = 0;
	
	CollisionUp = false;
	CollisionSide = false;
	CollisionDown = false;
}

PhysicModelStatic::~PhysicModelStatic()
{
	GameLogicObject = NULL;
	
	bpos.Set( 0.0f, 0.0f, 0.0f );
	pos.Set( 0.0f, 0.0f, 0.0f );
	vel.Set( 0.0f, 0.0f, 0.0f );
	force.Set( 0.0f, 0.0f, 0.0f );
	
	mass = 75.0f;
	
	see[0] = 0.0f;
	see[1] = 0.0f;
	seeaspect = 0.0f;
	
	TerrainCollisionUse = false;
	RayCollisionUse = false;
	ObjectsCollisionUse = false;
	Draw = false;
	MoveUse = false;
	
	model = NULL;
	
	MainVectorId = 0;
	
	rayType.resize( 0 );
	
	CollisionUp = false;
	CollisionSide = false;
	CollisionDown = false;
}

inline void PhysicModelStatic::ReactAfterCollisionDetection()
{
	if( contact.WasIntersection() == false )
		return;
	
	Vector direction = contact.GetMediumDirection();
	int i, j;
	Collision collision;
	
	Vector faceBarycentric, distantPoint, intersectPoint;
	
	float moveLength = 0.0f, fastMove;
	
	float diagonal = size.Lenght();
	
	for( i = 0; i < contact.points.size(); ++i )
	{
		faceBarycentric = contact.GetFaceBarycentic( i );
		distantPoint = faceBarycentric - ( direction * diagonal );
		collision.RayAABB( distantPoint, faceBarycentric, this, &intersectPoint );
		fastMove = ( intersectPoint - faceBarycentric ).Lenght();
		if( moveLength < fastMove )
			moveLength = fastMove;
	}
	
	if( moveLength != 0.0f )
		pos += direction * moveLength;
}


