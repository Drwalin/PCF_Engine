


inline void Command::Set( char * command )
{
	char * com = GetStringBetweenSpace( command );
	
	if( !strcmp( com, "FullScreen" ) )
	{
		engineInstantiation->WindowFullScreen = (bool)(GetIntFromString( command, 0 )%2);
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
		engineInstantiation->map.maxiumumnumberoftrianglescolliders[0] = GetIntFromString( command, 0 );
		engineInstantiation->map.maxiumumnumberoftrianglescolliders[1] = GetIntFromString( command, 1 );
	}
	else if( !strcmp( com, "ObjectsColliderSize" ) )
	{
		engineInstantiation->map.maxiumumnumberofobjectcolliders[0] = GetIntFromString( command, 0 );
		engineInstantiation->map.maxiumumnumberofobjectcolliders[1] = GetIntFromString( command, 1 );
	}
	else if( !strcmp( com, "MouseSensitivity" ) )
	{
		GameInstantiation->SensitivityX = (float)GetIntFromString( command, 0 );
		GameInstantiation->SensitivityY = (float)GetIntFromString( command, 1 );
	}
	else if( !strcmp( com ,"UseMouse" ) )
	{
		GameInstantiation->UseMouse = (bool)(GetIntFromString( command, 0 )%2);
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


inline int Command::ArgueNumber( char * command )
{
	if( !strcmp( command, "WindowPos" ) )				return 2;
	if( !strcmp( command, "WindowSize" ) )				return 2;
	if( !strcmp( command, "TerrainColliderSize" ) )		return 2;
	if( !strcmp( command, "ObjectsColliderSize" ) )		return 2;
	if( !strcmp( command, "MouseSensitivity" ) )		return 2;
	
	if( !strcmp( command, "FullScreen" ) )				return 1;
	if( !strcmp( command, "MaxObjects" ) )				return 1;
	if( !strcmp( command, "MaxCollisionThreads" ) )		return 1;
	if( !strcmp( command, "UseMouse" ) )				return 1;
	
	if( !strcmp( command, "bind" ) )					return 0;
	
	return -1;
}


inline int Command::SetCommand( char * command )
{
	char * com = GetStringBetweenSpace( command );
	int argues = ArgueNumber( com );
	if( argues < 0 )
	{
		com = GetStringBetweenCharacter( command, '=', 0 );
		argues = ArgueNumber( com );
		if( argues < 0 )
		{
			delete[] com;
			return 0;
		}
	}
	int * tab = new int[argues];
	int i;
	printf( "\n Argues = %i", argues );
	for( i = 0; i < argues; i++ )
	{
		*(tab+i) = GetIntFromString( command, i );
		printf( " :: %i", *(tab+i) );
	}
	delete[] com;
	Set( command );
	return 1;
}


