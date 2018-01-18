


// keyboard

bool isKeyDown( int keyID )
{
    if( al_key_down(&keyb_currentFrame, keyID) )
        return true;
    return false;
}

bool wasKeyDown( int keyID )
{
    if( al_key_down(&keyb_lastFrame, keyID) )
        return true;
    return false;
}

bool isKeyPressed( int keyID )
{
    if( al_key_down(&keyb_lastFrame, keyID) == 0 && al_key_down(&keyb_currentFrame, keyID) )
        return true;
    return false;
}

bool isKeyReleased( int keyID )
{
    if( al_key_down(&keyb_lastFrame, keyID) && al_key_down(&keyb_currentFrame, keyID) == 0 )
        return true;
    return false;
}

bool isKeyStillDown( int keyID )
{
    if( al_key_down(&keyb_lastFrame, keyID) && al_key_down(&keyb_currentFrame, keyID) )
        return true;
    return false;
}

bool isKeyStillUp( int keyID )
{
    if( al_key_down(&keyb_lastFrame, keyID) == 0 && al_key_down(&keyb_currentFrame, keyID) == 0 )
        return true;
    return false;
}

// mouse:

bool isLMBDown()
{
    if( al_mouse_button_down(&mouse, 1) )
        return true;
    return false;
}

bool wasLMBDown()
{
    if( al_mouse_button_down(&mouse_lastFrame, 1) )
        return true;
    return false;
}

bool isLMBPressed()
{
    if( al_mouse_button_down(&mouse_lastFrame, 1) == 0 && al_mouse_button_down(&mouse, 1) )
        return true;
    return false;
}

bool isLMBReleased()
{
    if( al_mouse_button_down(&mouse_lastFrame, 1) && al_mouse_button_down(&mouse, 1) == 0 )
        return true;
    return false;
}

bool isLMBStillDown()
{
    if( al_mouse_button_down(&mouse_lastFrame, 1) && al_mouse_button_down(&mouse, 1) )
        return true;
    return false;
}

bool isLMBStillUp()
{
    if( al_mouse_button_down(&mouse_lastFrame, 1) == 0 && al_mouse_button_down(&mouse, 1) == 0 )
        return true;
    return false;
}

