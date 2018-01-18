


class Window3D
{
public:
	vector < Vector > points;
	Vector pos;
	float lookx, looky;
	
	VMatrix matrix;
	
	inline Vector GetForwardVersor();
	inline Vector GetBackwardVersor();
	inline Vector GetLeftVersor();
	inline Vector GetRightVersor();
	
	inline void InitMatix();
	inline void Update( float rotx, float roty, Vector move );
	inline void Clear();
	inline void AddPoint( Vector src );
	Window3D();
};


