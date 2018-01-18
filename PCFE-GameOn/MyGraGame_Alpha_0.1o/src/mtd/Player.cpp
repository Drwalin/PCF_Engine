

inline void PlayerUpdate( float time )
{
	
}

inline void AIUpdate( float time )
{
	
}

inline void Update( float time )
{
	
}

inline void PrimaryAttack()
{
	
}

inline void SecondaryAttack()
{
	
}

inline void Reload()
{
	
}

inline void Interaction()
{
	
}

inline void Delete()
{
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

inline void Init( Player * src, Object * parent )
{
	Delete();
	if( src -> ai != NULL )
		ai = new AI;
	else 
		ai = NULL;
	weaponEquiped = HAND;
	weapon = new bool[WEAPONS_NUMBER];
	ammo = new int[WEAPONS_NUMBER];
	ammoLoaded = new int[WEAPONS_NUMBER];
	handRange = src -> handRange;
	Hp = src -> Hp;
	maxHp = src -> maxHp;
	Energy = src -> Energy;
	maxEnergy = src -> maxEnergy;
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


