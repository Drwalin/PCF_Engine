


inline void ShadowMap::Generate( Map * map )
{
	printf( "\n Generating Shadow Map" );
	
	VBO.vertices.resize( 0 );
	VBO.indices.resize( 0 );
	
	edgeLenght = 0.5f;
	
	int i, j, k, l, num, a, b, c;
	float d1, d2;
	Vector v1, v2, v3, v4;
	float f1, f2, f3, f4;
	
	Vector dir1, dir2, dir3, beg;
	float range1, range2, range3;
	float len1, len2, len3;
	float max_;
	
	for( int i = 0; i < map->triPHYS.size(); ++i )
	{
		beg = map->triPHYS[i].vertex[0];
		dir1 = map->triPHYS[i].vertex[1] - beg;
		dir2 = map->triPHYS[i].vertex[2] - beg;
		dir3 = map->triPHYS[i].vertex[2] - map->triPHYS[i].vertex[1];
		range1 = dir1.Lenght();
		range2 = dir2.Lenght();
		range3 = dir3.Lenght();
		
		if( abs(range1) <= 0.07f || abs(range2) <= 0.07f || abs(range3) <= 0.07f )
		{
			continue;
		}
		else
		{
			max_ = range1;
			if( range2 > max_ ) max_ = range2;
			if( range3 > max_ ) max_ = range3;
			
			num = int( max_ / edgeLenght );	// number of edges on triangle
			if( num > 20 )
				num = 20;
			
			if( num <= 1 )
			{
				a = GetIndiceId( map->triPHYS[i].vertex[0] );
				b = GetIndiceId( map->triPHYS[i].vertex[1] );
				c = GetIndiceId( map->triPHYS[i].vertex[2] );
				VBO.AddTriangle( a, b, c );
			}
			else
			{
				len1 = range1 / float(num);
				len2 = range2 / float(num);
				len3 = range3 / float(num);
				
				dir1 *= len1 / range1;
				dir2 *= len2 / range2;
				dir3 *= len3 / range3;
				
				
				for( j = 0; j < num; ++j )
				{
					for( k = 0; k < (num-j); ++k )
					{
						a = GetIndiceId( beg + (dir1*float(j))   + (dir2*float(k)) );
						b = GetIndiceId( beg + (dir1*float(j+1)) + (dir2*float(k)) );
						c = GetIndiceId( beg + (dir1*float(j))   + (dir2*float(k+1)) );
						VBO.AddTriangle( a, b, c );
						
						if( (k+1) < (num-j) )
						{
							a = GetIndiceId( beg + (dir1*float(j+1)) + (dir2*float(k+1)) );
							VBO.AddTriangle( a, b, c );
						}
					}
				}
			}
		}
		
		if( i*20/(map->triPHYS.size()) != (i+1)*20/(map->triPHYS.size()) )
			printf( " ." );
	}
	
	if( baseColor != NULL )
		delete[] baseColor;
	baseColor = new unsigned char[VBO.vertices.size()];
	for( i = 0; i < VBO.vertices.size(); ++i )
	{
		baseColor[i] = 230;
	}
	
	printf( " Done" );
	
	printf( "\n Calculating static lights" );
	
	CalculateBaseLights( map );
	
	printf( " Done" );
	
	printf( "\n Vertices: %i", VBO.vertices.size() );
	printf( "\n Triangles: %i", VBO.indices.size() / 3 );
}


