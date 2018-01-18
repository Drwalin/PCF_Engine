


class ObjectPhysicalCuboid
{
public:
    Vector pos[2][2][2];
    Vector speed[2][2][2];
    Vector force[2][2][2];
    Vector barycenter;      // œrodek ciê¿koœci
    
    FLOATING_VALUES_TYPE mass;
    
    bool collision;
    
    int type;
    int id;
    int id_graphicmodel;
    NameLine64 name;
    
    //FLOATING_VALUES_TYPE
    float GetVertexMass( float a, float b, float c ){ return mass; };   // -
        // ró¿na masa w zale¿nosci od po³o¿enia wierzcho³ka wzgledem barycenrum ( œrodek ciê¿koœci )
    
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
        // type: 0-nie dodawaj, 1-si³a, 2-prêdkoœæ, 3-pozycja
        // point - wzglêdem pocz¹tku uk³adu wspó³rzêdnych (origin)
    
    ObjectPhysicalCuboid(){}                                            // -
};
