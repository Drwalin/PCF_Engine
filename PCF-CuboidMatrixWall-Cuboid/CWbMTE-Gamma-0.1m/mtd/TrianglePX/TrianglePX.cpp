

inline Vector TrianglePX::ClosestPoint( Vector p )
{
// Check if P in vertex region outside A
	Vector ab = vertex[1] - vertex[0];
	Vector ac = vertex[2] - vertex[0];
	Vector ap = p - vertex[0];
	float d1 = ab.Dot(ap);
	float d2 = ac.Dot(ap);
	if (d1 <= 0.0f && d2 <= 0.0f) return vertex[0]; // barycentric coordinates (1,0,0)
// Check if P in vertex region outside B
	Vector bp = p - vertex[1];
	float d3 = ab.Dot(bp);
	float d4 = ac.Dot(bp);
	if (d3 >= 0.0f && d4 <= d3) return vertex[1]; // barycentric coordinates (0,1,0)
// Check if P in edge region of AB, if so return projection of P onto AB
	float vc = (d1*d4) - (d3*d2);
	if (vc <= 0.0f && d1 >= 0.0f && d3 <= 0.0f)
	{
		float v = d1 / (d1 - d3);
		return vertex[0] + (v * ab); // barycentric coordinates (1-v,v,0)
	}
// Check if P in vertex region outside C
	Vector cp = p - vertex[2];
	float d5 = ab.Dot(cp);
	float d6 = ac.Dot(cp);
	if (d6 >= 0.0f && d5 <= d6) return vertex[2]; // barycentric coordinates (0,0,1)
// Check if P in edge region of AC, if so return projection of P onto AC
	float vb = (d5*d2) - (d1*d6);
	if (vb <= 0.0f && d2 >= 0.0f && d6 <= 0.0f)
	{
		float w = d2 / (d2 - d6);
	return vertex[0] + (ac * w); // barycentric coordinates (1-w,0,w)
	}
// Check if P in edge region of BC, if so return projection of P onto BC
	float va =( d3*d6) - (d5*d4);
	if (va <= 0.0f && (d4 - d3) >= 0.0f && (d5 - d6) >= 0.0f)
	{
		float w = (d4 - d3) / ((d4 - d3) + (d5 - d6));
		return vertex[1] + ((vertex[2] - vertex[1]) * w); // barycentric coordinates (0,1-w,w)
	}
// P inside face region. Compute Q through its barycentric coordinates (u,v,w)
	float denom = 1.0f / (va + vb + vc);
	float v = vb * denom;
	float w = vc * denom;
	return vertex[0] + (ab * v) + (ac * w);
}

inline bool TrianglePX::PointIn( Vector p )
{
	if( wallnormals[0].Dot( p - vertex[0] ) >= 0.0f )
		if( wallnormals[1].Dot( p - vertex[1] ) >= 0.0f )
			if( wallnormals[2].Dot( p - vertex[2] ) >= 0.0f )
				return true;
	return false;
}

inline bool TrianglePX::PointIn( Vector p1, Vector p2 )
{
	Vector dir = (p2-p1).Versor();
	float dot = normal.Dot( dir );
	if( dot == 0.0f )
		return false;
	float t = ( - det - normal.Dot( p1 ) ) / dot;
	if( t < 0.0f || t > (p2-p1).Lenght() )
		return false;
	return PointIn( p1 + (dir*t) );
}

inline bool TrianglePX::PointIn( Vector p1, Vector p2, Vector * dst )
{
	Vector dir = (p2-p1).Versor();
	float dot = normal.Dot( dir );
	if( dot == 0.0f )
	{
		return false;
	}
	float t = ( normal.Dot( vertex[0] - p1 ) ) / dot;
	if( t < 0.0f || t > (p2-p1).Lenght() )
	{
		return false;
	}
	*dst = p1 + (dir*t);
	return PointIn( *dst );
}

