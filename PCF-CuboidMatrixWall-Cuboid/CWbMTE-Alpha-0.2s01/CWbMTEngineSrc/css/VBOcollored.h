


class VBOvertexCollored
{
public:
	float x, y, z;
	unsigned char r, g, b, a;
	
	VBOvertexCollored();
	~VBOvertexCollored();
};

class VBOcollored
{
public:
	vector < VBOvertexCollored > vertices;
	vector < unsigned int > indices;
	unsigned int verticesVBOid;
	unsigned int indicesVBOid;
	
	inline void AddVertex( float x, float y, float z, unsigned char r, unsigned char g, unsigned char b, unsigned char a );
	inline void AddTriangle( unsigned int a, unsigned int b, unsigned int c );
	inline void Generate();
	inline void Draw();
	inline void DrawBy( unsigned int begin, unsigned int count );
	inline void Delete();
	
	VBOcollored();
	~VBOcollored();
};


