


inline bool Collision::RayTriangle( Vector p1, Vector p2, TrianglePX * tri )
{
	return tri -> PointIn( p1, p2 );
}


