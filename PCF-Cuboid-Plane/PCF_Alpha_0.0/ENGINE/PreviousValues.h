float timefps[3];




//window, phisics, graphic:
    unsigned int X_window = 800;
    unsigned int Y_window = 450;
    unsigned int X_position = 200;
    unsigned int Y_position = 200;
    
    NameLine128 windowname;
    bool FULLSCREEN_IS=false;
    bool DRAWCAMERAOBJECT=false;
    bool PHISICCALCULATE=false;
    bool DRAWNORMAL=false;
    bool FIRSTPEARSON=false;
    bool DRAWOBIECTVEREXSPEED=false;
    bool DRAWOBIECTVEREXFORCE=false;



//wskazniki na funkcje:
    typedef void ( * VoidIntFunction )( unsigned int );
    typedef void ( * VoidVoidFunction )();
    VoidIntFunction ChangeForcesFunction = EmptyFunctionVoidInt;
    VoidVoidFunction GameRendererFunction = EmptyFunctionVoidVoid;



//mapa, gra:
    int full_game_and_map_loaded_to_memory=0;

