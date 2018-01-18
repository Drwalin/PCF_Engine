






void Map::Draw( int id_object )
{
    glPushMatrix();

	glLoadIdentity();
	glPushMatrix();

	glDepthFunc( GL_LEQUAL );



    if( FIRSTPEARSON == true )
    {
        glTranslatef( 0.0f, 0.0f, -3.0f );
        glRotatef( -object[id_object].looky, 1.0f, 0.0f, 0.0f );
        glTranslatef( 0.0f, -1.62f, 0.0f );
        glRotatef( 180.0f, 0.0f, 1.0f, 0.0f );
        //humanoid[0].Draw( 2.0f * object[id_object].radian, abs(sqrt( object[id_object].speed[0]*object[id_object].speed[0] + object[id_object].speed[2]*object[id_object].speed[2] )) );
        
        
        
        glLoadIdentity();
        
        glTranslatef( 0.0f, 0.0f, -3.0f );      //trzecio-osobowy widok
    }
	glRotatef( -object[id_object].looky, 1.0f, 0.0f, 0.0f );
	glRotatef( -(object[id_object].lookxz-90.0f), 0.0f, 1.0f, 0.0f );
	glTranslatef( -object[id_object].pos[0], -(object[id_object].GetMaxY() - 0.1f), -object[id_object].pos[2] );



    DrawTriangles();



    /*
        for( unsigned int numb = 0; numb < object.size(); numb++ )
        {
            if( numb != draw_object_id && numb != 0 )
            {
                glLoadIdentity();
                //if( FIRSTPEARSON == true )
                //    glTranslatef( 0.0f, 0.0f, -3.0f );
            	glRotatef( -object[id_object].looky, 1.0f, 0.0f, 0.0f );
            	glRotatef( -(object[id_object].lookxz-90.0f), 0.0f, 1.0f, 0.0f );
            	glTranslatef( -(object[id_object].pos[0]-object[numb].pos[0]), -(object[id_object].pos[1]-object[numb].pos[1]+object[numb].radian+(object[id_object].radian*0.7f)), -(object[id_object].pos[2]-object[numb].pos[2]) );
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
    */


}










