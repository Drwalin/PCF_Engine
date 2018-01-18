




void Map::ClearColliderAlive()
{
    int xtrg=0,ytrg=0,ztrg=0;
    for( xtrg = 0; xtrg < NUMBERTRIGGERALIVE; xtrg++ ){
    //for( ytrg = 0; ytrg < NUMBERTRIGGERALIVE; ytrg++ ){
    for( ztrg = 0; ztrg < NUMBERTRIGGERALIVE; ztrg++ ){
        collideralive[xtrg]/*[0]*/[ztrg].id.resize(0);
    }}//}
}
void Map::ClearColliderPhysic()
{
    int xtrg=0,ytrg=0,ztrg=0;
    for( xtrg = 0; xtrg < NUMBERTRIGGERPHYSICAL; xtrg++ ){
    //for( ytrg = 0; ytrg < NUMBERTRIGGERPHYSICAL; ytrg++ ){
    for( ztrg = 0; ztrg < NUMBERTRIGGERPHYSICAL; ztrg++ ){
        colliderphysic[xtrg]/*[0]*/[ztrg].id.resize(0);
    }}//}
}
void Map::ClearColliderTriangle()
{
    int xtrg=0,ytrg=0,ztrg=0;
    for( xtrg = 0; xtrg < NUMBERTRIGGERTRIANGLE; xtrg++ ){
    //for( ytrg = 0; ytrg < NUMBERTRIGGERTRIANGLE; ytrg++ ){
    for( ztrg = 0; ztrg < NUMBERTRIGGERTRIANGLE; ztrg++ ){
        collidertriangle[xtrg]/*[0]*/[ztrg].id.resize(0);
    }}//}
}

