
    
    

class Vector
{
public:
    float vector[3];
    
    inline float& operator [] ( int id );                   // odwo�anie si� do sk�adowej wektora ( x, y, z )
    inline Vector operator +  ( const Vector &src )const;   // dodanie wektora
    inline Vector operator += ( const Vector &src );        // dodanie wektora
    inline Vector operator -  ( const Vector &src )const;   // odj�cie wektora
    inline Vector operator -= ( const Vector &src );        // odj�cie wektora
    inline Vector operator && ( const Vector &src )const;   // iloczyn wektorowy
    inline Vector operator *  ( const Vector &src )const;   // mno�y odpowiadaj�ce sobie miejasca w tablicach przez siebie
    //inline Vector operator *  ( const float  &src )const;   // pomnozenie kazdej sk�adowej wektora przez skalar
    inline Vector operator *= ( const float  &src );        // pomnozenie kazdej sk�adowej wektora przez skalar
    inline bool   operator == ( const Vector &src )const;   // sprawdzenie r�wno�ci wektor�w
    inline bool   operator != ( const Vector &src )const;   // sprawdzenie nier�wno�ci wektor�w
    inline bool   operator <  ( const float  &src )const;   // sprawdzenie ka�dej bezwzgl�dnej sk�adowej wektor czy jest mniejsza od src
    inline bool   operator >  ( const float  &src )const;   // sprawdzenie ka�dej bezwzgl�dnej sk�adowej wektor czy jest wi�ksza od src
    inline bool   operator <  ( Vector &src )const;   // sprawdzenie ka�dej bezwzgl�dnej sk�adowej wektor czy jest mniejsza od src
    inline bool   operator >  ( Vector &src )const;   // sprawdzenie ka�dej bezwzgl�dnej sk�adowej wektor czy jest wi�ksza od src
    inline bool   operator <= ( Vector &src )const;   // sprawdzenie ka�dej bezwzgl�dnej sk�adowej wektor czy jest mniejsza od src
    inline bool   operator >= ( Vector &src )const;   // sprawdzenie ka�dej bezwzgl�dnej sk�adowej wektor czy jest wi�ksza od src
    
    
    inline Vector Set( float x, float y, float z );         // ustawia sk�adowe wektora
    
    inline float Dot( Vector src );                         // zwraca a[0]*b[0] + a[1]*b[1] + a[2]*b[2]
    inline float Lenght();                                  // zwraca d�ugo�� wektora
    inline Vector Versor();                                 // zwraca wersor(wektor normalny, jednostkowy) utworzony z wektora
    inline Vector Normalize();                              // normalizuje wektor, po czym go zwraca
    inline Vector CreateVector( Vector src1, Vector src2 ); // tworzy wektor z podanych dwu punkt�w
    
    inline void SetLenght( float dst );						// zmiana d�ugo�ci wektora
    inline void GoToVector( Vector dst, float velocity );	// d��enie do wektora
    inline void GoToLenght( float dst, float velocity );	// d��enie do konkretnej d�ugo�ci wektora z pr�dko�ci�
    
    Vector();
    Vector( float x, float y, float z );
};

inline Vector SetVector( float x, float y, float z );


