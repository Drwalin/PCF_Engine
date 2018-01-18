


#define EPSILON 0.0001f

inline unsigned int Collision::RayAABB( Vector p0, Vector p1, Vector * offset1, AABB * object )
{
	//int TestSegmentAABB(Vector p0, Vector p1, AABB b)
	
	Vector objbeg = (*offset1) + object->pos;
	Vector objend = (*offset1) + object->pos + object->size;
	
	
	Vector c = (objbeg + objend) * 0.5f; // Box center-point
	Vector e = objend - c; // Box halflength extents
	Vector m = (p0 + p1) * 0.5f; // Segment midpoint
	Vector d = p1 - m; // Segment halflength vector
	m = m - c; // Translate box and segment to origin
	// Try world coordinate axes as separating axes
	float adx = abs(d[0]);
	if( abs(m[0]) > e[0] + adx ) return 0;
	float ady = abs(d[1]);
	if( abs(m[1]) > e[1] + ady ) return 0;
	float adz = abs(d[2]);
	if( abs(m[2]) > e[2] + adz ) return 0;
	// Add in an epsilon term to counteract arithmetic errors when segment is
	// (near) parallel to a coordinate axis (see text for detail)
	adx += EPSILON; ady += EPSILON; adz += EPSILON;
	// Try cross products of segment direction vector with coordinate axes
	if( abs( ( m[1] * d[2] ) - ( m[2] * d[1] ) ) > ( e[1] * adz ) + ( e[2] * ady ) ) return 0;
	if( abs( ( m[2] * d[0] ) - ( m[0] * d[2] ) ) > ( e[0] * adz ) + ( e[2] * adx ) ) return 0;
	if( abs( ( m[0] * d[1] ) - ( m[1] * d[0] ) ) > ( e[0] * ady ) + ( e[1] * adx ) ) return 0;
	// No separating axis found; segment must be overlapping AABB
	return 1;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*
	
//	float t1, t2, fast;
//	float ood;
	
	float tmin = 0.0f; // set to -FLT_MAX to get first hit on line
	float tmax = (direction-begin).Lenght(); // set to max distance ray can travel (for segment)
	direction = (direction-begin).Versor();
	float t;
	Vector fast;
	
	
	
	if( direction[0] != 0 )
	{	// X begin
		t = ( objbeg[0] - begin[0] ) / ( direction[0] );
		if( t <= tmax && t >= tmin )
		{
			fast = begin + (direction*t);
			if( (fast >= ( objbeg )) && (fast <= ( objend )) )
			{
				(*place) = fast;
				return 1;
			}
		}
	}
	
	if( direction[1] != 0 )
	{	// Y begin
		t = ( objbeg[1] - begin[1] ) / ( direction[1] );
		if( t <= tmax && t >= tmin )
		{
			fast = begin + (direction*t);
			if( (fast >= ( objbeg )) && (fast <= ( objend )) )
			{
				(*place) = fast;
				return 1;
			}
		}
	}
	
	if( direction[2] != 0 )
	{	// Z begin
		t = ( objbeg[2] - begin[2] ) / ( direction[2] );
		if( t <= tmax && t >= tmin )
		{
			fast = begin + (direction*t);
			if( (fast >= ( objbeg )) && (fast <= ( objend )) )
			{
				(*place) = fast;
				return 1;
			}
		}
	}
	
	if( direction[0] != 0 )
	{	// X end
		t = ( objend[0] - begin[0] ) / ( direction[0] );
		if( t <= tmax && t >= tmin )
		{
			fast = begin + (direction*t);
			if( (fast >= ( objbeg )) && (fast <= ( objend )) )
			{
				(*place) = fast;
				return 1;
			}
		}
	}
	
	if( direction[1] != 0 )
	{	// Y end
		t = ( objend[1] - begin[1] ) / ( direction[1] );
		if( t <= tmax && t >= tmin )
		{
			fast = begin + (direction*t);
			if( (fast >= ( objbeg )) && (fast <= ( objend )) )
			{
				(*place) = fast;
				return 1;
			}
		}
	}
	
	if( direction[2] != 0 )
	{	// Z end
		t = ( objend[2] - begin[2] ) / ( direction[2] );
		if( t <= tmax && t >= tmin )
		{
			fast = begin + (direction*t);
			if( (fast >= ( objbeg )) && (fast <= ( objend )) )
			{
				(*place) = fast;
				return 1;
			}
		}
	}
	
	
	return 0;
	*/
}


