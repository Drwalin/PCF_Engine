



class Map
{
public:
	vector < Texture > texture;
	vector < GraphicModel > model;
	
	vector < TrianglePX > triPHYS;
	vector < TriangleGX > triTEXT;
	vector < TriangleSTGX > triSTRIP;
	vector < VBOtextured > vbotex;
	vector < VBOcollored > vbocol;
	
	PointParticle particles;
	Lightning * lightnings;
	int NumberOfLightnings;
	
    vector < PhysicModelStatic > staticobject;
	
	////OperateParticles ParticlesSystem;
	
	int CameraObject;
	
	float Gravity;
	float AirResistance;
	
    int maxiumumnumberoftrianglescolliders[2];
    int maxiumumnumberofobjectcolliders[2];
	
    ColliderTerrain ** colliderter;
    ColliderObjects ** colliderobj;
    ColliderObjects colliderobjectout;
    float moveColliderTerrain[2];
    float moveColliderObject[2];
    float sizeColliderTerrain[2];
    float sizeColliderObject[2];
	
	inline void UpdateForces( float FrameTime );
	inline void UpdateObjectsCollisions( float FrameTime, int begin, int end );
	inline void UpdateAllObjectsCollisions( float FrameTime );
	//inline void UpdateObjects( float FrameTime );
	
	inline void UpdateObjectColliders();
	inline void UpdateTerrainColliders();
	
	inline void Update( float FrameTime );
	
	inline void Draw();
	
	inline int  SegmentCollision( Vector p1, Vector p2, PhysicModelStatic ** object, TrianglePX ** triangle, PhysicModelStatic * decludingobject );
	inline bool SegmentCollideObject( Vector begin, Vector end, PhysicModelStatic ** object, PhysicModelStatic * decludingobject );
	inline int  ConeObjectsvector( Vector begin, Vector end, float aspect, vector<PhysicModelStatic*>* objects, PhysicModelStatic * decludingobject );
	
	Map();
	~Map();
};







