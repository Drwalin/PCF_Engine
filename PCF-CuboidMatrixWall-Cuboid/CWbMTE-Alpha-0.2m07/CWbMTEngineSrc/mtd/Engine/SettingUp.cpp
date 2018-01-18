


inline int Engine::AddVBO( char * texturesrc, int texturtype )
{
	map.vbotex.resize( map.vbotex.size() + 1 );
	map.vbotex[ map.vbotex.size() - 1 ].SetTexture( texturesrc, texturtype );
	return map.vbotex.size() - 1;
}

inline void Engine::SetLightningLimit( int size )
{
	map.NumberOfLightnings = size;
	if( map.lightnings != NULL )
		delete[] map.lightnings;
	map.lightnings = new Lightning[ map.NumberOfLightnings ];
}

inline void Engine::AddVertexToLastVBO( float x, float y, float z, float uvx, float uvy )
{
	map.vbotex[ map.vbotex.size() - 1 ].AddVertex( x, y, z, uvx, uvy );
}

inline void Engine::CreateTriangleWithLastThreeVertices()
{
	map.vbotex[ map.vbotex.size() - 1 ].AddTriangle(
													map.vbotex[ map.vbotex.size() - 1 ].vertices.size() - 3,
													map.vbotex[ map.vbotex.size() - 1 ].vertices.size() - 2,
													map.vbotex[ map.vbotex.size() - 1 ].vertices.size() - 1
													);
}

inline void Engine::AddPhysicTriangle( Vector a, Vector b, Vector c, Vector normal )
{
	
}


