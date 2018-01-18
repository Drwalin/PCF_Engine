


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

Engine * engineInstantiation = NULL;
SoundEngine * soundEngineInstantiation = NULL;

long long int frames_physic_loop = 0;
long long int cool_down_physic_fps = 0;
float GlobalPhysicTimeScale = 0.21f;

void Reshape__( int width, int height );
void Renderer__();
void FrameFunction__( int arg );
__cdecl void PhysicLoop__( void * args );
inline void SetEngineInstantiation( Engine * src );
__cdecl void PhysicObjectCollision__( void * args );


