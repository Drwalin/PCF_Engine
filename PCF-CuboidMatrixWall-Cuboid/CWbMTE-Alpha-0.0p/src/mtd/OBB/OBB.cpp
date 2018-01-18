


inline void OBB::DrawEdges()
{	
    glDisable( GL_BLEND );
    glDisable( GL_TEXTURE_2D );
    
	glLineWidth(10.0);
	
	glBegin( GL_LINES );
		
		glColor3ub( 200, 200, 200 );
		
		glVertex3fv( &( (GetVertex(0) )[0] ) );
		glVertex3fv( &( (GetVertex(1) )[0] ) );
		
		glVertex3fv( &( (GetVertex(1) )[0] ) );
		glVertex3fv( &( (GetVertex(2) )[0] ) );
		
		glVertex3fv( &( (GetVertex(2) )[0] ) );
		glVertex3fv( &( (GetVertex(3) )[0] ) );
		
		glVertex3fv( &( (GetVertex(3) )[0] ) );
		glVertex3fv( &( (GetVertex(0) )[0] ) );
		
		glVertex3fv( &( (GetVertex(4) )[0] ) );
		glVertex3fv( &( (GetVertex(5) )[0] ) );
		
		glVertex3fv( &( (GetVertex(5) )[0] ) );
		glVertex3fv( &( (GetVertex(6) )[0] ) );
		
		glVertex3fv( &( (GetVertex(6) )[0] ) );
		glVertex3fv( &( (GetVertex(7) )[0] ) );
		
		glVertex3fv( &( (GetVertex(7) )[0] ) );
		glVertex3fv( &( (GetVertex(4) )[0] ) );
		
		glVertex3fv( &( (GetVertex(0) )[0] ) );
		glVertex3fv( &( (GetVertex(4) )[0] ) );
		
		glVertex3fv( &( (GetVertex(1) )[0] ) );
		glVertex3fv( &( (GetVertex(5) )[0] ) );
		
		glVertex3fv( &( (GetVertex(2) )[0] ) );
		glVertex3fv( &( (GetVertex(6) )[0] ) );
		
		glVertex3fv( &( (GetVertex(3) )[0] ) );
		glVertex3fv( &( (GetVertex(7) )[0] ) );
		
	glEnd();
	
    glEnable( GL_BLEND );
    glEnable( GL_TEXTURE_2D );
}

inline Vector OBB::GetVertex( int id )
{
	switch( ((unsigned int)id)%8 )
	{
	case 0:
		return rotate.GetVertex( SetVector( -size[0], -size[1], -size[2] ) ) + pos;
	case 1:
		return rotate.GetVertex( SetVector( size[0], -size[1], -size[2] ) ) + pos;
	case 2:
		return rotate.GetVertex( SetVector( size[0], -size[1], size[2] ) ) + pos;
	case 3:
		return rotate.GetVertex( SetVector( -size[0], -size[1], size[2] ) ) + pos;
	case 4:
		return rotate.GetVertex( SetVector( -size[0], size[1], -size[2] ) ) + pos;
	case 5:
		return rotate.GetVertex( SetVector( size[0], size[1], -size[2] ) ) + pos;
	case 6:
		return rotate.GetVertex( SetVector( size[0], size[1], size[2] ) ) + pos;
	case 7:
		return rotate.GetVertex( SetVector( -size[0], size[1], size[2] ) ) + pos;
	}
	return SetVector( 0.0f, 0.0f, 0.0f );
}


OBB::OBB()
{
	bpos.Set( 0.0f, 0.0f, 0.0f );
	pos.Set( 0.0f, 0.0f, 0.0f );
	size.Set( 0.5f, 0.5f, 0.5f );
	
	vel.Set( 0.0f, 0.0f, 0.0f );
	force.Set( 0.0f, 0.0f, 0.0f );
	resistanceforce.Set( 0.0f, 0.0f, 0.0f );
	
	mass = 1.0f;
	
	Collision = false;
	
	rotate.InitEmpty();
	rotatespeed.InitEmpty();
	mass = 0.0f;
}

OBB::~OBB()
{
	bpos.Set( 0.0f, 0.0f, 0.0f );
	pos.Set( 0.0f, 0.0f, 0.0f );
	size.Set( 0.0f, 0.0f, 0.0f );
	
	vel.Set( 0.0f, 0.0f, 0.0f );
	force.Set( 0.0f, 0.0f, 0.0f );
	resistanceforce.Set( 0.0f, 0.0f, 0.0f );
	
	mass = 0.0f;
	
	Collision = false;
	
	rotate.InitEmpty();
	rotatespeed.InitEmpty();
	mass = 0.0f;
}


