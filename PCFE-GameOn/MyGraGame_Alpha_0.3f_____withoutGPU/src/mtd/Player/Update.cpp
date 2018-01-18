


inline void Player::PlayerUpdate( float time )
{
	if( object != NULL )
	{
		VMatrix matrix;
		matrix.InitEmpty();
		matrix.RotateY( (object->see[0]+90.0f) );
		Vector forward;
		forward.Set( 0.0f, 0.0f, FORCE_DEFINE * (float( object->CollisionDown ? 1.0f : 0.2f ) * float(object->size[1] > 1.1f ? 1.0f : 0.4f)) );
		
		if( keyboardobiect.downkeypressed[ '2' ] )
		{
			ChangeWeaponTo( 2 );
		}
		
		if( keyboardobiect.downkeypressed[ '3' ] )
		{
			ChangeWeaponTo( 3 );
		}
		
		if( keyboardobiect.downkeypressed[ 'P' ] )
		{
			GameInstance->UseMouse = !GameInstance->UseMouse;
		}
		
		if( keyboardobiect.keypressed[GameInstance->PrimaryAttack] )
		{
			PrimaryAttack( keyboardobiect.downkeypressed[GameInstance->PrimaryAttack], time );
		}
		
		if( keyboardobiect.downkeypressed[GameInstance->Reload] )
		{
			Reload();
		}
		
		if( keyboardobiect.keypressed[GameInstance->MoveForward] ) // Move Forward
		{
			if( object->vel.Dot( matrix.GetVertex( forward )/(forward.Lenght()) ) <= MAX_VELOCITY_DEFINE )
				object->force += matrix.GetVertex( forward );
		}
		
		if( keyboardobiect.keypressed[GameInstance->MoveBackward] ) // Move Backward
		{
			if( object->vel.Dot( 0.0f-matrix.GetVertex( forward )/(forward.Lenght()) ) <= MAX_VELOCITY_DEFINE )
				object->force -= matrix.GetVertex( forward );
		}
		
		if( keyboardobiect.keypressed[GameInstance->StrafeLeft] ) // Strafe Left
		{
			if( object->vel.Dot( matrix.GetVertex( SetVector( +FORCE_DEFINE, 0.0f, 0.0f ) )/(forward.Lenght()) ) <= MAX_VELOCITY_DEFINE )
			{
				object->force[0] += cos( (object->see[0] + 90.0f) *M_PI/180.0f) * FORCE_DEFINE;
				object->force[2] += -sin( (object->see[0] + 90.0f) *M_PI/180.0f) * FORCE_DEFINE;
			}
		}
		
		if( keyboardobiect.keypressed[GameInstance->StrafeRight] ) // Strafe Right
		{
			if( object->vel.Dot( matrix.GetVertex( SetVector( -FORCE_DEFINE, 0.0f, 0.0f ) )/(forward.Lenght()) ) <= MAX_VELOCITY_DEFINE )
			{
				object->force[0] += cos( (object->see[0] + 270.0f) *M_PI/180.0f) * FORCE_DEFINE;
				object->force[2] += -sin( (object->see[0] + 270.0f) *M_PI/180.0f) * FORCE_DEFINE;
			}
		}
		
		if( object->CollisionDown && keyboardobiect.keypressed[GameInstance->Jump] )	// Jump
		{
			object->vel[1] = 4.5f;
		}
		
		if( keyboardobiect.keypressed[GameInstance->Crouch] || object->CollisionUp )
		{
			crouch = true;
		}
		else
		{
			crouch = false;
		}
		
		if( crouch )	// Crouch
		{
			if( abs(object->size[1]-1.0f) > 0.01f  )
				object->pos[1] += 0.4f;
			object->size[1] = 1.0f;
		}
		else
		{
			if( abs(object->size[1]-1.75f) > 0.01f  )
				object->pos[1] -= 0.4f;
			object->size[1] = 1.75f;
		}
		
		if( GameInstance->UseMouse == true )
		{
			POINT point;
			GetCursorPos( & point );
			rotateDestiny[0] -= float(point.x-(glutGet(GLUT_WINDOW_X)+(glutGet( GLUT_WINDOW_WIDTH ) / 2))) * GameInstance->SensitivityX / (1000.0f);
			rotateDestiny[1] -= float(point.y-(glutGet(GLUT_WINDOW_Y)+(glutGet( GLUT_WINDOW_HEIGHT ) / 2))) * GameInstance->SensitivityY / (1000.0f);
			SetCursorPos( glutGet(GLUT_WINDOW_X)+(glutGet( GLUT_WINDOW_WIDTH ) / 2), glutGet(GLUT_WINDOW_Y)+(glutGet( GLUT_WINDOW_HEIGHT ) / 2) );
		}
		
		if(GetAsyncKeyState(GameInstance->LookLeft) & 0x8000)
		{
			rotateDestiny[0] += 360.0f * time / 2.0f;
		}		
		if(GetAsyncKeyState(GameInstance->LookUp) & 0x8000)
		{
			rotateDestiny[1] += 360.0f * time / 2.0f;
		}
		if(GetAsyncKeyState(GameInstance->LookRight) & 0x8000)
		{
			rotateDestiny[0] -= 360.0f * time / 2.0f;
		}
		if(GetAsyncKeyState(GameInstance->LookDown) & 0x8000)
		{
			rotateDestiny[1] -= 360.0f * time / 2.0f;
		}
		
		if( keyboardobiect.downkeypressed[ 'F' ] )
		{
			GameInstance -> engine.GetDynamicLightSourceHandle( 0 ) -> angle = -GameInstance -> engine.GetDynamicLightSourceHandle( 0 ) -> angle;
		}
		
		matrix.InitEmpty();
		matrix.RotateY( object->see[0] + 90.0f );
		matrix.RotateX( -object->see[1] );
		GameInstance -> engine.GetDynamicLightSourceHandle( 0 ) -> direction = matrix.GetVertex( SetVector( 0.0f, 0.0f, 1.0f ) );
		GameInstance -> engine.GetDynamicLightSourceHandle( 0 ) -> origin = object->GetBarycentricDraw();
	}
}

