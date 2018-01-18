
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
    /*out.SetMatrix(
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
        m[0][2]*m[2][3]*m[3][3] -
        m[0][3]*m[2][1]*m[3][2],
    */return out;
    /*
    

Naukowiec.org
Wzory
Matematyka
Wzór na macierz...
Przydatne kalkulatory i narzêdzia
Kalkulator macierzy
zobacz wiêcej narzêdzi..
Wzór na macierz odwrotn¹ 4x4
A
A
A
Maj¹c macierz AA tak¹ ¿e:

A=?????a11a21a31a41a12a22a32a42a13a23a33a43a14a24a34a44?????A=[a11a12a13a14a21a22a23a24a31a32a33a34a41a42a43a44]

Macierz odwrotn¹ mo¿na obliczyæ w nastêpuj¹cy sposób:

je¿eli:

det(A)=a11a22a33a44+a11a23a34a42+a11a24a32a43+det(A)=a11a22a33a44+a11a23a34a42+a11a24a32a43+

+a12a21a34a43+a12a23a31a44+a12a24a33a41++a12a21a34a43+a12a23a31a44+a12a24a33a41+

+a13a21a32a44+a13a22a34a41+a13a24a31a42++a13a21a32a44+a13a22a34a41+a13a24a31a42+

+a14a21a33a42+a14a22a31a43+a14a23a32a41++a14a21a33a42+a14a22a31a43+a14a23a32a41+

-a11a22a34a43-a11a23a32a44-a11a24a33a42+-a11a22a34a43-a11a23a32a44-a11a24a33a42+

-a12a21a33a44-a12a23a34a41-a12a24a31a43+-a12a21a33a44-a12a23a34a41-a12a24a31a43+

-a13a21a34a42-a13a22a31a44-a13a24a32a41+-a13a21a34a42-a13a22a31a44-a13a24a32a41+

-a14a21a32a43-a14a22a33a41-a14a23a31a42?0-a14a21a32a43-a14a22a33a41-a14a23a31a42?0

to macierz odwrotna wynosi:

A-1=1det(A)?????b11b21b31b41b12b22b32b42b13b23b33b43b14b24b34b44?????A-1=1det(A)[b11b12b13b14b21b22b23b24b31b32b33b34b41b42b43b44]

gdzie:

b11=a22a33a44+a23a34a42+a24a32a43-a22a34a43-a23a32a44-a24a33a42b11=a22a33a44+a23a34a42+a24a32a43-a22a34a43-a23a32a44-a24a33a42

b12=a12a34a43+a13a32a44+a14a33a42-a12a33a44-a13a34a42-a14a32a43b12=a12a34a43+a13a32a44+a14a33a42-a12a33a44-a13a34a42-a14a32a43

b13=a12a23a44+a13a24a42+a14a22a43-a12a24a43-a13a22a44-a14a23a42b13=a12a23a44+a13a24a42+a14a22a43-a12a24a43-a13a22a44-a14a23a42

b14=a12a24a33+a13a22a34+a14a23a32-a12a23a34-a13a24a32-a14a22a33b14=a12a24a33+a13a22a34+a14a23a32-a12a23a34-a13a24a32-a14a22a33

b21=a21a34a43+a23a31a44+a24a33a41-a21a33a44-a23a34a41-a24a31a43b21=a21a34a43+a23a31a44+a24a33a41-a21a33a44-a23a34a41-a24a31a43

b22=a11a33a44+a13a34a41+a14a31a43-a11a34a43-a13a31a44-a14a33a41b22=a11a33a44+a13a34a41+a14a31a43-a11a34a43-a13a31a44-a14a33a41

b23=a11a24a43+a13a21a44+a14a23a41-a11a23a44-a13a24a41-a14a21a43b23=a11a24a43+a13a21a44+a14a23a41-a11a23a44-a13a24a41-a14a21a43

b24=a11a23a34+a13a24a31+a14a21a33-a11a24a33-a13a21a34-a14a23a31b24=a11a23a34+a13a24a31+a14a21a33-a11a24a33-a13a21a34-a14a23a31

b31=a21a32a44+a22a34a41+a24a31a42-a21a34a42-a22a31a44-a24a32a41b31=a21a32a44+a22a34a41+a24a31a42-a21a34a42-a22a31a44-a24a32a41

b32=a11a34a42+a12a31a44+a14a32a41-a11a32a44-a12a34a41-a14a31a42b32=a11a34a42+a12a31a44+a14a32a41-a11a32a44-a12a34a41-a14a31a42

b33=a11a22a44+a12a24a41+a14a21a42-a11a24a42-a12a21a44-a14a22a41b33=a11a22a44+a12a24a41+a14a21a42-a11a24a42-a12a21a44-a14a22a41

b34=a11a24a32+a12a21a34+a14a22a31-a11a22a34-a12a24a31-a14a21a32b34=a11a24a32+a12a21a34+a14a22a31-a11a22a34-a12a24a31-a14a21a32

b41=a21a33a42+a22a31a43+a23a32a41-a21a32a43-a22a33a41-a23a31a42b41=a21a33a42+a22a31a43+a23a32a41-a21a32a43-a22a33a41-a23a31a42

b42=a11a32a43+a12a33a41+a13a31a42-a11a33a42-a12a31a43-a13a32a41b42=a11a32a43+a12a33a41+a13a31a42-a11a33a42-a12a31a43-a13a32a41

b43=a11a23a42+a12a21a43+a13a22a41-a11a22a43-a12a23a41-a13a21a42b43=a11a23a42+a12a21a43+a13a22a41-a11a22a43-a12a23a41-a13a21a42

b44=a11a22a33+a12a23a31+a13a21a32-a11a23a32-a12a21a33-a13a22a31b44=a11a22a33+a12a23a31+a13a21a32-a11a23a32-a12a21a33-a13a22a31
    */
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
    
}
