




class ObjectAlive
{
public:
    Vertex pos;
    Vertex speed;
    Vertex force;
    Vertex barycenter;
    
    FLOATING_VALUES_TYPE lookxz;
    FLOATING_VALUES_TYPE looky;
    
    FLOATING_VALUES_TYPE width;         // dla x i z
    FLOATING_VALUES_TYPE heightlegs;    // dla y
    FLOATING_VALUES_TYPE heightches;    // dla y
    FLOATING_VALUES_TYPE heighhead;     // dla y
    
    FLOATING_VALUES_TYPE mass;
    
    bool collision;
    bool collisiondown;
    bool collisionup;
    
    bool sneak;
    bool run;
    
    int type;
    int id;
    int id_graphicmodel;
    NameLine128 name;
    
    FLOATING_VALUES_TYPE GetMaxX();                     // +
    FLOATING_VALUES_TYPE GetMaxY();                     // +
    FLOATING_VALUES_TYPE GetMaxZ();                     // +
    FLOATING_VALUES_TYPE GetMinX();                     // +
    FLOATING_VALUES_TYPE GetMinY();                     // +
    FLOATING_VALUES_TYPE GetMinZ();                     // +
    
    Vertex GetMaxVertexWithVersor( Vertex * versor );   // +
    
    ObjectAlive();                                      // +
};








