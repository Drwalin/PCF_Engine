


inline int Game::LoadObjAsPhysic( char * src )
{
	Vector normal, a, b, c;
	
	int i;
	char * argument = new char[4096];
	char * stringbetweenslash = new char[4096];
	
	vector < Vector > vertices;
	vector < Vector > normals;
	Vector fastvec;
	
	ifstream file;
	file.open( src );
	
	if( file.good() )	// if file exist
	{
		int face[9];
		
		while( !file.eof() )
		{
			file >> argument;
			if( !strcmp( argument, "v" ) )		// Vertices
			{
				file >> fastvec[0];
				file >> fastvec[1];
				file >> fastvec[2];
				vertices.push_back( fastvec );
			}
			else if( !strcmp( argument, "vn" ) )		// Vertices
			{
				file >> fastvec[0];
				file >> fastvec[1];
				file >> fastvec[2];
				normals.push_back( fastvec );
			}
			else if( !strcmp( argument, "f" ) )		// Faces
			{
				file.getline( argument, 4095 );
				
				stringbetweenslash = GetStringBetweenCharacter( argument, '/', 0 );
				face[0] = GetIntFromString( stringbetweenslash, 0 );
				face[0]--;
				stringbetweenslash = GetStringBetweenCharacter( argument, '/', 1 );
				face[1] = GetIntFromString( stringbetweenslash, 0 );
				face[1]--;
				stringbetweenslash = GetStringBetweenCharacter( argument, '/', 2 );
				face[2] = GetIntFromString( stringbetweenslash, 0 );
				face[2]--;
				stringbetweenslash = GetStringBetweenCharacter( argument, '/', 2 );
				face[3] = GetIntFromString( stringbetweenslash, 1 );
				face[3]--;
				stringbetweenslash = GetStringBetweenCharacter( argument, '/', 3 );
				face[4] = GetIntFromString( stringbetweenslash, 0 );
				face[4]--;
				stringbetweenslash = GetStringBetweenCharacter( argument, '/', 4 );
				face[5] = GetIntFromString( stringbetweenslash, 0 );
				face[5]--;
				stringbetweenslash = GetStringBetweenCharacter( argument, '/', 4 );
				face[6] = GetIntFromString( stringbetweenslash, 1 );
				face[6]--;
				stringbetweenslash = GetStringBetweenCharacter( argument, '/', 5 );
				face[7] = GetIntFromString( stringbetweenslash, 0 );
				face[7]--;
				stringbetweenslash = GetStringBetweenCharacter( argument, '/', 6 );
				face[8] = GetIntFromString( stringbetweenslash, 0 );
				face[8]--;
				
				a = vertices[face[0]];
				b = vertices[face[3]];
				c = vertices[face[6]];
				normal = ( a - b ) && ( a - c );
				if( normal.Dot( normals[face[2]] ) < 0.0f || normal.Dot( normals[face[5]] ) < 0.0f || normal.Dot( normals[face[8]] ) < 0.0f )
					normal = 0.0f - normal;
				normal.Normalize();
				GameInstantiation->engine.AddPhysicTriangle( a, b, c, normal );
			}
			else
			{
				file.getline( argument, 4095 );
			}
		}
	}
	
	vertices.resize(0);
	normals.resize(0);
	
	delete[] argument;
	delete[] stringbetweenslash;
	
	return 0;
}


