


void Renderer()
{
    al_set_target_bitmap( al_get_backbuffer( display ) );
    al_clear_to_color( al_map_rgb( 32, 32, 32 ) );
    
    
    char possition[10][64];
    
    sprintf( possition[0], "Vertex: %i", vertex.size() );
    sprintf( possition[1], "Buttons: %i", button.size() );
	if( ActivatedWindow >= 0 && ActivatedWindow <= 2 )
	{
	    sprintf( possition[2], "Window %i scale: %f", ActivatedWindow, window[ActivatedWindow].scale );
	    DrawString( 2, 8, 20, 132, possition[2] );
	}
    
    DrawString( 2, 8, 20, 100, possition[0] );
    DrawString( 2, 8, 20, 116, possition[1] );
    
    
    
    window[0].Draw();
    window[1].Draw();
    window[2].Draw();
    
    al_set_target_bitmap( al_get_backbuffer( display ) );
    
    al_draw_scaled_bitmap( window[0].texture, 0, 0, al_get_bitmap_width(window[0].texture), al_get_bitmap_height(window[0].texture), window[0].x, window[0].y, window[0].wx, window[0].wy, 0 );
    al_draw_scaled_bitmap( window[1].texture, 0, 0, al_get_bitmap_width(window[1].texture), al_get_bitmap_height(window[1].texture), window[1].x, window[1].y, window[1].wx, window[1].wy, 0 );
    al_draw_scaled_bitmap( window[2].texture, 0, 0, al_get_bitmap_width(window[2].texture), al_get_bitmap_height(window[2].texture), window[2].x, window[2].y, window[2].wx, window[2].wy, 0 );
    
    int i;
    
    for( i = 0; i < button.size(); i++ )
    {
		al_draw_rectangle( button[i].x, button[i].y, button[i].x+button[i].wx, button[i].y+button[i].wy, al_map_rgb( 192, 32, 32 ), 4 );
//		button[i].Draw();
	}
    
    DrawCursor( mouse.x, mouse.y );
    al_flip_display();
}
