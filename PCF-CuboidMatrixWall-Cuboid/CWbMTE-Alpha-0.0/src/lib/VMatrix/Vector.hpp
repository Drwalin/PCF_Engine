
    
    

class Vector
{
public:
    float vector[3];
    
    inline float& operator [] ( int a );                    // odwo³anie siê to sk³adowej wektora ( x, y, z )
    inline Vector operator +  ( const Vector &src )const;   // dodanie wektora
    inline Vector operator += ( const Vector &src );        // dodanie wektora
    inline Vector operator -  ( const Vector &src )const;   // odjêcie wektora
    inline Vector operator -= ( const Vector &src );        // odjêcie wektora
    inline Vector operator && ( const Vector &src )const;   // iloczyn wektorowy
//  inline Vector operator *= ( const Vector &src );        // iloczyn wektorowy
    inline Vector operator *  ( const Vector &src )const;   // mno¿y odpowiadaj¹ce sobie miejasca w tablicach przez siebie
    inline Vector operator *  ( const float  &src )const;   // pomnozenie kazdej sk³adowej wektora przez skalar
    inline Vector operator *= ( const float  &src );        // pomnozenie kazdej sk³adowej wektora przez skalar
    inline bool   operator == ( const Vector &src )const;   // sprawdzenie równoœci wektorów
    inline bool   operator != ( const Vector &src )const;   // sprawdzenie nierównoœci wektorów
    inline bool   operator <  ( const float  &src )const;   // sprawdzenie ka¿dej bezwzglêdnej sk³adowej wektor czy jest mniejsza od src
    inline bool   operator >  ( const float  &src )const;   // sprawdzenie ka¿dej bezwzglêdnej sk³adowej wektor czy jest wiêksza od src
    
    
    inline Vector Set( float x, float y, float z );         // ustawia sk³adowe wektora
    
    inline float Lenght();                                  // zwraca d³ugoœæ wektora
    inline Vector Versor();                                 // zwraca wersor(wektor normalny, jednostkowy) utworzony z wektora
    inline Vector Normalize();                              // normalizuje wektor, po czym go zwraca
    inline Vector CreateVector( Vector src1, Vector src2 ); // tworzy wektor z podanych dwu punktów
    
    Vector()
    {
        vector[0] = 0.0f;
        vector[1] = 0.0f;
        vector[2] = 0.0f;
    }
};

inline Vector SetVector( float x, float y, float z );              // zwraca wektor utworzony z podanych sk³adowych

// operatory:

inline float& Vector::operator [] ( int id )            // zwraca wskaŸnik jako zmienn¹, któr¹ mo¿na zmieniaæ ( iterator do [ X, Y, X ] )
{
	if(( id >= 0 ) && ( id < 3 )){
	   return ((float*)this)[int(id)];
	}else if( id < 0 ){
	   return ((float*)this)[0];
	}else if( id == 3 ){
        float one_f = 1.0f;
        return one_f;
    }else{
        return ((float*)this)[2];
    }
}

inline Vector Vector::operator +( const Vector &src )const   // zwraca sumê wektorów
{
    Vector out;
    out.vector[0] = vector[0] + src.vector[0];
    out.vector[1] = vector[1] + src.vector[1];
    out.vector[2] = vector[2] + src.vector[2];
    return out;
}

inline Vector Vector::operator +=( const Vector &src )  //dodaje wektor
{
    vector[0] = vector[0] + src.vector[0];
    vector[1] = vector[1] + src.vector[1];
    vector[2] = vector[2] + src.vector[2];
    return *this;
}

inline Vector Vector::operator -( const Vector &src )const   // zwraca ró¿nicê wektorów
{
    Vector out;
    out.vector[0] = vector[0] - src.vector[0];
    out.vector[1] = vector[1] - src.vector[1];
    out.vector[2] = vector[2] - src.vector[2];
    return out;
}

inline Vector Vector::operator -=( const Vector &src )  // odejmu wektor
{
    vector[0] = vector[0] - src.vector[0];
    vector[1] = vector[1] - src.vector[1];
    vector[2] = vector[2] - src.vector[2];
    return *this;
}

