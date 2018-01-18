


#define WASTE (4.0f/7.0f)
#define NECK (6.0f/7.0f)
inline void Bullet::Update( float time )
{
	Vector bpos = pos;
	vel[1] -= 9.81f * time;
	vel.GoToLenght( 0.0f, 3.11f * time );	// decelerate by air resist
	pos += vel * time;
	
	TrianglePX * triangle;
	PhysicModelStatic * object;
	
	GameInstance->engine.SegmentCollision( bpos, pos, &object, &triangle, NULL, SHOOT );
	
	if( object != NULL )
	{
		int damage = 0;
		{
			Collision collision;
			Vector point;
			collision.RayAABB( bpos, pos, object, &point );
			float height;
			height = point[1] - object->pos[1];
			height = height / object->size[1];
			
			if( height <= WASTE )
				damage = damageBaseLegs;
				else if( height <= NECK )
			damage = damageBaseCorpus;
			else
				damage = damageBaseHead;
			
			damage = int( float(damage) * vel.Lenht() / baseVelocity );
		}
		
		Player * player;
		void * obj = object -> GetGameLogicObject();
		
		if( obj -> IsPlayer() || obj -> IsItem() )
			object -> vel += vel * mass / ( object -> GetMass() );
		
		if( obj -> IsPlayer() )
			obj -> player -> Hp -= damage;
		
		parent -> destroy = true;
	}
	else if( triangle != NULL )
	{
		parent -> destroy = true;
	}
}
#undef WASTE
#undef NECK

inline void Bullet::Init( Vector pos_, Vector vel_, float baseVel_, int head, int corpus, int legs, float mass_, Object * parent_ )
{
	parent = parent_;
	parent -> destroy = false;
	mass = mass_;
	pos = pos_;
	vel = vel_;
	baseVelocity = baseVel_;
	damageBaseHead = head;
	damageBaseCorpus = corpus;
	damageBaseLegs = legs;
}

Bullet::Bullet()
{
	mass = 0.001f;
	pos.Set( 0.0f, 0.0f, 0.0f );
	vel.Set( 0.0f, 0.0f, 0.0f );
	baseVelocity = 0.0f;
	damageBaseHead = 0;
	damageBaseCorpus = 0;
	damageBaseLegs = 0;
	parent = NULL;
}

Bullet::~Bullet()
{
	mass = 0.0f;
	pos.Set( 0.0f, 0.0f, 0.0f );
	vel.Set( 0.0f, 0.0f, 0.0f );
	baseVelocity = 0.0f;
	damageBaseHead = 0;
	damageBaseCorpus = 0;
	damageBaseLegs = 0;	
	parent = NULL;
}


