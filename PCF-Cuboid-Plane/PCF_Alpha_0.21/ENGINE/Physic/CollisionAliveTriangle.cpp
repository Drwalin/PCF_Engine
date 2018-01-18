
#define OBJNUM object[number]
#define OBJTRI triangle[ collidertriangle[x][z].id[calculate] ]
//#define OBJTRI triangle[ calculate ]



/*


             /|\
              |        _
              |        /|
              |+y    /
              |    /-z
              |  /
              |/__ __ __\
               +x   /
      
      
             /|\
              |
              |
              |+y
              |
              |
              |__ __ __\
             /    +x   /
           /
         /+z
      |/_


    numerowanie krawêdzi:
    
             __ __ __ __ __ ___
           /|      8          /|
         /  |               /  |
       /11  |             /9   |
     /__ __ __ __ __ __ /      |
    |       |   10     |       |
    |       |          |       |
    |       |          |       |
    |       |          |       |
    |       |          |       |
    |       |4         |       |5
    |       |          |       |
    |       |          |       |
    |       |          |       |
    |7      |          |6      |
    |       |          |       |
    |       |          |       |
    |       |__ __ __ _|_ __ __|
    |      /       0   |      /
    |    /3            |    /1
    |  /               |  /
    |/__ __ __ __ __ __|/ 
            2
            
    numerowanie wiezcho³ków:
    
            4__________________5
           /|                 /|
         /  |               /  |
       /    |             /    |
     /_________________ /      |
    |7      |          |6      |
    |       |          |       |
    |       |          |       |
    |       |          |       |
    |       |          |       |
    |       |          |       | 
    |       |          |       |
    |       |          |       |
    |       |          |       |
    |       |          |       |
    |       |          |       |
    |       |          |       |
    |      0|__________|_______|1
    |      /           |      /
    |    /             |    /
    |  /               |  /
    |/_________________|/
    3                  2
    
*/

