


inline void ShadowMap::CalculateBaseLights( Map * map )
{
	map->lightSourcesStatic.resize( 1 );
	int i, j, srcNum = map->lightSourcesStatic.size();
	
	LightSource * source = &(map->lightSourcesStatic[0]);
	
	source[0].origin.Set( 0.0f, 15.0f, 0.0f );
	source[0].direction.Set( 0.0f, -1.0f, 0.0f );
	source[0].range = 230.0f;
	source[0].angle = 110.0f;
	
	
	Vector point;
	float lenght, dlen, angle;
	unsigned char dColor;
	int SegmentCollisonFlag;
	
	for( j = 0; j < VBO.vertices.size(); ++j )
	{
		for( i = 0; i < srcNum; ++i )
		{
			point = VBO.vertices[j].pos;
			dlen = ( point - source[i].origin ).Lenght();
			if( dlen < source[i].range )
			{
				angle = acos( source[i].direction.Dot( VBO.vertices[j].pos - source[i].origin ) / dlen ) * 180.0f / float(M_PI);
				if( angle < source[i].angle )
				{
					SegmentCollisonFlag = map->SegmentCollision( source[i].origin, VBO.vertices[j].pos + ( ( VBO.vertices[j].pos - source[i].origin ) * 0.0f ), &point );
					
					lenght = ( point - source[i].origin ).Lenght();
					
					
					if( lenght >= dlen-0.08f || SegmentCollisonFlag == COLLISION_NO )
					{
						if( abs(VBO.vertices[j].pos[0]) > 36.0f && abs(VBO.vertices[j].pos[2]) > 36.0f && VBO.vertices[j].pos[1] > -1.0f && VBO.vertices[j].pos[1] < 14.0f )
							printf( "\n %f  :  %f  :  %f", VBO.vertices[j].pos[0], VBO.vertices[j].pos[1], VBO.vertices[j].pos[2] );
						
						
						dColor = (( unsigned char )( 230.0f * ( source[i].range - dlen ) * ( source[i].angle - angle ) / ( source[i].angle * source[i].range ) ));
						if( dColor <= baseColor[j] )
							baseColor[j] -= dColor;
						else
							baseColor[j] = 0;
					}
				}
			}
		}
		if( j*5/(VBO.vertices.size()) != (j+1)*5/(VBO.vertices.size()) )
			printf( " ." );
	}
	
	for( i = 0; i < VBO.vertices.size(); ++i )
	{
		VBO.vertices[i].a = baseColor[i];
	}
}


