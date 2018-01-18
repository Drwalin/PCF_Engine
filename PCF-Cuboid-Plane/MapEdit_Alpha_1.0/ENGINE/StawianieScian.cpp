
void EmptyWallsFunction___( float * nullpoint, float backresize, float rightresize, float highresize, unsigned int texture ){}



void FloorFunction( float * nullpoint, float backresize, float rightresize, float highresize, unsigned int texture )
{
    map.tri.resize( map.tri.size() + 2 );
    map.tri[map.tri.size()-2].tri[0][0] = nullpoint[0];
    map.tri[map.tri.size()-2].tri[0][1] = nullpoint[1];
    map.tri[map.tri.size()-2].tri[0][2] = nullpoint[2];
    
    map.tri[map.tri.size()-2].tri[1][0] = nullpoint[0]+backresize;
    map.tri[map.tri.size()-2].tri[1][1] = nullpoint[1];
    map.tri[map.tri.size()-2].tri[1][2] = nullpoint[2];
    
    map.tri[map.tri.size()-2].tri[2][0] = nullpoint[0]+backresize;
    map.tri[map.tri.size()-2].tri[2][1] = nullpoint[1];
    map.tri[map.tri.size()-2].tri[2][2] = nullpoint[2]+rightresize;
    
    map.tri[map.tri.size()-2].texture = texture;
    
    map.tri[map.tri.size()-2].image[0][0] = 0.0f;
    map.tri[map.tri.size()-2].image[0][1] = 0.0f;
    map.tri[map.tri.size()-2].image[1][0] = 1.0f;
    map.tri[map.tri.size()-2].image[1][1] = 0.0f;
    map.tri[map.tri.size()-2].image[2][0] = 1.0f;
    map.tri[map.tri.size()-2].image[2][1] = 1.0f;
    
    map.tri[map.tri.size()-2].drawtexture = 1;
    
    
    
    
    
    map.tri[map.tri.size()-1].tri[0][0] = nullpoint[0];
    map.tri[map.tri.size()-1].tri[0][1] = nullpoint[1];
    map.tri[map.tri.size()-1].tri[0][2] = nullpoint[2];
    
    map.tri[map.tri.size()-1].tri[1][0] = nullpoint[0]+backresize;
    map.tri[map.tri.size()-1].tri[1][1] = nullpoint[1];
    map.tri[map.tri.size()-1].tri[1][2] = nullpoint[2]+rightresize;
    
    map.tri[map.tri.size()-1].tri[2][0] = nullpoint[0];
    map.tri[map.tri.size()-1].tri[2][1] = nullpoint[1];
    map.tri[map.tri.size()-1].tri[2][2] = nullpoint[2]+rightresize;
    
    map.tri[map.tri.size()-1].texture = texture;
    
    map.tri[map.tri.size()-1].image[0][0] = 0.0f;
    map.tri[map.tri.size()-1].image[0][1] = 0.0f;
    map.tri[map.tri.size()-1].image[1][0] = 1.0f;
    map.tri[map.tri.size()-1].image[1][1] = 1.0f;
    map.tri[map.tri.size()-1].image[2][0] = 0.0f;
    map.tri[map.tri.size()-1].image[2][1] = 1.0f;
    
    map.tri[map.tri.size()-1].drawtexture = 1;
}


void FloorFunctionDraw( float * nullpoint, float backresize, float rightresize, float highresize, unsigned int texture )
{
    	glBindTexture( GL_TEXTURE_2D, map.texture[texture] );
    	
    	glColor3f( 1.0f, 1.0f, 1.0f );
    	
    	glBegin( GL_QUADS );
    
        	glTexCoord2f( 0.0f, 0.0f );
        		glVertex3f( nullpoint[0], nullpoint[1], nullpoint[2] );
        
        	glTexCoord2f( 1.0f, 0.0f );
        		glVertex3f( nullpoint[0]+backresize, nullpoint[1], nullpoint[2] );
        
        	glTexCoord2f( 1.0f, 1.0f );
        		glVertex3f( nullpoint[0]+backresize, nullpoint[1], nullpoint[2]+rightresize );
        		
        	glTexCoord2f( 0.0f, 1.0f );
        		glVertex3f( nullpoint[0], nullpoint[1], nullpoint[2]+rightresize );
    
    	glEnd();
    	
    	
}



