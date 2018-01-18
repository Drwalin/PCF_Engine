


class ShadowMap
{
public:
	VBOcolored VBO;
	float edgeLenght;
	
	inline unsigned int GetIndiceId( Vector point );
	inline void Draw();
	inline void Update( Map * map );
	inline void Generate( Map * map );
	
	ShadowMap();
	~ShadowMap();
};


