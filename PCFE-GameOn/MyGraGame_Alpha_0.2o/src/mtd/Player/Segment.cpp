


inline void Player::PrimaryAttack()
{
	if( cooldown <= 0.0f )
	{
		rotateVelocity[1] = float( rand() % int( abs( GameInstance -> weapon[weaponEquiped].recoilUp * 5.0f ) ) ) * ( GameInstance -> weapon[weaponEquiped].recoilUp < 0.0f ? -1.0f : 1.0f ) / 5.0f;
		rotateVelocity[0] = ( float( rand() % int( abs( GameInstance -> weapon[weaponEquiped].recoilSide * 5.0f * 2.0f ) ) ) - abs( GameInstance -> weapon[weaponEquiped].recoilSide * 5.0f ) ) / 5.0f;
		
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
	
}

inline void Player::Interaction()
{
	
}


