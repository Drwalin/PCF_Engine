


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
		
		if( !strcmp( argument, "sapce,V=xyzC=xy,T=iiiN=xyz" ) )
		/*
			type of saving data
			"space" - coordinates are separated by ' '
			"V=xyzC=xy" - vertices are describes by coordinates x, y, z
			"T=iiiN=xyz" - triangles are describes by id's of vertices (by 0), "N=xyz" - means triangle have normal versor created by coordinates x, y, z
		*/
		{
			file >> i;
			Vector fast_vec;
			vertex.resize( i );
			
			for( i = 0; i < vertex.size(); i++ )
			{
				file >> vertex[i][0];
				file >> vertex[i][1];
				file >> vertex[i][2];
				file >> vertex[i][3];
				file >> vertex[i][4];
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
				fast_vec = triangles[i].normal;
				triangles[i].CalcNormal();
				if( fast_vec != triangles[i].normal )
				{
					triangles[i].reverse_normal = (triangles[i].reverse_normal>=0.0f) ? -1.0f : 1.0f;
					triangles[i].CalcNormal();
				}
			}
		}
	}
	
	file.close();
	
	delete[] name;
	delete[] argument;
}


