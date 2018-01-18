



void Map::DrawTriangles()
{
    
glBegin( GL_TRIANGLES );
    unsigned int numb = 0;
    for( numb = 0; numb < triangle.size(); numb++ )
    {
    	glBindTexture( GL_TEXTURE_2D, textures[triangle[numb].texture].texture );
    	
    	glColor3f( 1.0f, 1.0f, 1.0f );
    	
    
        	glTexCoord2f( triangle[numb].image[0][0], triangle[numb].image[0][1] );
        		glVertex3f( triangle[numb].tri[0].vertex[0],
                            triangle[numb].tri[0].vertex[1],
                            triangle[numb].tri[0].vertex[2] );
        
        	glTexCoord2f( triangle[numb].image[1][0], triangle[numb].image[1][1] );
        		glVertex3f( triangle[numb].tri[1].vertex[0],
                            triangle[numb].tri[1].vertex[1],
                            triangle[numb].tri[1].vertex[2] );
        
        	glTexCoord2f( triangle[numb].image[2][0], triangle[numb].image[2][1] );
        		glVertex3f( triangle[numb].tri[2].vertex[0],
                            triangle[numb].tri[2].vertex[1],
                            triangle[numb].tri[2].vertex[2] );
    
    	
    	
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
glEnd();
}
