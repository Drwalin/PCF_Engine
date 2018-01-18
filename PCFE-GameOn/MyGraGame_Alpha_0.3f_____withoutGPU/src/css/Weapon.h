
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
	
	int shotSound;
	int reloadSound;
	
	float recoilUp;
	float recoilSide;
	
	int damageHead;
	int damageCorpus;
	int damageLegs;
	
	Vector moveWeaponInHand;
	Vector moveWeaponAfterShot;
	Vector rotateWeaponAfterShot;
	
	inline void SetShotSound( char * src );
	inline void SetReloadSound( char * src );
	inline void SetModel( StaticGraphicModel * src );
	inline void Draw();
	inline void SetName( char * src );
	inline char * GetName();
	inline int GetMagazineCapacity();
	inline int GetAmmoCapacity();
	inline float GetChangeWeaponCooldown();
	inline float GetShootingCooldown();
	inline float GetReloadingCooldown();
	inline void PlayShot( Vector src );
	inline void PlayReload( Vector src );
	
	inline void Delete();
	
	Weapon();
	~Weapon();
};

#endif
