


inline int Engine::SegmentCollision( Vector p1, Vector p2, PhysicModelStatic ** object, TrianglePX ** triangle, PhysicModelStatic * decludingobject )
{
	return map.SegmentCollision( p1, p2, object, triangle, decludingobject );
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

void Engine::PhisicLoop()
{
	int i;
    FrameTime = 0.0f;
    unsigned int BegginTime = 0;
    unsigned int EndTime = 0;
    
    map.UpdateTerrainColliders();
    
	for( i = 0; i < MaximumNumberOfPhysicsThreads; i++ )
	{
		(*(ThreadsInfo+i)) = PXTHREAD_CLEAR;
	}
    
    while( true )
    {
		frames_physic_loop++;
        FrameTime = BegginTime - clock();
        BegginTime = clock();
        if( FrameTime < 5 )
            FrameTime = 5;
        else if( FrameTime > 70 )
            FrameTime = 70;
        
        FrameTime = FrameTime / 1000.0f;
        
        FrameTime *= GlobalPhisicTimeScale;
        
        map.UpdateForces( FrameTime );
        
        KeyboardFunction( FrameTime );
        
        map.UpdateObjectColliders();
        
        for( i = 0; i < map.staticobject.size(); i++ )
        {
			map.staticobject[i].IdentityCollisions();
			if( map.staticobject[i].pos[0] < -248.0f )
				map.staticobject[i].pos[0] = -248.0f;
			if( map.staticobject[i].pos[2] < -248.0f )
				map.staticobject[i].pos[2] = -248.0f;
			if( map.staticobject[i].pos[0] > 248.0f )
				map.staticobject[i].pos[0] = 248.0f;
			if( map.staticobject[i].pos[2] > 248.0f )
				map.staticobject[i].pos[2] = 248.0f;
		}
        
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
        
        while( clock() < BegginTime + 10 )
        {
            Delay( 0 ); // microsecconds delay
        }
	}
}


