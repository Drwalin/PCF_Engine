


void UpdateCreateVertex( float time )
{
	if( isLMBDown() )
	{
		int i;
		float x, y;
		for( i = 0; i < 3; i++ )
		{
			if( window[i].IsPointInside( mouse.x, mouse.y ) )
			{
				ActivatedWindow = i;
				{
					window[i].GetPoint( mouse.x-window[i].x, mouse.y-window[i].y, &x, &y );
					switch( window[i].drawaxis )
					{
					case 1:
						vertex.push_back( SetVector( x, y, 2.0f ) );
						break;
					case 2:
						vertex.push_back( SetVector( x, 2.0f, y ) );	
						break;
					case 3:
						vertex.push_back( SetVector( 2.0f, y, x ) );
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


