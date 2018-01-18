


class LightSource
{
public:
	Vector origin;
	Vector direction;
	float range;
	float angle;
	float density;
	
	VMatrix matrix;
	Vector originBuffered;
	Vector directionBuffered;
	float rangeBuffered;
	float angleBuffered;
	float densityBuffered;
	float depthBufferData[600*600];
	
	inline void UpdateDepthBuffer( Map * map );
	inline unsigned char GetLightStrenght( Vector pos );
	
	LightSource();
	~LightSource();
};

class GlobalLightSource
{
public:
	Vector origin;
	Vector direction;
	float range;
	float angle;
	float density;
	
	GlobalLightSource();
	~GlobalLightSource();
};


