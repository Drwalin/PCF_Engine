


void Map::Draw( float FrameTime )
{
	glRotatef( -staticobject[0]->see[1], 1.0f, 0.0f, 0.0f );
	glRotatef( -(staticobject[0]->see[0]-90.0f), 0.0f, 1.0f, 0.0f );
	glTranslatef( -(staticobject[0]->pos[0]+(staticobject[0]->aabb[0].size[0]*0.5f)), -(staticobject[0]->pos[1]+(staticobject[0]->aabb[0].size[1]*0.9f)), -(staticobject[0]->pos[2]+(staticobject[0]->aabb[0].size[2]*0.5f)) );
	
	glColor3f( 1.0f, 1.0f, 1.0f );
	glEnable( GL_TEXTURE_2D );
	glDepthFunc( GL_LESS );
	
	int i;
	for( i = 0; i < vbotex.size(); i++ )
	{
		vbotex[i].Draw();
	}
	
	for( i = 0; i < vbocol.size(); i++ )
	{
		vbocol[i].Draw();
	}
	
	particles.Update( FrameTime );
	for( i = 0; i < NumberOfLightnings; i++ )
	{
		lightnings[i].Update( FrameTime );
		if( lightnings[i].actualTime > lightnings[i].EndingTime )
		{
			if( lightnings[i].EndingTime != 0.0f )
			{
				lightnings[i].EndingTime = 0.0f;
				delete[] lightnings[i].vertex.children;
				lightnings[i].vertex.children = NULL;
			}
		}
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
		
		if( staticobject[i]->model == NULL )
		{
			glLineWidth(2.0);
			glDepthFunc( GL_LESS );
			glDisable( GL_BLEND );
			glDisable( GL_TEXTURE_2D );
			glBegin( GL_LINES );
				glVertex3fv( &( ( staticobject[i]->aabb[0].GetVertex(0) + staticobject[i]->pos )[0] ) );
				glVertex3fv( &( ( staticobject[i]->aabb[0].GetVertex(1) + staticobject[i]->pos )[0] ) );
				
				glVertex3fv( &( ( staticobject[i]->aabb[0].GetVertex(1) + staticobject[i]->pos )[0] ) );
				glVertex3fv( &( ( staticobject[i]->aabb[0].GetVertex(2) + staticobject[i]->pos )[0] ) );
				
				glVertex3fv( &( ( staticobject[i]->aabb[0].GetVertex(2) + staticobject[i]->pos )[0] ) );
				glVertex3fv( &( ( staticobject[i]->aabb[0].GetVertex(3) + staticobject[i]->pos )[0] ) );
				
				glVertex3fv( &( ( staticobject[i]->aabb[0].GetVertex(3) + staticobject[i]->pos )[0] ) );
				glVertex3fv( &( ( staticobject[i]->aabb[0].GetVertex(0) + staticobject[i]->pos )[0] ) );
				
				glVertex3fv( &( ( staticobject[i]->aabb[0].GetVertex(4) + staticobject[i]->pos )[0] ) );
				glVertex3fv( &( ( staticobject[i]->aabb[0].GetVertex(5) + staticobject[i]->pos )[0] ) );
				
				glVertex3fv( &( ( staticobject[i]->aabb[0].GetVertex(5) + staticobject[i]->pos )[0] ) );
				glVertex3fv( &( ( staticobject[i]->aabb[0].GetVertex(6) + staticobject[i]->pos )[0] ) );
				
				glVertex3fv( &( ( staticobject[i]->aabb[0].GetVertex(6) + staticobject[i]->pos )[0] ) );
				glVertex3fv( &( ( staticobject[i]->aabb[0].GetVertex(7) + staticobject[i]->pos )[0] ) );
				
				glVertex3fv( &( ( staticobject[i]->aabb[0].GetVertex(7) + staticobject[i]->pos )[0] ) );
				glVertex3fv( &( ( staticobject[i]->aabb[0].GetVertex(4) + staticobject[i]->pos )[0] ) );
				
				glVertex3fv( &( ( staticobject[i]->aabb[0].GetVertex(0) + staticobject[i]->pos )[0] ) );
				glVertex3fv( &( ( staticobject[i]->aabb[0].GetVertex(4) + staticobject[i]->pos )[0] ) );
				
				glVertex3fv( &( ( staticobject[i]->aabb[0].GetVertex(1) + staticobject[i]->pos )[0] ) );
				glVertex3fv( &( ( staticobject[i]->aabb[0].GetVertex(5) + staticobject[i]->pos )[0] ) );
				
				glVertex3fv( &( ( staticobject[i]->aabb[0].GetVertex(2) + staticobject[i]->pos )[0] ) );
				glVertex3fv( &( ( staticobject[i]->aabb[0].GetVertex(6) + staticobject[i]->pos )[0] ) );
				
				glVertex3fv( &( ( staticobject[i]->aabb[0].GetVertex(3) + staticobject[i]->pos )[0] ) );
				glVertex3fv( &( ( staticobject[i]->aabb[0].GetVertex(7) + staticobject[i]->pos )[0] ) );
			glEnd();
		}
		else
		{
			glTranslatef( (staticobject[i]->min[0]+staticobject[i]->max[0])*0.5f, (staticobject[i]->min[1]+staticobject[i]->max[1])*0.5f, (staticobject[i]->min[2]+staticobject[i]->max[2])*0.5f );
			glRotatef(  90.0f+staticobject[i]->see[0], 0.0f, 1.0f, 0.0f );
			
			glScalef( staticobject[i]->GraphicModelScale, staticobject[i]->GraphicModelScale, staticobject[i]->GraphicModelScale );
			//glScalef( ((staticobject[i]->max-staticobject[i]->min)[0]), ((staticobject[i]->max-staticobject[i]->min)[1]), ((staticobject[i]->max-staticobject[i]->min)[2]) );
			staticobject[i]->model -> Draw();
			//glScalef( 1.0f/((staticobject[i]->max-staticobject[i]->min)[0]), 1.0f/((staticobject[i]->max-staticobject[i]->min)[1]), 1.0f/((staticobject[i]->max-staticobject[i]->min)[2]) );
			glScalef( 1.0f/staticobject[i]->GraphicModelScale, 1.0f/staticobject[i]->GraphicModelScale, 1.0f/staticobject[i]->GraphicModelScale );
			
			glRotatef( -90.0f-staticobject[i]->see[0], 0.0f, 1.0f, 0.0f );
			glTranslatef( -(staticobject[i]->min[0]+staticobject[i]->max[0])*0.5f, -(staticobject[i]->min[1]+staticobject[i]->max[1])*0.5f, -(staticobject[i]->min[2]+staticobject[i]->max[2])*0.5f );
		}
	}
	
    glEnable( GL_BLEND );
    glEnable( GL_TEXTURE_2D );
	
	glColor3ub( 255, 255, 255 );
	
	glDepthFunc( GL_ALWAYS );
}


