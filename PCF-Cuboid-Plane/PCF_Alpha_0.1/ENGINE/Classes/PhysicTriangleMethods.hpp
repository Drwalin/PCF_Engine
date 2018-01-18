

FLOATING_VALUES_TYPE PhysicTriangle::GetMinX()
{
    FLOATING_VALUES_TYPE value;
    value = tri[0].vector[0];
    if( tri[1].vector[0] < value )
        value = tri[1].vector[0];
    if( tri[2].vector[0] < value )
        value = tri[2].vector[0];
    return value;
}
FLOATING_VALUES_TYPE PhysicTriangle::GetMinY()
{
    FLOATING_VALUES_TYPE value;
    value = tri[0].vector[1];
    if( tri[1].vector[1] < value )
        value = tri[1].vector[1];
    if( tri[2].vector[1] < value )
        value = tri[2].vector[1];
    return value;
}
FLOATING_VALUES_TYPE PhysicTriangle::GetMinZ()
{
    FLOATING_VALUES_TYPE value;
    value = tri[0].vector[2];
    if( tri[1].vector[2] < value )
        value = tri[1].vector[2];
    if( tri[2].vector[2] < value )
        value = tri[2].vector[2];
    return value;
}
FLOATING_VALUES_TYPE PhysicTriangle::GetMaxX()
{
    FLOATING_VALUES_TYPE value;
    value = tri[0].vector[0];
    if( tri[1].vector[0] > value )
        value = tri[1].vector[0];
    if( tri[2].vector[0] > value )
        value = tri[2].vector[0];
    return value;
}
FLOATING_VALUES_TYPE PhysicTriangle::GetMaxY()
{
    FLOATING_VALUES_TYPE value;
    value = tri[0].vector[1];
    if( tri[1].vector[1] > value )
        value = tri[1].vector[1];
    if( tri[2].vector[1] > value )
        value = tri[2].vector[1];
    return value;
}
FLOATING_VALUES_TYPE PhysicTriangle::GetMaxZ()
{
    FLOATING_VALUES_TYPE value;
    value = tri[0].vector[2];
    if( tri[1].vector[2] > value )
        value = tri[1].vector[2];
    if( tri[2].vector[2] > value )
        value = tri[2].vector[2];
    return value;
}







void PhysicTriangle::CalculateNormal()
{
	float radian=0.0f;
	
	Vector _v_ector[2];
	
    /*
	_v_ector[0].CreateVector( tri[0], tri[1] );
	_v_ector[1].CreateVector( tri[1], tri[2] );
	
	normal = _v_ector[0] && _v_ector[0];   // wykonanie iloczynu wektorowego
	normal.Normalize();
	*/
	
	_v_ector[0].vector[0] = tri[0].vector[0] - tri[1].vector[0];
	_v_ector[0].vector[1] = tri[0].vector[1] - tri[1].vector[1];
	_v_ector[0].vector[2] = tri[0].vector[2] - tri[1].vector[2];
	_v_ector[1].vector[0] = tri[1].vector[0] - tri[2].vector[0];
	_v_ector[1].vector[1] = tri[1].vector[1] - tri[2].vector[1];
	_v_ector[1].vector[2] = tri[1].vector[2] - tri[2].vector[2];

	normal.vector[0] = _v_ector[0].vector[1]*_v_ector[1].vector[2] - _v_ector[0].vector[2]*_v_ector[1].vector[1];
	normal.vector[1] = _v_ector[0].vector[2]*_v_ector[1].vector[0] - _v_ector[0].vector[0]*_v_ector[1].vector[2];
	normal.vector[2] = _v_ector[0].vector[0]*_v_ector[1].vector[1] - _v_ector[0].vector[1]*_v_ector[1].vector[0];
	
	radian = sqrt( normal.vector[0]*normal.vector[0] + normal.vector[1]*normal.vector[1] + normal.vector[2]*normal.vector[2] );
	
	normal.vector[0] = normal.vector[0] / radian;
	normal.vector[1] = normal.vector[1] / radian;
	normal.vector[2] = normal.vector[2] / radian;
	
}


void PhysicTriangle::CalculateDet()
{
    det = 0 - ( (tri[0].vector[0]*normal[0]) + (tri[0].vector[1]*normal[1]) + (tri[0].vector[2]*normal[2]) );
    cout << endl<<det;
}


PhysicTriangle::PhysicTriangle()
{
    tri[0].vector[0] = 0.0f;
    tri[0].vector[1] = 0.0f;
    tri[0].vector[2] = 0.0f;
    tri[1].vector[0] = 10.0f;
    tri[1].vector[1] = 1.0f;
    tri[1].vector[2] = 0.0f;
    tri[2].vector[0] = 0.0f;
    tri[2].vector[1] = 1.0f;
    tri[2].vector[2] = 10.0f;
    
    image[0][0] = 0.0f;
    image[0][1] = 0.0f;
    image[1][0] = 1.0f;
    image[1][1] = 0.0f;
    image[2][0] = 1.0f;
    image[2][1] = 1.0f;
    
    normal.vector[0] = 0.0f;
    normal.vector[1] = 0.0f;
    normal.vector[2] = 0.0f;
    
    det = 0.0f;
    
    texture = 0; 
}
