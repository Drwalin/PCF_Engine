


class DustParticles
{
public:
    int ParticleNumber;
    Vector * particles;
    Vector * velocity;
    
    void RandPossition();
    void RandVelocity();
    void SetParticles( int number );
    void Update( float FrameTime );
    void DrawInPoint( Vector pos );
    
    DustParticles();
    ~DustParticles();
};
