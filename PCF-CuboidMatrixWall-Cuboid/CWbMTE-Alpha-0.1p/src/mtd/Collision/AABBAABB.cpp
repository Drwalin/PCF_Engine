


inline unsigned int Collision::AABBAABB( AABB * object1, Vector * offset1, AABB * object2, Vector * offset2, float time )
{
	Vector min1 = object1 -> pos + *offset1;
	Vector max1 = object1 -> size + min1;
	Vector min2 = object2 -> pos + *offset2;
	Vector max2 = object2 -> size + min2;
	
	Vector stepin1 = max2 - min1;
	Vector stepin2 = max1 - min2;
	if( max2 > min1 && max1 > min2 )
	{
		Vector * stepin = ( stepin1 < stepin2 ) ? &stepin1 : &stepin2 ;
		
		int loweststepinaxis = 0;
		{
			if( abs((*stepin)[1]) < abs((*stepin)[loweststepinaxis]) )
				loweststepinaxis = 1;
			if( abs((*stepin)[2]) < abs((*stepin)[loweststepinaxis]) )
				loweststepinaxis = 2;
		}
		
		if( loweststepinaxis == 1 )
		{
			if( min1[1] < min2[1] )
			{
				object1 -> CollisionUp = true;
				object2 -> CollisionDown = true;
			}
			else
			{
				object1 -> CollisionDown = true;
				object2 -> CollisionUp = true;
			}
		}
		else
		{
			object1 -> CollisionSide = true;
			object2 -> CollisionSide = true;
		}
		
		if( min1[loweststepinaxis] < min2[loweststepinaxis] )
		{
			if( (*(object1->vel)).Lenght() > (*(object2->vel)).Lenght() )
				(*offset1)[loweststepinaxis] -= ((*stepin)[loweststepinaxis]);
			else if( (*(object1->vel)).Lenght() < (*(object2->vel)).Lenght() )
				(*offset2)[loweststepinaxis] += ((*stepin)[loweststepinaxis]);
			else
			{
				(*offset1)[loweststepinaxis] -= ((*stepin)[loweststepinaxis]) * 0.5f;
				(*offset2)[loweststepinaxis] += ((*stepin)[loweststepinaxis]) * 0.5f;
			}
			if( (*(object1->vel))[loweststepinaxis] > 0.0f )
				(*(object1->vel))[loweststepinaxis] = 0.0f;
			if( (*(object2->vel))[loweststepinaxis] < 0.0f )
				(*(object2->vel))[loweststepinaxis] = 0.0f;
		}
		else
		{
			if( (*(object1->vel)).Lenght() > (*(object2->vel)).Lenght() )
				(*offset1)[loweststepinaxis] += ((*stepin)[loweststepinaxis]);
			else if( (*(object1->vel)).Lenght() < (*(object2->vel)).Lenght() )
				(*offset2)[loweststepinaxis] -= ((*stepin)[loweststepinaxis]);
			else
			{
				(*offset1)[loweststepinaxis] += ((*stepin)[loweststepinaxis]) * 0.5f;
				(*offset2)[loweststepinaxis] -= ((*stepin)[loweststepinaxis]) * 0.5f;
			}
		//	(*offset2)[loweststepinaxis] -= ((*stepin)[loweststepinaxis]) / 2.0f;
		//	(*offset1)[loweststepinaxis] += ((*stepin)[loweststepinaxis]) / 2.0f;
			if( (*(object1->vel))[loweststepinaxis] < 0.0f )
				(*(object1->vel))[loweststepinaxis] = 0.0f;
			if( (*(object2->vel))[loweststepinaxis] > 0.0f )
				(*(object2->vel))[loweststepinaxis] = 0.0f;
		}
		
		return 1;
	}
	return 0;
}


