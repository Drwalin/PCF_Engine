


class TriangleSTGX
{
public:
    unsigned int vertexnumber;
    Vector * vertex;
    float * texcoordx;
    float * texcoordy;
    unsigned int texture;
    
    inline void Draw( unsigned int textureid );
    TriangleSTGX();
    ~TriangleSTGX();
};
