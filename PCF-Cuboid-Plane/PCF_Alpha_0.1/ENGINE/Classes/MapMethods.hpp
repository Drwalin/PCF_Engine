

/*
    UWAGA!!!
    �cie�ki do plik�w nale�y podawa� zawsze od lokacji pliku .exe ( pliku gry )

*/


#include"Map\LoadTextures.hpp"
#include"Map\MapColliderOperations.hpp"
#include"Map\MapLoad.hpp"

#include"Map\DrawTriangles.hpp"
#include"Map\DrawObjects.hpp"
#include"Map\MapDraw.hpp"




#include"Map\UpdatePhysic.hpp"




Map::Map()
{
    object.resize( 0 );
    objectphys.resize( 0 );
    triangle.resize( 0 );
    models.resize( 0 );
    textures.resize( 0 );
    
    mapname.name[0] = 0;
    
    gravitation = -9.81;
    
    ClearColliderAlive();
    ClearColliderPhysic();
    ClearColliderTriangle();
}
