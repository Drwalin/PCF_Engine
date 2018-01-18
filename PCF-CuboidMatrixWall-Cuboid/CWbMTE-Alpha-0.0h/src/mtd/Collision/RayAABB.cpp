
#define EPSILON 0.00001f

inline unsigned int Collision::RayAABB( Vector begin, Vector direction, Vector * place, Vector * offset1, AABB * object )
{
	float t1, t2, fast;
	float ood;
	float tmin = 0.0f; // set to -FLT_MAX to get first hit on line
	float tmax = (direction-begin).Lenght(); // set to max distance ray can travel (for segment)
	direction = (direction-begin).Versor();
	// For all three slabs
	for ( int i = 0; i < 3; i++ )
	{
		if ( abs(direction[i]) < EPSILON )
		{
			// Ray is parallel to slab. No hit if origin not within slab
			if ( begin[i] < (object->pos[i]+(*offset1)[i]) || begin[i] > (object->pos[i]+(*offset1)[i] + object->size[i]) ) return 0;
		}
		else
		{
			// Compute intersection t value of ray with near and far plane of slab
			ood = 1.0f / direction[i];
			t1 = ( object->pos[i]+(*offset1)[i] - begin[i] ) * ood;
			t2 = ( object->pos[i]+(*offset1)[i] + object->size[i] - begin[i] ) * ood;
			// Make t1 be intersection with near plane, t2 with far plane
			if ( t1 > t2 )
			{
				fast = t1;
				t1 = t2;
				t2 = fast;
			}
			// Compute the intersection of slab intersection intervals
			if ( t1 > tmin ) tmin = t1;
			if ( t2 > tmax ) tmax = t2;
			// Exit with no collision as soon as slab intersection becomes empty
			if ( tmin > tmax ) return 0;
		}
	}
	// Ray intersects all 3 slabs. Return point (q) and intersection t value (tmin)
	(*place) = begin + (direction * tmin);
	return 1;
}

#undef EPSILON
