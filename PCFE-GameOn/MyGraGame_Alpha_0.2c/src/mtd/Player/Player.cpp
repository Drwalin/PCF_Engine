


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

inline void Player::Init()
{
	Delete();
	weaponEquiped = HAND;
	ammo = new int[WEAPONS_NUMBER];
	weapon = new bool[WEAPONS_NUMBER];
	ammoLoaded = new int[WEAPONS_NUMBER];
	int i;
	for( i = 0; i < WEAPONS_NUMBER; ++i )
	{
		weapon[i] = false;
		ammo[i] = 0;
		ammoLoaded[i] = 0;
	}
	handRange = 2.0f;
	Hp = 100;
	maxHp = 100;
	Energy = 0;
	maxEnergy = 100;
	team = 0;
}

Player::Player()
{
	team = 0;
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


