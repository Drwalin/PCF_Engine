


/////////////////////
// End playing sound:
class MySoundEndReceiver : public irrklang::ISoundStopEventReceiver
{
public:
	virtual void OnSoundStopped( irrklang::ISound * sound, irrklang::E_STOP_EVENT_CAUSE reason, void * userData )
	{
//		int i;
//		for( i = 0; i < soundEngineInstantiation->sounds.size(); i++ )
//		{
//			if( soundEngineInstantiation->sounds[i] == sound )
//			{
		sound->drop();
//				soundEngineInstantiation->sounds.erase( soundEngineInstantiation->sounds.begin() + i );
//				i--;
//			}
//		}
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

inline void SoundEngine::Update()
{
	VMatrix matrix;
	matrix.InitEmpty();
	matrix.RotateY( (engineInstantiation->map.staticobject[0].see[0]+90.0f) );
	matrix.RotateX( -(engineInstantiation->map.staticobject[0].see[1]) );
	Vector look = matrix.GetVertex( SetVector( 0.0f, 0.0f, 100.0f ) );
	Vector up = matrix.GetVertex( SetVector( 0.0f, 100.0f, 0.0f ) );
	Vector pos;
	pos.Set( (engineInstantiation->map.staticobject[0].pos[0]+(engineInstantiation->map.staticobject[0].aabb[0].size[0]*0.5f)), (engineInstantiation->map.staticobject[0].pos[1]+(engineInstantiation->map.staticobject[0].aabb[0].size[1]*0.9f)), (engineInstantiation->map.staticobject[0].pos[2]+(engineInstantiation->map.staticobject[0].aabb[0].size[2]*0.5f)) );
	
	irrklang::vec3df position( pos[0], pos[1], pos[2] );				// position of the listener
	irrklang::vec3df lookDirection( look[0], look[1], look[2] );		// the direction the listener looks into
	irrklang::vec3df velPerSecond(0,0,0);								// only relevant for doppler effects
	irrklang::vec3df upVector( up[0], up[1], up[2] );					// where 'up' is in your 3D scene
	SEngine->setListenerPosition( position, lookDirection, velPerSecond, upVector);
}

inline void SoundEngine::PlaySound( char * src, Vector origin )
{
	irrklang::vec3df position( origin[0], origin[1], origin[2] );
	int i;
	
	HearDistance = 10.0f;
	
	for( i = 0; i < samples.size(); i++ )
	{
		if( !strcmp( src, samples[i].name ) )
		{
			irrklang::ISound * fastsound = SEngine->play3D( samples[i].source, irrklang::vec3df( origin[0], origin[1], origin[2] ), false, false, true );
			fastsound -> setMinDistance(HearDistance);
			fastsound -> setSoundStopEventReceiver(myGlobalReceiver);
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


