


inline void ShadowMap::Update( Map * map, int beg, int end )
{
	unsigned char FastColor = 230;
	
	Vector point;
	float lenght, dlen, angle;
	unsigned char dColor;
	int SegmentCollisonFlag;
	
	unsigned int i, j, srcNum = map->lightSourcesDynamic.size();
	for( j = beg; j < VBO.vertices.size() && j < end; ++j )
	{
		FastColor = baseColor[j];
		for( i = 0; i < srcNum; ++i )
		{
			point = VBO.vertices[j].pos;
			dlen = ( point - map->lightSourcesDynamic[i]->origin ).Lenght();
			if( dlen < map->lightSourcesDynamic[i]->range )
			{
				angle = acos( map->lightSourcesDynamic[i]->direction.Dot( VBO.vertices[j].pos - map->lightSourcesDynamic[i]->origin ) / dlen ) * 180.0f / float(M_PI);
				if( angle < map->lightSourcesDynamic[i]->angle )
				{
					SegmentCollisonFlag = map->SegmentCollision( map->lightSourcesDynamic[i]->origin, VBO.vertices[j].pos + ( ( VBO.vertices[j].pos - map->lightSourcesDynamic[i]->origin ) * 0.0f ), &point );
					
					lenght = ( point - map->lightSourcesDynamic[i]->origin ).Lenght();
					
					
					if( lenght >= dlen-0.08f || SegmentCollisonFlag == COLLISION_NO )
					{
						dColor = ( unsigned char )( 230.0f * sqrt((-dlen/(map->lightSourcesDynamic[i]->range))+1) * sqrt((-angle/(map->lightSourcesDynamic[i]->angle))+1) * map->lightSourcesDynamic[i]->density );
						if( dColor <= FastColor )
							FastColor -= dColor;
						else
							FastColor = 0;
					}
				}
			}
		}
		
		VBO.vertices[j].a = FastColor;
	}
}

