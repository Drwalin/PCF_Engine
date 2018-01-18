




class FireParticle
{
public:
    int ParticleNumber;
    Vector * particles;
    int * particleslive;
    Vector velocity;
    Vector Source;
    
    void Set( int number, Vector pos, Vector direction );
    void Update( float FrameTime );
    void Draw();
    
    FireParticle();
    ~FireParticle();
};
