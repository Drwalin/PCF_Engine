


#include"Draw.cpp"
#include"Update.cpp"
#include"CalculateBaseLights.cpp"
#include"Generate.cpp"

#define EPSILON 0.0113f
inline unsigned int ShadowMap::GetIndiceId( Vector point )
{
	unsigned int i;
	Vector fast;
	for( i = VBO.vertices.size() - 1; i >= 0; --i )
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
	VBO.AddVertex( point[0], point[1], point[2], 0, 0, 0, 230 );
	return VBO.vertices.size() - 1;
}
#undef EPSILON

ShadowMap::ShadowMap()
{
	edgeLenght = 1.5f;
	baseColor = NULL;
}

ShadowMap::~ShadowMap()
{
	edgeLenght = 0.0f;
	if( baseColor != NULL )
		delete[] baseColor;
	baseColor = NULL;
}


