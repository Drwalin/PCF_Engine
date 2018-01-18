
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
//		_endthread();
	}
	if( AskingPause == true )
	{
		PhysicThreadStopped = true;
		while( OrderContinue == false )
		{
			Delay( 10 );
		}
		PhysicThreadStopped = false;
	}
	PhysicThreadWork = true;
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
			Delay( 0 );
			if( deleteVBOs == true )
			{
				DeleteVBOs();
				deleteVBOs = false;
			}
		}
		GraphicThreadStopped = false;
	}
}


inline void Engine::PauseAll()
{
	AskingPause = true;
	while( true )
	{
		if( GraphicThreadStopped == true )
//			if( PhysicThreadStopped == true )
				break;
		Delay( 0 );
	}
}

inline void Engine::ContinueAll()
{
	AskingPause = false;
	OrderContinue = true;
	while( true )
	{
		if( GraphicThreadStopped == false )
//			if( PhysicThreadStopped == false )
				break;
		Delay( 0 );
	}
	OrderContinue = false;
}

inline void Engine::CalculateDynamicLight()
{
	lightVertexCalculated;
	NumberLightVertexCalculatedPerFrame;
	if( lightVertexCalculated+map.shadowMap.VBO.vertices.size()/NumberLightVertexCalculatedPerFrame > map.shadowMap.VBO.vertices.size() )
		map.UpdateShadowMap( lightVertexCalculated, map.shadowMap.VBO.vertices.size() );
	else
		map.UpdateShadowMap( lightVertexCalculated, lightVertexCalculated+map.shadowMap.VBO.vertices.size()/NumberLightVertexCalculatedPerFrame );
	lightVertexCalculated += map.shadowMap.VBO.vertices.size()/NumberLightVertexCalculatedPerFrame;
	if( lightVertexCalculated >= map.shadowMap.VBO.vertices.size() )
		lightVertexCalculated = 0;
}


