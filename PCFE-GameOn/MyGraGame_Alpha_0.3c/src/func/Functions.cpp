


inline float RandFloat( float a, float b )
{
	return (float(rand()%10000)*(b-a)/9999.0f)+a;
}

inline int RandInt( int a, int b )
{
	return (rand()%(b-a))+a;
}


