
void LoadMap( char * name )
{
    char argument_c[1024];
    int argument_i;
    unsigned int i = 0;
    ifstream file,file1,file2;
    
    sprintf( argument_c, "Data\\Maps\\%s\\Buildings_%s.mp", name, name );
    file.open( argument_c );
    if( !file.good() )
    {
        cout <<"\n Brak pliku budynkow mapy";
        getch();
        exit(0);
    }
    
    file >> argument_i;
    buildings.resize( argument_i );
    for( i = 0; i < argument_i; i++ )
    {
        file >> buildings[i].x;
        file >> buildings[i].y;
        file >> buildings[i].width;
        file >> buildings[i].height;
        file >> buildings[i].id_texture;
    }
    
    file.close();
    
    
    
    
    
    sprintf( argument_c, "Data/Maps/%s/NPCs_%s.mp", name, name );
    file1.open( argument_c );
    if( !file1.good() )
    {
        cout << "\n Brak pliku NPC'tow mapy";
        getch();
        exit(0);
    }
    
    file1 >> argument_i;
    npcs.resize( argument_i );
    for( i = 0; i < argument_i; i++ )
    {
        file1 >> npcs[i].x;
        file1 >> npcs[i].y;
        file1 >> npcs[i].width;
        file1 >> npcs[i].height;
        file1 >> npcs[i].textures;
        file1 >> npcs[i].type;
        file1 >> npcs[i].id;
        npcs[i].sx = 0.0f;
        npcs[i].sy = 0.0f;
    }
    
    file1.close();
    
    
    
    
    
    sprintf( argument_c, "Data\\Maps\\%s\\%s.mp", name, name );
    file2.open( argument_c );
    if( !file2.good() )
    {
        cout <<"\n Brak glownego pliku mapy";
        getch();
        exit(0);
    }
    
    file2 >> player.x;
    file2 >> player.y;
    file2 >> player.width;
    file2 >> player.height;
    player.sx = 0.0f;
    player.sy = 0.0f;
    
    file2.close();
}

void Load()
{
    char argument_c[1024];
    int argument_i;
    ifstream file;
    file.open( "settings.ini" );
    if( !file.good() )
    {
        cout << "\n Brak pliku konfiguracji (settings.ini)";
        getch();
        exit(0);
    }
    
    file >> argument_c;
    file >> argument_c;
    LoadMap( argument_c );
    file >> argument_c;
    file >> argument_c;
    LoadTextures( argument_c );
    
    file.close();
}
