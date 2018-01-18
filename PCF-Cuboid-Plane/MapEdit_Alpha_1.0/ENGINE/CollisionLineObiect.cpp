



float RadianLinePoint( float * versor, float * possition )
{
    float floatradian = abs(
                        (versor[0] * possition[0]) +
                        (versor[1] * possition[1]) +
                        (versor[2] * possition[2])
                        );
    
                        
    float point[3] = {
                        versor[0] * floatradian,
                        versor[1] * floatradian,
                        versor[2] * floatradian
                     };
                     
    return sqrt(
                ((point[0] - possition[0]) * (point[0] - possition[0])) +
                ((point[1] - possition[1]) * (point[1] - possition[1])) +
                ((point[2] - possition[2]) * (point[2] - possition[2]))
               );
}







unsigned int CollisionLineObiect( float anglexz, float angley, float range, unsigned int objouting, float * possition )
{
    float fastradianpoint = 0.0f;
    float radianobjectnull = 0.0f;
    unsigned int returnobjectcollision = 0;
    float secondpoint[3] = { Xpoint( anglexz ), Ypoint( angley ), Zpoint( anglexz ) };
    float directionrange = sqrt( secondpoint[0]*secondpoint[0] + secondpoint[1]*secondpoint[1] + secondpoint[2]*secondpoint[2] );
    float directionversor[3] = { secondpoint[0]/directionrange, secondpoint[1]/directionrange, secondpoint[2]/directionrange };
    /*
    secondpoint[0] += possition[0];
    secondpoint[1] += possition[1];
    secondpoint[2] += possition[2];
    */
    int chunk[2];
    float pointobject[3];
    float radianpointline;

    for( float radian = 0.0f; radian < (range+ADDRADIANLINECHECK); radian += ADDRADIANLINECHECK )
    {
        if( (chunk[0] == (int)((Xpoint( directionversor[0]*radian ) + possition[0])/XSIZETRIGGEROBJ)) && (chunk[1] == (int)((Zpoint( directionversor[2]*radian ) + possition[2])/ZSIZETRIGGEROBJ)) ) 
        {
            continue;
        }  
        chunk[0] = (int)((Xpoint( directionversor[0]*radian ) + possition[0])/XSIZETRIGGEROBJ);
        chunk[1] = (int)((Zpoint( directionversor[2]*radian ) + possition[2])/ZSIZETRIGGEROBJ);
        if( chunk[0] < 0.0f || chunk[1] < 0.0f )
        {
            continue;
        }
        chunk[0] = (unsigned int)chunk[0];
        chunk[1] = (unsigned int)chunk[1];
        
        
        
        for( unsigned int number = 0; number < trigger[chunk[0]][chunk[1]].obj.size(); number++ )
        {
            if( trigger[ chunk[ 0 ]][chunk[ 1 ]].obj[ number ] != 0 && trigger[ chunk[ 0 ]][chunk[ 1 ]].obj[ number ] != objouting )
            {
                pointobject[0] = object[ trigger[ chunk[ 0 ]][chunk[ 1 ]].obj[ number ]].pos[0] - possition[0];
                pointobject[1] = object[ trigger[ chunk[ 0 ]][chunk[ 1 ]].obj[ number ]].pos[1] - possition[1];
                pointobject[2] = object[ trigger[ chunk[ 0 ]][chunk[ 1 ]].obj[ number ]].pos[2] - possition[2];
                radianpointline = RadianLinePoint( directionversor, pointobject );
                if( radianpointline <= abs(object[ trigger[ chunk[ 0 ]][chunk[ 1 ]].obj[ number ]].radian) )
                {
                //    return trigger[ chunk[ 0 ]][chunk[ 1 ]].obj[ number ];
                    if( returnobjectcollision != 0 )
                    {
                        fastradianpoint = sqrt( pointobject[0]*pointobject[0] + pointobject[1]*pointobject[1] + pointobject[2]*pointobject[2] );
                        if( fastradianpoint < radianobjectnull && fastradianpoint < range )
                        {
                            returnobjectcollision = trigger[ chunk[ 0 ]][chunk[ 1 ]].obj[ number ];
                            radianobjectnull = fastradianpoint;
                        }
                    }
                    else
                    {
                        radianobjectnull = sqrt( pointobject[0]*pointobject[0] + pointobject[1]*pointobject[1] + pointobject[2]*pointobject[2] );
                        if( radianobjectnull <= range )
                        {
                            returnobjectcollision = trigger[ chunk[ 0 ]][chunk[ 1 ]].obj[ number ];
                        }
                        else if( radianobjectnull > range )
                        {
                            radianobjectnull = 0.0f;
                        }
                    }
                }
            }
        }
    }
    return returnobjectcollision;

}










#define NORMAL map.tri[ trigger[chunk[0]][chunk[1]].tri[number] ].normal
#define TRI map.tri[ trigger[chunk[0]][chunk[1]].tri[number] ].tri
#define DET map.tri[ trigger[chunk[0]][chunk[1]].tri[number] ].det
        
