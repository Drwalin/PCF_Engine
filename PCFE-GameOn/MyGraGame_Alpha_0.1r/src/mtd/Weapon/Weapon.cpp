


inline void Weapon::SetName( const char * src )
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

Weapon::Weapon()
{
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


