



inline void Particle::DestroyAll()
{
    if( next != NULL )
    {
        next -> DestroyAll();
    }
    delete this;
}

inline void Particle::Draw( float * looky, float * lookxz, Vector * move )
{
    if( next != NULL )
    {
        next -> Draw( looky, lookxz, move );
    }
    
    glLoadIdentity();
    glRotatef( -*looky, 1.0f, 0.0f, 0.0f );
    glRotatef( -(*lookxz-90.0f), 0.0f, 1.0f, 0.0f );
    glTranslatef( -(*move[0]-*possition[0]), -(*move[1]-*possition[1]), -(*move[2]-*possition[2]) );
    glRotatef( (*lookxz-90.0f), 0.0f, 1.0f, 0.0f );
    glRotatef( *looky, 1.0f, 0.0f, 0.0f );
    glRotatef( rotate, 0.0f, 0.0f, 1.0f );
    
    float texcoord[2][2];
    float postex = ((life / lifebeggin) * 16.0f) + 0.5;
    int postexi = int(postex);
    texcoord[0][0] =   float(int(postex/4)) / 4.0f;
    texcoord[0][1] = ( float(int(postex/4)) / 4.0f) + 0.0625f;    // 0.0625 = 1/16
    texcoord[1][0] = ( float    (postex  )  % 4   ) /   16.0f;
    texcoord[1][1] = ((float    (postex  )  % 4)+1) /   16.0f;
    
    glBindTexture( GL_TEXTURE_2D, texture );
        
        glBegin( GL_QUADS );
        	glTexCoord2f( texcoord[0][0], texcoord[1][0] );
                glVertex3f( -size, -size, 0.0 );
        	glTexCoord2f( texcoord[0][0], texcoord[1][1] );
                glVertex3f( -size,  size, 0.0 );
        	glTexCoord2f( texcoord[0][1], texcoord[1][1] );
                glVertex3f(  size,  size, 0.0 );
        	glTexCoord2f( texcoord[0][1], texcoord[1][0] );
                glVertex3f(  size, -size, 0.0 );
        glEnd();
}

inline Particle * Particle::Update( float FrameTime )
{
    if( next != NULL )
    {
        next -> Update;
    }
    else
    {
        next = NULL;
    }
    life -= FrameTime;
    if( life <= 0.0f )
    {
        Particle * fast = next;
        delete * this;
        return fast;
    }
    velocity += ( gravity * FrameTime );
    possition += ( velocity * FrameTime );
    rotate += M_PI*FrameTime*0.09f;
    size *= ( sin( FrameTime ) + 1.0f);
    return this;
}

Particle::Particle( Vector src, Vector speed, Vector gravitysrc, float sizeb, float lifeb, unsigned int textureid )
{
    possition = src;
    velocity = speed;
    rotate = float(rand()%3600000)*0.01f;
    size = sizeb;
    gravity = gravitysrc;
    
    life = lifeb;
    lifebeggin = lifeb;
    
    texture = textureid;
    
    next = NULL;
}

Particle::~Particle()
{
    possition.Set( 0.0f, 0.0f, 0.0f );
    velocity.Set( 0.0f, 0.0f, 0.0f );
    rotate = 0.0f;
    size = 0.0f;
    gravity = 0.0f;
    
    life = 0.0f;
    lifebeggin = 0.0f;
    
    texture = 0;
    
    next = NULL;
}





class OperateParticles
{
public:
    
    Particle * particle;
    
    
    OperateParticles();
    ~OperateParticles();
};

inline void OperateParticles::DestroyParticles()
{
    if( particle != NULL )
    {
        particle -> DestroyAll();
    }
}

inline void OperateParticles::Update( float FrameTime )
{
    if( particle != NULL )
    {
        particle -> Update( FrameTime );
    }
}

inline void OperateParticles::AddParticles( Vector src, Vector direction, Vector gravity, float velocity, float velocitydifference, int number, float life, float lifedifference, unsigned int texture, float size )
{
    if( i <= 0 )
    {
        return;
    }
    
    Vector speed;
    
    direction.Normalize();
    //velocity *= 1000.0f;
    velocitydifference *= 1000.0f;
    
    life *= 1000.0f;
    lifedifference *= 1000.0f;
    
    Particle * newparticlebeggin = NULL;
    Particle * newparticleactually = NULL;
    
    for( int i = 0; i < number; i++ )
    {
        speed.Set( direction[0]*velocity + ( ( float(rand()%(int)velocitydifference) - (velocitydifference/2.0f) ) * 0.001f ),
                   direction[1]*velocity + ( ( float(rand()%(int)velocitydifference) - (velocitydifference/2.0f) ) * 0.001f ),
                   direction[2]*velocity + ( ( float(rand()%(int)velocitydifference) - (velocitydifference/2.0f) ) * 0.001f ) );
        if( newparticlebeggin != NULL )
        {
            newparticleactually -> next = new Particle( src, speed, gravity, size + float((rand()%200)-100)*0.01f, texture );
            newparticleactually = newparticleactually -> next;
        }
        else
        {
            newparticlebeggin = new Particle( src, speed, gravity, size + float((rand()%200)-100)*0.01f, texture );
            newparticleactually = newparticlebeggin;
        }
    }
    newparticleactually -> next = particle;
    particle = newparticlebeggin;
}

inline void OperateParticles::Draw( float * looky, float * lookxz, Vector * move )
{
    if( particle != NULL )
    {
        particle -> Draw( looky, lookxz, move );
    }
}

OperateParticles::OperateParticles()
{
    particle = NULL;
}

OperateParticles::~OperateParticles()
{
    DestroyParticles();
    particle = NULL;
}
