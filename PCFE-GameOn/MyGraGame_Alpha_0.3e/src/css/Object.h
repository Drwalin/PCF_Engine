
#ifndef OBJECT_H
#define OBJECT_H

class Object
{
public:
	PhysicModelStatic * object;
	
	ItemListed * item;
	Player * player;
	
	bool destroy;
	
	inline bool IsItem();
	inline bool IsPlayer();
	
	inline void DestroyInit();
	
	inline void Delete();
	
	inline bool NeedDelete();
	
	inline void Update( float time );
	
	Object();
	~Object();
};

#endif
