


class Vertex
{
public:
	Vector pos;
	float xtexcoord;
	float ytexcoord;
	
	inline float& operator[]( int id )
	{
		switch( id )
		{
		case 0: return pos[0];
		case 1: return pos[1];
		case 2: return pos[2];
		case 3: return xtexcoord;
		case 4: return ytexcoord;
		}
	}
	Vertex()
	{
		pos.Set( 0.0f, 0.0f, 0.0f );
		xtexcoord = 0.0f;
		ytexcoord = 0.0f;
	}
};


