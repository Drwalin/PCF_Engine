


inline unsigned int Engine::TextureId( char * src )
{
	int i;
	for( i = 0; i < textures.size(); i++ )
	{
		if( !strcmp( src, textures[i]->name ) )
		{
			return textures[i]->GetID();
		}
	}
	return 0;
}

inline void Engine::AddTexture( char * src, int type )
{
printf( "\n --b--" );
	textures.resize( textures.size() + 1 );
printf( "\n --b--" );
	textures[ textures.size() - 1 ] = new Texture;
printf( "\n --b--" );
	textures[ textures.size() - 1 ]->LoadInit( src, type );
}


