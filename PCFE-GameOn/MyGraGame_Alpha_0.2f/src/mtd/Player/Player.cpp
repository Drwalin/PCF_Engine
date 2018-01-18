


inline void Player::DrawWeapon()
{
	Vector point;
	Vector rotation;
	VMatrix matrix;
	
	matrix.InitEmpty();
	matrix.RotateY( (object->see[0]+90.0f) );
	matrix.RotateX( -(object->see[1]) );
	point.Set( -0.2f, -0.2f, 0.5f );
	point = ( object->GetEyePos() + matrix.GetVertex( point ) );
	
	glTranslatef( point[0], point[1], point[2] );
	
	glRotatef( 90.0f+object->see[0], 0.0f, 1.0f, 0.0f );
	glRotatef( -object->see[1], 1.0f, 0.0f, 0.0f );
	
	glColor3ub( 255, 255, 255 );
	
	GameInstance -> weapon[weaponEquiped].Draw();
	
	glRotatef( object->see[1], 1.0f, 0.0f, 0.0f );
	glRotatef( -90.0f-object->see[0], 0.0f, 1.0f, 0.0f );
	
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


