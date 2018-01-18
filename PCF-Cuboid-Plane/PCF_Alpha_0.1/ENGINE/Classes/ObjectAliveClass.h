




class ObjectAlive
{
public:
    Vector bpos;
    Vector pos;
    Vector speed;
    Vector force;
    Vector barycenter;
    
    float lookxz;
    float looky;
    
    float width;          // dla x i z
    float heightlegs;     // dla y
    float heightchest;    // dla y
    float heighthead;     // dla y
    
    FLOATING_VALUES_TYPE mass;
    
    bool collision;
    bool collisiondown;
    bool collisionup;
    
    bool sneak;
    bool run;
    
    int type;
    int id;
    int id_graphicmodel;
    NameLine128 name;
    
    inline float GetMaxX();                                     // +
    inline float GetMaxY();                                     // +
    inline float GetMaxZ();                                     // +
    inline float GetMinX();                                     // +
    inline float GetMinY();                                     // +
    inline float GetMinZ();                                     // +
    
    inline Vector GetMaxVertexWithVersor( Vector versor );    // +
    
    ObjectAlive();                                              // +
};








