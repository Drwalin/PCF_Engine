


class OBB
{
public:
	Vector bpos;
	Vector pos;
	Vector size;        // size object (x,y,z) without rotation
	
	Vector vel;
	Vector force;
	Vector resistanceforce;
	
	float mass;
	
	bool Collision;
	
	VMatrix rotate;
	VMatrix rotatespeed;
	
	inline void DrawEdges();
	
	inline Vector GetVertex( int id );
	
	OBB();
	~OBB();
};


