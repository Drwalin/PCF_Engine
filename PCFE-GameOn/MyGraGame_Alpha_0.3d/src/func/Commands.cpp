


inline void SetCommand( char * command )
{
	char * com = GetStringBetweenSpace( command );
	
	if( !strcmp( com, "FullScreen" ) )
	{
		GameInstance->engine.WindowFullScreen = (bool)(GetIntFromString( command, 0 )%2);
	}
	else if( !strcmp( com, "UseMouse" ) )
	{
		GameInstance->UseMouse = (bool)(GetIntFromString( command, 0 )%2);
	}
	else if( !strcmp( com, "HideMouse" ) )
	{
		GameInstance->engine.HideMouse = (bool)(GetIntFromString( command, 0 )%2);
		ShowCursor( GameInstance->engine.HideMouse );
	}
	else if( !strcmp( com, "MaxObjects" ) )
	{
		GameInstance->engine.MaximumNumberOfObjects = GetIntFromString( command, 0 );
	}
	else if( !strcmp( com, "MaxCollisionThreads" ) )
	{
		GameInstance->engine.MaximumNumberOfPhysicsThreads = GetIntFromString( command, 0 );
	}
	else if( !strcmp( com, "WindowPos" ) )
	{
		GameInstance->engine.WindowPossition [0] = GetIntFromString( command, 0 );
		GameInstance->engine.WindowPossition [1] = GetIntFromString( command, 1 );
	}
	else if( !strcmp( com, "WindowSize" ) )
	{
		GameInstance->engine.WindowSize      [0] = GetIntFromString( command, 0 );
		GameInstance->engine.WindowSize      [1] = GetIntFromString( command, 1 );
	}
	else if( !strcmp( com, "TerrainColliderSize" ) )
	{
		GameInstance->engine.map.maximumnumberoftrianglescolliders[0] = GetIntFromString( command, 0 );
		GameInstance->engine.map.maximumnumberoftrianglescolliders[1] = GetIntFromString( command, 1 );
	}
	else if( !strcmp( com, "ObjectsColliderSize" ) )
	{
		GameInstance->engine.map.maximumnumberofobjectcolliders[0] = GetIntFromString( command, 0 );
		GameInstance->engine.map.maximumnumberofobjectcolliders[1] = GetIntFromString( command, 1 );
	}
	else if( !strcmp( com, "MouseSensitivity" ) )
	{
		GameInstance->SensitivityX = (float)GetIntFromString( command, 0 );
		GameInstance->SensitivityY = (float)GetIntFromString( command, 1 );
	}
	else if( !strcmp( com, "Volume" ) )
	{
		GameInstance->engine.SetVolume( ((float)GetIntFromString( command, 0 )) * 0.01f );
	}
	else if( !strcmp( com, "LightMapEdgeLenght" ) )
	{
		GameInstance->engine.SetLightMapEdgeLenght( float(GetIntFromString( command, 0 ))/100.0f );
	}
	else if( !strcmp( com, "LightMapEdgeMaxNumber" ) )
	{
		GameInstance->engine.SetMaximumNumberOfEdges( GetIntFromString( command, 0 ) );
	}
	else if( !strcmp( com, "FramesPerLightVerticesCalculate" ) )
	{
		GameInstance -> engine.NumberLightVertexCalculatedPerFrame = GetIntFromString( command, 0 );
	}
	else if( !strcmp( com, "bind" ) )
	{
		char * fast1 = GetStringBetweenCharacter( command, ' ', 1 );
		char * fast2 = GetStringBetweenCharacter( command, ' ', 2 );
		
		if( !strcmp( fast1, "MoveForward" ) )
			GameInstance->MoveForward = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "MoveBackward" ) )
			GameInstance->MoveBackward = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "StrafeLeft" ) )
			GameInstance->StrafeLeft = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "StrafeRight" ) )
			GameInstance->StrafeRight = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "Jump" ) )
			GameInstance->Jump = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "Crouch" ) )
			GameInstance->Crouch = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "LookLeft" ) )
			GameInstance->LookLeft = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "LookUp" ) )
			GameInstance->LookUp = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "LookRight" ) )
			GameInstance->LookRight = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "LookDown" ) )
			GameInstance->LookDown = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "PrimaryAttack" ) )
			GameInstance->PrimaryAttack = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "SecondaryAttack" ) )
			GameInstance->SecondaryAttack = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "Zoom" ) )
			GameInstance->Zoom = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "Run" ) )
			GameInstance->Run = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "Sneak" ) )
			GameInstance->Sneak = GetKeyCode( fast2 );
		else if( !strcmp( fast1, "Reload" ) )
			GameInstance->Reload = GetKeyCode( fast2 );
		
		if( fast1 != NULL )
			delete[] fast1;
		if( fast2 != NULL )
			delete[] fast2;
	}
	
	delete[] com;
}


