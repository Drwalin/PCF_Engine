


// -------------------------------
// n: distance to near clip plane
// f: distance to far clip plane
// z: value in depth buffer
// -------------------------------



namespace ImageSaveingHeightMap
{
	vector < unsigned char > image;
	unsigned int height, width;
	
	inline void SetPixel( int x, int y, float hei )
	{
		image[((width-1-x)*height*4)+(y*4)+0] = (unsigned char)(hei*255);
		image[((width-1-x)*height*4)+(y*4)+1] = (unsigned char)(hei*255);
		image[((width-1-x)*height*4)+(y*4)+2] = (unsigned char)(hei*255);
		image[((width-1-x)*height*4)+(y*4)+3] = 255;
	}
	
	void SaveMap(const char* filename)
	{
		vector<unsigned char> png;
		unsigned error = lodepng::encode(png, image, width, height);
		if(!error) lodepng::save_file(png, filename);
		if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
	}
};




inline float glConvertDepthBufferZvalue( float n, float f, float z )
{
	return ( n*f / (n-f) ) / ( z - f / (f-n) );
}

inline void LightSource::UpdateDepthBuffer( Map * map )
{
	if( angle > 40.0f  )
		angle = 40.0f;
	
	direction.Normalize();
	
	originBuffered = origin;
	directionBuffered = direction;
	rangeBuffered = range;
	angleBuffered = angle;
	densityBuffered = density;
	
	float anglex, angley;
	angley = ( acos( directionBuffered.Dot( SetVector( 0.0f, -1.0f, 0.0 ) ) ) * 180.0f / float(M_PI) ) - 90.0f;
	anglex = ( acos( SetVector( directionBuffered[0], 0.0f, directionBuffered[2] ).Versor().Dot( SetVector( 0.0f, 0.0f, 1.0f ) ) ) * 180.0f / float(M_PI) );
	if( directionBuffered[0] >= 0.0f )
		anglex = -anglex;
	
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glViewport( 800, 0, (GLsizei)600, (GLsizei)600 );
    gluPerspective( angleBuffered*2.35f, 1.0f, 0.1f, rangeBuffered );
	
	glMatrixMode( GL_MODELVIEW );
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	glClear( GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();
	glEnable( GL_DEPTH_TEST );
	glEnable( GL_ALPHA_TEST );
	glEnable( GL_BLEND );
	glDepthFunc( GL_LEQUAL );
	glDepthMask( GL_TRUE );
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
	
	
	glLoadIdentity();
	glRotatef( -angley, 1.0f, 0.0f, 0.0f );
	glRotatef( anglex-180.0f, 0.0f, 1.0f, 0.0f );
	glTranslatef( -originBuffered[0], -originBuffered[1], -originBuffered[2] );
	
	int i;
	
	glColor3ub( 255, 255, 255 );
	
	for( i = 0; i < map->vbotex.size(); i++ )
	{
		map->vbotex[i].Draw();
	}
	for( i = 0; i < map->vbocol.size(); i++ )
	{
		map->vbocol[i].Draw();
	}
	for( i = 0; i < map->graphicMapModels.size(); ++i )
	{
		map->graphicMapModels[i] -> Draw();
	}
//	map->DrawShadowMap();
	
	///////////////////////////////////////////
	///////////////////////////////////////////
	glFlush();		// nie miem czy to musi byæ
	///////////////////////////////////////////
	///////////////////////////////////////////
	
	glReadBuffer( GL_FRONT );
	glReadPixels( 800, 0, 600, 600, GL_DEPTH_COMPONENT, GL_FLOAT, depthBufferData );
	
	
	
	ImageSaveingHeightMap::width = 600;
	ImageSaveingHeightMap::height = 600;
	ImageSaveingHeightMap::image.resize( ImageSaveingHeightMap::width*ImageSaveingHeightMap::height*4 );
//	ImageSaveingHeightMap::SaveMap( "Shadow_Map.png" );
	
	int j;
	for( i = 0; i < ImageSaveingHeightMap::width; ++i )
	{
		for( j = 0; j < ImageSaveingHeightMap::height; ++j )
		{
//			ImageSaveingHeightMap::SetPixel( i, j, 255 );
//			ImageSaveingHeightMap::SetPixel( i, j, glConvertDepthBufferZvalue( 0.1f, rangeBuffered, depthBufferData[(i*600)+j] )/rangeBuffered );
		}
	}
	
	
	
	
//	glutSwapBuffers();
	
	matrix.InitEmpty();
	matrix.RotateX( angley );
	matrix.RotateY( anglex );
//	matrix.RotateY( -90.0f );
//	matrix.Translate( 0.0f-originBuffered );
	
	
}

inline unsigned char LightSource::GetLightStrenght( Vector pos )
{
	Vector point, pointprim;
	point = matrix.GetVertex( pos - originBuffered );
	
	if( point[2] <= 0.101f )
	{
		return 0;
	}
	
	pointprim = point * 0.1f / point[2];
	
	float anglemul, len = point[2];//point.Lenght();
	
	anglemul = acos( SetVector( 0.0f, 0.0f, 1.0f ).Dot( point.Versor() ) ) * 180.0f / float(M_PI);
	
	if( anglemul < angleBuffered && len < rangeBuffered && len > 0.1f )
	{
		float max_x =  tan( angleBuffered ) * 0.1f;
		int posx, posy;
		posx = int( 300.0f - ( pointprim[1] * 300.0f / max_x ) );
		posy = int( 300.0f + ( pointprim[0] * 300.0f / max_x ) );
//		posx = int( ( 300.0f * acos( SetVector( point[0], 0.0f, point[2] ).Versor().Dot( SetVector( 0.0f, 0.0f, 1.0f ) ) ) * 180.0f / ( float(M_PI) * angleBuffered ) ) + 300.0f );
//		posy = int( ( 300.0f * acos( SetVector( 0.0f, point[1], point[2] ).Versor().Dot( SetVector( 0.0f, 0.0f, 1.0f ) ) ) * 180.0f / ( float(M_PI) * angleBuffered ) ) + 300.0f );
		
		if( posx < 0 || posy < 0 || posx >= 600 || posy >= 600 )
		{
			return 0;
		}
		
		float pointZposFromBuffer = glConvertDepthBufferZvalue( 0.1f, rangeBuffered, depthBufferData[(posx*600)+posy] );
		
		float distance = pointZposFromBuffer;//( point * pointZposFromBuffer / point[2] ).Lenght();
		
//		printf( "\n %f", distance/rangeBuffered );
//		if( ImageSaveingHeightMap::image.size() > 0 )//posx >= 0 && posy >= 0 && posx < 600 && posy < 600 )
//			ImageSaveingHeightMap::SetPixel( posx, posy, distance/rangeBuffered );
		if( distance*1.25f >= len )
		{
			return ( unsigned char )( 230.0f * sqrt((-len/rangeBuffered)+1.0f) * ((angleBuffered-anglemul)/angleBuffered) * densityBuffered );
		}
	}
	return 0;
}

LightSource::LightSource()
{
	matrix.InitEmpty();
//	upDirectionBuffered.Set( 1.0f, 1.0f, 1.0f );
	originBuffered.Set( 0.0f, 100.0f, 0.0f );
	directionBuffered.Set( 0.0, -1.0f, 0.0f );
	rangeBuffered = 1000.0f;
	angleBuffered = 90.0f;
	densityBuffered = 1.0f;
	origin.Set( 0.0f, 100.0f, 0.0f );
	direction.Set( 0.0, -1.0f, 0.0f );
	range = 1000.0f;
	angle = 90.0f;
	density = 1.0f;
	int i;
	for( i = 0; i < 600*600; ++i )
		depthBufferData[i] = 0.0f;
}

LightSource::~LightSource()
{
	matrix.InitEmpty();
	originBuffered.Set( 0.0f, 0.0f, 0.0f );
	directionBuffered.Set( 0.0, 0.0f, 0.0f );
	rangeBuffered = 0.0f;
	angleBuffered = 0.0f;
	densityBuffered = 0.0f;
	origin.Set( 0.0f, 0.0f, 0.0f );
	direction.Set( 0.0, 0.0f, 0.0f );
	range = 0.0f;
	angle = 0.0f;
	density = 0.0f;
	int i;
	for( i = 0; i < 600*600; ++i )
		depthBufferData[i] = 0.0f;
}



GlobalLightSource::GlobalLightSource()
{
	origin.Set( 0.0f, 100.0f, 0.0f );
	direction.Set( 0.0, -1.0f, 0.0f );
	range = 1000.0f;
	angle = 90.0f;
	density = 1.0f;
}

GlobalLightSource::~GlobalLightSource()
{
	origin.Set( 0.0f, 0.0f, 0.0f );
	direction.Set( 0.0, 0.0f, 0.0f );
	range = 0.0f;
	angle = 0.0f;
	density = 0.0f;
}

