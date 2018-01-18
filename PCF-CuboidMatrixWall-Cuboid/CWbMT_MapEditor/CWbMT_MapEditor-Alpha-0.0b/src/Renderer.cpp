


void Renderer()
{
    al_set_target_bitmap( al_get_backbuffer( display ) );
    al_clear_to_color( al_map_rgb( 32, 32, 32 ) );
    
//    map.Draw();
    /*
    char possition[2][64];
    
    sprintf( possition[0], "X pos: %f", 666 );
    sprintf( possition[1], "Y pos: %f", 666 );
    
    DrawString( 2, 8, 20, 100, possition[0] );
    DrawString( 2, 8, 20, 116, possition[1] );
    */
    //DrawGUI();
    
    
    window[0].Draw();
    window[1].Draw();
    window[2].Draw();
    
    DrawCursor( mouse.x, mouse.y );
    al_flip_display();
}
