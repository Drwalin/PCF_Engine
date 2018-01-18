



inline Vector AABB::ClosestPoint( Vector p )
{
    Vector out;
    if( p[0] >= pos[0]+size[0] )
        out[0] = pos[0]+size[0];
    else if( p[0] <= pos[0]-size[0] )
        out[0] = pos[0]-size[0];
    else
        out[0] = p[0];
        
    if( p[1] >= pos[1]+size[1] )
        out[1] = pos[1]+size[1];
    else if( p[1] <= pos[1]-size[1] )
        out[1] = pos[1]-size[1];
    else
        out[1] = p[1];
    
    if( p[2] >= pos[2]+size[2] )
        out[2] = pos[2]+size[2];
    else if( p[2] <= pos[2]-size[2] )
        out[2] = pos[2]-size[2];
    else
        out[2] = p[2];
    
    return out;
}

AABB::Object()
{
    bpos.Set( 0.0f, 0.0f, 0.0f );
    pos.Set( 0.0f, 0.0f, 0.0f );
    velocity.Set( 0.0f, 0.0f, 0.0f );
    force.Set( 0.0f, 0.0f, 0.0f );
    size.Set( 1.0f, 1.0f, 1.0f );
    
    mass = 1.0f;
    
    model = 0;
    
    GravityUse = true;
    VelocityUse = true;
    ForceUse = true;
    CollisionUse = true;
    
    CollisionDown = false;
    CollisionUp = false;
    CollisionSide = false;
    
    ColliderDownX = NULL;
    ColliderUpX = NULL;
}

AABB::~Object()
{
    bpos.Set( 0.0f, 0.0f, 0.0f );
    pos.Set( 0.0f, 0.0f, 0.0f );
    velocity.Set( 0.0f, 0.0f, 0.0f );
    force.Set( 0.0f, 0.0f, 0.0f );
    size.Set( 0.0f, 0.0f, 0.0f );
    
    mass = 0.0f;
    
    model = 0;
    
    GravityUse = true;
    VelocityUse = true;
    ForceUse = true;
    CollisionUse = true;
    
    CollisionDown = false;
    CollisionUp = false;
    CollisionSide = false;
    
    delete ColliderDownX;
    ColliderDownX = NULL;
    delete ColliderUpX;
    ColliderUpX = NULL;
}



