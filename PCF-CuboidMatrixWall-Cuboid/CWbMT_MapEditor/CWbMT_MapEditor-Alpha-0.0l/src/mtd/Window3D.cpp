


inline Vector Window3D::GetForwardVersor()
{
	VMatrix fast;
	fast.InitEmpty();
    fast.RotateY( -lookx );
    fast.RotateX( -looky );
    return fast.GetVertex( SetVector( 0.0f, 0.0, 1.0f ) );
}

inline Vector Window3D::GetBackwardVersor()
{
	VMatrix fast;
	fast.InitEmpty();
    fast.RotateY( -lookx );
    fast.RotateX( -looky );
    return fast.GetVertex( SetVector( 0.0f, 0.0, -1.0f ) );
}

inline Vector Window3D::GetLeftVersor()
{
	VMatrix fast;
	fast.InitEmpty();
//    fast.RotateX( -looky );
    fast.RotateY( -(lookx+90.0f) );
    return fast.GetVertex( SetVector( 0.0f, 0.0, 1.0f ) );
}

inline Vector Window3D::GetRightVersor()
{
	VMatrix fast;
	fast.InitEmpty();
//    fast.RotateX( -looky );
    fast.RotateY( -(lookx-90.0f) );
    return fast.GetVertex( SetVector( 0.0f, 0.0, 1.0f ) );
}



inline void Window3D::InitMatix()
{
	matrix.InitEmpty();
    matrix.RotateX( looky );
    matrix.RotateY( lookx );
    matrix.Translate( 0.0f - pos );
}

inline void Window3D::Update( float rotx, float roty, Vector move )
{
	lookx += rotx;
	looky += roty;
	if( looky < -90.0f )
		looky = -90.0f;
	else if( looky > 90.0f )
		looky = 90.0f;
	pos += move;
	InitMatix();
	points.resize( 0 );
}

inline void Window3D::Clear()
{
	matrix.InitEmpty();
	points.resize( 0 );
}

inline void Window3D::AddPoint( Vector src )
{
	points.push_back( src );
	points[points.size()-1] = matrix.GetVertex( src );
	
	if( points[points.size()-1][2] <= 0.1f )
	{
		points[points.size()-1][2] = -1.0f;
		return;
	}
	float l = points[points.size()-1].Lenght();
	float t = 1 / ((points[points.size()-1]/l)[2]);
	points[points.size()-1] = (points[points.size()-1] / l) * t;
	points[points.size()-1][2] = l;
}

Window3D::Window3D()
{
	points.resize( 0 );
	pos.Set( 0.0f, 0.0f, 0.0f );
	lookx = 0.0f;
	looky = 0.0f;
	matrix.InitEmpty();
}


