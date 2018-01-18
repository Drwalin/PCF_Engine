


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

inline void Engine::AddGraphicModelAsMap( char * name, unsigned int texture )
{
	map.graphicMapModels.resize( map.graphicMapModels.size() + 1 );
	map.graphicMapModels[map.graphicMapModels.size()-1] = new StaticGraphicModel;
	map.graphicMapModels[map.graphicMapModels.size()-1] -> Init( name, texture );
}


