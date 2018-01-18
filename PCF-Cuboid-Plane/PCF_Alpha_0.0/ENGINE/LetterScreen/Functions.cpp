void ScreenWrite( char * word );
void ScreenGoTo( unsigned int x, unsigned int y );
void ScreenClear();
void ScreenDraw();
void ScreenLetterDraw( unsigned int x, unsigned int y, char symbol );
void ScreenLoadTextures();

char buffor[80][45];
unsigned int index[2];
//unsigned int index;


//#define "SYMBOL "Data\Fonts\Classic


//char texturefiles[96][16];
BITMAPINFOHEADER ScreenbitmapInfoHeader[96];
unsigned char * ScreenbitmapData[96];
unsigned int Screentexture[96];


void ScreenWrite( char * word )
{
    for( unsigned int id = 0; ( word[id] < 127 ) && ( word[id] > 31 ); id++ )
    {
        buffor[index[0]][index[1]] = word[id];
        index[0]++;
        if( index[0] >= 80 )
        {
            index[0] = 0;
            index[1]--;
            if( index[1] >= 45 )
            {
                index[1] = 0;
            }
        }
    }
}

void ScreenGoTo( unsigned int x, unsigned int y )
{
    index[0] = x % 80;
    index[1] = 44 - ( y % 45 );
}

void ScreenClear()
{
    for( unsigned int x = 0; x < 80; x++ )
    {
        for( unsigned int y = 0; y < 45; y++ )
        {
            buffor[x][y] = ' ';
        }
    }
}

void ScreenDraw()
{
    for( unsigned int x = 0; x < 80; x++ )
    {
        for( unsigned int y = 0; y < 45; y++ )
        {
            if( ( buffor[x][y] > 31 ) && ( buffor[x][y] < 127 ) && buffor[x][y] != ' ')
            {
             ScreenLetterDraw( x, y, buffor[x][y] );
/*                	glBindTexture( GL_TEXTURE_2D, Screentexture[buffor[x][y]-32] );
                	
                	glColor3f( 1.0f, 1.0f, 1.0f );
                	
                	glBegin( GL_QUADS );
                
                    	glTexCoord2f( 0.0f, 0.0f );
                    		glVertex3f( float(x)-40.0f, float(y)-22.5f, 40.0f );
                            
                    	glTexCoord2f( 0.0f, 1.0f );
                    		glVertex3f( float(x)-40.0f, float(y)-21.5f, 40.0f );
                        
                    	glTexCoord2f( 1.0f, 1.0f  );
                    		glVertex3f( float(x)-40.0f, float(y)-21.5f, 40.0f );
                        
                    	glTexCoord2f( 1.0f, 0.0f );
                    		glVertex3f( float(x)-39.0f, float(y)-22.5f, 40.0f );
                		
                    glEnd();*/
            }
            else
            {
                continue;
            }
        }
    }
}







void ScreenLetterDraw( unsigned int x, unsigned int y, char symbol )
{
	glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
	glBindTexture( GL_TEXTURE_2D, Screentexture[symbol-32] );
	
	glColor3f( 1.0f, 1.0f, 1.0f );
	
	glBegin( GL_QUADS );

    	glTexCoord2f( 0.0f, 0.0f );
    		glVertex3f( float(x)-40.0f, float(y)-22.5f, -40.0f );
            
    	glTexCoord2f( 0.0f, 1.0f );
    		glVertex3f( float(x)-40.0f, float(y)-21.5f, -40.0f );
        
    	glTexCoord2f( 1.0f, 1.0f  );
    		glVertex3f( float(x)-39.0f, float(y)-21.5f, -40.0f );
        
    	glTexCoord2f( 1.0f, 0.0f );
    		glVertex3f( float(x)-39.0f, float(y)-22.5f, -40.0f );
		
    glEnd();
}






void ScreenLoadTextures()
{
    index[0] = 1;
    index[1] = 1;
    char symbolname[][64] = {   "Data\\Fonts\\Classic\\SYMBOL00.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL01.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL02.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL03.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL04.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL05.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL06.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL07.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL08.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL09.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL0A.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL0B.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL0C.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL0D.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL0E.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL0F.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL10.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL11.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL12.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL13.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL14.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL15.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL16.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL17.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL18.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL19.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL1A.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL1B.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL1C.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL1D.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL1E.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL1F.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL20.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL21.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL22.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL23.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL24.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL25.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL26.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL27.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL28.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL29.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL2A.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL2B.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL2C.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL2D.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL2E.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL2F.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL30.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL31.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL32.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL33.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL34.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL35.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL36.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL37.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL38.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL39.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL3A.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL3B.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL3C.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL3D.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL3E.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL3F.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL40.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL41.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL42.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL43.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL44.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL45.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL46.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL47.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL48.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL49.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL4A.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL4B.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL4C.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL4D.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL4E.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL4F.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL50.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL51.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL52.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL53.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL54.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL55.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL56.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL57.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL58.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL59.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL5A.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL5B.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL5C.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL5D.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL5E.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL5F.bmpx",
                                "Data\\Fonts\\Classic\\SYMBOL60.bmpx"
                                };
                            
	for( unsigned int number = 0; number < 96; number++ )
	{
		ScreenbitmapData[ number ] = LoadBitmapFileRGBA( symbolname[ number ] , &ScreenbitmapInfoHeader[ number ] );

		glGenTextures( 1, &Screentexture[ number ] );
		glBindTexture( GL_TEXTURE_2D, Screentexture[ number ] );

		glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_LINEAR );	//GL_LINEAR
		glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_LINEAR );	//GL_LINEAR

		glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_REPEAT );
		glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_REPEAT );

		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, ScreenbitmapInfoHeader[ number ].biWidth,
		ScreenbitmapInfoHeader[ number ].biHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, ScreenbitmapData[ number ]);
	}
}























