


#define WASTE (4.0f/7.0f)
#define NECK (6.0f/7.0f)

inline void Player::PrimaryAttack( bool keyPressed, float time )
{
	if( cooldown <= 0.0f )
	{
		if( ammoLoaded[weaponEquiped] > 0 )
		{
			ammoLoaded[weaponEquiped]--;
			
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
				matrix.RotateY( object->see[0] + 90.0f + (RandFloat( -rotatePlus.Lenght(), rotatePlus.Lenght() )*0.6f) );
				matrix.RotateX( -object->see[1] + (RandFloat( -rotatePlus.Lenght(), rotatePlus.Lenght() )*0.6f) );
				
				float weaponRange = 300.0f;
				
				Vector beg, end;
				beg = object -> GetEyePos();
				end = beg + matrix.GetVertex( SetVector( 0.0f, 0.0f, weaponRange ) );
				
				GameInstance->engine.SegmentCollision( beg, end, &objectAttacked, &triangle, GameInstance->engine.Object(0), SHOT );
				
				if( objectAttacked != NULL )
				{
					Object * obj_ = (Object*) (objectAttacked -> GetGameLogicObject());
					Vector contactPoint;
					Collision collision;
					collision.RayAABB( beg, end, objectAttacked, &contactPoint );
					
						
					if( obj_ -> IsPlayer() )
					{
						int damage;
						float height;
						height = contactPoint[1] - objectAttacked->pos[1];
						height = height / objectAttacked->size[1];
						
						if( height <= WASTE )
						{
							damage = GameInstance -> weapon[weaponEquiped].damageLegs;
						}
						else if( height <= NECK )
						{
							damage = GameInstance -> weapon[weaponEquiped].damageCorpus;
						}
						else
						{
							damage = GameInstance -> weapon[weaponEquiped].damageHead;
							GameInstance -> engine.PlaySound( "headshot", contactPoint, 0.88f );
						}
						
						if( weaponEquiped >= 2 )
							damage = int( float(damage) * (weaponRange-((beg-contactPoint).Lenght())) / weaponRange );
						
						(obj_ -> player -> Hp) -= damage;
						
						GameInstance->engine.map.particles.AddParticle( contactPoint, 0.02f, (beg-contactPoint).Versor() * 0.25f, SetVector(0.0f,-0.2f,0.0f), 0.03f, 220, 20, 20, 20, 20, 20, 2.25f, 0.5f, RandInt( 5, 10 ) );
					}
					else if( obj_ -> IsItem() )
					{
						GameInstance->engine.map.particles.AddParticle( contactPoint, 0.02f, (beg-contactPoint).Versor() * 0.25f, SetVector(0.0f,-0.2f,0.0f), 0.03f, 120, 120, 120, 20, 20, 20, 2.75f, 0.5f, RandInt( 5, 10 ) );
					}
					
					if( obj_ -> object != NULL )
					{
						obj_ -> object -> vel += (contactPoint-beg).Versor() * sqrt( 470.0f / ( obj_ -> object -> mass ) ) * (weaponRange-((contactPoint-beg).Lenght())) / weaponRange;
					}
				}
				else if( triangle != NULL )
				{
					Vector contactPoint;
					Collision collision;
					collision.RayTriangle( beg, end, triangle, &contactPoint );
					
					GameInstance->engine.map.particles.AddParticle( contactPoint, 0.02f, (beg-contactPoint).Versor() * 0.25f, SetVector(0.0f,-0.2f,0.0f), 0.03f, 120, 120, 120, 40, 40, 10, 2.25f, 0.5f, RandInt( 5, 10 ) );
					
					// play sound "shot_wall" in contactPoint
				}
			}
			
			rotateVelocity[1] = float( rand() % int( abs( GameInstance -> weapon[weaponEquiped].recoilUp * 5.0f ) ) ) * ( GameInstance -> weapon[weaponEquiped].recoilUp < 0.0f ? -1.0f : 1.0f ) / 7.0f;
			rotateVelocity[0] = ( float( rand() % int( abs( GameInstance -> weapon[weaponEquiped].recoilSide * 5.0f * 2.0f ) ) ) - abs( GameInstance -> weapon[weaponEquiped].recoilSide * 5.0f ) ) / 7.0f;
		}
		else if( ( keyPressed || ( cooldown <= 0.0f && cooldown + time > 0.0f ) ) && ammoLoaded[weaponEquiped] <= 0 )
		{
			Vector point;
			VMatrix matrix;
			matrix.InitEmpty();
			matrix.RotateY( (object->see[0]+90.0f) );
			matrix.RotateX( -(object->see[1]) );
			point = GameInstance -> weapon[weaponEquiped].moveWeaponInHand;
			point = ( object->GetEyePos() + matrix.GetVertex( point ) );
			
			GameInstance -> engine.PlaySound( "emptyclip", point, 1.69f );
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


