
/*
	file struct:
		
		[SECTION 1]
			-textures
			
		
		[SECTION 2]
			-vertexes
		
		[SECTION 3]
			-draw
*/

inline int GraphicModel::LoadModel( char * src )
{
	this -> ~GraphicModel();
	
	int NameSize, i;
	
	for( NameSize = 0; (*(src+NameSize)<127) && (*(src+NameSize)>31); NameSize++ ){}	// check name size
	
	name = new char[NameSize+1];
	
	for( i = 0; (*(src+i)<127) && (*(src+i)>31) && (i<=NameSize); i++ ) { *(name+i) = 0; *(name+i) = *(src+i); }	// move src name to name	
	
	ifstream file;
	file.open( name, ios::binary );
	
	if( file.good() )	// if file exist
	{
		char TexturesNumber = 0;
		char VertexNumber = 0;
		char Fast = 0;
		char NameSize = 0;
		char * NameFast = new char[257];
		vector < char > dataSection;
		
		file >> TexturesNumber;						// read number of textures
		texture = new Texture[(int)TexturesNumber];	// create textures
		for( i = 0; i < TexturesNumber; i++ )		// load and read textures
		{
			file >> NameSize;
			file.read( NameFast, (int)NameSize );
			*(NameFast+NameSize) = 0;
			(texture+i) -> LoadInit( NameFast );	// load textures
		}
		delete[] NameFast;
		
		
		file >> VertexNumber;								// read number of vertexes
		VertexSize = VertexNumber;
		scale = new char[((int)(VertexSize))*3];			// create vertexes
		for( i = 0; i < ((int)(VertexSize))*3; i++ )		// read vertexes
		{
			file >> Fast;
			*(scale+i) = (((short)Fast)<<8);
			file >> Fast;
			*(scale+i) + ((short)Fast);
		}
		
		while( !file.eof() )	// read data section
		{
			file >> Fast;
			dataSection.push_back( Fast );
		}
		
		DataSize = dataSection.size();
		data = new char[ DataSize ];	// create data
		
		for( i = 0; i < DataSize; i++ )		// move date from vector to data table
		{
			*(data+i) = dataSection[i];
		}
		
		file.close();
		loaded = true;
		return 1;	// file exist
	}
	return 0;		// file not exist
}
