


#include"Draw.cpp"
#include"Update.cpp"
#include"Generate.cpp"

#define EPSILON 0.0311f
inline unsigned int ShadowMap::GetIndiceId( Vector point )
{
	unsigned int i;
	Vector fast;
	for( i = 0; i < VBO.vertices.size(); ++i )
	{
		fast = VBO.vertices[i].pos - point;
		if( fast[0] < EPSILON )
			if( fast[0] > -EPSILON )
				if( fast[1] < EPSILON )
					if( fast[1] > -EPSILON )
						if( fast[2] < EPSILON )
							if( fast[2] > -EPSILON )
								return i;
	}
	VBO.AddVertex( point[0], point[1], point[2], 7, 7, 7, rand()%256 );
	return VBO.vertices.size() - 1;
}
#undef EPSILON

ShadowMap::ShadowMap()
{
	edgeLenght = 1.5f;
}

ShadowMap::~ShadowMap()
{
	edgeLenght = 0.0f;
}

