


/////////////////////
// End playing sound:
/*class MySoundEndReceiver : public irrklang::ISoundStopEventReceiver
{
public:
	virtual void OnSoundStopped( irrklang::ISound * sound, irrklang::E_STOP_EVENT_CAUSE reason, void * userData )
	{
		int i;
		for( i = 0; i < soundEngineInstantiation->sounds.size(); i++ )
		{
			if( soundEngineInstantiation->sounds[i] == sound )
			{
				sound->drop();
				soundEngineInstantiation->sounds.erase( soundEngineInstantiation->sounds.begin() + i );
				i--;
			}
		}
	}
};
MySoundEndReceiver* myGlobalReceiver = new MySoundEndReceiver();
*/
//////////////////
// Sample Methods:
	
inline void SoundSampleSources::SetName( char * src )
{
	int l = strlen( src ), i, j = 0, k = 0;
	for( i = 0; i < l; i++ )
	{
		if( src[i] == '\\' || src[i] == '/' )
			j = i+1;
		if( *(src+i) == '.' )
			k = i;
	}
	if( name != NULL )
		delete[] name;
	name = new char[1+k-j];
	name[k-j] = 0;
	for( i = j; i < k; i++ )
		name[i-j] = src[i];
	printf("\n%s-:-", name );
}

SoundSampleSources::SoundSampleSources()
{
	source = NULL;
	name = NULL;
}

SoundSampleSources::~SoundSampleSources()
{
	if( source != NULL )
		delete source;
	if( name != NULL )
		delete[] name;
}


////////////////////////
// Sound Engine Methods:

inline void SoundEngine::Init()
{
	SEngine = irrklang::createIrrKlangDevice();
}

inline void SoundEngine::DeInit()
{
	if( SEngine != NULL )
		SEngine->drop();
//	sounds.resize( 0 );
	samples.resize( 0 );
}

inline void SoundEngine::PlaySound( char * src )
{
//	sounds.resize( sounds.size() + 1 );
//	int id = sounds.size() - 1;
	int i;
	
	for( i = 0; i < samples.size(); i++ )
	{
		if( !strcmp( src, samples[i].name ) )
		{
			/*sounds[id] = */SEngine->play2D( samples[i].source );
//			sounds[id] -> setSoundStopEventReceiver(myGlobalReceiver);
			break;
		}
	}
}
inline void SoundEngine::AddSound( char * src )
{
	samples.resize( samples.size() + 1 );
	int id = samples.size() - 1;
	int i;
	
	samples[id].SetName( src );
	samples[id].source = SEngine->addSoundSourceFromFile( src );
}

SoundEngine::SoundEngine()
{
	SEngine = NULL;
}

SoundEngine::~SoundEngine()
{
	DeInit();
}


