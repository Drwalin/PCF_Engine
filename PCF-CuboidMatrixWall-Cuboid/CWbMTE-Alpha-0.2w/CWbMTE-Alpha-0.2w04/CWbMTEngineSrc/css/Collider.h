


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
