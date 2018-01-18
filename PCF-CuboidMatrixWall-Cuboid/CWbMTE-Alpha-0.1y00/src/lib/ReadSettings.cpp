


inline void Game::ReadSettings( char * src )
{
	ifstream file;
	file.open( src );
	if( file.good() )
	{
		int i;
		char * command = new char[1024];
		
		while( !file.eof() )
		{
			file.getline( command, 1023 );
			console.SetCommand( command );
			printf( "\nCommend done: %s", command );
			Delay( 1 );
		}
		delete[] command;
	}
	file.close();
}


