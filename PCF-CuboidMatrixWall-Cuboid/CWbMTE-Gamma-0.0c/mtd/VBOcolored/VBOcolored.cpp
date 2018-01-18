


VBOvertexColored::VBOvertexColored()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	r = 0;
	g = 0;
	b = 0;
	a = 0;
}

VBOvertexColored::~VBOvertexColored()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	r = 0;
	g = 0;
	b = 0;
	a = 0;
}


inline void VBOcolored::AddVertex( float x, float y, float z, unsigned char r, unsigned char g, unsigned char b, unsigned char a )
{
	VBOvertexColored vert;
	vert.x = x;
	vert.y = y;
	vert.z = z;
	vert.r = r;
	vert.g = g;
	vert.b = b;
	vert.a = a;
	vertices.push_back( vert );
}

inline void VBOcolored::AddTriangle( unsigned int a, unsigned int b, unsigned int c )
{
	indices.push_back( a );
	indices.push_back( b );
	indices.push_back( c );
}

inline void VBOcolored::Generate()
{
	glGenBuffers( 1, &verticesVBOid );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER_ARB, verticesVBOid );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER_ARB, sizeof(VBOvertexColored)*vertices.size(), &vertices[0].x, GL_STATIC_DRAW_ARB );
	
	glGenBuffers( 1, &indicesVBOid );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER_ARB, indicesVBOid );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER_ARB, sizeof(int)*indices.size(), &indices[0], GL_STATIC_DRAW );
}

#define BUFFER_OFFSET(i) ((void*)(i))

inline void VBOcolored::DrawBy( unsigned int begin, unsigned int count )
{
	glEnable( GL_TEXTURE_2D );
	glEnable( GL_DEPTH_TEST );
	glDepthFunc( GL_LESS );
	glEnable( GL_BLEND );
	
	glBindBuffer( GL_ARRAY_BUFFER_ARB, verticesVBOid );
	glEnableClientState( GL_VERTEX_ARRAY );
	glVertexPointer( 3, GL_FLOAT, sizeof(VBOvertexColored), BUFFER_OFFSET(0) );
	
	glEnableClientState( GL_COLOR_ARRAY );
	glColorPointer( 3, GL_UNSIGNED_BYTE, sizeof(VBOvertexColored), BUFFER_OFFSET(12) );
	
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER_ARB, indicesVBOid );
	glDrawElements( GL_TRIANGLES, count, GL_UNSIGNED_INT, BUFFER_OFFSET(begin*sizeof(VBOvertexColored)) );
}

inline void VBOcolored::Draw()
{
	DrawBy( 0, indices.size() );
}

inline void VBOcolored::Delete()
{
	glDeleteBuffers( 1, &verticesVBOid );
	glDeleteBuffers( 1, &indicesVBOid );
	
	vertices.resize( 0 );
	indices.resize( 0 );
	verticesVBOid = 0;
	indicesVBOid = 0;
}

VBOcolored::VBOcolored()
{
	vertices.resize( 0 );
	indices.resize( 0 );
	verticesVBOid = 0;
	indicesVBOid = 0;
}

VBOcolored::~VBOcolored()
{
	Delete();
}


