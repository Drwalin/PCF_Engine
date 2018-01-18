


inline void Engine::AddSoundSource( char * src )
{
	soundEngineInstantiation -> AddSound( src );
}

inline void Engine::PlaySound( char * src )
{
	soundEngineInstantiation -> PlaySound( src );
}

inline void Engine::PlaySound( char * src, Vector origin )
{
	soundEngineInstantiation -> PlaySound( src, origin );
}

inline void Engine::PlaySound( char * src, Vector origin, float range )
{
	soundEngineInstantiation -> PlaySound( src, origin, range );
}
	

