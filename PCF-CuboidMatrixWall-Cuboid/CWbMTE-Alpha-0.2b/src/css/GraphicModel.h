

class GraphicModel
{
private:
	VBOtextured VBO;
	
	bool loaded;		// is model loaded
public:
	
	inline int LoadModel( char * src );
	
	inline void Init( char * modelpath, char * texturepath );
	
	inline void Draw();
	
	GraphicModel();
	~GraphicModel();
};
