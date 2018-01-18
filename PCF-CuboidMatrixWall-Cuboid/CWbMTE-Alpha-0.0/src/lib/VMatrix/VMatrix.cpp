
//#define M_PI 3.14159f

#include"Vector.hpp"

#include"VMatrix.h"



// Funkcje inicjuj¹ce:

inline VMatrix VMatrix::SetMatrix(          // podstawia do tablicy podane argumenty
        float src00, float src01, float src02, float src03,
        float src10, float src11, float src12, float src13,
        float src20, float src21, float src22, float src23,
        float src30, float src31, float src32, float src33 )
{
    m[0][0] = src00; m[0][1] = src01; m[0][2] = src02; m[0][3] = src03;
    m[1][0] = src10; m[1][1] = src11; m[1][2] = src12; m[1][3] = src13;
    m[2][0] = src20; m[2][1] = src21; m[2][2] = src22; m[2][3] = src23;
    m[3][0] = src30; m[3][1] = src31; m[3][2] = src32; m[3][3] = src33;
    return *this;
}

inline VMatrix VMatrix::SetMatrix( VMatrix src )     // podstawia macierz pod macierz
{
    m[0][0] = src.m[0][0]; m[0][1] = src.m[0][1]; m[0][2] = src.m[0][2]; m[0][3] = src.m[0][3];
    m[1][0] = src.m[1][0]; m[1][1] = src.m[1][1]; m[1][2] = src.m[1][2]; m[1][3] = src.m[1][3];
    m[2][0] = src.m[2][0]; m[2][1] = src.m[2][1]; m[2][2] = src.m[2][2]; m[2][3] = src.m[2][3];
    m[3][0] = src.m[3][0]; m[3][1] = src.m[3][1]; m[3][2] = src.m[3][2]; m[3][3] = src.m[3][3];
    return *this;
}

inline VMatrix VMatrix::SetMatrix( float **src )     // podstawia macierz pod macierz
{
    m[0][0] = src[0][0]; m[0][1] = src[0][1]; m[0][2] = src[0][2]; m[0][3] = src[0][3];
    m[1][0] = src[1][0]; m[1][1] = src[1][1]; m[1][2] = src[1][2]; m[1][3] = src[1][3];
    m[2][0] = src[2][0]; m[2][1] = src[2][1]; m[2][2] = src[2][2]; m[2][3] = src[2][3];
    m[3][0] = src[3][0]; m[3][1] = src[3][1]; m[3][2] = src[3][2]; m[3][3] = src[3][3];
    return *this;
}

inline VMatrix VMatrix::InitEmpty()     // inicjiuje pust¹ macierz
{
    SetMatrix(
                1.0f, 0.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 0.0f, 1.0f );
    return *this;
}





// Obs³uga operatorów:

inline VMatrix VMatrix::operator += ( const Vector &src )       // translacja wektorem
{
    VMatrix out;
    out.m[0][3] += src.vector[0];
    out.m[1][3] += src.vector[1];
    out.m[2][3] += src.vector[2];
    return out;
}

