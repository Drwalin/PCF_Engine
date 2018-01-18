


inline void Player::Delete()
{
	if( object != NULL )
	{
		GameInstance -> engine.DeleteObject( object->MainVectorId );
	}
	object = NULL;
	parent = NULL;
	if( ai != NULL )
	{
		ai -> Delete();
		delete ai;
	}
	ai = NULL;
	Hp = 0;
	maxHp = 0;
	Energy = 0;
	maxEnergy = 0;
	cooldown = 0.0f;		// after: attack, change weapon, reload
	handRange = 0.f;
	if( weapon != NULL )
		delete[] weapon;
	if( ammo != NULL )
		delete[] ammo;
	if( ammoLoaded != NULL )
		delete[] ammoLoaded;
	weapon = NULL;
	ammo = NULL;
	ammoLoaded = NULL;
	int weaponEquiped = 0;
}

inline void Player::Init( bool AI_, Object * parent, itn maxHp_, int maxEnergy_, float handRange_ )
{
	Delete();
	if( AI_ )
	{
		ai = new AI;
		ai -> parent = this;
	}
	else 
	{
		ai = NULL;
	}
	weaponEquiped = HAND;
	weapon = new bool[WEAPONS_NUMBER];
	ammo = new int[WEAPONS_NUMBER];
	ammoLoaded = new int[WEAPONS_NUMBER];
	handRange = handRange_;
	Hp = maxHp_;
	maxHp = maxHp_;
	Energy = maxEnergy_;
	maxEnergy = maxEnergy_;
}

Player::Player()
{
	object = NULL;
	parent = NULL;
	ai = NULL;
	Hp = 0;
	maxHp = 0;
	Energy = 0;
	maxEnergy = 0;
	cooldown = 0.0f;		// after: attack, change weapon, reload
	handRange = 1.0f;
	weapon = NULL;
	ammo = NULL;
	ammoLoaded = NULL;
	int weaponEquiped = 0;
}

Player::~Player()
{
	Delete();
}


