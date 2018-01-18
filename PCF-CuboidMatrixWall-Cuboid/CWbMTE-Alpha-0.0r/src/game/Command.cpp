


inline void Command::Set( char * command, int * arg )
{
	if( !strcmp( command, "FullScreen" ) )
	{
		engineInstantiation->WindowFullScreen = (bool)((*(arg))%2);
	}
	else if( !strcmp( command, "MaxObjects" ) )
	{
		engineInstantiation->MaximumNumberOfObjects = (*(arg));
	}
	else if( !strcmp( command, "MaxCollisionThreads" ) )
	{
		engineInstantiation->MaximumNumberOfPhysicsThreads = (*(arg));
	}
	else if( !strcmp( command, "WindowPos" ) )
	{
		engineInstantiation->WindowPossition [0] = (*(arg));
		engineInstantiation->WindowPossition [1] = (*(arg+1));
	}
	else if( !strcmp( command, "WindowSize" ) )
	{
		engineInstantiation->WindowSize      [0] = (*(arg));
		engineInstantiation->WindowSize      [1] = (*(arg+1));
	}
	else if( !strcmp( command, "TerrainColliderSize" ) )
	{
		engineInstantiation->map.maxiumumnumberoftrianglescolliders[0] = (*(arg));
		engineInstantiation->map.maxiumumnumberoftrianglescolliders[1] = (*(arg+1));
	}
	else if( !strcmp( command, "ObjectsColliderSize" ) )
	{
		engineInstantiation->map.maxiumumnumberofobjectcolliders[0] = (*(arg));
		engineInstantiation->map.maxiumumnumberofobjectcolliders[1] = (*(arg+1));
	}
	else if( !strcmp( command, "MouseSensitivity" ) )
	{
		GameInstantiation->SensitivityX = (float)(*(arg));
		GameInstantiation->SensitivityY = (float)(*(arg+1));
	}
}


inline int Command::ArgueNumber( char * command )
{
	if( !strcmp( command, "WindowPos" ) )				return 2;
	if( !strcmp( command, "WindowSize" ) )				return 2;
	if( !strcmp( command, "TerrainColliderSize" ) )		return 2;
	if( !strcmp( command, "ObjectsColliderSize" ) )		return 2;
	if( !strcmp( command, "FullScreen" ) )				return 1;
	if( !strcmp( command, "MaxObjects" ) )				return 1;
	if( !strcmp( command, "MaxCollisionThreads" ) )		return 1;
	if( !strcmp( command, "MouseSensitivity" ) )		return 2;
	if( !strcmp( command, "UseMouse" ) )				return 1;
	
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
	Set( com, tab );
	delete[] com;
	return 1;
}


