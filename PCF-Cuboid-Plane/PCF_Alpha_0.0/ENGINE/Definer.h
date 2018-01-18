



//Map types:
    //typy argumentów we wczytywaniu mapy
    #define FULL_WORDS_ARGUMENTS_1_0 int('A')
    #define BINARY_ARGUMENTS_1_0 1

//wartoœci mo¿liwe do zwrócenia przez funkcje Load/Init...:
    #define LOADING_FILE_FOULT -69
    #define NORMAL_FILE_LOADED 1
    #define INVALID_ARGUMENT 0
    #define INVALID_VALUE -8
    #define UNKNOWN_ERROR -666
    
    




//trigger size:
    #define NUMBERTRIGGERALIVE 40
    float SIZETRIGGERALIVE = 16.01f;
    #define NUMBERTRIGGERPHYSICAL 40
    float SIZETRIGGERPHYSICAL = 16.01f;
    #define NUMBERTRIGGERTRIANGLE 40
    float SIZETRIGGERTRIANGLE = 16.01f;


    #define ADDRADIANLINECHECK 10.0f





//values type:
    #define FLOATING_VALUES_TYPE float





//math consts:
    #define const_PI 3.14159


//game:
    #define PLAYE_R_ID 1
    #define PLAYER map.object[1]


    
//Machine modules:
    #define ENGINE_FULLSCREEN               &FULLSCREEN_IS
    #define ENGINE_DRAWCAMERAOBJECT         &DRAWCAMERAOBJECT
    #define ENGINE_PHISIC                   &PHISICCALCULATE
    #define ENGINE_DRAWNORMAL               &DRAWNORMAL
    #define ENGINE_FIRSTPEARSON             &FIRSTPEARSON
    #define ENGINE_DRAWOBIECTVEREXFORCE     &DRAWOBIECTVEREXFORCE
    #define ENGINE_DRAWOBIECTVEREXSPEED     &DRAWOBIECTVEREXSPEED






enum{
    // wektory normalne
    NORMALS_SMOOTH, // GLU_SMOOTH
    NORMALS_FLAT, // GLU_FLAT
    NORMALS_NONE, // GLU_NONE
    
    // orientacja
    ORIENTATION_OUTSIDE, // GLU_OUTSIDE
    ORIENTATION_INSIDE, // GLU_INSIDE
    
    // styl
    STYLE_POINT, // GLU_POINT
    STYLE_LINE, // GLU_LINE
    STYLE_FILL, // GLU_FILL
    STYLE_SILHOUETTE // GLU_SILHOUETTE
};
