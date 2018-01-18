




FLOATING_VALUES_TYPE ObjectAlive::GetMinX()
{
    return pos.vertex[0];
}
FLOATING_VALUES_TYPE ObjectAlive::GetMinY()
{
    return pos.vertex[1];
}
FLOATING_VALUES_TYPE ObjectAlive::GetMinZ()
{
    return pos.vertex[2];
}
FLOATING_VALUES_TYPE ObjectAlive::GetMaxX()
{
    return pos.vertex[0]+width;
}
FLOATING_VALUES_TYPE ObjectAlive::GetMaxY()
{
    return pos.vertex[1]+heighhead+heightches+(heightlegs*float(sneak%2));
}
FLOATING_VALUES_TYPE ObjectAlive::GetMaxZ()
{
    return pos.vertex[2]+width;
}



Vertex ObjectAlive::GetMaxVertexWithVersor( Vertex * versor )
{
    //    dla obiektu mog¹cego siê obracaæ, najpierwsz trzeba przekszta³ciæ wierzcho³ki i versor,
    //    obliczyæ ak jak tu, a na koñcu przekrzta³ciæ punkt zwrotny odwrotnie do przekrzta³cenia pocz¹tkowego
    
    Vertex pointout;
    pointout.vertex[0] = 0.0f;
    pointout.vertex[1] = 0.0f;
    pointout.vertex[2] = 0.0f;
    
    if( versor->vertex[0] <  0.0f )
        pointout.vertex[0] = GetMinX();
    else
        pointout.vertex[0] = GetMaxX();
    
    
    if( versor->vertex[1] <  0.0f )
        pointout.vertex[1] = GetMinY();
    else
        pointout.vertex[1] = GetMaxY();
    
    
    if( versor->vertex[2] <  0.0f )
        pointout.vertex[2] = GetMinZ();
    else
        pointout.vertex[2] = GetMaxZ();
    
    
    return pointout;
}








ObjectAlive::ObjectAlive()
{
    FLOATING_VALUES_TYPE width = 0.6f;
    FLOATING_VALUES_TYPE heightlegs = 0.8f;
    FLOATING_VALUES_TYPE heightches = 0.52f;
    FLOATING_VALUES_TYPE heighhead = 0.33f;
    
    pos.vertex[0] = 0.0f;
    pos.vertex[1] = 0.0f;
    pos.vertex[2] = 0.0f;
    speed.vertex[0] = 0.0f;
    speed.vertex[1] = 0.0f;
    speed.vertex[2] = 0.0f;
    force.vertex[0] = 0.0f;
    force.vertex[1] = 0.0f;
    force.vertex[2] = 0.0f;
    barycenter.vertex[0] = width / 2.0f;
    barycenter.vertex[1] = ( heightlegs + heightches + heighhead ) /2.0f;
    barycenter.vertex[2] = width / 2.0f;
    
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
