
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
				int i;
				for( i = 0; i < map.vbotex.size(); ++i )
				{
					map.vbotex[i].Delete();
					map.vbotex[i].vertices.resize( 0 );
					map.vbotex[i].indices.resize( 0 );
				}
				for( i = 0; i < map.vbocol.size(); ++i )
				{
					map.vbocol[i].Delete();
					map.vbocol[i].vertices.resize( 0 );
					map.vbocol[i].indices.resize( 0 );
				}
				for( i = 0; i < map.graphicMapModels.size(); ++i )
				{
					map.graphicMapModels[i] -> Delete();
					map.graphicMapModels[i] -> VBO.vertices.resize( 0 );
					map.graphicMapModels[i] -> VBO.indices.resize( 0 );
					delete map.graphicMapModels[i];
				}
				map.vbotex.resize( 0 );
				map.vbocol.resize( 0 );
				map.graphicMapModels.resize( 0 );
				
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


