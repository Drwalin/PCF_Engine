


LightSource::LightSource()
{
	origin.Set( 0.0f, 100.0f, 0.0f );
	direction.Set( 0.0, -1.0f, 0.0f );
	range = 1000.0f;
	angle = 90.0f;
}

LightSource::~LightSource()
{
	origin.Set( 0.0f, 0.0f, 0.0f );
	direction.Set( 0.0, 0.0f, 0.0f );
	range = 0.0f;
	angle = 0.0f;
}


