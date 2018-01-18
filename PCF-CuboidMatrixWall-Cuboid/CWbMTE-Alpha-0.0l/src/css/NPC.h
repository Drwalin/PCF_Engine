


class NPC
{
public:
    Vector pos;
    Vector size;        // size object (x,y,z) without rotation
    Vector vel;
    Vector force;
    
	float maxspeed;
    
    float mass;
    
    bool CollisionDown;
    bool CollisionUp;
    bool CollisionSide;
	
	inline Vector MaxWithVector( Vector dst );
	inline Vector ClosesPoint( Vector dst );
	
	NPC();
	~NPC();
};


