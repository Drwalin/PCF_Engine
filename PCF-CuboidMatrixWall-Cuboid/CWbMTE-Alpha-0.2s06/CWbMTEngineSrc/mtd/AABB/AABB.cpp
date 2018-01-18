




inline Vector AABB::MaxWithVector( Vector dst )
{
	Vector point = pos + ( size * 0.5f );
	if( pos[0] < 0.0f )			point[0] = pos[0];
	else if( pos[0] > 0.0f )	point[0] = pos[0] + size[0];
	if( pos[1] < 0.0f )			point[1] = pos[1];
	else if( pos[1] > 0.0f )	point[1] = pos[1] + size[1];
	if( pos[2] < 0.0f )			point[2] = pos[2];
	else if( pos[2] > 0.0f )	point[2] = pos[2] + size[2];
	return point;
}

inline Vector AABB::ClosesPoint( Vector dst )
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

inline Vector AABB::GetVertex( int id )
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



AABB::AABB()
{
	pos.Set( 0.0f, 0.0f, 0.0f );
	size.Set( 0.6f, 1.75f, 0.6f );
	vel = NULL;
	force = NULL;
	resistanceforce = NULL;
	
	mass = 75.0f;
    
    CollisionDown = false;
    CollisionUp = false;
    CollisionSide = false;
}

AABB::~AABB()
{
	pos.Set( 0.0f, 0.0f, 0.0f );
	size.Set( 0.0f, 0.0f, 0.0f );
	vel = NULL;
	force = NULL;
	resistanceforce = NULL;
	
	mass = 0.0f;
    
    CollisionDown = false;
    CollisionUp = false;
    CollisionSide = false;
}



