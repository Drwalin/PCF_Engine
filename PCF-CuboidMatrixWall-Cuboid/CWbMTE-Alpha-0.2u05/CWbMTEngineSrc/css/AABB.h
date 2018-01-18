


class AABB
{
public:
	Vector pos;
	Vector size;        // size object (x,y,z) without rotation
	Vector * vel;
	Vector * force;
	Vector * resistanceforce;
	float rotatehead;
	
	float mass;
	
	bool CollisionDown;
	bool CollisionUp;
	bool CollisionSide;
	
	inline Vector GetVertex( int id );
	
	inline Vector MaxWithVector( Vector dst );
	inline Vector ClosesPoint( Vector dst );
	
	AABB();
	~AABB();
};


