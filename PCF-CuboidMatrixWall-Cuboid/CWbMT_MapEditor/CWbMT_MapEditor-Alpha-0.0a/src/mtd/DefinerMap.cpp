


void Map::Init()
{
    int x=0, y=0, i=0;
    float _x=0.0f,_y=0.0f;
    for( x = 0; x < XMAPSIZE; x++ ){
    for( y = 0; y < YMAPSIZE; y++ ){
        blocks[x][y] = 0;
        npc[x][y] = 0;
    }}
    
    for( i = 0; i < buildings.size(); i++ )
    {
        for( x = buildings[i].x; x < XMAPSIZE && x < (buildings[i].x+buildings[i].width); x++ ){
        for( y = buildings[i].y; y < YMAPSIZE && y < (buildings[i].y+buildings[i].height); y++ ){
            blocks[int(x%XMAPSIZE)][int(y%YMAPSIZE)] = i+1;
        }}
    }
    
    for( i = 0; i < npcs.size(); i++ )
    {
        for( _x = npcs[i].x; _x < XMAPSIZE && _x < (npcs[i].x+npcs[i].width); _x++ ){
        for( _y = npcs[i].y; _y < YMAPSIZE && _x < (npcs[i].y+npcs[i].height); _y++ ){
            npc[(unsigned int)(_x)%XMAPSIZE][(unsigned int)(_y)%YMAPSIZE] = i+2;
        }}
    }
    
    for( _x = player.x; _x < XMAPSIZE && _x < (player.x+player.width); _x++ ){
    for( _y = player.y; _y < YMAPSIZE && _x < (player.y+player.height); _y++ ){
        npc[(unsigned int)(_x)%XMAPSIZE][(unsigned int)(_y)%YMAPSIZE] = 1;
    }}
}







