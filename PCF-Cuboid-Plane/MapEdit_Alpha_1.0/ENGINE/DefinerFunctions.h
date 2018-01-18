


//Collision:
void CollisionSeeLine( vector < unsigned int > * seeobjects, unsigned int ignore, float anglexz, float angley, float range, float * possition );
bool __CollisionLineTriangles( unsigned int objouting, float * pos1, float * pos2, float * posout );
unsigned int CollisionLineObiect( float anglexz, float angley, float range, unsigned int objouting, float * possition );
bool CollisionObjectTriangle( unsigned int calculate, float x, float z, unsigned int time );
float RadianFloatLinePoint( float * versor, float * possition );
float RadianLinePoint( float * versor, float * possition );


//math:
float AngleXZ( float * point );
float AngleY( float * point );
float Xpoint( float ang );
float Ypoint( float ang );
float Zpoint( float ang );

//bmp:
unsigned char *LoadBitmapFileRGBA(char *filename, BITMAPINFOHEADER *bitmapInfoHeader);
unsigned char *LoadBitmapFileRGB(char *filename, BITMAPINFOHEADER *bitmapInfoHeader);


//Renderer:
void RenderMap();
void Renderer();




//Inne
void EmptyFunctionVoidInt(unsigned int val){val;return;}
void EmptyFunctionVoidVoid(){return;}
void EngineMainLoop();
void ClearObjects();


//Engine enable/disable:
void EngineDisable( bool * Machine );
void EngineEnable( bool * Machine );
bool EngineGet( bool * Machine );



void EmptyWallsFunction___( float * nullpoint, float backresize, float rightresize, float highresize, unsigned int texture );
void FloorFunction( float * nullpoint, float backresize, float rightresize, float highresize, unsigned int texture );
void FloorFunctionDraw( float * nullpoint, float backresize, float rightresize, float highresize, unsigned int texture );
void WallFunction( float * nullpoint, float backresize, float rightresize, float highresize, unsigned int texture );
void WallFunctionDraw( float * nullpoint, float backresize, float rightresize, float highresize, unsigned int texture );
void TriangleFunction( float * nullpoint, float backresize, float rightresize, float highresize, unsigned int texture );
void TriangleFunctionDraw( float * nullpoint, float backresize, float rightresize, float highresize, unsigned int texture );


void Ramp1Function( float * nullpoint, float backresize, float rightresize, float highresize, unsigned int texture );
void Ramp1FunctionDraw( float * nullpoint, float backresize, float rightresize, float highresize, unsigned int texture );
void Ramp2Function( float * nullpoint, float backresize, float rightresize, float highresize, unsigned int texture );
void Ramp2FunctionDraw( float * nullpoint, float backresize, float rightresize, float highresize, unsigned int texture );









