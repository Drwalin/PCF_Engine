
#include"..\Math\VMatrix.cpp"


#define S3DGL_BUFFOR_X 100
#define S3DGL_BUFFOR_Y 100


#include"S3DGL.h"


inline void S3DGL::Clear()
{
    //triangles.resize( 0 );
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
    Z_near =   0.1f;
    Z_far  = 100.0f;
    
    x_ = abs(tan( ( fov/2.0f) *M_PI/180.0f ) * Z_near);
    y_ = abs(x_ * (float(S3DGL_BUFFOR_Y)/float(S3DGL_BUFFOR_X)));
    
    float pixelcellsize = 0.2f*(2.0f*abs(x_))/float(S3DGL_BUFFOR_X);
    
    Clear();
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
    if( versor[2] == 0.0f )
        return -1;
    float t = Z_near / versor[2];
    (*dst) = ( versor * t );
    return 1;
}


inline int S3DGL::PutPixel( char * color, Vector point )
{
    /*
    x += abs(x_);
    x *= float(S3DGL_BUFFOR_X)/(abs(x_)*2.0f);
    if( x < 0 || x >= S3DGL_BUFFOR_X )
        return -1;
    y -= abs(y_);
    y *= float(S3DGL_BUFFOR_Y)/(abs(y_)*2.0f);
    y = -y;
    if( y < 0 || y >= S3DGL_BUFFOR_Y )
        return -1;
    depthbuffor[int(x)][int(y)] = depth;
    collorbuffor[int(x)][int(y)] = collor;
    return 1;
    */
    Vector out;
    
    
    
    
    
    
}










inline void S3DGL::AddTriangle( Vector * pos )
{
    Vector point[3];
    point[0] = matrix.GetVertex( pos[0] );
    point[1] = matrix.GetVertex( pos[1] );
    point[2] = matrix.GetVertex( pos[2] );
    
    // pozbycie siê trójk¹tów niemog¹cych byæ widzianymi
    if( point[0][2] < Z_near &&  point[1][2] < Z_near &&  point[2][2] < Z_near )
        return;
    if( point[0][2] > Z_far  &&  point[1][2] > Z_far  &&  point[2][2] > Z_far  )
        return;
    
    if( point[0][0] < -x_ &&  point[1][0] < -x_ &&  point[2][0] < -x_ )
        return;
    if( point[0][0] > x_  &&  point[1][0] > x_  &&  point[2][0] > x_  )
        return;
    
    if( point[0][1] < -y_ &&  point[1][1] < -y_ &&  point[2][1] < -y_ )
        return;
    if( point[0][1] > y_  &&  point[1][1] > y_  &&  point[2][1] > y_  )
        return;
    
    // wpisanie trójk¹ta do buforu koloru i g³êbokoœci
    Vector fast[6];         // do chwilowego przetrzymywania danych
    Vector versor[3];       // wersory kierunku: 0,1 - dwu krawêdzi trójk¹ta, 2 - wype³nienia trójk¹ta
    float maxradian[3];     // d³ugoœci wersorów
    float radian[3]={0,0,0};// aktualne po³o¿enie na powy¿szych wektorach kierunkowych
    float radianplus[3];    // zwiêkszanie po³o¿enia na powy¿szych wektorach
    Vector vectorpoint[3];  // aktualne punkty na powy¿szych wektoarach kierunkowych
    Vector pointonplane[3]; // punkty na p³aszczyŸnie Z=Z_near
    float v0divv1;          // d³ugoœæ wektora[0] / d³ugoœæ wektora[1]
    float pixelcellsize;    // rozmiar piksela na p³aszczyŸnie Z=Z_near
        
        //NullVersorPointOnPlane( triangles[number].point[0].Versor(), &vectortrianglevertex[0] )
        //NullVersorPointOnPlane( triangles[number].point[1].Versor(), &vectortrianglevertex[1] )
        //NullVersorPointOnPlane( triangles[number].point[2].Versor(), &vectortrianglevertex[2] )
        
        versor[0] = point[1] - point[0];
        versor[1] = point[2] - point[0];
        maxradian[0] = versor[0].Lenght();
        maxradian[1] = versor[1].Lenght();
        versor[0].Normalize();
        versor[1].Normalize();
        
        v0divv1 = maxradian[0] / maxradian[1];
        
        if( NullVersorPointOnPlane( point[0].Versor(), &fast[0] ) == -1 )
            fast[0] = point[0];
        if( NullVersorPointOnPlane( point[1].Versor(), &fast[1] ) == -1 )
            fast[1] = point[1];
        
        fast[3][0] = (fast[1] - fast[0]).Lenght();
        fast[3][1] = (fast[2] - fast[0]).Lenght();
        
        //if( fast[3][0] < fast[3][1] )
        //    fast[3][0] = fast[3][1];
        //if( fast[3][0] < fast[3][2] )
        //    fast[3][0] = fast[3][2];
        
        
        //pixelcellsize = (float(S3DGL_BUFFOR_X)/(abs(x_)*2.0f)) * fast[3][0];
        //pixelcellsize = float(S3DGL_BUFFOR_X) * fast[3][0]/(abs(x_)*2.0f);
        
        
        radianplus[0] = maxradian[0] / (float(S3DGL_BUFFOR_X) * fast[3][0]/(abs(x_)*2.0f));
        radianplus[1] = maxradian[1] / (float(S3DGL_BUFFOR_X) * fast[3][1]/(abs(x_)*2.0f));
        
        radian[1] = 0.0f;
        
        for( radian[0] = 0.0f; radian[0] < maxradian[0]; radian[0] += radianplus[0] )
        {
            vectorpoint[0] = (versor[0]*radian[0]) + point[0];
            PutPixel( collor, vectorpoint[0] );
            // w tym miejscu ma byæ obliczenie tej drugiej krawêdzi
            
            for( ; ( radian[1] < maxradian[1] ) && ( radian[1] < (v0divv1*radian[0]) ); radian[1] += radianplus[1] )
            {
                vectorpoint[1] = (versor[1]*radian[1]) + point[0];
                PutPixel( collor, vectorpoint[1] );
            }
            
            maxradian[2] = 
            if( NullVersorPointOnPlane( point[2].Versor(), &fast[2] ) == -1 )
                fast[2] = point[2];
            fast[3][2] = (vectorpoint[1] - vectorpoint[0]).Lenght();
            radianplus[2] = maxradian[2] / (float(S3DGL_BUFFOR_X) * fast[3][2]/(abs(x_)*2.0f));
            
            for( radian[2] = 0.0f; radian[2] < maxradian[2]; radian[2] += radianplus[2] )
            {
                vectorpoint[2] = (versor[2]*radian[2]) + vectorpoint[0];
                PutPixel( collor, vectorpoint[3] );
            }
            
            
            
            
            
            
            
            
            
    
    
}





