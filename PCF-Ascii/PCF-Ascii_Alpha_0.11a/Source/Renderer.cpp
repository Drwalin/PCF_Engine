
void gotoxy( int column, int line )
{
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



void Renderer()
{
    al_set_target_bitmap( al_get_backbuffer( display ) );
    al_clear_to_color( al_map_rgba( 32, 32, 32, 0 ) );
    
    float pt[3][3] = { { 0.0f, 0.0f, 10.0f }, { 5.0f, 0.0f, 10.0f }, { 5.0f, -5.0f, 10.0f } };
    Vector dup[3];
    dup[0].Set( pt[0][0], pt[0][1], pt[0][2] );
    dup[1].Set( pt[1][0], pt[1][1], pt[1][2] );
    dup[2].Set( pt[2][0], pt[2][1], pt[2][2] );
    
    S3DGL world;
    world.Clear();
    world.RotateX( angley );
    world.RotateY( anglexz );
    world.Translate( SetVector( 0.0f, 0.0f, 0.0f ) - move );
    
    
    
    
    
    
    
    
    //world.AddTriangle( -5, -5, -5, -5, 5, -5, 5, 5, -5 );
    //world.AddTriangle( -5, -5, -5, 5, -5, -5, 5, 5, -5 );
    //world.AddTriangle( -5, -5, 5, -5, 5, 5, 5, 5, 5 );
    //world.AddTriangle( -5, -5, 5, 5, -5, 5, 5, 5, 5 );
    
    for( int a=move[0]/5-7; a<(move[0]/5+7); a++ ){
    for( int b=move[2]/5-7; b<(move[2]/5+7); b++ ){
        if( a>=0 && a<100 && b>=0 && b<100 )
        world.AddTriangle( a*5, hmap[a][b], b*5, (a+1)*5, hmap[a+1][b], b*5, a*5, hmap[a][b+1], (b+1)*5 );
        //world.AddTriangle( a*5, hmap[a][b+1], (b+1)*5, (a+1)*5, hmap[a+1][b], b*5, (a+1)*5, hmap[a+1][b+1], (b+1)*5 );
    }}
    
    
    
    
    
    
    
    
    world.Calculate();
    for( unsigned int x = 0; x < S3DGL_BUFFOR_X; x++ ){
    for( unsigned int y = 0; y < S3DGL_BUFFOR_Y; y++ ){
        if( (world.collorbuffor[x][y]) == '#' )
        {
            //DrawString( 0, 2, x*2.0f, y*2.0f, "#" );
            DrawChar( 0, 2, x*2.0f, y*2.0f, '#' );
        }
        else
        {
            //DrawString( 0, 8, x*8, y*8, " " );
        }
    }}
    
    /*
    al_set_target_bitmap( desktop ); 
    al_clear_to_color( al_map_rgba( 32, 32, 32, 0 ) );
    
    DrawString( 0, 8, 0, 2*0, logo01 );
    DrawString( 0, 8, 0, 2*4, logo02 );
    DrawString( 0, 8, 0, 2*8, logo03 );
    DrawString( 0, 8, 0, 2*12, logo04 );
    DrawString( 0, 8, 0, 2*16, logo05 );
    DrawString( 0, 8, 0, 2*20, logo06 );
    DrawString( 0, 8, 0, 2*24, logo07 );
    DrawString( 0, 8, 0, 2*28, logo08 );
    DrawString( 0, 8, 0, 2*32, logo09 );
    DrawString( 0, 8, 0, 2*36, logo10 );
    DrawString( 0, 8, 0, 2*40, logo11 );
    DrawString( 0, 8, 0, 2*44, logo12 );
    DrawString( 0, 8, 0, 2*48, logo13 );
    DrawString( 0, 8, 0, 2*52, logo14 );
    DrawString( 0, 8, 0, 2*56, logo15 );
    DrawString( 0, 8, 0, 2*60, logo16 );
    DrawString( 0, 8, 0, 2*64, logo17 );
    DrawString( 0, 8, 0, 2*68, logo18 );
    
    al_set_target_bitmap( al_get_backbuffer( display ) );
    */
    al_draw_scaled_bitmap( desktop, 0, 0, 296, 144, 0, 0, 144, 144, 0 );
  
    
    DrawCursor( mouse.x, mouse.y );
    al_flip_display();
}
