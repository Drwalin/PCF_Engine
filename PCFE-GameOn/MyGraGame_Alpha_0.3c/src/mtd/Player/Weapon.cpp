


inline void Player::ChangeWeaponTo( int id )
{
	if( weapon[id] == true )
	{
		weaponEquiped = id;
		weaponEquiped %= GameInstance->weapon.size();
		cooldown = GameInstance -> weapon[weaponEquiped].GetChangeWeaponCooldown();
		shooting = false;
	}
}

inline void Player::Reload()
{
	if( cooldown <= 0.0f )
	{
		if( ammo[weaponEquiped] > 0 && ammoLoaded[weaponEquiped] < GameInstance->weapon[weaponEquiped].GetMagazineCapacity() )
		{
			if( ammo[weaponEquiped] >= GameInstance->weapon[weaponEquiped].GetMagazineCapacity() - ammoLoaded[weaponEquiped] )
			{
				ammoLoaded[weaponEquiped] += GameInstance->weapon[weaponEquiped].GetMagazineCapacity() - ammoLoaded[weaponEquiped];
				ammo[weaponEquiped] -= GameInstance->weapon[weaponEquiped].GetMagazineCapacity() - ammoLoaded[weaponEquiped];
			}
			else
			{
				ammoLoaded[weaponEquiped] += ammo[weaponEquiped];
				ammo[weaponEquiped] = 0;
			}
			cooldown = GameInstance->weapon[weaponEquiped].GetReloadingCooldown();
			
			Vector point;
			VMatrix matrix;
			matrix.InitEmpty();
			matrix.RotateY( (object->see[0]+90.0f) );
			matrix.RotateX( -(object->see[1]) );
			point = GameInstance -> weapon[weaponEquiped].moveWeaponInHand;
			point = ( object->GetEyePos() + matrix.GetVertex( point ) );
			
			GameInstance -> weapon[weaponEquiped].PlayReload( point );
			
			shooting = false;
		}
	}
}


