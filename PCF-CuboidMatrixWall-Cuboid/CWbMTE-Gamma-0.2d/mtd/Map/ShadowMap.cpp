


inline void Map::DrawShadowMap()
{
	shadowMap.Draw();
}

inline void Map::UpdateShadowMap()
{
	shadowMap.Update( this );
}

inline void Map::GenerateShadowMap()
{
	shadowMap.Generate( this );
}


