


void UpdateCreateVertex( float time )
{
	if( isLMBPressed() )
	{
		int i;
		float x, y;
		for( i = 0; i < window.size(); i++ )
		{
			if( window[i].win == NULL )
			{
				if( window[i].IsPointInside( mouse.x, mouse.y ) )
				{
					ActivatedWindow = i;
					{
						window[i].GetPoint( mouse.x-window[i].x, mouse.y-window[i].y, &x, &y );
						vertex.resize( vertex.size()+1 );
						switch( window[i].drawaxis )
						{
						case 1:
							vertex[vertex.size()-1].pos.Set( x, y, 2.0f );
							break;
						case 2:
							vertex[vertex.size()-1].pos.Set( x, 2.0f, y );	
							break;
						case 3:
							vertex[vertex.size()-1].pos.Set( 2.0f, y, x );
							break;
						}
					}
					ActivatedVertex = vertex.size()-1;
					return;
				}
				
				if( i >= window.size()-1 )
				{
					ActivatedWindow = -1;
				}
			}
		}
	}
}


