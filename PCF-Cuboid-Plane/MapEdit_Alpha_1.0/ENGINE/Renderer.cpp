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
	
	
    RenderMap();
    GameRendererFunction();
    
    
    
/*    
    
	glDepthFunc( GL_ALWAYS );
    
    glLoadIdentity();
    glTranslatef( sin( (float(clock())/1.0f) *const_PI/180 ), 0.0f, 0.0f );
        	glColor3f( 1.0f, 1.0f, 1.0f );
        	glBegin( GL_LINES );
        	
        	
        	   glVertex3f( 0.0f, 2.0f, -2.0f );
        	   glVertex3f( 0.0f, -1.0f, -2.0f );
            glEnd();
*/    
    
    
//    humanoid[0].Draw();
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}








void RenderMap()
{

    glPushMatrix();

	glLoadIdentity();
	glPushMatrix();

	glDepthFunc( GL_LEQUAL );

//	glEnable (GL_BLEND);
//    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);



//    glTranslatef( 0.0f, 0.0f, -2.0f );
//	glRotatef( -object[draw_object_id].looky, 1.0f, 0.0f, 0.0f );
//    glRotatef( 180.0f, 0.0f, 1.0f, 0.0f );
//	glRotatef( object[draw_object_id].looky, 1.0f, 0.0f, 0.0f );


    if( FIRSTPEARSON == true )
    {
        glTranslatef( 0.0f, 0.0f, -3.0f );
        glRotatef( -object[draw_object_id].looky, 1.0f, 0.0f, 0.0f );
        glTranslatef( 0.0f, -1.62f, 0.0f );
        glRotatef( 180.0f, 0.0f, 1.0f, 0.0f );
        humanoid[0].Draw( 2.0f * object[draw_object_id].radian, abs(sqrt( object[draw_object_id].speed[0]*object[draw_object_id].speed[0] + object[draw_object_id].speed[2]*object[draw_object_id].speed[2] )) );
        
        
        
        glLoadIdentity();
        
        glTranslatef( 0.0f, 0.0f, -3.0f );      //trzecio-osobowy widok
    }
	glRotatef( -object[draw_object_id].looky, 1.0f, 0.0f, 0.0f );
	glRotatef( -(object[draw_object_id].lookxz-90.0f), 0.0f, 1.0f, 0.0f );
	glTranslatef( -object[draw_object_id].pos[0], -(object[draw_object_id].pos[1]), -object[draw_object_id].pos[2] );


//    cout<<endl<<clock();




    glDisable( GL_BLEND );
    glLineWidth(5.0);
    glBegin( GL_LINES );
        glColor3ub( 255, 0, 0 );
            glVertex3f( 0.0f, 0.0f, 0.0f );
            glVertex3f( 10000.0f, 0.0f, 0.0f );
        glColor3ub( 0, 255, 0 );
            glVertex3f( 0.0f, 0.0f, 0.0f );
            glVertex3f( 0.0f, 10000.0f, 0.0f );
        glColor3ub( 0, 0, 255 );
            glVertex3f( 0.0f, 0.0f, 0.0f );
            glVertex3f( 0.0f, 0.0f, 10000.0f );
    glEnd();
    glEnable( GL_BLEND );

    map.DrawMap();


if(GetAsyncKeyState(0x02) & 0x8000)
{

    
    float point2[3] = { Xpoint( object[draw_object_id].lookxz ), Ypoint( object[draw_object_id].looky ), Zpoint( object[draw_object_id].lookxz ) };
    
    float rad_ian = sqrt( point2[0]*point2[0]+point2[1]*point2[1]+point2[2]*point2[2] );
        
    point2[0] = ( wallradianplayer * point2[0] / rad_ian );
    point2[1] = ( wallradianplayer * point2[1] / rad_ian );
    point2[2] = ( wallradianplayer * point2[2] / rad_ian );
    
    point2[0] += object[draw_object_id].pos[0];
    point2[1] += object[draw_object_id].pos[1];
    point2[2] += object[draw_object_id].pos[2];
    
    switch( objectsettype )
    {
        case 0:
            walldraw[wallprinter]( point2, resize[0], resize[1], resize[2], texture );
            break;
        case 1:
            glLoadIdentity();
            glTranslatef( 0.0f, 0.0f, -wallradianplayer );
            humanoid[ 0 ].Draw( 1.7f, 0.0f );
            break;
    }
}














        for( unsigned int numb = 0; numb < object.size(); numb++ )
        {
            if( numb != draw_object_id && numb != 0 )
            {
                glLoadIdentity();
                if( FIRSTPEARSON == true )
                    glTranslatef( 0.0f, 0.0f, -3.0f );
            	glRotatef( -object[draw_object_id].looky, 1.0f, 0.0f, 0.0f );
            	glRotatef( -(object[draw_object_id].lookxz-90.0f), 0.0f, 1.0f, 0.0f );
            	glTranslatef( -(object[draw_object_id].pos[0]-object[numb].pos[0]), -(object[draw_object_id].pos[1]-object[numb].pos[1]+object[numb].radian), -(object[draw_object_id].pos[2]-object[numb].pos[2]) );
                glRotatef( 180.0f+object[numb].lookxz, 0.0f, 1.0f, 0.0f );
                

                
                if( object[numb].modeltype == HUMANMODEL )
                {
                    humanoid[ object[numb].model ].Draw( 2.0f * object[numb].radian, abs(sqrt( object[numb].speed[0]*object[numb].speed[0] + object[numb].speed[2]*object[numb].speed[2] )) );
                }
                else if( object[numb].modeltype == CUBEMODEL )
                {
                    cubes[ object[numb].model ].Draw( object[numb].radian, object[numb].model );
                }
            }
        } 





}




