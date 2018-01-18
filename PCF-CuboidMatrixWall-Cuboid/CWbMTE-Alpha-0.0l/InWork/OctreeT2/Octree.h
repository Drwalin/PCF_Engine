


class Octree
{
public:
	vector < void* > items;
	
	Octree * next;
	
	inline void * operator[] ( const int id );
	inline void AddItem( void * src );
	inline void SetItem( int id, void * src );
	inline void CreateChildrens();
	inline void DeleteChildrens();
	
	Octree();
	~Octree();
};



class OperateOctree
{
public:
	Octree * octree;
	Octree octree_out;
	Vector offset;
	Vector size;
	int maxChildren;
	
	inline void SetAt( Vector begin, Vector end, void * src );
	inline vector < void * > GetFrom( Vector begin, Vector end );
	inline void Clear();
	
	
	OperateOctree();
	~OperateOctree();
};
