


#define EPSILON 0.0001f

inline unsigned int Collision::RayAABB( Vector p0, Vector p1, Vector * offset1, AABB * object )
{
	if( false )
	{
		
		Vector p = p0 - *offset1;
		Vector direction = p1 - p0;
		float length = direction.Lenght();
		direction = direction / length;
		float tf = -1.0f, t = length + 10.0f;
		Vector fast;
		
		if( direction[0] != 0.0f )
		{	// X axis
			tf = ( p[0]-object->size[0] ) * 1.0f / ( direction[0] );
			fast = p + (direction * tf);
			if( ((fast>(0.0f))) && ((fast<(object->size))) )
				t = tf;
			tf = ( p[0] ) * 1.0f / ( direction[0] );
			if( tf < t )
			{
				fast = p + (direction * tf);
				if( ((fast>(0.0f))) && ((fast<(object->size))) )
					t = tf;
			}
		}
		
		if( direction[1] != 0.0f )
		{
			tf = ( p[1]-object->size[1] ) * 1.0f / ( direction[1] );
			if( tf < t )
			{
				fast = p + (direction * tf);
				if( ((fast>(0.0f))) && ((fast<(object->size))) )
					t = tf;
			}
			tf = ( p[1] ) * 1.0f / ( direction[1] );
			if( tf < t )
			{
				fast = p + (direction * tf);
				if( ((fast>(0.0f))) && ((fast<(object->size))) )
					t = tf;
			}
		}
		
		if( direction[2] != 0.0f )
		{
			tf = ( p[2]-object->size[2] ) * 1.0f / ( direction[2] );
			if( tf < t )
			{
				fast = p + (direction * tf);
				if( ((fast>(0.0f))) && ((fast<(object->size))) )
					t = tf;
			}
			tf = ( p[2] ) * 1.0f / ( direction[2] );
			if( tf < t )
			{
				fast = p + (direction * tf);
				if( ((fast>(0.0f))) && ((fast<(object->size))) )
					t = tf;
			}
		}
		
		if( t > 0.0f && t < length )
			return 1;
	}
	else
	{
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
	}
	return 0;
}

#undef EPSILON


