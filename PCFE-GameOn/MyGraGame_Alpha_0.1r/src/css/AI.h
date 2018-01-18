
#ifndef AI_H
#define AI_H

class AI
{
public:
	Vector destinyPoint;
	Vector lastSeenPoint;
	float timeUntilReaction;
	
	Player * parent;
	
	float seeRange;
	
	float timeUntilNextRotate;
	float rotateDegrees;
	float rotateVelocity;
	
	inline void Update( float time );
	
	inline void Delete();
	
	AI();
	~AI();
};

#endif
