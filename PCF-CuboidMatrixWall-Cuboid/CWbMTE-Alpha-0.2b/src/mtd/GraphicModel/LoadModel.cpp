


namespace LoadModelNamespace
{
	struct VT
	{
		float a;	// x
		float b;	// y
	};
};

inline int GraphicModel::LoadModel( char * src )
{
	int i;
	char * argument = new char[4096];
	char * stringbetweenslash = new char[4096];
	
	vector < Vector > vertices;
	vector < LoadModelNamespace::VT > texv;
	Vector fastvec;
	LoadModelNamespace::VT fasttext;
	
	ifstream file;
	file.open( src );
	
	if( file.good() )	// if file exist
	{
		int face[9];
		
		printf( "\nZly mudzin z Africa!" );
		
		while( !file.eof() )
		{
			file >> argument;
			if( !strcmp( argument, "vt" ) )			// Texture Coords
			{
				file >> fasttext.a;
				file >> fasttext.b;
				texv.push_back( fasttext );
			}
			else if( !strcmp( argument, "v" ) )		// Vertices
			{
				file >> fastvec[0];
				file >> fastvec[1];
				file >> fastvec[2];
				vertices.push_back( fastvec );
			}
			else if( !strcmp( argument, "f" ) )		// Faces
			{
				printf( "\n" );
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
				
				VBO.AddVertex( vertices[face[0]][0], vertices[face[0]][1], vertices[face[0]][2], texv[face[1]].a, texv[face[1]].b );
				VBO.AddVertex( vertices[face[3]][0], vertices[face[3]][1], vertices[face[3]][2], texv[face[4]].a, texv[face[4]].b );
				VBO.AddVertex( vertices[face[6]][0], vertices[face[6]][1], vertices[face[6]][2], texv[face[7]].a, texv[face[7]].b );
				VBO.AddTriangle( VBO.vertices.size()-3, VBO.vertices.size()-2, VBO.vertices.size()-1 );
			}
			else
			{
				file.getline( argument, 4095 );
			}
		}
	}
	delete[] argument;
	delete[] stringbetweenslash;
	loaded = true;
	printf( "\nZly mudzin z Africka!!!" );
	
	return 0;		// file not exist
}


