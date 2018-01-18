


VBOvertexTexture::VBOvertexTexture()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	texcoordx = 0.0f;
	texcoordy = 0.0f;
}

VBOvertexTexture::~VBOvertexTexture()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	texcoordx = 0.0f;
	texcoordy = 0.0f;
}

inline void VBOtextured::AddVertex( float x, float y, float z, float texcoordx, float texcoordy )
{
	VBOvertexTexture vert;
	vert.x = x;
	vert.y = y;
	vert.z = z;
	vert.texcoordx = texcoordx;
	vert.texcoordy = texcoordy;
	vertices.push_back( vert );
}

inline void VBOtextured::AddTriangle( unsigned int a, unsigned int b, unsigned int c )
{
	indices.push_back( a );
	indices.push_back( b );
	indices.push_back( c );
}

inline void VBOtextured::SetTexture( unsigned int texture )
{
	textureVBO = texture;
}

inline void VBOtextured::Generate()
{
	glGenBuffers( 1, &verticesVBOid );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER_ARB, verticesVBOid );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER_ARB, sizeof(VBOvertexTexture)*vertices.size(), &vertices[0].x, GL_STATIC_DRAW_ARB );
	
	glGenBuffers( 1, &indicesVBOid );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER_ARB, indicesVBOid );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER_ARB, sizeof(int)*indices.size(), &indices[0], GL_STATIC_DRAW );
}

#define BUFFER_OFFSET(i) ((void*)(i))

inline void VBOtextured::DrawBy( unsigned int begin, unsigned int count )
{
	glEnable( GL_TEXTURE_2D );
	glEnable( GL_DEPTH_TEST );
	glDepthFunc( GL_LESS );
	glEnable( GL_BLEND );
	
	glBindBuffer( GL_ARRAY_BUFFER_ARB, verticesVBOid );
	glEnableClientState( GL_VERTEX_ARRAY );
	glVertexPointer( 3, GL_FLOAT, sizeof(VBOvertexTexture), BUFFER_OFFSET(0) );
	
	glBindTexture( GL_TEXTURE_2D, textureVBO );
	glEnableClientState( GL_TEXTURE_COORD_ARRAY );
	glTexCoordPointer( 2, GL_FLOAT, sizeof(VBOvertexTexture), BUFFER_OFFSET(12) );
	
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER_ARB, indicesVBOid );
	glDrawElements( GL_TRIANGLES, count, GL_UNSIGNED_INT, BUFFER_OFFSET(begin*sizeof(VBOvertexTexture)) );
}

inline void VBOtextured::Draw()
{
	DrawBy( 0, indices.size() );
}

inline void VBOtextured::Delete()
{
	glDeleteBuffers( 1, &verticesVBOid );
	glDeleteBuffers( 1, &indicesVBOid );
	
	vertices.resize( 0 );
	indices.resize( 0 );
	verticesVBOid = 0;
	indicesVBOid = 0;
	textureVBO = 0;
}

VBOtextured::VBOtextured()
{
	textureVBO = 0;
	vertices.resize( 0 );
	indices.resize( 0 );
	verticesVBOid = 0;
	indicesVBOid = 0;
}

VBOtextured::~VBOtextured()
{
	Delete();
}


