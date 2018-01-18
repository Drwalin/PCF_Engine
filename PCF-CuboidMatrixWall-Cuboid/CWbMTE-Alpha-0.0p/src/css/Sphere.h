


class Sphere
{
public:
	Vector bpos;
	Vector pos;
	Vector vel;
	Vector force;
	Vector resistanceforce;
	
	float mass;
	float radian;
	
	bool Collision;
	
	inline Vector MaxWithVector( Vector dst );
	inline Vector ClosesPoint( Vector dst );
	
	Sphere();
	~Sphere();
};


