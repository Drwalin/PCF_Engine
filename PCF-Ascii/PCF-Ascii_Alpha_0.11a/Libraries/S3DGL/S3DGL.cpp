
#include"..\Math\VMatrix.cpp"


#define S3DGL_BUFFOR_X 400
#define S3DGL_BUFFOR_Y 300


#include"S3DGL.h"


inline void S3DGL::Clear()
{
    triangles.resize( 0 );
    matrix.InitEmpty();
    for( unsigned int x=0; x < S3DGL_BUFFOR_X; x++ ){
    for( unsigned int y=0; y < S3DGL_BUFFOR_Y; y++ ){
        depthbuffor[x][y] = -1.0f;
        collorbuffor[x][y] = 0;//char(' ');//0;
    }}
}

S3DGL::S3DGL()
{
    fov  =  90.0f;
    X_near =   0.1f;
    X_far  = 10000.0f;
    Clear();
}

inline void S3DGL::AddTriangle( float ** pos )
{
    Vector setvector[3];
    setvector[0] = matrix.GetVertex( SetVector( pos[0][0], pos[0][1], pos[0][2] ) );
    setvector[1] = matrix.GetVertex( SetVector( pos[1][0], pos[1][1], pos[1][2] ) );
    setvector[2] = matrix.GetVertex( SetVector( pos[2][0], pos[2][1], pos[2][2] ) );
    
    /*
    // pozbycie siê trójk¹tów niemog¹cych byæ widzianymi
    if( setvector[0][2] < X_near &&  setvector[1][2] < X_near &&  setvector[2][2] < X_near )
        return;
    if( setvector[0][2] > X_far  &&  setvector[1][2] > X_far  &&  setvector[2][2] > X_far  )
        return;
    
    float x_ = tan( ( fov/2.0f) *M_PI/180.0f ) * X_far;
    
    if( setvector[0][0] < -x_ &&  setvector[1][0] < -x_ &&  setvector[2][0] < -x_ )
        return;
    if( setvector[0][0] > x_  &&  setvector[1][0] > x_  &&  setvector[2][0] > x_  )
        return;
    
    
    float y_ = x_ * (float(S3DGL_BUFFOR_Y)/float(S3DGL_BUFFOR_X)); // tan( ((float(S3DGL_BUFFOR_Y)/float(S3DGL_BUFFOR_X)) *fov/2.0f) *M_PI/180.0f ) * far;
    
    if( setvector[0][1] < -y_ &&  setvector[1][1] < -y_ &&  setvector[2][1] < -y_ )
        return;
    if( setvector[0][1] > y_  &&  setvector[1][1] > y_  &&  setvector[2][1] > y_  )
        return;
    */
    
    // dodanie trójk¹ta je¿eli mo¿e byæ widziany przez kamere
    triangles.resize( triangles.size()+1 );
    triangles[ triangles.size()-1 ].Set( setvector );
}

inline void S3DGL::AddTriangle( Vector * pos )
{
    Vector setvector[3];
    setvector[0] = matrix.GetVertex( pos[0] );
    setvector[1] = matrix.GetVertex( pos[1] );
    setvector[2] = matrix.GetVertex( pos[2] );
    
    // pozbycie siê trójk¹tów niemog¹cych byæ widzianymi
    if( setvector[0][2] < X_near &&  setvector[1][2] < X_near &&  setvector[2][2] < X_near )
        return;
    if( setvector[0][2] > X_far  &&  setvector[1][2] > X_far  &&  setvector[2][2] > X_far  )
        return;
    
    float x_ = tan( ( fov/2.0f) *M_PI/180.0f ) * X_far;
    
    if( setvector[0][0] < -x_ &&  setvector[1][0] < -x_ &&  setvector[2][0] < -x_ )
        return;
    if( setvector[0][0] > x_  &&  setvector[1][0] > x_  &&  setvector[2][0] > x_  )
        return;
    
    
    float y_ = x_ * (float(S3DGL_BUFFOR_Y)/float(S3DGL_BUFFOR_X)); // tan( ((float(S3DGL_BUFFOR_Y)/float(S3DGL_BUFFOR_X)) *fov/2.0f) *M_PI/180.0f ) * far;
    
    if( setvector[0][1] < -y_ &&  setvector[1][1] < -y_ &&  setvector[2][1] < -y_ )
        return;
    if( setvector[0][1] > y_  &&  setvector[1][1] > y_  &&  setvector[2][1] > y_  )
        return;
    
    triangles.resize( triangles.size()+1 );
    triangles[ triangles.size()-1 ].Set( setvector );
}

inline void S3DGL::AddTriangle( float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3 )
{
    Vector v_set[3];
    v_set[0].Set( x1, y1, z1 );
    v_set[1].Set( x2, y2, z2 );
    v_set[2].Set( x3, y3, z3 );
    AddTriangle( v_set );
}

inline void S3DGL::RotateX( float angle )
{
    matrix.RotateX( angle );
}

inline void S3DGL::RotateY( float angle )
{
    matrix.RotateY( angle );
}

inline void S3DGL::RotateZ( float angle )
{
    matrix.RotateZ( angle );
}
    
inline void S3DGL::Translate( float x, float y, float z )
{
    matrix.Translate( SetVector( x, y, z ) );
}

inline void S3DGL::Translate( float * pos )
{
    matrix.Translate( SetVector( pos[0], pos[1], pos[2] ) );
}

