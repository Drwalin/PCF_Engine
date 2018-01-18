


inline Vector Triangle::GetBeginNormal()
{
	return ( vertex[indices[0]] + vertex[indices[1]] + vertex[indices[2]] ) / 3.0f;
}

inline bool Triangle::IsTherePoint( int id )
{
	if( indices[0] == id ) return true;
	if( indices[1] == id ) return true;
	if( indices[2] == id ) return true;
	return false;
}

inline void Triangle::NegateNormal()
{
	normal = 0.0f - normal;
}

inline void Triangle::CalcNormal()
{
	normal = ( (vertex[indices[0]]-vertex[indices[1]]) && (vertex[indices[0]]-vertex[indices[2]]) ).Versor();
}



// Indices:

inline int& Indices::operator[]( int id )
{
	return triangles[id/3].indices[id%3];
}

inline int Indices::size()
{
	return triangles.size()*3;
}


