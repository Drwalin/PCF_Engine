


inline bool Object::IsItem()
{
	if( item != NULL )
		return true;
	return false;
}

inline bool Object::IsPlayer()
{
	if( player != NULL )
		return true;
	return false;
}

inline void Object::Update( float time )
{
	if( IsPlayer() )
	{
		player -> Update( time );
	}
	coolDownToPlayStepSound -= time;
	if( coolDownToPlayStepSound <= 0.0f )
	{
		if( (object->vel-Vector(0.0f,object->vel[1],0.0f)).Lenght() > 2.0f && object->CollisionDown )
		{
			char * soundName = new char[128];
			sprintf( soundName, "Grass_%i", (rand()%4)+1 );
			GameInstance -> engine.PlaySound( soundName, object->pos+(Vector(object->size[0],0.0f,object->size[2])*0.5f), 50.5f );
			delete[] soundName;
			coolDownToPlayStepSound = 0.7f + (float((rand()%1000)-300)/2500.0f);
		}
	}
}

inline void Object::DestroyInit()
{
	destroy = true;
}

inline bool Object::NeedDelete()
{
	return destroy;
}

inline void Object::Delete()
{
	object = NULL;
	destroy = false;
	item = NULL;
	if( player != NULL )
	{
		player -> Delete();
		delete player;
		player = NULL;
	}
}

Object::Object()
{
	object = NULL;
	destroy = false;
	item = NULL;
	player = NULL;
	coolDownToPlayStepSound = 0.0f;
}

Object::~Object()
{
	Delete();
	coolDownToPlayStepSound = 0.0f;
}


