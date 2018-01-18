


int AnimatedGraphicModel::LoadModel( char * src )
{
	ifstream file, frame;
	file.open( src );
	
	if( file.good() )
	{
		int i, framesNumber;
		
		{
			int l = strlen( src ), j = 0, k = 0;
			j = 0;
			for( i = 0; i < l; i++ )
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
			for( i = j; i < k; i++ )
				name[i-j] = src[i];
		}
		
		char * modelPath = NULL;
		{
			int l = strlen( src ), j = 0;
			for( i = l-1; i >= 0; i-- )
			{
				if( src[i] == '\\' || src[i] == '/' )
				{
					j = i+1;
					break;
				}
			}
			modelPath = new char[j+1];
			modelPath[j] = 0;
			for( i = 0; i < j; i++ )
			{
				modelPath[i] = src[i];
			}
		}
		
		
		
		
		
		char * filePath = new char [4096];
		
		
		
		
		
		delete[] modelPath;
		delete[] filePath;
		return 1;
	}
	return 0;
}


