


void Map::Draw( float FrameTime )
{
	int i;
	for( i = 0; i < staticobject.size(); ++i )
	{
		staticobject[i]->drawpos = staticobject[i]->drawposprim;
	}
	
	
	{
		Vector EyePos = staticobject[0]->GetEyePos();
		glRotatef( -staticobject[0]->see[1], 1.0f, 0.0f, 0.0f );
		glRotatef( -(staticobject[0]->see[0]-90.0f), 0.0f, 1.0f, 0.0f );
		glTranslatef( -EyePos[0], -EyePos[1], -EyePos[2] );
	}
	
	glColor3f( 1.0f, 1.0f, 1.0f );
	glEnable( GL_TEXTURE_2D );
	glDepthFunc( GL_LEQUAL );
	
	glTexEnvf( GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE );
	
	if( updateVBOs == true )
	{
		int BegginTime___ = clock();
		for( i = 0; i < vbotex.size(); ++i )
		{
			vbotex[i].Generate();
		}
		for( i = 0; i < vbocol.size(); ++i )
		{
			vbocol[i].Generate();
		}
		for( i = 0; i < graphicMapModels.size(); ++i )
		{
			printf( "\n loading map model:   \"%s\"", graphicMapModels[i]->name );
			graphicMapModels[i] -> Init( graphicMapModels[i]->name, 0 );
		}
		updateVBOs = false;
		printf( "\n\n     VBOs updating time [ms]: %i\n\n", int((int)clock() - BegginTime___) );
	}
	for( i = 0; i < vbotex.size(); i++ )
	{
		vbotex[i].Draw();
	}
	for( i = 0; i < vbocol.size(); i++ )
	{
		vbocol[i].Draw();
	}
	for( i = 0; i < graphicMapModels.size(); ++i )
	{
		graphicMapModels[i] -> Draw();
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
	
	glDisable( GL_BLEND );
	glDisable( GL_TEXTURE_2D );
	
	particles.Draw();
	for( i = 0; i < NumberOfLightnings; i++ )
	{
		if( lightnings[i].EndingTime > lightnings[i].actualTime )
			lightnings[i].Draw();
	}
	
    glEnable( GL_BLEND );
    glEnable( GL_TEXTURE_2D );
	glColor3ub( 255, 255, 255 );
		
	for( i = 0; i < staticobject.size(); i++ )
	{
		glColor3ub( 255, 255, 255 );
		
		if( DebugMode == true )
		{
			glLineWidth(2.0);
			glDepthFunc( GL_LESS );
			glDisable( GL_BLEND );
			glDisable( GL_TEXTURE_2D );
			glBegin( GL_LINES );
				glVertex3fv( &( staticobject[i]->GetVertexDraw(0)[0] ) );
				glVertex3fv( &( staticobject[i]->GetVertexDraw(1)[0] ) );
				
				glVertex3fv( &( staticobject[i]->GetVertexDraw(1)[0] ) );
				glVertex3fv( &( staticobject[i]->GetVertexDraw(2)[0] ) );
				
				glVertex3fv( &( staticobject[i]->GetVertexDraw(2)[0] ) );
				glVertex3fv( &( staticobject[i]->GetVertexDraw(3)[0] ) );
				
				glVertex3fv( &( staticobject[i]->GetVertexDraw(3)[0] ) );
				glVertex3fv( &( staticobject[i]->GetVertexDraw(0)[0] ) );
				
				glVertex3fv( &( staticobject[i]->GetVertexDraw(4)[0] ) );
				glVertex3fv( &( staticobject[i]->GetVertexDraw(5)[0] ) );
				
				glVertex3fv( &( staticobject[i]->GetVertexDraw(5)[0] ) );
				glVertex3fv( &( staticobject[i]->GetVertexDraw(6)[0] ) );
				
				glVertex3fv( &( staticobject[i]->GetVertexDraw(6)[0] ) );
				glVertex3fv( &( staticobject[i]->GetVertexDraw(7)[0] ) );
				
				glVertex3fv( &( staticobject[i]->GetVertexDraw(7)[0] ) );
				glVertex3fv( &( staticobject[i]->GetVertexDraw(4)[0] ) );
				
				glVertex3fv( &( staticobject[i]->GetVertexDraw(0)[0] ) );
				glVertex3fv( &( staticobject[i]->GetVertexDraw(4)[0] ) );
				
				glVertex3fv( &( staticobject[i]->GetVertexDraw(1)[0] ) );
				glVertex3fv( &( staticobject[i]->GetVertexDraw(5)[0] ) );
				
				glVertex3fv( &( staticobject[i]->GetVertexDraw(2)[0] ) );
				glVertex3fv( &( staticobject[i]->GetVertexDraw(6)[0] ) );
				
				glVertex3fv( &( staticobject[i]->GetVertexDraw(3)[0] ) );
				glVertex3fv( &( staticobject[i]->GetVertexDraw(7)[0] ) );
			glEnd();
		}
		if( staticobject[i]->model != NULL )
		{
			glTranslatef( staticobject[i]->GetBarycentricDraw()[0], staticobject[i]->GetBarycentricDraw()[1], staticobject[i]->GetBarycentricDraw()[2] );//,staticobject[i]->drawpos[0]+(staticobject[i]->size[0]*0.5f), staticobject[i]->drawpos[1]+(staticobject[i]->size[1]*0.5f), staticobject[i]->drawpos[2]+(staticobject[i]->size[2]*0.5f) );
			glRotatef(  90.0f+staticobject[i]->see[0], 0.0f, 1.0f, 0.0f );
			
			glScalef( staticobject[i]->GraphicModelScale, staticobject[i]->GraphicModelScale, staticobject[i]->GraphicModelScale );
			staticobject[i] -> model -> Draw();
			glScalef( 1.0f/staticobject[i]->GraphicModelScale, 1.0f/staticobject[i]->GraphicModelScale, 1.0f/staticobject[i]->GraphicModelScale );
			
			glRotatef( -90.0f-staticobject[i]->see[0], 0.0f, 1.0f, 0.0f );
			glTranslatef( -staticobject[i]->GetBarycentricDraw()[0], -staticobject[i]->GetBarycentricDraw()[1], -staticobject[i]->GetBarycentricDraw()[2] );//-staticobject[i]->drawpos[0]-(staticobject[i]->size[0]*0.5f), -staticobject[i]->drawpos[1]-(staticobject[i]->size[1]*0.5f), -staticobject[i]->drawpos[2]-(staticobject[i]->size[2]*0.5f) );
		}
	}
}


