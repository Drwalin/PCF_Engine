


inline int Game::LoadMap( char * srcFile )
{
	ifstream file;
	file.open( srcFile );
	
	if( file.good() )
	{
		char * str = new char[4096];
		char * command = new char[1024];
		char * arg = new char[1024];
		float argf;
		char argc;
		int argi;
		
		while( !file.eof() )
		{
			file >> str;
			if( !strcmp( str, "GraphicMap" ) )
			{
				file >> arg;
				GameInstance->engine.AddGraphicModelAsMap( arg, GameInstance -> engine.TextureId( "Glock311" ) );
			}
			else if( !strcmp( str, "PhisicMap" ) )
			{
				file >> arg;
				GameInstance->LoadObjAsPhysic( arg );
			}
			else if( !strcmp( str, "Object" ) )
			{
				argc = 0;
				while( argc != '{' )
				{
					file >> argc;
				}
				
				while( arg[0] != '}' )
				{
					file >> arg;
					if( !strcmp( arg, "pos" ) )
					{
						Vector pos[3];
						Vector vel[3];
						
						
						
						
						
						file >> argf;
					}
				}
			}
		}
		
		delete[] str;
		delete[] command;
		delete[] arg;
		
		file.close();
		return 1;
	}
	
	return 0;
}


