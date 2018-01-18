


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

inline void UpdateKeyboard()
{
	int i;
	if( ActivatedWindow >= 0 && ActivatedWindow <= 2 )
	{
		if( isKeyPressed(ALLEGRO_KEY_EQUALS) )
		{
			window[ActivatedWindow].scale += 0.1f;
		}
		if( isKeyPressed(ALLEGRO_KEY_MINUS) )
		{
			window[ActivatedWindow].scale -= 0.1f;
		}
		if( window[ActivatedWindow].scale < 0.01f )
		{
			window[ActivatedWindow].scale = 0.01f;
		}
		else if( window[ActivatedWindow].scale > 1000.0f )
		{
			window[ActivatedWindow].scale = 1000.0f;
		}
	}
	
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
			x_ = vertex[i][1];
			y_ = vertex[i][2];
			break;
		}
		wind->GetPoint( x_, y_, &_x, &_y );
		if( abs(_x-(x-(wind->x))) < 10 && abs(_y-(y-(wind->y))) < 10 )
			return i;
	}
	return -1;
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
					if( ActivatedWindow != i )
					{
						ActivatedWindow = i;
						break;
					}
					
					int id = CollidePoint( mouse.x, mouse.y, window+i );
					if( id == -1 )
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
						ActivatedVertex = vertex.size()-1;
					}
					else
					{
						ActivatedVertex = id;
					}
					
					break;
				}
				
				if( i == 2 )
				{
					ActivatedWindow = -1;
				}
			}
		}
	}
	
	UpdateKeyboard();
	
	
}


