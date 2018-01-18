
//piszczel = 0.45f
//biodro = 0.35f
//klatka = 0.52f
//ramie = 0.3f
//przedramie = 0.43f
//szyja = 0.13f
//twarz = 0.2f

//#define float(clock()) (movespeed*(float)clock()/1000.0f)




void EngineHumanoidGraphicModel::Load( char * modelname )
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

void EngineHumanoidGraphicModel::Init()
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
























void EngineHumanoidGraphicModel::Draw( float height, float movespeed )
{
    if( int(float(movespeed*5.0f)) != 0 )
        DrawMove( height, movespeed );
    else
        DrawState( height );
    
}

void EngineHumanoidGraphicModel::DrawMove( float height, float movespeed )
{
    glScalef( height / 1.62f, height / 1.62f, height / 1.62f );
    
    
    
    float statetri[8][3] = {
        { -0.06f, 1.32f, 0.06f  },
        { 0.06f,  1.32f, 0.06f  },
        { 0.06f,  1.32f, -0.06f },
        { -0.06f, 1.32f, -0.06f },
        
        { -0.06f, 1.5f, 0.1f    },
        { 0.06f,  1.5f, 0.1f    },
        { 0.06f,  1.5f, -0.02f  },
        { -0.06f, 1.5f, -0.02f  },
        };
        
    float statehead[10][3] = {
        { -0.04f, 1.42f, 0.14f  },
        { 0.04f,  1.42f, 0.14f  },
        { -0.1f,  1.62f, 0.1f   },
        { 0.1f,   1.62f, 0.1f   },
        { -0.04f, 1.62f, -0.04f },
        { 0.04f,  1.62f, -0.04f },
        { -0.1f,  1.5f,  -0.04f },
        { 0.1f,   1.5f,  -0.04f },
        { -0.1f,  1.42f, 0.07f  },
        { 0.1f,   1.42f, 0.07f  },
        };
    
    
    float consthands[8][3] = {
        { -0.3f, 1.32f, 0.10f  },
        { -0.2f, 1.17f, 0.14f  },
        { 0.2f,  1.17f, 0.14f  },
        { 0.3f,  1.32f, 0.10f  },
        { 0.3f,  1.32f, -0.10f },
        { 0.2f,  1.17f, -0.10f },
        { -0.2f, 1.17f, -0.10f },
        { -0.3f, 1.32f, -0.10f },
    };
    
    float lhandtri[5][3] = {
        { -0.35f, 0.59f + sin( (((((float)clock())*movespeed)/300.0f+180.0f) *const_PI/180) ) / 16.0f + 0.0625f,       0.0f + sin( (((((float)clock())/movespeed)/300.0f+180.0f) *const_PI/180) ) / 5.0f + 0.2f   },
        { -0.35f, 1.02f, 0.07f + sin( (((((float)clock())*movespeed)/300.0f+180.0f) *const_PI/180) ) / 12.0f},// + 0.083f  },
        { -0.25f, 1.02f, 0.07f + sin( (((((float)clock())*movespeed)/300.0f+180.0f) *const_PI/180) ) / 12.0f},// + 0.083f  },
        { -0.25f, 0.92f, -0.07f + sin( (((((float)clock())*movespeed)/300.0f+180.0f) *const_PI/180) ) / 12.0f},// + 0.083f },
        { -0.35f, 0.92f, -0.07f + sin( (((((float)clock())*movespeed)/300.0f+180.0f) *const_PI/180) ) / 12.0f},// + 0.083f }
        };
    float rhandtri[5][3] = {
        { 0.35f, 0.59f + sin( ((((float)clock())*movespeed)/300.0f) *const_PI/180 ) / 16.0f + 0.0625f,        0.0f + sin( ((((float)clock())*movespeed)/300.0f) *const_PI/180 ) / 5.0f + 0.2f   },
        { 0.35f, 1.02f, 0.07f + sin( ((((float)clock())*movespeed)/300.0f) *const_PI/180 ) / 12.0f},// + 0.083f  },
        { 0.25f, 1.02f, 0.07f + sin( ((((float)clock())*movespeed)/300.0f) *const_PI/180 ) / 12.0f},// + 0.083f  },
        { 0.25f, 0.92f, -0.07f + sin( ((((float)clock())*movespeed)/300.0f) *const_PI/180 ) / 12.0f},// + 0.083f },
        { 0.35f, 0.92f, -0.07f + sin( ((((float)clock())*movespeed)/300.0f) *const_PI/180 ) / 12.0f},// + 0.083f }
        };
    
/*****
    float lhandtri[5][3] = {
        { -0.35f, 0.59f + sin( (((((float)clock())*movespeed)/300.0f+180.0f) *const_PI/180) ) / 16.0f + 0.0625f,       0.0f + sin( (((((float)clock())*movespeed)/300.0f+180.0f) *const_PI/180) ) / 5.0f + 0.2f   },
        { -0.35f, 1.02f, 0.07f + sin( (((((float)clock())*movespeed)/300.0f+180.0f) *const_PI/180) ) / 12.0f},// + 0.083f  },
        { -0.25f, 1.02f, 0.07f + sin( (((((float)clock())*movespeed)/300.0f+180.0f) *const_PI/180) ) / 12.0f},// + 0.083f  },
        { -0.25f, 0.92f, -0.07f + sin( (((((float)clock())*movespeed)/300.0f+180.0f) *const_PI/180) ) / 12.0f},// + 0.083f },
        { -0.35f, 0.92f, -0.07f + sin( (((((float)clock())*movespeed)/300.0f+180.0f) *const_PI/180) ) / 12.0f},// + 0.083f }
        };
    float rhandtri[5][3] = {
        { 0.35f, 0.59f + sin( ((((float)clock())*movespeed)/300.0f) *const_PI/180 ) / 16.0f + 0.0625f,        0.0f + sin( ((((float)clock())*movespeed)/300.0f) *const_PI/180 ) / 5.0f + 0.2f   },
        { 0.35f, 1.02f, 0.07f + sin( ((((float)clock())*movespeed)/300.0f) *const_PI/180 ) / 12.0f},// + 0.083f  },
        { 0.25f, 1.02f, 0.07f + sin( ((((float)clock())*movespeed)/300.0f) *const_PI/180 ) / 12.0f},// + 0.083f  },
        { 0.25f, 0.92f, -0.07f + sin( ((((float)clock())*movespeed)/300.0f) *const_PI/180 ) / 12.0f},// + 0.083f },
        { 0.35f, 0.92f, -0.07f + sin( ((((float)clock())*movespeed)/300.0f) *const_PI/180 ) / 12.0f},// + 0.083f }
        };
*****/       
/*****
    float lhandtri[5][3] = {
        { -0.35f, 0.59f, 0.0f   },
        { -0.35f, 1.02f, 0.07f  },
        { -0.25f, 1.02f, 0.07f  },
        { -0.25f, 0.92f, -0.07f },
        { -0.35f, 0.92f, -0.07f }
        };
    float rhandtri[5][3] = {
        { 0.35f, 0.59f, 0.0f   },
        { 0.35f, 1.02f, 0.07f  },
        { 0.25f, 1.02f, 0.07f  },
        { 0.25f, 0.92f, -0.07f },
        { 0.35f, 0.92f, -0.07f }
        };
*****/
        
        
    float constlegs[6][3] = {
        { -0.2f, 0.8f, 0.07  },
        { 0.0f,  0.8f, 0.07  },
        { 0.2f,  0.8f, 0.07  },
        { 0.2f,  0.8f, -0.07 },
        { 0.0f,  0.8f, -0.07 },
        { -0.2f, 0.8f, -0.07 }
        };
        
    float llegtri[5][3] = {
        { -0.15f, 0.0f,  0.0f + sin( ((((float)clock())*movespeed)/300.0f) *const_PI/180 ) / 10.0f   },
        { -0.09f, 0.45f, 0.07f + sin( ((((float)clock())*movespeed)/300.0f) *const_PI/180 ) / 10.0f + 0.1f  },
        { -0.2f,  0.45f, 0.07f + sin( ((((float)clock())*movespeed)/300.0f) *const_PI/180 ) / 10.0f + 0.1f  },
        { -0.2f,  0.45f, -0.07f + sin( ((((float)clock())*movespeed)/300.0f) *const_PI/180 ) / 10.0f + 0.1f },
        { -0.09f, 0.45f, -0.07f + sin( ((((float)clock())*movespeed)/300.0f) *const_PI/180 ) / 10.0f + 0.1f }
        };
    float rlegtri[5][3] = {
        { 0.15f, 0.0f,  0.0f + sin( (((((float)clock())*movespeed)/300.0f+180.0f) *const_PI/180) ) / 10.0f   },
        { 0.09f, 0.45f, 0.07f + sin( (((((float)clock())*movespeed)/300.0f+180.0f) *const_PI/180) ) / 10.0f + 0.1f  },
        { 0.2f,  0.45f, 0.07f + sin( (((((float)clock())*movespeed)/300.0f+180.0f) *const_PI/180) ) / 10.0f + 0.1f  },
        { 0.2f,  0.45f, -0.07f + sin( (((((float)clock())*movespeed)/300.0f+180.0f) *const_PI/180) ) / 10.0f + 0.1f },
        { 0.09f, 0.45f, -0.07f + sin( (((((float)clock())*movespeed)/300.0f+180.0f) *const_PI/180) ) / 10.0f + 0.1f }
        };
    
         
    	glBindTexture( GL_TEXTURE_2D, textures[0] );
    	
    	glColor3f( 1.0f, 1.0f, 1.0f );
    	glColor3ub( 255, 255, 255 );
    	
    	glBegin( GL_TRIANGLES );
                    //prawy piszczel:
        	glTexCoord2f( 1.0f, 1.0f );
        		glVertex3fv( rlegtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
        		glVertex3fv( rlegtri[1] );
        	glTexCoord2f( 0.0f, 0.0f );
        		glVertex3fv( rlegtri[2] );
        		
        	glTexCoord2f( 1.0f, 1.0f );
        		glVertex3fv( rlegtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
        		glVertex3fv( rlegtri[2] );
        	glTexCoord2f( 0.0f, 0.0f );
        		glVertex3fv( rlegtri[3] );
        		
        	glTexCoord2f( 1.0f, 1.0f );
        		glVertex3fv( rlegtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
        		glVertex3fv( rlegtri[4] );
        	glTexCoord2f( 0.0f, 0.0f );
        		glVertex3fv( rlegtri[3] );
        		
        	glTexCoord2f( 1.0f, 1.0f );
        		glVertex3fv( rlegtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
        		glVertex3fv( rlegtri[1] );
        	glTexCoord2f( 0.0f, 0.0f );
        		glVertex3fv( rlegtri[4] );
        		
        		
                    //lewy piszczel:
        	glTexCoord2f( 1.0f, 1.0f );
        		glVertex3fv( llegtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
        		glVertex3fv( llegtri[1] );
        	glTexCoord2f( 0.0f, 0.0f );
        		glVertex3fv( llegtri[2] );
        		
        	glTexCoord2f( 1.0f, 1.0f );
        		glVertex3fv( llegtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
        		glVertex3fv( llegtri[2] );
        	glTexCoord2f( 0.0f, 0.0f );
        		glVertex3fv( llegtri[3] );
        		
        	glTexCoord2f( 1.0f, 1.0f );
        		glVertex3fv( llegtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
        		glVertex3fv( llegtri[4] );
        	glTexCoord2f( 0.0f, 0.0f );
        		glVertex3fv( llegtri[3] );
        		
        	glTexCoord2f( 1.0f, 1.0f );
        		glVertex3fv( llegtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
        		glVertex3fv( llegtri[1] );
        	glTexCoord2f( 0.0f, 0.0f );
        		glVertex3fv( llegtri[4] );
    glEnd();      
       
       
    	glBindTexture( GL_TEXTURE_2D, textures[1] );
       
    glBegin( GL_QUADS );
                    //prawe udo:
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( rlegtri[1]   );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( rlegtri[2]   );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( constlegs[2] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( constlegs[1] );
                
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( rlegtri[2]   );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( rlegtri[3]   );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( constlegs[3] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( constlegs[2] );
    
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( rlegtri[4]   );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( rlegtri[3]   );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( constlegs[3] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( constlegs[4] );
                
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( rlegtri[1]   );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( rlegtri[4]   );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( constlegs[4] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( constlegs[1] );
    
    
                    //lewe udo:
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( llegtri[1]   );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( llegtri[2]   );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( constlegs[0] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( constlegs[1] );
                
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( llegtri[2]   );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( llegtri[3]   );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( constlegs[5] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( constlegs[0] );
    
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( llegtri[4]   );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( llegtri[3]   );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( constlegs[5] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( constlegs[4] );
                
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( llegtri[1]   );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( llegtri[4]   );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( constlegs[4] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( constlegs[1] );
    
    
    glEnd();
    
    
    	glBindTexture( GL_TEXTURE_2D, textures[2] );
    
    glBegin( GL_TRIANGLES );
    
                    //lewe przedramie:
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( lhandtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( lhandtri[1] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( lhandtri[2] );
    
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( lhandtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( lhandtri[2] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( lhandtri[3] );
    
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( lhandtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( lhandtri[3] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( lhandtri[4] );
    
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( lhandtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( lhandtri[1] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( lhandtri[4] );
    
                    //prawe przedramie:
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( rhandtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( rhandtri[1] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( rhandtri[2] );
    
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( rhandtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( rhandtri[2] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( rhandtri[3] );
    
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( rhandtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( rhandtri[3] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( rhandtri[4] );
    
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( rhandtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( rhandtri[1] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( rhandtri[4] );
    
    glEnd();
    
    
    	glBindTexture( GL_TEXTURE_2D, textures[3] );
    
    glBegin( GL_QUADS );
    
                    //lewe ramie:
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( lhandtri[1] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( lhandtri[2] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[1] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[0] );
                
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( lhandtri[2] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( lhandtri[3] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[6] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[1] );
        
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( lhandtri[4] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( lhandtri[3] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[6] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[7] );
                
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( lhandtri[1] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( lhandtri[4] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[7] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[0] );
        
        
    
                    //prawe ramie:
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( rhandtri[1] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( rhandtri[2] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[2] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[3] );
                
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( rhandtri[2] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( rhandtri[3] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[5] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[2] );
                
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( rhandtri[4] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( rhandtri[3] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[5] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[4] );
                
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( rhandtri[1] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( rhandtri[4] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[4] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[3] );
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[4] );
                
                	//tulow
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( constlegs[0] );		//przod
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( constlegs[2] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( consthands[2] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[1] );
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[5] );
                
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( constlegs[5] );		//tyl
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( constlegs[3] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( consthands[5] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[6] );
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[6] );
                
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( constlegs[2] );		//prawo
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( constlegs[3] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[5] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[2] );
                
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( constlegs[0] );		//lewo
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( constlegs[5] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[6] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[1] );
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[7] );
                
                	//ramiona:
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[1] );		//przod
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( consthands[2] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( consthands[3] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[0] );
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[8] );
                
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[6] );		//tyl
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( consthands[5] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( consthands[4] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[7] );
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[9] );
                
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[0] );		//gora
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( consthands[3] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( consthands[4] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[7] );
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[10] );
                
                	//szyja:
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statetri[0] );		//przod
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( statetri[1] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( statetri[5] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statetri[4] );
                
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statetri[1] );		//prawy
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( statetri[2] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( statetri[6] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statetri[5] );
                
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statetri[3] );		//tyl
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( statetri[2] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( statetri[6] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statetri[7] );
                	
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statetri[0] );		//lewy
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( statetri[3] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( statetri[7] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statetri[4] );
    

    	glBindTexture( GL_TEXTURE_2D, textures[11] );

                    //glowa:
        	glTexCoord2f( 0.0f, 0.0f );        //twarz
                glVertex3fv( statehead[0] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( statehead[1] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statehead[3] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statehead[2] );
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[12] );

        	glTexCoord2f( 0.0f, 0.0f );        //'top' glowy
                glVertex3fv( statehead[2] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( statehead[3] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statehead[5] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statehead[4] );
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[13] );

        	glTexCoord2f( 0.0f, 0.0f );        //tyl glowy
                glVertex3fv( statehead[6] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( statehead[7] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statehead[5] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statehead[4] );
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[14] );

        	glTexCoord2f( 0.0f, 0.0f );        //nadszyje
                glVertex3fv( statehead[8] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( statehead[9] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statehead[7] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statehead[6] );
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[15] );

        	glTexCoord2f( 0.0f, 0.0f );        //podbrodek
                glVertex3fv( statehead[0] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( statehead[1] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statehead[9] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statehead[8] );
    
    
    glEnd();
    
    
    	glBindTexture( GL_TEXTURE_2D, textures[16] );
    
    glBegin( GL_TRIANGLES );
    
        	glTexCoord2f( 1.0f, 0.0f );        //przod glowy prawy
                glVertex3fv( statehead[1] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statehead[3] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statehead[9] );
    
        	glTexCoord2f( 1.0f, 0.0f );        //przod glowy lewy
                glVertex3fv( statehead[0] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statehead[2] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statehead[8] );
                
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[17] );
    
        	glTexCoord2f( 1.0f, 0.0f );        //policzek prawy
                glVertex3fv( statehead[3] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statehead[7] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statehead[9] );
    
        	glTexCoord2f( 1.0f, 0.0f );        //policzek lewy
                glVertex3fv( statehead[2] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statehead[6] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statehead[8] );
                
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[18] );
    
        	glTexCoord2f( 1.0f, 0.0f );        //tyl glowy prawy
                glVertex3fv( statehead[3] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statehead[5] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statehead[7] );
    
        	glTexCoord2f( 1.0f, 0.0f );        //tyl glowy lewy
                glVertex3fv( statehead[2] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statehead[4] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statehead[6] );
    
    glEnd();    
}






void EngineHumanoidGraphicModel::DrawState( float height )
{
    glScalef( height / 1.62f, height / 1.62f, height / 1.62f );
    
    
    
    float statetri[8][3] = {
        { -0.06f, 1.32f, 0.06f  },
        { 0.06f,  1.32f, 0.06f  },
        { 0.06f,  1.32f, -0.06f },
        { -0.06f, 1.32f, -0.06f },
        
        { -0.06f, 1.5f, 0.1f    },
        { 0.06f,  1.5f, 0.1f    },
        { 0.06f,  1.5f, -0.02f  },
        { -0.06f, 1.5f, -0.02f  },
        };
        
    float statehead[10][3] = {
        { -0.04f, 1.42f, 0.14f  },
        { 0.04f,  1.42f, 0.14f  },
        { -0.1f,  1.62f, 0.1f   },
        { 0.1f,   1.62f, 0.1f   },
        { -0.04f, 1.62f, -0.04f },
        { 0.04f,  1.62f, -0.04f },
        { -0.1f,  1.5f,  -0.04f },
        { 0.1f,   1.5f,  -0.04f },
        { -0.1f,  1.42f, 0.07f  },
        { 0.1f,   1.42f, 0.07f  },
        };
    
    
    float consthands[8][3] = {
        { -0.3f, 1.32f, 0.10f  },
        { -0.2f, 1.17f, 0.14f  },
        { 0.2f,  1.17f, 0.14f  },
        { 0.3f,  1.32f, 0.10f  },
        { 0.3f,  1.32f, -0.10f },
        { 0.2f,  1.17f, -0.10f },
        { -0.2f, 1.17f, -0.10f },
        { -0.3f, 1.32f, -0.10f },
    };
    float lhandtri[5][3] = {
        { -0.35f, 0.62f, 0.1f   },
        { -0.35f, 1.02f, 0.07f  },
        { -0.25f, 1.02f, 0.07f  },
        { -0.25f, 0.92f, -0.07f },
        { -0.35f, 0.92f, -0.07f }
        };
    float rhandtri[5][3] = {
        { 0.35f, 0.62f, 0.1f   },
        { 0.35f, 1.02f, 0.07f  },
        { 0.25f, 1.02f, 0.07f  },
        { 0.25f, 0.92f, -0.07f },
        { 0.35f, 0.92f, -0.07f }
        };
        
        
    float constlegs[6][3] = {
        { -0.2f, 0.8f, 0.07  },
        { 0.0f,  0.8f, 0.07  },
        { 0.2f,  0.8f, 0.07  },
        { 0.2f,  0.8f, -0.07 },
        { 0.0f,  0.8f, -0.07 },
        { -0.2f, 0.8f, -0.07 }
        };
    
    float llegtri[5][3] = {
        { -0.15f, 0.0f,  0.0f   },
        { -0.09f, 0.45f, 0.13f  },
        { -0.2f,  0.45f, 0.13f  },
        { -0.2f,  0.45f, -0.01f },
        { -0.09f, 0.45f, -0.01f }
        };
    float rlegtri[5][3] = {
        { 0.15f, 0.0f,  0.0f   },
        { 0.09f, 0.45f, 0.13f  },
        { 0.2f,  0.45f, 0.13f  },
        { 0.2f,  0.45f, -0.01f },
        { 0.09f, 0.45f, -0.01f }
        };
     
    	glBindTexture( GL_TEXTURE_2D, textures[0] );
    	
    	glColor3f( 1.0f, 1.0f, 1.0f );
    	glColor3ub( 255, 255, 255 );
    	
    	glBegin( GL_TRIANGLES );
                    //prawy piszczel:
        	glTexCoord2f( 1.0f, 1.0f );
        		glVertex3fv( rlegtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
        		glVertex3fv( rlegtri[1] );
        	glTexCoord2f( 0.0f, 0.0f );
        		glVertex3fv( rlegtri[2] );
        		
        	glTexCoord2f( 1.0f, 1.0f );
        		glVertex3fv( rlegtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
        		glVertex3fv( rlegtri[2] );
        	glTexCoord2f( 0.0f, 0.0f );
        		glVertex3fv( rlegtri[3] );
        		
        	glTexCoord2f( 1.0f, 1.0f );
        		glVertex3fv( rlegtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
        		glVertex3fv( rlegtri[4] );
        	glTexCoord2f( 0.0f, 0.0f );
        		glVertex3fv( rlegtri[3] );
        		
        	glTexCoord2f( 1.0f, 1.0f );
        		glVertex3fv( rlegtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
        		glVertex3fv( rlegtri[1] );
        	glTexCoord2f( 0.0f, 0.0f );
        		glVertex3fv( rlegtri[4] );
        		
        		
                    //lewy piszczel:
        	glTexCoord2f( 1.0f, 1.0f );
        		glVertex3fv( llegtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
        		glVertex3fv( llegtri[1] );
        	glTexCoord2f( 0.0f, 0.0f );
        		glVertex3fv( llegtri[2] );
        		
        	glTexCoord2f( 1.0f, 1.0f );
        		glVertex3fv( llegtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
        		glVertex3fv( llegtri[2] );
        	glTexCoord2f( 0.0f, 0.0f );
        		glVertex3fv( llegtri[3] );
        		
        	glTexCoord2f( 1.0f, 1.0f );
        		glVertex3fv( llegtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
        		glVertex3fv( llegtri[4] );
        	glTexCoord2f( 0.0f, 0.0f );
        		glVertex3fv( llegtri[3] );
        		
        	glTexCoord2f( 1.0f, 1.0f );
        		glVertex3fv( llegtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
        		glVertex3fv( llegtri[1] );
        	glTexCoord2f( 0.0f, 0.0f );
        		glVertex3fv( llegtri[4] );
    glEnd();      
       
       
    	glBindTexture( GL_TEXTURE_2D, textures[1] );
       
    glBegin( GL_QUADS );
                    //prawe udo:
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( rlegtri[1]   );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( rlegtri[2]   );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( constlegs[2] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( constlegs[1] );
                
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( rlegtri[2]   );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( rlegtri[3]   );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( constlegs[3] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( constlegs[2] );
    
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( rlegtri[4]   );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( rlegtri[3]   );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( constlegs[3] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( constlegs[4] );
                
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( rlegtri[1]   );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( rlegtri[4]   );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( constlegs[4] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( constlegs[1] );
    
    
                    //lewe udo:
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( llegtri[1]   );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( llegtri[2]   );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( constlegs[0] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( constlegs[1] );
                
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( llegtri[2]   );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( llegtri[3]   );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( constlegs[5] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( constlegs[0] );
    
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( llegtri[4]   );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( llegtri[3]   );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( constlegs[5] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( constlegs[4] );
                
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( llegtri[1]   );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( llegtri[4]   );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( constlegs[4] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( constlegs[1] );
    
    
    glEnd();
    
    
    	glBindTexture( GL_TEXTURE_2D, textures[2] );
    
    glBegin( GL_TRIANGLES );
    
                    //lewe przedramie:
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( lhandtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( lhandtri[1] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( lhandtri[2] );
    
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( lhandtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( lhandtri[2] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( lhandtri[3] );
    
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( lhandtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( lhandtri[3] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( lhandtri[4] );
    
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( lhandtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( lhandtri[1] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( lhandtri[4] );
    
                    //prawe przedramie:
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( rhandtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( rhandtri[1] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( rhandtri[2] );
    
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( rhandtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( rhandtri[2] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( rhandtri[3] );
    
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( rhandtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( rhandtri[3] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( rhandtri[4] );
    
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( rhandtri[0] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( rhandtri[1] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( rhandtri[4] );
    
    glEnd();
    
    
    	glBindTexture( GL_TEXTURE_2D, textures[3] );
    
    glBegin( GL_QUADS );
    
                    //lewe ramie:
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( lhandtri[1] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( lhandtri[2] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[1] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[0] );
                
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( lhandtri[2] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( lhandtri[3] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[6] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[1] );
        
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( lhandtri[4] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( lhandtri[3] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[6] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[7] );
                
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( lhandtri[1] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( lhandtri[4] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[7] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[0] );
        
        
    
                    //prawe ramie:
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( rhandtri[1] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( rhandtri[2] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[2] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[3] );
                
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( rhandtri[2] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( rhandtri[3] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[5] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[2] );
                
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( rhandtri[4] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( rhandtri[3] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[5] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[4] );
                
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( rhandtri[1] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( rhandtri[4] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[4] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[3] );
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[4] );
                
                	//tulow
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( constlegs[0] );		//przod
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( constlegs[2] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( consthands[2] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[1] );
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[5] );
                
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( constlegs[5] );		//tyl
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( constlegs[3] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( consthands[5] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[6] );
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[6] );
                
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( constlegs[2] );		//prawo
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( constlegs[3] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[5] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[2] );
                
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( constlegs[0] );		//lewo
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( constlegs[5] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[6] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[1] );
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[7] );
                
                	//ramiona:
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[1] );		//przod
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( consthands[2] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( consthands[3] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[0] );
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[8] );
                
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[6] );		//tyl
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( consthands[5] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( consthands[4] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[7] );
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[9] );
                
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( consthands[0] );		//gora
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( consthands[3] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( consthands[4] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( consthands[7] );
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[10] );
                
                	//szyja:
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statetri[0] );		//przod
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( statetri[1] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( statetri[5] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statetri[4] );
                
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statetri[1] );		//prawy
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( statetri[2] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( statetri[6] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statetri[5] );
                
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statetri[3] );		//tyl
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( statetri[2] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( statetri[6] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statetri[7] );
                	
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statetri[0] );		//lewy
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( statetri[3] );
        	glTexCoord2f( 0.0f, 0.0f );
                glVertex3fv( statetri[7] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statetri[4] );
    

    	glBindTexture( GL_TEXTURE_2D, textures[11] );

                    //glowa:
        	glTexCoord2f( 0.0f, 0.0f );        //twarz
                glVertex3fv( statehead[0] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( statehead[1] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statehead[3] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statehead[2] );
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[12] );

        	glTexCoord2f( 0.0f, 0.0f );        //'top' glowy
                glVertex3fv( statehead[2] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( statehead[3] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statehead[5] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statehead[4] );
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[13] );

        	glTexCoord2f( 0.0f, 0.0f );        //tyl glowy
                glVertex3fv( statehead[6] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( statehead[7] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statehead[5] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statehead[4] );
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[14] );

        	glTexCoord2f( 0.0f, 0.0f );        //nadszyje
                glVertex3fv( statehead[8] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( statehead[9] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statehead[7] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statehead[6] );
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[15] );

        	glTexCoord2f( 0.0f, 0.0f );        //podbrodek
                glVertex3fv( statehead[0] );
        	glTexCoord2f( 1.0f, 0.0f );
                glVertex3fv( statehead[1] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statehead[9] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statehead[8] );
    
    
    glEnd();
    
    
    	glBindTexture( GL_TEXTURE_2D, textures[16] );
    
    glBegin( GL_TRIANGLES );
    
        	glTexCoord2f( 1.0f, 0.0f );        //przod glowy prawy
                glVertex3fv( statehead[1] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statehead[3] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statehead[9] );
    
        	glTexCoord2f( 1.0f, 0.0f );        //przod glowy lewy
                glVertex3fv( statehead[0] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statehead[2] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statehead[8] );
                
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[17] );
    
        	glTexCoord2f( 1.0f, 0.0f );        //policzek prawy
                glVertex3fv( statehead[3] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statehead[7] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statehead[9] );
    
        	glTexCoord2f( 1.0f, 0.0f );        //policzek lewy
                glVertex3fv( statehead[2] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statehead[6] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statehead[8] );
                
                
                
    	glBindTexture( GL_TEXTURE_2D, textures[18] );
    
        	glTexCoord2f( 1.0f, 0.0f );        //tyl glowy prawy
                glVertex3fv( statehead[3] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statehead[5] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statehead[7] );
    
        	glTexCoord2f( 1.0f, 0.0f );        //tyl glowy lewy
                glVertex3fv( statehead[2] );
        	glTexCoord2f( 1.0f, 1.0f );
                glVertex3fv( statehead[4] );
        	glTexCoord2f( 0.0f, 1.0f );
                glVertex3fv( statehead[6] );
    
    glEnd();    
}
