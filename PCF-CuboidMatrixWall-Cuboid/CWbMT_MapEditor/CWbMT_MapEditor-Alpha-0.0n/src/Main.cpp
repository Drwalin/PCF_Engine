


int main( int argc, char ** argv )
{
    char * name__ = new char[8192];
    printf( "\n Write path to the source map file: " );
    scanf( "%s", name__ );
	
	__Init();
	
	float time1 = 0.0f, time2 = 0.0f, frametime = 0.0f;
	
	
	vertex.resize( vertex.size()+8 );
	
	vertex[vertex.size()-8].pos = SetVector( -10.0f, -2.0f,  10.0f );
	vertex[vertex.size()-7].pos = SetVector( -10.0f,  2.0f,  10.0f );
	vertex[vertex.size()-6].pos = SetVector(  10.0f,  2.0f,  10.0f );
	vertex[vertex.size()-5].pos = SetVector(  10.0f, -2.0f,  10.0f );
	vertex[vertex.size()-4].pos = SetVector( -10.0f, -2.0f, -10.0f );
	vertex[vertex.size()-3].pos = SetVector( -10.0f,  2.0f, -10.0f );
	vertex[vertex.size()-2].pos = SetVector(  10.0f,  2.0f, -10.0f );
	vertex[vertex.size()-1].pos = SetVector(  10.0f, -2.0f, -10.0f );
	
	
	
    Button fast_but;
    fast_but.x = 0;
    fast_but.y = 0;
    fast_but.wx = 200;
    fast_but.wy = 40;
    fast_but.other_option = DRAW_NONE;
    fast_but.option_enabling = MOVE_WINDOW;
	fast_but.texture_on = al_load_bitmap( "Data\\Textures\\Buttons\\MoveWindowOn.png" );
	fast_but.texture_off = al_load_bitmap( "Data\\Textures\\Buttons\\MoveWindowOff.png" );
    button.push_back( fast_but );
    
    fast_but.x = 0;
    fast_but.y = 40;
    fast_but.wx = 200;
    fast_but.wy = 40;
    fast_but.other_option = DRAW_NONE;
    fast_but.option_enabling = OPERATE_VERTEX;
	fast_but.texture_on = al_load_bitmap( "Data\\Textures\\Buttons\\OperateVertexOn.png" );
	fast_but.texture_off = al_load_bitmap( "Data\\Textures\\Buttons\\OperateVertexOff.png" );
    button.push_back( fast_but );
    
    fast_but.x = 0;
    fast_but.y = 80;
    fast_but.wx = 200;
    fast_but.wy = 40;
    fast_but.other_option = DRAW_NONE;
    fast_but.option_enabling = CREATE_VERTEX;
	fast_but.texture_on = al_load_bitmap( "Data\\Textures\\Buttons\\CreateVertexOn.png" );
	fast_but.texture_off = al_load_bitmap( "Data\\Textures\\Buttons\\CreateVertexOff.png" );
    button.push_back( fast_but );
    
    fast_but.x = 0;
    fast_but.y = 120;
    fast_but.wx = 200;
    fast_but.wy = 40;
    fast_but.other_option = USE_CONNECTING_POINTS;
    fast_but.option_enabling = NONE_OPTION;
	fast_but.texture_on = al_load_bitmap( "Data\\Textures\\Buttons\\ConnectVertexOn.png" );////////////////
	fast_but.texture_off = al_load_bitmap( "Data\\Textures\\Buttons\\ConnectVertexOff.png" );//////////////
    button.push_back( fast_but );
    
    
    
    fast_but.x = 0;
    fast_but.y = 200;
    fast_but.wx = 200;
    fast_but.wy = 40;
    fast_but.other_option = DRAW_GRID;
    fast_but.option_enabling = NONE_OPTION;
	fast_but.texture_on = al_load_bitmap( "Data\\Textures\\Buttons\\DrawGridOn.png" );
	fast_but.texture_off = al_load_bitmap( "Data\\Textures\\Buttons\\DrawGridOff.png" );
    button.push_back( fast_but );
    
	
    
    fast_but.x = 0;
    fast_but.y = 280;
    fast_but.wx = 200;
    fast_but.wy = 40;
    fast_but.other_option = DRAW_NONE;
    fast_but.option_enabling = SAVE_PROJECT;
	fast_but.texture_on = al_load_bitmap( "Data\\Textures\\Buttons\\SaveProject.png" );
	fast_but.texture_off = al_load_bitmap( "Data\\Textures\\Buttons\\SaveProject.png" );
    button.push_back( fast_but );
    
    fast_but.x = 0;
    fast_but.y = 320;
    fast_but.wx = 200;
    fast_but.wy = 40;
    fast_but.other_option = DRAW_NONE;
    fast_but.option_enabling = LOAD_PROJECT;
	fast_but.texture_on = al_load_bitmap( "Data\\Textures\\Buttons\\LoadProject.png" );
	fast_but.texture_off = al_load_bitmap( "Data\\Textures\\Buttons\\LoadProject.png" );
    button.push_back( fast_but );
    
    fast_but.x = 0;
    fast_but.y = 360;
    fast_but.wx = 200;
    fast_but.wy = 40;
    fast_but.other_option = DRAW_NONE;
    fast_but.option_enabling = REVERSE_NORMAL;
	fast_but.texture_on = al_load_bitmap( "Data\\Textures\\Buttons\\ReverseNormal.png" );
	fast_but.texture_off = al_load_bitmap( "Data\\Textures\\Buttons\\ReverseNormal.png" );
    button.push_back( fast_but );
    
    
    
    fast_but.x = 0;
    fast_but.y = 440;
    fast_but.wx = 200;
    fast_but.wy = 40;
    fast_but.other_option = DRAW_NONE;
    fast_but.option_enabling = SET_TEXTURE_COORDINATES;
	fast_but.texture_on = al_load_bitmap( "Data\\Textures\\Buttons\\SetTextureCoordinates.png" );
	fast_but.texture_off = al_load_bitmap( "Data\\Textures\\Buttons\\SetTextureCoordinates.png" );
    button.push_back( fast_but );
    
    
    
    
    /*
    char * name__ = new char[8192];
    printf( "\n Write path to the source map file: " );
    scanf( "%s", name__ );*/
    FullMapTexture = al_load_bitmap( name__ );	// "..\\BigData\\Map\\WiedzminWorld.png" );
    delete[] name__;
    
    
    
    
    while( !isKeyDown( ALLEGRO_KEY_ESCAPE ) )
    {
        frametime = time2 - time1;
        if( frametime < (1.0f/__MAXFPS) )
        {
            al_get_keyboard_state( &keyb_currentFrame );
            time2 = al_get_time();
            continue;
        }
        time1 = al_get_time();
        al_get_keyboard_state( &keyb_currentFrame );
        al_get_mouse_state( &mouse );
        
        
        
        
        
        
        
        
        
        UpdateIteration( frametime );
        
        
        
        
        
        Renderer();
        
        
        
        
        
        mouse_lastFrame = mouse;
        keyb_lastFrame = keyb_currentFrame;
        
        time2 = al_get_time();
    }
    __DeInit();
    return 0;
}


