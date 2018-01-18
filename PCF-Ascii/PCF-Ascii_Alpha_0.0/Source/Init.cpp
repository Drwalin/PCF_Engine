




void __Init()
{
    InitScriptsFunctions();
    
    al_init();
    
    
    display = al_create_display( 800, 600 ); // ( 900, 700 );
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
    
    desktop = al_create_bitmap( 296, 144 ); 
    
    
    InitFonts();
    
    
    
    
    al_set_target_bitmap( desktop ); 
    al_clear_to_color( al_map_rgba( 0, 0, 0, 0 ) );
    
    DrawString( 0, 8, 0, 2*0, logo01 );
    DrawString( 0, 8, 0, 2*4, logo02 );
    DrawString( 0, 8, 0, 2*8, logo03 );
    DrawString( 0, 8, 0, 2*12, logo04 );
    DrawString( 0, 8, 0, 2*16, logo05 );
    DrawString( 0, 8, 0, 2*20, logo06 );
    DrawString( 0, 8, 0, 2*24, logo07 );
    DrawString( 0, 8, 0, 2*28, logo08 );
    DrawString( 0, 8, 0, 2*32, logo09 );
    DrawString( 0, 8, 0, 2*36, logo10 );
    DrawString( 0, 8, 0, 2*40, logo11 );
    DrawString( 0, 8, 0, 2*44, logo12 );
    DrawString( 0, 8, 0, 2*48, logo13 );
    DrawString( 0, 8, 0, 2*52, logo14 );
    DrawString( 0, 8, 0, 2*56, logo15 );
    DrawString( 0, 8, 0, 2*60, logo16 );
    DrawString( 0, 8, 0, 2*64, logo17 );
    DrawString( 0, 8, 0, 2*68, logo18 );
    
    al_set_target_bitmap( al_get_backbuffer( display ) );
    
    
    
    
    
    al_hide_mouse_cursor( display );
}
