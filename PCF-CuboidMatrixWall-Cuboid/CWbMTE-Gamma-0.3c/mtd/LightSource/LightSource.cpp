


// -------------------------------
// n: distance to near clip plane
// f: distance to far clip plane
// z: value in depth buffer
// -------------------------------
inline float glConvertDepthBufferZvalue( float n, float f, float z )
{
	bool dupa = false;
	if( dupa )
	{
		float wz = (2.0 * z) - 1.0;////////////////5	
		float a = -(f - n) / (2.0 * f * n);////////////////5
		float b =  (f + n) / (2.0 * f * n);////////////////5
		return 1.0 / (wz * a + b);////////////////5
	}
    
    
	if( dupa )
	{
		return (2*f*n/(f-n))/(((2.0f*z)-1.0f)-((f+n)/(f-n)));////////////2
	}
	
	
	
	if( dupa )	//
	{
		return ( ( ( (f-n) / z ) / (f+n) ) / (f*n) );//////////1 my
	}
	
	
	
	if( dupa )
	{
		GLfloat clip_z = z;//(z - 0.5f) * 2.0f;////////////////3
		return 2*f*n/(clip_z*(f-n)-(f+n));////////////////////3      Crizer'sPL
	}
	
	
	
	if( !dupa )
	{
		return (n*f/(n-f))/(z-f/(f-n));////////////////4
	}
}

Vector GetOGLPos(int x, int y)
{
    GLint viewport[4];
    GLdouble modelview[16];
    GLdouble projection[16];
    GLfloat winX, winY, winZ;
    GLdouble posX, posY, posZ;
 
    glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
    glGetDoublev( GL_PROJECTION_MATRIX, projection );
    glGetIntegerv( GL_VIEWPORT, viewport );
 
    winX = (float)x;
    winY = (float)viewport[3] - (float)y;
    glReadPixels( 300/*x*/, 300/*int(winY)*/, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );
    
    winZ = winZ * 2.0f - 1.0f;
 
    gluUnProject( winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ );
 
    return SetVector( posX, posY, posZ );
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
	anglex = ( acos( SetVector( directionBuffered[0], 0.0f, directionBuffered[2] ).Dot( SetVector( 0.0f, 0.0f, 1.0f ) ) ) * 180.0f / float(M_PI) );
	if( directionBuffered[0] >= 0.0f )
		anglex = -anglex;
//	anglex = -anglex;
	
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( angleBuffered*2.0f, 4.0f/3.0f, 0.1f, 200.0f );//rangeBuffered );
	
	glMatrixMode( GL_MODELVIEW );
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();
	glEnable( GL_DEPTH_TEST );
	glDisable( GL_ALPHA_TEST );
	glDisable( GL_BLEND );
	glDepthFunc( GL_LEQUAL );
	glDepthMask( GL_TRUE );
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
	
	
	glLoadIdentity();
	glRotatef( -angley, 1.0f, 0.0f, 0.0f );
	glRotatef( -anglex+90.0f, 0.0f, 1.0f, 0.0f );
	glTranslatef( -originBuffered[0], -originBuffered[1], -originBuffered[2] );
	
	int i;
	
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
	
	
	///////////////////////////////////////////
	///////////////////////////////////////////
	glFlush();		// nie miem czy to musi byæ
	///////////////////////////////////////////
	///////////////////////////////////////////
	
	glReadBuffer( GL_FRONT );
	glReadPixels( 100, 0, 600, 600, GL_DEPTH_COMPONENT, GL_FLOAT, depthBufferData );
	
	
	matrix.InitEmpty();
	matrix.RotateY( anglex );
	matrix.RotateX( -angley );
	matrix.Translate( 0.0f-originBuffered );
	
	//printf( "\n depth = %f", GetOGLPos( 300, 300 )[2] );
	//if( false )
	{
		GLdouble projection_[16];
		GLfloat depth_;
		float distance_;
	 
		glGetDoublev( GL_PROJECTION_MATRIX, projection_ );
		glReadPixels( 300, 300, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &/*amp;*/depth_ );
	 
		//distance_ = projection_[14] / ( depth_ * -2.0 + 1.0 - projection_[10] ) * -1.0f;
		//distance_ = ( ( depth_ * -2.0f + 1.0f ) - projection_[14] ) / ( projection_[10] );
		//distance_ = projection_[14] / ( depth_ * -2.0 + 1.0 - projection_[10] ) * -1.0f;
		distance_ = glConvertDepthBufferZvalue( 0.1f, rangeBuffered, depth_ );
		printf( "\n   Depth buffer: %f", depth_ );
		exit( 0 );
	}
	
	//ofstream file___light_Log( "log.log" );
	//file___light_Log << "\n\n\n\n\n\n" << depthBufferData;
	/*
	int j;
	for( i = 0; i < 600; ++i )
	{
		for( j = 0; j < 600; ++j )
		{
			file___light_Log << depthBufferData[(600*i)+j] << "   ";
		}
		file___light_Log << "\n";
	}
	*/
}

inline unsigned char LightSource::GetLightStrenght( Vector pos )
{
	Vector point, pointprim;
	point = matrix.GetVertex( pos );
	
	if( point[2] <= 0.00001f )
	{
		return 0;
	}
	
	pointprim = point * 0.1f / point[2];
	
	float anglex, angley, anglemul, len = point.Lenght(), t;
	
	anglemul = acos( SetVector( 0.0f, 0.0f, 1.0f ).Dot( point.Versor() ) ) * 180.0f / float(M_PI);
	
	if( anglemul < angleBuffered && len < rangeBuffered )
	{
		float max_v =  tan( angleBuffered ) * 0.1f;
		int posx, posy;
		posx = int( ( pointprim[0] * 300.0f / max_v ) + 300.0f );
		posy = int( ( pointprim[1] * 300.0f / max_v ) + 300.0f);
		
		if( posx < 0 || posy < 0 || posx >= 600 || posy >= 600 )
		{
			return 0;
		}
		
		float pointZposFromBuffer = glConvertDepthBufferZvalue( 0.1f, rangeBuffered, depthBufferData[((posy)*600)+posx] );
		
		if( pointZposFromBuffer/*(rangeBuffered+0.01f)*/ >= point[2] )
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

