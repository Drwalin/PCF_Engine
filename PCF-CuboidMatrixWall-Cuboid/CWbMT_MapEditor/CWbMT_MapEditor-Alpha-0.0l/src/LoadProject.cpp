


inline void LoadProject()
{
	char * name = new char[4096];
	printf( "\n Wrtie project file name: " );
	scanf( "%s", name );
	
	char * argument = new char[4096];
	
	ifstream file;
	file.open( name );
	
	int i;
	
	if( file.good() )
	{
		file.getline( argument, 4095 );
		
		if( !strcmp( argument, "sapce,V=xyz,T=iiiN=xyz" ) )
		/*
			type of saving data
			"space" - coordinates are separated by ' '
			"V=xyz" - vertices are describes by coordinates x, y, z
			"T=iiiN=xyz" - triangles are describes by id's of vertices (by 0), "N=xyz" - means triangle have normal versor created by coordinates x, y, z
		*/
		{
			file >> i;
			vertex.resize( i );
			
			for( i = 0; i < vertex.size(); i++ )
			{
				file >> vertex[i][0];
				file >> vertex[i][1];
				file >> vertex[i][2];
			}
			
			file >> i;
			triangles.resize( i );
			
			for( i = 0; i < triangles.size(); i++ )
			{
				file >> triangles[i].indices[0];
				file >> triangles[i].indices[1];
				file >> triangles[i].indices[2];
				file >> triangles[i].normal[0];
				file >> triangles[i].normal[1];
				file >> triangles[i].normal[2];
			}
		}
	}
	
	file.close();
	
	delete[] name;
	delete[] argument;
}


