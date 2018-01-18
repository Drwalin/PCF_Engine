


inline void SetTextureCoordinaes()
{
	if( ActivatedVertex < 0 || ActivatedVertex >= vertex.size() )
	{
		return;
	}
	
	int mx(0), my(0);
	int texwidth = al_get_bitmap_width( FullMapTexture );
	int texheight = al_get_bitmap_height( FullMapTexture );
	int windowx = al_get_bitmap_width(  al_get_backbuffer( display ) );
	int windowy = al_get_bitmap_height( al_get_backbuffer( display ) );
	int ww_ = windowx,wh_ = windowy;
	
	mouse_lastFrame = mouse;
	
	if( ww_ > texwidth )
		ww_ = texwidth;
	if( wh_ > texheight )
		wh_ = texheight;
	
	while( !isKeyDown(ALLEGRO_KEY_ENTER) )
	{
		al_get_keyboard_state( &keyb_currentFrame );
		al_get_mouse_state( &mouse );
		
		if( isLMBDown() )
		{
			mx += mouse_lastFrame.x - mouse.x;
			my += mouse_lastFrame.y - mouse.y;
		}
		
		/*
		if( mx > texwidth-ww_ )
			mx = texwidth-ww_;
		if( my > texheight-wh_ )
			my = texheight-wh_;
		
		if( mx < 0 )
			mx = 0;
		if( my < 0 )
			my = 0;
		*/
		
		al_set_target_bitmap( al_get_backbuffer( display ) );
		al_clear_to_color( al_map_rgb( 32, 32, 32 ) );
		
		al_draw_scaled_bitmap( 	FullMapTexture,
								mx, my,
								ww_, wh_,
								0, 0,
								ww_, wh_,
								0 );
		
		DrawCursor( mouse.x, mouse.y );
		al_flip_display();
		
		mouse_lastFrame = mouse;
		keyb_lastFrame = keyb_currentFrame;
	}
	
	vertex[ActivatedVertex][3] = float(mouse.x+mx)/float(texwidth);
	vertex[ActivatedVertex][4] = float(texheight-(mouse.y+my))/float(texheight);
}


