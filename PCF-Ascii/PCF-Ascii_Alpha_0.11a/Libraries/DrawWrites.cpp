ALLEGRO_BITMAP * fonts[3] = { NULL, NULL, NULL };

int InitFonts()
{
    fonts[0] = al_load_bitmap( "Data\\Fonts\\font1.png" );
    fonts[1] = al_load_bitmap( "Data\\Fonts\\font2.png" );
    fonts[2] = al_load_bitmap( "Data\\Fonts\\font3.png" );
}

void DeInitFonts()
{
    al_destroy_bitmap( fonts[0] );
    al_destroy_bitmap( fonts[1] );
    al_destroy_bitmap( fonts[2] );
}

void DrawChar( unsigned int id_font, int size, float x, float y, char symbol )
{
    al_draw_scaled_bitmap( fonts[id_font],
                            (float)(int(( symbol - 32 ) % 16)*8.0f),
                            (float)(int(( symbol - 32 ) / 16)*8.0f),
                            2.0f, 2.0f, x, y, size, size*1.0f, 0 );
}

void DrawString( unsigned int id_font, int size, float x, float y, char * string )
{
    //float size = 8.0f; if( _size > 0 ) { size = _size; }
    
    float letter[2];
    
    for( unsigned int id = 0; ( string[id] < 127 ) && ( string[id] > 31 ); id++ )
    {
        DrawChar( id_font, size, x, y, string[id] );
        /*
        letter[0] = (float)(int(( string[id] - 32 ) % 16)*8.0f);
        letter[1] = (float)(int(( string[id] - 32 ) / 16)*8.0f);
        al_draw_scaled_bitmap( fonts[id_font], letter[0], letter[1], 8.0f, 8.0f, x, y, size, size, 0 );
        */
        x += size;
    }
}
