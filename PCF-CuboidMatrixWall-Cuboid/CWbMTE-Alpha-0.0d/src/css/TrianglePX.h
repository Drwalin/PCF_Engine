


class TrianglePX
{
public:
	Vector vertex[3];
	Vector normal;
	float det;
	float resistance;	// factor of resistance
	
	inline void Calculate();
	inline Vector ClosestPoint( Vector p );
	inline void SetNormal( Vector src );
	
	TrianglePX();
	~TrianglePX();
};





