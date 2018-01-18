


namespace Command
{
	inline int ArgueNumber( char * command )
	{
		if( strcmp( command, "FullScreen" ) )					return 1;
		else if( strcmp( command, "MaxObjects" ) )				return 1;
		else if( strcmp( command, "MaxCollisionThreads" ) )		return 1;
		
		else if( strcmp( command, "WindowPos" ) )				return 2;
		else if( strcmp( command, "WindowSize" ) )				return 2;
		else if( strcmp( command, "TerrainColliderSize" ) )		return 2;
		else if( strcmp( command, "ObjectsColliderSize" ) )		return 2;
		
		return -1;
	}
	
	inline void Set( char * command )
	{
		
	}
	
	inline void Set( char * command, int arg1 )
	{
		if( strcmp( command, "FullScreen" ) )
		{
			engineInstantiation->WindowFullScreen = (bool)arg1;
		}
		else if( strcmp( command, "MaxObjects" ) )
		{
			engineInstantiation->MaximumNumberOfObjects = arg1;
		}
		else if( strcmp( command, "MaxCollisionThreads" ) )
		{
			engineInstantiation->MaximumNumberOfPhysicsThreads = arg1;
		}
	}
	
	inline void Set( char * command, int arg1, int arg2 )
	{
		if( strcmp( command, "WindowPos" ) )
		{
			engineInstantiation->WindowPossition [0] = arg1;
			engineInstantiation->WindowPossition [1] = arg2;
		}
		else if( strcmp( command, "WindowSize" ) )
		{
			engineInstantiation->WindowSize      [0] = arg1;
			engineInstantiation->WindowSize      [1] = arg2;
		}
		else if( strcmp( command, "TerrainColliderSize" ) )
		{
			engineInstantiation->map.maxiumumnumberoftrianglescolliders[0] = arg1;
			engineInstantiation->map.maxiumumnumberoftrianglescolliders[1] = arg2;
		}
		else if( strcmp( command, "ObjectsColliderSize" ) )
		{
			engineInstantiation->map.maxiumumnumberofobjectcolliders[0] = arg1;
			engineInstantiation->map.maxiumumnumberofobjectcolliders[1] = arg2;
		}
	}
	
	inline void Set( char * command, int arg1, int arg2, int arg3 )
	{
		
	}
	
	inline int SetCommand( char * command )
	{
		
		
		
		
		
		
		
		
	}
}


