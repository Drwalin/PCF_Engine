


inline bool Collision::RayTriangle( Vector p1, Vector p2, TrianglePX * tri )
{
	return tri -> PointIn( p1, p2 );
}

inline bool Collision::RayTriangle( Vector p1, Vector p2, TrianglePX * tri, Vector * point )
{
	*point = tri -> GetCrossPoint( p1, p2 );
	if( tri -> PointIn( *point ) == true )
	{
		return true;
	}
	point = NULL;
	return false;
}


