


void UpdateOperateVertex( float time )
{
	int i;
	
	if( isRMBPressed() )
	{
		ActivatedVertex = -1;
	}
	
    if( isLMBPressed() )
    {
		for( i = 0; i < window.size(); i++ )
		{
			if( window[i].IsPointInside( mouse.x, mouse.y ) )
			{
				if( ActivatedWindow != i )
				{
					ActivatedWindow = i;
				}
				
				if( window[i].win != NULL )
				{
					int id = CollidePoint( mouse.x, mouse.y, &(window[i]) );
					if( id != -1 )
					{
						ActivatedVertex = id;
						if( RENDER_OPTION[USE_CONNECTING_POINTS] == true )
						{
							int j;
							for( j = 0; j < ConnectedPoints.size(); j++ )
							{
								if( ConnectedPoints[j] == id )
									break;
							}
							if( j >= ConnectedPoints.size() )
							{
								if( ConnectedPoints.size() < 3 )
								{
									ConnectedPoints.push_back( id );
								}
								else
								{
									ConnectedPoints.erase( ConnectedPoints.begin() );
									ConnectedPoints.push_back( id );
								}
							}
						}
					}
				}
				else
				{
					int id = CollidePoint( mouse.x, mouse.y, &(window[i]) );
					if( ActivatedVertex == id )
					{
						float px, py, nx, ny;
						window[i].GetPoint( mouse.x-window[i].x, mouse.y-window[i].y, &px, &py );
						
						while( isLMBDown() )
						{
							al_get_keyboard_state( &keyb_currentFrame );
							al_get_mouse_state( &mouse );
							
							window[i].GetPoint( mouse.x-window[i].x, mouse.y-window[i].y, &nx, &ny );
							
							switch( window[i].drawaxis )
							{
							case 1:
								vertex[ActivatedVertex][0] -= px - nx;
								vertex[ActivatedVertex][1] -= py - ny;
								break;
							case 2:
								vertex[ActivatedVertex][0] -= px - nx;
								vertex[ActivatedVertex][2] -= py - ny;
								break;
							case 3:
								vertex[ActivatedVertex][2] -= px - nx;
								vertex[ActivatedVertex][1] -= py - ny;
								break;
							}
							
							window[i].GetPoint( mouse.x-window[i].x, mouse.y-window[i].y, &px, &py );
							
							Renderer();
							mouse_lastFrame = mouse;
							keyb_lastFrame = keyb_currentFrame;
						}
					}
					else
					{
						ActivatedVertex = id;
						if( RENDER_OPTION[USE_CONNECTING_POINTS] == true )
						{
							int j;
							for( j = 0; j < ConnectedPoints.size(); j++ )
							{
								if( ConnectedPoints[j] == id )
									break;
							}
							if( j >= ConnectedPoints.size() )
							{
								if( ConnectedPoints.size() < 3 )
								{
									ConnectedPoints.push_back( id );
								}
								else
								{
									ConnectedPoints.erase( ConnectedPoints.begin() );
									ConnectedPoints.push_back( id );
								}
							}
						}
					}
				}
				break;
			}
			
			if( i >= window.size()-1 )
			{
				ActivatedWindow = -1;
			}
		}
	}
}


