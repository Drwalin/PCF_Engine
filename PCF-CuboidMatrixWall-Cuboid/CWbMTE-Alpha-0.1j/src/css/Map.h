



class Map
{
public:
	vector < Texture > texture;
	vector < GraphicModel > model;
	
	vector < TrianglePX > triPHYS;
	vector < TriangleGX > triTEXT;
	vector < TriangleSTGX > triSTRIP;
	vector < VBO > vbo;
	
	PointParticle particles;
	
    vector < PhysicModelStatic > staticobject;
    //vector < PhisicModel > orientatedobject;
	
	////OperateParticles ParticlesSystem;
	
	int CameraObject;
	
	float Gravity;
	float AirResistance;
	
    unsigned int maxiumumnumberoftrianglescolliders[2];
    unsigned int maxiumumnumberofobjectcolliders[2];
	
    ColliderTerrain ** colliderter;
    //ColliderTerrain colliderter[32][32];
    ColliderObjects ** colliderobj;
    float moveColliderTerrain[2];
    float moveColliderObject[2];
    float sizeColliderTerrain[2];
    float sizeColliderObject[2];
	
	inline void UpdateForces( float FrameTime );
	inline void UpdateObjectsCollisions( float FrameTime, int begin, int end );
	//inline void UpdateObjects( float FrameTime );
	
	inline void UpdateObjectColliders();
	inline void UpdateTerrainColliders();
	
	inline void Update( float FrameTime );
	
	inline void Draw();
	
	inline int SegmentCollision( Vector p1, Vector p2, PhysicModelStatic ** object, TrianglePX ** triangle );
	
	Map();
	~Map();
};







