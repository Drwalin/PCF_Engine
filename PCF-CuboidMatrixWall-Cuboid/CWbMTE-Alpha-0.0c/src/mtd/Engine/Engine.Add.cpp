
inline void Engine::Add( int arg, ... )
{
    va_list arglist;
    va_start( arglist, arg );
    switch( arg )
    {
    // Objects:
    case CMT_OBJECT:
        map.object.resize( map.object.size()+1 );
        map.object[ map.object.size()-1 ].pos[0] = va_arg( arglist, float );
        map.object[ map.object.size()-1 ].pos[1] = va_arg( arglist, float );
        map.object[ map.object.size()-1 ].pos[2] = va_arg( arglist, float );
        map.object[ map.object.size()-1 ].size[0] = va_arg( arglist, float );
        map.object[ map.object.size()-1 ].size[1] = va_arg( arglist, float );
        map.object[ map.object.size()-1 ].size[2] = va_arg( arglist, float );
        map.object[ map.object.size()-1 ].mass = va_arg( arglist, float );
        map.object[ map.object.size()-1 ].model_id = va_arg( arglist, int );
        map.object[ map.object.size()-1 ].CollisionUse = va_arg( arglist, bool );
        map.object[ map.object.size()-1 ].GravityUse = va_arg( arglist, bool );
        int * id_object = va_arg( arglist, *int );
        if( id_object != NULL )
            *id_object = map.wall.size()-1;
        va_end( arglist );
        return; // break;
    
    case CMT_OBJECT_POS:
        int id_object = va_arg( arglist, int );
        map.object[ id_object ].pos[0] += va_arg( arglist, float );
        map.object[ id_object ].pos[1] += va_arg( arglist, float );
        map.object[ id_object ].pos[2] += va_arg( arglist, float );
        va_end( arglist );
        return; // break;
    
    case CMT_OBJECT_SPEED:
        int id_object = va_arg( arglist, int );
        map.object[ id_object ].speed[0] += va_arg( arglist, float );
        map.object[ id_object ].speed[1] += va_arg( arglist, float );
        map.object[ id_object ].speed[2] += va_arg( arglist, float );
        va_end( arglist );
        return; // break;
    
    case CMT_OBJECT_FORCE:
        int id_object = va_arg( arglist, int );
        map.object[ id_object ].force[0] += va_arg( arglist, float );
        map.object[ id_object ].force[1] += va_arg( arglist, float );
        map.object[ id_object ].force[2] += va_arg( arglist, float );
        va_end( arglist );
        return; // break;
    
    case CMT_OBJECT_SIZE:
        int id_object = va_arg( arglist, int );
        map.object[ id_object ].size[0] += va_arg( arglist, float );
        map.object[ id_object ].size[1] += va_arg( arglist, float );
        map.object[ id_object ].size[2] += va_arg( arglist, float );
        va_end( arglist );
        return; // break;
    
    case CMT_OBJECT_LOOK:
        int id_object = va_arg( arglist, int );
        map.object[ id_object ].lookxz += va_arg( arglist, float );
        map.object[ id_object ].looky += va_arg( arglist, float );
        va_end( arglist );
        return; // break;
    
    
    
    case CMT_OBJECT_V:
        map.object.resize( map.object.size()+1 );
        float * pos_object;
        float * size_object;
        pos_object = va_arg( arglist, *float );
        size_object = va_arg( arglist, *float );
        map.object[ map.object.size()-1 ].pos[0] = pos_object[0];
        map.object[ map.object.size()-1 ].pos[1] = pos_object[1];
        map.object[ map.object.size()-1 ].pos[2] = pos_object[2];
        map.object[ map.object.size()-1 ].size[0] = size_object[0];
        map.object[ map.object.size()-1 ].size[1] = size_object[1];
        map.object[ map.object.size()-1 ].size[2] = size_object[2];
        map.object[ map.object.size()-1 ].mass = va_arg( arglist, float );
        map.object[ map.object.size()-1 ].model_id = va_arg( arglist, int );
        map.object[ map.object.size()-1 ].CollisionUse = va_arg( arglist, bool );
        map.object[ map.object.size()-1 ].GravityUse = va_arg( arglist, bool );
        int * id_object = va_arg( arglist, *int );
        if( id_object != NULL )
            *id_object = map.object.size()-1;
        va_end( arglist );
        return;
    
    case CMT_OBJECT_POS_V:
        int id_object = va_arg( arglist, int );
        float * pos_object;
        pos_object = va_arg( arglist, *float );
        map.object[ id_object ].pos[0] += pos_object[0];
        map.object[ id_object ].pos[1] += pos_object[1];
        map.object[ id_object ].pos[2] += pos_object[2];
        va_end( arglist );
        return;
    
    case CMT_OBJECT_SPEED_V:
        int id_object = va_arg( arglist, int );
        float * speed_object;
        speed_object = va_arg( arglist, *float );
        map.object[ id_object ].speed[0] += speed_object[0];
        map.object[ id_object ].speed[1] += speed_object[1];
        map.object[ id_object ].speed[2] += speed_object[2];
        va_end( arglist );
        return;
    
    case CMT_OBJECT_FORCE_V:
        int id_object = va_arg( arglist, int );
        float * force_object;
        force_object = va_arg( arglist, *float );
        map.object[ id_object ].force[0] += force_object[0];
        map.object[ id_object ].force[1] += force_object[1];
        map.object[ id_object ].force[2] += force_object[2];
        va_end( arglist );
        return;
    
    case CMT_OBJECT_SIZE_V:
        int id_object = va_arg( arglist, int );
        float * size_object;
        size_object = va_arg( arglist, *float );
        map.object[ id_object ].size[0] += size_object[0];
        map.object[ id_object ].size[1] += size_object[1];
        map.object[ id_object ].size[2] += size_object[2];
        va_end( arglist );
        return;
    
    case CMT_OBJECT_LOOK_V:
        int id_object = va_arg( arglist, int );
        float * look_object;
        look_object = va_arg( arglist, *float );
        map.object[ id_object ].lookxz += look_object[0];
        map.object[ id_object ].looky += look_object[1];
        va_end( arglist );
        return;
    
    
    
    // Textures:
    case CMT_TEXTURE:
        map.textures.resize( map.texture.size()+1 );
        sprintf( map.textures[ map.textures.size()-1 ].name, "%s", va_arg( arglist, *char ) );
        int * id_texture = va_arg( arglist, *int );
        if( id_texture != NULL )
            *id_texture = map.textures.size()-1;
        va_end( arglist );
        return;
    
    
    
    // Models:
    case CMT_MODEL_HUMANOID:
        map.models.resize( map.models.size()+1 );
        sprintf( map.models[ map.models.size()-1 ].name, "%s", va_arg( arglist, *char ) );
        sprintf( map.models[ map.models.size()-1 ].type = CMT_MODEL_HUMANOID;
        int * id_model = va_arg( arglist, *int );
        if( id_model != NULL )
            *id_model = map.models.size()-1;
        va_end( arglist );
        return;
    
    case CMT_MODEL_STATIC:
        map.models.resize( map.models.size()+1 );
        sprintf( map.models[ map.models.size()-1 ].name, "%s", va_arg( arglist, *char ) );
        sprintf( map.models[ map.models.size()-1 ].type = CMT_MODEL_STATIC;
        int * id_model = va_arg( arglist, *int );
        if( id_model != NULL )
            *id_model = map.models.size()-1;
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


