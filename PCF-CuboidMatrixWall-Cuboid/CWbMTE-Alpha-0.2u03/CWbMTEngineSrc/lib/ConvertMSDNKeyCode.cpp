


char ** KeyCodeCharacters;

inline int InitKeyCodes( char * src )
{
	ifstream file;
	file.open( src );
	if( !file.good() )
	{
		return 0;
	}
	
	char * fast = new char[2048];
	KeyCodeCharacters = new char*[256];
	int i;
	for( i = 0; i < 256; i++ )
	{
		*(KeyCodeCharacters+i) = NULL;
	}
	while( !file.eof() )
	{
		file.getline( fast, 2047 );
		*(KeyCodeCharacters+GetIntFromString(fast)) = GetStringBetweenSpace(fast);
	}
	
	delete[] fast;
	file.close();
	return 1;
}

inline int GetKeyCode( char * src )
{
	int i;
	for( i = 0; i < 256; i++ )
	{
		if( *(KeyCodeCharacters+i) != NULL )
		{
			if( !strcmp( src, *(KeyCodeCharacters+i) ) )
			{
				return i;
			}
		}
	}
	return 0;
}

inline char * GetKeyName( int src )
{
	return *(KeyCodeCharacters+src);
}


