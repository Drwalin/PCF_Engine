


#define source map->lightSourcesStatic

inline void ShadowMap::CalculateBaseLights( Map * map )
{
	Vector point;
	float lenght, dlen, angle;
	unsigned char dColor;
	int SegmentCollisonFlag;
	
	unsigned int i, j, srcNum = map->lightSourcesStatic.size();
	for( j = 0; j < VBO.vertices.size(); ++j )
	{
		for( i = 0; i < srcNum; ++i )
		{
			point = VBO.vertices[j].pos;
			dlen = ( point - map->lightSourcesStatic[i].origin ).Lenght();
			if( dlen < map->lightSourcesStatic[i].range )
			{
				angle = acos( map->lightSourcesStatic[i].direction.Dot( VBO.vertices[j].pos - map->lightSourcesStatic[i].origin ) / dlen ) * 180.0f / float(M_PI);
				if( angle < map->lightSourcesStatic[i].angle )
				{
					SegmentCollisonFlag = map->SegmentCollision( map->lightSourcesStatic[i].origin, VBO.vertices[j].pos + ( ( VBO.vertices[j].pos - map->lightSourcesStatic[i].origin ) * 0.0f ), &point );
					
					lenght = ( point - map->lightSourcesStatic[i].origin ).Lenght();
					
					
					if( lenght >= dlen-0.08f || SegmentCollisonFlag == COLLISION_NO )
					{
						//dColor = ( unsigned char )( 230.0f * sqrt((-dlen/(map->lightSourcesStatic[i].range))+1) * sqrt((-angle/(map->lightSourcesStatic[i].angle))+1) * source[i].density );
						dColor = ( unsigned char )( 230.0f * sqrt((-dlen/(map->lightSourcesDynamic[i]->range))+1.0f) * ((map->lightSourcesDynamic[i]->angle-angle)/(map->lightSourcesDynamic[i]->angle)) * map->lightSourcesDynamic[i]->density );
						if( dColor <= baseColor[j] )
							baseColor[j] -= dColor;
						else
							baseColor[j] = 0;
					}
				}
			}
		}
		
		VBO.vertices[j].a = baseColor[j];
		
		if( j*20/(VBO.vertices.size()) != (j+1)*20/(VBO.vertices.size()) )
			printf( " ." );
	}
}


