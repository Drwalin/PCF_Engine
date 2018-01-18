


void __Init()
{
    al_init();
    
    display = al_create_display( 1920-(3+3), 1080-(27+22+3) );
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
    
    
    window.resize( 4 );
    
    window[0].wx = (windowx-400)/2;
    window[0].wy = (windowy)/2;
    window[0].x = 200;
    window[0].y = (windowy)/2;
    window[0].drawaxis = 1;
    window[2].wx = (windowx-400)/2;
    window[2].wy = (windowy)/2;
    window[2].x = ((windowx-400)/2) + 200;
    window[2].y = (windowy)/2;
    window[2].drawaxis = 3;
    window[1].wx = (windowx-400)/2;
    window[1].wy = (windowy)/2;
    window[1].x = ((windowx-400)/2) + 200;
    window[1].y = 0;
    window[1].drawaxis = 2;
    
    window[3].wx = (windowx-400)/2;
    window[3].wy = (windowy)/2;
    window[3].x = 200;
    window[3].y = 0;
    window[3].win = new Window3D;
    
    
    
}


