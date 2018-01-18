


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

inline bool Object::NeedDelete()
{
	if( IsBullet() )
	{
		if( bullet -> destroy )
		{
			return true;
		}
	}
	else if( IsPlayer() )
	{
		if( player -> ai != NULL )
		{
			if( player -> Hp <= 0 )
			{
				return true;
			}
		}
	}
	else if( !IsItem() )
	{
		return true;
	}
	return false;
}

inline void Object::Delete()
{
	item = NULL;
	if( player != NULL )
	{
		player -> Delete();
		delete[] player;
		player = NULL;
	}
	if( bullet != NULL )
	{
		delete[] bullet;
		bullet = NULL;
	}
}

Object::Object()
{
	device = 0;
	item = NULL;
	player = NULL;
	bullet = NULL;
}

Object::~Object()
{
	Delete();
	device = 0;
	item = NULL;
	player = NULL;
	bullet = NULL;
}


