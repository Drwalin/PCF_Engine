


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
	int i;
	for( i = 0; i < map.vbotex.size(); ++i )
	{
		map.vbotex[i].Delete();
	}
	for( i = 0; i < map.vbocol.size(); ++i )
	{
		map.vbocol[i].Delete();
	}
	for( i = 0; i < map.graphicMapModels.size(); ++i )
	{
		map.graphicMapModels[i] -> Delete();
		delete map.graphicMapModels[i];
		map.graphicMapModels[i] = NULL;
	}
	map.vbotex.resize( 0 );
	map.vbocol.resize( 0 );
	map.graphicMapModels.resize( 0 );
	map.triPHYS.resize( 0 );
}

inline void Engine::UpdateWorld()
{
	map.updateVBOs = true;
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

inline void Engine::AddGraphicObject( StaticGraphicModel * src, Vector pos, Vector rotate, float scale )
{
	VBOtextured * vbo = NULL;
	
	int i;
	for( i = 0; i < map.vbotex.size(); i++ )
	{
		if( map.vbotex[i].textureVBO == src -> VBO.textureVBO )
		{
			vbo = &(map.vbotex[i]);
			break;
		}
	}
	if( i >= map.vbotex.size() )
	{
		AddVBO( src -> VBO.textureVBO );
		vbo = &(map.vbotex[ map.vbotex.size() - 1 ]);
	}
	
	VMatrix matrix;
	
	matrix.InitEmpty();
	matrix.Translate( pos );
	matrix.RotateY( rotate[1] );
	matrix.RotateX( rotate[0] );
	matrix.RotateZ( rotate[2] );
	matrix.Scale( scale );
	
	for( i = 0; i < src->VBO.vertices.size(); i++ )
	{
		pos = matrix.GetVertex( SetVector( src->VBO.vertices[i].x, src->VBO.vertices[i].y, src->VBO.vertices[i].z ) );
		AddVertexToLastVBO( pos[0], pos[1], pos[2], src->VBO.vertices[i].texcoordx, src->VBO.vertices[i].texcoordy );
		
		if( i % 3 == 2 )
		{
			CreateTriangleWithLastThreeVertices();
		}
	}
}


