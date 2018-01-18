


inline int CheckButtons()
{
	int i, j;
	for( i = 0; i < button.size(); i++ )
	{
		if( button[i].IsPointInside( mouse.x, mouse.y ) )
		{
			if( button[i].other_option == DRAW_NONE )
			{
				switch( button[i].option_enabling )
				{
				case LOAD_PROJECT:
					LoadProject();
					break;
				case SAVE_PROJECT:
					SaveProject();
					break;
				case SET_TEXTURE_COORDINATES:
					SetTextureCoordinaes();
					break;
				case REVERSE_NORMAL:
					if( ConnectedPoints.size() == 3 )
					{
						for( j = 0; j < triangles.size(); j++ )
						{
							if( triangles[j].IsTherePoint( ConnectedPoints[0] ) )
							{
								if( triangles[j].IsTherePoint( ConnectedPoints[1] ) )
								{
									if( triangles[j].IsTherePoint( ConnectedPoints[2] ) )
									{
										triangles[j].reverse_normal = (triangles[j].reverse_normal>=0.0f) ? -1.0f : 1.0f;
										triangles[j].CalcNormal();
									}
								}
							}
						}
					}
					break;
				default:
					ActivatedEditorOption = button[i].option_enabling;
				}
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

inline void UpdateKeyboard( float time )
{
	int i, j;
	
	if( RENDER_OPTION[USE_CONNECTING_POINTS] == false )
	{
		if( ActivatedVertex != -1 )
		{
			if( isKeyPressed(ALLEGRO_KEY_DELETE) )
			{
				for( i = 0; i < triangles.size(); i++ )
				{
					if( triangles[i].IsTherePoint( ActivatedVertex ) )
					{
						triangles.erase( triangles.begin() + i );
						i--;
					}
					else
					{
						if( triangles[i].indices[0] > ActivatedVertex )
							triangles[i].indices[0]--;
						if( triangles[i].indices[1] > ActivatedVertex )
							triangles[i].indices[1]--;
						if( triangles[i].indices[2] > ActivatedVertex )
							triangles[i].indices[2]--;
					}
				}
				vertex.erase( vertex.begin() + ActivatedVertex );
				ActivatedVertex = -1;
			}
		}
	}
	else
	{
		if( isKeyPressed(ALLEGRO_KEY_DELETE) )
		{
			if( ConnectedPoints.size() == 3 )
			{
				for( i = 0; i < triangles.size(); i++ )
				{
					if( triangles[i].IsTherePoint( ConnectedPoints[0] ) )
					{
						if( triangles[i].IsTherePoint( ConnectedPoints[1] ) )
						{
							if( triangles[i].IsTherePoint( ConnectedPoints[2] ) )
							{
								triangles.erase( triangles.begin() + i );
								i--;
								ActivatedVertex = -1;
							}
						}
					}
				}
			}
		}
		else if( isKeyPressed(ALLEGRO_KEY_INSERT) )
		{
			if( ConnectedPoints.size() == 3 )
			{
				for( i = 0; i < triangles.size(); i++ )
				{
					if( triangles[i].IsTherePoint( ConnectedPoints[0] ) )
					{
						if( triangles[i].IsTherePoint( ConnectedPoints[1] ) )
						{
							if( triangles[i].IsTherePoint( ConnectedPoints[2] ) )
							{
								break;
							}
						}
					}
				}
				if( i >= triangles.size() )
				{
						triangles.resize( triangles.size()+1 );
						triangles[ triangles.size()-1 ].indices[0] = ConnectedPoints[0];
						triangles[ triangles.size()-1 ].indices[1] = ConnectedPoints[1];
						triangles[ triangles.size()-1 ].indices[2] = ConnectedPoints[2];
						triangles[ triangles.size()-1 ].CalcNormal();
				}
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
	
	
	if( RENDER_OPTION[USE_CONNECTING_POINTS] == false )
	{
		ConnectedPoints.resize( 0 );
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
	
	UpdateKeyboard( time );
}


