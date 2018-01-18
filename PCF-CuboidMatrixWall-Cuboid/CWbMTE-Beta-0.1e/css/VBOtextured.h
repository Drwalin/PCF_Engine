


class VBOvertexTexture
{
public:
	float x, y, z;
	float texcoordx, texcoordy;
	
	VBOvertexTexture();
	~VBOvertexTexture();
};

class VBOtextured
{
public:
	vector < VBOvertexTexture > vertices;
	vector < unsigned int > indices;
	unsigned int textureVBO;
	unsigned int verticesVBOid;
	unsigned int indicesVBOid;
	
	inline void AddVertex( float x, float y, float z, float texcoordx, float texcoordy );
	inline void AddTriangle( unsigned int a, unsigned int b, unsigned int c );
	inline void Generate();
	inline void Draw();
	inline void DrawBy( unsigned int begin, unsigned int count );
	inline void SetTexture( unsigned int texture );
	inline void Delete();
	
	VBOtextured();
	~VBOtextured();
};


