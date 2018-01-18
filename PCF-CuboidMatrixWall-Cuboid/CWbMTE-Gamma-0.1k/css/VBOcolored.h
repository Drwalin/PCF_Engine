
#ifndef VBO_COLLORED_H
#define VBO_COLLORED_H

class VBOvertexColored
{
public:
	float x, y, z;
	unsigned char r, g, b, a;
	
	VBOvertexColored();
	~VBOvertexColored();
};

class VBOcolored
{
public:
	vector < VBOvertexColored > vertices;
	vector < unsigned int > indices;
	unsigned int verticesVBOid;
	unsigned int indicesVBOid;
	
	inline void AddVertex( float x, float y, float z, unsigned char r, unsigned char g, unsigned char b, unsigned char a );
	inline void AddTriangle( unsigned int a, unsigned int b, unsigned int c );
	inline void Generate();
	inline void DrawBy( unsigned int begin, unsigned int count );
	inline void Draw();
	inline void Delete();
	
	VBOcolored();
	~VBOcolored();
};

#endif