void WallFunction( float * nullpoint, float backresize, float rightresize, float highresize, unsigned int texture )
{
    map.tri.resize( map.tri.size() + 2 );
    map.tri[map.tri.size()-2].tri[0][0] = nullpoint[0];
    map.tri[map.tri.size()-2].tri[0][1] = nullpoint[1];
    map.tri[map.tri.size()-2].tri[0][2] = nullpoint[2];
    
    map.tri[map.tri.size()-2].tri[1][0] = nullpoint[0];
    map.tri[map.tri.size()-2].tri[1][1] = nullpoint[1]+highresize;
    map.tri[map.tri.size()-2].tri[1][2] = nullpoint[2];
    
    map.tri[map.tri.size()-2].tri[2][0] = nullpoint[0]+backresize;
    map.tri[map.tri.size()-2].tri[2][1] = nullpoint[1]+highresize;
    map.tri[map.tri.size()-2].tri[2][2] = nullpoint[2]+rightresize;
    
    map.tri[map.tri.size()-2].texture = texture;
    
    map.tri[map.tri.size()-2].image[0][0] = 0.0f;
    map.tri[map.tri.size()-2].image[0][1] = 0.0f;
    map.tri[map.tri.size()-2].image[1][0] = 1.0f;
    map.tri[map.tri.size()-2].image[1][1] = 0.0f;
    map.tri[map.tri.size()-2].image[2][0] = 1.0f;
    map.tri[map.tri.size()-2].image[2][1] = 1.0f;
    
    map.tri[map.tri.size()-2].drawtexture = 1;
    
    
    
    
    
    map.tri[map.tri.size()-1].tri[0][0] = nullpoint[0];
    map.tri[map.tri.size()-1].tri[0][1] = nullpoint[1];
    map.tri[map.tri.size()-1].tri[0][2] = nullpoint[2];
    
    map.tri[map.tri.size()-1].tri[1][0] = nullpoint[0]+backresize;
    map.tri[map.tri.size()-1].tri[1][1] = nullpoint[1]+highresize;
    map.tri[map.tri.size()-1].tri[1][2] = nullpoint[2]+rightresize;
    
    map.tri[map.tri.size()-1].tri[2][0] = nullpoint[0]+backresize;
    map.tri[map.tri.size()-1].tri[2][1] = nullpoint[1];
    map.tri[map.tri.size()-1].tri[2][2] = nullpoint[2]+rightresize;
    
    map.tri[map.tri.size()-1].texture = texture;
    
    map.tri[map.tri.size()-1].image[0][0] = 0.0f;
    map.tri[map.tri.size()-1].image[0][1] = 0.0f;
    map.tri[map.tri.size()-1].image[1][0] = 1.0f;
    map.tri[map.tri.size()-1].image[1][1] = 1.0f;
    map.tri[map.tri.size()-1].image[2][0] = 0.0f;
    map.tri[map.tri.size()-1].image[2][1] = 1.0f;
    
    map.tri[map.tri.size()-1].drawtexture = 1;
}


void WallFunctionDraw( float * nullpoint, float backresize, float rightresize, float highresize, unsigned int texture )
{
    	glBindTexture( GL_TEXTURE_2D, map.texture[texture] );
    	
    	glColor3f( 1.0f, 1.0f, 1.0f );
    	
    	glBegin( GL_QUADS );
    
        	glTexCoord2f( 0.0f, 0.0f );
        		glVertex3f( nullpoint[0], nullpoint[1], nullpoint[2] );
        
        	glTexCoord2f( 1.0f, 0.0f );
        		glVertex3f( nullpoint[0], nullpoint[1]+highresize, nullpoint[2] );
        
        	glTexCoord2f( 1.0f, 1.0f );
        		glVertex3f( nullpoint[0]+backresize, nullpoint[1]+highresize, nullpoint[2]+rightresize );
        		
        	glTexCoord2f( 0.0f, 1.0f );
        		glVertex3f( nullpoint[0]+backresize, nullpoint[1], nullpoint[2]+rightresize );
    
    	glEnd();
    	
    	
}





void TriangleFunction( float * nullpoint, float backresize, float rightresize, float highresize, unsigned int texture )
{
    map.tri.resize( map.tri.size() + 2 );
    map.tri[map.tri.size()-2].tri[0][0] = nullpoint[0];
    map.tri[map.tri.size()-2].tri[0][1] = nullpoint[1];
    map.tri[map.tri.size()-2].tri[0][2] = nullpoint[2];
    
    map.tri[map.tri.size()-2].tri[1][0] = nullpoint[0]+backresize;
    map.tri[map.tri.size()-2].tri[1][1] = nullpoint[1]+highresize;
    map.tri[map.tri.size()-2].tri[1][2] = nullpoint[2];
    
    map.tri[map.tri.size()-2].tri[2][0] = nullpoint[0];
    map.tri[map.tri.size()-2].tri[2][1] = nullpoint[1]+highresize;
    map.tri[map.tri.size()-2].tri[2][2] = nullpoint[2]+rightresize;
    
    map.tri[map.tri.size()-2].texture = texture;
    
    map.tri[map.tri.size()-2].image[0][0] = 0.0f;
    map.tri[map.tri.size()-2].image[0][1] = 0.0f;
    map.tri[map.tri.size()-2].image[1][0] = 1.0f;
    map.tri[map.tri.size()-2].image[1][1] = 0.0f;
    map.tri[map.tri.size()-2].image[2][0] = 1.0f;
    map.tri[map.tri.size()-2].image[2][1] = 1.0f;
    
    map.tri[map.tri.size()-2].drawtexture = 1;
    
    
    
    
}


