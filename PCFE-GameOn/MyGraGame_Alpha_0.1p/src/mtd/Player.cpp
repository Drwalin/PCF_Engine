

inline void Player::PlayerUpdate( float time )
{
	
}

inline void Player::AIUpdate( float time )
{
	ai -> Update( time );
}

inline void Player::Update( float time )
{
	cooldown -= time;
	if( ai != NULL )
	{
		AIUpdate( time );
	}
	else
	{
		PlayerUpdate( time );
	}
}

inline void Player::ChangeWeaponTo( int id )
{
	if( cooldown <= 0.0f )
	{
		if( weapon[id] == true )
		{
			weaponEquiped = id;
			cooldown = GameInstance->weapon[weaponEquiped]->GetChangeWeaponCooldown();
		}
	}
}

inline void Player::Reload()
{
	if( cooldown <= 0.0f )
	{
		if( ammo[weaponEquiped] > 0 && ammoLoaded[weaponEquiped] < GameInstance->weapon[weaponEquiped]->GetMagazineCapacity() )
		{
			if( ammo[weaponEquiped] >= GameInstance->weapon[weaponEquiped]->GetMagazineCapacity() - GameInstance->weapon[weaponEquiped]->GetMagazineCapacity() )
			{
				ammoLoaded[weaponEquiped] += GameInstance->weapon[weaponEquiped]->GetMagazineCapacity() - GameInstance->weapon[weaponEquiped]->GetMagazineCapacity();
				ammo[weaponEquiped] -= GameInstance->weapon[weaponEquiped]->GetMagazineCapacity() - GameInstance->weapon[weaponEquiped]->GetMagazineCapacity();
			}
			else
			{
				ammoLoaded[weaponEquiped] += ammo[weaponEquiped];
				ammo[weaponEquiped] = 0;
			}
			cooldown = GameInstance->weapon[weaponEquiped]->GetReloadingCooldown();
		}
	}
}

inline void Player::PrimaryAttack()
{
	
}

inline void Player::SecondaryAttack()
{
	
}

inline void Player::Interaction()
{
	
}

inline void Player::Delete()
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

inline void Player::Init( Player * src, Object * parent )
{
	Delete();
	if( src -> ai != NULL )
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


