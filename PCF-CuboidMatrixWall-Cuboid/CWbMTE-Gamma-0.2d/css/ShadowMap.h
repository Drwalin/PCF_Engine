


class ShadowMap
{
public:
	VBOcolored VBO;
	float edgeLenght;
	unsigned char * baseColor;
	queue < unsigned int > editedInLastFrame;
	
	inline unsigned int GetIndiceId( Vector point );
	inline void Draw();
	inline void Update( Map * map );
	inline void CalculateBaseLights( Map * map );
	inline void Generate( Map * map );
	
	ShadowMap();
	~ShadowMap();
};


