


inline int Texture::LoadInit( char * name, int type )
{
	if( bitmapData != NULL )
	{
		delete[] bitmapData;
		bitmapData = NULL;
	}
	{	// if texture file exist
    	fstream file;
    	file.open( name, ios::in );
    	if( file.good() )
    	{
    	    cout<<endl<<"Dobry Mudin z Afrika";
		}
    	else
    	{
    	    cout<<endl<<"Dupsko Mudina";
    	    return TEXTURE_UNLOADED;
		}
    	file.close();
	}
	{
		glEnable( GL_TEXTURE_2D );
	
		bitmapData = LoadBitmapFileRGBA( name , &bitmapInfoHeader );        // ³aduje teksture do pamiêci

		glGenTextures( 1, &texture );
		glBindTexture( GL_TEXTURE_2D, texture );
		
		glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , type );	//GL_NEAREST
		glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , type );	//GL_NEAREST

		glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_REPEAT );
		glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_REPEAT );

		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, bitmapInfoHeader.biWidth,
					  bitmapInfoHeader.biHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, bitmapData );
	}
	return TEXTURE_LOADED;
}



inline int Texture::LoadInit( char * name )
{
	if( bitmapData != NULL )
	{
		delete[] bitmapData;
		bitmapData = NULL;
	}
	{	// if texture file exist
    	fstream file;
    	file.open( name, ios::in );
    	if( file.good() )
    	{
    	    cout<<endl<<"Dobry Mudin z Afrika";
		}
    	else
    	{
    	    cout<<endl<<"Dupsko Mudina";
    	    return TEXTURE_UNLOADED;
		}
    	file.close();
	}
	{
		glEnable( GL_TEXTURE_2D );
	
		bitmapData = LoadBitmapFileRGBA( name , &bitmapInfoHeader );        // ³aduje teksture do pamiêci

		glGenTextures( 1, &texture );
		glBindTexture( GL_TEXTURE_2D, texture );
		
		glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_LINEAR );	//GL_NEAREST
		glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_LINEAR );	//GL_NEAREST

		glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_REPEAT );
		glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_REPEAT );

		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, bitmapInfoHeader.biWidth,
					  bitmapInfoHeader.biHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, bitmapData );
	}
	return TEXTURE_LOADED;
}

inline unsigned int Texture::GetID()
{
	//if( texture != NULL )
		return texture;
	//else
	//	return 0;
}

inline void Texture::Bind()
{
	glBindTexture( GL_TEXTURE_2D, texture );
}

inline void Texture::Delete()
{
	glDeleteTextures( 1, &texture );
	texture = 0;
//	bitmapInfoHeader;
	if( bitmapData != NULL )
		delete[] bitmapData;
}


Texture::Texture()
{
	bitmapData = NULL;
}

Texture::~Texture()
{
	if( bitmapData != NULL )
	{
		delete[] bitmapData;
		bitmapData = NULL;
	}
}


