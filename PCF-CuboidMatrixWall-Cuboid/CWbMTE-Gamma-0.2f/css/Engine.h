
#ifndef ENGINE_H
#define ENGINE_H

/*
	Main engine class,
	that engine user
	(game-coder)
	has to know
*/

class Engine
{
public:
	
	char	WindowName			[256];
	int		WindowPossition		[2];
	int		WindowSize			[2];
	bool	WindowFullScreen;
	
	float GraphicFPS[3];
	float PhysicFPS[3];
	
	bool HideMouse;					// hiding mouse mode 
	
	bool GraphicThreadStopped;		// if graphic thread are stopped
	bool PhysicThreadStopped;		// if physic thread are stopped
	bool AskingPause;				// something asking about pause working engine
	bool AskingEnd;					// something asking about stop working engine
	bool OrderContinue;				// one of the threads can order that, to extort continue work
	
	bool RendererThreadWork;
	bool PhysicThreadWork;
	
	float GraphicTime;
	int BeginGraphicTime;
	int BeginPhisicTime;
	
	int MaximumNumberOfObjects;
	int MaximumNumberOfPhysicsThreads;
	unsigned char * ThreadsInfo;
	float FrameTime;
	
	unsigned int Physic__BegginTime;
	
	
	void CollisionLoop( int id );				// ...
	
	void Renderer();							// +/-
	void PhysicLoop();							// +/-
	void PhysicIteration();						// +/-
	void Reshape( int width, int height );		// +
	void FrameFunction( int arg );				// +
	
	Map map;
	bool deleteVBOs;
	
	bool UseVBO;
	
	vector < StaticGraphicModel * > GraphicModels;
private:
	vector < Texture * > textures;
	
	int ActualAddedIdLightnings;
	
	FunctionVoidFloat KeyboardFunction;
	FunctionVoidFloat GUIFunction;
	
	void CheckEngineThreadsInfoPhysicThread();
	void CheckEngineThreadsInfoRendererThread();
	
public:
	/*
		http://edu.pjwstk.edu.pl/wyklady/pro/scb/PRG2CPP_files/node68.html
	*/
	
	inline void GenerateShadowMap();
	inline void DeleteShadowMap();
	
	inline int SegmentCollision( Vector p1, Vector p2, PhysicModelStatic ** object, TrianglePX ** triangle, PhysicModelStatic * decludingobject, unsigned int rayTypeSrc );
	
	inline StaticGraphicModel * GetStaticModelHandle( char * src );
	inline int AddGraphicModel( char * name, unsigned int texture, Vector scale );
	inline void AddGraphicModelAsMap( const char * name );
	inline void Init( int * argc, char **argv );
	inline void BeginLoop();
	inline void DeleteVBOs();
	
	inline void SetUseVBO();
	inline void SetDontUseVBO();
	
	inline void AddSoundSource( char * src );
	inline void PlaySound( float volume, char * src );
	inline void PlaySound( float volume, int src );
	inline void PlaySound( char * src, Vector origin, float minDistance );
	inline void PlaySound( char * src, Vector origin );
	inline void PlaySound( int src, Vector origin, float minDistance );
	inline void PlaySound( int src, Vector origin );
	inline int GetSoundId( char * src );
	inline float GetVolume();
	inline void SetVolume( float src );
	
	inline void PauseAll();
	inline void ContinueAll();
	inline void UpdateWorld();
	inline void DestroyWorldInEngineThread();
	inline void DestroyWorldOutOfEngineThread();
	
	inline void SetKeybordFunction( FunctionVoidFloat src );
	inline void SetGUIFunction( FunctionVoidFloat src );
	
	inline void GenerateVBOs();
	inline int AddVBO( unsigned int texture );
	inline void SetLightningLimit( int size );
	inline void AddVertexToLastVBO( float x, float y, float z, float uvx, float uvy );
	inline void CreateTriangleWithLastThreeVertices();
	
	inline void AddPhysicTriangle( Vector a, Vector b, Vector c, Vector normal );
	
	inline PhysicModelStatic * Object( int id );
	inline PhysicModelStatic * BackObject();
	inline PhysicModelStatic * FrontObject();
	inline unsigned int ObjectsNumber();
	inline void AddObject();
	inline void AddObjects( int number );
	inline void DeleteObject( int id );
	
	inline void AddLightning( Vector begin_, Vector end_, float beginWidth_, float EndWidth_, float r1_, float g1_, float b1_, float r2_, float g2_, float b2_, int segments_, float branch_, float branchDensity_, float beginTime, float endTime );
	
	inline void AddTexture( char * src, int type );
	inline unsigned int TextureId( char * src );
	
	inline void AddGraphicObject( StaticGraphicModel * src, Vector pos, Vector rotate, float scale );
	
	inline void AddLightSource( Vector origin, Vector direction, float range, float angleInConeVertex, float lightDensity );
	
	Engine();										// +
	~Engine();										// +
};

#endif
