


Engine * engineInstantiation = NULL;
long long int frames_physic_loop = 0;
long long int cool_down_physic_fps = 0;
float GlobalPhisicTimeScale = 1.0f;

void Reshape__( int width, int height )
{
	engineInstantiation -> Reshape( width, height );
}

void Renderer__()
{
	engineInstantiation -> Renderer();
}

void FrameFunction__( int arg )
{
	engineInstantiation -> FrameFunction( arg );
}

__cdecl void PhisicLoop__( void * args )
{
	engineInstantiation -> PhisicLoop();
	_endthread();
}

inline void SetEngineInstantiation( Engine * src )
{
	engineInstantiation = src;
}

__cdecl void PhisicObjectCollision__( void * args )
{
	int id = *((int*)(args));
	engineInstantiation -> CollisionLoop( id );
	_endthread();
}


