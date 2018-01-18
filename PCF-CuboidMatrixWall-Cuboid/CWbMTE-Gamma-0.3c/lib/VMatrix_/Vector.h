
    
    

class Vector
{
public:
    float vector[3];
    
    inline float& operator [] ( int id );                   // odwo³anie siê do sk³adowej wektora ( x, y, z )
    inline Vector operator +  ( const Vector &src )const;   // dodanie wektora
    inline Vector operator += ( const Vector &src );        // dodanie wektora
    inline Vector operator -  ( const Vector &src )const;   // odjêcie wektora
    inline Vector operator -= ( const Vector &src );        // odjêcie wektora
    inline Vector operator && ( const Vector &src )const;   // iloczyn wektorowy
    inline Vector operator *  ( const Vector &src )const;   // mno¿y odpowiadaj¹ce sobie miejasca w tablicach przez siebie
    //inline Vector operator *  ( const float  &src )const;   // pomnozenie kazdej sk³adowej wektora przez skalar
    inline Vector operator *= ( const float  &src );        // pomnozenie kazdej sk³adowej wektora przez skalar
    inline bool   operator == ( const Vector &src )const;   // sprawdzenie równoœci wektorów
    inline bool   operator != ( const Vector &src )const;   // sprawdzenie nierównoœci wektorów
    inline bool   operator <  ( const float  &src )const;   // sprawdzenie ka¿dej bezwzglêdnej sk³adowej wektor czy jest mniejsza od src
    inline bool   operator >  ( const float  &src )const;   // sprawdzenie ka¿dej bezwzglêdnej sk³adowej wektor czy jest wiêksza od src
    inline bool   operator <  ( Vector &src )const;   // sprawdzenie ka¿dej bezwzglêdnej sk³adowej wektor czy jest mniejsza od src
    inline bool   operator >  ( Vector &src )const;   // sprawdzenie ka¿dej bezwzglêdnej sk³adowej wektor czy jest wiêksza od src
    inline bool   operator <= ( Vector &src )const;   // sprawdzenie ka¿dej bezwzglêdnej sk³adowej wektor czy jest mniejsza od src
    inline bool   operator >= ( Vector &src )const;   // sprawdzenie ka¿dej bezwzglêdnej sk³adowej wektor czy jest wiêksza od src
    
    
    inline Vector Set( float x, float y, float z );         // ustawia sk³adowe wektora
    
    inline float Dot( Vector src );                         // zwraca a[0]*b[0] + a[1]*b[1] + a[2]*b[2]
    inline float Lenght();                                  // zwraca d³ugoœæ wektora
    inline Vector Versor();                                 // zwraca wersor(wektor normalny, jednostkowy) utworzony z wektora
    inline Vector Normalize();                              // normalizuje wektor, po czym go zwraca
    inline Vector CreateVector( Vector src1, Vector src2 ); // tworzy wektor z podanych dwu punktów
    
    inline void SetLenght( float dst );						// zmiana d³ugoœci wektora
    inline void GoToVector( Vector dst, float velocity );	// d¹¿enie do wektora
    inline void GoToLenght( float dst, float velocity );	// d¹¿enie do konkretnej d³ugoœci wektora z prêdkoœci¹
    
    Vector();
    Vector( float x, float y, float z );
};

inline Vector SetVector( float x, float y, float z );


