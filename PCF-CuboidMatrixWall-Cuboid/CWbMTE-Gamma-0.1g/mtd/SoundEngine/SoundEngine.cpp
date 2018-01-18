


/////////////////////
// End playing sound:
class MySoundEndReceiver : public irrklang::ISoundStopEventReceiver
{
public:
	virtual void OnSoundStopped( irrklang::ISound * sound, irrklang::E_STOP_EVENT_CAUSE reason, void * userData )
	{
		while( soundEngineInstantiation->operatingOnSoundSources == true ){Delay(0);}
		soundEngineInstantiation->operatingOnSoundSources = true;
		int i;
		for( i = 0; i < soundEngineInstantiation->sounds.size(); i++ )
		{
			if( soundEngineInstantiation->sounds[i].snd == sound )
			{
				sound -> drop();
				soundEngineInstantiation->sounds[i].snd = NULL;
				soundEngineInstantiation->sounds.erase( soundEngineInstantiation->sounds.begin() + i );
				i--;
			}
		}
		soundEngineInstantiation->operatingOnSoundSources = false;
	}
};
MySoundEndReceiver* myGlobalReceiver = new MySoundEndReceiver();



//////////////////
// Sample Methods:

inline void SoundSampleSources::SetName( char * src )
{
	int l = strlen( src ), i, j = 0;
	int k = l;
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
	volume = 1.0f;
	range = 100.0f;
	snd = NULL;
	pos.Set( 0.0f, 0.0f, 0.0f );
	Ended = false;
}

OneSample::~OneSample()
{
	volume = 0.0f;
	range = 0.0f;
	pos.Set( 0.0f, 0.0f, 0.0f );
//	if( snd != NULL )
//		snd->drop();
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
	while( operatingOnSoundSources == true ){Delay(0);}
	operatingOnSoundSources = true;
	
	HearDistance = 100.0f;
	
	Vector pos;
	pos = engineInstance->Object(0)->GetEyePos();
	
	int i;
	
	float sndVolume = 0.0f;
	for( i = 0; i < sounds.size(); i++ )
	{
		if( sounds[i].range <= 0.0f )
		{
			sndVolume = 1.0f;
		}
		else
		{
			sndVolume = (pos-sounds[i].pos).Lenght();
			if( sndVolume == 0.0f )
			{
				sndVolume = 1.0f;
			}
			else if( sndVolume > sounds[i].range )
			{
				sndVolume = 0.0;
			}
			else
			{
				sndVolume = pow( ((double)(sndVolume-sounds[i].range))/((double)sounds[i].range), 2.0 );
			}
		}
		sndVolume *= sounds[i].volume * GlobalVolume;
		
		if( sndVolume > 1.0f )
			sndVolume = 1.0f;
		if( sndVolume < 0.0f )	
			sndVolume = 0.0f;
		
		if( sounds[i].snd != NULL )
			sounds[i].snd->setVolume( sndVolume );
	}
	operatingOnSoundSources = false;
}

inline void SoundEngine::AddSound( char * src )
{
	ifstream file;
	file.open( src );
	if( file.good() )
	{
		SoundSampleSources * pointer = new SoundSampleSources;
		pointer -> SetName( src );
		pointer -> source = SEngine->addSoundSourceFromFile( src );
		samples.push_back( pointer );
		pointer = NULL;
	}
}

inline void SoundEngine::PlaySound( float volume, char * src )
{
	while( operatingOnSoundSources == true ){Delay(0);}
	operatingOnSoundSources = true;
	
	int i;
	for( i = 0; i < samples.size(); i++ )
	{
		if( !strcmp( src, samples[i]->name ) )
		{
			sounds.resize( sounds.size() + 1 );
			sounds[sounds.size()-1].volume = volume;
			sounds[sounds.size()-1].range = -100.0f;
			sounds[sounds.size()-1].snd = SEngine->play2D( samples[i]->source, false, false, true );
			sounds[sounds.size()-1].snd -> setSoundStopEventReceiver(myGlobalReceiver);
			sounds[sounds.size()-1].snd -> setVolume( volume * GlobalVolume );
			break;
		}
	}
	operatingOnSoundSources = false;
}

inline void SoundEngine::PlaySound( float volume, char * src, Vector origin )
{
	while( operatingOnSoundSources == true ){Delay(0);}
	operatingOnSoundSources = true;
	
	int i;
	for( i = 0; i < samples.size(); i++ )
	{
		if( !strcmp( src, samples[i]->name ) )
		{
			sounds.resize( sounds.size() + 1 );
			sounds[sounds.size()-1].volume = volume;
			sounds[sounds.size()-1].pos = origin;
			sounds[sounds.size()-1].range = 100.0f;
			sounds[sounds.size()-1].snd = SEngine->play2D( samples[i]->source, false, false, true );
			sounds[sounds.size()-1].snd -> setSoundStopEventReceiver(myGlobalReceiver);
			sounds[sounds.size()-1].snd -> setVolume( volume * GlobalVolume );
			break;
		}
	}
	operatingOnSoundSources = false;
}

inline void SoundEngine::PlaySound( float volume, char * src, Vector origin, float range )
{
	while( operatingOnSoundSources == true ){Delay(0);}
	operatingOnSoundSources = true;
	
	int i;
	for( i = 0; i < samples.size(); i++ )
	{
		if( !strcmp( src, samples[i]->name ) )
		{
			sounds.resize( sounds.size() + 1 );
			sounds[sounds.size()-1].volume = volume;
			sounds[sounds.size()-1].pos = origin;
			sounds[sounds.size()-1].range = range;
			sounds[sounds.size()-1].snd = SEngine->play2D( samples[i]->source, false, false, true );
			sounds[sounds.size()-1].snd -> setSoundStopEventReceiver(myGlobalReceiver);
			sounds[sounds.size()-1].snd -> setVolume( volume * GlobalVolume );
			break;
		}
	}
	operatingOnSoundSources = false;
}

SoundEngine::SoundEngine()
{
	GlobalVolume = 1.0f;
	operatingOnSoundSources = false;
	SEngine = NULL;
	HearDistance = 100.0f;
}

SoundEngine::~SoundEngine()
{
	GlobalVolume = 0.0f;
	operatingOnSoundSources = false;
	DeInit();
}


