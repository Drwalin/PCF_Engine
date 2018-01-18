

void TriangleGX::Draw( unsigned int textureid );
{
    glBegin( GL_TRIANGLES );
    
        glBindTexture( GL_TEXTURE_2D, textureid );
        
        	glTexCoord2f( texcoord[0][0], texcoord[0][1] );
                glVertex3fv( &vertex[0][0] );
        	glTexCoord2f( texcoord[1][0], texcoord[1][1] );
                glVertex3fv( &vertex[1][0] );
        	glTexCoord2f( texcoord[2][0], texcoord[2][1] );
                glVertex3fv( &vertex[2][0] );
                
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






