


inline int Engine::AddGraphicModel( char * name, char * texture, Vector scale, int type )
{
	GraphicModels.resize( GraphicModels.size() + 1 );
	GraphicModels[ GraphicModels.size() - 1 ] = new StaticGraphicModel;
	GraphicModels[ GraphicModels.size() - 1 ] -> Init( name, texture, type, scale );
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


