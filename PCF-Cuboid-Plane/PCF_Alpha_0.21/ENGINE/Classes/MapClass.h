

/*


    CollisionAliveTriangle( int obj )
    
    CollisionAlivePhysic( int obj ) ~= CollisionAliveAlive( int obj )
    
    CollisionPhysicTriangle( int obj )
    CollisionPhysicPhysic( int obj ) ~= CollisionPhysicAlive( int obj )

*/


class Map
{
public:
    vector < Texture >              textures;
    vector < Models >               models;
    vector < ObjectAlive >          object;
    vector < ObjectPhysicalCuboid > objectphys;
    vector < PhysicTriangle >       triangle;
    
    NameLine128                     mapname;
    
    float gravitation;
    
    ColliderCell collideralive      [NUMBERTRIGGERALIVE]    [NUMBERTRIGGERALIVE]    ;//[NUMBERTRIGGERALIVE];
    ColliderCell colliderphysic     [NUMBERTRIGGERPHYSICAL] [NUMBERTRIGGERPHYSICAL] ;//[NUMBERTRIGGERPHYSICAL];
    ColliderCell collidertriangle   [NUMBERTRIGGERTRIANGLE] [NUMBERTRIGGERTRIANGLE] ;//[NUMBERTRIGGERTRIANGLE];
    
    inline void AddObjectAlive( float * pos, float width,
        float heightlegs, float heightchest, float heighthead,
        float mass, int type, int id, int id_graphicmodel,
        char * name );                                  // -
    
    inline void AddObjectPhysic( /* ... argumenty */ ); // -
    
    
    inline void AddPhysicTriangle( float * pos1, float * pos2,
        float * pos3, float * texcoord1, float * texcoord2,
        float * texcoord3, unsigned int texure );       // -
    
    
    inline bool Map::IfVectorPointCrossTriangle(
        Vector src1, Vector src2,
            unsigned int id_triangle, Vector * dst );   // +
    
    
    void ClearColliderAlive();                          // +
    void ClearColliderPhysic();                         // +
    void ClearColliderTriangle();                       // +
    void UpdateColliderAlive();                         // +
    void UpdateColliderPhysic();                        // +
    void UpdateColliderTriangle();                      // +
    
    
    
    void CollisionLineAll();                            // -
    
    
    
    void CollisionAliveTriangle( unsigned int number,
                            unsigned int frametime );   // +/-, ...
    void CollisionAlivePhysic( unsigned int obj );      // -
    void CollisionAliveAlive( unsigned int obj );       // -
    void CollisionPhysicTriangle( unsigned int obj );   // -
    void CollisionPhysicPhysic( unsigned int obj );     // -
    void CollisionPhysicAlive( unsigned int obj );      // -
    
    void UpdatePhysic( unsigned int frametime );        // ...
    
    
    
    void DrawTriangles();                               // +/- , ...
    void DrawObjects();                                 // -
        // u¿ywaj¹c modeli
    void Draw( int id_object );                         // +/- , ...
    
    int LoadTextures( NameLine128 name);                //
    int LoadInit( NameLine128 name );                   // +/- , ...
    int Init();                                         // -
    int Load( NameLine128 name );                       // -
    
    Map();                                              // +
};
