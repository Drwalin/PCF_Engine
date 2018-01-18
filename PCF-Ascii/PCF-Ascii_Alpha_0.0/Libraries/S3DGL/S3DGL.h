




class S3DGL
{
private:
    class Triangle3D
    {
    public:
        Vector point[3];
        inline void Set( Vector * tri ){
            //point[0] = tri[0]; point[1] = tri[1]; point[2] = tri[2];
            point[0][0]=tri[0][0]; point[0][1]=tri[0][1]; point[0][2]=tri[0][2];
            point[1][0]=tri[1][0]; point[1][1]=tri[1][1]; point[1][2]=tri[1][2];
            point[2][0]=tri[2][0]; point[2][1]=tri[2][1]; point[2][2]=tri[2][2];
        }
        Triangle3D(){
            point[0][0]=0.0f; point[0][1]=0.0f; point[0][2]=0.0f;
            point[1][0]=0.0f; point[1][1]=0.0f; point[1][2]=0.0f;
            point[2][0]=0.0f; point[2][1]=0.0f; point[2][2]=0.0f;
        }
    };
public:
    float fov;  // k¹t widzenia
    float X_near; // pocz¹tek
    float X_far;  // koniec
    vector < Triangle3D > triangles;
    VMatrix matrix;
    float depthbuffor[S3DGL_BUFFOR_X][S3DGL_BUFFOR_Y];
    char collorbuffor[S3DGL_BUFFOR_X][S3DGL_BUFFOR_Y];
public:
    inline int NullVersorPointOnPlane( //unsigned int id,
                                        Vector versor,
                                        Vector * dst );     // +
    inline int  PutPixel( char collor, float depth, float x,
                          float y, float x_, float y_ );    // +
    
    inline void AddTriangle( float ** pos );                // +
    inline void AddTriangle( Vector * pos );               // +
    inline void AddTriangle( float x1, float y1, float z1,
                             float x2, float y2, float z2,
                             float x3, float y3, float z3 );// +
    
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
    
    inline char * GetCollorBuffor();                       // +
    
    inline void Clear();                                    // +
    
    S3DGL();                                                // +
};

