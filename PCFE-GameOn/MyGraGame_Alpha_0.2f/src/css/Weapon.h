
#ifndef WEAPON_H
#define WEAPON_H

class Weapon
{
public:
	StaticGraphicModel * model;
	char * name;
	int magazineCapacity;
	int ammoCapacity;
	float changeingCooldown;
	float shootingCooldown;
	float reloadingCooldown;
	
	inline void SetModel( StaticGraphicModel * src );
	inline void Draw();
	inline void SetName( const char * src );
	inline char * GetName();
	inline int GetMagazineCapacity();
	inline int GetAmmoCapacity();
	inline float GetChangeWeaponCooldown();
	inline float GetShootingCooldown();
	inline float GetReloadingCooldown();
	
	inline void Delete();
	
	Weapon();
	~Weapon();
};

#endif