inline Vector Vector::operator &&( const Vector &src )const  // iloczyn wektorowy
{
    Vector out;
	out.vector[0] = vector[1]*src.vector[2] - vector[2]*src.vector[1];
	out.vector[1] = vector[2]*src.vector[0] - vector[0]*src.vector[2];
	out.vector[2] = vector[0]*src.vector[1] - vector[1]*src.vector[0];
    return out;
}




inline Vector Vector::operator *  ( const Vector &src )const   // mno¿y odpowiadaj¹ce sobie miejasca w tablicach przez siebie
{
    Vector out;
    out.Set( vector[0] * src.vector[0],
             vector[1] * src.vector[1],
             vector[2] * src.vector[2] );
    return out;
}

inline Vector Vector::operator *  ( const float &src )const    // zwrócenie przemno¿onego wektora przez skalar
{
    Vector out;
    out.vector[0] = vector[0] * src;
    out.vector[1] = vector[1] * src;
    out.vector[2] = vector[2] * src;
    return out;
}

inline Vector Vector::operator *=( const float &src )   // mno¿enie wektora przez skalar
{
    vector[0] = vector[0] * src;
    vector[1] = vector[1] * src;
    vector[2] = vector[2] * src;
    return *this;
}

inline bool   Vector::operator == ( const Vector &src )const   // sprawdzenie równoœci wektorów
{
    if( (!memcmp( vector, src.vector, 3*sizeof(src.vector[0]) )) == 1 )
        return true;
    else
        return false;
}

inline bool   Vector::operator != ( const Vector &src )const   // sprawdzenie nierównoœci wektorów
{
    if( (!memcmp( vector, src.vector, 3*sizeof(src.vector[0]) )) != 1 )
        return true;
    else
        return false;
}

inline bool   Vector::operator <  ( const float  &src )const   // sprawdzenie ka¿dej bezwzglêdnej sk³adowej wektor czy jest mniejsza od src
{
    if( abs(vector[0]) < src )
        if( abs(vector[1]) < src )
            if( abs(vector[2]) < src )
                return true;
    return false;
}

inline bool   Vector::operator >  ( const float  &src )const   // sprawdzenie ka¿dej bezwzglêdnej sk³adowej wektor czy jest mniejsza od src
{
    if( abs(vector[0]) > src )
        if( abs(vector[1]) > src )
            if( abs(vector[2]) > src )
                return true;
    return false;
}



// metody:


inline Vector Vector::Set( float x, float y, float z )
{
    vector[0] = x;
    vector[1] = y;
    vector[2] = z;
    return *this;
}





inline float Vector::Lenght()       // zwraca d³ugoœæ wektora
{
    return sqrt( (vector[0]*vector[0]) + (vector[1]*vector[1]) + (vector[2]*vector[2]) );
}

inline Vector Vector::Versor()      // zwraca wersor utworzony z wektora
{
    Vector out;
    float lenght = Lenght();
    if( lenght != 0.0f )
    {
        out.vector[0] = vector[0] / lenght;
        out.vector[1] = vector[1] / lenght;
        out.vector[2] = vector[2] / lenght;
    }
    return out;
}

inline Vector Vector::Normalize()   // normalizuje wekto ( zmienia wektor w wersor )
{
    float lenght = Lenght();
    if( lenght != 0.0f )
    {
        vector[0] = vector[0] / lenght;
        vector[1] = vector[1] / lenght;
        vector[2] = vector[2] / lenght;
    }
    return *this;
}

inline Vector Vector::CreateVector( Vector src1, Vector src2 )     // tworzy wektor z podanych dwu punktow
{
    vector[0] = src2.vector[0] - src1.vector[0];
    vector[1] = src2.vector[1] - src1.vector[1];
    vector[2] = src2.vector[2] - src1.vector[2];
    return *this;
}

inline Vector SetVector( float x, float y, float z )              // zwraca wektor utworzony z podanych sk³adowych
{
    Vector out;
    out[0] = x;
    out[1] = y;
    out[2] = z;
    return out;
}