inline VMatrix VMatrix::operator *  ( const VMatrix &src )const // zwraca pomno¿on¹ aktualn¹ przez podan¹ macierz
{
    VMatrix out;
    out.SetMatrix(
                    (m[0][0]*src.m[0][0]) + (m[0][1]*src.m[1][0]) + (m[0][2]*src.m[2][0]) + (m[0][3]*src.m[3][0]),
                    (m[0][0]*src.m[0][1]) + (m[0][1]*src.m[1][1]) + (m[0][2]*src.m[2][1]) + (m[0][3]*src.m[3][1]),
                    (m[0][0]*src.m[0][2]) + (m[0][1]*src.m[1][2]) + (m[0][2]*src.m[2][2]) + (m[0][3]*src.m[3][2]),
                    (m[0][0]*src.m[0][3]) + (m[0][1]*src.m[1][3]) + (m[0][2]*src.m[2][3]) + (m[0][3]*src.m[3][3]),
                    
                    (m[1][0]*src.m[0][0]) + (m[1][1]*src.m[1][0]) + (m[1][2]*src.m[2][0]) + (m[1][3]*src.m[3][0]),
                    (m[1][0]*src.m[0][1]) + (m[1][1]*src.m[1][1]) + (m[1][2]*src.m[2][1]) + (m[1][3]*src.m[3][1]),
                    (m[1][0]*src.m[0][2]) + (m[1][1]*src.m[1][2]) + (m[1][2]*src.m[2][2]) + (m[1][3]*src.m[3][2]),
                    (m[1][0]*src.m[0][3]) + (m[1][1]*src.m[1][3]) + (m[1][2]*src.m[2][3]) + (m[1][3]*src.m[3][3]),
                    
                    (m[2][0]*src.m[0][0]) + (m[2][1]*src.m[1][0]) + (m[2][2]*src.m[2][0]) + (m[2][3]*src.m[3][0]),
                    (m[2][0]*src.m[0][1]) + (m[2][1]*src.m[1][1]) + (m[2][2]*src.m[2][1]) + (m[2][3]*src.m[3][1]),
                    (m[2][0]*src.m[0][2]) + (m[2][1]*src.m[1][2]) + (m[2][2]*src.m[2][2]) + (m[2][3]*src.m[3][2]),
                    (m[2][0]*src.m[0][3]) + (m[2][1]*src.m[1][3]) + (m[2][2]*src.m[2][3]) + (m[2][3]*src.m[3][3]),
                    
                    (m[3][0]*src.m[0][0]) + (m[3][1]*src.m[1][0]) + (m[3][2]*src.m[2][0]) + (m[3][3]*src.m[3][0]),
                    (m[3][0]*src.m[0][1]) + (m[3][1]*src.m[1][1]) + (m[3][2]*src.m[2][1]) + (m[3][3]*src.m[3][1]),
                    (m[3][0]*src.m[0][2]) + (m[3][1]*src.m[1][2]) + (m[3][2]*src.m[2][2]) + (m[3][3]*src.m[3][2]),
                    (m[3][0]*src.m[0][3]) + (m[3][1]*src.m[1][3]) + (m[3][2]*src.m[2][3]) + (m[3][3]*src.m[3][3]) );
    return out;
}

inline VMatrix VMatrix::operator *= ( const VMatrix &src )      // mno¿y aktualn¹ pzez podan¹ macierz
{
    VMatrix out;
    out.SetMatrix(
                    (m[0][0]*src.m[0][0]) + (m[0][1]*src.m[1][0]) + (m[0][2]*src.m[2][0]) + (m[0][3]*src.m[3][0]),
                    (m[0][0]*src.m[0][1]) + (m[0][1]*src.m[1][1]) + (m[0][2]*src.m[2][1]) + (m[0][3]*src.m[3][1]),
                    (m[0][0]*src.m[0][2]) + (m[0][1]*src.m[1][2]) + (m[0][2]*src.m[2][2]) + (m[0][3]*src.m[3][2]),
                    (m[0][0]*src.m[0][3]) + (m[0][1]*src.m[1][3]) + (m[0][2]*src.m[2][3]) + (m[0][3]*src.m[3][3]),
                    
                    (m[1][0]*src.m[0][0]) + (m[1][1]*src.m[1][0]) + (m[1][2]*src.m[2][0]) + (m[1][3]*src.m[3][0]),
                    (m[1][0]*src.m[0][1]) + (m[1][1]*src.m[1][1]) + (m[1][2]*src.m[2][1]) + (m[1][3]*src.m[3][1]),
                    (m[1][0]*src.m[0][2]) + (m[1][1]*src.m[1][2]) + (m[1][2]*src.m[2][2]) + (m[1][3]*src.m[3][2]),
                    (m[1][0]*src.m[0][3]) + (m[1][1]*src.m[1][3]) + (m[1][2]*src.m[2][3]) + (m[1][3]*src.m[3][3]),
                    
                    (m[2][0]*src.m[0][0]) + (m[2][1]*src.m[1][0]) + (m[2][2]*src.m[2][0]) + (m[2][3]*src.m[3][0]),
                    (m[2][0]*src.m[0][1]) + (m[2][1]*src.m[1][1]) + (m[2][2]*src.m[2][1]) + (m[2][3]*src.m[3][1]),
                    (m[2][0]*src.m[0][2]) + (m[2][1]*src.m[1][2]) + (m[2][2]*src.m[2][2]) + (m[2][3]*src.m[3][2]),
                    (m[2][0]*src.m[0][3]) + (m[2][1]*src.m[1][3]) + (m[2][2]*src.m[2][3]) + (m[2][3]*src.m[3][3]),
                    
                    (m[3][0]*src.m[0][0]) + (m[3][1]*src.m[1][0]) + (m[3][2]*src.m[2][0]) + (m[3][3]*src.m[3][0]),
                    (m[3][0]*src.m[0][1]) + (m[3][1]*src.m[1][1]) + (m[3][2]*src.m[2][1]) + (m[3][3]*src.m[3][1]),
                    (m[3][0]*src.m[0][2]) + (m[3][1]*src.m[1][2]) + (m[3][2]*src.m[2][2]) + (m[3][3]*src.m[3][2]),
                    (m[3][0]*src.m[0][3]) + (m[3][1]*src.m[1][3]) + (m[3][2]*src.m[2][3]) + (m[3][3]*src.m[3][3]) );
    SetMatrix( out );
    return *this;
}

