


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
	
	if( destinyPoint != NULL )
	{
		Vector distance = (*destinyPoint) - parent -> object -> GetBarycentricDraw();
		if( distance.Lenght() > 4.0f )
		{
			distance[1] = 0.0f;
			distance.Normalize();
			float force_ = FORCE_DEFINE * (float( parent -> object -> CollisionDown ? 1.0f : 0.2f ) * float(parent -> object -> size[1] > 1.1f ? 1.0f : 0.4f));
			if( parent -> object -> vel.Dot( distance ) <= MAX_VELOCITY_DEFINE )
				parent -> object -> force += distance * force_;
		}
		else
		{
			delete destinyPoint;
			destinyPoint = NULL;
		}
	}
	
	if( lastSeenPoint != NULL && destinyPoint == NULL )
	{
		destinyPoint = lastSeenPoint;
		lastSeenPoint = NULL;
	}
	
	if( lastSeenPoint == NULL && destinyPoint == NULL && seenVelocity != NULL )
	{
		destinyPoint = new Vector;
		walkWithVelocityCooldown = ( float( (rand()%2000) + 800 ) / 1000.0f );
		*destinyPoint = parent -> object -> GetBarycentricDraw() + ( (*seenVelocity) * walkWithVelocityCooldown );
		delete seenVelocity;
		seenVelocity = NULL;
	}
	
	if( rotateDegrees > 0.001f )
	{
		float degree = abs( rotateVelocity * time );
		float direction = ( rotateVelocity < 0.0f ) ? -1.0f : 1.0f;
		if( degree > rotateDegrees )
		{
			parent -> object -> see[0] += direction * rotateDegrees;
			rotateDegrees = 0.0f;
		}
		else
		{
			parent -> object -> see[0] += direction * degree;
			rotateDegrees -= degree;
		}
	}
}

AI::AI()
{
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


