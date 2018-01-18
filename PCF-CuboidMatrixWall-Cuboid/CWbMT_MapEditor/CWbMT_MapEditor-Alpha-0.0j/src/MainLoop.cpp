


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

inline void UpdateKeyboard( float time )
{
	int i, j;
	
	
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
					i--;
				}
			}
			for( i = 0; i < ConnectedPoints.size(); i++ )
			{
				if( ConnectedPoints[i] == ActivatedVertex )
				{
					ConnectedPoints.erase( ConnectedPoints.begin() + i );
					break;
				}
			}
			ActivatedVertex = -1;
		}
	}
	
	if( RENDER_OPTION[USE_CONNECTING_POINTS] == false )
	{
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
						i -= i%3;
						indices.erase( indices.begin() + i );
						indices.erase( indices.begin() + i );
						indices.erase( indices.begin() + i );
						i--;
					}
				}
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
				for( i = 0; i+2 < indices.size(); i+=3 )
				{
					for( j = 0; j < 3 && ( indices[i+j]==ConnectedPoints[0] || indices[i+j]==ConnectedPoints[1] || indices[i+j]==ConnectedPoints[2] ); j++ ){}
					if( j == 3 )
					{
						indices.erase( indices.begin() + i );
						indices.erase( indices.begin() + i );
						indices.erase( indices.begin() + i );
						ActivatedVertex = -1;
						i -= 3;
						continue;
					}
				}
			}
		}
		else if( isKeyPressed(ALLEGRO_KEY_INSERT) )
		{
			if( ConnectedPoints.size() == 3 )
			{
				for( i = 0; i+2 < indices.size(); i+=3 )
				{
					for( j = 0; j < 3 && ( indices[i+j]==ConnectedPoints[0] || indices[i+j]==ConnectedPoints[1] || indices[i+j]==ConnectedPoints[2] ); j++ ){}
					if( j == 3 )
					{
						break;
					}
				}
				if( i+2 >= indices.size() )
				{
					for( i = 0; i < ConnectedPoints.size(); i++ )
					{
						indices.push_back( ConnectedPoints[i] );
					}
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