inline VMatrix VMatrix::operator *  ( const float  &src )const  // pomnozenie kazdej sk³adowej macierzy przez skalar
{
    VMatrix out;
    out.m[0][0] = m[0][0] * src;    out.m[0][1] = m[0][1] * src;    out.m[0][2] = m[0][2] * src;    out.m[0][3] = m[0][3] * src;
    out.m[1][0] = m[1][0] * src;    out.m[1][1] = m[1][1] * src;    out.m[1][2] = m[1][2] * src;    out.m[1][3] = m[1][3] * src;
    out.m[2][0] = m[2][0] * src;    out.m[2][1] = m[2][1] * src;    out.m[2][2] = m[2][2] * src;    out.m[2][3] = m[2][3] * src;
    out.m[3][0] = m[3][0] * src;    out.m[3][1] = m[3][1] * src;    out.m[3][2] = m[3][2] * src;    out.m[3][3] = m[3][3] * src;
    return out;
}

inline VMatrix VMatrix::operator *= ( const float  &src )       // pomnozenie kazdej sk³adowej macierzy przez skalar
{
    m[0][0] *= src;    m[0][1] *= src;    m[0][2] *= src;    m[0][3] *= src;
    m[1][0] *= src;    m[1][1] *= src;    m[1][2] *= src;    m[1][3] *= src;
    m[2][0] *= src;    m[2][1] *= src;    m[2][2] *= src;    m[2][3] *= src;
    m[3][0] *= src;    m[3][1] *= src;    m[3][2] *= src;    m[3][3] *= src;
    return *this;
}


// Obs³uga obrotów, translacji, skalowañ na macierzach

inline VMatrix VMatrix::Translate( Vector src )                    // translacja, przesuniêcie ( X, Y, Z ) o sk³adowe wektora src( x, y, z )
{
    VMatrix out;
    out.SetMatrix( 1.0f, 0.0f, 0.0f, src[0],
                   0.0f, 1.0f, 0.0f, src[1],
                   0.0f, 0.0f, 1.0f, src[2],
                   0.0f, 0.0f, 0.0f, 1.0f );
    
    (*this) = (*this) * out;
    return *this;
}

inline VMatrix VMatrix::RotateX( float angle )                     // obrócenie o k¹t angle w kierunku przeciwnym o kierunku ruchu wskazówek zegara wokó³ osi X
{
    VMatrix out;
    out.SetMatrix(   1.0f,                   0.0f,                    0.0f,   0.0f,
                     0.0f, cos(angle*3.14159f/180.0f), -sin(angle*3.14159f/180.0f),   0.0f,
                     0.0f, sin(angle*3.14159f/180.0f),  cos(angle*3.14159f/180.0f),   0.0f,
                     0.0f,                   0.0f,                    0.0f,   1.0f );
    (*this) = (*this) * out;
    return *this;
}

inline VMatrix VMatrix::RotateY( float angle )                     // obrócenie o k¹t angle w kierunku przeciwnym o kierunku ruchu wskazówek zegara wokó³ osi Y
{
    VMatrix out;
    out.SetMatrix(  cos(angle*3.14159f/180.0f),    0.0f, sin(angle*3.14159f/180.0f),   0.0f,
                                      0.0f,    1.0f,                   0.0f,   0.0f,
                   -sin(angle*3.14159f/180.0f),    0.0f, cos(angle*3.14159f/180.0f),   0.0f,
                                      0.0f,    0.0f,                   0.0f,   1.0f );
    (*this) = (*this) * out;
    return *this;
}

