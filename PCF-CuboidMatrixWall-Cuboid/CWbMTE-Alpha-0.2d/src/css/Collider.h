


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
	//vector < PhisicModel * > model;
	
	inline void Clear();
	
	ColliderObjects();
	~ColliderObjects();
};
