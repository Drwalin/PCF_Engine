











int Map::LoadInit( NameLine128 name )
{
    NameLine128 argument;
    FLOATING_VALUES_TYPE argumentfloat;
    
    if( object.size() == 0 )
    {
        object.resize( 1 );
    }
    
    fstream file;
    file.open( name.name, ios::in );
    if( !file.good() )
    {
        return LOADING_FILE_FOULT;              // b³¹d przy wczyywaniu pliku textury
    }
    {
        file >> argument.name[0];
        switch( argument.name[0] )
        {
        case 65://FULL_WORDS_ARGUMENTS_1_0:
            {
                    while( 1 )
                    {
                        argument.name[0] = 0;
                        file >> argument.name[0];
                        if(  argument.name[0] == 't' )//    strcmp( argument.name, "texture" ) )               // za³aduje i zainicjuj texture
                        {
                            file.getline( argument.name, 128 );
                            textures.resize( textures.size()+1 );
                            textures[textures.size()-1].LoadInit( argument );
                            continue;
                        }
                        else if( argument.name[0] == 'm' )// strcmp( argument.name, "model" ) )                 // za³aduj i zainicjuj model
                        {
                            file.getline( argument.name, 128 );
                            models.resize( models.size()+1 );
                            models[models.size()-1].LoadInit( argument );
                            continue;
                        }
                        else if( argument.name[0] == 'o' )// strcmp( argument.name, "object" ) )                // wybierz obiekt
                        {
                            argument.name[0] = 0;
                            file >> argument.name;
                            if( argument.name[0] == 'a' )//      strcmp( argument.name, "alive" ) )             // za³aduj ¿ywy obiekt ( bez kolizji i fizyki obrotów )
                            {
                                object.resize( object.size()+1 );
                                file >> argument.name;
                                file >> object[object.size()-1].pos.vertex[0];
                                file >> object[object.size()-1].pos.vertex[1];
                                file >> object[object.size()-1].pos.vertex[2];
                                
                                file >> argument.name;
                                file >> object[object.size()-1].width;
                                file >> argument.name;
                                file >> object[object.size()-1].heightlegs;
                                file >> argument.name;
                                file >> object[object.size()-1].heightches;
                                file >> argument.name;
                                file >> object[object.size()-1].heighhead;
                                file >> argument.name;
                                file >> object[object.size()-1].mass;
                                
                                file >> argument.name;
                                file >> object[object.size()-1].type;
                                file >> argument.name;
                                file >> object[object.size()-1].id;
                                file >> argument.name;
                                file >> object[object.size()-1].id_graphicmodel;
                                file >> argument.name;
                                file >> object[object.size()-1].name.name;
                                continue;
                            }
                            else if( argument.name[0] == 'p' )// strcmp( argument.name, "physic" ) )            // za³aduj obiekt martwy ( z kolizj¹ i fizyk¹ obrotów )
                            {
                                continue;
                            }
                            else
                            {
                                return INVALID_ARGUMENT;
                            }
                        }
                        else if( argument.name[0] == 'T' )// strcmp( argument.name, "triangle" ) )              // wczytanie i zainiciowanie trójk¹ta fizycznego ( bez zainstalowania w colliderach 0
                        {
                            triangle.resize( triangle.size()+1 );
                            file >> argument.name;
                            file >> triangle[triangle.size()-1].tri[0].vertex[0];
                            file >> triangle[triangle.size()-1].tri[0].vertex[1];
                            file >> triangle[triangle.size()-1].tri[0].vertex[2];
                            file >> argument.name;
                            file >> triangle[triangle.size()-1].tri[1].vertex[0];
                            file >> triangle[triangle.size()-1].tri[1].vertex[1];
                            file >> triangle[triangle.size()-1].tri[1].vertex[2];
                            file >> argument.name;
                            file >> triangle[triangle.size()-1].tri[2].vertex[0];
                            file >> triangle[triangle.size()-1].tri[2].vertex[1];
                            file >> triangle[triangle.size()-1].tri[2].vertex[2];
                            
                            file >> argument.name;
                            file >> triangle[triangle.size()-1].image[0][0];
                            file >> triangle[triangle.size()-1].image[0][1];
                            file >> argument.name;
                            file >> triangle[triangle.size()-1].image[1][0];
                            file >> triangle[triangle.size()-1].image[1][1];
                            file >> argument.name;
                            file >> triangle[triangle.size()-1].image[2][0];
                            file >> triangle[triangle.size()-1].image[2][1];
                            
                            
                            file >> argument.name;
                            file >> triangle[triangle.size()-1].texture;            // jeœli 0 to nie rysowaæ
                            
                            triangle[triangle.size()-1].CalculateNormal();  // obliczenie normalnej p³aszczyzny
                            triangle[triangle.size()-1].CalculateDet();     // obliczenie wskaŸnika przesuniêcia trójk¹ta w przestrzeni
                            continue;
                        }
                        else if( argument.name[0] == 's' )// strcmp( argument.name, "stop" ) )                  // zakoñczenie ³adowania i inicjowania modeli, textu, obiektów, trójk¹tów fozcznych i przejœcie do iniciowania obiektów w collider triggerach
                        {
                            //goto INIT_COLLIDER_TRIGGERS;
        UpdateColliderAlive();
        UpdateColliderPhysic();
        UpdateColliderTriangle();
        return NORMAL_FILE_LOADED;
                        }
                        else if( argument.name[0] == '|' )// strcmp( argument.name, "//" ) )            // komentarz jednoliniowy o maksymalnej d³ugoœci 126 znaków (wliczaj¹c spacje i znaki specjalne prócz znaku przejœcia do nowej linii
                        {
                            file.getline( argument.name, 128 ); cout<<"\n"<<argument.name;
                            continue;
                        }
                        else if( argument.name[0] == '/' )// strcmp( argument.name, "/*" ) )            // komentarz wieloliniowy
                        {
                            while(  argument.name[0] == '/' )//!strcmp( argument.name, "/" ) )
                            {
                                file >> argument.name; cout<<"\n"<<argument.name;
                            }
                            continue;
                        }
                        else
                        {
                            return INVALID_ARGUMENT;
                        }
                        
                        
                        
                    }
            }
            break;
        case BINARY_ARGUMENTS_1_0:
            {
            }
            break;
        default:
            return INVALID_ARGUMENT;
        }
    }
    
//    INIT_COLLIDER_TRIGGERS:
        
        
        UpdateColliderAlive();
        UpdateColliderPhysic();
        UpdateColliderTriangle();
        
        
        
    /*
    unsigned int xtrg=0,ytrg=0,ztrg=0,i=0;
    for( i = 0; i < triangle.size() ; i++ )     //za³adowanie trójk¹tów do collider triggerow
    {
        for( xtrg = float(int(float(triangle[i].GetMinX()/SIZETRIGGERTRIANGLE)))*SIZETRIGGERTRIANGLE; xtrg < (triangle[i].GetMaxX() + ( NUMBERTRIGGERTRIANGLE - (triangle[i].GetMaxX() - float(int(triangle[i].GetMaxX()/SIZETRIGGERTRIANGLE)%2)) )); xtrg += SIZETRIGGERTRIANGLE ){
            if( (in(xtrg)/SIZETRIGGERTRIANGLE) >= NUMBERTRIGGERTRIANGLE || (int)xtrg < 0 ) continue;
        for( ytrg = float(int(float(triangle[i].GetMinY()/SIZETRIGGERTRIANGLE)))*SIZETRIGGERTRIANGLE; ytrg < (triangle[i].GetMaxY() + ( NUMBERTRIGGERTRIANGLE - (triangle[i].GetMaxY() - float(int(triangle[i].GetMaxY()/SIZETRIGGERTRIANGLE)%2)) )); ytrg += SIZETRIGGERTRIANGLE ){
            if( (in(xtrg)/SIZETRIGGERTRIANGLE) >= NUMBERTRIGGERTRIANGLE || (int)xtrg < 0 ) continue;
        for( ztrg = float(int(float(triangle[i].GetMinZ()/SIZETRIGGERTRIANGLE)))*SIZETRIGGERTRIANGLE; ztrg < (triangle[i].GetMaxZ() + ( NUMBERTRIGGERTRIANGLE - (triangle[i].GetMaxZ() - float(int(triangle[i].GetMaxZ()/SIZETRIGGERTRIANGLE)%2)) )); ztrg += SIZETRIGGERTRIANGLE ){
            if( (in(xtrg)/SIZETRIGGERTRIANGLE) >= NUMBERTRIGGERTRIANGLE || (int)xtrg < 0 ) continue;
            
            collidertriangle[int(xtrg/SIZETRIGGERTRIANGLE)][int(ytrg/SIZETRIGGERTRIANGLE)][int(ztrg/SIZETRIGGERTRIANGLE)].id.resize(
                collidertriangle[int(xtrg/SIZETRIGGERTRIANGLE)][int(ytrg/SIZETRIGGERTRIANGLE)][int(ztrg/SIZETRIGGERTRIANGLE)].id.size()+1 );
            collidertriangle[int(xtrg/SIZETRIGGERTRIANGLE)][int(ytrg/SIZETRIGGERTRIANGLE)][int(ztrg/SIZETRIGGERTRIANGLE)].id[
                collidertriangle[int(xtrg/SIZETRIGGERTRIANGLE)][int(ytrg/SIZETRIGGERTRIANGLE)][int(ztrg/SIZETRIGGERTRIANGLE)].id.size()-1 ] = i+1;
                
        }}}
    }*/
    
    
    
    //return UNKNOWN_ERROR;
    return NORMAL_FILE_LOADED;
}










