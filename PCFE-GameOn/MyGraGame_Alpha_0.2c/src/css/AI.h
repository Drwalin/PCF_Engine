
#ifndef AI_H
#define AI_H

class AI
{
public:
	Vector * destinyPoint;
	Vector * lastSeenPoint;
	Vector * seenVelocity;
	float timeUntilReaction;
	float timeUntilCheckEnemies;
	float timeUntilCheckFriends;
	float walkWithVelocityCooldown;
	
	Player * follow;
	Player * enemy;
	
	Player * parent;
	
	float seeRange;
	
	float timeUntilNextRotate;
	float rotateDegrees;
	float rotateVelocity;
	
	bool agressiveMode;
	bool attack;
	
	inline bool AmISeeObject( PhysicModelStatic * src );
	inline Player * GetSeeEnemy();
	inline Player * GetSeeFriend();
	inline void UpdateCooldown( float time );
	inline void CorrectMove( float time );
	inline void Update( float time );
	
	AI();
	~AI();
};

#endif
