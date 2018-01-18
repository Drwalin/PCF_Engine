




inline float ObjectAlive::GetMinX()
{
    return pos[0];
}
inline float  ObjectAlive::GetMinY()
{
    return pos[1];
}
inline float ObjectAlive::GetMinZ()
{
    return pos[2];
}
inline float ObjectAlive::GetMaxX()
{
    return pos[0]+width;
}
inline float ObjectAlive::GetMaxY()
{
    return pos[1]+heighthead+heightchest+heightlegs;//(heightlegs*float(sneak%2));
}
inline float ObjectAlive::GetMaxZ()
{
    return pos[2]+width;
}



inline Vector ObjectAlive::GetMaxVertexWithVersor( Vector versor )
{
    //    dla obiektu mog¹cego siê obracaæ, najpierwsz trzeba przekszta³ciæ wierzcho³ki i versor,
    //    obliczyæ ak jak tu, a na koñcu przekrzta³ciæ punkt zwrotny odwrotnie do przekrzta³cenia pocz¹tkowego
    
    Vector pointout;
    pointout[0] = 0.0f;
    pointout[1] = 0.0f;
    pointout[2] = 0.0f;
    
    if( versor.vector[0] <  0.0f )
        pointout[0] = GetMinX();
    else
        pointout[0] = GetMaxX();
    
    
    if( versor.vector[1] <  0.0f )
        pointout[1] = GetMinY();
    else
        pointout[1] = GetMaxY();
    
    
    if( versor.vector[2] <  0.0f )
        pointout[2] = GetMinZ();
    else
        pointout[2] = GetMaxZ();
    
    
    return pointout;
}








ObjectAlive::ObjectAlive()
{
    FLOATING_VALUES_TYPE width = 0.6f;
    FLOATING_VALUES_TYPE heightlegs = 0.8f;
    FLOATING_VALUES_TYPE heightches = 0.52f;
    FLOATING_VALUES_TYPE heighhead = 0.33f;
    
    bpos[0] = 0.0f;
    bpos[1] = 0.0f;
    bpos[2] = 0.0f;
    pos[0] = 0.0f;
    pos[1] = 0.0f;
    pos[2] = 0.0f;
    speed[0] = 0.0f;
    speed[1] = 0.0f;
    speed[2] = 0.0f;
    force[0] = 0.0f;
    force[1] = 0.0f;
    force[2] = 0.0f;
    barycenter[0] = width / 2.0f;
    barycenter[1] = ( heightlegs + heightches + heighhead ) /2.0f;
    barycenter[2] = width / 2.0f;
    
    lookxz = 0.0f;;
    looky = 0.0f;
    
    mass = 75.0f;
    
    collision = false;
    collisiondown = false;
    collisionup = false;
    
    sneak = false;
    run = false;
    
    type = 0;
    id = 0;
    id_graphicmodel = 0;
    name.name[0] = 0;
}
