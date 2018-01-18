


void Renderer()
{
    al_set_target_bitmap( al_get_backbuffer( display ) );
    al_clear_to_color( al_map_rgb( 32, 32, 32 ) );
    
    map.Draw();
    
    char possition[2][64];
    
    sprintf( possition[0], "X pos: %f", player.x );
    sprintf( possition[1], "Y pos: %f", player.y );
    
    DrawString( 2, 8, 20, 100, possition[0] );
    DrawString( 2, 8, 20, 116, possition[1] );
    
    //DrawGUI();
    
    DrawCursor( mouse.x, mouse.y );
    al_flip_display();
}
