
inline void TriangleGX::Draw( unsigned int textureid )
{
    glBegin( GL_TRIANGLES );
    
        glBindTexture( GL_TEXTURE_2D, textureid );
        
        for( unsigned int i = 0; i < vertexnumber; i++ )
        {
        	glTexCoord2f( texcoord[i][0], texcoord[i][1] );
                glVertex3fv( &vertex[i][0] );
        }   
    glEnd();
}

TriangleGX::TriangleGX()
{
    vertex[0].Set( 0.0f, 0.0f, 0.0f );
    vertex[1].Set( 0.0f, 0.0f, 0.0f );
    vertex[2].Set( 0.0f, 0.0f, 0.0f );
    texcoord[0][0] = 0.0f;
    texcoord[0][1] = 0.0f;
    texcoord[1][0] = 0.0f;
    texcoord[1][1] = 0.0f;
    texcoord[2][0] = 0.0f;
    texcoord[2][1] = 0.0f;
    texture = 0;
}

TriangleGX::~TriangleGX()
{
    vertex[0].Set( 0.0f, 0.0f, 0.0f );
    vertex[1].Set( 0.0f, 0.0f, 0.0f );
    vertex[2].Set( 0.0f, 0.0f, 0.0f );
    texcoord[0][0] = 0.0f;
    texcoord[0][1] = 0.0f;
    texcoord[1][0] = 0.0f;
    texcoord[1][1] = 0.0f;
    texcoord[2][0] = 0.0f;
    texcoord[2][1] = 0.0f;
    texture = 0;
}






