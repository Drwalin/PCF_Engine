


inline int CheckButtons()
{
	int i;
	for( i = 0; i < button.size(); i++ )
	{
		if( button[i].IsPointInside( mouse.x, mouse.y ) )
		{
			if( button[i].other_option == DRAW_NONE )
			{
				ActivatedEditorOption = button[i].option_enabling;
			}
			else
			{
				RENDER_OPTION[button[i].other_option] = RENDER_OPTION[button[i].other_option] ? false : true;
			}
			return 1;
		}
	}
	return 0;
}

inline void UpdateKeyboard()
{
	int i;
	
	if( ActivatedVertex != -1 )
	{
		if( isKeyPressed(ALLEGRO_KEY_DELETE) )
		{
			vertex.erase( vertex.begin() + ActivatedVertex );
			for( i = 0; i < indices.size(); i++ )
			{
				if( indices[i] > ActivatedVertex )
				{
					indices[i]--;
				}
				else if( indices[i] == ActivatedVertex )
				{
					i = (i/3)*3;
					indices.erase( indices.begin() + i );
					indices.erase( indices.begin() + i );
					indices.erase( indices.begin() + i );
				}
			}
			ActivatedVertex = -1;
		}
	}
}

int CollidePoint( int x, int y, SeeAspect *wind )
{
	int i;
	float x_, y_;
	int _x, _y;
	for( i = 0; i < vertex.size(); i++ )
	{
		switch( wind -> drawaxis )
		{
		case 1:
			x_ = vertex[i][0];
			y_ = vertex[i][1];
			break;
		case 2:
			x_ = vertex[i][0];
			y_ = vertex[i][2];
			break;
		case 3:
			x_ = vertex[i][2];
			y_ = vertex[i][1];
			break;
		}
		wind->GetPoint( x_, y_, &_x, &_y );
		if( abs(_x-(x-(wind->x))) < 8 && abs(_y-(y-(wind->y))) < 8 )
			return i;
	}
	return -1;
}




void UpdateOperateVertex( float time )
{
	int i;
	
	if( ActivatedVertex != -1 )
	{
		if( isKeyPressed(ALLEGRO_KEY_DELETE) )
		{
			vertex.erase( vertex.begin() + ActivatedVertex );
			for( i = 0; i < indices.size(); i++ )
			{
				if( indices[i] > ActivatedVertex )
				{
					indices[i]--;
				}
				else if( indices[i] == ActivatedVertex )
				{
					i = (i/3)*3;
					indices.erase( indices.begin() + i );
					indices.erase( indices.begin() + i );
					indices.erase( indices.begin() + i );
				}
			}
			ActivatedVertex = -1;
		}
	}
	
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
				
				int id = CollidePoint( mouse.x, mouse.y, &(window[i]) );
				if( id != -1 )
				{
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

void UpdateCreateVertex( float time )
{
	if( isLMBPressed() )
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






void UpdateIteration( float time )
{
	if( isLMBPressed() )
	{
		CheckButtons();
	}
	
	switch( ActivatedEditorOption )
	{
	case MOVE_WINDOW:
		UpdateMoveWindow( time );
		break;
	case OPERATE_VERTEX:
		UpdateOperateVertex( time );
		break;
	case CREATE_VERTEX:
		UpdateCreateVertex( time );
		break;
	}
}


