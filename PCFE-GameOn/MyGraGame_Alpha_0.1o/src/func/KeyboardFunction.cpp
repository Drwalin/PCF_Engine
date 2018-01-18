


void KeyboardFunction( float FrameTime )
{
	int i;
	
	for( i = 0; i < GameInstance->engine.ObjectsNumber(); i++ )
	{
		if( GameInstance->engine.Object(i)->pos[0] < wsl[0] )
			GameInstance->engine.Object(i)->pos[0] = wsl[0];
		if( GameInstance->engine.Object(i)->pos[2] < wsl[2] )
			GameInstance->engine.Object(i)->pos[2] = wsl[2];
		if( GameInstance->engine.Object(i)->pos[0] > wsh[0] )
			GameInstance->engine.Object(i)->pos[0] = wsh[0];
		if( GameInstance->engine.Object(i)->pos[2] > wsh[2] )
			GameInstance->engine.Object(i)->pos[2] = wsh[2];
		if( GameInstance->engine.Object(i)->pos[1] < -9.0f )
		{
			GameInstance->engine.Object(i)->pos[1] = -9.0f;
			GameInstance->engine.Object(i)->vel[1] = 0.0f;
		}
	}
	
	keyboardobiect.Update();
	
	VMatrix matrix;
	matrix.InitEmpty();
	matrix.RotateY( (GameInstance->engine.Object(0)->see[0]+90.0f) );
	Vector forward;
	#define FORCE_DEFINE 3000.0f
	#define MAX_VELOCITY_DEFINE 2.5f
	forward.Set( 0.0f, 0.0f, FORCE_DEFINE * (float( GameInstance->engine.Object(0)->CollisionDown ? 1.0f : 0.1f )) );
	
	
	if( keyboardobiect.downkeypressed[ 'P' ] )
	{
		GameInstance->UseMouse = !GameInstance->UseMouse;
	}
	
	if( keyboardobiect.downkeypressed[ 0x02 ] )
	{
		AddLightings++;
	}
	
	
	if( keyboardobiect.keypressed[GameInstance->MoveForward] ) // Move Forward
	{
		if( GameInstance->engine.Object(0)->vel.Dot( matrix.GetVertex( forward )/(forward.Lenght()) ) <= MAX_VELOCITY_DEFINE )
			GameInstance->engine.Object(0)->force += matrix.GetVertex( forward );
	}
	
	if( keyboardobiect.keypressed[GameInstance->MoveBackward] ) // Move Backward
	{
		if( GameInstance->engine.Object(0)->vel.Dot( 0.0f-matrix.GetVertex( forward )/(forward.Lenght()) ) <= MAX_VELOCITY_DEFINE )
			GameInstance->engine.Object(0)->force -= matrix.GetVertex( forward );
	}
	
	if( keyboardobiect.keypressed[GameInstance->StrafeLeft] ) // Strafe Left
	{
		if( GameInstance->engine.Object(0)->vel.Dot( matrix.GetVertex( SetVector( +FORCE_DEFINE, 0.0f, 0.0f ) )/(forward.Lenght()) ) <= MAX_VELOCITY_DEFINE )
		{
			GameInstance->engine.Object(0)->force[0] += cos( (GameInstance->engine.Object(0)->see[0] + 90.0f) *M_PI/180.0f) * FORCE_DEFINE;
			GameInstance->engine.Object(0)->force[2] += -sin( (GameInstance->engine.Object(0)->see[0] + 90.0f) *M_PI/180.0f) * FORCE_DEFINE;
		}
	}
	
	if( keyboardobiect.keypressed[GameInstance->StrafeRight] ) // Strafe Right
	{
		if( GameInstance->engine.Object(0)->vel.Dot( matrix.GetVertex( SetVector( -FORCE_DEFINE, 0.0f, 0.0f ) )/(forward.Lenght()) ) <= MAX_VELOCITY_DEFINE )
		{
			GameInstance->engine.Object(0)->force[0] += cos( (GameInstance->engine.Object(0)->see[0] + 270.0f) *M_PI/180.0f) * FORCE_DEFINE;
			GameInstance->engine.Object(0)->force[2] += -sin( (GameInstance->engine.Object(0)->see[0] + 270.0f) *M_PI/180.0f) * FORCE_DEFINE;
		}
	}
	
	if( GameInstance->engine.Object(0)->CollisionDown && keyboardobiect.keypressed[GameInstance->Jump] )	// Jump
	{
		GameInstance->engine.Object(0)->vel[1] = 4.5f;
	}
	
	if( keyboardobiect.keypressed[GameInstance->Crouch] || GameInstance->engine.Object(0)->CollisionUp )	// Crouch
	{
		if( keyboardobiect.downkeypressed[GameInstance->Crouch] )
			GameInstance->engine.Object(0)->vel[1] += 1.5f;
		GameInstance->engine.Object(0)->size[1] = 1.0f;
	}
	else
	{
		if( keyboardobiect.upkeypressed[GameInstance->Crouch] )
			GameInstance->engine.Object(0)->vel[1] -= 1.5f;
		GameInstance->engine.Object(0)->size[1] = 1.75f;
	}
}


