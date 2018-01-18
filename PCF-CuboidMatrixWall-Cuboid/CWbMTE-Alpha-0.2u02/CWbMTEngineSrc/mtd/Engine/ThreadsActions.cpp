
/*
	bool GraphicThreadStopped;		// if graphic thread are stopped
	bool PhysicThreadStopped;		// if physic thread are stopped
	bool AskingPause;				// something asking about pause working engine
	bool AskingEnd;					// something asking about stop working engine
	bool OrderContinue;				// one of the threads can order that, to extort continue work
*/
void Engine::CheckEngineThreadsInfoPhysicThread()
{
	if( AskingEnd == true )
	{
		_endthread();
	}
	if( AskingPause == true )
	{
		PhysicThreadStopped = true;
		while( OrderContinue == false )
		{
			Delay( 0 );
		}
		PhysicThreadStopped = false;
	}
}

void Engine::CheckEngineThreadsInfoRendererThread()
{
	if( AskingEnd == true )
	{
		/*
			End OpenGL threads (?)
		*/
	}
	if( AskingPause == true )
	{
		GraphicThreadStopped = true;
		while( OrderContinue == false )
		{
			Delay( 10 );
		}
		GraphicThreadStopped = false;
	}
}


inline void Engine::PauseAll()
{
	AskingEnd = true;
	while( true )
	{
		if( GraphicThreadStopped == true )
			if( PhysicThreadStopped == true )
				break;
		Delay( 0 );
	}
}

inline void Engine::ContinueAll()
{
	AskingEnd = false;
	OrderContinue = true;
	while( true )
	{
		if( GraphicThreadStopped == false )
			if( PhysicThreadStopped == false )
				break;
		Delay( 0 );
	}
	OrderContinue = false;
}


