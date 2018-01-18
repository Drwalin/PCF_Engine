

class GraphicModel
{
private:
	VBOtextured VBO;
	
	char * name;		// model file name
	bool loaded;		// is model loaded
public:
	
	inline int LoadModel( char * src );
	
	inline void Init( char * texturename );
	
	inline void Draw();
	
	GraphicModel();
	~GraphicModel();
};
