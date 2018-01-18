
/*
    Main engine class,
    that engine user
    (game-coder)
    has to know
*/

class Engine
{
private:
    
    char    WindowName      [256];
    int     WindowPossition [2];
    int     WindowSize      [2];
    bool    WindowFullScreen;
    
    float GraphicFPS[3];
    float PhysicFPS[3];
    
    bool GraphicThreadStopped;  // if graphic thread are stopped
    bool PhysicThreadStopped;   // if physic thread are stopped
    bool AskingPause;           // something asking about pause working engine
    bool AskingEnd;             // something asking about stop working engine
    bool OrderContinue;         // one of the threads can order that, to extort continue work
    
    int GraphicMode;            // OpenGL / DirectX      (implicitly OpenGL mode (only yet))
    
    int MEMORYSavingMode;          // Maximum nuber of maps (implicitly maximmum mode)
    int CPUSavingMode;          // Collision precision   (implicitly maximmum mode)
    int GPUSavingMode;          // Graphic library mode  (implicitly maximmum mode)
    
    int CameraObject;
    
    float GraphicTime;
    int BeginGraphicTime;
    
    Map map;

    
    
    FunctionVoidInt KeyboardFunction;
    FunctionVoidInt GUIFunction;
    
    inline         void Renderer();                         // +/-
    inline __cdecl void PhisicLoop();                       // +/-
    inline         void Reshape( int width, int height );   // +
    inline         void FrameFunction( int arg );           // +
    
public:
    
    /*
        http://edu.pjwstk.edu.pl/wyklady/pro/scb/PRG2CPP_files/node68.html
    */

    inline int LineCheckCollision( float * src1, float * src2, int objectbypass, float * collisionpos, int * idobject );    // -
        // Return id object (+1), if( idobject == NULL ) -> no collision
    
    inline void Get( int arg, ... );                // -
        // Get item value
    inline void Set( int arg, ... );                // -
        // Set item value
    inline void Add( int arg, ... );                // ...
        // Add new item
    inline void Del( int arg, ... );                // -
        // Delete/Destroy
    inline void Do ( int arg, ... );                // -
        // Ask about pause/stop/continue work of threads
    
    inline void Init( int * argc, char *argv[] );   //+/-
    inline void BeginLoop();                        // -
    
    Engine();                                       // +
    ~Engine();                                      // +
    
};








