


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
//	vector < irrklang::ISound * > sounds;
	vector < SoundSampleSources > samples;
	
	float HearDistance;
	
	inline void Init();
	inline void DeInit();
	
	inline void PlaySound( char * src );	// file name without path and expansion
	inline void AddSound( char * src );		// file name with path
	inline void Update();
	inline void PlaySound( char * src, Vector origin );
	
	//inline void Update();
	
	
	SoundEngine();
	~SoundEngine();
};


