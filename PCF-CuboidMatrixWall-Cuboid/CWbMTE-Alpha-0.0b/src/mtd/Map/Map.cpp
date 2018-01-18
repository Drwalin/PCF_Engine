




#include"CollisionAABBAABB.cpp"
#include"CollisionAABBTriangle.cpp"




#include"UpdateColliders.cpp"






#include"Update.cpp"


Map::Map()
{
    textures.resize( 0 );
    models.resize( 0 );
    
    objAABB.resize( 0 );
    triPHYS.resize( 0 );
    triTEXT.resize( 0 );
    triSTRIP.resize( 0 );
    
    ParticlesSystem.particle = NULL;
    
    int CameraObject = 1;
    
    Gravity = -9.81f;
    AirResistance = 0.0f;
}

Map::~Map()
{
    textures.resize( 0 );
    models.resize( 0 );
    
    objAABB.resize( 0 );
    triPHYS.resize( 0 );
    triTEXT.resize( 0 );
    triSTRIP.resize( 0 );
    
    ParticlesSystem.particle = NULL;
    
    int CameraObject = 1;
    
    Gravity = -9.81f;
    AirResistance = 0.0f;
}

