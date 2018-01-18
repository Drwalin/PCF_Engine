



void Map::DrawTriangles()
{
    
    
    	glColor3f( 1.0f, 1.0f, 1.0f );
glEnable( GL_BLEND );
    unsigned int numb = 0;
    for( numb = 0; numb < triangle.size(); numb++ )
    {
    	if( triangle[numb].texture > 0 && triangle[numb].texture <= textures.size()  )
    	{
    	        glBindTexture( GL_TEXTURE_2D, textures[triangle[numb].texture-1].texture );
    	
glBegin( GL_TRIANGLES );
    
                glTexCoord2f( triangle[numb].image[0][0], triangle[numb].image[0][1] );
                    glVertex3f( triangle[numb].tri[0].vector[0],
                                triangle[numb].tri[0].vector[1],
                                triangle[numb].tri[0].vector[2] );
        
        	    glTexCoord2f( triangle[numb].image[1][0], triangle[numb].image[1][1] );
        		    glVertex3f( triangle[numb].tri[1].vector[0],
                                triangle[numb].tri[1].vector[1],
                                triangle[numb].tri[1].vector[2] );
        
            	glTexCoord2f( triangle[numb].image[2][0], triangle[numb].image[2][1] );
        	        glVertex3f( triangle[numb].tri[2].vector[0],
                                triangle[numb].tri[2].vector[1],
                                triangle[numb].tri[2].vector[2] );
    
    	
glEnd();


    	/*
    	if( DRAWNORMAL )
    	{
        	glBegin( GL_LINES );
        	
        	glColor3f( 0.0f, 0.0f, 0.0f );
        	/*
        	   glVertex3fv( tri[numb].tri[0][0], tri[numb].tri[0][1], tri[numb].tri[0][2] );
        	   glVertex3f ( tri[numb].tri[0][0] + tri[numb].normal[0], tri[numb].tri[0][1] + tri[numb].normal[1], tri[numb].tri[0][2] + tri[numb].normal[2] );
        	   
        	   glVertex3fv( tri[numb].tri[1][0], tri[numb].tri[1][1], tri[numb].tri[1][2] );
        	   glVertex3f ( tri[numb].tri[1][0] + tri[numb].normal[0], tri[numb].tri[1][1] + tri[numb].normal[1], tri[numb].tri[1][2] + tri[numb].normal[2] );
        	   
        	   glVertex3fv( tri[numb].tri[2][0], tri[numb].tri[2][1], tri[numb].tri[2][2] );
        	   glVertex3f ( tri[numb].tri[2][0] + tri[numb].normal[0], tri[numb].tri[2][1] + tri[numb].normal[1], tri[numb].tri[2][2] + tri[numb].normal[2] );
        	   
        	   
        	   glVertex3f( tri[numb].sphere[0], tri[numb].sphere[1], tri[numb].sphere[2] );
        	   glVertex3f( tri[numb].sphere[0] + tri[numb].normal[0], tri[numb].sphere[1] + tri[numb].normal[1], tri[numb].sphere[2] + tri[numb].normal[2] );
        	*/
        	/*
        	glEnd();
        }
        */
        
        }
    }
}
