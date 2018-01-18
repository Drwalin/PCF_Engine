

class StaticGraphicModel
{
private:
	VBOtextured VBO;
	
	bool loaded;		// is model loaded
public:
	char * name;
	
	inline int LoadModel( char * src );
	
	inline void Init( char * modelpath, char * texturepath, int type );
	
	inline void Draw();
	
	StaticGraphicModel();
	~StaticGraphicModel();
};
