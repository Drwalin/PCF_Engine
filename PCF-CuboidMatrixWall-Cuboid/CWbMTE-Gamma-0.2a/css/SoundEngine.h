
#ifndef SOUND_ENGINE_H
#define SOUND_ENGINE_H

class SoundSampleSources
{
public:
	irrklang::ISoundSource * source;
	char * name;
	
	inline void SetName( char * src );
	
	SoundSampleSources();
	~SoundSampleSources();
};

class SoundEngine
{
public:
	irrklang::ISoundEngine * SEngine;
	vector < SoundSampleSources * > samples;
	
	float GlobalVolume;
	
	inline void Init();
	inline void DeInit();
	
	inline void AddSound( char * src );		// file name with path
	inline void PlaySound( float volume, char * src );	// file name without path and expansion
	inline void PlaySound( char * src, Vector origin, float minDistance );
	inline void PlaySound( char * src, Vector origin );
	inline void PlaySound( float volume, int src );
	inline void PlaySound( int src, Vector origin, float minDistance );
	inline void PlaySound( int src, Vector origin );
	inline int GetSoundId( char * src );
	
	inline void Update();
	
	SoundEngine();
	~SoundEngine();
};

#endif
