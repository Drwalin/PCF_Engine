


inline void AI::Update( float time )
{
	UpdateCooldown( time );
	CorrectMove( time );
	
	if( timeUntilCheckEnemies <= 0.0f )
	{
		timeUntilCheckEnemies = float( (rand()%300)+100 ) / 1000.0f;
		enemy = GetSeeEnemy();
	}
	
	if( timeUntilCheckFriends <= 0.0f )
	{
		timeUntilCheckFriends = float( (rand()%300)+100 ) / 1000.0f;
		follow = GetSeeFriend();
	}
	
	if( follow != NULL )
	{
		if( AmISeeObject( follow -> object ) == false )
		{
			follow = NULL;
		}
	}
	
	if( follow != NULL )
	{
		if( destinyPoint == NULL )
			destinyPoint = new Vector;
		*destinyPoint = follow -> object -> GetBarycentricDraw();
		if( lastSeenPoint == NULL )
			lastSeenPoint = new Vector;
		*lastSeenPoint = follow -> object -> GetBarycentricDraw();
		if( seenVelocity == NULL )
			seenVelocity = new Vector;
		*seenVelocity = follow -> object -> vel;
	}
	
	if( timeUntilNextRotate <= 0.0f && destinyPoint == NULL )
	{
		timeUntilNextRotate = float( (rand()%1000)+1000 ) / 1000.0f;
		rotateDegrees = float( (rand() % 160) + 20 );
		rotateVelocity = float( (rand() % 60) + 80 ) * (rand()%2==0?1.0f:-1.0f);
	}
	else if( destinyPoint != NULL )
	{
		Vector direction;
		direction = (*destinyPoint) - parent -> object -> GetEyePos();
		direction.Normalize();
		float angle = acos( direction.Dot( SetVector( 0.0f, 0.0f, 1.0f ) ) ) * 180.0f / float(M_PI);
		rotateDegrees = angle - parent -> object -> see[0];
	}
}


