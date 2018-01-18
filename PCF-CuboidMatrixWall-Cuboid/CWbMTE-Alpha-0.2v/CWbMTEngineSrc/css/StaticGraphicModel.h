

class StaticGraphicModel
{
private:
	
	bool loaded;		// is model loaded
public:
	VBOtextured VBO;
	char * name;
	
	inline int LoadModel( char * src, Vector scale_src );
	inline void Init( char * modelpath, unsigned int texture, Vector scale );
	inline void Draw();
	
	StaticGraphicModel();
	~StaticGraphicModel();
};
