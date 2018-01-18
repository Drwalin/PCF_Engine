

FLOATING_VALUES_TYPE PhysicTriangle::GetMinX()
{
    FLOATING_VALUES_TYPE value;
    value = tri[0].vertex[0];
    if( tri[1].vertex[0] < value )
        value = tri[1].vertex[0];
    if( tri[2].vertex[0] < value )
        value = tri[2].vertex[0];
    return value;
}
FLOATING_VALUES_TYPE PhysicTriangle::GetMinY()
{
    FLOATING_VALUES_TYPE value;
    value = tri[0].vertex[1];
    if( tri[1].vertex[1] < value )
        value = tri[1].vertex[1];
    if( tri[2].vertex[1] < value )
        value = tri[2].vertex[1];
    return value;
}
FLOATING_VALUES_TYPE PhysicTriangle::GetMinZ()
{
    FLOATING_VALUES_TYPE value;
    value = tri[0].vertex[2];
    if( tri[1].vertex[2] < value )
        value = tri[1].vertex[2];
    if( tri[2].vertex[2] < value )
        value = tri[2].vertex[2];
    return value;
}
FLOATING_VALUES_TYPE PhysicTriangle::GetMaxX()
{
    FLOATING_VALUES_TYPE value;
    value = tri[0].vertex[0];
    if( tri[1].vertex[0] > value )
        value = tri[1].vertex[0];
    if( tri[2].vertex[0] > value )
        value = tri[2].vertex[0];
    return value;
}
FLOATING_VALUES_TYPE PhysicTriangle::GetMaxY()
{
    FLOATING_VALUES_TYPE value;
    value = tri[0].vertex[1];
    if( tri[1].vertex[1] > value )
        value = tri[1].vertex[1];
    if( tri[2].vertex[1] > value )
        value = tri[2].vertex[1];
    return value;
}
FLOATING_VALUES_TYPE PhysicTriangle::GetMaxZ()
{
    FLOATING_VALUES_TYPE value;
    value = tri[0].vertex[2];
    if( tri[1].vertex[2] > value )
        value = tri[1].vertex[2];
    if( tri[2].vertex[2] > value )
        value = tri[2].vertex[2];
    return value;
}







void PhysicTriangle::CalculateNormal()
{
	FLOATING_VALUES_TYPE radian=0.0f;
	
	Vertex vector[2];
	vector[0].vertex[0] = tri[0].vertex[0] - tri[1].vertex[0];
	vector[0].vertex[1] = tri[0].vertex[1] - tri[1].vertex[1];
	vector[0].vertex[2] = tri[0].vertex[2] - tri[1].vertex[2];
	vector[1].vertex[0] = tri[1].vertex[0] - tri[2].vertex[0];
	vector[1].vertex[1] = tri[1].vertex[1] - tri[2].vertex[1];
	vector[1].vertex[2] = tri[1].vertex[2] - tri[2].vertex[2];

	normal.vertex[0] = vector[0].vertex[1]*vector[1].vertex[2] - vector[0].vertex[2]*vector[1].vertex[1];
	normal.vertex[1] = vector[0].vertex[2]*vector[1].vertex[0] - vector[0].vertex[0]*vector[1].vertex[2];
	normal.vertex[2] = vector[0].vertex[0]*vector[1].vertex[1] - vector[0].vertex[1]*vector[1].vertex[0];
	
	radian = sqrt( normal.vertex[0]*normal.vertex[0] + normal.vertex[1]*normal.vertex[1] + normal.vertex[2]*normal.vertex[2] );
	
	normal.vertex[0] = normal.vertex[0] / radian;
	normal.vertex[1] = normal.vertex[1] / radian;
	normal.vertex[2] = normal.vertex[2] / radian;
}


void PhysicTriangle::CalculateDet()
{
    det = 0 - ( (tri[0].vertex[0]*normal.vertex[0]) + (tri[0].vertex[1]*normal.vertex[1]) + (tri[0].vertex[2]*normal.vertex[2]) );
}


PhysicTriangle::PhysicTriangle()
{
    tri[0].vertex[0] = 0.0f;
    tri[0].vertex[1] = 0.0f;
    tri[0].vertex[2] = 0.0f;
    tri[1].vertex[0] = 10.0f;
    tri[1].vertex[1] = 1.0f;
    tri[1].vertex[2] = 0.0f;
    tri[2].vertex[0] = 0.0f;
    tri[2].vertex[1] = 1.0f;
    tri[2].vertex[2] = 10.0f;
    
    image[0][0] = 0.0f;
    image[0][1] = 0.0f;
    image[1][0] = 1.0f;
    image[1][1] = 0.0f;
    image[2][0] = 1.0f;
    image[2][1] = 1.0f;
    
    normal.vertex[0] = 0.0f;
    normal.vertex[1] = 0.0f;
    normal.vertex[2] = 0.0f;
    
    det = 0.0f;
    
    texture = 0; 
}
