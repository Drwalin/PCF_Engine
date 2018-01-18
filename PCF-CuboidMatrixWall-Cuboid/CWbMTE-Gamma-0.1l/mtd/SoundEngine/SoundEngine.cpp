


/////////////////////
// End playing sound:
class MySoundEndReceiver : public irrklang::ISoundStopEventReceiver
{
public:
	virtual void OnSoundStopped( irrklang::ISound * sound, irrklang::E_STOP_EVENT_CAUSE reason, void * userData )
	{
		sound -> drop();
		return;
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
	samples.resize( 0 );
}

inline void SoundEngine::Update()
{
	Vector pos;
	pos = engineInstance->Object(0)->GetEyePos();
	
	VMatrix matrix;
	
	matrix.InitEmpty();
	matrix.RotateY( (engineInstance->Object(0)->see[0]+90.0f) );
	matrix.RotateX( -(engineInstance->Object(0)->see[1]) );
	Vector look = matrix.GetVertex( SetVector( 0.0f, 0.0f, 1000.0f ) );
	Vector up = matrix.GetVertex( SetVector( 0.0f, 1000.0f, 0.0f ) );
	
	irrklang::vec3df position( pos[0], pos[1], pos[2] );			// position of the listener
	irrklang::vec3df lookDirection( look[0], look[1], look[2] );	// the direction the listener looks into
	irrklang::vec3df velPerSecond(0,0,0);							// only relevant for doppler effects
	irrklang::vec3df upVector( up[0], up[1], up[2] );				// where 'up' is in your 3D scene
	
	SEngine->setListenerPosition( position, lookDirection, velPerSecond, upVector );
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

inline void SoundEngine::PlaySound( float volume, int src )
{
	if( src < 0 || src >= samples.size() )
		return;
	
	irrklang::ISound * snd_ = NULL;
	
	snd_ = SEngine->play2D( samples[src]->source, false, false, true );
	snd_ -> setSoundStopEventReceiver(myGlobalReceiver);
	snd_ -> setVolume( volume * GlobalVolume );
	snd_ = NULL;
}

inline void SoundEngine::PlaySound( float volume, int src, Vector origin )
{
	if( src < 0 || src >= samples.size() )
		return;
	
	
	irrklang::ISound * snd_ = NULL;
	irrklang::vec3df position( origin[0], origin[1], origin[2] );
	
	snd_ = SEngine->play3D( samples[src]->source, position, false, false, true, false );
	snd_ -> setSoundStopEventReceiver(myGlobalReceiver);
	snd_ -> setMinDistance( 2.0f );
	snd_ -> setVolume( volume * GlobalVolume );
	snd_ = NULL;
}

inline void SoundEngine::PlaySound( float volume, int src, Vector origin, float range )
{
	if( src < 0 || src >= samples.size() )
		return;
	
	
	irrklang::ISound * snd_ = NULL;
	irrklang::vec3df position( origin[0], origin[1], origin[2] );
	
	snd_ = SEngine->play3D( samples[src]->source, position, false, false, true, false );
	snd_ -> setSoundStopEventReceiver(myGlobalReceiver);
	snd_ -> setMinDistance( 2.0f );
	snd_ -> setVolume( volume * GlobalVolume );
	snd_ = NULL;
}

inline void SoundEngine::PlaySound( float volume, char * src )
{
	int i;
	for( i = 0; i < samples.size(); i++ )
	{
		if( !strcmp( src, samples[i]->name ) )
		{
			PlaySound( volume, i );
			return;
		}
	}
}

inline void SoundEngine::PlaySound( float volume, char * src, Vector origin )
{
	int i;
	for( i = 0; i < samples.size(); i++ )
	{
		if( !strcmp( src, samples[i]->name ) )
		{
			PlaySound( volume, i, origin );
			return;
		}
	}
}

inline void SoundEngine::PlaySound( float volume, char * src, Vector origin, float range )
{
	int i;
	for( i = 0; i < samples.size(); i++ )
	{
		if( !strcmp( src, samples[i]->name ) )
		{
			PlaySound( volume, i, origin, range );
			return;
		}
	}
}

inline int SoundEngine::GetSoundId( char * src )
{
	int i;
	for( i = 0; i < samples.size(); i++ )
	{
		if( !strcmp( src, samples[i]->name ) )
		{
			return i;
		}
	}
	return -1;
}

SoundEngine::SoundEngine()
{
	GlobalVolume = 1.0f;
	SEngine = NULL;
}

SoundEngine::~SoundEngine()
{
	GlobalVolume = 0.0f;
	DeInit();
}