inline void Player::AIUpdate( float time )
{
	if( Hp <= 0 )
	{
		parent -> destroy = true;
		return;
	}
	ai -> Update( time );
}

inline void Player::Update( float time )
{
	
	if( object != NULL )
	{
		if( object->pos[0] < wsl[0] )
			object->pos[0] = wsl[0];
		if( object->pos[2] < wsl[2] )
			object->pos[2] = wsl[2];
		if( object->pos[0] > wsh[0] )
			object->pos[0] = wsh[0];
		if( object->pos[2] > wsh[2] )
			object->pos[2] = wsh[2];
		if( object->pos[1] < -9.0f )
		{
			object->pos[1] = -9.0f;
			object->vel[1] = 0.0f;
		}
	}
	
	cooldown -= time;
	if( cooldown <= 0.0f )
	{
		shooting = false;
	}
	
	if( ai != NULL )
	{
		AIUpdate( time );
	}
	else
	{
		PlayerUpdate( time );
	}
	
	if( cooldown <= 0.0f || shooting == false )
	{
		rotateVelocity.Set( 0.0f, 0.0f, 0.0f );
	}
	
	if( rotateVelocity.Lenght() > 0.1f )
	{
		rotatePlus += rotateVelocity * time;
	}
	else
	{
		rotatePlus = rotatePlus * 0.922f;
	}
	
	if( rotatePlus.Lenght() > 5.0f )
	{
		rotateDestiny += rotatePlus.Versor() * ( rotatePlus.Lenght() - 5.0f );
		rotatePlus.SetLenght( 5.0f );
	}
	
	if( rotateDestiny[1] < -90.0f )
	{
		rotateDestiny[1] = -90.0f;
	}
	else if( object->see[1] > 90.0f )
	{
		rotateDestiny[1] = 90.0f;
	}
	
	object -> see[0] = rotateDestiny[0] + rotatePlus[0];
	object -> see[1] = rotateDestiny[1] + rotatePlus[1];
}


