


void UpdateMoveWindow( float time )
{
	if( ActivatedWindow >= 0 && ActivatedWindow <= window.size() )
	{
		window[ActivatedWindow].scale += float(GetWheelMove());
		if( window[ActivatedWindow].scale <= 1.0f )
			window[ActivatedWindow].scale = 1.0f;
	}
	
	if( isLMBPressed() )
	{
		int i;
		for( i = 0; i < window.size(); i++ )
		{
			if( window[i].IsPointInside( mouse.x, mouse.y ) )
			{
				ActivatedWindow = i;
				
				if( window[i].win != NULL )
				{
					while( isLMBDown() )
					{
						al_get_keyboard_state( &keyb_currentFrame );
						al_get_mouse_state( &mouse );
						
						Vector fast_vec = SetVector( 0.0f, 0.0f, 0.0f );
						if( isKeyDown( ALLEGRO_KEY_W ) )
							fast_vec += (window[i].win -> GetForwardVersor()) * 10.0f * time;
						if( isKeyDown( ALLEGRO_KEY_S ) )
							fast_vec += (window[i].win -> GetBackwardVersor()) * 10.0f * time;
						if( isKeyDown( ALLEGRO_KEY_A ) )
							fast_vec += (window[i].win -> GetLeftVersor()) * 10.0f * time;
						if( isKeyDown( ALLEGRO_KEY_D ) )
							fast_vec += (window[i].win -> GetRightVersor()) * 10.0f * time;
						
						window[i].win -> Update( mouse_lastFrame.x-mouse.x, mouse_lastFrame.y-mouse.y, fast_vec );
						
						Renderer();
						mouse_lastFrame = mouse;
						keyb_lastFrame = keyb_currentFrame;
					}
					return;
				}
				else
				{
					float px, py, nx, ny;
					window[i].GetPoint( mouse.x-window[i].x, mouse.y-window[i].y, &px, &py );
					
					while( isLMBDown() )
					{
						al_get_keyboard_state( &keyb_currentFrame );
						al_get_mouse_state( &mouse );
						
						window[i].GetPoint( mouse.x-window[i].x, mouse.y-window[i].y, &nx, &ny );
						
						window[i].mx += px - nx;
						window[i].my += py - ny;
						
						window[i].GetPoint( mouse.x-window[i].x, mouse.y-window[i].y, &px, &py );
						
						Renderer();
						mouse_lastFrame = mouse;
						keyb_lastFrame = keyb_currentFrame;
					}
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


