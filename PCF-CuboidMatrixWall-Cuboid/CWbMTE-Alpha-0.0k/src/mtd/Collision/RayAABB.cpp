


inline unsigned int Collision::RayAABB( Vector begin, Vector direction, Vector * place, Vector * offset1, AABB * object )
{
//	float t1, t2, fast;
//	float ood;
	
	float tmin = 0.0f; // set to -FLT_MAX to get first hit on line
	float tmax = (direction-begin).Lenght(); // set to max distance ray can travel (for segment)
	direction = (direction-begin).Versor();
	float t;
	Vector fast;
	
	Vector objbeg = (*offset1) + object->pos;
	Vector objend = (*offset1) + object->pos + object->size;
	
	
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
}


