



void DrawCursor( int x, int y )
{
    al_draw_line( x-17, y,   x+17, y,   al_map_rgb( 16, 16,  255 ), 1 );
    al_draw_line( x,   y-17, x,   y+17, al_map_rgb( 16, 16,  255 ), 1 );
    
    al_draw_line( x+18, y,   x+4, y,   al_map_rgba( 0,  255, 0, 127 ), 3 );
    al_draw_line( x,   y+18, x,   y+4, al_map_rgba( 0,  255, 0, 127 ), 3 );
    al_draw_line( x-18, y,   x-5, y,   al_map_rgba( 0,  255, 0, 127 ), 3 );
    al_draw_line( x,   y-18, x,   y-5, al_map_rgba( 0,  255, 0, 127 ), 3 );
    
    al_draw_line( x-17, y,   x-6, y,   al_map_rgb( 255, 16,  16 ), 1 );
    al_draw_line( x,   y-17, x,   y-6, al_map_rgb( 255, 16,  16 ), 1 );
    al_draw_line( x+17, y,   x+5, y,   al_map_rgb( 255, 16,  16 ), 1 );
    al_draw_line( x,   y+17, x,   y+5, al_map_rgb( 255, 16,  16 ), 1 );
    
    al_draw_rectangle( x-1, y-1, x+1, y+1, al_map_rgb( 192, 32, 32 ), 1 );
    
//    al_draw_filled_rectangle( 3, 3, width-3, height-3, al_map_rgb( 32, 32, 32 ) );
    
}
