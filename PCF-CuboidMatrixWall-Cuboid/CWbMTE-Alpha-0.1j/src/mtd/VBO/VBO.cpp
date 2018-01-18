


inline void VBO::AddVertex( float x, float y, float z, float texcoordx, float texcoordy )
{
	VBOvertex vert;
	vert.x = x;
	vert.y = y;
	vert.z = z;
	vert.texcoordx = texcoordx;
	vert.texcoordy = texcoordy;
	vertices.push_back( vert );
}

inline void VBO::AddTriangle( unsigned int a, unsigned int b, unsigned int c )
{
	indices.push_back( a );
	indices.push_back( b );
	indices.push_back( c );
}

inline void VBO::SetTexture( char * filename )
{
	textureVBO.LoadInit( filename );
}

inline void VBO::Generate()
{
	//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress( "glGenBuffers" );
    glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress( "glBindBuffer" );
    glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress( "glBufferData" );
    glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)wglGetProcAddress("glDeleteBuffers" );
//    glMapBuffer = (PFNGLMAPBUFFERPROC)wglGetProcAddress( "glMapBuffer" );
	
	glGenBuffers( 1, &verticesVBOid );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER_ARB, verticesVBOid );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER_ARB, sizeof(VBOvertex)*vertices.size(), &vertices[0].x, GL_STATIC_DRAW_ARB );
	
	glGenBuffers( 1, &indicesVBOid );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER_ARB, indicesVBOid );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER_ARB, sizeof(int)*indices.size(), &indices[0], GL_STATIC_DRAW );
}

#define BUFFER_OFFSET(i) ((void*)(i))

inline void VBO::Draw()
{
	glEnable( GL_TEXTURE_2D );
	glEnable( GL_DEPTH_TEST );
	glDepthFunc( GL_LESS );
	glEnable( GL_BLEND );
	
	glBindBuffer( GL_ARRAY_BUFFER_ARB, verticesVBOid );
	glEnableClientState( GL_VERTEX_ARRAY );
	glVertexPointer( 3, GL_FLOAT, sizeof(VBOvertex), BUFFER_OFFSET(0) );
//	glEnableClientState( GL_COLOR_ARRAY );
//	glColorPointer( 3, GL_UNSIGNED_BYTE, sizeof(VBOvertex), BUFFER_OFFSET(#INF#) );
	
	textureVBO.Bind();
	glEnableClientState( GL_TEXTURE_COORD_ARRAY );
	glTexCoordPointer( 2, GL_FLOAT, sizeof(VBOvertex), BUFFER_OFFSET(12) );
	
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER_ARB, indicesVBOid );
	glDrawElements( GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, BUFFER_OFFSET(0) );
}


