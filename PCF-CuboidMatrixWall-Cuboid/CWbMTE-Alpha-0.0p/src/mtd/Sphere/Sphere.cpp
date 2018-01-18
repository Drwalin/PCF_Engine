


inline Vector Sphere::MaxWithVector( Vector dst )
{
	return (dst.Versor() * radian) + pos;
}

inline Vector Sphere::ClosesPoint( Vector dst )
{
	Vector a = (dst-pos);
	float lenght = a.Lenght();
	return (lenght < radian) ? dst : (a.Versor() * radian) + pos;
}
	
Sphere::Sphere()
{
	pos.Set( 0.0f, 0.0f, 0.0f );
	vel.Set( 0.0f, 0.0f, 0.0f );
	force.Set( 0.0f, 0.0f, 0.0f );
	resistanceforce.Set( 0.0f, 0.0f, 0.0f );
	
	mass = 75.0f;
	radian = 0.25f;
	
	Collision = false;
}

Sphere::~Sphere()
{
	pos.Set( 0.0f, 0.0f, 0.0f );
	vel.Set( 0.0f, 0.0f, 0.0f );
	force.Set( 0.0f, 0.0f, 0.0f );
	resistanceforce.Set( 0.0f, 0.0f, 0.0f );
	
	mass = 0.1f;
	radian = 0.25f;
	
	Collision = false;
}


