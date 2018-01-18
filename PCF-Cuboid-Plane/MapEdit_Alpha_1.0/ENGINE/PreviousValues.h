float timefps[3];

//window:
    unsigned int X_window = 800;
    unsigned int Y_window = 450;
    unsigned int X_position = 0;
    unsigned int Y_position = 0;




//window, phisics, graphic:
    bool FULLSCREEN_IS=false;
    bool DRAWCAMERAOBJECT=false;
    bool PHISICCALCULATE=false;
    bool DRAWNORMAL=false;
    bool FIRSTPEARSON=false;


//wskazniki na funkcje:
    typedef void ( * VoidIntFunction )( unsigned int );
    typedef void ( * VoidVoidFunction )();
    VoidIntFunction ChangeForcesFunction = EmptyFunctionVoidInt;
    VoidVoidFunction GameRendererFunction = EmptyFunctionVoidVoid;
    typedef void ( * WallsVoid )( float*, float, float, float, unsigned int );

//przyciski:
//    bool keys[256];
//    bool specialkeys[256];





