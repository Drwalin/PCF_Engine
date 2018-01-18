


void Player::Update( float time )
{
    bx = x;
    by = y;
    
    if( isKeyDown( ALLEGRO_KEY_W ) )
    {
        player.y -= 4.0f*time;
    }
    if( isKeyDown( ALLEGRO_KEY_A ) )
    {
        player.x -= 4.0f*time;
    }
    if( isKeyDown( ALLEGRO_KEY_S ) )
    {
        player.y += 4.0f*time;
    }
    if( isKeyDown( ALLEGRO_KEY_D ) )
    {
        player.x += 4.0f*time;
    }
    
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


