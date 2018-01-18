


void KeyboardFunction( float FrameTime )
{
	keyboardobiect.Update();
	
	VMatrix matrix;
	matrix.InitEmpty();
	//matrix.RotateX( -engineInstantiation->map.staticobject[0].see[1] );
	matrix.RotateY( (engineInstantiation->map.staticobject[0].see[0]+90.0f) );
	Vector forward;
	//#define FORCE_DEFINE 2500.0f
	#define FORCE_DEFINE 5000.0f
	#define MAX_VELOCITY_DEFINE 3.0f
	forward.Set( 0.0f, 0.0f, FORCE_DEFINE );
	
	if( keyboardobiect.keypressed[0x57] ) // 'W'
	{
		if( ((AABB*)(engineInstantiation->map.staticobject[0].object))->vel.Dot( matrix.GetVertex( forward )/(forward.Lenght()) ) <= MAX_VELOCITY_DEFINE )
			((AABB*)(engineInstantiation->map.staticobject[0].object))->force += matrix.GetVertex( forward );
	}
	if( keyboardobiect.keypressed[0x53] ) // 'S'
	{
		if( ((AABB*)(engineInstantiation->map.staticobject[0].object))->vel.Dot( 0.0f-matrix.GetVertex( forward )/(forward.Lenght()) ) <= MAX_VELOCITY_DEFINE )
			((AABB*)(engineInstantiation->map.staticobject[0].object))->force -= matrix.GetVertex( forward );
	}
	if( keyboardobiect.keypressed[0x41] ) // 'A'
	{
		if( ((AABB*)(engineInstantiation->map.staticobject[0].object))->vel.Dot( matrix.GetVertex( SetVector( +FORCE_DEFINE, 0.0f, 0.0f ) )/(forward.Lenght()) ) <= MAX_VELOCITY_DEFINE )
		{
			((AABB*)(engineInstantiation->map.staticobject[0].object))->force[0] += cos( (engineInstantiation->map.staticobject[0].see[0] + 90.0f) *M_PI/180.0f) * FORCE_DEFINE;
			((AABB*)(engineInstantiation->map.staticobject[0].object))->force[2] += -sin( (engineInstantiation->map.staticobject[0].see[0] + 90.0f) *M_PI/180.0f) * FORCE_DEFINE;
		}
	}
	if( keyboardobiect.keypressed[0x44] ) // 'D'
	{
		if( ((AABB*)(engineInstantiation->map.staticobject[0].object))->vel.Dot( matrix.GetVertex( SetVector( -FORCE_DEFINE, 0.0f, 0.0f ) )/(forward.Lenght()) ) <= MAX_VELOCITY_DEFINE )
		{
			((AABB*)(engineInstantiation->map.staticobject[0].object))->force[0] += cos( (engineInstantiation->map.staticobject[0].see[0] + 270.0f) *M_PI/180.0f) * FORCE_DEFINE;
			((AABB*)(engineInstantiation->map.staticobject[0].object))->force[2] += -sin( (engineInstantiation->map.staticobject[0].see[0] + 270.0f) *M_PI/180.0f) * FORCE_DEFINE;
		}
	}
	if( keyboardobiect.keypressed[0x20] ) // SPACE
	{
		((AABB*)(engineInstantiation->map.staticobject[0].object))->force[1] += FORCE_DEFINE * 0.5f;
	}
	if( keyboardobiect.keypressed[0x11] ) // CTRL
	{
		((AABB*)(engineInstantiation->map.staticobject[0].object))->force[1] -= FORCE_DEFINE * 0.5f;
	}
}


