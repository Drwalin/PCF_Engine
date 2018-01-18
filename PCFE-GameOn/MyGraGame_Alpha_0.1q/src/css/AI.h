
#ifndef AI_H
#define AI_H

class AI
{
public:
	Vector destinyPoint;
	Vector lastSeenPoint
	
	Player * parent;
	
	float seeRange;
	
	float rotateCooldown;
	float rotateDegrees;
	float rotateInTime
	
	inline void Update( float time );
	
	inline void Delete();
	
	AI();
	~AI();
};

#endif
