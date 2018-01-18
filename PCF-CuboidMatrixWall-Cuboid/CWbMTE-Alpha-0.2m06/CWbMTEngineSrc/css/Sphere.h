


class Sphere
{
public:
	
	Vector pos;
	Vector * vel;
	Vector * force;
	Vector * resistanceforce;
	
	float mass;
	float radian;
	
	bool CollisionSide;
	
	inline Vector MaxWithVector( Vector dst );
	inline Vector ClosesPoint( Vector dst );
	
	Sphere();
	~Sphere();
};


