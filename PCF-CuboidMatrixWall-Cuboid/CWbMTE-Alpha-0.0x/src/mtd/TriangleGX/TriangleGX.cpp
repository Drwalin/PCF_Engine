

inline void TriangleGX::Draw()
{
//	glBegin( GL_TRIANGLES );
//		glBindTexture( GL_TEXTURE_2D, textureid );
		glColor3f( 0.1f, (vertex[0][1]+20.0f)/40.0f, 0.2f );
			glTexCoord2fv( texcoord[0] );
				glVertex3fv( &vertex[0][0] );
		glColor3f( 0.1f, (vertex[1][1]+20.0f)/40.0f, 0.2f );
			glTexCoord2fv( texcoord[1] );
				glVertex3fv( &vertex[1][0] );
		glColor3f( 0.1f, (vertex[2][1]+20.0f)/40.0f, 0.2f );
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






