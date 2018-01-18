


inline void SetName( const char * src )
{
	int i, l = strlen(src);
	name = new char[l+1];
	name[l] = 0;
	for( i = 0; i < l; ++i )
		name[i] = src[i];
}

inline void SetType( const int src )
{
	type = src;
}

inline void SetId( const int src )
{
	id = src;
}

ItemListed()
{
	name = NULL;
	type = 0;
	id = 0;
}

~ItemListed()
{
	if( name != NULL )
		delete[] name;
	name = NULL;
	type = 0;
	id = 0;
}


