


void Map::Draw()
{
	glRotatef( -staticobject[0].see[1], 1.0f, 0.0f, 0.0f );
	glRotatef( -(staticobject[0].see[0]-90.0f), 0.0f, 1.0f, 0.0f );
	glTranslatef( -(staticobject[0].pos[0]+(staticobject[0].aabb[0].size[0]*0.5f)), -(staticobject[0].pos[1]+(staticobject[0].aabb[0].size[1]*0.9f)), -(staticobject[0].pos[2]+(staticobject[0].aabb[0].size[2]*0.5f)) );
	
	glColor3f( 1.0f, 1.0f, 1.0f );
	glEnable( GL_TEXTURE_2D );
	glDepthFunc( GL_LESS );
	
	texture[0].Bind();
	
	int i;
	for( i = 0; i < vbotex.size(); i++ )
	{
		vbotex[i].Draw();
	}
	
	for( i = 0; i < vbocol.size(); i++ )
	{
		vbocol[i].Draw();
	}
	
    TrianglePX * triangle;
    PhysicModelStatic * object;
	
	{
		engineInstantiation->map.staticobject[1].see[0] += 0.1f;
		
		VMatrix matrix;
		matrix.InitEmpty();
		matrix.RotateY( (engineInstantiation->map.staticobject[1].see[0]+90.0f) );
		matrix.RotateX( -(engineInstantiation->map.staticobject[1].see[1]) );
		engineInstantiation->SegmentCollision(
							engineInstantiation->map.staticobject[1].pos+(engineInstantiation->map.staticobject[1].aabb[0].size*SetVector(0.5f,0.8f,0.5f)),
							engineInstantiation->map.staticobject[1].pos+(engineInstantiation->map.staticobject[1].aabb[0].size*SetVector(0.5f,0.8f,0.5f)) + matrix.GetVertex( SetVector( 0.0f, 0.0f, 300.0f ) ),
							&object, &triangle, &(engineInstantiation->map.staticobject[1]) );
		glDepthFunc( GL_LESS );
		glLineWidth( 5.0f );
		glBegin( GL_LINES );
			glColor3f( 1.0f, 0.1f, 0.1f );
			glVertex3fv( &( ( engineInstantiation->map.staticobject[1].pos+(engineInstantiation->map.staticobject[1].aabb[0].size*SetVector(0.5f,0.8f,0.5f)) )[0] ) );
			glVertex3fv( &( ( engineInstantiation->map.staticobject[1].pos+(engineInstantiation->map.staticobject[1].aabb[0].size*SetVector(0.5f,0.8f,0.5f)) + matrix.GetVertex( SetVector( 0.0f, 0.0f, 300.0f ) ) )[0] ) );
		glEnd();
		
		matrix.InitEmpty();
		matrix.RotateY( (engineInstantiation->map.staticobject[0].see[0]+90.0f) );
		matrix.RotateX( -(engineInstantiation->map.staticobject[0].see[1]) );
		engineInstantiation->SegmentCollision(
							engineInstantiation->map.staticobject[0].pos+(engineInstantiation->map.staticobject[0].aabb[0].size*SetVector(0.5f,0.9f,0.5f)),
							engineInstantiation->map.staticobject[0].pos+(engineInstantiation->map.staticobject[0].aabb[0].size*SetVector(0.5f,0.9f,0.5f)) + matrix.GetVertex( SetVector( 0.0f, 0.0f, 300.0f ) ),
							&object, &triangle, &(engineInstantiation->map.staticobject[0]) );
	}
	
	
	if( triangle != NULL )
	{
		glLineWidth( 45.0f );
		glColor3f( 1.0f, 0.2f, 0.2f );
		glBegin( GL_LINE_LOOP );
			glVertex3fv( &((triangle->vertex[0])[0]) );
			glVertex3fv( &((triangle->vertex[1])[0]) );
			glVertex3fv( &((triangle->vertex[2])[0]) );
		glEnd();
	}
	
	glEnable( GL_BLEND );
	glEnable( GL_TEXTURE_2D );
	
	particles.Draw();
	glDisable( GL_BLEND );
	glDisable( GL_TEXTURE_2D );
	for( i = 0; i < NumberOfLightnings; i++ )
	{
		if( lightnings[i].EndingTime > lightnings[i].actualTime )
			lightnings[i].Draw();
	}
		
	for( i = 0; i < staticobject.size(); i++ )
	{
		glColor3ub( 255, 255, 255 );
		
		if( staticobject[i].model == NULL )
		{
			glLineWidth(2.0);
			glDepthFunc( GL_LESS );
			glDisable( GL_BLEND );
			glDisable( GL_TEXTURE_2D );
			glBegin( GL_LINES );
				glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(0) + staticobject[i].pos )[0] ) );
				glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(1) + staticobject[i].pos )[0] ) );
				
				glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(1) + staticobject[i].pos )[0] ) );
				glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(2) + staticobject[i].pos )[0] ) );
				
				glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(2) + staticobject[i].pos )[0] ) );
				glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(3) + staticobject[i].pos )[0] ) );
				
				glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(3) + staticobject[i].pos )[0] ) );
				glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(0) + staticobject[i].pos )[0] ) );
				
				glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(4) + staticobject[i].pos )[0] ) );
				glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(5) + staticobject[i].pos )[0] ) );
				
				glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(5) + staticobject[i].pos )[0] ) );
				glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(6) + staticobject[i].pos )[0] ) );
				
				glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(6) + staticobject[i].pos )[0] ) );
				glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(7) + staticobject[i].pos )[0] ) );
				
				glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(7) + staticobject[i].pos )[0] ) );
				glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(4) + staticobject[i].pos )[0] ) );
				
				glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(0) + staticobject[i].pos )[0] ) );
				glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(4) + staticobject[i].pos )[0] ) );
				
				glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(1) + staticobject[i].pos )[0] ) );
				glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(5) + staticobject[i].pos )[0] ) );
				
				glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(2) + staticobject[i].pos )[0] ) );
				glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(6) + staticobject[i].pos )[0] ) );
				
				glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(3) + staticobject[i].pos )[0] ) );
				glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(7) + staticobject[i].pos )[0] ) );
			glEnd();
		}
		else
		{
			glTranslatef( (staticobject[i].min[0]+staticobject[i].max[0])*0.5f, (staticobject[i].min[1]+staticobject[i].max[1])*0.5f, (staticobject[i].min[2]+staticobject[i].max[2])*0.5f );
			glRotatef(  90.0f+staticobject[i].see[0], 0.0f, 1.0f, 0.0f );
			
			glScalef( ((staticobject[i].max-staticobject[i].min)[0]), ((staticobject[i].max-staticobject[i].min)[1]), ((staticobject[i].max-staticobject[i].min)[2]) );
			staticobject[i].model -> Draw();
			glScalef( 1.0f/((staticobject[i].max-staticobject[i].min)[0]), 1.0f/((staticobject[i].max-staticobject[i].min)[1]), 1.0f/((staticobject[i].max-staticobject[i].min)[2]) );
			
			glRotatef( -90.0f-staticobject[i].see[0], 0.0f, 1.0f, 0.0f );
			glTranslatef( -(staticobject[i].min[0]+staticobject[i].max[0])*0.5f, -(staticobject[i].min[1]+staticobject[i].max[1])*0.5f, -(staticobject[i].min[2]+staticobject[i].max[2])*0.5f );
		}
	}
	
    glEnable( GL_BLEND );
    glEnable( GL_TEXTURE_2D );
	
	glColor3ub( 255, 255, 255 );
	
	glDepthFunc( GL_ALWAYS );
	
	glLoadIdentity();
}


