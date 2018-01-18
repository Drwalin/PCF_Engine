


inline void Map::DrawShadowMap()
{
	shadowMap.Draw();
}

inline void Map::UpdateShadowMap( int beg, int end )
{
	shadowMap.Update( this, beg, end );
}

inline void Map::GenerateShadowMap()
{
	shadowMap.Generate( this );
}


