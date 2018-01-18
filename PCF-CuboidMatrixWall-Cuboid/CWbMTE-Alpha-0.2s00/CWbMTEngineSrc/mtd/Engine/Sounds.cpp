


inline void Engine::AddSoundSource( char * src )
{
	soundEngineInstantiation -> AddSound( src );
}

inline void Engine::PlaySound( float volume, char * src )
{
	soundEngineInstantiation -> PlaySound( volume, src );
}

inline void Engine::PlaySound( float volume, char * src, Vector origin )
{
	soundEngineInstantiation -> PlaySound( volume, src, origin );
}

inline void Engine::PlaySound( float volume, char * src, Vector origin, float range )
{
	soundEngineInstantiation -> PlaySound( volume, src, origin, range );
}
	

