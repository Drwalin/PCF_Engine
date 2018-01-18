

#define NUMBEROFALLKEYS 254

class ENGINEKeyboard
{
    public:
        bool backkeypressed[NUMBEROFALLKEYS];
        bool keypressed[NUMBEROFALLKEYS];
        bool downkeypressed[NUMBEROFALLKEYS];
        bool upkeypressed[NUMBEROFALLKEYS];
    
    void Update()
    {
        for( unsigned int keynumber = 0; keynumber < NUMBEROFALLKEYS; keynumber++ )
        {
            keypressed[keynumber] = GetAsyncKeyState(keynumber) & 0x8000;
        }
        
        for( unsigned int keynumber = 0; keynumber < NUMBEROFALLKEYS; keynumber++ )
        {
            if( ( backkeypressed[keynumber] == true && keypressed[keynumber] == true ) || ( backkeypressed[keynumber] == false && keypressed[keynumber] == false ) )
            {
                downkeypressed[keynumber] = false;
                upkeypressed[keynumber] = false;
            }
            else if( backkeypressed[keynumber] == true && keypressed[keynumber] == false )
            {
                downkeypressed[keynumber] = false;
                upkeypressed[keynumber] = true;
            }
            else if( backkeypressed[keynumber] == false && keypressed[keynumber] == true )
            {
                downkeypressed[keynumber] = true;
                upkeypressed[keynumber] = false;
            }
        }
        
        for( unsigned int keynumber = 0; keynumber < NUMBEROFALLKEYS; keynumber++ )
        {
            backkeypressed[keynumber] = keypressed[keynumber];
        }
    }
    
    ENGINEKeyboard()
    {
        for( unsigned int keynumber = 0; keynumber < NUMBEROFALLKEYS; keynumber++ )
        {
            backkeypressed[keynumber] == false;
            downkeypressed[keynumber] = false;
            upkeypressed[keynumber] = false;
            keypressed[keynumber] == false;
        }
    }
};

#undef NUMBEROFALLKEYS


ENGINEKeyboard keyboardobiect;










