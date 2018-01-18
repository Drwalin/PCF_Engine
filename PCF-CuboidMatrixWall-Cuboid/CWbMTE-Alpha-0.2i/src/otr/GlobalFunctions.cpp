


typedef void (APIENTRY * PFNGLBINDBUFFERPROC) (GLenum target, GLuint buffer);
typedef void (APIENTRY * PFNGLDELETEBUFFERSPROC) (GLsizei n, const GLuint *buffers);
typedef void (APIENTRY * PFNGLGENBUFFERSPROC) (GLsizei n, GLuint *buffers);
typedef void (APIENTRY * PFNGLBUFFERDATAPROC) (GLenum target, int size, const GLvoid *data, GLenum usage);
typedef void (APIENTRY * PFNGLCLIENTACTIVETEXTUREPROC) (GLenum texture);

PFNGLGENBUFFERSPROC glGenBuffers = NULL;					// VBO Name Generation Procedure
PFNGLBINDBUFFERPROC glBindBuffer = NULL;					// VBO Bind Procedure
PFNGLBUFFERDATAPROC glBufferData = NULL;					// VBO Data Loading Procedure
PFNGLDELETEBUFFERSPROC glDeleteBuffers = NULL;
PFNGLCLIENTACTIVETEXTUREPROC glClientActiveTexture = NULL;
//PFNGLDELETEBUFFERSARBPROC glDeleteBuffersARB = NULL;		// VBO Deletion Procedure

Engine * engineInstantiation = NULL;
SoundEngine * soundEngineInstantiation = NULL;

long long int frames_physic_loop = 0;
long long int cool_down_physic_fps = 0;
float GlobalPhisicTimeScale = 0.4f;

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


