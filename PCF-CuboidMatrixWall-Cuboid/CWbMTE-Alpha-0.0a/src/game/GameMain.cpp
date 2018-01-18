




int main( int argc, char *argv[] )
{
    Engine engine;
    
    engine.Set( CMT_WINDOW_NAME, "CWbMTEngine Alpha 0.0" );
    engine.Set( CMT_WINDOW_POS, 0, 0 );
    engine.Set( CMT_WINDOW_SIZE, 800, 600 );
    engine.Set( CMT_GRAPHIC_MODE_OPENGL );
    
    int MapId;
    engine.Add( CMT_MAP_NEW, &MapId );
    engine.Set( CMT_MAP_ID_TO_UPDATE, MapId );
    
    engine.Set( CMT_GRAVITY, -9.81f );
    engine.Set( CMT_AIR_RESISTANCE, 1.3f );
    
    int Wall_Id_1;
    engine.Add( CMT_WALL,
                pos.x, pos.y, pos.z,
                size.x, size.y, size.z,
                rotate.arround.x, rotate.arround.y, rotate.arround.z,
                id_texture,
                &Wall_Id_1 );
    
    int PlayerId;
    engine.Add( CMT_OBJECT,
                pos.x, pos.y, pos.z,
                size.x, size.y, size.z,
                mass, model_id
                collision(bool), gravity(bool), &PlayerId );
    
    engine.Set( CMT_CAMER_ID_OBJECT, PlayerId );
    
    engine.Add( CMT_OBJECT_FORCE, PlayerId, 69.0f, 666.0f, 69.0f );
    engine.Set( CMT_OBJECT_POS, PlayerId, 13.0f, 69.0f, 666.0f );
    engine.Add( CMT_WALL_POS, Wall_Id_1, 666.0f, 666.0f, 666.0f );
    engine.Set( CMT_WALL_POS, Wall_Id_1, 6669.0f, 6669.0f, 6669.0f );
    
    float * pozycja_dupy;
    float * wielkosc_dupy;
    engine.Get( CMT_OBJECT_SPEED, PlayerId, pozycja_dupy );
    engine.Get( CMT_OBJECT_SIZE, PlayerId, wielkosc_dupy );
    
    engine.Del( CMT_OBJECT, PlayerId );
    engine.Del( CMT_WALL, Wall_Id_1 );
    
    engine.Init( &argc, argv );
    engine.BeginLoop();
    
    return 0;
}
