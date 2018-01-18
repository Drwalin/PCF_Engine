

inline float Max2( float a, float b )
{
    if( a > b )
        return a;
    else
        return b;
}

inline float Min2( float a, float b )
{
    if( a < b )
        return a;
    else
        return b;
}

inline float Max3( float a, float b, float c )
{
    if( a < b )
        a = b;
    if( a < c )
        a = c;
    return a;
}

inline float Min3( float a, float b, float c )
{
    if( a > b )
        a = b;
    if( a > c )
        a = c;
    return a;
}
