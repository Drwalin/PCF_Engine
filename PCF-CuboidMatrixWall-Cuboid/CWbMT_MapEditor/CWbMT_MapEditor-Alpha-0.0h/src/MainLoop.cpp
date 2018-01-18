


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