bool __CollisionLineTriangles( unsigned int objouting, float * pos1, float * pos2, float * posout )
{
    float fastradianpoint = 0.0f;
    float radianobjectnull = 0.0f;
    float directionrange = sqrt( pow(pos1[0]-pos2[0],2) + pow(pos1[1]-pos2[1],2) + pow(pos1[2]-pos2[2],2) );
    //float directionversor[3] = { (pos1[0]-pos2[0])/directionrange, (pos1[1]-pos2[1])/directionrange, (pos1[2]-pos2[2])/directionrange };
    float directionversor[3] = { (pos2[0]-pos1[0])/directionrange, (pos2[1]-pos1[1])/directionrange, (pos2[2]-pos1[2])/directionrange };
    float range;
    posout[0] = pos2[0];
    posout[1] = pos2[1];
    posout[2] = pos2[2];
    float t=0.0f;
    
    float ab, bc, ac, ad, bd, cd, P, P1, P2, P3, o;
    
    posout[0] = pos2[0];
    posout[1] = pos2[1];
    posout[2] = pos2[2];
    
    bool ifcollision = 0;
    
    
    int chunk[2]={999999,999999};
    float pointobject[3];
    float radianpointline = directionrange;;

    for( float radian = 0.0f; radian < (range+ADDRADIANLINECHECK); radian += ADDRADIANLINECHECK )
    {
        /*
        if( (chunk[0] == (int)((Xpoint( directionversor[0]*radian ) + pos1[0])/XSIZETRIGGER)) && (chunk[1] == (int)((Zpoint( directionversor[2]*radian ) + pos1[2])/ZSIZETRIGGER)) ) 
        {
            continue;
        }  
        chunk[0] = (int)((Xpoint( directionversor[0]*radian ) + pos1[0])/XSIZETRIGGER);
        chunk[1] = (int)((Zpoint( directionversor[2]*radian ) + pos1[2])/ZSIZETRIGGER);
        */
        
        
        if( (chunk[0] == (int)((directionversor[0]*radian + pos1[0])/XSIZETRIGGER)) && (chunk[1] == (int)((directionversor[2]*radian + pos1[2])/ZSIZETRIGGER)) ) 
        {
            continue;
        }  
        chunk[0] = (int)((directionversor[0]*radian + pos1[0])/XSIZETRIGGER);
        chunk[1] = (int)((directionversor[2]*radian + pos1[2])/ZSIZETRIGGER);
        
        
        if( chunk[0] < 0.0f || chunk[1] < 0.0f || chunk[0] > XSIZETRIGGER || chunk[1] > ZSIZETRIGGER )
        {
            continue;
        }
        chunk[0] = (unsigned int)chunk[0];
        chunk[1] = (unsigned int)chunk[1];
        
        
        for( unsigned int number = 0; number < trigger[chunk[0]][chunk[1]].tri.size(); number++ )
        {
            if( (NORMAL[0]*directionversor[0]) + (NORMAL[1]*directionversor[1]) + (NORMAL[2]*directionversor[2]) != 0.0f )
            {
                
                
                t = abs( 0.0f - ( ( DET + (NORMAL[0]*pos1[0]) + (NORMAL[1]*pos1[1]) + (NORMAL[2]*pos1[2]) ) / ( (NORMAL[0]*directionversor[0]) + (NORMAL[1]*directionversor[1]) + (NORMAL[2]*directionversor[2]) ) )  );
                
                if( directionrange >= t )
                {
                    if( radianobjectnull > t || ifcollision == 0)
                    {
                        
                        pointobject[0] = directionversor[0]*t + pos1[0];
                        pointobject[1] = directionversor[1]*t + pos1[1];
                        pointobject[2] = directionversor[2]*t + pos1[2];
                        
                        ab = sqrt( pow(TRI[0][0]-TRI[1][0],2) + pow(TRI[0][1]-TRI[1][1],2) + pow(TRI[0][2]-TRI[1][2],2) );
                        bc = sqrt( pow(TRI[1][0]-TRI[2][0],2) + pow(TRI[1][1]-TRI[2][1],2) + pow(TRI[1][2]-TRI[2][2],2) );
                        ac = sqrt( pow(TRI[2][0]-TRI[0][0],2) + pow(TRI[2][1]-TRI[0][1],2) + pow(TRI[2][2]-TRI[0][2],2) );
                        
                        ad = sqrt( pow(TRI[0][0]-pointobject[0],2) + pow(TRI[0][1]-pointobject[1],2) + pow(TRI[0][2]-pointobject[2],2) );
                        bd = sqrt( pow(TRI[1][0]-pointobject[0],2) + pow(TRI[1][1]-pointobject[1],2) + pow(TRI[1][2]-pointobject[2],2) );
                        cd = sqrt( pow(TRI[2][0]-pointobject[0],2) + pow(TRI[2][1]-pointobject[1],2) + pow(TRI[2][2]-pointobject[2],2) );
                        
                        o  = (ab+bd+ad)/2.0f;
                        P1 = sqrt(o*(o-ab)*(o-bd)*(o-ad));
                        
                        o  = (bd+bc+cd)/2.0f;
                        P2 = sqrt(o*(o-bd)*(o-bc)*(o-cd));
                        
                        o  = (ad+cd+ac)/2.0f;
                        P3 = sqrt(o*(o-ad)*(o-cd)*(o-ac));
                        
                        o  = (ab+bc+ac)/2.0f;
                        P  = sqrt(o*(o-ab)*(o-bc)*(o-ac));
                        
                        
                        if( P+1.0f >= P1+P2+P3 )
                        {
                            
                            ifcollision = true;
                            
                            
                            posout[0] = directionversor[0]*(t-0.05f) + pos1[0];
                            posout[1] = directionversor[1]*(t-0.05f) + pos1[1];
                            posout[2] = directionversor[2]*(t-0.05f) + pos1[2];
                        
                            radianobjectnull = t;
                            
                        }
                    }
                }
                
                
                
            }
        }
    }
    if( directionrange < sqrt( pow(pos1[0]-posout[0],2) + pow(pos1[1]-posout[1],2) + pow(pos1[2]-posout[2],2) ) )
    {
        posout[0] = pos2[0];
        posout[1] = pos2[1];
        posout[2] = pos2[2];
    }
    return ifcollision;
}


#undef NORMAL
#undef TRI
#undef DET











