


inline void Player::DrawWeapon()
{
	Vector point;
	Vector rotation;
	VMatrix matrix;
	
	point = GameInstance -> weapon[weaponEquiped].moveWeaponInHand;
	rotation[0] = -object->see[1];
	rotation[1] = 90.0f+object->see[0];
	rotation[2] = 0.0f;
	
	if( shooting == true )
	{
		point += GameInstance -> weapon[weaponEquiped].moveWeaponAfterShot * sin( M_PI * cooldown / ( GameInstance -> weapon[weaponEquiped].shootingCooldown ) );
		rotation -= GameInstance -> weapon[weaponEquiped].rotateWeaponAfterShot * sin( M_PI * cooldown / ( GameInstance -> weapon[weaponEquiped].shootingCooldown ) );
	}
	
	matrix.InitEmpty();
	matrix.RotateY( (object->see[0]+90.0f) );
	matrix.RotateX( -(object->see[1]) );
	point = ( object->GetEyePos() + matrix.GetVertex( point ) );
	
	glTranslatef( point[0], point[1], point[2] );
	
	glRotatef( rotation[1], 0.0f, 1.0f, 0.0f );
	glRotatef( rotation[0], 1.0f, 0.0f, 0.0f );
	glRotatef( rotation[2], 0.0f, 0.0f, 1.0f );
	
	glColor3ub( 255, 255, 255 );
	
	GameInstance -> weapon[weaponEquiped].Draw();
	
	glRotatef( -rotation[2], 0.0f, 0.0f, 1.0f );
	glRotatef( -rotation[0], 1.0f, 0.0f, 0.0f );
	glRotatef( -rotation[1], 0.0f, 1.0f, 0.0f );
	
	glTranslatef( -point[0], -point[1], -point[2] );
}

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
	shooting = false;
}

inline void Player::Init()
{
	Delete();
	weaponEquiped = HAND;
	ammo = new int[GameInstance->weapon.size()];
	weapon = new bool[GameInstance->weapon.size()];
	ammoLoaded = new int[GameInstance->weapon.size()];
	int i;
	for( i = 0; i < GameInstance->weapon.size(); ++i )
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
	shooting = false;
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


