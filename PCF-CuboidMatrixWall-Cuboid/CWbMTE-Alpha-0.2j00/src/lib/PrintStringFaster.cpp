


inline void drawString( const char *str, int x, int y, float color[4] )
{
	void * font = GLUT_BITMAP_8_BY_13;
	
    glPushAttrib( GL_LIGHTING_BIT | GL_CURRENT_BIT ); // lighting and color mask
    glDisable( GL_LIGHTING );     // need to disable lighting for proper text color
    glDisable( GL_TEXTURE_2D );

    glColor4fv(color);          // set text color
    glRasterPos2i(x, y);        // place text position

    // loop all characters in the string
    while( *str )
    {
        glutBitmapCharacter( font, *str );
        ++str;
    }

    glEnable( GL_TEXTURE_2D );
    glPopAttrib();
}


