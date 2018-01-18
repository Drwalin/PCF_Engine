
#ifndef OBJECT_H
#define OBJECT_H

class Object
{
public:
	ItemListed * item;
	Player * player;
	Bullet * bullet;
	
	inline bool IsItem();
	inline bool IsPlayer();
	inline bool IsBullet();
	
	inline void Delete();
	
	inline bool NeedDelete();
	
	inline void Update( float time );
	
	Object();
	~Object();
};

#endif
