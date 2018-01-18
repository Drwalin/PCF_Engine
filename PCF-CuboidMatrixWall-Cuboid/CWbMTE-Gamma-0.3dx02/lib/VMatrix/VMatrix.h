




class VMatrix
{
public:
    float m[4][4];
    
    inline VMatrix SetMatrix(
        float src00, float src01, float src02, float src03,
        float src10, float src11, float src12, float src13,
        float src20, float src21, float src22, float src23,
        float src30, float src31, float src32, float src33 );   // ustawia dane wartoœci w macierzy
    inline VMatrix SetMatrix( VMatrix src );                    // podstawia macierz pod macierz
    inline VMatrix SetMatrix( float **src );                    // podstawia macierz pod macierz
    
    inline VMatrix InitEmpty();                             // inicjiuje pust¹ macierz
    //inline VMatrix InitTranslate( Vector src );             // inicjiuje macierz przesuniêt¹ o wektor
    //inline VMatrix InitRotateX( float angle );              // inicjiuje macierz obrócon¹ na osi X
    //inline VMatrix InitRotateY( float angle );              // inicjiuje macierz obrócon¹ na osi Y
    //inline VMatrix InitRotateZ( float angle );              // inicjiuje macierz obrócon¹ na osi Z
    //inline VMatrix InitScale( float size );                 // inicjiuje o zmienionym rozmiarze
    
    inline float & operator [] ( const int src );
    
    inline VMatrix operator += ( const Vector &src );       // translacja wektorem
    inline VMatrix operator *  ( const VMatrix &src )const; // zwraca pomno¿on¹ aktualn¹ przez podan¹ macierz
    inline VMatrix operator *= ( const VMatrix &src );      // mno¿y aktualn¹ pzez podan¹ macierz
    inline Vector  operator *  ( const Vector &src )const;  // zwraca pomno¿on¹ aktualn¹ macierz przez podany wektor
    inline VMatrix operator *  ( const float  &src )const;  // pomnozenie kazdej sk³adowej macierzy przez skalar
    inline VMatrix operator *= ( const float  &src );       // pomnozenie kazdej sk³adowej macierzy przez skalar
    
    
    inline VMatrix Translate( Vector src );                    // translacja, przesuniêcie ( X, Y, Z ) o sk³adowe wektora src( x, y, z )
    inline VMatrix RotateX( float angle );                     // obrócenie o k¹t angle w kierunku przeciwnym o kierunku ruchu wskazówek zegara wokó³ osi X
    inline VMatrix RotateY( float angle );                     // obrócenie o k¹t angle w kierunku przeciwnym o kierunku ruchu wskazówek zegara wokó³ osi Y
    inline VMatrix RotateZ( float angle );                     // obrócenie o k¹t angle w kierunku przeciwnym o kierunku ruchu wskazówek zegara wokó³ osi Z
    inline VMatrix Scale( Vector src );                        // sklowanie ( X, Y, Z ) o sk³adowe wektora src( x, y, z )
    inline VMatrix Scale( float src );                         // sklowanie ( X, Y, Z ) o skalar
    
    
    inline VMatrix GetReverse();                            // zwrócenie odwrotnej macierzy
    inline VMatrix Reverse();                               // zamienienie macierzy na odwrotn¹
    
    inline Vector GetVertex( Vector src );                  // zwraca wekor/punkt po transformacji aktualn¹ macierz¹
    inline Vector GetVertexBack( Vector src );              // zwraca wekor/punkt po transformacji wstecznej aktualn¹ macierz¹
    
    
    inline float GetDet();                                  // zwraca wyznacznik macierzy
    
    VMatrix(){ InitEmpty(); }
};
