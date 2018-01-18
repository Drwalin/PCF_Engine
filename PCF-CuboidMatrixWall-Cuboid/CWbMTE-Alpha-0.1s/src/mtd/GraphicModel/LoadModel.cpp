


inline int GraphicModel::LoadModel( char * src )
{
	{
		//this -> ~GraphicModel();
		if( name != NULL )
			delete[] name;
		loaded = false;
	}
	
	int NameSize, i, j;
	char * argument = new char[4096];
	
	for( NameSize = 0; (*(src+NameSize)<127) && (*(src+NameSize)>31); NameSize++ ){}	// check name size
	name = new char[NameSize+1];
	for( i = 0; (*(src+i)<127) && (*(src+i)>31) && (i<=NameSize); i++ ) { *(name+i) = 0; *(name+i) = *(src+i); }	// move src name to name	
	
	ifstream file;
	file.open( src );
	
	printf( "\n dziala? ladowanie modeli" );
	getch();
	
	if( file.good() )	// if file exist
	{
		printf( "\naad" );
		getch();
		
		file.getline( argument, 4095 );
		
		if( !strcmp( argument, "space,V=xyzC=xy,T=iiiN=xyz" ) )
		/*
			type of saving data
			"space" - coordinates are separated by ' '
			"V=xyzC=xy" - vertices are describes by coordinates x, y, z
			"T=iiiN=xyz" - triangles are describes by id's of vertices (by 0), "N=xyz" - means triangle have normal versor created by coordinates x, y, z
		*/
		{
			file >> j;
			Vector fast_vec;
			float vertexes[5];
			unsigned int indices[3];
			
			for( i = 0; i < j; i++ )
			{
				file >> vertexes[0];
				file >> vertexes[1];
				file >> vertexes[2];
				file >> vertexes[3];
				file >> vertexes[4];
				VBO.AddVertex( vertexes[0], vertexes[1], vertexes[2], vertexes[3], vertexes[4] );
			}
			
			file >> j;
			
			for( i = 0; i < j; i++ )
			{
				file >> indices[0];
				file >> indices[1];
				file >> indices[2];
				file >> vertexes[0];
				file >> vertexes[1];
				file >> vertexes[2];
				VBO.AddTriangle( indices[0], indices[1], indices[2] );
			}
			
			loaded = true;
			printf( "\nModel Loaded" );
			getch();
			
			return 1;
		}
	}
	return 0;		// file not exist
}


