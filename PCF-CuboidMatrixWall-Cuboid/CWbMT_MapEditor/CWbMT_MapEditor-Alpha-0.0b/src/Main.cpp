


int main()
{
	printf( "a" );
	
    __Init();
    float time1 = 0.0f, time2 = 0.0f, frametime = 0.0f;
    
//    background = al_load_bitmap( "Data\\Textures\\BackGround.png" );
    
    ////////////al_show_native_message_box( display, "Blad", "NULL", "Nie moge utworzyc okna!", NULL, ALLEGRO_MESSAGEBOX_ERROR );
    
//    al_destroy_bitmap( background );
//    background = al_load_bitmap( "Data\\Textures\\BackGround.png" );
    
    printf( "ddd" );
    
    while( !isKeyDown( ALLEGRO_KEY_ESCAPE ) )
    {
        frametime = time2 - time1;
        if( frametime < (1.0f/__MAXFPS) )
        {
            al_get_keyboard_state( &keyb_currentFrame );
            time2 = al_get_time();
            continue;
        }
        time1 = al_get_time();
        al_get_keyboard_state( &keyb_currentFrame );
        al_get_mouse_state( &mouse );
        
        if( isKeyPressed( ALLEGRO_KEY_O ) )
            __MAXFPS--;
        if( isKeyPressed( ALLEGRO_KEY_P ) )
            __MAXFPS++;
        
        
        
        
        
        UpdateIteration( frametime );
        
        
        
        
        
        Renderer();
        
        
        
        
        
        keyb_lastFrame = keyb_currentFrame;
        if( __MAXFPS < 1.0f )
            __MAXFPS = 1.0f;
        time2 = al_get_time();
    }
    __DeInit();
    return 0;
}


