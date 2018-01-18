


inline void Player::ChangeWeaponTo( int id )
{
	if( weapon[id] == true )
	{
		weaponEquiped = id;
		cooldown = GameInstance->weapon[weaponEquiped]->GetChangeWeaponCooldown();
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


