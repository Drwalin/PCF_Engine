


void Renderer()
{
    al_set_target_bitmap( al_get_backbuffer( display ) );
    al_clear_to_color( al_map_rgb( 32, 32, 32 ) );
    
    
    char possition[10][256];
    
	if( ActivatedWindow >= 0 && ActivatedWindow < window.size() )
	{
	    sprintf( possition[2], "Window %i scale: %f", ActivatedWindow, window[ActivatedWindow].scale );
	    DrawString( 2, 8, 844, 132, possition[2] );
	}
    sprintf( possition[0], "Vertex: %i", vertex.size() );
    sprintf( possition[1], "Buttons: %i", button.size() );
    sprintf( possition[2], "Pos: %f, %f, %f", window[3].win->pos[0], window[3].win->pos[1], window[3].win->pos[2] );
    sprintf( possition[3], "Rotate: %f, %f", window[3].win->lookx, window[3].win->looky );
    
    DrawString( 2, 8, 844, 100, possition[0] );
    DrawString( 2, 8, 844, 116, possition[1] );
    DrawString( 2, 8, 4, 200, possition[2] );
    
    
    
    window[0].Draw();
    window[1].Draw();
    window[2].Draw();
    window[3].Draw();
    
    al_set_target_bitmap( al_get_backbuffer( display ) );
    
    al_draw_scaled_bitmap( window[0].texture, 0, 0, al_get_bitmap_width(window[0].texture), al_get_bitmap_height(window[0].texture), window[0].x, window[0].y, window[0].wx, window[0].wy, 0 );
    al_draw_scaled_bitmap( window[1].texture, 0, 0, al_get_bitmap_width(window[1].texture), al_get_bitmap_height(window[1].texture), window[1].x, window[1].y, window[1].wx, window[1].wy, 0 );
    al_draw_scaled_bitmap( window[2].texture, 0, 0, al_get_bitmap_width(window[2].texture), al_get_bitmap_height(window[2].texture), window[2].x, window[2].y, window[2].wx, window[2].wy, 0 );
    al_draw_scaled_bitmap( window[3].texture, 0, 0, al_get_bitmap_width(window[3].texture), al_get_bitmap_height(window[3].texture), window[3].x, window[3].y, window[3].wx, window[3].wy, 0 );
    
    int i;
    
    for( i = 0; i < button.size(); i++ )
    {
		button[i].Draw();
	}
    
    
    DrawString( 2, 8, 4, 400, possition[2] );
    DrawString( 2, 8, 4, 418, possition[3] );
    
    DrawCursor( mouse.x, mouse.y );
    al_flip_display();
}
