


inline void AI::UpdateCooldown( float time )
{
	walkWithVelocityCooldown -= time;
	timeUntilReaction -= time;
	timeUntilNextRotate -= time;
	timeUntilCheckEnemies -= time;
	timeUntilCheckFriends -= time;
}

inline void AI::CorrectMove( float time )
{
	if( walkWithVelocityCooldown < 0.0f && destinyPoint != NULL && lastSeenPoint == NULL && seenVelocity == NULL )
	{
		delete destinyPoint;
		destinyPoint = NULL;
	}
	
	deleteDestinyPoint = false;
	
	if( destinyPoint != NULL )
	{
		Vector distance = (*destinyPoint) - parent -> object -> GetBarycentricDraw();
		float force_ = FORCE_DEFINE * (float( parent -> object -> CollisionDown ? 1.0f : 0.2f ) * float(parent -> object -> size[1] > 1.1f ? 1.0f : 0.4f));
		if( distance.Lenght() < 4.0f && distance.Lenght() != 0.0f )
		{
			distance[1] = 0.0f;
			distance.Normalize();
			if( parent -> object -> vel.Dot( distance ) <= MAX_VELOCITY_DEFINE )
				parent -> object -> force -= distance * force_ * 0.6f ;
		}
		else if( distance.Lenght() > 6.0f )
		{
			distance[1] = 0.0f;
			distance.Normalize();
			if( parent -> object -> vel.Dot( distance ) <= MAX_VELOCITY_DEFINE )
				parent -> object -> force += distance * force_;
		}
		else
		{
			deleteDestinyPoint = true;
		}
	}
	
	if( lastSeenPoint != NULL && deleteDestinyPoint == true )
	{
		if( destinyPoint != NULL )
			delete destinyPoint;
		destinyPoint = lastSeenPoint;
		lastSeenPoint = NULL;
		if( seenVelocity != NULL )
		{
			Vector distance = (*destinyPoint) - parent -> object -> GetBarycentricDraw();
			distance[1] = 0.0f;
			distance.Normalize();
			(*destinyPoint) += distance * 8.0f;
		}
		deleteDestinyPoint = false;
	}
	
	if( lastSeenPoint == NULL && deleteDestinyPoint == true && seenVelocity != NULL )
	{
		if( destinyPoint != NULL )
			delete destinyPoint;
		destinyPoint = new Vector;
		walkWithVelocityCooldown = ( float( (rand()%2000) + 800 ) / 1000.0f );
		*destinyPoint = parent -> object -> GetBarycentricDraw() + ( (*seenVelocity) * walkWithVelocityCooldown );
		delete seenVelocity;
		seenVelocity = NULL;
		deleteDestinyPoint = false;
	}
	
	if( rotateDegrees > 0.0f )
	{
		float degree = abs( rotateVelocity * time );
		float direction = ( rotateVelocity < 0.0f ) ? -1.0f : 1.0f;
		if( degree > rotateDegrees )
		{
			parent -> rotateDestiny[0] += direction * rotateDegrees;
			rotateDegrees = 0.0f;
		}
		else
		{
			parent -> rotateDestiny[0] += direction * degree;
			rotateDegrees -= degree;
		}
	}
}

AI::AI()
{
	deleteDestinyPoint = false;
	destinyPoint = NULL;
	lastSeenPoint = NULL;
	seenVelocity = NULL;
	timeUntilReaction = 0.0f;
	follow = NULL;
	enemy = NULL;
	parent = NULL;
	seeRange = 100.0f;
	timeUntilNextRotate = 0.0f;
	rotateDegrees = 0.0f;
	rotateVelocity = 0.0f;
	attack = false;
	agressiveMode = false;
	timeUntilCheckEnemies = 0.0f;
	timeUntilCheckFriends = 0.0f;
	walkWithVelocityCooldown = 0.0f;
}

AI::~AI()
{
	deleteDestinyPoint = false;
	walkWithVelocityCooldown = 0.0f;
	if( destinyPoint != NULL )
		delete destinyPoint;
	if( lastSeenPoint != NULL )
		delete lastSeenPoint;
	if( seenVelocity != NULL )
		delete seenVelocity;
	destinyPoint = NULL;
	lastSeenPoint = NULL;
	seenVelocity = NULL;
	timeUntilReaction = 0.0f;
	follow = NULL;
	enemy = NULL;
	parent = NULL;
	seeRange = 0.0f;
	timeUntilNextRotate = 0.0f;
	rotateDegrees = 0.0f;
	rotateVelocity = 0.0f;
	attack = false;
	agressiveMode = false;
	timeUntilCheckEnemies = 0.0f;
	timeUntilCheckFriends = 0.0f;
}


