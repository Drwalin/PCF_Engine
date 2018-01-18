


/////////////////////
// End playing sound:
class MySoundEndReceiver : public irrklang::ISoundStopEventReceiver
{
public:
	virtual void OnSoundStopped( irrklang::ISound * sound, irrklang::E_STOP_EVENT_CAUSE reason, void * userData )
	{
		while( soundEngineInstantiation->operatingOnSoundSources == true ){Sleep(0);}
		soundEngineInstantiation->operatingOnSoundSources = true;
		int i;
		for( i = 0; i < soundEngineInstantiation->sounds.size(); i++ )
		{
			if( soundEngineInstantiation->sounds[i].snd == sound )
			{
				soundEngineInstantiation->sounds[i].Ended = true;
				
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
	while( operatingOnSoundSources == true ){Sleep(0);}
	operatingOnSoundSources = true;
	
	HearDistance = 100.0f;
	
	Vector pos;
	pos.Set( (engineInstantiation->map.staticobject[0].pos[0]+(engineInstantiation->map.staticobject[0].aabb[0].size[0]*0.5f)), (engineInstantiation->map.staticobject[0].pos[1]+(engineInstantiation->map.staticobject[0].aabb[0].size[1]*0.9f)), (engineInstantiation->map.staticobject[0].pos[2]+(engineInstantiation->map.staticobject[0].aabb[0].size[2]*0.5f)) );
	
	int i;
	
	float sndVolume = 0.0f;
	
	for( i = 0; i < sounds.size(); i++ )
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
	operatingOnSoundSources = false;
}

inline void SoundEngine::AddSound( char * src )
{
	SoundSampleSources * pointer = new SoundSampleSources;
	pointer -> SetName( src );
	pointer -> source = SEngine->addSoundSourceFromFile( src );
	samples.push_back( pointer );
	pointer = NULL;
	
}

inline void SoundEngine::PlaySound( char * src )
{
	while( operatingOnSoundSources == true ){Sleep(0);}
	operatingOnSoundSources = true;
	
	int i;
	for( i = 0; i < samples.size(); i++ )
	{
		if( !strcmp( src, samples[i]->name ) )
		{
			/*sounds[id] = */SEngine->play2D( samples[i]->source, false, false, false );
//			sounds[id] -> setSoundStopEventReceiver(myGlobalReceiver);
			break;
		}
	}
	operatingOnSoundSources = false;
}

inline void SoundEngine::PlaySound( char * src, Vector origin )
{
	while( operatingOnSoundSources == true ){Sleep(0);}
	operatingOnSoundSources = true;
	
	int i;
	for( i = 0; i < samples.size(); i++ )
	{
		if( !strcmp( src, samples[i]->name ) )
		{
			OneSample fastsnd;
			sounds.push_back( fastsnd );
			sounds[sounds.size()-1].pos = origin;
			sounds[sounds.size()-1].range = 100.0f;
			sounds[sounds.size()-1].snd = SEngine->play2D( samples[i]->source, false, false, true );
			sounds[sounds.size()-1].snd -> setSoundStopEventReceiver(myGlobalReceiver);
			sounds[sounds.size()-1].snd -> setVolume( 0.1f );
			break;
		}
	}
	operatingOnSoundSources = false;
}

inline void SoundEngine::PlaySound( char * src, Vector origin, float range )
{
	while( operatingOnSoundSources == true ){Sleep(0);}
	operatingOnSoundSources = true;
	
	int i;
	for( i = 0; i < samples.size(); i++ )
	{
		if( !strcmp( src, samples[i]->name ) )
		{
			OneSample fastsnd;
			fastsnd.pos = origin;
			fastsnd.range = range;
			fastsnd.snd = SEngine->play2D( samples[i]->source, false, false, true );
			fastsnd.snd -> setSoundStopEventReceiver(myGlobalReceiver);
			fastsnd.snd -> setVolume( 0.1f );
			sounds.push_back( fastsnd );
			fastsnd.snd = NULL;
			break;
		}
	}
	operatingOnSoundSources = false;
}

SoundEngine::SoundEngine()
{
	operatingOnSoundSources = false;
	SEngine = NULL;
	HearDistance = 100.0f;
}

SoundEngine::~SoundEngine()
{
	operatingOnSoundSources = false;
	DeInit();
}


