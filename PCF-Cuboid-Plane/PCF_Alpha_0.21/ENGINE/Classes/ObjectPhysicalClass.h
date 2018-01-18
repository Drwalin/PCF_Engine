


class ObjectPhysicalCuboid
{
public:
    Vector pos[2][2][2];
    Vector speed[2][2][2];
    Vector force[2][2][2];
    Vector barycenter;      // �rodek ci�ko�ci
    
    FLOATING_VALUES_TYPE mass;
    
    bool collision;
    
    int type;
    int id;
    int id_graphicmodel;
    NameLine64 name;
    
    //FLOATING_VALUES_TYPE
    float GetVertexMass( float a, float b, float c ){ return mass; };   // -
        // r�na masa w zale�nosci od po�o�enia wierzcho�ka wzgledem barycenrum ( �rodek ci�ko�ci )
    
    float GetMaxX(){return 0.0f;}                                       // -
    float GetMaxY(){return 0.0f;}                                       // -
    float GetMaxZ(){return 0.0f;}                                       // -
    float GetMinX(){return 0.0f;}                                       // -
    float GetMinY(){return 0.0f;}                                       // -
    float GetMinZ(){return 0.0f;}                                       // -
    
    Vector GetMaxVertexWithVersor( Vector versor ){}                    // -
    
    void AddForceVectorInPoint( Vector point, Vector _force ){}         // -
    void AddSpeedVectorInPoint( Vector point, Vector _speed ){}         // -
    void AddVectorInPoint( int type, Vector point, Vector vector ){}    // -
        // type: 0-nie dodawaj, 1-si�a, 2-pr�dko��, 3-pozycja
        // point - wzgl�dem pocz�tku uk�adu wsp�rz�dnych (origin)
    
    ObjectPhysicalCuboid(){}                                            // -
};
