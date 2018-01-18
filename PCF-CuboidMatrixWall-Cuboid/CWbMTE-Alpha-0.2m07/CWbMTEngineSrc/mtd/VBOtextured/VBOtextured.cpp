


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

inline void VBOtextured::SetTexture( char * filename, int type )
{
	textureVBO.LoadInit( filename, type );
}

inline void VBOtextured::Generate()
{
	//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress( "glGenBuffers" );
    glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress( "glBindBuffer" );
    glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress( "glBufferData" );
//    glMapBuffer = (PFNGLMAPBUFFERPROC)wglGetProcAddress( "glMapBuffer" );
	
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
	
	textureVBO.Bind();
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
    glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)wglGetProcAddress("glDeleteBuffers" );
    
	glDeleteBuffers( 1, &verticesVBOid );
	glDeleteBuffers( 1, &indicesVBOid );
	
	vertices.resize( 0 );
	indices.resize( 0 );
	textureVBO.Delete();
	verticesVBOid = 0;
	indicesVBOid = 0;
}


