

void EngineCubeGraphicModel::Load( char * modelname )
{
    char argument = 0;
    fstream file;
    file.open( modelname, ios::in );
    while( 1 )
    {
        file >> argument;
        switch( argument )
        {
        case 'f':
            texturefiles.resize( texturefiles.size() + 1 );
            bitmapInfoHeader.resize( bitmapInfoHeader.size() + 1 );
            bitmapData.resize( bitmapData.size() + 1 );
            textures.resize( textures.size() + 1 );
            file.getline( texturefiles[ texturefiles.size()-1 ].name, 64 );
            cout<<endl<<"loading data and prepare values";
            break;
            
        default:
            //goto endloop;
            return;
        }
    }
    
//    endloop:
    
    /*
    for( unsigned int number = 0; number < 19; number ++ )
    {
	   bitmapData[ number ] = LoadBitmapFileRGBA( texturefiles[ number ].name , &bitmapInfoHeader[ number ] );
    }
    */
}

void EngineCubeGraphicModel::Init()
{
	for( unsigned int number = 0; number < texturefiles.size(); number++ )
	{
        cout<<endl<<"loading textures and prepare textures";
        cout<<"     "<<texturefiles[ number ].name;
	    bitmapData[ number ] = LoadBitmapFileRGBA( texturefiles[ number ].name , &bitmapInfoHeader[ number ] );

        fstream fileopen;
        fileopen.open( texturefiles[ number ].name, ios::in );
        if( fileopen.good() )
        {
            cout<<" - gitara";
            fileopen.close();
        }


		glGenTextures( 1, &textures[ number ] );
		glBindTexture( GL_TEXTURE_2D, textures[ number ] );

		glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_LINEAR );	//GL_NEAREST
		glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_LINEAR );	//GL_NEAREST

		glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_REPEAT );
		glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_REPEAT );

		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, bitmapInfoHeader[ number ].biWidth,
					 bitmapInfoHeader[ number ].biHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, bitmapData[ number ] );
    }
}


void EngineCubeGraphicModel::Draw( float height, unsigned int id )
{
    glScalef( height * 2.0f, height * 2.0f, height * 2.0f );


    float vertices[2][4][3] =   {{
                                { -0.5f, 0.0f, -0.5f },
                                { 0.5f,  0.0f, -0.5f },
                                { 0.5f,  0.0f, 0.5f  },
                                { -0.5f, 0.0f, 0.5f  }
                                },{
                                { -0.5f, 1.0f,  -0.5f },
                                { 0.5f,  1.0f,  -0.5f },
                                { 0.5f,  1.0f,  0.5f  },
                                { -0.5f, 1.0f,  0.5f  },
                                }};


    glBegin( GL_QUADS );
    
        glBindTexture( GL_TEXTURE_2D, cubes[id].textures[0] );

        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( vertices[0][0] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( vertices[0][1] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( vertices[0][2] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( vertices[0][3] );

//        glBindTexture( GL_TEXTURE_2D, cubes[id].textures[1] );
        
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( vertices[1][0] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( vertices[1][1] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( vertices[1][2] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( vertices[1][3] );

//        glBindTexture( GL_TEXTURE_2D, cubes[id].textures[2] );
        
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( vertices[1][0] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( vertices[1][1] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( vertices[0][1] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( vertices[0][0] );

//        glBindTexture( GL_TEXTURE_2D, cubes[id].textures[3] );
        
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( vertices[1][1] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( vertices[1][2] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( vertices[0][2] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( vertices[0][1] );

//        glBindTexture( GL_TEXTURE_2D, cubes[id].textures[4] );
        
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( vertices[1][2] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( vertices[1][3] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( vertices[0][3] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( vertices[0][2] );

//        glBindTexture( GL_TEXTURE_2D, cubes[id].textures[5] );
        
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( vertices[1][3] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( vertices[1][0] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( vertices[0][0] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( vertices[0][3] );



    glEnd();
}

















