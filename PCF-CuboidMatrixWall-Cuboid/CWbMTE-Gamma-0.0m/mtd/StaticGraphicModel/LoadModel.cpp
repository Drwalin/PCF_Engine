


namespace LoadModelNamespace
{
	struct VT
	{
		float a;	// x
		float b;	// y
	};
};

inline int StaticGraphicModel::LoadModel( char * src, Vector scale_src )
{
	vector < char * > mtl;
	vector < unsigned int > textureID;
	
	int i;
	Vector min, max, scale;
	min.Set( 1000000.0f, 1000000.0f, 1000000.0f );
	max.Set( -1000000.0f, -1000000.0f, -1000000.0f );
	char * argument = new char[4096];
	char * stringbetweenslash = new char[4096];
	
	{	// load mtl
		
		int len = strlen(src) + 1;
		char * nameMtl = new char[len];
		nameMtl[len-1] = 0;
		for( i = 0; i < len-4; ++i );
		{
			nameMtl[i] = src[i];
		}
		nameMtl[i] = 'm';
		++i;
		nameMtl[i] = 't';
		++i;
		nameMtl[i] = 'l';
		
		ifstream file;
		file.open( nameMtl );
		
		if( file.good() )	// if file exist
		{
			while( !file.eof() )
			{
				file >> argument;
				if( !strcmp( argument, "newmtl" ) )
				{
					VBO.resize( VBO.size() + 1 );
					char * fast = NULL;
					mtl.push_back( fast );
					textureID.push_back( 0 );
					mtl.back() = new char[1024];
					file >> mtl.back();
				}
				else if( !strcmp( argument, "map_Kd" ) )			// Texture Coords
				{
					file >> stringbetweenslash;
					stringbetweenslash[ strlen(stringbetweenslash)-3 ] = 0;
					textureID.back() = engineInstantiation -> TextureId( stringbetweenslash );
				}/*
				else
				{
					file.getline( argument, 4095 );
				}*/
			}
		}
		else
		{
			printf( "\n   ERROR loading Mtl for object: file doesn't exist: %s", nameMtl );
		}
		
		delete[] nameMtl;
	}
	
	
	vector < Vector > vertices;
	vector < LoadModelNamespace::VT > texv;
	Vector fastvec;
	LoadModelNamespace::VT fasttext;
	
	char * src_ = new char[strlen(src)+1];
	{
		int l = strlen(src), j = 0, k = 0;
		j = 0;
		for( i = 0; i < strlen(src); ++i )
		{
			src_[i] = src[i];
		}src_[i] = 0;
		for( i = 0; i < l; ++i )
		{
			if( src[i] == '\\' || src[i] == '/' )
				j = i+1;
			if( *(src+i) == '.' )
				k = i;
		}
		if( name != NULL )
			delete[] name;
		name = new char[1+k-j];
		name[k-j] = 0;
		for( i = j; i < k; ++i )
			name[i-j] = src_[i];
	}
	
	ifstream file;
	file.open( src_ );
	delete[] src_;
	
	if( file.good() )	// if file exist
	{
		int face[9];
		
		bool MaxMinCalculated = false;
		
		while( !file.eof() )
		{
			file >> argument;
			if( !strcmp( argument, "usemtl" ) )
			{
				file >> stringbetweenslash;
				for( i = 0; i < mtl.size(); ++i )
					if( !strcmp( mtl[i], stringbetweenslash ) )
						break;
				
				VBO.resize( VBO.size() + 1 );
				VBO.back().SetTexture( textureID[i] );
			}
			else if( !strcmp( argument, "vt" ) )			// Texture Coords
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
				if( min[0] > fastvec[0] )
					min[0] = fastvec[0];
				if( min[1] > fastvec[1] )
					min[1] = fastvec[1];
				if( min[2] > fastvec[2] )
					min[2] = fastvec[2];
				if( max[0] < fastvec[0] )
					max[0] = fastvec[0];
				if( max[1] < fastvec[1] )
					max[1] = fastvec[1];
				if( max[2] < fastvec[2] )
					max[2] = fastvec[2];
			}
			else if( !strcmp( argument, "f" ) )		// Faces
			{
				if( MaxMinCalculated == false )
				{
					scale.Set( abs(max[0]-min[0]), abs(max[1]-min[1]), abs(max[2]-min[2]) );
					for( i = 0; i < vertices.size(); i++ )
					{
						vertices[i] = vertices[i] - min;
						vertices[i][0] -= scale[0] * 0.5f;
						vertices[i][1] -= scale[1] * 0.5f;
						vertices[i][2] -= scale[2] * 0.5f;
						vertices[i] = vertices[i] / scale[1];
					}
					MaxMinCalculated = true;
				}
				
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
				
				VBO.back().AddVertex( vertices[face[0]][0], vertices[face[0]][1], vertices[face[0]][2], texv[face[1]].a, texv[face[1]].b );
				VBO.back().AddVertex( vertices[face[3]][0], vertices[face[3]][1], vertices[face[3]][2], texv[face[4]].a, texv[face[4]].b );
				VBO.back().AddVertex( vertices[face[6]][0], vertices[face[6]][1], vertices[face[6]][2], texv[face[7]].a, texv[face[7]].b );
				VBO.back().AddTriangle( VBO.back().vertices.size()-3, VBO.back().vertices.size()-2, VBO.back().vertices.size()-1 );
			}
			else
			{
				file.getline( argument, 4095 );
			}
		}
	}
	
	vertices.resize(0);
	texv.resize(0);
	
	delete[] argument;
	delete[] stringbetweenslash;
	loaded = true;
	
	printf( "\n Model \"%s\" Loaded", name );
	
	for( i = 0; i < mtl.size(); ++i )
	{
		if( mtl[i] != NULL )
		{
			delete[] mtl[i];
		}
	}
	
	return 0;		// file not exist
}

