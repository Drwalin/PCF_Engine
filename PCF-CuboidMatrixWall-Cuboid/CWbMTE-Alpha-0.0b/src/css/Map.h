
class Collider
{
public:
    TrianglePX * tri;
    Collider()
    {
        tri = NULL;
    }
    ~Collider()
    {
        delete[] tri;
    }
};



class Map
{
public:
    vector < Texture > textures;
    vector < Model > models;
    
    vector < AABB > objAABB;
    vector < TrianglePX > triPHYS;
    vector < TriangleGX > triTEXT;
    vector < TriangleSTGX > triSTRIP;
    
    OperateParticles ParticlesSystem;
    
    int CameraObject;
    
    float Gravity;
    float AirResistance;
    
    inline void CollisionAABBTriangle( AABB * obj, TrianglePX * tri );
    inline void CollisionAABBAABB( AABB * a, AABB * b );
    
    inline void UpdateForces( float FrameTime );
    inline void UpdateObjectsCollisions( float FrameTime );
    inline void UpdateObjects( float FrameTime );
    inline void UpdateColliders();
    
    void Update( float FrameTime );
    
    Map();
    ~Map();
};







