


/////////////////////
// End playing sound:
class MySoundEndReceiver : public irrklang::ISoundStopEventReceiver
{
public:
	virtual void OnSoundStopped( irrklang::ISound * sound, irrklang::E_STOP_EVENT_CAUSE reason, void * userData )
	{
		int i;
		for( i = 0; i < soundEngineInstantiation->sounds.size(); i++ )
		{
			if( soundEngineInstantiation->sounds[i].snd == sound )
			{
				sound->drop();
				soundEngineInstantiation->sounds.erase( soundEngineInstantiation->sounds.begin() + i );
				i--;
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
		source->drop();
	if( name != NULL )
		delete[] name;
}



////////////////
// Sound Sample:

OneSample::OneSample()
{
	snd = NULL;
	pos.Set( 0.0f, 0.0f, 0.0f );
}

OneSample::~OneSample()
{
	pos.Set( 0.0f, 0.0f, 0.0f );
	if( snd != NULL )
		snd->drop();
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
inline void SoundEngine::AddSound( char * src )
{
	samples.resize( samples.size() + 1 );
	int id = samples.size() - 1;
	int i;
	
	samples[id].SetName( src );
	samples[id].source = SEngine->addSoundSourceFromFile( src );
}

inline void SoundEngine::Update()
{
	HearDistance = 100.0f;
	
	Vector pos;
	pos.Set( (engineInstantiation->map.staticobject[0].pos[0]+(engineInstantiation->map.staticobject[0].aabb[0].size[0]*0.5f)), (engineInstantiation->map.staticobject[0].pos[1]+(engineInstantiation->map.staticobject[0].aabb[0].size[1]*0.9f)), (engineInstantiation->map.staticobject[0].pos[2]+(engineInstantiation->map.staticobject[0].aabb[0].size[2]*0.5f)) );
	
	int i;
	
	float sndVolume = 0.0f;
	
	for( i = 0; i < samples.size(); i++ )
	{
		sndVolume = (pos-sounds[i].pos).Lenght();
		sndVolume = (HearDistance-sndVolume) / HearDistance;
		
		if( sndVolume > 1.0f )
			sndVolume = 1.0f;
		if( sndVolume < 0.0f )
			sndVolume = 0.0f;
		if( sounds[i].snd != NULL )
			sounds[i].snd->setVolume( sndVolume );
	}
	
//	irrklang::vec3df position( pos[0], pos[1], pos[2] );				// position of the listener
//	irrklang::vec3df lookDirection( look[0], look[1], look[2] );		// the direction the listener looks into
//	irrklang::vec3df velPerSecond(0,0,0);								// only relevant for doppler effects
//	irrklang::vec3df upVector( up[0], up[1], up[2] );					// where 'up' is in your 3D scene
//	SEngine->setListenerPosition( position, lookDirection, velPerSecond, upVector);
}

inline void SoundEngine::PlaySound( char * src, Vector origin )
{
	sounds.resize( sounds.size() + 1 );
	int id = sounds.size() - 1;
	int i;
	
	for( i = 0; i < samples.size(); i++ )
	{
		if( !strcmp( src, samples[i].name ) )
		{
			sounds[id].snd = SEngine->play2D( samples[i].source, false, false, true );
			sounds[id].snd -> setSoundStopEventReceiver(myGlobalReceiver);
			sounds[id].snd -> setVolume( 1.0f );
			sounds[id].pos = origin;
			break;
		}
	}
}

SoundEngine::SoundEngine()
{
	SEngine = NULL;
	HearDistance = 100.0f;
}

SoundEngine::~SoundEngine()
{
	DeInit();
}


