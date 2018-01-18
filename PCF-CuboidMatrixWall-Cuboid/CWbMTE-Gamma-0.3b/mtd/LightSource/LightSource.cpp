


// -------------------------------
// n: distance to near clip plane
// f: distance to far clip plane
// z: value in depth buffer
// -------------------------------
inline float glConvertDepthBufferZvalue( float n, float f, float z )
{
	return (2*f*n/(f-n))/(z-((f+n)/(f-n)));
	
    // Convert Z from [0, 1] to [-1, 1]
    float wz = (2.0 * z) - 1.0;
 
    // Inverse projection matrix on the Z coordinate (assuming W=1)
    float a = -(f - n) / (2.0 * f * n);
    float b =  (f + n) / (2.0 * f * n);
    return -1.0 / (wz * a + b);
}

inline void LightSource::UpdateDepthBuffer( Map * map )
{
	if( angle > 89.0f  )
		angle = 89.0f;
	
	direction.Normalize();
	
	originBuffered = origin;
	directionBuffered = direction;
	rangeBuffered = range;
	angleBuffered = angle;
	densityBuffered = density;
	
	/*
	float anglex, angley;
	angley = ( acos( directionBuffered.Dot( SetVector( 0.0f, -1.0f, 0.0 ) ) ) * 180.0f / float(M_PI) ) - 90.0f;
	anglex = ( acos( SetVector( directionBuffered[0], 0.0f, directionBuffered[2] ).Dot( SetVector( 0.0f, 0.0f, 1.0f ) ) ) * 180.0f / float(M_PI) );
	if( directionBuffered[0] < 0.0f )
		anglex = -anglex;
	*/
	
	
	if( directionBuffered.Versor() == SetVector(0.0f,1.0f,0.0f) )
	{
		upDirectionBuffered = SetVector( 0.0f, 0.0f, -1.0f );
	}
	else if( directionBuffered.Versor() == SetVector(0.0f,-1.0f,0.0f) )
	{
		upDirectionBuffered = SetVector( 0.0f, 0.0f, 1.0f );
	}
	else
	{
		upDirectionBuffered = ( directionBuffered && ( ( directionBuffered.Versor() == SetVector(0.0f,1.0f,0.0f) ) ? SetVector(1.0f,0.0f,0.0f) : SetVector(0.0f,1.0f,0.0f) ) ) && directionBuffered;
		if( upDirectionBuffered.Dot( SetVector( 0.0f, 1.0f, 0.0f ) ) * 180.0f / float(M_PI) > 90.0f )
			upDirectionBuffered = upDirectionBuffered * (-1.0f);
	}
	
//	printf( "\n   %f : %f : %f ||  %f : %f : %f ||  %f : %f : %f", originBuffered[0], originBuffered[1], originBuffered[2], directionBuffered[0], directionBuffered[1], directionBuffered[2], upDirectionBuffered[0], upDirectionBuffered[1], upDirectionBuffered[2] );
	
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( angleBuffered*2.0f, 4.0f/3.0f, 0.1f, rangeBuffered );
	
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
	
	gluLookAt( 	originBuffered[0], originBuffered[1], originBuffered[2],
				originBuffered[0]+directionBuffered[0], originBuffered[1]+directionBuffered[1], originBuffered[2]+directionBuffered[2],
				upDirectionBuffered[0], upDirectionBuffered[1], upDirectionBuffered[2] );
	
//	glRotatef( -staticobject[0]->see[1], 1.0f, 0.0f, 0.0f );
//	glRotatef( -(staticobject[0]->see[0]-90.0f), 0.0f, 1.0f, 0.0f );
//	glTranslatef( -originBuffered[0], -originBuffered[1], -originBuffered[2] );
	
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
//	glFlush();		// nie miem czy to musi byæ
	///////////////////////////////////////////
	///////////////////////////////////////////
	
	glReadBuffer(GL_FRONT);
	glReadPixels( 100, 0, 600, 600, GL_DEPTH_COMPONENT, GL_FLOAT, depthBufferData );
	
	matrix = gluLookAtVMatrix( originBuffered, directionBuffered, upDirectionBuffered );
	/*
	matrix.InitEmpty();
	matrix.RotateX( staticobject[0]->see[1] );
	matrix.RotateX( staticobject[0]->see[1] );
	glRotatef( -staticobject[0]->see[1], 1.0f, 0.0f, 0.0f );
	glRotatef( -(staticobject[0]->see[0]-90.0f), 0.0f, 1.0f, 0.0f );
	glTranslatef( -originBuffered[0], -originBuffered[1], -originBuffered[2] );
	*/
	
	
	/*
	ofstream file___light_Log( "log.log" );
	file___light_Log << "\n\n\n\n\n\n";
	int j;
	for( i = 0; i < 600; ++i )
	{
		for( j = 0; j < 600; ++j )
		{
			file___light_Log << depthBufferData[(600*i)+j] << "   ";
		}
		file___light_Log << "\n";
	}*/
	
	printf( "\n   depth value: %f", glConvertDepthBufferZvalue( 0.1f, rangeBuffered, depthBufferData[300*601] ) );
}

inline unsigned char LightSource::GetLightStrenght( Vector pos )
{
	Vector point, pointprim;
	point = matrix.GetVertex( pos );
	
	float anglex, angley, anglemul, len = point.Lenght(), t;
	
//	anglemul = acos(  ) * 180.0f / float(M_PI);
	
	anglex = acos( SetVector( 0.0f, 0.0f, abs(point[2]) ).Versor().Dot( SetVector( point[0], 0.0f, point[2] ) ) ) * 180.0f / float(M_PI);
	angley = acos( SetVector( point[0], 0.0f, abs(point[2]) ).Versor().Dot( point ) ) * 180.0f / float(M_PI);
	
	if( point[0] >= 0.0f )
		anglex = -anglex;
	if( point[1] >= 0.0f )
		angley = -angley;
	
	anglemul = acos( SetVector( 0.0f, 0.0f, 1.0f ).Dot( point.Versor() ) ) * 180.0f / float(M_PI);
	
	if( anglemul < angleBuffered && len < rangeBuffered )
	{
		int posx, posy;
		posx = 300 + int( anglex * 300.0f / angleBuffered );
		posy = 300 + int( angley * 300.0f / angleBuffered );
		
		float pointZposFromBuffer = glConvertDepthBufferZvalue( 0.1f, rangeBuffered, depthBufferData[(posy*600)+posx] );
		
		if( rangeBuffered+0.01f >= point[2] )
		{
			return ( unsigned char )( 230.0f * sqrt((-len/rangeBuffered)+1.0f) * ((angleBuffered-anglemul)/angleBuffered) * densityBuffered );
		}
	}
	return 0;
}

LightSource::LightSource()
{
	matrix.InitEmpty();
	upDirectionBuffered.Set( 1.0f, 1.0f, 1.0f );
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

