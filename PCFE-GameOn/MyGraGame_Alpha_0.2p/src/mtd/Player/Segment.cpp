


#define WASTE (4.0f/7.0f)
#define NECK (6.0f/7.0f)

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
		
		{	// bullet ray-tracing
			TrianglePX * triangle;
			PhysicModelStatic * objectAttacked;
			VMatrix matrix;
			matrix.InitEmpty();
			matrix.RotateY( object->see[0] + 90.0f );
			matrix.RotateX( -object->see[1] );
			
			float weaponRange = 300.0f;
			
			Vector beg, end;
			beg = object -> GetEyePos();
			end = beg + matrix.GetVertex( SetVector( 0.0f, 0.0f, weaponRange ) );
			
			GameInstance->engine.SegmentCollision( beg, end, &objectAttacked, &triangle, GameInstance->engine.Object(0), SHOT );
			
			if( objectAttacked != NULL )
			{
				Vector contactPoint;
				Collision collision;
				collision.RayAABB( beg, end, objectAttacked, &contactPoint );
				
				float height;
				height = contactPoint[1] - objectAttacked->pos[1];
				height = height / objectAttacked->size[1];
				
				if( height <= WASTE )
					damage = GameInstance -> weapon[weaponEquiped].damageLegs;
				else if( height <= NECK )
					damage = GameInstance -> weapon[weaponEquiped].damageCorpus;
				else
					damage = GameInstance -> weapon[weaponEquiped].damageHead;
				
				damage = int( float(damage) * (beg-end).Lenght() / weaponRange );
			}
		}
	}
}

inline void Player::SecondaryAttack()
{
	
}

inline void Player::Interaction()
{
	
}

#undef WASTE
#undef NECK