void Map::Draw()
{
    if( pixelmovex < 0 )
        pixelmovex = 0;
    else if( pixelmovex >= (XMAPSIZE*TEXTURESSIZE)-al_get_bitmap_width( al_get_backbuffer( display ) ) )
             pixelmovex =  (XMAPSIZE*TEXTURESSIZE)-al_get_bitmap_width( al_get_backbuffer( display ) )-1;
    if( pixelmovey < 0 )
        pixelmovey = 0;
    else if( pixelmovey >= (YMAPSIZE*TEXTURESSIZE)-al_get_bitmap_height( al_get_backbuffer( display ) ) )
             pixelmovey =  (YMAPSIZE*TEXTURESSIZE)-al_get_bitmap_height( al_get_backbuffer( display ) )-1;
        
    int x=0, y=0, i=0;
    
    int xwin = al_get_bitmap_width( al_get_backbuffer( display ) );
    int ywin = al_get_bitmap_height( al_get_backbuffer( display ) );
    
    
    al_set_target_bitmap( desktop ); 
    al_clear_to_color( al_map_rgb( 0, 0, 0 ) );
    
    /*
    for( x = pixelmovex; x >= 0 && x < (XMAPSIZE*TEXTURESSIZE+TEXTURESSIZE) && x < (pixelmovex+al_get_bitmap_width( desktop )+TEXTURESSIZE); x += TEXTURESSIZE ){
    for( y = pixelmovey; y >= 0 && y < (YMAPSIZE*TEXTURESSIZE+TEXTURESSIZE) && y < (pixelmovey+al_get_bitmap_height( desktop )+TEXTURESSIZE); y += TEXTURESSIZE ){
        if( blocks[x/TEXTURESSIZE][y/TEXTURESSIZE] > 0 )
        {
            al_draw_scaled_bitmap( buildingstextures[buildings[blocks[x/TEXTURESSIZE][y/TEXTURESSIZE]-1].id_texture],
                                    0, 0,
                                    al_get_bitmap_width(  buildingstextures[buildings[blocks[x/TEXTURESSIZE][y/TEXTURESSIZE]-1].id_texture] ),//+((x-pixelmovex)*((x-pixelmovex)<0)),
                                    al_get_bitmap_height( buildingstextures[buildings[blocks[x/TEXTURESSIZE][y/TEXTURESSIZE]-1].id_texture] ),//+((y-pixelmovey)*((y-pixelmovey)<0)),
                                    x-pixelmovex,//-((x-pixelmovex)*((x-pixelmovex)<0)),
                                    y-pixelmovey,//-((y-pixelmovey)*((y-pixelmovey)<0)),
                                    TEXTURESSIZE,//+((x-pixelmovex)*((x-pixelmovex)<0)),
                                    TEXTURESSIZE,//+((y-pixelmovey)*((y-pixelmovey)<0)),
                                    0 );
        }
    }}*/
    
    if( background == NULL )
    {
        al_destroy_bitmap( background );
        background = al_load_bitmap( "Data\\Textures\\BackGround.png" );
        cout<<endl<<"dupa";
    }
    
    for( x = 0; x >= 0 && x <= (xwin+al_get_bitmap_width(  background )); x += al_get_bitmap_width(  background ) ){
    for( y = 0; y >= 0 && y <= (ywin+al_get_bitmap_height( background )); y += al_get_bitmap_height( background ) ){
//        al_draw_bitmap( background,
//                        x-((x+pixelmovex)%al_get_bitmap_width(  background )),
//                        y-((y+pixelmovey)%al_get_bitmap_height( background )),
//                        0 );
    }}
    
    for( x = 0; x >= 0 && x < (XMAPSIZE*TEXTURESSIZE) && x < (al_get_bitmap_width( desktop )+TEXTURESSIZE); x += TEXTURESSIZE ){
    for( y = 0; y >= 0 && y < (YMAPSIZE*TEXTURESSIZE) && y < (al_get_bitmap_height( desktop )+TEXTURESSIZE); y += TEXTURESSIZE ){
        if( blocks[int(x+pixelmovex)/TEXTURESSIZE][int(y+pixelmovey)/TEXTURESSIZE] > 0 )
        {
            al_draw_scaled_bitmap( buildingstextures[buildings[blocks[int(x+pixelmovex)/TEXTURESSIZE][int(y+pixelmovey)/TEXTURESSIZE]-1].id_texture],
                                    0, 0,
                                    al_get_bitmap_width(  buildingstextures[buildings[blocks[(x+pixelmovex)/TEXTURESSIZE][(y+pixelmovey)/TEXTURESSIZE]-1].id_texture] ),//+((x-pixelmovex)*((x-pixelmovex)<0)),
                                    al_get_bitmap_height( buildingstextures[buildings[blocks[(x+pixelmovex)/TEXTURESSIZE][(y+pixelmovey)/TEXTURESSIZE]-1].id_texture] ),//+((y-pixelmovey)*((y-pixelmovey)<0)),
                                    x-((x+pixelmovex)%TEXTURESSIZE),//-((x-pixelmovex)*((x-pixelmovex)<0)),
                                    y-((y+pixelmovey)%TEXTURESSIZE),//-((y-pixelmovey)*((y-pixelmovey)<0)),
                                    TEXTURESSIZE,//+((x-pixelmovex)*((x-pixelmovex)<0)),
                                    TEXTURESSIZE,//+((y-pixelmovey)*((y-pixelmovey)<0)),
                                    0 );
        }
        else if(0)// background != NULL )
        {
            al_draw_scaled_bitmap( background,
                                    0, 0,
                                    256,//al_get_bitmap_width(  background ),//+((x-pixelmovex)*((x-pixelmovex)<0)),
                                    256,//al_get_bitmap_height( background ),//+((y-pixelmovey)*((y-pixelmovey)<0)),
                                    x-((x+pixelmovex)%TEXTURESSIZE),//-((x-pixelmovex)*((x-pixelmovex)<0)),
                                    y-((y+pixelmovey)%TEXTURESSIZE),//-((y-pixelmovey)*((y-pixelmovey)<0)),
                                    TEXTURESSIZE,//+((x-pixelmovex)*((x-pixelmovex)<0)),
                                    TEXTURESSIZE,//+((y-pixelmovey)*((y-pixelmovey)<0)),
                                    0 );
        }
    }}
    
    for( i = 0; i < npcs.size(); i++ )
    {
        if( npcs[i].x*float(TEXTURESSIZE) > float(pixelmovex) ){
        if( (npcs[i].x+npcs[i].width)*float(TEXTURESSIZE)  < float(pixelmovex+xwin) ){
        if( npcs[i].y*float(TEXTURESSIZE) > float(pixelmovey) ){
        if( (npcs[i].y+npcs[i].height)*float(TEXTURESSIZE) < float(pixelmovey+ywin) ){
            
            al_draw_scaled_bitmap( npcstextures[npcs[i].textures],
                                    0, 0,
                                    al_get_bitmap_width(  npcstextures[npcs[i].textures] ),
                                    al_get_bitmap_height( npcstextures[npcs[i].textures] ),
                                    (npcs[i].x*float(TEXTURESSIZE)-pixelmovex),
                                    (npcs[i].y*float(TEXTURESSIZE)-pixelmovey),
                                    float(TEXTURESSIZE)*npcs[i].width,
                                    float(TEXTURESSIZE)*npcs[i].height,
                                    0 );
        }}}}
    }
    
    
    
            al_draw_scaled_bitmap( player.textures[0],
                                    0, 0,
                                    al_get_bitmap_width(  player.textures[0] ),
                                    al_get_bitmap_height( player.textures[0] ),
                                    (player.x*float(TEXTURESSIZE)-pixelmovex),
                                    (player.y*float(TEXTURESSIZE)-pixelmovey),
                                    float(TEXTURESSIZE)*player.width,
                                    float(TEXTURESSIZE)*player.height,
                                    0 );
    
    al_set_target_bitmap( al_get_backbuffer( display ) );
    al_draw_bitmap( desktop, 0, 0, 0 );
}












