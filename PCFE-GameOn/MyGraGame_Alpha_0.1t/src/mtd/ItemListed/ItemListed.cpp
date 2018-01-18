


inline void ItemListed::SetName( const char * src )
{
	int i, l = strlen(src);
	name = new char[l+1];
	name[l] = 0;
	for( i = 0; i < l; ++i )
		name[i] = src[i];
}

inline void ItemListed::SetType( const int src )
{
	type = src;
}

inline bool ItemListed::IsWeapon()
{
	if( type == WEAPON )
		return true;
	return false;
}

inline void ItemListed::etId( const int src )
{
	id = src;
}

ItemListed::ItemListed()
{
	name = NULL;
	type = 0;
	id = 0;
}

ItemListed::~ItemListed()
{
	if( name != NULL )
		delete[] name;
	name = NULL;
	type = 0;
	id = 0;
}


