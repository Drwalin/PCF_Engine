


class TrianglePX
{
public:
	Vector vertex[3];
	Vector normal;
	Vector wallnormals[3];
	float walldet[3];
	Vector min, max;
	float det;
	float resistance;	// factor of resistance
	
	inline void Calculate();
	inline Vector ClosestPoint( Vector p );
	inline void SetNormal( Vector src );
	inline bool PointIn( Vector p );
	inline bool PointIn( Vector p1, Vector p2 );
	inline Vector GetCrossPoint( Vector p1, Vector p2 );
	inline Vector GetFromPointDeviationWithVector( Vector p, Vector direction__ );
	
	TrianglePX();
	~TrianglePX();
};





