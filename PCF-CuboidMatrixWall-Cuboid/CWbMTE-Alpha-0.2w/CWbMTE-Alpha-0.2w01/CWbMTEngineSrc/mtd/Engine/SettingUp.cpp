


inline int Engine::AddVBO( unsigned int texture )
{
	map.vbotex.resize( map.vbotex.size() + 1 );
	map.vbotex[ map.vbotex.size() - 1 ].SetTexture( texture );
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
	map.triPHYS.resize( map.triPHYS.size() + 1 );
	map.triPHYS[ map.triPHYS.size()-1 ].vertex[0] = a;
	map.triPHYS[ map.triPHYS.size()-1 ].vertex[1] = b;
	map.triPHYS[ map.triPHYS.size()-1 ].vertex[2] = c;
	map.triPHYS[ map.triPHYS.size()-1 ].normal = normal;
	map.triPHYS[ map.triPHYS.size()-1 ].Calculate();
}

inline void Engine::AddObject()
{
	map.staticobject.resize( map.staticobject.size() + 1 );
	map.staticobject[ map.staticobject.size() - 1 ] = new PhysicModelStatic;
}

inline void Engine::AddObjects( int number )
{
	int i;
	for( i = 0; i < number; i++ )
	{
		AddObject();
	}
}

inline void Engine::DestroyWorld()
{
	map.DestroyColliders();
}

inline void Engine::UpdateWorld()
{
	map.UpdateTerrainColliders();
}

inline PhysicModelStatic * Engine::Object( int id )
{
	return map.staticobject[id];
}

inline unsigned int Engine::ObjectsNumber()
{
	return map.staticobject.size();
}

inline void Engine::AddLightning( Vector begin_, Vector end_, float beginWidth_, float EndWidth_, float r1_, float g1_, float b1_, float r2_, float g2_, float b2_, int segments_, float branch_, float branchDensity_, float beginTime, float endTime )
{
	ActualAddedIdLightnings %= map.NumberOfLightnings;
	engineInstantiation->map.lightnings[ ActualAddedIdLightnings ].Set( begin_, end_, beginWidth_, EndWidth_, r1_, g1_, b1_, r2_, g2_, b2_, segments_, branch_, branchDensity_, beginTime, endTime );
	ActualAddedIdLightnings++;
}

inline unsigned int Engine::GraphicObjectsNumber()
{
	return map.graphicObjects.size();
}

inline void Engine::AddGraphicObject()
{
	map.graphicObjects.resize( map.graphicObjects.size() + 1 );
}

inline GraphicObject * Engine::GetGraphicObject( unsigned int id )
{
	if( id >= map.graphicObjects.size() )
		return NULL;
	return &map.graphicObjects[ id ];
}

inline GraphicObject * Engine::LastGraphicObject()
{
	if( map.graphicObjects.size() == 0 )
		return NULL;
	return &map.graphicObjects[ map.graphicObjects.size() - 1 ];
}


