


int main( int argc, char ** argv )
{
	
    __Init();
    
    float time1 = 0.0f, time2 = 0.0f, frametime = 0.0f;
    
    background = al_load_bitmap( "Data\\Textures\\BackGround.png" );
    
    vertex.push_back( SetVector( 12.0f, 2.0f, 2.0f ) );
    vertex.push_back( SetVector( 2.0f, 12.0f, 2.0f ) );
    vertex.push_back( SetVector( 2.0f, 2.0f, 12.0f ) );
    indices.push_back( 0 );
    indices.push_back( 1 );
    indices.push_back( 2 );
    
    
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
        
        
        
        
        
        
        
        
        
        UpdateIteration( frametime );
        
        
        
        
        
        Renderer();
        
        
        
        
        
        mouse_lastFrame = mouse;
        keyb_lastFrame = keyb_currentFrame;
        
        time2 = al_get_time();
    }
    __DeInit();
    return 0;
}


