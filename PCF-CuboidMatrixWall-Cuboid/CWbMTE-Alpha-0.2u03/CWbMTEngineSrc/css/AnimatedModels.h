


class OneAnimationFrame
{
public:
	vector < VBOvertexTexture > vertices;
};

class AnimatedGraphicModel
{
public:
	Texture texture;
	vector < OneAnimationFrame > frame;
	
	char * name;
	
	int LoadModel( char * src );
	void Draw( float time );
	
	AnimatedGraphicModel();
	~AnimatedGraphicModel();
};