inline bool TrianglePX::GetCrossPoint( Vector p1, Vector p2, Vector * dst )
{
	Vector dir = (p2-p1).Versor();
	float dot = normal.Dot( dir );
	if( dot == 0.0f )
	{
		return false;
	}
	float t = ( normal.Dot( vertex[0] - p1 ) ) / dot;
	if( t < 0.0f || t > (p2-p1).Lenght() )
	{
		return false;
	}
	*dst = p1 + (dir*t);
	return true;
}

inline Vector TrianglePX::GetCrossPoint( Vector p1, Vector p2 )
{
	Vector dir = (p2-p1).Versor();
	float dot = normal.Dot( dir );
	if( dot == 0.0f )
		return p1;
	float t = ( - det - normal.Dot( p1 ) ) / dot;
	if( t < 0.0f || t > (p2-p1).Lenght() )
		return p1;
	return p1 + (dir*t);
}

inline void TrianglePX::Calculate()
{
	normal.Normalize();
	det = - normal.Dot( vertex[0] ); 
	
	wallnormals[0] = ( normal && (vertex[1]-vertex[0]) ).Versor();
	if( wallnormals[0].Dot( vertex[2]-vertex[0] ) < 0.0f ) wallnormals[0]	= 0.0f - wallnormals[0];
	wallnormals[1] = ( normal && (vertex[2]-vertex[1]) ).Versor();
	if( wallnormals[1].Dot( vertex[0]-vertex[1] ) < 0.0f ) wallnormals[1]	= 0.0f - wallnormals[1];
	wallnormals[2] = ( normal && (vertex[0]-vertex[2]) ).Versor();
	if( wallnormals[2].Dot( vertex[1]-vertex[2] ) < 0.0f ) wallnormals[2]	= 0.0f - wallnormals[2];
	
	walldet[0] = -wallnormals[0].Dot( vertex[0] );
	walldet[1] = -wallnormals[1].Dot( vertex[1] );
	walldet[2] = -wallnormals[2].Dot( vertex[2] );
	
	min = vertex[0];
	max = vertex[0];
	
	int i, j;
	for( i = 1; i < 3; i++ )
	{
		for( j = 0; j < 3; j++ )
		{
			if( min[j] > vertex[i][j] ) min[j] = vertex[i][j];
			if( max[j] < vertex[i][j] ) max[j] = vertex[i][j];
		}
	}
}

inline void TrianglePX::SetNormal( Vector src )
{
	normal = src;
	Calculate();
}

inline Vector TrianglePX::GetFromPointDeviationWithVector( Vector p, Vector direction__ )
{
	Vector dir = ( direction__ - ( normal * direction__.Dot( normal ) ) ).Versor();
	Vector cross;
	float t, dot;
	int i, j;
	for( i = 0; i < 3; ++i )
	{
		dot = dir.Dot( wallnormals[i] );
		if( dot > 0.0f )
		{
			t = ( - walldet[i] - wallnormals[i].Dot( dir ) ) / dot;
			cross = p + ( dir * t );
			for( j = 0; j < 3; ++j )
				if( j != i )
					if( wallnormals[j].Dot( cross )+walldet[j] <= 0.0001f )
						break;
			if( j < 3 )
				continue;
			else
				return cross;
		}
	}
	return p;
}


TrianglePX::TrianglePX()
{
	vertex[0].Set( 0.0f, 0.0f, 0.0f );
	vertex[1].Set( 0.0f, 0.0f, 0.0f );
	vertex[2].Set( 0.0f, 0.0f, 0.0f );
	normal.Set( 0.0f, 0.0f, 0.0f );
	det = 0.0f;
}

TrianglePX::~TrianglePX()
{
	vertex[0].Set( 0.0f, 0.0f, 0.0f );
	vertex[1].Set( 0.0f, 0.0f, 0.0f );
	vertex[2].Set( 0.0f, 0.0f, 0.0f );
	normal.Set( 0.0f, 0.0f, 0.0f );
	det = 0.0f;
}
