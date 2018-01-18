


inline void Engine::SetUseVBO()
{
	UseVBO = true;
}

inline void Engine::SetDontUseVBO()
{
	UseVBO = false;
}

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

inline unsigned int Engine::ObjectsNumber()
{
	return map.staticobject.size();
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

inline PhysicModelStatic * Engine::Object( int id )
{
	if( id < 0 || id >= map.staticobject.size() )
		return NULL;
	return map.staticobject[id];
}

inline PhysicModelStatic * Engine::BackObject()
{
	return Object( map.staticobject.size() - 1 );
}

inline PhysicModelStatic * Engine::FrontObject()
{
	return Object( 0 );
}

inline void Engine::DeleteObject( int id )
{
	if( id < 0 || id >= ObjectsNumber() )
		return;
	delete map.staticobject[id];
	map.staticobject.erase( map.staticobject.begin() + id );
}

inline void Engine::DestroyWorldInEngineThread()
{
	DeleteVBOs();
	deleteVBOs = false;
	map.triPHYS.resize( 0 );
	
	for( int i = 0; i < map.lightSourcesDynamic.size(); ++i )
		delete map.lightSourcesDynamic[i];
	map.lightSourcesDynamic.resize( 0 );
	map.lightSourcesStatic.resize( 0 );
}

inline void Engine::DestroyWorldOutOfEngineThread()
{
	deleteVBOs = true;
	while( deleteVBOs == true )
	{
		Delay( 0 );
	}
	map.triPHYS.resize( 0 );
	
	for( int i = 0; i < map.lightSourcesDynamic.size(); ++i )
		delete map.lightSourcesDynamic[i];
	map.lightSourcesDynamic.resize( 0 );
	map.lightSourcesStatic.resize( 0 );
}

inline void Engine::UpdateWorld()
{
	map.updateVBOs = true;
	map.UpdateTerrainColliders();
	if( EnableStaticLight || EnableDynamicLight )
	{
		map.GenerateShadowMap();
	}
}

inline void Engine::AddLightning( Vector begin_, Vector end_, float beginWidth_, float EndWidth_, float r1_, float g1_, float b1_, float r2_, float g2_, float b2_, int segments_, float branch_, float branchDensity_, float beginTime, float endTime )
{
	ActualAddedIdLightnings %= map.NumberOfLightnings;
	engineInstance->map.lightnings[ ActualAddedIdLightnings ].Set( begin_, end_, beginWidth_, EndWidth_, r1_, g1_, b1_, r2_, g2_, b2_, segments_, branch_, branchDensity_, beginTime, endTime );
	ActualAddedIdLightnings++;
}

inline void Engine::AddGraphicObject( StaticGraphicModel * src, Vector pos, Vector rotate, float scale )
{
	VMatrix matrix;
	
	matrix.InitEmpty();
	matrix.Translate( pos );
	matrix.RotateY( rotate[1] );
	matrix.RotateX( rotate[0] );
	matrix.RotateZ( rotate[2] );
	matrix.Scale( scale );
	
	int i, j, k;
	for( j = 0; j < src -> VBO.size(); ++j )
	{
		for( i = 0; i < map.vbotex.size(); i++ )
		{
			if( map.vbotex[i].textureVBO == src -> VBO[j].textureVBO )
			{
				break;
			}
		}
		if( i >= map.vbotex.size() )
		{
			AddVBO( src -> VBO[j].textureVBO );
		}
		
		for( k = 0; k < src->VBO[j].vertices.size(); ++k )
		{
			pos = matrix.GetVertex( SetVector( src->VBO[j].vertices[i].x, src->VBO[j].vertices[i].y, src->VBO[j].vertices[i].z ) );
			AddVertexToLastVBO( pos[0], pos[1], pos[2], src->VBO[j].vertices[i].texcoordx, src->VBO[j].vertices[i].texcoordy );
			
			if( k % 3 == 2 )
			{
				CreateTriangleWithLastThreeVertices();
			}
		}
	}
}

inline void Engine::StaticLightEnable()
{
	EnableStaticLight = true;
}

inline void Engine::DynamicLightEnable()
{
	EnableDynamicLight = true;
}

inline void Engine::StaticLightDisable()
{
	EnableStaticLight = false;
}

inline void Engine::DynamicLightDisable()
{
	EnableDynamicLight = false;
}

inline void Engine::AddLightSource( Vector origin, Vector direction, float range, float angleInConeVertex, float lightDensity )
{
	map.lightSourcesStatic.resize( map.lightSourcesStatic.size() + 1 );
	map.lightSourcesStatic.back().origin = origin;
	map.lightSourcesStatic.back().direction = direction.Versor();
	map.lightSourcesStatic.back().range = range;
	map.lightSourcesStatic.back().angle = angleInConeVertex;
	map.lightSourcesStatic.back().density = lightDensity;
}

inline void Engine::SetLightMapEdgeLenght( float src )
{
	map.shadowMap.edgeLenght = src;
}

inline void Engine::SetMaximumNumberOfEdges( int src )
{
	map.shadowMap.numberOfEdges = src;
}

inline LightSource * Engine::AddDynamicLightSource( Vector origin, Vector direction, float range, float angleInConeVertex, float lightDensity )
{
	map.lightSourcesDynamic.resize( map.lightSourcesDynamic.size() + 1 );
	map.lightSourcesDynamic.back() = new LightSource;
	map.lightSourcesDynamic.back()->origin = origin;
	map.lightSourcesDynamic.back()->direction = direction.Versor();
	map.lightSourcesDynamic.back()->range = range;
	map.lightSourcesDynamic.back()->angle = angleInConeVertex;
	map.lightSourcesDynamic.back()->density = lightDensity;
}

inline LightSource * Engine::GetDynamicLightSourceHandle( int src )
{
	if( src < 0 || src >= map.lightSourcesDynamic.size() )
		return NULL;
	return map.lightSourcesDynamic[src];
}


