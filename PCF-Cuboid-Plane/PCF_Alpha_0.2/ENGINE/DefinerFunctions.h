


//Collision:
//void CollisionSeeLine( vector < unsigned int > * seeobjects, unsigned int ignore, float anglexz, float angley, float range, float * possition );
//bool __CollisionLineTriangles( unsigned int objouting, float * pos1, float * pos2, float * posout );
//unsigned int CollisionLineObiect( float anglexz, float angley, float range, unsigned int objouting, float * possition );
//bool CollisionObjectTriangle( unsigned int calculate, float x, float z, unsigned int time );
//float RadianFloatLinePoint( float * versor, float * possition );
//float RadianLinePoint( float * versor, float * possition );


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
//void RenderMap();
void Renderer();




//Inne
void EmptyFunctionVoidInt(unsigned int val){val;return;}
void EmptyFunctionVoidVoid(){return;}
//void EngineMainLoop();


//Engine enable/disable:
void EngineDisable( bool * Machine );
void EngineEnable( bool * Machine );
bool EngineGet( bool * Machine );
