


inline void ReadSettings( char * src )
{
	ifstream file;
	file.open( src );
	if( file.good() )
	{
		int i;
		char * command = new char[1024];
		int arg1,arg2,arg3;
		
		while( !file.eof() )
		{
			arg1 = 0; arg2 = 0; arg3 = 0;
			
			for( i = 0; i < 1024; i++ )
				*(command+i) = 0;
			
			file >> command;
			switch( Command::ArgueNumber( command ) )
			{
//			case 0:
//				Command::Set( command );
//				printf( "End Loading Setting: %s\n", command );
//				break;
			case 1:
				file >> arg1;
				Command::Set( command, arg1 );
				printf( "End Loading Setting: %s = %i\n", command, arg1 );
				break;
			case 2:
				file >> arg1;
				file >> arg2;
				Command::Set( command, arg1, arg2 );
				printf( "End Loading Setting: %s = %i , %i\n", command, arg1, arg2 );
				break;
			case 3:
				file >> arg1;
				file >> arg2;
				file >> arg3;
				Command::Set( command, arg1, arg2, arg3 );
				printf( "End Loading Setting: %s = %i , %i , %i\n", command, arg1, arg2, arg3 );
				break;
			}
			Delay( 1 );
		}
		delete[] command;
	}
	file.close();
}


