




class Map
{
public:
    vector < Texture >              textures;
    vector < Models >               models;
    vector < ObjectAlive >          object;
    vector < ObjectPhysicalCuboid > objectphys;
    vector < PhysicTriangle >       triangle;
    
    NameLine128                     mapname;
    
    ColliderCell collideralive      [NUMBERTRIGGERALIVE]    [NUMBERTRIGGERALIVE]    ;//[NUMBERTRIGGERALIVE];
    ColliderCell colliderphysic     [NUMBERTRIGGERPHYSICAL] [NUMBERTRIGGERPHYSICAL] ;//[NUMBERTRIGGERPHYSICAL];
    ColliderCell collidertriangle   [NUMBERTRIGGERTRIANGLE] [NUMBERTRIGGERTRIANGLE] ;//[NUMBERTRIGGERTRIANGLE];
    
    void ClearColliderAlive();          // +
    void ClearColliderPhysic();         // +
    void ClearColliderTriangle();       // +
    void UpdateColliderAlive();         // +
    void UpdateColliderPhysic();        // +
    void UpdateColliderTriangle();      // +
    
    void UpdatePhisic();                // -
    
    void DrawTriangles();               // +/- , ...
    void DrawObjects();                 // -
        // u¿ywaj¹c modeli
    void Draw( int id_object );         // +/- , ...
    
    int LoadInit( NameLine128 name );   // +/- , ...
    int Init();                         // -
    int Load( NameLine128 name );       // -
    
    Map();                              // +
};
