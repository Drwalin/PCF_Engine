




class S3DGL
{
public:
    VMatrix matrix;
    
    float fov;  // k¹t widzenia
    float Z_near; // pocz¹tek
    float Z_far;  // koniec
    
    float depthbuffor[S3DGL_BUFFOR_X][S3DGL_BUFFOR_Y];
    char collorbuffor[S3DGL_BUFFOR_X][S3DGL_BUFFOR_Y][4];
    float collor[4];
    
    float x_;
    float y_;
    
public:
    inline int NullVersorPointOnPlane( Vector versor,
                                       Vector * dst );      // +
    inline int  PutPixel( char * color, Vector point );     // +
    
    inline void AddTriangle( Vector * pos );                // ...
    inline void AddTriangle( float x1, float y1, float z1,
                             float x2, float y2, float z2,
                             float x3, float y3, float z3 );// +
                             
    inline void AddLine( Vector * pos, char * color );      // -
    inline void AddLine( float x1, float y1, float z1,
                         float x2, float y2, float z2 );    // -
    
    inline void RotateX( float angle );                     // +
    inline void RotateY( float angle );                     // +
    inline void RotateZ( float angle );                     // +
    
    inline void Translate( float x, float y, float z );     // +
    inline void Translate( float * pos );                   // +
    inline void Translate( Vector pos );                    // +
    
    inline void Scale( float x, float y, float z );         // -
    inline void Scale( float * pos );                       // -
    inline void Scale( Vector pos );                        // -
    
    inline void SetMatrix( VMatrix src );                   // +
    
    inline void Calculate();                                // +/-, ...
    
    inline char * GetCollorBuffor();                        // +
    
    inline void Clear();                                    // +
    
    inline void SetColor();
    
    S3DGL();                                                // +
};

