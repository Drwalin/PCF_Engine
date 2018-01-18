




class Particle
{
public:
    Vector possition;
    Vector velocity;
    float rotate;   // in rad's
    float size;
    Vector gravity;
    
    float life;
    float lifebeggin;
    
    unsigned int texture;
    
    Particle * next;
    
    inline void DestroyAll();
    inline Particle * Update( float FrameTime );
    inline void Draw( float * looky, float * lookxz, Vector * move );
    
    Particle( Vector src, Vector speed, Vector gravitysrc, float sizeb, float lifeb, unsigned int textureid );
    ~Particle();
};

class OperateParticles
{
public:
    
    Particle * particle;
    
    inline void DestroyParticles();
    
    inline void AddParticles( Vector src, Vector direction, Vector gravity, float velocity, float velocitydifference, int number, float life, float lifedifference, unsigned int texture );
    
    inline void Update( float FrameTime );
    inline void Draw( float * looky, float * lookxz, Vector * move );
    
    OperateParticles();
    ~OperateParticles();
};
