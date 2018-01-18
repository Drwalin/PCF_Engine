



class Object
{
public:
    Vector bpos;
    Vector pos;
    Vector speed;
    Vector rotspeed;    // rotation speed
    Vector force;
    Vector rotforce;    // rotation force
    Vector size;        // size object (x,y,z) without rotation
    
    VMatrix brotate;
    VMatrix rotate;
    
    bool RotatingUse;
    bool GravityUse;
    bool SpeedUse;
    bool ForceUse;
    
    bool CollisionDown;
    bool CollisionUp;
    bool CollisionSide;
    
    void AddForce( vector src_point, vector src_force );
    void Update();
    
    Object();
};

















