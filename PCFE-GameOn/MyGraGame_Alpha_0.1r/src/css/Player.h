
#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
	PhysicModelStatic * object;
	Object * parent;
	AI * ai;
	
	int Hp;
	int maxHp;
	int Energy;
	int maxEnergy;
	
	float cooldown;		// after: attack, change weapon, reload
	
	float handRange;
	
	bool * weapon;
	int * ammo;
	int * ammoLoaded;
	
	int weaponEquiped;
	
	inline void PlayerUpdate( float time );
	inline void AIUpdate( float time );
	inline void Update( float time );
	
	inline void ChangeWeaponTo( int id );
	
	inline void Reload();
	inline void PrimaryAttack();
	inline void SecondaryAttack();
	
	inline void Interaction();
	
	inline void Delete();
	
	inline void Init( int weaponNumberSrc );
	
	Player();
	~Player();
};

#endif
