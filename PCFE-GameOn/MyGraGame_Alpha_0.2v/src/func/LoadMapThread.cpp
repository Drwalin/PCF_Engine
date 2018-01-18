


__cdecl void GameThreadTestLoadingMap( void * args )
{
	while( true )
	{
		if( keyboardobiect.downkeypressed[ 'U' ] )
		{
			printf( "\n  Loading new map" );
			int BegginingTime = clock();
			GameInstance->engine.PauseAll();
			GameInstance->engine.DestroyWorldOutOfEngineThread();
			LoadMap();
			GameInstance->engine.ContinueAll();
			printf( "\n  Loading new map and updating time [ms]: %i\n", (int)(clock()-BegginingTime) );
		}
		Sleep( 20 );
	}
	_endthread();
}


