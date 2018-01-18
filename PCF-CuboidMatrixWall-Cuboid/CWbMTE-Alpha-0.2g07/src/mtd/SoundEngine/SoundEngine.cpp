


/////////////////////
// End playing sound:
class MySoundEndReceiver : public irrklang::ISoundStopEventReceiver
{
public:
	virtual void OnSoundStopped( irrklang::ISound * sound, irrklang::E_STOP_EVENT_CAUSE reason, void * userData )
	{
		int i;
		for( i = 0; i < soundEngineInstantiation->sounds.size()-1; i++ )
		{
			if( soundEngineInstantiation->sounds[i].snd == sound )
			{
				soundEngineInstantiation->sounds[i].Ended = true;
			}
		}
	}
};
MySoundEndReceiver* myGlobalReceiver = new MySoundEndReceiver();



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
//	printf("\n%s", name );
}

SoundSampleSources::SoundSampleSources()
{
	source = NULL;
	name = NULL;
}

SoundSampleSources::~SoundSampleSources()
{
	if( source != NULL )
		source->drop();
	if( name != NULL )
		delete[] name;
}



////////////////
// Sound Sample:

OneSample::OneSample()
{
	range = 100.0f;
	snd = NULL;
	pos.Set( 0.0f, 0.0f, 0.0f );
	Ended = false;
}

OneSample::~OneSample()
{
	range = 0.0f;
	pos.Set( 0.0f, 0.0f, 0.0f );
	if( snd != NULL )
		snd->drop();
	Ended = false;
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
	sounds.resize( 0 );
	samples.resize( 0 );
}

inline void SoundEngine::Update()
{
	HearDistance = 100.0f;
	
	Vector pos;
	pos.Set( (engineInstantiation->map.staticobject[0].pos[0]+(engineInstantiation->map.staticobject[0].aabb[0].size[0]*0.5f)), (engineInstantiation->map.staticobject[0].pos[1]+(engineInstantiation->map.staticobject[0].aabb[0].size[1]*0.9f)), (engineInstantiation->map.staticobject[0].pos[2]+(engineInstantiation->map.staticobject[0].aabb[0].size[2]*0.5f)) );
	
	int i;
	
	float sndVolume = 0.0f;
	
	for( i = 0; i < sounds.size()-1; i++ )
	{
		if( sounds[i].Ended == true )
		{
			Sleep( 0 );
			sounds.erase( sounds.begin() + i );
			i--;
			continue;
		}
		
		if( (HearDistance*sounds[i].range) == 0.0f )
			continue;
		
		sndVolume = (pos-sounds[i].pos).Lenght();
		sndVolume = ( (HearDistance*sounds[i].range) - (sndVolume*sndVolume) ) / (HearDistance*sounds[i].range);
		
		if( sndVolume > 1.0f )
			sndVolume = 1.0f;
		if( sndVolume < 0.0f )
			sndVolume = 0.0f;
		if( sounds[i].snd != NULL )
			sounds[i].snd->setVolume( sndVolume );
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

inline void SoundEngine::PlaySound( char * src )
{
//	sounds.resize( sounds.size() + 1 );
//	int id = sounds.size() - 1;
	int i;
	
	for( i = 0; i < samples.size(); i++ )
	{
		if( !strcmp( src, samples[i].name ) )
		{
			/*sounds[id] = */SEngine->play2D( samples[i].source, false, false, false );
//			sounds[id] -> setSoundStopEventReceiver(myGlobalReceiver);
			break;
		}
	}
}

inline void SoundEngine::PlaySound( char * src, Vector origin )
{
	int i;
	for( i = 0; i < samples.size(); i++ )
	{
		if( !strcmp( src, samples[i].name ) )
		{
			{
				OneSample fastsnd;
				sounds.insert( sounds.begin(), fastsnd );
			}
			sounds[0].pos = origin;
			sounds[0].snd = SEngine->play2D( samples[i].source, false, false, true );
			sounds[0].snd -> setSoundStopEventReceiver(myGlobalReceiver);
			sounds[0].snd -> setVolume( 1.0f );
			break;
		}
	}
}

inline void SoundEngine::PlaySound( char * src, Vector origin, float range )
{
	int i;
	for( i = 0; i < samples.size(); i++ )
	{
		if( !strcmp( src, samples[i].name ) )
		{
			{
				OneSample fastsnd;
				sounds.insert( sounds.begin(), fastsnd );
			}
			sounds[0].pos = origin;
			sounds[0].range = range;
			sounds[0].snd = SEngine->play2D( samples[i].source, false, false, true );
			sounds[0].snd -> setSoundStopEventReceiver(myGlobalReceiver);
			sounds[0].snd -> setVolume( 1.0f );
			break;
		}
	}
}

SoundEngine::SoundEngine()
{
	sounds.resize( 1 );
	SEngine = NULL;
	HearDistance = 100.0f;
}

SoundEngine::~SoundEngine()
{
	DeInit();
}


