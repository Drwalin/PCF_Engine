

#define trg trigger[int(x/XSIZETRIGGEROBJ)][int(z/ZSIZETRIGGEROBJ)].obj




float RadianFloatLinePoint( float * versor, float * possition, float * returnpoint )
{
    return (versor[0] * possition[0]) +
           (versor[1] * possition[1]) +
           (versor[2] * possition[2]);
}

void CollisionSeeLine( vector < unsigned int > * seeobjects, unsigned int ignore, float anglexz, float angley, float seeaspect, float range, float * possition )
{
    float returnpoint[3];
    float secondpoint[3] = { Xpoint( anglexz ), Ypoint( angley ), Zpoint( anglexz ) };
    float directionrange = sqrt( secondpoint[0]*secondpoint[0] + secondpoint[1]*secondpoint[1] + secondpoint[2]*secondpoint[2] );
    float versor[3] = { secondpoint[0]/directionrange, secondpoint[1]/directionrange, secondpoint[2]/directionrange };
    
    float possitioncheckpoint[3];
    
    for( float x = (possition[0]-range); x < (possition[0]+range+XSIZETRIGGEROBJ); x += XSIZETRIGGEROBJ )
    {
    for( float z = (possition[2]-range); z < (possition[2]+range+ZSIZETRIGGEROBJ); z += ZSIZETRIGGEROBJ )
    {
        for( unsigned int num = 0; num < trg.size(); num++ )
        {
            possitioncheckpoint[0] = object[trg[num]].pos[0] - possition[0];
            possitioncheckpoint[1] = object[trg[num]].pos[1] - possition[1];
            possitioncheckpoint[2] = object[trg[num]].pos[2] - possition[2];
            
            RadianFloatLinePoint( versor, possitioncheckpoint, returnpoint );
            
        }
    }
    }
}

#undef trg

//float RadianLinePoint( float * versor, float * possition )
//unsigned int CollisionLineObiect( float anglexz, float angley, float range, unsigned int objouting, float * possition )
