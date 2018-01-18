


inline void Player::PrimaryAttack()
{
	if( cooldown <= 0.0f )
	{
		Vector point;
		VMatrix matrix;
		matrix.InitEmpty();
		matrix.RotateY( (object->see[0]+90.0f) );
		matrix.RotateX( -(object->see[1]) );
		point = GameInstance -> weapon[weaponEquiped].moveWeaponInHand;
		point = ( object->GetEyePos() + matrix.GetVertex( point ) );
		
		GameInstance -> weapon[weaponEquiped].PlayShot( point );
		cooldown = GameInstance -> weapon[weaponEquiped].shootingCooldown;
		shooting = true;
	}
}

inline void Player::SecondaryAttack()
{
	/*
	if( cooldown <= 0.0f )
	{
		cooldown = GameInstance -> weapon[weaponEquiped].shootingCooldown * 2.0f;
		shooting = true;
	}
	*/
}

inline void Player::Interaction()
{
	
}


