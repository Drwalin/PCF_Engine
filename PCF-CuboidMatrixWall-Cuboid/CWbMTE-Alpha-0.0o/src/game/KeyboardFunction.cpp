


void KeyboardFunction( float FrameTime )
{
	keyboardobiect.Update();
	
	VMatrix matrix;
	matrix.InitEmpty();
	//matrix.RotateX( -engineInstantiation->map.staticobject[0].see[1] );
	matrix.RotateY( (engineInstantiation->map.staticobject[0].see[0]+90.0f) );
	Vector forward;
	//#define FORCE_DEFINE 2500.0f
	#define FORCE_DEFINE 2000.0f
	#define MAX_VELOCITY_DEFINE 3.0f
	forward.Set( 0.0f, 0.0f, FORCE_DEFINE );
	
	if( keyboardobiect.keypressed[0x57] ) // 'W'
	{
		if( engineInstantiation->map.staticobject[0].vel.Dot( matrix.GetVertex( forward )/(forward.Lenght()) ) <= MAX_VELOCITY_DEFINE )
			engineInstantiation->map.staticobject[0].force += matrix.GetVertex( forward );
	}
	if( keyboardobiect.keypressed[0x53] ) // 'S'
	{
		if( engineInstantiation->map.staticobject[0].vel.Dot( 0.0f-matrix.GetVertex( forward )/(forward.Lenght()) ) <= MAX_VELOCITY_DEFINE )
			engineInstantiation->map.staticobject[0].force -= matrix.GetVertex( forward );
	}
	if( keyboardobiect.keypressed[0x41] ) // 'A'
	{
		if( engineInstantiation->map.staticobject[0].vel.Dot( matrix.GetVertex( SetVector( +FORCE_DEFINE, 0.0f, 0.0f ) )/(forward.Lenght()) ) <= MAX_VELOCITY_DEFINE )
		{
			engineInstantiation->map.staticobject[0].force[0] += cos( (engineInstantiation->map.staticobject[0].see[0] + 90.0f) *M_PI/180.0f) * FORCE_DEFINE;
			engineInstantiation->map.staticobject[0].force[2] += -sin( (engineInstantiation->map.staticobject[0].see[0] + 90.0f) *M_PI/180.0f) * FORCE_DEFINE;
		}
	}
	if( keyboardobiect.keypressed[0x44] ) // 'D'
	{
		if( engineInstantiation->map.staticobject[0].vel.Dot( matrix.GetVertex( SetVector( -FORCE_DEFINE, 0.0f, 0.0f ) )/(forward.Lenght()) ) <= MAX_VELOCITY_DEFINE )
		{
			engineInstantiation->map.staticobject[0].force[0] += cos( (engineInstantiation->map.staticobject[0].see[0] + 270.0f) *M_PI/180.0f) * FORCE_DEFINE;
			engineInstantiation->map.staticobject[0].force[2] += -sin( (engineInstantiation->map.staticobject[0].see[0] + 270.0f) *M_PI/180.0f) * FORCE_DEFINE;
		}
	}
	if( keyboardobiect.keypressed[0x20] ) // SPACE
	{
		engineInstantiation->map.staticobject[0].force[1] += FORCE_DEFINE;
	}
	if( keyboardobiect.keypressed[0x11] ) // CTRL
	{
		engineInstantiation->map.staticobject[0].force[1] -= FORCE_DEFINE;
	}
}


