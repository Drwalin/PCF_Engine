ALLEGRO_BITMAP * fonts[3] = { NULL, NULL, NULL };

inline int InitFonts()
{
    fonts[0] = al_load_bitmap( "Data\\Fonts\\font1.png" );
    fonts[1] = al_load_bitmap( "Data\\Fonts\\font2.png" );
    fonts[2] = al_load_bitmap( "Data\\Fonts\\font3.png" );
}

inline void DeInitFonts()
{
    al_destroy_bitmap( fonts[0] );
    al_destroy_bitmap( fonts[1] );
    al_destroy_bitmap( fonts[2] );
}

inline void DrawChar( unsigned int id_font, int size, float x, float y, char symbol )
{
    al_draw_scaled_bitmap( fonts[id_font],
                            (float)(int(( symbol - 32 ) % 16)*8.0f),
                            (float)(int(( symbol - 32 ) / 16)*8.0f),
                            8.0f, 8.0f, x, y, size, size*2, 0 );
}

inline void DrawString( unsigned int id_font, int size, float x, float y, char * string )
{
    float letter[2];
    
    for( unsigned int id = 0; ( string[id] < 127 ) && ( string[id] > 31 ); id++ )
    {
        DrawChar( id_font, size, x, y, string[id] );
        x += size;
    }
}
