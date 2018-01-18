


void KeyboardFunction( float FrameTime )
{
	keyboardobiect.Update();
	
	VMatrix matrix;
	matrix.InitEmpty();
	matrix.RotateY( (engineInstantiation->map.staticobject[0].see[0]+90.0f) );
//	matrix.RotateX( engineInstantiation->map.staticobject[0].see[1] );
	Vector forward;
	//#define FORCE_DEFINE 2500.0f
	#define FORCE_DEFINE 3000.0f
	#define MAX_VELOCITY_DEFINE 2.5f
	forward.Set( 0.0f, 0.0f, FORCE_DEFINE * (float( engineInstantiation->map.staticobject[0].aabb[0].CollisionDown ? 1.0f : 0.1f )) );
	
	/*
	GameInstantiation->LookLeft;
	GameInstantiation->LookUp;
	GameInstantiation->LookRight;
	GameInstantiation->LookDown;
	GameInstantiation->PrimaryAttack;
	GameInstantiation->SecondaryAttack;
	GameInstantiation->Zoom;
	GameInstantiation->Run;
	GameInstantiation->Sneak;
	*/
	
	if( keyboardobiect.keypressed[GameInstantiation->MoveForward] ) // 'W'
	{
		if( engineInstantiation->map.staticobject[0].vel.Dot( matrix.GetVertex( forward )/(forward.Lenght()) ) <= MAX_VELOCITY_DEFINE )
			engineInstantiation->map.staticobject[0].force += matrix.GetVertex( forward );
	}
	if( keyboardobiect.keypressed[GameInstantiation->MoveBackward] ) // 'S'
	{
		if( engineInstantiation->map.staticobject[0].vel.Dot( 0.0f-matrix.GetVertex( forward )/(forward.Lenght()) ) <= MAX_VELOCITY_DEFINE )
			engineInstantiation->map.staticobject[0].force -= matrix.GetVertex( forward );
	}
	if( keyboardobiect.keypressed[GameInstantiation->StrafeLeft] ) // 'A'
	{
		if( engineInstantiation->map.staticobject[0].vel.Dot( matrix.GetVertex( SetVector( +FORCE_DEFINE, 0.0f, 0.0f ) )/(forward.Lenght()) ) <= MAX_VELOCITY_DEFINE )
		{
			engineInstantiation->map.staticobject[0].force[0] += cos( (engineInstantiation->map.staticobject[0].see[0] + 90.0f) *M_PI/180.0f) * FORCE_DEFINE;
			engineInstantiation->map.staticobject[0].force[2] += -sin( (engineInstantiation->map.staticobject[0].see[0] + 90.0f) *M_PI/180.0f) * FORCE_DEFINE;
		}
	}
	if( keyboardobiect.keypressed[GameInstantiation->StrafeRight] ) // 'D'
	{
		if( engineInstantiation->map.staticobject[0].vel.Dot( matrix.GetVertex( SetVector( -FORCE_DEFINE, 0.0f, 0.0f ) )/(forward.Lenght()) ) <= MAX_VELOCITY_DEFINE )
		{
			engineInstantiation->map.staticobject[0].force[0] += cos( (engineInstantiation->map.staticobject[0].see[0] + 270.0f) *M_PI/180.0f) * FORCE_DEFINE;
			engineInstantiation->map.staticobject[0].force[2] += -sin( (engineInstantiation->map.staticobject[0].see[0] + 270.0f) *M_PI/180.0f) * FORCE_DEFINE;
		}
	}
	if( keyboardobiect.downkeypressed[GameInstantiation->Jump] )//&& engineInstantiation->map.staticobject[0].aabb[0].CollisionDown ) // SPACE
	{
		engineInstantiation->map.staticobject[0].force[1] += engineInstantiation->map.staticobject[0].GetMass() * 0.12f / (FrameTime*FrameTime);//FORCE_DEFINE;
	}
	if( keyboardobiect.keypressed[GameInstantiation->Crouch] ) // CTRL
	{
		engineInstantiation->map.staticobject[0].force[1] -= FORCE_DEFINE;
	}
}


