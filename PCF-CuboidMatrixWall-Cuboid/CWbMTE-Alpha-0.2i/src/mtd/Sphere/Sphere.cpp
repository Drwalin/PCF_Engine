


inline Vector Sphere::MaxWithVector( Vector dst )
{
	return (dst.Versor() * radian) + pos;
}

inline Vector Sphere::ClosesPoint( Vector dst )
{
	Vector a = (dst-pos);
	float lenght = a.Lenght();
	return (lenght < radian) ? (a.Versor() * lenght) + pos : (a.Versor() * radian) + pos;
}
	
Sphere::Sphere()
{
	pos;
	vel = NULL;
	force = NULL;
	resistanceforce = NULL;
	
	mass = 75.0f;
	radian = 0.25f;
	
	CollisionSide = false;
}

Sphere::~Sphere()
{
	pos;
	vel = NULL;
	force = NULL;
	resistanceforce = NULL;
	
	mass = 0.0f;
	radian = 0.25f;
	
	CollisionSide = false;
}


