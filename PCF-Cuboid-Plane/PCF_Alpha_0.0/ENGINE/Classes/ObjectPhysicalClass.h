


class ObjectPhysicalCuboid
{
public:
    Vertex pos[2][2][2];
    Vertex speed[2][2][2];
    Vertex force[2][2][2];
    Vertex barycenter;
    
    FLOATING_VALUES_TYPE mass;
    
    bool collision;
    
    int type;
    int id;
    int id_graphicmodel;
    NameLine64 name;
    
    //FLOATING_VALUES_TYPE
    float GetMaxX(){return 0.0f;}                                       // -
    float GetMaxY(){return 0.0f;}                                       // -
    float GetMaxZ(){return 0.0f;}                                       // -
    float GetMinX(){return 0.0f;}                                       // -
    float GetMinY(){return 0.0f;}                                       // -
    float GetMinZ(){return 0.0f;}                                       // -
    
    Vertex GetMaxVertexWithVersor( Vertex * versor );                   // -
    
    void AddForceVectorInPoint( Vertex * point, Vertex * force );       // -
    void AddSpeedVectorInPoint( Vertex * point, Vertex * speed );       // -
    void AddVectorInPoint( int type, Vertex * point, Vertex * vector ); // -
        // type: 0-nie dodawaj, 1-si³a, 2-prêdkoœæ, 3-pozycja
        // point - wzglêdem pocz¹tku uk³adu wspó³rzêdnych (origin)
    
    ObjectPhysicalCuboid(){}                                            // -
};
