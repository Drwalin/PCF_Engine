


class TrianglePX
{
public:
    Vector vertex[3];
    Vector normal;
    float det;
    float resistance;	// factor of resistance
    
    inline void Calculate();
    inline void ClosestPoint( Vector p );
    
    TrianglePX();
    ~TrianglePX();
};