void TriangleFunctionDraw( float * nullpoint, float backresize, float rightresize, float highresize, unsigned int texture )
{
    	glBindTexture( GL_TEXTURE_2D, map.texture[texture] );
    	
    	glColor3f( 1.0f, 1.0f, 1.0f );
    	
    	glBegin( GL_TRIANGLES );
    
        	glTexCoord2f( 0.0f, 0.0f );
        		glVertex3f( nullpoint[0], nullpoint[1], nullpoint[2] );
        
        	glTexCoord2f( 1.0f, 0.0f );
        		glVertex3f( nullpoint[0]+backresize, nullpoint[1]+highresize, nullpoint[2] );
        
        	glTexCoord2f( 1.0f, 1.0f );
        		glVertex3f( nullpoint[0], nullpoint[1]+highresize, nullpoint[2]+rightresize );
    
    	glEnd();
    	
    	
}







void Ramp1Function( float * nullpoint, float backresize, float rightresize, float highresize, unsigned int texture )
{
    map.tri.resize( map.tri.size() + 2 );
    map.tri[map.tri.size()-2].tri[0][0] = nullpoint[0];
    map.tri[map.tri.size()-2].tri[0][1] = nullpoint[1];
    map.tri[map.tri.size()-2].tri[0][2] = nullpoint[2];
    
    map.tri[map.tri.size()-2].tri[1][0] = nullpoint[0]+backresize;
    map.tri[map.tri.size()-2].tri[1][1] = nullpoint[1]+highresize;
    map.tri[map.tri.size()-2].tri[1][2] = nullpoint[2];
    
    map.tri[map.tri.size()-2].tri[2][0] = nullpoint[0]+backresize;
    map.tri[map.tri.size()-2].tri[2][1] = nullpoint[1]+highresize;
    map.tri[map.tri.size()-2].tri[2][2] = nullpoint[2]+rightresize;
    
    map.tri[map.tri.size()-2].texture = texture;
    
    map.tri[map.tri.size()-2].image[0][0] = 0.0f;
    map.tri[map.tri.size()-2].image[0][1] = 0.0f;
    map.tri[map.tri.size()-2].image[1][0] = 1.0f;
    map.tri[map.tri.size()-2].image[1][1] = 0.0f;
    map.tri[map.tri.size()-2].image[2][0] = 1.0f;
    map.tri[map.tri.size()-2].image[2][1] = 1.0f;
    
    map.tri[map.tri.size()-2].drawtexture = 1;
    
    
    
    
    
    map.tri[map.tri.size()-1].tri[0][0] = nullpoint[0];
    map.tri[map.tri.size()-1].tri[0][1] = nullpoint[1];
    map.tri[map.tri.size()-1].tri[0][2] = nullpoint[2];
    
    map.tri[map.tri.size()-1].tri[1][0] = nullpoint[0]+backresize;
    map.tri[map.tri.size()-1].tri[1][1] = nullpoint[1]+highresize;
    map.tri[map.tri.size()-1].tri[1][2] = nullpoint[2]+rightresize;
    
    map.tri[map.tri.size()-1].tri[2][0] = nullpoint[0];
    map.tri[map.tri.size()-1].tri[2][1] = nullpoint[1];
    map.tri[map.tri.size()-1].tri[2][2] = nullpoint[2]+rightresize;
    
    map.tri[map.tri.size()-1].texture = texture;
    
    map.tri[map.tri.size()-1].image[0][0] = 0.0f;
    map.tri[map.tri.size()-1].image[0][1] = 0.0f;
    map.tri[map.tri.size()-1].image[1][0] = 1.0f;
    map.tri[map.tri.size()-1].image[1][1] = 1.0f;
    map.tri[map.tri.size()-1].image[2][0] = 0.0f;
    map.tri[map.tri.size()-1].image[2][1] = 1.0f;
    
    map.tri[map.tri.size()-1].drawtexture = 1;
    
}


