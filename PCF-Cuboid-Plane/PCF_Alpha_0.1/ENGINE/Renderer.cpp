//float timefps[3];


void Renderer()
{
    if( timefps[0] != clock() )
    {
        timefps[1] = 1.0f/(float(abs( timefps[0] - clock() ))/1000.0f);
    }
    timefps[0] = clock();
    
    glEnable( GL_BLEND );
    
    glClearColor( 0.5f, 0.6f, 1.0f, 1.0f );

	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
		
    glColorMask( GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE );
	glMatrixMode( GL_MODELVIEW ); 
	glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	glColor3f( 1.0f, 1.0f, 1.0f );
	
	
    map.Draw( 1 );//PLAYE_R_ID );
    
    
    GameRendererFunction();
    
    
    
    
    
    
    
    
    
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}





