



class Map
{
public:
	
	Chunk *** chunk;
	int NumberOfChunks[2];
	vector < Chunk * > chunksContainer;
	
	bool OperatingOnChunks;
	
	vector < PhysicModelStatic * > staticobject;
	
	
	PointParticle particles;
	Lightning * lightnings;
	int NumberOfLightnings;
	
	int CameraObject;
	
	float Gravity;
	float AirResistance;
	
	inline ColliderObjects * GetTerrainCollider( int x, int z );
	inline ColliderTerrain * GetObjectCollider( int x, int z );
	
	inline bool AddObjectToColliders( PhysicModelStatic * src );
	
	inline void UpdateForces( float FrameTime );
	inline void UpdateObjectsCollisions( float FrameTime, int begin, int end );
	inline void UpdateAllObjectsCollisions( float FrameTime );
	
	inline void UpdateObjectColliders();
	inline void UpdateTerrainColliders();
	
	inline void Update( float FrameTime );
	
	inline void Draw( float FrameTime );
	
	inline int  SegmentCollision( Vector p1, Vector p2, PhysicModelStatic ** object, TrianglePX ** triangle, PhysicModelStatic * decludingobject );
	inline bool SegmentCollideObject( Vector begin, Vector end, PhysicModelStatic ** object, PhysicModelStatic * decludingobject );
	
	inline void WaitWhileOperatingChunks();
	
	inline void DeleteChunk( int x, int z );
	inline bool AddChunk( Chunk * src );
	
	Map();
	~Map();
};







