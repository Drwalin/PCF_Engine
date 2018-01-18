


inline int Engine::AddGraphicModel( char * name, unsigned int texture, Vector scale )
{
	GraphicModels.resize( GraphicModels.size() + 1 );
	GraphicModels[ GraphicModels.size() - 1 ] = new StaticGraphicModel;
	GraphicModels[ GraphicModels.size() - 1 ] -> Init( name, texture, scale );
}

inline StaticGraphicModel * Engine::GetStaticModelHandle( char * src )
{
	int i;
	for( i = 0; i < GraphicModels.size(); i++ )
	{
		if( !strcmp( src, GraphicModels[i] -> name ) )
		{
			return GraphicModels[i];
		}
	}
	return NULL;
}

inline void Engine::AddGraphicModelAsMap( const char * name, unsigned int texture )
{
	map.graphicMapModels.resize( map.graphicMapModels.size() + 1 );
	map.graphicMapModels[map.graphicMapModels.size()-1] = new StaticGraphicModel;
	int i;
	map.graphicMapModels[map.graphicMapModels.size()-1] -> name = new char[strlen(name)+1];
	for( i = 0; i < strlen(name); ++i )
	{
		map.graphicMapModels[map.graphicMapModels.size()-1] -> name[i] = name[i];
	}
	map.graphicMapModels[map.graphicMapModels.size()-1] -> name[i] = 0;
//	map.graphicMapModels[map.graphicMapModels.size()-1] -> VBO.textureVBO = texture;
}