void Map::CollisionAliveTriangle( unsigned int number, unsigned int frametime )     // kolizja obieku ¿ywego z trójk¹tem
{
    map.UpdateColliderTriangle();
    
    int x,z;
    unsigned int calculate;
    
    for( x = (int)((OBJNUM.GetMinX())/SIZETRIGGERTRIANGLE); x <= (int)((OBJNUM.GetMaxX())/SIZETRIGGERTRIANGLE); x++ ){
        if( x >= 0 && x < NUMBERTRIGGERTRIANGLE ){
    for( z = (int)((OBJNUM.GetMinZ())/SIZETRIGGERTRIANGLE); z <= (int)((OBJNUM.GetMaxZ())/SIZETRIGGERTRIANGLE); z++ ){
        if( z >= 0 && z < NUMBERTRIGGERTRIANGLE )
        {
            for( calculate = 0; calculate < collidertriangle[x][z].id.size(); calculate++ )//triangle.size(); calculate++ )//
            {
                if( OBJNUM.GetMaxY() > OBJTRI.GetMinY() ){
                if( OBJNUM.GetMinY() < OBJTRI.GetMaxY() ){
                if( OBJNUM.GetMaxX() > OBJTRI.GetMinX() ){
                if( OBJNUM.GetMinX() < OBJTRI.GetMaxX() ){
                if( OBJNUM.GetMaxZ() > OBJTRI.GetMinZ() ){
                if( OBJNUM.GetMinZ() < OBJTRI.GetMaxZ() ){
                    
                    
                    Vector vector_clear;
                    Vector vector_clear2;
                    
                    float radian1;
                    float radian2;
                    
                    
                    Vector p1, p2, p3;
                    Vector point_cross_triangle;
                    
                    p1 = ( OBJNUM.GetMaxVertexWithVersor( vector_clear - OBJNUM.speed ) - ( OBJNUM.pos - OBJNUM.bpos ) );
                    p3 = OBJNUM.GetMaxVertexWithVersor( OBJNUM.speed );
                    
                    
                    if( IfVectorPointCrossTriangle( p1, p3, calculate, &point_cross_triangle ) == false )
                    {
                        continue;
                    }
                    
                    
                    if( 1 == 0 )    // obliczanie kolizji
                    {
                        DO_COLLISION_ALIVE_OBJECT_TRIANGLE: // nazwa dla procedury 'goto'
                            OBJNUM.collision = true;
                            
                            Vector speed_versor;
                            speed_versor = OBJNUM.speed.Versor();
                            if( abs(OBJTRI.normal[1]) > 0.5f )
                            {
                                if( speed_versor[1] < -0.0f )
                                    OBJNUM.collisiondown = true;
                                else if( speed_versor[1] > 0.0f )
                                    OBJNUM.collisionup = true;
                            }
                            
                            
                            p1 = ( OBJNUM.GetMaxVertexWithVersor( vector_clear - OBJNUM.speed ) - ( OBJNUM.pos - OBJNUM.bpos ) );
                            vector_clear  = OBJTRI.normal * ( p3 - OBJTRI.tri[0] );
                            vector_clear2 = OBJTRI.normal * ( p1 - OBJTRI.tri[0] );
                            radian1 = ( vector_clear[0]  + vector_clear[1]  + vector_clear[2]  );
                            radian2 = ( vector_clear2[0] + vector_clear2[1] + vector_clear2[2] );
                            if( ( radian1 < 0.0f && radian2 > 0.0f ) || ( radian1 > 0.0f && radian2 < 0.0f ) )
                            {
                                // obliczanie odbiæ prêdkoœci i zmiany pozycji:
                                    
                                vector_clear = OBJTRI.normal * ( p3 - OBJTRI.tri[0] );
                                OBJNUM.pos = OBJNUM.pos - ( OBJTRI.normal * ( vector_clear[0] + vector_clear[1] + vector_clear[2] ) );
                            
                                vector_clear = OBJTRI.normal * ( OBJNUM.speed );
                                OBJNUM.speed = OBJNUM.speed - ( OBJTRI.normal * ( vector_clear[0] + vector_clear[1] + vector_clear[2] ) );
                            }
                            // obliczanie si³y tarcia:
                                // trza zrobiæ ;d
                            
                            //if( OBJNUM.speed.Lenght() > 2.0f )
                            //{
                            //    speed_versor = OBJNUM.speed.Versor();
                            //    OBJNUM.force = OBJNUM.force - ( speed_versor * abs( OBJNUM.force[1] * OBJNUM.mass ) );
                            //}
                            
                            speed_versor = OBJNUM.speed.Versor();
                            float resistanceforce = ((OBJNUM.force*OBJTRI.normal)).Lenght() * 3.5f;
    			            float rspeed = OBJNUM.speed.Lenght();
                            
                            
    			            
    			            
    			            if( rspeed >= 5.0f )
    			            {
                                OBJNUM.force -= OBJNUM.speed * ( 230.0f * OBJNUM.mass * float(frametime) / 1000.0f );//speed_versor * abs( 1.5f * resistanceforce );
                            }
                            else if( rspeed >= 0.1f )
                            {
                                OBJNUM.force -= OBJNUM.speed * ( 230.0f * OBJNUM.mass * float(frametime) / 1000.0f );//speed_versor * abs( 0.4f * resistanceforce );
                            }
                            else
                            {
                                //if( OBJNUM.force.Lenght()*2.0f <= resistanceforce*0.5f )
        		                //{
                                    OBJNUM.speed.Set( 0.0f, 0.0f, 0.0f );
                                    OBJNUM.force.Set( 0.0f, 0.0f, 0.0f );
                                //}
                                //else
                                //{
                                       
                                //}
                            }
                            
                            
                            continue;
                    }
                    
                    
                    p1.Set( OBJNUM.GetMaxX() , OBJNUM.GetMinY() , OBJNUM.GetMinZ() );
                    p2.Set( OBJNUM.GetMinX() , OBJNUM.GetMinY() , OBJNUM.GetMinZ() );
                    if( IfVectorPointCrossTriangle( p1, p2, calculate, &vector_clear ) == true )    // krawêdŸ 0
                        goto DO_COLLISION_ALIVE_OBJECT_TRIANGLE;  // przeniesienie do punktu obliczania kolizji
                    
                    p1.Set( OBJNUM.GetMaxX() , OBJNUM.GetMinY() , OBJNUM.GetMinZ() );
                    p2.Set( OBJNUM.GetMaxX() , OBJNUM.GetMinY() , OBJNUM.GetMaxZ() );
                    if( IfVectorPointCrossTriangle( p1, p2, calculate, &vector_clear ) == true )    // krawêdŸ 1
                        goto DO_COLLISION_ALIVE_OBJECT_TRIANGLE;  // przeniesienie do punktu obliczania kolizji
                    
                    p1.Set( OBJNUM.GetMinX() , OBJNUM.GetMinY() , OBJNUM.GetMaxZ() );
                    p2.Set( OBJNUM.GetMaxX() , OBJNUM.GetMinY() , OBJNUM.GetMaxZ() );
                    if( IfVectorPointCrossTriangle( p1, p2, calculate, &vector_clear ) == true )    // krawêdŸ 2
                        goto DO_COLLISION_ALIVE_OBJECT_TRIANGLE;  // przeniesienie do punktu obliczania kolizji
                    
                    p1.Set( OBJNUM.GetMinX() , OBJNUM.GetMinY() , OBJNUM.GetMaxZ() );
                    p2.Set( OBJNUM.GetMinX() , OBJNUM.GetMinY() , OBJNUM.GetMinZ() );
                    if( IfVectorPointCrossTriangle( p1, p2, calculate, &vector_clear ) == true )    // krawêdŸ 3
                        goto DO_COLLISION_ALIVE_OBJECT_TRIANGLE;  // przeniesienie do punktu obliczania kolizji
                    
                    
                    
                    
                    p1.Set( OBJNUM.GetMinX() , OBJNUM.GetMinY() , OBJNUM.GetMinZ() );
                    p2.Set( OBJNUM.GetMinX() , OBJNUM.GetMaxY() , OBJNUM.GetMinZ() );
                    if( IfVectorPointCrossTriangle( p1, p2, calculate, &vector_clear ) == true )    // krawêdŸ 4
                        goto DO_COLLISION_ALIVE_OBJECT_TRIANGLE;  // przeniesienie do punktu obliczania kolizji
                    
                    p1.Set( OBJNUM.GetMaxX() , OBJNUM.GetMinY() , OBJNUM.GetMinZ() );
                    p2.Set( OBJNUM.GetMaxX() , OBJNUM.GetMaxY() , OBJNUM.GetMinZ() );
                    if( IfVectorPointCrossTriangle( p1, p2, calculate, &vector_clear ) == true )    // krawêdŸ 5
                        goto DO_COLLISION_ALIVE_OBJECT_TRIANGLE;  // przeniesienie do punktu obliczania kolizji
                    
                    p1.Set( OBJNUM.GetMaxX() , OBJNUM.GetMinY() , OBJNUM.GetMaxZ() );
                    p2.Set( OBJNUM.GetMaxX() , OBJNUM.GetMaxY() , OBJNUM.GetMaxZ() );
                    if( IfVectorPointCrossTriangle( p1, p2, calculate, &vector_clear ) == true )    // krawêdŸ 6
                        goto DO_COLLISION_ALIVE_OBJECT_TRIANGLE;  // przeniesienie do punktu obliczania kolizji
                    
                    p1.Set( OBJNUM.GetMinX() , OBJNUM.GetMinY() , OBJNUM.GetMaxZ() );
                    p2.Set( OBJNUM.GetMinX() , OBJNUM.GetMaxY() , OBJNUM.GetMaxZ() );
                    if( IfVectorPointCrossTriangle( p1, p2, calculate, &vector_clear ) == true )    // krawêdŸ 7
                        goto DO_COLLISION_ALIVE_OBJECT_TRIANGLE;  // przeniesienie do punktu obliczania kolizji
                    
                    
                    
                    
                    p1.Set( OBJNUM.GetMaxX() , OBJNUM.GetMaxY() , OBJNUM.GetMinZ() );
                    p2.Set( OBJNUM.GetMinX() , OBJNUM.GetMaxY() , OBJNUM.GetMinZ() );
                    if( IfVectorPointCrossTriangle( p1, p2, calculate, &vector_clear ) == true )    // krawêdŸ 8
                        goto DO_COLLISION_ALIVE_OBJECT_TRIANGLE;  // przeniesienie do punktu obliczania kolizji
                    
                    p1.Set( OBJNUM.GetMaxX() , OBJNUM.GetMaxY() , OBJNUM.GetMinZ() );
                    p2.Set( OBJNUM.GetMaxX() , OBJNUM.GetMaxY() , OBJNUM.GetMaxZ() );
                    if( IfVectorPointCrossTriangle( p1, p2, calculate, &vector_clear ) == true )    // krawêdŸ 9
                        goto DO_COLLISION_ALIVE_OBJECT_TRIANGLE;  // przeniesienie do punktu obliczania kolizji
                    
                    p1.Set( OBJNUM.GetMinX() , OBJNUM.GetMaxY() , OBJNUM.GetMaxZ() );
                    p2.Set( OBJNUM.GetMaxX() , OBJNUM.GetMaxY() , OBJNUM.GetMaxZ() );
                    if( IfVectorPointCrossTriangle( p1, p2, calculate, &vector_clear ) == true )    // krawêdŸ 10
                        goto DO_COLLISION_ALIVE_OBJECT_TRIANGLE;  // przeniesienie do punktu obliczania kolizji
                    
                    p1.Set( OBJNUM.GetMinX() , OBJNUM.GetMaxY() , OBJNUM.GetMaxZ() );
                    p2.Set( OBJNUM.GetMinX() , OBJNUM.GetMaxY() , OBJNUM.GetMinZ() );
                    if( IfVectorPointCrossTriangle( p1, p2, calculate, &vector_clear ) == true )    // krawêdŸ 11
                        goto DO_COLLISION_ALIVE_OBJECT_TRIANGLE;  // przeniesienie do punktu obliczania kolizji
                    
                    
                    
                }}}}}}
            }
        }
    }}}
}

#undef OBJNUM
#undef OBJTRI



