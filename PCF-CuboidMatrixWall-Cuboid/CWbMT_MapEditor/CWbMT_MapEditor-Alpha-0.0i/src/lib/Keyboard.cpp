


// keyboard

inline bool isKeyDown( int keyID )
{
    if( al_key_down(&keyb_currentFrame, keyID) )
        return true;
    return false;
}

inline bool wasKeyDown( int keyID )
{
    if( al_key_down(&keyb_lastFrame, keyID) )
        return true;
    return false;
}

inline bool isKeyPressed( int keyID )
{
    if( al_key_down(&keyb_lastFrame, keyID) == 0 && al_key_down(&keyb_currentFrame, keyID) )
        return true;
    return false;
}

inline bool isKeyReleased( int keyID )
{
    if( al_key_down(&keyb_lastFrame, keyID) && al_key_down(&keyb_currentFrame, keyID) == 0 )
        return true;
    return false;
}

inline bool isKeyStillDown( int keyID )
{
    if( al_key_down(&keyb_lastFrame, keyID) && al_key_down(&keyb_currentFrame, keyID) )
        return true;
    return false;
}

inline bool isKeyStillUp( int keyID )
{
    if( al_key_down(&keyb_lastFrame, keyID) == 0 && al_key_down(&keyb_currentFrame, keyID) == 0 )
        return true;
    return false;
}

// mouse:

inline bool isLMBDown()
{
    if( al_mouse_button_down(&mouse, 1) )
        return true;
    return false;
}

inline bool wasLMBDown()
{
    if( al_mouse_button_down(&mouse_lastFrame, 1) )
        return true;
    return false;
}

inline bool isLMBPressed()
{
    if( al_mouse_button_down(&mouse_lastFrame, 1) == 0 && al_mouse_button_down(&mouse, 1) )
        return true;
    return false;
}

inline bool isLMBReleased()
{
    if( al_mouse_button_down(&mouse_lastFrame, 1) && al_mouse_button_down(&mouse, 1) == 0 )
        return true;
    return false;
}

inline bool isLMBStillDown()
{
    if( al_mouse_button_down(&mouse_lastFrame, 1) && al_mouse_button_down(&mouse, 1) )
        return true;
    return false;
}

inline bool isLMBStillUp()
{
    if( al_mouse_button_down(&mouse_lastFrame, 1) == 0 && al_mouse_button_down(&mouse, 1) == 0 )
        return true;
    return false;
}



inline bool isRMBDown()
{
    if( al_mouse_button_down(&mouse, 2) )
        return true;
    return false;
}

inline bool wasRMBDown()
{
    if( al_mouse_button_down(&mouse_lastFrame, 2) )
        return true;
    return false;
}

inline bool isRMBPressed()
{
    if( al_mouse_button_down(&mouse_lastFrame, 2) == 0 && al_mouse_button_down(&mouse, 2) )
        return true;
    return false;
}

inline bool isRMBReleased()
{
    if( al_mouse_button_down(&mouse_lastFrame, 2) && al_mouse_button_down(&mouse, 2) == 0 )
        return true;
    return false;
}

inline bool isRMBStillDown()
{
    if( al_mouse_button_down(&mouse_lastFrame, 2) && al_mouse_button_down(&mouse, 2) )
        return true;
    return false;
}

inline bool isRMBStillUp()
{
    if( al_mouse_button_down(&mouse_lastFrame, 2) == 0 && al_mouse_button_down(&mouse, 2) == 0 )
        return true;
    return false;
}



inline bool isMMBDown()
{
    if( al_mouse_button_down(&mouse, 3) )
        return true;
    return false;
}

inline bool wasMMBDown()
{
    if( al_mouse_button_down(&mouse_lastFrame, 3) )
        return true;
    return false;
}

inline bool isMMBPressed()
{
    if( al_mouse_button_down(&mouse_lastFrame, 3) == 0 && al_mouse_button_down(&mouse, 3) )
        return true;
    return false;
}

inline bool isMMBReleased()
{
    if( al_mouse_button_down(&mouse_lastFrame, 3) && al_mouse_button_down(&mouse, 3) == 0 )
        return true;
    return false;
}

inline bool isMMBStillDown()
{
    if( al_mouse_button_down(&mouse_lastFrame, 3) && al_mouse_button_down(&mouse, 3) )
        return true;
    return false;
}

inline bool isMMBStillUp()
{
    if( al_mouse_button_down(&mouse_lastFrame, 3) == 0 && al_mouse_button_down(&mouse, 3) == 0 )
        return true;
    return false;
}



inline int GetWheelMove()
{
	return mouse.z - mouse_lastFrame.z;
}


