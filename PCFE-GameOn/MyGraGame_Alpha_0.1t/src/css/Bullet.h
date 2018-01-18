
#ifndef BULLET_H
#define BULLET_H

class Bullet
{
public:
	Object * parent;
	
	Vector pos;
	Vector vel;
	
	float mass;
	
	float baseVelocity;
	
	int damageBaseHead;
	int damageBaseCorpus;
	int damageBaseLegs;
	
	inline void Update( float time );
	inline void Init( Vector pos_, Vector vel_, float baseVel_, int head, int corpus, int legs, float mass_, Object * parent_ ;
	
	Bullet();
	~Bullet();
};

#endif
