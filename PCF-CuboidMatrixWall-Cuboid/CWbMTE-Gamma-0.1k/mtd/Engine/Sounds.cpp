


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

inline float Engine::GetVolume()
{
	return soundEngineInstantiation -> GlobalVolume;
}

inline void Engine::SetVolume( float src )
{
	if( src < 0.0f )
		soundEngineInstantiation -> GlobalVolume = 0.0f;
	else if( src > 1.0f )
		soundEngineInstantiation -> GlobalVolume = 1.0f;
	else
		soundEngineInstantiation -> GlobalVolume = src;
}

inline void Engine::PlaySound( float volume, int src )
{
	soundEngineInstantiation -> PlaySound( volume, src );
}

inline void Engine::PlaySound( float volume, int src, Vector origin )
{
	soundEngineInstantiation -> PlaySound( volume, src, origin );
}

inline void Engine::PlaySound( float volume, int src, Vector origin, float range )
{
	soundEngineInstantiation -> PlaySound( volume, src, origin, range );
}

inline int Engine::GetSoundId( char * src )
{
	return soundEngineInstantiation -> GetSoundId( src );
}
	

