




class VMatrix
{
public:
    float m[4][4];
    
    inline VMatrix SetMatrix(
        float src00, float src01, float src02, float src03,
        float src10, float src11, float src12, float src13,
        float src20, float src21, float src22, float src23,
        float src30, float src31, float src32, float src33 );   // ustawia dane warto�ci w macierzy
    inline VMatrix SetMatrix( VMatrix src );                    // podstawia macierz pod macierz
    inline VMatrix SetMatrix( float **src );                    // podstawia macierz pod macierz
    
    inline VMatrix InitEmpty();                             // inicjiuje pust� macierz
    //inline VMatrix InitTranslate( Vector src );             // inicjiuje macierz przesuni�t� o wektor
    //inline VMatrix InitRotateX( float angle );              // inicjiuje macierz obr�con� na osi X
    //inline VMatrix InitRotateY( float angle );              // inicjiuje macierz obr�con� na osi Y
    //inline VMatrix InitRotateZ( float angle );              // inicjiuje macierz obr�con� na osi Z
    //inline VMatrix InitScale( float size );                 // inicjiuje o zmienionym rozmiarze
    
    inline float & operator [] ( const int src );
    
    inline VMatrix operator += ( const Vector &src );       // translacja wektorem
    inline VMatrix operator *  ( const VMatrix &src )const; // zwraca pomno�on� aktualn� przez podan� macierz
    inline VMatrix operator *= ( const VMatrix &src );      // mno�y aktualn� pzez podan� macierz
    inline Vector  operator *  ( const Vector &src )const;  // zwraca pomno�on� aktualn� macierz przez podany wektor
    inline VMatrix operator *  ( const float  &src )const;  // pomnozenie kazdej sk�adowej macierzy przez skalar
    inline VMatrix operator *= ( const float  &src );       // pomnozenie kazdej sk�adowej macierzy przez skalar
    
    
    inline VMatrix Translate( Vector src );                    // translacja, przesuni�cie ( X, Y, Z ) o sk�adowe wektora src( x, y, z )
    inline VMatrix RotateX( float angle );                     // obr�cenie o k�t angle w kierunku przeciwnym o kierunku ruchu wskaz�wek zegara wok� osi X
    inline VMatrix RotateY( float angle );                     // obr�cenie o k�t angle w kierunku przeciwnym o kierunku ruchu wskaz�wek zegara wok� osi Y
    inline VMatrix RotateZ( float angle );                     // obr�cenie o k�t angle w kierunku przeciwnym o kierunku ruchu wskaz�wek zegara wok� osi Z
    inline VMatrix Scale( Vector src );                        // sklowanie ( X, Y, Z ) o sk�adowe wektora src( x, y, z )
    inline VMatrix Scale( float src );                         // sklowanie ( X, Y, Z ) o skalar
    
    
    inline VMatrix GetReverse();                            // zwr�cenie odwrotnej macierzy
    inline VMatrix Reverse();                               // zamienienie macierzy na odwrotn�
    
    inline Vector GetVertex( Vector src );                  // zwraca wekor/punkt po transformacji aktualn� macierz�
    inline Vector GetVertexBack( Vector src );              // zwraca wekor/punkt po transformacji wstecznej aktualn� macierz�
    
    
    inline float GetDet();                                  // zwraca wyznacznik macierzy
    
    VMatrix(){ InitEmpty(); }
};
