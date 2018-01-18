


inline void SetCommand( char * command )
{
	char * com = GetStringBetweenSpace( command );
	
	if( !strcmp( com, "FullScreen" ) )
	{
		engineInstantiation->WindowFullScreen = (bool)(GetIntFromString( command, 0 )%2);
	}
	else if( !strcmp( com, "UseMouse" ) )
	{
		GameInstantiation->UseMouse = (bool)(GetIntFromString( command, 0 )%2);
	}
	else if( !strcmp( com, "HideMouse" ) )
	{
		engineInstantiation->HideMouse = (bool)(GetIntFromString( command, 0 )%2);
		ShowCursor( engineInstantiation->HideMouse );
	}
	else if( !strcmp( com, "MaxObjects" ) )
	{
		engineInstantiation->MaximumNumberOfObjects = GetIntFromString( command, 0 );
	}
	else if( !strcmp( com, "MaxCollisionThreads" ) )
	{
		engineInstantiation->MaximumNumberOfPhysicsThreads = GetIntFromString( command, 0 );
	}
	else if( !strcmp( com, "WindowPos" ) )
	{
		engineInstantiation->WindowPossition [0] = GetIntFromString( command, 0 );
		engineInstantiation->WindowPossition [1] = GetIntFromString( command, 1 );
	}
	else if( !strcmp( com, "WindowSize" ) )
	{
		engineInstantiation->WindowSize      [0] = GetIntFromString( command, 0 );
		engineInstantiation->WindowSize      [1] = GetIntFromString( command, 1 );
	}
	else if( !strcmp( com, "TerrainColliderSize" ) )
	{
		engineInstantiation->map.maximumnumberoftrianglescolliders[0] = GetIntFromString( command, 0 );
		engineInstantiation->map.maximumnumberoftrianglescolliders[1] = GetIntFromString( command, 1 );
	}
	else if( !strcmp( com, "ObjectsColliderSize" ) )
	{
		engineInstantiation->map.maximumnumberofobjectcolliders[0] = GetIntFromString( command, 0 );
		engineInstantiation->map.maximumnumberofobjectcolliders[1] = GetIntFromString( command, 1 );
	}
	else if( !strcmp( com, "MouseSensitivity" ) )
	{
		GameInstantiation->SensitivityX = (float)GetIntFromString( command, 0 );
		GameInstantiation->SensitivityY = (float)GetIntFromString( command, 1 );
	}
	else if( !strcmp( com, "Volume" ) )
	{
		GameInstantiation->engine.SetVolume( ((float)GetIntFromString( command, 0 )) * 0.01f );
	}
	else if( !strcmp( com, "bind" ) )
	{
		char * fast1 = GetStringBetweenCharacter( command, ' ', 1 );
		char * fast2 = GetStringBetweenCharacter( command, ' ', 2 );
		
		if( !strcmp( fast1, "MoveForward" ) )
			GameInstantiation->MoveForward = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "MoveBackward" ) )
			GameInstantiation->MoveBackward = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "StrafeLeft" ) )
			GameInstantiation->StrafeLeft = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "StrafeRight" ) )
			GameInstantiation->StrafeRight = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "Jump" ) )
			GameInstantiation->Jump = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "Crouch" ) )
			GameInstantiation->Crouch = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "LookLeft" ) )
			GameInstantiation->LookLeft = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "LookUp" ) )
			GameInstantiation->LookUp = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "LookRight" ) )
			GameInstantiation->LookRight = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "LookDown" ) )
			GameInstantiation->LookDown = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "PrimaryAttack" ) )
			GameInstantiation->PrimaryAttack = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "SecondaryAttack" ) )
			GameInstantiation->SecondaryAttack = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "Zoom" ) )
			GameInstantiation->Zoom = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "Run" ) )
			GameInstantiation->Run = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "Sneak" ) )
			GameInstantiation->Sneak = GetKeyCode( fast2 );
		
		if( fast1 != NULL )
			delete[] fast1;
		if( fast2 != NULL )
			delete[] fast2;
	}
	
	delete[] com;
}


