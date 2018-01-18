


inline void Button::Draw()
{
	if( other_option == DRAW_NONE )
	{
		switch( option_enabling )
		{
		case LOAD_PROJECT:
		case SAVE_PROJECT:
			al_draw_scaled_bitmap( texture_on, 0, 0, al_get_bitmap_width(texture_on), al_get_bitmap_height(texture_on), x, y, wx, wy, 0 );
			break;
		default:
			if( ActivatedEditorOption == option_enabling )
				al_draw_scaled_bitmap( texture_on, 0, 0, al_get_bitmap_width(texture_on), al_get_bitmap_height(texture_on), x, y, wx, wy, 0 );
			else
				al_draw_scaled_bitmap( texture_off, 0, 0, al_get_bitmap_width(texture_off), al_get_bitmap_height(texture_off), x, y, wx, wy, 0 );
		}
	}
	else
	{
		if( RENDER_OPTION[other_option] == true )
			al_draw_scaled_bitmap( texture_on, 0, 0, al_get_bitmap_width(texture_on), al_get_bitmap_height(texture_on), x, y, wx, wy, 0 );
		else
			al_draw_scaled_bitmap( texture_off, 0, 0, al_get_bitmap_width(texture_off), al_get_bitmap_height(texture_off), x, y, wx, wy, 0 );
	}
}

inline bool Button::IsPointInside( int srcx, int srcy )
{
	if( srcx > x && srcy > y && srcx < x+wx && srcy < y+wy )
		return true;
	return false;
}


Button::Button()
{
	option_enabling = NONE_OPTION;
	x = 0;
	y = 0;
	wx = 0;
	wy = 0;
}


