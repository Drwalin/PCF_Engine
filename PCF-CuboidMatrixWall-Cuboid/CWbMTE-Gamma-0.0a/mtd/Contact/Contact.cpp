


inline void Contact::AddPoint( Vector point )
{
	points.back().push_back( point );
}

inline void Contact::AddDirection( Vector dir )
{
	direction.push_back( dir );
	points.resize( points.size() + 1 );
}

inline Vector Contact::GetFaceBarycentic( const int id )
{
	if( id >= points.size() )
		return SetVector( 0.0f, 0.0f, 0.0f );
	else if( points[id].size() == 0 )
		return SetVector( 0.0f, 0.0f, 0.0f );
	
	int i;
	Vector fMax = points[id][0], fMin = points[id][0];
	
	for( i = 1; i < points[id].size(); ++i )
	{
		if( fMin[0] > points[id][i][0] )
			fMin[0] = points[id][i][0];
		if( fMin[1] > points[id][i][1] )
			fMin[1] = points[id][i][1];
		if( fMin[2] > points[id][i][2] )
			fMin[2] = points[id][i][2];
		if( fMax[0] < points[id][i][0] )
			fMax[0] = points[id][i][0];
		if( fMax[1] < points[id][i][1] )
			fMax[1] = points[id][i][1];
		if( fMax[2] < points[id][i][2] )
			fMax[2] = points[id][i][2];
	}
	
	return (fMin + fMax) * 0.5f;
}

inline Vector Contact::GetMediumDirection()
{
	int i;
	Vector dst = SetVector( 0.0f, 0.0f, 0.0f );
	for( i = 0; i < direction.size(); ++i )
		if( points[i].size() > 0 )
			dst += direction[i];
	return dst.Versor();
}

inline bool Contact::WasIntersection()
{
	bool intersection = false;
	int i;
	for( i = 0; i < points.size(); ++i )
	{
		if( points[i].size() > 0 )
		{
			intersection = true;
		}
		else
		{
//			points.erase( points.begin() + i );
//			direction.erase( direction.begin() + i );
//			--i;
		}
	}
	return false;
}

inline void Contact::Clear()
{
	int i;
	for( i = 0; i < points.size(); ++i )
		points[i].resize( 0 );
	
	points.resize( 0 );
	direction.resize( 0 );
}

Contact::Contact()
{
	points.resize( 0 );
	direction.resize( 0 );
}

Contact::~Contact()
{
	points.resize( 0 );
	direction.resize( 0 );
}


