




int Map::LoadTextures( NameLine128 name)
{
    NameLine128 textrname;
    NameLine128 texturepath;
    ifstream file;
    file.open( name.name );
    if( !file.good() )
    {
        return LOADING_FILE_FOULT;
    }
    while( 1 )
    {
        textrname.name[0] = 0;
        file.getline( textrname.name, 128 );
        if( textrname.name[0] == 0 )
        {
            break;
        }
        else
        {
            sprintf( texturepath.name, "Media\\Textures\\%s", textrname.name );
            textures.resize( textures.size()+1 );
            textures[textures.size()-1].LoadInit( texturepath );
        }
    }
}