inline void S3DGL::Translate( Vector movevector )
{
    matrix.Translate( movevector );
}

inline void S3DGL::SetMatrix( VMatrix src )
{
    matrix = src;
}





inline char * S3DGL::GetCollorBuffor()
{
    //return (*collorbuffor[0][0]);
    return NULL;
}





inline int S3DGL::NullVersorPointOnPlane( Vector versor, Vector * dst )
{
    //float dup = 10.0f / versor[2];
    
    
    float det = ( 1.0f * X_near );
    float t = ( det ) / ( versor[2] );
    if( t < X_near )
        return -1;
    (*dst) = ( versor * t );
    return 1;
}


inline int S3DGL::PutPixel( char collor, float depth, float x, float y, float x_, float y_ )
{
    x += abs(x_);
    x *= float(S3DGL_BUFFOR_X)/(abs(x_)*2.0f);
    if( x < 0 || x >= S3DGL_BUFFOR_X )
        return -1;
    y -= abs(y_);
    y *= float(S3DGL_BUFFOR_Y)/(abs(y_)*2.0f);
    y = -y;
    if( y < 0 || y >= S3DGL_BUFFOR_Y )
        return -1;
    //depthbuffor[int(x)][int(y)] = depth;
    collorbuffor[int(x)][int(y)] = collor;
    return 1;
}





inline void S3DGL::Calculate()
{
    float x_ = abs(tan( ( fov/2.0f) *M_PI/180.0f ) * X_near);
    float y_ = abs(x_ * (float(S3DGL_BUFFOR_Y)/float(S3DGL_BUFFOR_X)));
    float px, py;           // po³o¿enie punktu na p³aszczyŸnie Z=near
    float radian;           // odleg³oœæ liczonego piksela od punktu A
    float maxradian;        // odleg³oœæ od punktu A do punktu B
    float pixelcellsize;    // rozmiar piksela na p³aszczyŸnie Z=near
    Vector lineversor;      // wersor kierunkowy danej krawêdzi rysowanego trójk¹ta
    Vector vectortrianglevertex[3];
    
    pixelcellsize = 0.2f*(2.0f*abs(x_))/float(S3DGL_BUFFOR_X);
    
    for( unsigned int number = 0; number < triangles.size(); number++ )
    {
        //vectortrianglevertex[0] = triangles[number].point[0];
        //vectortrianglevertex[1] = triangles[number].point[1];
        //vectortrianglevertex[2] = triangles[number].point[2];
        
        if( NullVersorPointOnPlane( triangles[number].point[0].Versor(), &vectortrianglevertex[0] ) == -1 )
            continue;
        if( NullVersorPointOnPlane( triangles[number].point[1].Versor(), &vectortrianglevertex[1] ) == -1 )
            continue;
        if( NullVersorPointOnPlane( triangles[number].point[2].Versor(), &vectortrianglevertex[2] ) == -1 )
            continue;
        
        
        //PutPixel( '#', -1, vectortrianglevertex[0][0], vectortrianglevertex[0][1], x_, y_ );
        //PutPixel( '#', -1, vectortrianglevertex[1][0], vectortrianglevertex[1][1], x_, y_ );
        //PutPixel( '#', -1, vectortrianglevertex[2][0], vectortrianglevertex[2][1], x_, y_ );
        
        
        lineversor = vectortrianglevertex[1] - vectortrianglevertex[0]; //SetVector( vectortrianglevertex[0], vectortrianglevertex[1] );
        maxradian = lineversor.Lenght();
        lineversor.Normalize();
        for( radian = 0.0f; radian <= maxradian; radian += pixelcellsize )
        {
            px = ( (lineversor[0] * radian) + vectortrianglevertex[0][0] );
            if( px < -x_ || px > x_ )
                continue;
            
            py = ( (lineversor[1] * radian) + vectortrianglevertex[0][1] );
            if( py < -y_ || py > y_ )
                continue;
            
            PutPixel( '#', -1, px, py, x_, y_ );
        }
        
        lineversor = vectortrianglevertex[2] - vectortrianglevertex[1]; //(SetVector( vectortrianglevertex[1], vectortrianglevertex[2] ));
        maxradian = lineversor.Lenght();
        lineversor.Normalize();
        for( radian = 0.0f; radian <= maxradian; radian += pixelcellsize )
        {
            px = ( (lineversor[0] * radian) + vectortrianglevertex[1][0] );
            if( px < -x_ || px > x_ )
                continue;
            
            py = ( (lineversor[1] * radian) + vectortrianglevertex[1][1] );
            if( py < -y_ || py > y_ )
                continue;
            
            PutPixel( '#', -1, px, py, x_, y_ );
        }
        
        lineversor = vectortrianglevertex[2] - vectortrianglevertex[0]; //(SetVector( vectortrianglevertex[0], vectortrianglevertex[2] ));
        maxradian = lineversor.Lenght();
        lineversor.Normalize();
        for( radian = 0.0f; radian <= maxradian; radian += pixelcellsize )
        {
            px = ( (lineversor[0] * radian) + vectortrianglevertex[0][0] );
            if( px < -x_ || px > x_ )
                continue;
            
            py = ( (lineversor[1] * radian) + vectortrianglevertex[0][1] );
            if( py < -y_ || py > y_ )
                continue;
            
            PutPixel( '#', -1, px, py, x_, y_ );
        }
        
        
        
        
    }
}




