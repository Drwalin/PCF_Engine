


inline int GetIntFromString( char * src, int id )
{
	// id - which intiger
	int pos = 0;
	int lenght = strlen( src );
	int i = 0;
	
	while( i < lenght && !( (unsigned char)((*(src+i))-48) < 10 && ( ( ( *(src+i-1) == ' ' || *(src+i-1) == ',' || *(src+i-1) == ';' ) && i > 0 ) || ( ( *(src+i-2) == ' ' || *(src+i-2) == ',' || *(src+i-2) == ';' ) && *(src+i-1) == '-' && i > 1 ) || i == 0 || ( i == 1 && *(src+i-1) == '-' ) ) ) )
	{
		i++;
	}
	
	while( i < lenght )
	{
		if( pos < id )
		{
			pos++;
			if( (unsigned char)((*(src+i))-48) < 10 && ( ( ( *(src+i-1) == ' ' || *(src+i-1) == ',' || *(src+i-1) == ';' ) && i > 0 ) || ( ( *(src+i-2) == ' ' || *(src+i-2) == ',' || *(src+i-2) == ';' ) && *(src+i-1) == '-' && i > 1 ) || i == 0 || ( i == 1 && *(src+i-1) == '-' ) ) )
				i++;
			while( i < lenght && !( (unsigned char)((*(src+i))-48) < 10 && ( ( ( *(src+i-1) == ' ' || *(src+i-1) == ',' || *(src+i-1) == ';' ) && i > 0 ) || ( ( *(src+i-2) == ' ' || *(src+i-2) == ',' || *(src+i-2) == ';' ) && *(src+i-1) == '-' && i > 1 ) || i == 0 || ( i == 1 && *(src+i-1) == '-' ) ) ) )
			{
				i++;
			}
		}
		else
		{
			break;
		}
	}
	
	if( i >= lenght )
		return 0;
	
	int positive = 1;
	if( i > 0 )
		if( *(src+i-1) == '-' )
			positive = -1;
	
	int dst = 0;
	while( (unsigned char)((*(src+i))-48) < 10 && i < lenght )
	{
		dst *= 10;
		dst += (int)((*(src+i))-48);
		i++;
	}
	return dst*positive;
}

inline int GetIntFromString( char * src )
{
	return GetIntFromString( src, 0 );
}

inline char * GetStringBetweenCharacter( char * src, char character, int id )
{
	int pos = id;
	int i=0;
	int lenght = strlen( src );
	int beginpos = 0;
	int lenghread = 0;
	while( i < lenght && *(src+i) == character )
		i++;
	for( ; i < lenght; i++ )
	{
		if( pos > 0)
		{
			if( *(src+i) == character )
				pos--;
			else
				continue;
			while( i < lenght && *(src+i) == character )
				i++;
			if( i >= lenght )
				return NULL;
			if( *(src+i) != character && i > 0 )
				i--;
		}
		else
		{
			while( i < lenght && *(src+i) == character )
				i++;
			if( i >= lenght )
				return NULL;
			beginpos = i;
			lenghread = beginpos;
			while( i < lenght && *(src+i) != character )
			{
				lenghread++;
				i++;
			}
			char * dst = new char[lenghread+1-beginpos];
			for( i = beginpos; i < lenghread; i++ )
				*(dst+i-beginpos) = *(src+i);
			*(dst+lenghread-beginpos) = 0;
			return dst;
		}
	}
	return NULL;
}

inline char * GetStringBetweenSpace( char * src, int id )
{
	return GetStringBetweenCharacter( src, ' ', id );
}

inline char * GetStringBetweenSpace( char * src )
{
	return GetStringBetweenSpace( src, 0 );
}


