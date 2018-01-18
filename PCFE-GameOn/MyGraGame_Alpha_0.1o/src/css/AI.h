
#ifndef AI_H
#define AI_H

class AI
{
public:
	Vector destinyPoint;
	
	Player * parent;
	
	void Update();
	
	AI();
	~AI();
};

#endif
