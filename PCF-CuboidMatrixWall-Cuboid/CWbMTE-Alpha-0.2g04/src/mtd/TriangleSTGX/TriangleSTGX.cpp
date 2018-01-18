
inline void TriangleSTGX::Draw( unsigned int textureid )
{
    glBegin( GL_TRIANGLE_STRIP );
    
        glBindTexture( GL_TEXTURE_2D, textureid );
        
        for( unsigned int i = 0; i < vertexnumber; i++ )
        {
        	glTexCoord2f( *(texcoordx+i), *(texcoordy+i) );
                glVertex3fv( &vertex[i][0] );
        }   
    glEnd();
}

TriangleSTGX::TriangleSTGX()
{
	vertex = NULL;
	texcoordx = NULL;
	texcoordy = NULL;
    texture = 0;
}

TriangleSTGX::~TriangleSTGX()
{
	if( vertex != NULL )
		delete[] vertex;
	if( texcoordx != NULL )
		delete[] texcoordx;
	if( texcoordy != NULL )
		delete[] texcoordy;
    texture = 0;
}






