



inline int Texture::LoadInit( char * name )
{
	if( bitmapData != NULL )
	{
		delete[] bitmapData;
		bitmapData = NULL;
	}
	if( texture != NULL )
	{
		delete texture;
		texture = NULL;
	}
	{	// if texture file exist
    	fstream file;
    	file.open( name, ios::in );
    	if( file.good() )
    	    cout<<endl<<"Dobry Mudin z Afrika";
    	else
    	{
    	    cout<<endl<<"Dupsko Mudina";
    	    return TEXTURE_UNLOADED;
		}
    	file.close();
	}
	{
		texture = new unsigned int;
		
		glEnable( GL_TEXTURE_2D );
	
		bitmapData = LoadBitmapFileRGBA( name , &bitmapInfoHeader );        // ³aduje teksture do pamiêci

		glGenTextures( 1, texture );
		glBindTexture( GL_TEXTURE_2D, *texture );
		
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
	if( texture != NULL )
		return *texture;
	else
		return 0;
}

Texture::Texture()
{
	bitmapData = NULL;
	texture = NULL;
}

Texture::~Texture()
{
	if( bitmapData != NULL )
	{
		delete[] bitmapData;
		bitmapData = NULL;
	}
	if( texture != NULL )
	{
		delete texture;
		texture = NULL;
	}
}


