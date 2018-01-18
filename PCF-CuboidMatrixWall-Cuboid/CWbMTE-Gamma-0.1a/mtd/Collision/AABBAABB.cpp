


#define EPSILON 0.0f

inline unsigned int Collision::AABBAABB( PhysicModelStatic * object1, PhysicModelStatic * object2, float time )
{
	Vector min1 = object1 -> pos;
	Vector max1 = object1 -> size + min1;
	Vector min2 = object2 -> pos;
	Vector max2 = object2 -> size + min2;
	
	if( max2 > min1 && max1 > min2 )
	{
		Vector stepin;
		float fast1 = -1.0f, fast2 = -1.0f;
		
		int i;
		
		for( i = 0; i < 3; ++i )
		{
			fast1 = -1.0f;
			fast2 = -1.0f;
			
			if( abs(min1[i]-max2[i]) < abs(min2[i]-max1[i]) )
				stepin[i] = abs(min1[i]-max2[i]);
			else
				stepin[i] = abs(min2[i]-max1[i]);
			/*
			
			
			if( abs(max2[i]-min2[i]) + EPSILON > abs((min1[i])-max2[i]) + abs(min1[i]-min2[i]) )
				fast1 = min1[i];
			else if( abs(max2[i]-min2[i]) + EPSILON > abs((max1[i])-max2[i]) + abs(max1[i]-min2[i]) )
				fast1 = max1[i];
			else
			{
				stepin[i] = 0.0f;
				continue;
			}
			
			if( abs(max1[i]-min1[i]) + EPSILON > abs((min2[i])-max1[i]) + abs(min2[i]-min1[i]) )
				fast2 = min2[i];
			else if( abs(max1[i]-min1[i]) + EPSILON > abs((max2[i])-max1[i]) + abs(max2[i]-min1[i]) )
				fast2 = max2[i];
			else
			{
				stepin[i] = 0.0f;
				continue;
			}
			
			stepin[i] = abs( fast1 - fast2 );
			*/
		}
		
		/*
		if( abs(max2[0]-min2[0]) + EPSILON > abs((min1[0])-max2[0]) + abs(min1[0]-min2[0]) )
			fast1 = min1[0];
		else if( abs(max2[0]-min2[0]) + EPSILON > abs((max1[0])-max2[0]) + abs(max1[0]-min2[0]) )
			fast1 = max1[0];
		
		if( abs(max1[0]-min1[0]) + EPSILON > abs((min2[0])-max1[0]) + abs(min2[0]-min1[0]) )
			fast2 = min2[0];
		else if( abs(max1[0]-min1[0]) + EPSILON > abs((max2[0])-max1[0]) + abs(max2[0]-min1[0]) )
			fast2 = max2[0];
		
		stepin[0] = abs( fast1 - fast2 );
		
		fast1 = -1.0f;
		fast2 = -1.0f;
		
		if( abs(max2[1]-min2[1]) + EPSILON > abs((min1[1])-max2[1]) + abs(min1[1]-min2[1]) )
			fast1 = min1[1];
		else if( abs(max2[1]-min2[1]) + EPSILON > abs((max1[1])-max2[1]) + abs(max1[1]-min2[1]) )
			fast1 = max1[1];
		
		if( abs(max1[1]-min1[1]) + EPSILON > abs((min2[1])-max1[1]) + abs(min2[1]-min1[1]) )
			fast2 = min2[1];
		else if( abs(max1[1]-min1[1]) + EPSILON > abs((max2[1])-max1[1]) + abs(max2[1]-min1[1]) )
			fast2 = max2[1];
		
		stepin[1] = abs( fast1 - fast2 );
		
		fast1 = -1.0f;
		fast2 = -1.0f;
		
		if( abs(max2[2]-min2[2]) + EPSILON > abs((min1[2])-max2[2]) + abs(min1[2]-min2[2]) )
			fast1 = min1[2];
		else if( abs(max2[2]-min2[2]) + EPSILON > abs((max1[2])-max2[2]) + abs(max1[2]-min2[2]) )
			fast1 = max1[2];
		
		if( abs(max1[2]-min1[2]) + EPSILON > abs((min2[2])-max1[2]) + abs(min2[2]-min1[2]) )
			fast2 = min2[2];
		else if( abs(max1[2]-min1[2]) + EPSILON > abs((max2[2])-max1[2]) + abs(max2[2]-min1[2]) )
			fast2 = max2[2];
		
		stepin[2] = abs( fast1 - fast2 );
		*/
		
		
		int loweststepinaxis = 0;
		{
			if( stepin[1] < stepin[loweststepinaxis] )
				loweststepinaxis = 1;
			if( stepin[2] < stepin[loweststepinaxis] )
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
		
		
//		printf( "\n   Collision is with: %i + %i", object1->MainVectorId, object2->MainVectorId );
		
		/*
		Vector contactBarycentric;
		
		if( min1[0] < min2[0] )
			contactBarycentric[0] = (max1[0] + min2[0]) * 0.5f;
		else
			contactBarycentric[0] = (max2[0] + min1[0]) * 0.5f;
		
		if( min1[1] < min2[1] )
			contactBarycentric[1] = (max1[1] + min2[1]) * 0.5f;
		else
			contactBarycentric[1] = (max2[1] + min1[1]) * 0.5f;
		
		if( min1[2] < min2[2] )
			contactBarycentric[2] = (max1[2] + min2[2]) * 0.5f;
		else
			contactBarycentric[2] = (max2[2] + min1[2]) * 0.5f;
		
		
		
		Vector contactNormal;
		contactNormal.Set( 0.0f, 0.0f, 0.0f );
		if( min1[loweststepinaxis] < min2[loweststepinaxis] )
		{
			contactNormal[loweststepinaxis] = -1.0f;
			object1->contact.AddDirection( contactNormal );
			object1->contact.AddPoint( contactBarycentric );
			contactNormal[loweststepinaxis] = 1.0f;
			object2->contact.AddDirection( contactNormal );
			object2->contact.AddPoint( contactBarycentric );
		}
		else if( min1[loweststepinaxis] > min2[loweststepinaxis] )
		{
			contactNormal[loweststepinaxis] = 1.0f;
			object1->contact.AddDirection( contactNormal );
			object1->contact.AddPoint( contactBarycentric );
			contactNormal[loweststepinaxis] = -1.0f;
			object2->contact.AddDirection( contactNormal );
			object2->contact.AddPoint( contactBarycentric );
		}
		*/
		
		
		
		if( object1->vel.Lenght() > object2->vel.Lenght() )
		{
			object1->vel[loweststepinaxis] = 0.0f;
			object2->vel[loweststepinaxis] = 0.0f;
			if( min1[loweststepinaxis] < min2[loweststepinaxis] )
				object1->pos[loweststepinaxis] -= abs(stepin[loweststepinaxis]);
			else
				object1->pos[loweststepinaxis] += abs(stepin[loweststepinaxis]);
		}
		else
		{
			object2->vel[loweststepinaxis] = 0.0f;
			if( min2[loweststepinaxis] < min1[loweststepinaxis] )
				object2->pos[loweststepinaxis] -= abs(stepin[loweststepinaxis]);
			else
				object2->pos[loweststepinaxis] += abs(stepin[loweststepinaxis]);
		}
		
		
		return 1;
	}
	return 0;
}

#undef EPSILON


