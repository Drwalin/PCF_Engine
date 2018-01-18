


inline void Weapon::Draw()
{
	if( model != NULL )
		model -> Draw();
}

inline void Weapon::SetShotSound( char * src )
{
	shotSound = GameInstance -> engine.GetSoundId( src );
}

inline void Weapon::SetReloadSound( char * src )
{
	reloadSound = GameInstance -> engine.GetSoundId( src );
}

inline void Weapon::SetModel( StaticGraphicModel * src )
{
	model = src;
}

inline void Weapon::SetName( char * src )
{
	if( name != NULL )
		delete[] name;
	int i, l = strlen(src);
	name = new char[l+1];
	for( i = 0; i < l; ++i )
		name[i] = src[i];
	name[i] = 0;
}

inline void Weapon::Delete()
{
	recoilUp = 0.0f;
	recoilSide = 0.0f;
	moveWeaponInHand.Set( 0.0f, 0.0f, 0.0f );
	moveWeaponAfterShot.Set( 0.0f, 0.0f, 0.0f );
	rotateWeaponAfterShot.Set( 0.0f, 0.0f, 0.0f );
	shotSound = 0;
	reloadSound = 0;
	model = NULL;
	if( name != NULL )
		delete[] name;
	name = NULL;
	magazineCapacity = 0;
	ammoCapacity = 0;
	changeingCooldown = 0.0f;
	shootingCooldown = 0.0f;
	reloadingCooldown = 0.0f;
}

inline char * Weapon::GetName()
{
	return name;
}

inline int Weapon::GetMagazineCapacity()
{
	return magazineCapacity;
}

inline int Weapon::GetAmmoCapacity()
{
	return ammoCapacity;
}

inline float Weapon::GetChangeWeaponCooldown()
{
	return changeingCooldown;
}

inline float Weapon::GetShootingCooldown()
{
	return shootingCooldown;
}

inline float Weapon::GetReloadingCooldown()
{
	return reloadingCooldown;
}


inline void Weapon::PlayShot( Vector src )
{
	printf( "play_ " );
	GameInstance -> engine.PlaySound( 1.0f, shotSound, src );
	printf( " ...played " );
}

inline void Weapon::PlayReload( Vector src )
{
	GameInstance -> engine.PlaySound( 1.0f, reloadSound, src );
}

Weapon::Weapon()
{
	shotSound = -1;
	reloadSound = -1;
	recoilUp = 0.0f;
	recoilSide = 0.0f;
	moveWeaponInHand.Set( -0.2f, -0.2f, 0.5f );
	moveWeaponAfterShot.Set( 0.0f, 0.0f, 0.0f );
	rotateWeaponAfterShot.Set( 0.0f, 0.0f, 0.0f );
	model = NULL;
	name = NULL;
	magazineCapacity = 0;
	ammoCapacity = 0;
	changeingCooldown = 0.0f;
	shootingCooldown = 0.0f;
	reloadingCooldown = 0.0f;
}

Weapon::~Weapon()
{
	Delete();
}


