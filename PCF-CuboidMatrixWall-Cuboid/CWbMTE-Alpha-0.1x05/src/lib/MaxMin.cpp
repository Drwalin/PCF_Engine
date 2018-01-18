


namespace MaxAndMin
{
	
	inline float Max( float a, float b )
	{
		return (a>b)?a:b;
	}
	
	inline float Min( float a, float b )
	{
		return (a<b)?a:b;
	}
	
	inline float Max( float a, float b, float c )
	{
		return (a>((b>c)?b:c))?a:((b>c)?b:c);
	}
	
	inline float Min( float a, float b, float c )
	{
		return (a<((b<c)?b:c))?a:((b<c)?b:c);
	}
	
}


