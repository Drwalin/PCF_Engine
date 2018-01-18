

void LoadTextures( char * name )
{
    char argument_c[1024];
    int argument_i;
    unsigned int i = 0;
    ifstream file;
    ifstream imagepng;
    file.open( name );
    if( !file.good() )
    {
        cout << "\n Brak pliku textur";
        getch();
        exit(0);
    }
    
    file >> argument_i;
//    buildingstextures.resize( argument_i );
    for( i = 0; i < argument_i; i++ )
    {
        file.getline( argument_c, 1024 );
//        buildingstextures[i] = al_load_bitmap( argument_c );
    }
    
    file >> argument_i;
//    npcstextures.resize( argument_i );
    for( i = 0; i < argument_i; i++ )
    {
        file.getline( argument_c, 1024 );
//        npcstextures[i] = al_load_bitmap( argument_c );
    }
    
    file >> argument_i;
//    player.textures.resize( argument_i );
    for( i = 0; i < argument_i; i++ )
    {
        file.getline( argument_c, 1024 );
//        player.textures[i] = al_load_bitmap( argument_c );
    }
    
    file.getline( argument_c, 1024 );
    imagepng.open(argument_c);
    cout<<endl<<argument_c<<endl<<imagepng.good();
    imagepng.close();
    background = al_load_bitmap( argument_c );
    
    
    file.close();
}
