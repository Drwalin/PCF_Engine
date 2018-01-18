




void __Init()
{
    al_init();
    
    
    display = al_create_display( 900, 700 );
    al_set_window_title( display, GameName );
    
    al_install_keyboard();
    al_install_mouse();
    al_init_font_addon();
    al_init_primitives_addon();
    al_init_image_addon();  // odczyt/zapis w formatach BMP, PNG, JPG, PCX, TGA.
    Load();
    map.Init();
    
    windowx = al_get_bitmap_width(  al_get_backbuffer( display ) );
    windowy = al_get_bitmap_height( al_get_backbuffer( display ) );
    
    desktop = al_create_bitmap( windowx, windowy ); 
    
    InitFonts();
    
    al_hide_mouse_cursor( display );
}