inline VMatrix VMatrix::RotateZ( float angle )                     // obrócenie o k¹t angle w kierunku przeciwnym o kierunku ruchu wskazówek zegara wokó³ osi Z
{
    VMatrix out;
    out.SetMatrix( cos(angle*3.14159f/180.0f), -sin(angle*3.14159f/180.0f),   0.0f,   0.0f,
                   sin(angle*3.14159f/180.0f),  cos(angle*3.14159f/180.0f),   0.0f,   0.0f,
                   0.0f,                                      0.0f,   1.0f,   0.0f,
                   0.0f,                                      0.0f,   0.0f,   1.0f );
    (*this) = (*this) * out;
    return *this;
}

inline VMatrix VMatrix::Scale( Vector src )                        // sklowanie ( X, Y, Z ) o sk³adowe wektora src( x, y, z )
{
    VMatrix out;
    out.SetMatrix( src[0],   0.0f,   0.0f,   0.0f,
                     0.0f, src[1],   0.0f,   0.0f,
                     0.0f,   0.0f, src[2],   0.0f,
                     0.0f,   0.0f,   0.0f,   1.0f );
    (*this) *= out;
    return *this;
}

inline VMatrix VMatrix::Scale( float src )                         // sklowanie ( X, Y, Z ) o skalar
{
    VMatrix out;
    out.SetMatrix(  src, 0.0f, 0.0f, 0.0f,
                   0.0f,  src, 0.0f, 0.0f,
                   0.0f, 0.0f,  src, 0.0f,
                   0.0f, 0.0f, 0.0f, 1.0f );
    (*this) *= out;
    return *this;
}

