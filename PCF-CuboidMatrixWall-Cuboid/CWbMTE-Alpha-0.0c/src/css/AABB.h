



class AABB
{
public:
    Vector bpos;
    Vector pos;
    Vector velocity;
    Vector force;
    Vector size;        // size object (x,y,z) without rotation
    
    float mass;
    
    unsigned int model;
    
    bool GravityUse;
    bool VelocityUse;
    bool ForceUse;
    bool CollisionUse;
    
    bool CollisionDown;
    bool CollisionUp;
    bool CollisionSide;
    
    AABB * ColliderDownX;
    AABB * ColliderUpX;
    
    inline Vector ClosestPoint( Vector p );
    
    Object();
    ~Object();
};

















