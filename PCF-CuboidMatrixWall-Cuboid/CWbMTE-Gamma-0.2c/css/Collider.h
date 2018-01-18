
#ifndef COLLIDER_H
#define COLLIDER_H

class ColliderTerrain
{
public:
	
	vector < TrianglePX * > tri; 
	
	inline void Clear();
	
	ColliderTerrain();
	~ColliderTerrain();
};



class ColliderObjects
{
public:
	
	vector < PhysicModelStatic * > staticmodel;
	
	inline void Clear();
	
	ColliderObjects();
	~ColliderObjects();
};

#endif
