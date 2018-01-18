
#ifndef ITEM_LISTED_H
#define ITEM_LISTED_H

class ItemListed
{
public:
	char * name;
	int type;
	int id;
	
	inline void SetName( const char * src );
	inline void SetType( const int src );
	inline void SetId( const int src );
	inline bool IsWeapon();
	
	ItemListed();
	~ItemListed();
};

#endif
