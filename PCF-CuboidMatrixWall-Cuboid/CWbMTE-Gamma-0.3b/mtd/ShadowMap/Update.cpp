


inline void ShadowMap::Update( Map * map, int beg, int end )
{
	unsigned char FastColor;
	
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
			dColor = map -> lightSourcesDynamic[i] -> GetLightStrenght( VBO.vertices[j].pos );
			
			if( dColor <= FastColor )
				FastColor -= dColor;
			else
				FastColor = 0;
			
			/*
			point = VBO.vertices[j].pos;
			dlen = ( point - map->lightSourcesDynamic[i]->origin ).Lenght();
			if( dlen < map->lightSourcesDynamic[i]->range )
			{
				angle = acos( map->lightSourcesDynamic[i]->direction.Dot( VBO.vertices[j].pos - map->lightSourcesDynamic[i]->origin ) / dlen ) * 180.0f / float(M_PI);
				if( angle < map->lightSourcesDynamic[i]->angle )
				{
					if( dlen <= 0.01f )
					{
						dColor = ( unsigned char )( 230.0f * sqrt((-dlen/(map->lightSourcesDynamic[i]->range))+1.0f) * ((map->lightSourcesDynamic[i]->angle-angle)/(map->lightSourcesDynamic[i]->angle)) * map->lightSourcesDynamic[i]->density );
						if( dColor <= FastColor )
							FastColor -= dColor;
						else
							FastColor = 0;
					}
					else
					{
						SegmentCollisonFlag = map->SegmentCollision( map->lightSourcesDynamic[i]->origin, VBO.vertices[j].pos, &point );
						
						lenght = ( point - map->lightSourcesDynamic[i]->origin ).Lenght();
						
						
						if( lenght >= dlen-0.08f || SegmentCollisonFlag == COLLISION_NO )
						{
							//dColor = ( unsigned char )( 230.0f * sqrt((-dlen/(map->lightSourcesDynamic[i]->range))+1.0f) * sqrt((-angle/(map->lightSourcesDynamic[i]->angle))+1.0f) * map->lightSourcesDynamic[i]->density );
							dColor = ( unsigned char )( 230.0f * sqrt((-dlen/(map->lightSourcesDynamic[i]->range))+1.0f) * ((map->lightSourcesDynamic[i]->angle-angle)/(map->lightSourcesDynamic[i]->angle)) * map->lightSourcesDynamic[i]->density );
							if( dColor <= FastColor )
								FastColor -= dColor;
							else
								FastColor = 0;
						}
					}
				}
			}
			*/
		}
		
		VBO.vertices[j].a = FastColor;
	}
}

