


int Texture::LoadInit( NameLine128 name )           // ³adowanie i inicjowanie textur opengl
{
    if( name.name[0] == ' ' )
        sprintf( texturefile.name, "%s", &name.name[1] );
    else
        sprintf( texturefile.name, "%s", &name.name[0] );
        
    cout<<endl<<texturefile.name;
    
    fstream file;
    file.open( texturefile.name, ios::in );
    if( file.good() )
        cout<<endl<<"Dobry Mudin z Afrika";
    else
        cout<<endl<<"Dupsko Mudina";
    file.close();
    
			bitmapData = LoadBitmapFileRGBA( texturefile.name , &bitmapInfoHeader );        // ³aduje teksture do pamiêci

			glGenTextures( 1, &texture );
			glBindTexture( GL_TEXTURE_2D, texture );
cout<<endl<<texture;
			glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_LINEAR );	//GL_NEAREST
			glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_LINEAR );	//GL_NEAREST

			glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_REPEAT );
			glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_REPEAT );

			glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, bitmapInfoHeader.biWidth,
						  bitmapInfoHeader.biHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, bitmapData );
	cout<<endl;
}










Texture::Texture()
{
    texturefile.name[0] = 0;
    bitmapInfoHeader;
    bitmapData = NULL;
    texture = 0;
}
