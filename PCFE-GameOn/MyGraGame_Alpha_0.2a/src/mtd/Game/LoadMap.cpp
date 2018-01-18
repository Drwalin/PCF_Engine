


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
		
		int counter___ = 0;
		
		while( !file.eof() )
		{
			file >> str;
///			printf( "\n Next line: %s", str );
			if( !strcmp( str, "GraphicMap" ) )
			{
				file >> arg;
				GameInstance->engine.AddGraphicModelAsMap( arg );
			}
			else if( !strcmp( str, "PhysicsMap" ) )
			{
				file >> arg;
				GameInstance->LoadObjAsPhysic( arg );
			}
			else if( !strcmp( str, "object" ) )
			{
				file >> str;
///				printf( "\n Next line: %s - strlen()=%i", str, strlen(str) );
				
				if( !strcmp( str, "player" ) )
				{
					printf( "\n   Add Player" );
					AddPlayer();
				}
				else if( !strcmp( str, "bot" ) )
				{
					printf( "\n   Add Bot" );
					AddBot();
				}
				else if( !strcmp( str, "item" ) )
				{
					printf( "\n   Add Item" );
					AddItem();
				}
				else
				{
					printf( "\n\n\n   Continue;\n\n" );
					continue;
				}
				
				arg[0] = 0;
				
				while( arg[0] != '}' )
				{
					file >> arg;
					printf( "\n Next line: %s", arg );
					/*if( !strcmp( arg, "}" ) || arg[0] == '\}' )
					{
						++counter___;
						printf( "\n   End loading object: %i", counter___ );
						break;
					}
					else */if( !strcmp( arg, "pos" ) )
					{
						file >> object.back() -> object -> pos[0];
						file >> object.back() -> object -> pos[1];
						file >> object.back() -> object -> pos[2];
					}
					else if( !strcmp( arg, "vel" ) )
					{
						file >> object.back() -> object -> vel[0];
						file >> object.back() -> object -> vel[1];
						file >> object.back() -> object -> vel[2];
					}
					else if( !strcmp( arg, "mass" ) )
					{
						file >> object.back() -> object -> mass;
					}
					else if( !strcmp( arg, "size" ) )
					{
						file >> object.back() -> object -> size[0];
						file >> object.back() -> object -> size[1];
						file >> object.back() -> object -> size[2];
					}
					else if( !strcmp( arg, "look" ) )
					{
						file >> object.back() -> object -> see[0];
						file >> object.back() -> object -> see[1];
					}
					else if( !strcmp( arg, "model" ) )
					{
						file >> arg;
						object.back() -> object -> model = engine.GetStaticModelHandle( arg );
					}
					else if( !strcmp( arg, "modelScale" ) )
					{
						file >> object.back() -> object -> GraphicModelScale;
					}
					else if( !strcmp( arg, "rayCollision" ) )
					{
						file >> argi;
						object.back() -> object -> AddRayType( argi );
					}
					else if( !strcmp( arg, "hp" ) )
					{
						file >> object.back() -> player -> Hp;
					}
					else if( !strcmp( arg, "maxHp" ) )
					{
						file >> object.back() -> player -> maxHp;
					}
					else if( !strcmp( arg, "energy" ) )
					{
						file >> object.back() -> player -> Energy;
					}
					else if( !strcmp( arg, "maxEnergy" ) )
					{
						file >> object.back() -> player -> maxEnergy;
					}
					else if( !strcmp( arg, "ammo" ) )
					{
						file >> argi;
						if( argi >= 0 && argi < WEAPONS_NUMBER )
							file >> object.back() -> player -> ammo[argi];
					}
					else if( !strcmp( arg, "ammoLoaded" ) )
					{
						file >> argi;
						if( argi >= 0 && argi < WEAPONS_NUMBER )
							file >> object.back() -> player -> ammoLoaded[argi];
					}
					else if( !strcmp( arg, "weapon" ) )
					{
						file >> argi;
						if( argi >= 0 && argi < WEAPONS_NUMBER )
						{
							int argi2;
							file >> argi2; 
							object.back() -> player -> weapon[argi] = bool( argi2 );
						}
					}
					else if( !strcmp( arg, "weaponEquiped" ) )
					{
						file >> object.back() -> player -> weaponEquiped;
						object.back() -> player -> weaponEquiped %= WEAPONS_NUMBER;
					}
					else if( !strcmp( arg, "handRange" ) )
					{
						file >> object.back() -> player -> handRange;
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


