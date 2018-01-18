



class Map
{
public:
	vector < Texture > texture;
	vector < GraphicModel > model;
	
	vector < TrianglePX > triPHYS;
	vector < TriangleGX > triTEXT;
	vector < TriangleSTGX > triSTRIP;
	
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
	inline void UpdateObjectsCollisions( float FrameTime );
	//inline void UpdateObjects( float FrameTime );
	
	inline void UpdateObjectColliders();
	inline void UpdateTerrainColliders();
	
	void Update( float FrameTime );
	
	void Draw();
	
	Map();
	~Map();
};







