


class TrianglePX
{
public:
    Vector vertex[3];
    Vector normal;
    float det;
    
    inline void Calculate();
    inline void ClosestPoint( Vector p );
    
    TrianglePX();
    ~TrianglePX();
};





