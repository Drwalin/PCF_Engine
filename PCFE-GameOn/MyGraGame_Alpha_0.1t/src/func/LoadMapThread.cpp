


__cdecl void GameThreadTestLoadingMap( void * args )
{
	while(1)
	{
		if( keyboardobiect.downkeypressed[ 'U' ] )
		{
			int BegginingTime = clock();
			GameInstance->engine.PauseAll();
			LoadMap();
			GameInstance->engine.ContinueAll();
			printf( "\n  Loading new map and updating time [ms]: %i\n", (int)(clock()-BegginingTime) );
		}
		Sleep( 20 );
	}
	_endthread();
}


