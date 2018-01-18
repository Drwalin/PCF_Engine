


inline unsigned int Collision::AABBAABB( AABB * object1, Vector * offset1, AABB * object2, Vector * offset2, float time )
{
	float EPSILON = 0.001f;
	Vector min1 = object1 -> pos + *offset1;
	Vector max1 = object1 -> size + min1;
	Vector min2 = object2 -> pos + *offset2;
	Vector max2 = object2 -> size + min2;
	
	if( max2 > min1 && max1 > min2 )
	{
		Vector stepin;
		float fast1 = -1.0f, fast2 = -1.0f;
		if( abs(max2[0]-min2[0]) + EPSILON > abs((min1[0])-max2[0]) + abs((min1[0])-min2[0]) )			fast1 = min1[0];
		else if( abs(max2[0]-min2[0]) + EPSILON > abs((max1[0])-max2[0]) + abs((max1[0])-min2[0]) )		fast1 = max1[0];
		if( abs(max1[0]-min1[0]) + EPSILON > abs((min2[0])-max1[0]) + abs((min2[0])-min1[0]) )			fast2 = min2[0];
		else if( abs(max1[0]-min1[0]) + EPSILON > abs((max2[0])-max1[0]) + abs((max2[0])-min1[0]) )		fast2 = max2[0];
		stepin[0] = abs( fast1 - fast2 );
		fast1 = -1.0f;
		fast2 = -1.0f;
		if( abs(max2[1]-min2[1]) + EPSILON > abs((min1[1])-max2[1]) + abs((min1[1])-min2[1]) )			fast1 = min1[1];
		else if( abs(max2[1]-min2[1]) + EPSILON > abs((max1[1])-max2[1]) + abs((max1[1])-min2[1]) )		fast1 = max1[1];
		if( abs(max1[1]-min1[1]) + EPSILON > abs((min2[1])-max1[1]) + abs((min2[1])-min1[1]) )			fast2 = min2[1];
		else if( abs(max1[1]-min1[1]) + EPSILON > abs((max2[1])-max1[1]) + abs((max2[1])-min1[1]) )		fast2 = max2[1];
		stepin[1] = abs( fast1 - fast2 );
		fast1 = -1.0f;
		fast2 = -1.0f;
		if( abs(max2[2]-min2[2]) + EPSILON > abs((min1[2])-max2[2]) + abs((min1[2])-min2[2]) )			fast1 = min1[2];
		else if( abs(max2[2]-min2[2]) + EPSILON > abs((max1[2])-max2[2]) + abs((max1[2])-min2[2]) )		fast1 = max1[2];
		if( abs(max1[2]-min1[2]) + EPSILON > abs((min2[2])-max1[2]) + abs((min2[2])-min1[2]) )			fast2 = min2[2];
		else if( abs(max1[2]-min1[2]) + EPSILON > abs((max2[2])-max1[2]) + abs((max2[2])-min1[2]) )		fast2 = max2[2];
		stepin[2] = abs( fast1 - fast2 );
		
		
		int loweststepinaxis = 0;
		{
			/*
			if( abs((*stepin)[1]) < abs(stepin[loweststepinaxis]) )
				loweststepinaxis = 1;
			if( abs((*stepin)[2]) < abs(stepin[loweststepinaxis]) )
				loweststepinaxis = 2;
			*/
			
			if( stepin[1] < stepin[loweststepinaxis] )
				loweststepinaxis = 1;
			if( stepin[2] < stepin[loweststepinaxis] )
				loweststepinaxis = 2;
		}
		
		printf( "\n %8.8f :: %8.8f :: %8.8f", stepin[0], stepin[1], stepin[2] );
		
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
		
		
		if( (*(object1->vel)).Lenght() > (*(object2->vel)).Lenght() )
		{
			(*(object1->vel))[loweststepinaxis] = 0.0f;
			if( min1[loweststepinaxis] < min2[loweststepinaxis] )
				(*offset1)[loweststepinaxis] -= abs(stepin[loweststepinaxis]);
			else
				(*offset1)[loweststepinaxis] += abs(stepin[loweststepinaxis]);
		}
		else// if( (*(object1->vel)).Lenght() > (*(object2->vel)).Lenght() )
		{
			(*(object2->vel))[loweststepinaxis] = 0.0f;
			if( min2[loweststepinaxis] < min1[loweststepinaxis] )
				(*offset2)[loweststepinaxis] -= abs(stepin[loweststepinaxis]);
			else
				(*offset2)[loweststepinaxis] += abs(stepin[loweststepinaxis]);
		}
		/*
		else if( (*(object1->vel))[loweststepinaxis] > (*(object2->vel))[loweststepinaxis] )
		{
			
		}
		else
		{
			
		}
		*/
		
		
		
		/*
		if( min1[loweststepinaxis] < min2[loweststepinaxis] )
		{
			if( (*(object1->vel)).Lenght() > (*(object2->vel)).Lenght() )
				(*offset1)[loweststepinaxis] -= (stepin[loweststepinaxis]);
			else if( (*(object1->vel)).Lenght() < (*(object2->vel)).Lenght() )
				(*offset2)[loweststepinaxis] += (stepin[loweststepinaxis]);
			else
			{
				(*offset1)[loweststepinaxis] -= (stepin[loweststepinaxis]) * 0.5f;
				(*offset2)[loweststepinaxis] += (stepin[loweststepinaxis]) * 0.5f;
			}
			if( (*(object1->vel))[loweststepinaxis] > 0.0f )
				(*(object1->vel))[loweststepinaxis] = 0.0f;
			if( (*(object2->vel))[loweststepinaxis] < 0.0f )
				(*(object2->vel))[loweststepinaxis] = 0.0f;
		}
		else
		{
			if( (*(object1->vel)).Lenght() > (*(object2->vel)).Lenght() )
				(*offset1)[loweststepinaxis] += (stepin[loweststepinaxis]);
			else if( (*(object1->vel)).Lenght() < (*(object2->vel)).Lenght() )
				(*offset2)[loweststepinaxis] -= (stepin[loweststepinaxis]);
			else
			{
				(*offset1)[loweststepinaxis] += (stepin[loweststepinaxis]) * 0.5f;
				(*offset2)[loweststepinaxis] -= (stepin[loweststepinaxis]) * 0.5f;
			}
		//	(*offset2)[loweststepinaxis] -= (stepin[loweststepinaxis]) / 2.0f;
		//	(*offset1)[loweststepinaxis] += (stepin[loweststepinaxis]) / 2.0f;
			if( (*(object1->vel))[loweststepinaxis] < 0.0f )
				(*(object1->vel))[loweststepinaxis] = 0.0f;
			if( (*(object2->vel))[loweststepinaxis] > 0.0f )
				(*(object2->vel))[loweststepinaxis] = 0.0f;
		}
		*/
		
		return 1;
	}
	return 0;
}


