


void WallCollision( float * x, float * y, float * bx, float * by, float * width, float * height )
{
    float _x,_y;
    
    float xs,ys;
    
    if( *width > 1.0f )
        xs = 1.0f;
    else
        xs = *width;
    if( *height > 1.0f )
        ys = 1.0f;
    else
        ys = *height;
    
    //ys = 1.0f;
    //xs = 1.0f;
    
    //+1.0f-float(int(*width )%1)
    //+1.0f-float(int(*height)%1)
    
    /*
    for( _x = int(*x);  _x <= (float)(*x  + *width ) && _x >= 0.0f && _x < float(XMAPSIZE); _x += xs ){
    for( _y = int(*by); _y <= (float)(*by + *height) && _y >= 0.0f && _y < float(YMAPSIZE); _y += ys ){
        if( map.blocks[int(_x)][int(_y)] > 0 )
            *x = *bx;
    }}
    for( _x = int(*x);  _x <= (float)(*x  + *width ) && _x >= 0.0f && _x < float(XMAPSIZE); _x += xs ){
    for( _y = int(*y);  _y <= (float)(*y  + *height) && _y >= 0.0f && _y < float(YMAPSIZE); _y += ys ){
        if( map.blocks[int(_x)][int(_y)] > 0 )
            *y = *by;
    }}*/
    
    
    
    if( map.blocks[int(*x       )][int(*by        )] > 0 )
            *x = *bx;
    if( map.blocks[int(*x+*width)][int(*by+*height)] > 0 )
            *x = *bx;
    if( map.blocks[int(*x+*width)][int(*by        )] > 0 )
            *x = *bx;
    if( map.blocks[int(*x       )][int(*by+*height)] > 0 )
            *x = *bx;
    
    
    if( map.blocks[int(*x       )][int(*y        )] > 0 )
            *y = *by;
    if( map.blocks[int(*x+*width)][int(*y+*height)] > 0 )
            *y = *by;
    if( map.blocks[int(*x+*width)][int(*y        )] > 0 )
            *y = *by;
    if( map.blocks[int(*x       )][int(*y+*height)] > 0 )
            *y = *by;
    
    
}
