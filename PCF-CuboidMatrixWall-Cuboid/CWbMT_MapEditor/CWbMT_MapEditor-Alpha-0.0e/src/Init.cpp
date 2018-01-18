


void __Init()
{
    al_init();
    
    display = al_create_display( 1024, 768 );
    al_set_window_title( display, "???dziala???" );
    
    al_install_keyboard();
    al_install_mouse();
    al_init_font_addon();
    al_init_primitives_addon();
    al_init_image_addon();  // odczyt/zapis w formatach BMP, PNG, JPG, PCX, TGA.
    
    windowx = al_get_bitmap_width(  al_get_backbuffer( display ) );
    windowy = al_get_bitmap_height( al_get_backbuffer( display ) );
    
    desktop = al_create_bitmap( windowx, windowy ); 
    
    InitFonts();
    
    al_hide_mouse_cursor( display );
    
    
    window[0].x = 200;
    window[0].y = 384;
    window[0].drawaxis = 1;
    window[2].x = 512;
    window[2].y = 384;
    window[2].drawaxis = 3;
    window[1].x = 512;
    window[1].y = 0;
    window[1].drawaxis = 2;
    
    
    
    
    
}


