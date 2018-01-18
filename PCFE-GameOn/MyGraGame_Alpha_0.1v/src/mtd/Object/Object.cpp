


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

inline bool Object::IsBullet()
{
	if( bullet != NULL )
		return true;
	return false;
}

inline void Object::Update( float time )
{
	if( IsPlayer() )
	{
		player -> Update( time );
	}
	if( IsBullet() )
	{
		bullet -> Update( time );
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
	if( bullet != NULL )
	{
		delete bullet;
		bullet = NULL;
	}
}

Object::Object()
{
	object = NULL;
	destroy = false;
	item = NULL;
	player = NULL;
	bullet = NULL;
}

Object::~Object()
{
	Delete();
}