inline VMatrix VMatrix::GetReverse()                            // zwrócenie odwrotnej macierzy
{
    VMatrix out=(*this);
    out.SetMatrix(
        m[1][1]*m[2][2]*m[3][3] +
        m[1][2]*m[2][3]*m[3][1] +
        m[1][3]*m[2][1]*m[3][2] -
        m[1][1]*m[2][3]*m[3][2] -
        m[1][2]*m[2][1]*m[3][3] -
        m[1][3]*m[2][2]*m[3][1],
        
        m[0][1]*m[2][3]*m[3][2] +
        m[0][2]*m[2][1]*m[3][3] +
        m[0][3]*m[2][2]*m[3][1] -
        m[0][1]*m[2][2]*m[3][3] -
        m[0][2]*m[2][3]*m[3][1] -
        m[0][3]*m[2][1]*m[3][2],

        m[0][1]*m[1][2]*m[3][3]+
        m[0][2]*m[1][3]*m[3][1]+
        m[0][3]*m[1][1]*m[3][2]-
        m[0][1]*m[1][3]*m[3][2]-
        m[0][2]*m[1][1]*m[3][3]-
        m[0][3]*m[1][2]*m[3][1],

        m[0][1]*m[1][3]*m[2][2]+
        m[0][2]*m[1][1]*m[2][3]+
        m[0][3]*m[1][2]*m[2][1]-
        m[0][1]*m[1][2]*m[2][3]-
        m[0][2]*m[1][3]*m[2][1]-
        m[0][3]*m[1][1]*m[2][2],

        m[1][0]*m[2][3]*m[3][2]+
        m[1][2]*m[2][0]*m[3][3]+
        m[1][3]*m[2][2]*m[3][0]-
        m[1][0]*m[2][2]*m[3][3]-
        m[1][2]*m[2][3]*m[3][0]-
        m[1][3]*m[2][0]*m[3][2],

        m[0][0]*m[2][2]*m[3][3]+
        m[0][2]*m[2][3]*m[3][0]+
        m[0][3]*m[2][0]*m[3][2]-
        m[0][0]*m[2][3]*m[3][2]-
        m[0][2]*m[2][0]*m[3][3]-
        m[0][3]*m[2][2]*m[3][0],

        m[0][0]*m[1][3]*m[3][2]+
        m[0][2]*m[1][0]*m[3][3]+
        m[0][3]*m[1][2]*m[3][0]-
        m[0][0]*m[1][2]*m[3][3]-
        m[0][2]*m[1][3]*m[3][0]-
        m[0][3]*m[1][0]*m[3][2],

        m[0][0]*m[1][2]*m[2][3]+
        m[0][2]*m[1][3]*m[2][0]+
        m[0][3]*m[1][0]*m[2][2]-
        m[0][0]*m[1][3]*m[2][2]-
        m[0][2]*m[1][0]*m[2][3]-
        m[0][3]*m[1][2]*m[2][0],

        m[1][0]*m[2][1]*m[3][3]+
        m[1][1]*m[2][3]*m[3][0]+
        m[1][3]*m[2][0]*m[3][1]-
        m[1][0]*m[2][3]*m[3][1]-
        m[1][1]*m[2][0]*m[3][3]-
        m[1][3]*m[2][1]*m[3][0],

        m[0][0]*m[2][3]*m[3][1]+
        m[0][1]*m[2][0]*m[3][3]+
        m[0][3]*m[2][1]*m[3][0]-
        m[0][0]*m[2][1]*m[3][3]-
        m[0][1]*m[2][3]*m[3][0]-
        m[0][3]*m[2][0]*m[3][1],

        m[0][0]*m[1][1]*m[3][3]+
        m[0][1]*m[1][3]*m[3][0]+
        m[0][3]*m[1][0]*m[3][1]-
        m[0][0]*m[1][3]*m[3][1]-
        m[0][1]*m[1][0]*m[3][3]-
        m[0][3]*m[1][1]*m[3][0],

        m[0][0]*m[1][3]*m[2][1]+
        m[0][1]*m[1][0]*m[2][3]+
        m[0][3]*m[1][1]*m[2][0]-
        m[0][0]*m[1][1]*m[2][3]-
        m[0][1]*m[1][3]*m[2][0]-
        m[0][3]*m[1][0]*m[2][1],

        m[1][0]*m[2][2]*m[3][1]+
        m[1][1]*m[2][0]*m[3][2]+
        m[1][2]*m[2][1]*m[3][0]-
        m[1][0]*m[2][1]*m[3][2]-
        m[1][1]*m[2][2]*m[3][0]-
        m[1][2]*m[2][0]*m[3][1],

        m[0][0]*m[2][1]*m[3][2]+
        m[0][1]*m[2][2]*m[3][0]+
        m[0][2]*m[2][0]*m[3][1]-
        m[0][0]*m[2][2]*m[3][1]-
        m[0][1]*m[2][0]*m[3][2]-
        m[0][2]*m[2][1]*m[3][0],

        m[0][0]*m[1][2]*m[3][1]+
        m[0][1]*m[1][0]*m[3][2]+
        m[0][2]*m[1][1]*m[3][0]-
        m[0][0]*m[1][1]*m[3][2]-
        m[0][1]*m[1][2]*m[3][0]-
        m[0][2]*m[1][0]*m[3][1],

        m[0][0]*m[1][1]*m[2][2]+
        m[0][1]*m[1][2]*m[2][0]+
        m[0][2]*m[1][0]*m[2][1]-
        m[0][0]*m[1][2]*m[2][1]-
        m[0][1]*m[1][0]*m[2][2]-
        m[0][2]*m[1][1]*m[2][0] );
    return out;
}


// Zwrócenie punktu ztransformatowanego

inline Vector VMatrix::GetVertex( Vector src )                  // zwraca wekor/punkt po transformacji aktualn¹ macierz¹
{
    Vector out;
    out.vector[0] = (m[0][0]*src.vector[0]) + (m[0][1]*src.vector[1]) + (m[0][2]*src.vector[2]) + m[0][3];
    out.vector[1] = (m[1][0]*src.vector[0]) + (m[1][1]*src.vector[1]) + (m[1][2]*src.vector[2]) + m[1][3];
    out.vector[2] = (m[2][0]*src.vector[0]) + (m[2][1]*src.vector[1]) + (m[2][2]*src.vector[2]) + m[2][3];
    return out;
}

// Zwrócenie punktu ztransformatowanego wstecznie

//   http://www.naukowiec.org/wzory/matematyka/macierz-odwrotna-4x4_628.html
inline Vector GetVertexBack( Vector src )
{
    // punkt * macierz odwrotna = punkt przed przekrzta³ceniem
    return ((*this).GetReverse()).GetVertex( src );
}
