


inline void Game::LoadWeapons( char * src )
{
	ifstream file;
	file.open( src );
	if( !file.good() )
	{
		return;
	}
	else
	{
		char * data = new char[16000];
		char * fast1 = NULL;
		char * fast2 = NULL;
		while( !file.eof() )
		{
			file >> data;
			
			if( !strcmp( data, "weapon" ) )
			{
				weapon.resize( weapon.size() + 1 );
				while( !file.eof() && strcmp( data, "}" ) )
				{
					file >> data;
					
					if( !strcmp( data, "name" ) )
					{
						file >> data;
						weapon.back().SetName( data );
					}
					else if( !strcmp( data, "shotSound" ) )
					{
						file >> data;
						weapon.back().SetShotSound( data );
					}
					else if( !strcmp( data, "reloadSound" ) )
					{
						file >> data;
						weapon.back().SetReloadSound( data );
					}
					else if( !strcmp( data, "model" ) )
					{
						file >> data;
						weapon.back().model = engine.GetStaticModelHandle( data );
					}
					else if( !strcmp( data, "magazineCapacity" ) )
					{
						file >> weapon.back().magazineCapacity;
					}
					else if( !strcmp( data, "ammoCapacity" ) )
					{
						file >> weapon.back().ammoCapacity;
					}
					else if( !strcmp( data, "changeingCooldown" ) )
					{
						file >> weapon.back().changeingCooldown;
					}
					else if( !strcmp( data, "shootingCooldown" ) )
					{
						file >> weapon.back().shootingCooldown;
					}
					else if( !strcmp( data, "reloadingCooldown" ) )
					{
						file >> weapon.back().reloadingCooldown;
					}
					else if( !strcmp( data, "recoilUp" ) )
					{
						file >> weapon.back().recoilUp;
					}
					else if( !strcmp( data, "recoilSide" ) )
					{
						file >> weapon.back().recoilSide;
					}
					else if( !strcmp( data, "moveWeaponInHand" ) )
					{
						file >> weapon.back().moveWeaponInHand[0];
						file >> weapon.back().moveWeaponInHand[1];
						file >> weapon.back().moveWeaponInHand[2];
					}
					else if( !strcmp( data, "moveWeaponAfterShot" ) )
					{
						file >> weapon.back().moveWeaponAfterShot[0];
						file >> weapon.back().moveWeaponAfterShot[1];
						file >> weapon.back().moveWeaponAfterShot[2];
					}
					else if( !strcmp( data, "rotateWeaponAfterShot" ) )
					{
						file >> weapon.back().rotateWeaponAfterShot[0];
						file >> weapon.back().rotateWeaponAfterShot[1];
						file >> weapon.back().rotateWeaponAfterShot[2];
					}
					else if( !strcmp( data, "damageHead" ) )
					{
						file >> weapon.back().damageHead;
					}
					else if( !strcmp( data, "damageCorpus" ) )
					{
						file >> weapon.back().damageCorpus;
					}
					else if( !strcmp( data, "damageLegs" ) )
					{
						file >> weapon.back().damageLegs;
					}
				}
			}
		}
		delete[] data;
		file.close();
	}
}

inline void Game::LoadSounds( char * src )
{
	ifstream file;
	file.open( src );
	if( !file.good() )
	{
		return;
	}
	else
	{
		char * data = new char[16000];
		while( !file.eof() )
		{
			file.getline( data, 15999 );
			engine.AddSoundSource( data );
		}
		delete[] data;
		file.close();
	}
}

inline void Game::LoadModels( char * src )
{
	ifstream file;
	file.open( src );
	if( !file.good() )
	{
		return;
	}
	else
	{
		char * data = new char[16000];
		char * fast1 = NULL;
		char * fast2 = NULL;
		int a,b,c;
		while( !file.eof() )
		{
			file.getline( data, 15999 );
			fast1 = GetStringBetweenCharacter( data, ' ', 0 );
			if( !strcmp( fast1, "Static:" ) )
			{
				if( fast1 != NULL )
					delete[] fast1;
				fast1 = NULL;
				
				a = GetIntFromString( data, 0 );
				b = GetIntFromString( data, 1 );
				c = GetIntFromString( data, 2 );
				fast1 = GetStringBetweenCharacter( data, '\"', 1 );	// path to model file
				fast2 = GetStringBetweenCharacter( data, '\"', 3 );	// texture name
				
				engine.AddGraphicModel( fast1, engine.TextureId( fast2 ), Vector( float(a)/100.0f, float(b)/100.0f, float(c)/100.0f ) );
				
				if( fast1 != NULL )
					delete[] fast1;
				fast1 = NULL;
				if( fast2 != NULL )
					delete[] fast2;
				fast2 = NULL;
			}
			else
			{
				if( fast1 != NULL )
					delete[] fast1;
				fast1 = NULL;
			}
		}
		delete[] data;
		file.close();
	}
}

inline void Game::LoadTextures( char * src )
{
	ifstream file;
	file.open( src );
	if( !file.good() )
	{
		return;
	}
	else
	{
		char * data = new char[16000];
		char * fast1 = NULL;
		char * fast2 = NULL;
		while( !file.eof() )
		{
			file.getline( data, 15999 );
			
			fast1 = GetStringBetweenCharacter( data, ' ', 0 );	// Linear  or Neares draw mode
			fast2 = GetStringBetweenCharacter( data, '\"', 1 );	// path to texture file
			
			if( !strcmp( fast1, "Linear:" ) )
			{
				engine.AddTexture( fast2, GL_LINEAR );
			}
			else
			{
				engine.AddTexture( fast2, GL_NEAREST );
			}
			
			if( fast1 != NULL )
				delete[] fast1;
			fast1 = NULL;
			if( fast2 != NULL )
				delete[] fast2;
			fast2 = NULL;
		}
		delete[] data;
		file.close();
	}
}


