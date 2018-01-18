
class NameLine64
{
    public:
        char name[64];  
};

class EngineGraphicTriangleModel
{
    public:
        float tri[3][3];
        float image[3][2];
        unsigned int texture;   //iterator do kontenera z id textur
};


class EnginePhisicModel
{
    public:
        float tri[3][3];      //trojkat
        float normal[3];      //normalna danego trojkata
        float det;            //wskaŸnik przesuniêcia p³aszczyzny
        
        float sphere[3][3];      //punkty centrum sfer krawêdzi
        float radian[3];         //promien sfer obisanych na trojkacie
        float terrainresistance;    //opor powierzchni
        
        
        bool drawtexture;       //czy rysowac teksture?
        float image[3][2];
        unsigned int texture;   //iterator do kontenera z id textur
        
        void CalculateNormal();
        void CalculateVectorMul( float * vector1, float * vector2, float * output );
        void CalculateDet();
        void CalculateRadian( unsigned int number );
};

class EngineGraphicModel
{
    public:
        vector < EngineGraphicTriangleModel > triangles;
        
        vector < NameLine64 > texturefiles;
        vector < BITMAPINFOHEADER > bitmapInfoHeader;
        vector < unsigned char * > bitmapData;
        vector < unsigned int > texture;
        
        void Draw( float * position ){return;}
};



class EngineObject
{
    public:
        float bpos[3];  //poprzednia pozycja obiektu
        float pos[3];   //aktualna pozycja obiektu
        float speed[3]; //wektor predkosci
        float force[3]; //wektor sily
        
        float radian;   //promien sfery obiektu
        
        float mass;     //masa obiektu
        
        float lookxz;   //kat patrzenia w plaszczyznie y=0
        float looky;    //kat patrzenia w plaszczyznie prostopadlej do prostej lookxz+90.0f
    
        float density;         //gestosc otoczenia
        float gravitation;  //grawitacja dla obiektu
        
        float elastic;          //spreyzstosc obiektu
    
        unsigned int model;     //iterator do kontenera modelow obiektow
        unsigned int modeltype;  //typ modelu
        
        bool phisiccollision;       //obliczac czy kolizja z nim wyst¹pi³a?
        bool phisicmove;            //obliczac fizyke poruszania dla tego obiektu?
        bool phisicline;            //obliczac kolizje tego obiektu z linia?
        bool phisicsee;             //obliczac dla niego widzenie go?
        
        bool collision;         //czy kolizja w danej poprzedniej klatce wystepowala?
        
        void SetObject( float * possition, float masa, float radius, unsigned int idmodel );
        
        float * LookPoint();
        float LookX();
        float LookY();
        float LookZ();
        float LookXs();
        float LookYs();
        float LookZs();
        
        
        void SetPosX( float val )           {pos[0]=val;}
        void SetPosY( float val )           {pos[1]=val;}
        void SetPosZ( float val )           {pos[2]=val;}
        void AddPosX( float val )           {pos[0]+=val;}
        void AddPosY( float val )           {pos[1]+=val;}
        void AddPosZ( float val )           {pos[2]+=val;}
        float GetPosX()                     {return pos[0];}
        float GetPosY()                     {return pos[1];}
        float GetPosZ()                     {return pos[2];}
        
        
        void SetSpeedX( float val )         {speed[0]=val;}
        void SetSpeedY( float val )         {speed[1]=val;}
        void SetSpeedZ( float val )         {speed[2]=val;}
        void AddSpeedX( float val )         {speed[0]+=val;}
        void AddSpeedY( float val )         {speed[1]+=val;}
        void AddSpeedZ( float val )         {speed[2]+=val;}
        float GetSpeedX()                   {return speed[0];}
        float GetSpeedY()                   {return speed[1];}
        float GetSpeedZ()                   {return speed[2];}
        
        
        void SetForceX( float val )         {force[0]=val;}
        void SetForceY( float val )         {force[1]=val;}
        void SetForceZ( float val )         {force[2]=val;}
        void AddForceX( float val )         {force[0]+=val;}
        void AddForceY( float val )         {force[1]+=val;}
        void AddForceZ( float val )         {force[2]+=val;}
        float GetForceX()                   {return force[0];}
        float GetForceY()                   {return force[1];}
        float GetForceZ()                   {return force[2];}
        
        void SetMass( float val )           {mass=val;}
        float GetMass()                     {return mass;}
        
        void SetLookXZ( float val )         {lookxz=val;}
        float GetLookXZ()                   {return lookxz;}
        void SetLookY( float val )          {looky=val;}
        float GetLookY()                    {return looky;}
        
        void SetModel( unsigned int val )   {model=val;}
        unsigned int GetModel()             {return model;}
        
        void SetRadian( float val )         {radian=val;}
        float GetRadian()                   {return radian;}
        
        void SetDensity( float val )        {density=val;}
        float GetDensity()                  {return density;}
        
        void SetGravitation( float val )    {gravitation=val;}
        float GetGravitation()              {return gravitation;}
        
        EngineObject();
};



class EngineMap
{
    public:
        
        vector < NameLine64 > texturefiles;
        vector < BITMAPINFOHEADER > bitmapInfoHeader;
        vector < unsigned char * > bitmapData;
        vector < unsigned int > texture;
//        vector < unsigned char > texturesmooth;
        
        vector < EnginePhisicModel > tri;   //kontener trojkatow fizycznych
        vector < unsigned int > drawtri;
        
        float mapsize[3];       //wielkosc mapy [x,y,z]
        float mapmove[2];       //przesuniecie mapy [x,z]
        
        bool LoadMap( char *name );           //ladowanie mapy
        void SaveMap( char *name );             //zapisanie mapy
        void DrawMap();
};


class EngineEnvironmentModel
{
    public:
        float position[3];      //pozycja modelu
        unsigned int model;   //iterator do kontenera modelow
};

class EngineColliderTrigger
{
    public:
        vector < unsigned int > tri;
        vector < unsigned int > obj;
};




class EngineHumanoidGraphicModel
{
    public:
        float speed;    //speed of movement
        float angle;    //angle of looking xz
        float pos[3];   //possition
        bool attack;
        
        vector < EngineGraphicTriangleModel > triangles;
        
        vector < NameLine64 > texturefiles;
        vector < BITMAPINFOHEADER > bitmapInfoHeader;
        vector < unsigned char * > bitmapData;
        vector < unsigned int > textures;
        
        void Load( char * modelname );
        void Init();
        
        void Draw( float height, float movespeed );
        void DrawMove( float height, float movespeed );
        void DrawState(  float height );
};

class EngineCubeGraphicModel
{
    public:
        float speed;    //speed of movement
        float angle;    //angle of looking xz
        float pos[3];   //possition
        
        vector < EngineGraphicTriangleModel > triangles;
        
        vector < NameLine64 > texturefiles;
        vector < BITMAPINFOHEADER > bitmapInfoHeader;
        vector < unsigned char * > bitmapData;
        vector < unsigned int > textures;
        
        void Load( char * modelname );
        void Init();
        
        void Draw( float height, unsigned int id );
};