void Ramp1FunctionDraw( float * nullpoint, float backresize, float rightresize, float highresize, unsigned int texture )
{
    	glBindTexture( GL_TEXTURE_2D, map.texture[texture] );
    	
    	glColor3f( 1.0f, 1.0f, 1.0f );
    	
    	glBegin( GL_QUADS );
    
        	glTexCoord2f( 0.0f, 0.0f );
        		glVertex3f( nullpoint[0], nullpoint[1], nullpoint[2] );
        
        	glTexCoord2f( 1.0f, 0.0f );
        		glVertex3f( nullpoint[0]+backresize, nullpoint[1]+highresize, nullpoint[2] );
        
        	glTexCoord2f( 1.0f, 1.0f );
        		glVertex3f( nullpoint[0]+backresize, nullpoint[1]+highresize, nullpoint[2]+rightresize );
        		
        	glTexCoord2f( 0.0f, 1.0f );
        		glVertex3f( nullpoint[0], nullpoint[1], nullpoint[2]+rightresize );
    
    	glEnd();
    	
    	
}









void Ramp2Function( float * nullpoint, float backresize, float rightresize, float highresize, unsigned int texture )
{
    map.tri.resize( map.tri.size() + 2 );
    map.tri[map.tri.size()-2].tri[0][0] = nullpoint[0];
    map.tri[map.tri.size()-2].tri[0][1] = nullpoint[1];
    map.tri[map.tri.size()-2].tri[0][2] = nullpoint[2];
    
    map.tri[map.tri.size()-2].tri[1][0] = nullpoint[0];
    map.tri[map.tri.size()-2].tri[1][1] = nullpoint[1]+highresize;
    map.tri[map.tri.size()-2].tri[1][2] = nullpoint[2]+rightresize;
    
    map.tri[map.tri.size()-2].tri[2][0] = nullpoint[0]-backresize;
    map.tri[map.tri.size()-2].tri[2][1] = nullpoint[1]+highresize;
    map.tri[map.tri.size()-2].tri[2][2] = nullpoint[2]+rightresize;
    
    map.tri[map.tri.size()-2].texture = texture;
    
    map.tri[map.tri.size()-2].image[0][0] = 0.0f;
    map.tri[map.tri.size()-2].image[0][1] = 0.0f;
    map.tri[map.tri.size()-2].image[1][0] = 1.0f;
    map.tri[map.tri.size()-2].image[1][1] = 0.0f;
    map.tri[map.tri.size()-2].image[2][0] = 1.0f;
    map.tri[map.tri.size()-2].image[2][1] = 1.0f;
    
    map.tri[map.tri.size()-2].drawtexture = 1;
    
    
    
    
    
    map.tri[map.tri.size()-1].tri[0][0] = nullpoint[0];
    map.tri[map.tri.size()-1].tri[0][1] = nullpoint[1];
    map.tri[map.tri.size()-1].tri[0][2] = nullpoint[2];
    
    map.tri[map.tri.size()-1].tri[1][0] = nullpoint[0]-backresize;
    map.tri[map.tri.size()-1].tri[1][1] = nullpoint[1]+highresize;
    map.tri[map.tri.size()-1].tri[1][2] = nullpoint[2]+rightresize;
    
    map.tri[map.tri.size()-1].tri[2][0] = nullpoint[0]-backresize;
    map.tri[map.tri.size()-1].tri[2][1] = nullpoint[1];
    map.tri[map.tri.size()-1].tri[2][2] = nullpoint[2];
    
    map.tri[map.tri.size()-1].texture = texture;
    
    map.tri[map.tri.size()-1].image[0][0] = 0.0f;
    map.tri[map.tri.size()-1].image[0][1] = 0.0f;
    map.tri[map.tri.size()-1].image[1][0] = 1.0f;
    map.tri[map.tri.size()-1].image[1][1] = 1.0f;
    map.tri[map.tri.size()-1].image[2][0] = 0.0f;
    map.tri[map.tri.size()-1].image[2][1] = 1.0f;
    
    map.tri[map.tri.size()-1].drawtexture = 1;
    
}


void Ramp2FunctionDraw( float * nullpoint, float backresize, float rightresize, float highresize, unsigned int texture )
{
    	glBindTexture( GL_TEXTURE_2D, map.texture[texture] );
    	
    	glColor3f( 1.0f, 1.0f, 1.0f );
    	
    	glBegin( GL_QUADS );
    
        	glTexCoord2f( 0.0f, 0.0f );
        		glVertex3f( nullpoint[0], nullpoint[1], nullpoint[2] );
        
        	glTexCoord2f( 1.0f, 0.0f );
        		glVertex3f( nullpoint[0], nullpoint[1]+highresize, nullpoint[2]+rightresize );
        
        	glTexCoord2f( 1.0f, 1.0f );
        		glVertex3f( nullpoint[0]-backresize, nullpoint[1]+highresize, nullpoint[2]+rightresize );
        		
        	glTexCoord2f( 0.0f, 1.0f );
        		glVertex3f( nullpoint[0]-backresize, nullpoint[1], nullpoint[2] );
    
    	glEnd();
    	
    	
}