void Map::UpdateColliderAlive()
{
    ClearColliderAlive();
    int xtrg=0,ytrg=0,ztrg=0,i=0;
    for( i = 0; i < object.size() ; i++ )     //za³adowanie trójk¹tów do collider triggerow
    {
        for( xtrg = float(int(float(object[i].GetMinX()/SIZETRIGGERALIVE)))*SIZETRIGGERALIVE; xtrg < (object[i].GetMaxX() + ( SIZETRIGGERALIVE - (object[i].GetMaxX() - float(int(object[i].GetMaxX()/SIZETRIGGERALIVE)%2)) )); xtrg += SIZETRIGGERALIVE ){
            if( (int(xtrg)/SIZETRIGGERALIVE) >= NUMBERTRIGGERALIVE || (int)xtrg < 0 ) continue;
        //for( ytrg = float(int(float(object[i].GetMinY()/SIZETRIGGERALIVE)))*SIZETRIGGERALIVE; ytrg < (object[i].GetMaxY() + ( SIZETRIGGERALIVE - (object[i].GetMaxY() - float(int(object[i].GetMaxY()/SIZETRIGGERALIVE)%2)) )); ytrg += SIZETRIGGERALIVE ){
        //    if( (in(xtrg)/SIZETRIGGERALIVE) >= NUMBERTRIGGERALIVE || (int)xtrg < 0 ) continue;
        for( ztrg = float(int(float(object[i].GetMinZ()/SIZETRIGGERALIVE)))*SIZETRIGGERALIVE; ztrg < (object[i].GetMaxZ() + ( SIZETRIGGERALIVE - (object[i].GetMaxZ() - float(int(object[i].GetMaxZ()/SIZETRIGGERALIVE)%2)) )); ztrg += SIZETRIGGERALIVE ){
            if( (int(xtrg)/SIZETRIGGERALIVE) >= NUMBERTRIGGERALIVE || (int)xtrg < 0 ) continue;
            
            collideralive[int(xtrg/SIZETRIGGERALIVE)]/*[int(ytrg/SIZETRIGGERALIVE)]*/[int(ztrg/SIZETRIGGERALIVE)].id.resize(
                collideralive[int(xtrg/SIZETRIGGERALIVE)]/*[int(ytrg/SIZETRIGGERALIVE)]*/[int(ztrg/SIZETRIGGERALIVE)].id.size()+1 );
            collideralive[int(xtrg/SIZETRIGGERALIVE)]/*[int(ytrg/SIZETRIGGERALIVE)]*/[int(ztrg/SIZETRIGGERALIVE)].id[
                collideralive[int(xtrg/SIZETRIGGERALIVE)]/*[int(ytrg/SIZETRIGGERALIVE)]*/[int(ztrg/SIZETRIGGERALIVE)].id.size()-1 ] = i+1;
                
        }}//}
    }
}
void Map::UpdateColliderPhysic()
{
    ClearColliderPhysic();
    int xtrg=0,ytrg=0,ztrg=0,i=0;
    for( i = 0; i < objectphys.size() ; i++ )     //za³adowanie trójk¹tów do collider triggerow
    {
        for( xtrg = float(int(float(objectphys[i].GetMinX()/SIZETRIGGERPHYSICAL)))*SIZETRIGGERPHYSICAL; xtrg < (objectphys[i].GetMaxX() + ( SIZETRIGGERPHYSICAL - (objectphys[i].GetMaxX() - float(int(objectphys[i].GetMaxX()/SIZETRIGGERPHYSICAL)%2)) )); xtrg += SIZETRIGGERPHYSICAL ){
            if( (int(xtrg)/SIZETRIGGERPHYSICAL) >= NUMBERTRIGGERPHYSICAL || (int)xtrg < 0 ) continue;
        //for( ytrg = float(int(float(objectphys[i].GetMinY()/SIZETRIGGERPHYSICAL)))*SIZETRIGGERPHYSICAL; ytrg < (objectphys[i].GetMaxY() + ( SIZETRIGGERPHYSICAL - (objectphys[i].GetMaxY() - float(int(objectphys[i].GetMaxY()/SIZETRIGGERPHYSICAL)%2)) )); ytrg += SIZETRIGGERPHYSICAL ){
        //    if( (in(xtrg)/SIZETRIGGERPHYSICAL) >= NUMBERTRIGGERPHYSICAL || (int)xtrg < 0 ) continue;
        for( ztrg = float(int(float(objectphys[i].GetMinZ()/SIZETRIGGERPHYSICAL)))*SIZETRIGGERPHYSICAL; ztrg < (objectphys[i].GetMaxZ() + ( SIZETRIGGERPHYSICAL - (objectphys[i].GetMaxZ() - float(int(objectphys[i].GetMaxZ()/SIZETRIGGERPHYSICAL)%2)) )); ztrg += SIZETRIGGERPHYSICAL ){
            if( (int(xtrg)/SIZETRIGGERPHYSICAL) >= NUMBERTRIGGERPHYSICAL || (int)xtrg < 0 ) continue;
            
            colliderphysic[int(xtrg/SIZETRIGGERPHYSICAL)]/*[int(ytrg/SIZETRIGGERPHYSICAL)]*/[int(ztrg/SIZETRIGGERPHYSICAL)].id.resize(
                colliderphysic[int(xtrg/SIZETRIGGERPHYSICAL)]/*[int(ytrg/SIZETRIGGERPHYSICAL)]*/[int(ztrg/SIZETRIGGERPHYSICAL)].id.size()+1 );
            colliderphysic[int(xtrg/SIZETRIGGERPHYSICAL)]/*[int(ytrg/SIZETRIGGERPHYSICAL)]*/[int(ztrg/SIZETRIGGERPHYSICAL)].id[
                colliderphysic[int(xtrg/SIZETRIGGERPHYSICAL)]/*[int(ytrg/SIZETRIGGERPHYSICAL)]*/[int(ztrg/SIZETRIGGERPHYSICAL)].id.size()-1 ] = i+1;
                
        }}//}
    }
}
void Map::UpdateColliderTriangle()
{
    ClearColliderTriangle();
    int xtrg=0,ytrg=0,ztrg=0,i=0;
    for( i = 0; i < triangle.size() ; i++ )     //za³adowanie trójk¹tów do collider triggerow
    {
//        for( xtrg = float(int(float(triangle[i].GetMinX()/SIZETRIGGERTRIANGLE)))*SIZETRIGGERTRIANGLE; xtrg < (triangle[i].GetMaxX() + ( SIZETRIGGERTRIANGLE - (triangle[i].GetMaxX() - float(int(triangle[i].GetMaxX()/SIZETRIGGERTRIANGLE)%2)) )); xtrg += SIZETRIGGERTRIANGLE ){
//            if( (int(xtrg)/SIZETRIGGERTRIANGLE) >= NUMBERTRIGGERTRIANGLE || (int)xtrg < 0 ) continue;
//        //for( ytrg = float(int(float(triangle[i].GetMinY()/SIZETRIGGERTRIANGLE)))*SIZETRIGGERTRIANGLE; ytrg < (triangle[i].GetMaxY() + ( SIZETRIGGERTRIANGLE - (triangle[i].GetMaxY() - float(int(triangle[i].GetMaxY()/SIZETRIGGERTRIANGLE)%2)) )); ytrg += SIZETRIGGERTRIANGLE ){
//        //    if( (in(xtrg)/SIZETRIGGERTRIANGLE) >= NUMBERTRIGGERTRIANGLE || (int)xtrg < 0 ) continue;
//        for( ztrg = float(int(float(triangle[i].GetMinZ()/SIZETRIGGERTRIANGLE)))*SIZETRIGGERTRIANGLE; ztrg < (triangle[i].GetMaxZ() + ( SIZETRIGGERTRIANGLE - (triangle[i].GetMaxZ() - float(int(triangle[i].GetMaxZ()/SIZETRIGGERTRIANGLE)%2)) )); ztrg += SIZETRIGGERTRIANGLE ){
//            if( (int(xtrg)/SIZETRIGGERTRIANGLE) >= NUMBERTRIGGERTRIANGLE || (int)xtrg < 0 ) continue;
//            
//            collidertriangle[int(xtrg/SIZETRIGGERTRIANGLE)]/*[int(ytrg/SIZETRIGGERTRIANGLE)]*/[int(ztrg/SIZETRIGGERTRIANGLE)].id.resize(
//                collidertriangle[int(xtrg/SIZETRIGGERTRIANGLE)]/*[int(ytrg/SIZETRIGGERTRIANGLE)]*/[int(ztrg/SIZETRIGGERTRIANGLE)].id.size()+1 );
//            collidertriangle[int(xtrg/SIZETRIGGERTRIANGLE)]/*[int(ytrg/SIZETRIGGERTRIANGLE)]*/[int(ztrg/SIZETRIGGERTRIANGLE)].id[
//                collidertriangle[int(xtrg/SIZETRIGGERTRIANGLE)]/*[int(ytrg/SIZETRIGGERTRIANGLE)]*/[int(ztrg/SIZETRIGGERTRIANGLE)].id.size()-1 ] = i+1;
//                
//        }}//}
        for( xtrg = int(triangle[i].GetMinX()/SIZETRIGGERTRIANGLE); xtrg <= int(triangle[i].GetMaxX()/SIZETRIGGERTRIANGLE); xtrg++ ){
            if( xtrg < 0 || xtrg >= NUMBERTRIGGERTRIANGLE ) {continue;}else{
        for( ztrg = int(triangle[i].GetMinZ()/SIZETRIGGERTRIANGLE); ztrg <= int(triangle[i].GetMaxZ()/SIZETRIGGERTRIANGLE); ztrg++ ){
            if( ztrg < 0 || ztrg >= NUMBERTRIGGERTRIANGLE ) {continue;}else{
                //collidertriangle[xtrg][ztrg].id.resize(
                //    collidertriangle[xtrg][ztrg].id.size() + 1 );
                //collidertriangle[xtrg][ztrg].id[
                //    collidertriangle[xtrg][ztrg].id.size() - 1 ] = i;
                collidertriangle[xtrg][ztrg].id.push_back( (unsigned int)(i) );
        }}}}
    }
}






