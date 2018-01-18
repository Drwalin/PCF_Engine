

class GraphicModel
{
private:
	
	Texture * texture;	// texture table
	
	char * name;		// model file name
	bool loaded;		// is model loaded
	
	char * scale;
	char VertexSize;
	
	char * data;
	int DataSize;
	
public:
	
	inline int LoadModel( char * src );
	
	inline void Draw( Vector size );
	
	GraphicModel();
	~GraphicModel();
};