inline int StaticGraphicModel::LoadModel( char * src )
{
	vector < char * > mtl;
	vector < unsigned int > textureID;
	
	int i;
	Vector min, max, scale;
	min.Set( 1000000.0f, 1000000.0f, 1000000.0f );
	max.Set( -1000000.0f, -1000000.0f, -1000000.0f );
	char * argument = new char[4096];
	char * stringbetweenslash = new char[4096];
	
	{	// load mtl
		
		int len = strlen(src) + 1;
		char * nameMtl = new char[len];
		nameMtl[len-1] = 0;
		for( i = 0; i < len-4; ++i );
		{
			nameMtl[i] = src[i];
		}
		nameMtl[i] = 'm';
		++i;
		nameMtl[i] = 't';
		++i;
		nameMtl[i] = 'l';
		
		ifstream file;
		file.open( nameMtl );
		
		if( file.good() )	// if file exist
		{
			while( !file.eof() )
			{
				file >> argument;
				if( !strcmp( argument, "newmtl" ) )
				{
					VBO.resize( VBO.size() + 1 );
					char * fast = NULL;
					mtl.push_back( fast );
					textureID.push_back( 0 );
					mtl.back() = new char[1024];
					file >> mtl.back();
				}
				else if( !strcmp( argument, "map_Kd" ) )			// Texture Coords
				{
					file >> stringbetweenslash;
					stringbetweenslash[ strlen(stringbetweenslash)-3 ] = 0;
					textureID.back() = engineInstantiation -> TextureId( stringbetweenslash );
				}/*
				else
				{
					file.getline( argument, 4095 );
				}*/
			}
		}
		else
		{
			printf( "\n   ERROR loading Mtl for object: file doesn't exist: %s", nameMtl );
		}
		
		delete[] nameMtl;
	}
	
	
	vector < Vector > vertices;
	vector < LoadModelNamespace::VT > texv;
	Vector fastvec;
	LoadModelNamespace::VT fasttext;
	
	
	char * src_ = new char[strlen(src)+1];
	{
		int l = strlen(src), j = 0, k = 0;
		j = 0;
		for( i = 0; i < strlen(src); ++i )
		{
			src_[i] = src[i];
		}src_[i] = 0;
		for( i = 0; i < l; ++i )
		{
			if( src[i] == '\\' || src[i] == '/' )
				j = i+1;
			if( *(src+i) == '.' )
				k = i;
		}
		if( name != NULL )
			delete[] name;
		name = new char[1+k-j];
		name[k-j] = 0;
		for( i = j; i < k; ++i )
			name[i-j] = src_[i];
	}
	
	ifstream file;
	file.open( src_ );
	printf( "\n                     %s", src_ );
	delete[] src_;
	
	
	
	
	if( file.good() )	// if file exist
	{
		int face[9];
		
		while( !file.eof() )
		{
			file >> argument;
			if( !strcmp( argument, "usemtl" ) )
			{
				file >> stringbetweenslash;
				for( i = 0; i < mtl.size(); ++i )
					if( !strcmp( mtl[i], stringbetweenslash ) )
						break;
				
				if( i >= mtl.size() )
				{
					if( VBO.size() == 0 )
					{
						VBO.resize( 1 );
						VBO.back().SetTexture( 1 );
					}
				}
				else
				{
					VBO.resize( VBO.size() + 1 );
					VBO.back().SetTexture( textureID[i] );
				}
			}
			else if( !strcmp( argument, "vt" ) )			// Texture Coords
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
				
				VBO.back().AddVertex( vertices[face[0]][0], vertices[face[0]][1], vertices[face[0]][2], texv[face[1]].a, texv[face[1]].b );
				VBO.back().AddVertex( vertices[face[3]][0], vertices[face[3]][1], vertices[face[3]][2], texv[face[4]].a, texv[face[4]].b );
				VBO.back().AddVertex( vertices[face[6]][0], vertices[face[6]][1], vertices[face[6]][2], texv[face[7]].a, texv[face[7]].b );
				VBO.back().AddTriangle( VBO.back().vertices.size()-3, VBO.back().vertices.size()-2, VBO.back().vertices.size()-1 );
			}
			else
			{
				file.getline( argument, 4095 );
			}
		}
	}
	
	vertices.resize(0);
	texv.resize(0);
	
	delete[] argument;
	delete[] stringbetweenslash;
	loaded = true;
	
	printf( "\n Model \"%s\" Loaded", name );
	
	for( i = 0; i < mtl.size(); ++i )
	{
		if( mtl[i] != NULL )
		{
			delete[] mtl[i];
		}
	}
	
	return 0;		// file not exist
}


