void ScreenWrite( char * word );
void ScreenGoTo( unsigned int x, unsigned int y );
void ScreenClear();
void ScreenDraw();
void ScreenLetterDraw( unsigned int x, unsigned int y, char symbol );
void ScreenLoadTextures();

char buffor[80][45];
unsigned int index[2];
//unsigned int index;


//#define "SYMBOL "Media\Fonts\Classic


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
/*					glBindTexture( GL_TEXTURE_2D, Screentexture[buffor[x][y]-32] );
					
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
	char symbolname[][64] = {   "Media\\Fonts\\Classic\\SYMBOL00.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL01.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL02.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL03.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL04.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL05.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL06.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL07.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL08.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL09.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL0A.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL0B.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL0C.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL0D.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL0E.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL0F.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL10.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL11.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL12.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL13.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL14.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL15.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL16.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL17.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL18.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL19.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL1A.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL1B.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL1C.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL1D.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL1E.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL1F.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL20.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL21.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL22.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL23.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL24.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL25.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL26.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL27.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL28.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL29.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL2A.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL2B.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL2C.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL2D.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL2E.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL2F.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL30.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL31.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL32.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL33.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL34.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL35.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL36.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL37.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL38.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL39.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL3A.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL3B.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL3C.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL3D.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL3E.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL3F.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL40.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL41.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL42.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL43.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL44.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL45.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL46.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL47.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL48.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL49.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL4A.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL4B.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL4C.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL4D.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL4E.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL4F.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL50.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL51.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL52.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL53.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL54.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL55.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL56.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL57.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL58.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL59.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL5A.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL5B.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL5C.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL5D.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL5E.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL5F.bmpx",
								"Media\\Fonts\\Classic\\SYMBOL60.bmpx"
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























