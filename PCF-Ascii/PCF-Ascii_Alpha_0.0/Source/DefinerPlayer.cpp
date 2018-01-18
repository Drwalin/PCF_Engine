



void Player::Update( float time )
{
    bx = x;
    by = y;
    
    if( isKeyDown( ALLEGRO_KEY_UP ) )
    {
        angley+=180.0f*time;
    }
    if( isKeyDown( ALLEGRO_KEY_LEFT ) )
    {
        anglexz+=180.0f*time;
    }
    if( isKeyDown( ALLEGRO_KEY_DOWN ) )
    {
        angley-=180.0f*time;
    }
    if( isKeyDown( ALLEGRO_KEY_RIGHT ) )
    {
        anglexz-=180.0f*time;
    }
    
    if( isKeyDown( ALLEGRO_KEY_W ) )
    {
        move[0] += Xpoint( anglexz ) * 8.0f * time;
        move[2] += Zpoint( anglexz ) * 8.0f * time;
    }
    if( isKeyDown( ALLEGRO_KEY_A ) )
    {
        move[0] += Xpoint( anglexz+90.0f ) * 8.0f * time;
        move[2] += Zpoint( anglexz+90.0f ) * 8.0f * time;
    }
    if( isKeyDown( ALLEGRO_KEY_S ) )
    {
        move[0] += Xpoint( anglexz+180.0f ) * 8.0f * time;
        move[2] += Zpoint( anglexz+180.0f ) * 8.0f * time;
    }
    if( isKeyDown( ALLEGRO_KEY_D ) )
    {
        move[0] += Xpoint( anglexz+270.0f ) * 8.0f * time;
        move[2] += Zpoint( anglexz+270.0f ) * 8.0f * time;
    }
    if( isKeyDown( ALLEGRO_KEY_SPACE ) )
    {
        move[1] += 8.0f * time;
    }
    if( isKeyDown( ALLEGRO_KEY_LCTRL ) )
    {
        move[1] -= 8.0f * time;
    }
    
        if( anglexz > 269.0f )
            anglexz = -89.0f;
        if( anglexz < -89.0f )
            anglexz = 269.0f;
    
        if( angley < -89.0f )
            angley = -89.0f;
        if( angley >  90.0f )
            angley =  90.0f;
            
    if( x > float(XMAPSIZE+1)-width )
        x = float(XMAPSIZE+1)-width;
    else if( x < 0 )
        x = 0;
    if( y > float(YMAPSIZE+1)-height )
        y = float(YMAPSIZE+1)-height;
    else if( y < 0 )
        y = 0;
        
    if( bx > float(YMAPSIZE+1)-width )
        bx = float(YMAPSIZE+1)-width;
    else if( bx < 0 )
        bx = 0;
    if( by > float(XMAPSIZE+1)-height )
        by = float(XMAPSIZE+1)-height;
    else if( by < 0 )
        by = 0;
    
    
    WallCollision( &x, &y, &bx, &by, &width, &height );
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    al_set_target_bitmap( al_get_backbuffer( display ) );
    
    pixelmovex = int( float(x + (width /2.0f))*float(TEXTURESSIZE) - (windowx/2) );//(float(al_get_bitmap_width(  al_get_backbuffer( display ) )/2.0f)));
    pixelmovey = int( float(y + (height/2.0f))*float(TEXTURESSIZE) - (windowy/2) );//(float(al_get_bitmap_height( al_get_backbuffer( display ) )/2.0f)));
    
    if( pixelmovex < 0 )
        pixelmovex = 0;
    else if( pixelmovex >= (XMAPSIZE*TEXTURESSIZE) - windowx )//al_get_bitmap_width(  al_get_backbuffer( display ) ) )
             pixelmovex =  (XMAPSIZE*TEXTURESSIZE) - windowx;//al_get_bitmap_width(  al_get_backbuffer( display ) )-1;
    if( pixelmovey < 0 )
        pixelmovey = 0;
    else if( pixelmovey >= (YMAPSIZE*TEXTURESSIZE) - windowy )//al_get_bitmap_height( al_get_backbuffer( display ) ) )
             pixelmovey =  (YMAPSIZE*TEXTURESSIZE) - windowy;//al_get_bitmap_height( al_get_backbuffer( display ) )-1;
    
}









