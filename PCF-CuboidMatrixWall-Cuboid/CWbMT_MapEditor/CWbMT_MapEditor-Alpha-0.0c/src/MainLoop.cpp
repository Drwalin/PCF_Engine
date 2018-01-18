


inline int CheckButtons()
{
	int i;
	for( i = 0; i < button.size(); i++ )
	{
		if( button[i].IsPointInside( mouse.x, mouse.y ) )
		{
			/*
			
			
			*/
			return 1;
		}
	}
	return 0;
}

void UpdateIteration( float time )
{
	int i;
	
    if( isLMBPressed() )
    {
    	if( CheckButtons() == 1 )
    	{
			
		}
		else
    	{
			for( i = 0; i < 3; i++ )
			{
				if( window[i].IsPointInside( mouse.x, mouse.y ) )
				{
					float x, y;
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
						vertex.push_back( SetVector( 2.0f, x, y ) );
						break;
					}
					
					
					
					break;
				}
			}
			
			
			
			
		}
	}
    
    
    
    
    
    
    
}


