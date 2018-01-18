


__cdecl void GameThreadTestLoadingMap( void * args )
{
	while(1)
	{
		if( keyboardobiect.downkeypressed[ 'U' ] )
		{
			int BegginingTime = clock();
			GameInstance->engine.PauseAll();
			GameInstance->engine.DestroyWorld();
			LoadMap();
			GameInstance->engine.UpdateWorld();
			GameInstance->engine.ContinueAll();
			printf( "\n\n     Loading new map and updating time [ms]: %i\n\n", (int)(clock()-BegginingTime) );
		}
		Sleep( 20 );
	}
	_endthread();
}


