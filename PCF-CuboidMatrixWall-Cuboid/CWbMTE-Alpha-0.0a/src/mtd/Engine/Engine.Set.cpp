
inline void Engine::Set( int arg, ... )
{
    va_list arglist;
    va_start( arglist, arg );
    switch( arg )
    {
        // I have to change from args Get to args Set
    // Window:
    case CMT_WINDOW_NAME:
        char * name;
        name = va_arg( arglist, (char*) );
        name = WindowName;
        va_end( arglist );
        return; // break;
        break;
    
    case CMT_WINDOW_POS:
        int * pos[2];
        pos[0] = va_arg( arglist, (int*) );
        pos[1] = va_arg( arglist, (int*) );
        *pos[0] = WindowPossition[0];
        *pos[1] = WindowPossition[1];
        va_end( arglist );
        return; // break;
        break;
    
    case CMT_WINDOW_SIZE:
        int * size[2];
        size[0] = va_arg( arglist, (int*) );
        size[1] = va_arg( arglist, (int*) );
        *size[0] = WindowSize[0];
        *size[1] = WindowSize[1];
        va_end( arglist );
        return; // break;
        break;
    
    case CMT_FULL_SCREEN:
        bool fullscreen;
        fullscreen = va_arg( arglist, (bool*) );
        *fullscreen = WindowFullScreen;
        va_end( arglist );
        return; // break;
        break;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    case CMT_OBJECT:
        map[ ActuallyMapUsing ].object.resize( map[ ActuallyMapUsing ].object.size()+1 );
        map[ ActuallyMapUsing ].object[ map[ ActuallyMapUsing ].object.size()-1 ].pos[0] = va_arg( arglist, float );
        map[ ActuallyMapUsing ].object[ map[ ActuallyMapUsing ].object.size()-1 ].pos[1] = va_arg( arglist, float );
        map[ ActuallyMapUsing ].object[ map[ ActuallyMapUsing ].object.size()-1 ].pos[2] = va_arg( arglist, float );
        map[ ActuallyMapUsing ].object[ map[ ActuallyMapUsing ].object.size()-1 ].size[0] = va_arg( arglist, float );
        map[ ActuallyMapUsing ].object[ map[ ActuallyMapUsing ].object.size()-1 ].size[1] = va_arg( arglist, float );
        map[ ActuallyMapUsing ].object[ map[ ActuallyMapUsing ].object.size()-1 ].size[2] = va_arg( arglist, float );
        map[ ActuallyMapUsing ].object[ map[ ActuallyMapUsing ].object.size()-1 ].mass = va_arg( arglist, float );
        map[ ActuallyMapUsing ].object[ map[ ActuallyMapUsing ].object.size()-1 ].model_id = va_arg( arglist, int );
        map[ ActuallyMapUsing ].object[ map[ ActuallyMapUsing ].object.size()-1 ].collision_calculate = va_arg( arglist, bool );
        map[ ActuallyMapUsing ].object[ map[ ActuallyMapUsing ].object.size()-1 ].gravity_work = va_arg( arglist, bool );
        int * id_object = va_arg( arglist, *int );
        if( id_object != NULL )
            *id_object = map[ ActuallyMapUsing ].wall.size()-1;
        va_end( arglist );
        return; // break;
        
    case CMT_OBJECT_POS:
        int id_object = va_arg( arglist, int );
        map[ ActuallyMapUsing ].object[ id_object ].pos[0] += va_arg( arglist, float );
        map[ ActuallyMapUsing ].object[ id_object ].pos[1] += va_arg( arglist, float );
        map[ ActuallyMapUsing ].object[ id_object ].pos[2] += va_arg( arglist, float );
        va_end( arglist );
        return; // break;
        
    case CMT_OBJECT_SPEED:
        int id_object = va_arg( arglist, int );
        map[ ActuallyMapUsing ].object[ id_object ].speed[0] += va_arg( arglist, float );
        map[ ActuallyMapUsing ].object[ id_object ].speed[1] += va_arg( arglist, float );
        map[ ActuallyMapUsing ].object[ id_object ].speed[2] += va_arg( arglist, float );
        va_end( arglist );
        return; // break;
        
        
        
            
        
    // Map:
    case CMT_MAP_NEW:
        map.resize( map.size()+1 );
        id_model = va_arg( arglist, *int );
        if( id_model != NULL )
            *id_model = map.size()-1;
        va_end( arglist );
        return;
        
        
        
        
    default:
        va_end( arglist );
        AskingPause = true;
        Sleep( 1000 );
        ALLEGRO_DISPLAY * allegro_display_fast = NULL;
        char error_bad_action[256];
        sprintf( error_bad_action, "\nIn method Engine::Add is no action for: %i", arg );
        cout << error_bad_action;
        al_show_native_message_box( allegro_display_fast, "Error", error_bad_action, NULL, ALLEGRO_MESSAGEBOX_ERROR );
        getch();
        al_destroy_display( allegro_display_fast );
        exit( 0 );
    }
}


