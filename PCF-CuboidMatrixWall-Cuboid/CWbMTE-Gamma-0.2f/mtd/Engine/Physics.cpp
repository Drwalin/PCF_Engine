


inline int Engine::SegmentCollision( Vector p1, Vector p2, PhysicModelStatic ** object, TrianglePX ** triangle, PhysicModelStatic * decludingobject, unsigned int rayTypeSrc )
{
	return map.SegmentCollision( p1, p2, object, triangle, decludingobject, rayTypeSrc );
}

void Engine::CollisionLoop( int id )
{
	(*(ThreadsInfo+id)) = PXTHREAD_CLEAR;
	printf( "\nThread %i begin works.", id );
	while( true )
	{
		while( ( (*(ThreadsInfo+id)) & PXTHREAD_INWORK ) != PXTHREAD_INWORK ){ Delay( 0 ); }	// wait while calculate not start
		
		map.UpdateObjectsCollisions( FrameTime, (id*map.staticobject.size()/MaximumNumberOfPhysicsThreads), ((id+1)*map.staticobject.size()/MaximumNumberOfPhysicsThreads) );
		
		if( ( (*(ThreadsInfo+id)) & PXTHREAD_INWORK ) == PXTHREAD_INWORK )
			(*(ThreadsInfo+id)) -= PXTHREAD_INWORK;
	}
}

void Engine::PhysicIteration()
{
	int i;
	
	while( clock() < Physic__BegginTime + CWBMT_FRAMEINMS )
	{
		Delay( 0 ); // microsecconds delay
	}
	
	frames_physic_loop++;
	
	FrameTime = Physic__BegginTime - clock();
	Physic__BegginTime = clock();
	if( FrameTime < 5 )
		FrameTime = 5;
	else if( FrameTime > 70 )
		FrameTime = 70;
	
	FrameTime /= 1000.0f;
	
	FrameTime *= GlobalPhysicTimeScale;
	
	map.UpdateForces( FrameTime );
	
	KeyboardFunction( FrameTime );
	
	for( i = 0; i < map.staticobject.size(); i++ )
	{
		map.staticobject[i]->MainVectorId = i;
		map.staticobject[i]->IdentityCollisions();
	}
	
	map.UpdateObjectColliders();
	
	map.UpdateAllObjectsCollisions( FrameTime );
	
	for( i = 0; i < MaximumNumberOfPhysicsThreads; i++ )
	{
		(*(ThreadsInfo+i)) = PXTHREAD_INWORK;
	}
	
	while( true )
	{
		for( i = 0; i < MaximumNumberOfPhysicsThreads; i++ )
		{
			if( ( (*(ThreadsInfo+i)) & PXTHREAD_INWORK ) == PXTHREAD_INWORK )
				break;
		}
		if( i >= MaximumNumberOfPhysicsThreads )
			break;
		Delay( 0 );
	}
	soundEngineInstantiation -> Update();
}

void Engine::PhysicLoop()
{
	int i;
	PhysicThreadWork = true;
	Physic__BegginTime = 0;
	FrameTime = 0.0f;
	
	for( i = 0; i < MaximumNumberOfPhysicsThreads; i++ )
	{
		(*(ThreadsInfo+i)) = PXTHREAD_CLEAR;
	}
}


