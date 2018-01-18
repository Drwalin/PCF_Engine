


class VBOvertex
{
public:
	float x, y, z;
	float texcoordx, texcoordy;
};

class VBO
{
public:
	vector < VBOvertex > vertices;
	vector < unsigned int > indices;
	Texture textureVBO;
	unsigned int verticesVBOid;
	unsigned int indicesVBOid;
	
	inline void AddVertex( float x, float y, float z, float texcoordx, float texcoordy );
	inline void AddTriangle( unsigned int a, unsigned int b, unsigned int c );
	inline void Generate();
	inline void Draw();
	inline void SetTexture( char * filename );
};


