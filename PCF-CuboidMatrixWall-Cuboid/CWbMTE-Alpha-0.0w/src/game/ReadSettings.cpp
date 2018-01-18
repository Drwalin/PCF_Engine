


inline void Game::ReadSettings( char * src )
{
	ifstream file;
	file.open( src );
	if( file.good() )
	{
		char * command = new char[1024];
		
		while( !file.eof() )
		{
			file.getline( command, 1023 );
			console.SetCommand( command );
		}
		delete[] command;
	}
	file.close();
}


