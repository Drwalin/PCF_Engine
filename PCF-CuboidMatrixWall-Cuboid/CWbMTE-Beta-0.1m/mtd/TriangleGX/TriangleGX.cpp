

inline void TriangleGX::Draw()
{
//	glBegin( GL_TRIANGLES );
//		glBindTexture( GL_TEXTURE_2D, textureid );
			glTexCoord2fv( texcoord[0] );
				glVertex3fv( &vertex[0][0] );
			glTexCoord2fv( texcoord[1] );
				glVertex3fv( &vertex[1][0] );
			glTexCoord2fv( texcoord[2] );
				glVertex3fv( &vertex[2][0] );
//	glEnd();
}

inline void TriangleGX::SetTexture( unsigned int src )
{
	texture = src;
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






