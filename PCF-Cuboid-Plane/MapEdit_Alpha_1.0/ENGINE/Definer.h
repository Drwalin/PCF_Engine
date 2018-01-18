

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


//Machine modules:
    #define ENGINE_FULLSCREEN           &FULLSCREEN_IS
    #define ENGINE_DRAWCAMERAOBJECT     &DRAWCAMERAOBJECT
    #define ENGINE_PHISIC               &PHISICCALCULATE
    #define ENGINE_DRAWNORMAL           &DRAWNORMAL
    #define ENGINE_FIRSTPEARSON         &FIRSTPEARSON




//trigger size:
    //unsigned int XTRIGGER = 1024;
    //unsigned int ZTRIGGER = 1024;
    
    #define XTRIGGER 512
    #define ZTRIGGER 512
    float XSIZETRIGGER = 4000.0001f;
    float ZSIZETRIGGER = 4000.0001f;

    #define XTRIGGEROBJ 25
    #define ZTRIGGEROBJ 25
    float XSIZETRIGGEROBJ = 82.0f;
    float ZSIZETRIGGEROBJ = 82.0f;

    #define ADDRADIANLINECHECK 10.0f






//math consts:
    #define const_PI 3.14159




