



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
    
    glTranslatef( -((*move)[0]-
	(possition)[0]),
	 -((*move)[1]-
	 (possition)[1]), 
	 -((*move)[2]
	 -(possition)[2]) );
	 
    glRotatef( (*lookxz-90.0f), 0.0f, 1.0f, 0.0f );
    glRotatef( *looky, 1.0f, 0.0f, 0.0f );
    glRotatef( rotate, 0.0f, 0.0f, 1.0f );
    
    float texcoord[2][2];
    float postex = ((life / lifebeggin) * 16.0f) + 0.5;
    int postexi = int(postex);
    texcoord[0][0] =   float(int(postex/4)) / 4.0f;
    texcoord[0][1] = ( float(int(postex/4)) / 4.0f) + 0.0625f;    // 0.0625 = 1/16
    texcoord[1][0] = ( int      (postex  )  % 4   ) /   16.0f;
    texcoord[1][1] = ((int      (postex  )  % 4)+1) /   16.0f;
    
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
        next -> Update( FrameTime );
    }
    //else
    //{
        //next = NULL;
    //}
    life -= FrameTime;
    if( life <= 0.0f )
    {
        Particle * fast = next;
        delete this;
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
    gravity.Set( 0.0f, 0.0f, 0.0f );
    
    life = 0.0f;
    lifebeggin = 0.0f;
    
    texture = 0;
    
    next = NULL;
}






inline void OperateParticles::DestroyParticles()
{
    if( particle != NULL )
    {
        particle -> DestroyAll();
    }
}

inline void OperateParticles::Update( float FrameTime )
{
    //if( particle != NULL )
    //{
        //particle -> Update( FrameTime );
    //}
    
    Particle * object = particle;
    Particle * objectbefor = NULL;
    while( object != NULL )
    {
    	life -= FrameTime;
    	if( (object->life) <= 0.0f )
   		{
   			if( objectbefor == NULL )
   			{
   				particle = object -> next;
   				delete object;
   				object = particle;
   				continue;
   			}
   			else
   			{
   				objectbefore -> next = object -> next
   				delete object;
   				object = objectbefore -> next;
   				continue;
   			}
    	}
    	else
    	{
    		velocity *= (1.0f-FrameTime);
    		velocity += ( gravity * FrameTime );
    		possition += ( velocity * FrameTime );
    		rotate = (object->live)*M_PI/(2.0f*(object->lifebeggin));
    		size += sin( FrameTime*50.0f );
    		
    		objectbefore = object;
    		object = object -> next;
    	}
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
    //if( particle != NULL )
    //{
        //particle -> Draw( looky, lookxz, move );
    //}
    
    glLoadIdentity();
    glRotatef( -*looky, 1.0f, 0.0f, 0.0f );
    glRotatef( -(*lookxz-90.0f), 0.0f, 1.0f, 0.0f );
    glTranslatef( -(*move[0]-*possition[0]), -(*move[1]-*possition[1]), -(*move[2]-*possition[2]) );
    glRotatef( (*lookxz-90.0f), 0.0f, 1.0f, 0.0f );
    glRotatef( *looky, 1.0f, 0.0f, 0.0f );
    glRotatef( rotate, 0.0f, 0.0f, 1.0f );
    
    VMatrix verticesparticle;
    verticesparticle.InitEmpty();
    verticesparticle.RotateY( (*lookxz)-90.0f );
    verticesparticle.RotateX( *looky );
    
    
    Particle * object = particle;
    
    float texcoord[2][2];
    float postex;
    int postexi;
    Vertex particlevartex[4];
    while( object != NULL )
    {
    	
    	verticesparticle.RotateZ( object -> rotate );
    	
    	postex = ((life / lifebeggin) * 16.0f) + 0.5;
    	postexi = int(postex);
    	texcoord[0][0] =   float(int(postex/4)) / 4.0f;
    	texcoord[0][1] = ( float(int(postex/4)) / 4.0f) + 0.0625f;    // 0.0625 = 1/16
    	texcoord[1][0] = ( float    (postex  )  % 4   ) /   16.0f;
    	texcoord[1][1] = ((float    (postex  )  % 4)+1) /   16.0f;
    	
    	particlevartex[0] = verticesparticle.GetVertex( SetVector( -(object->size), -(object->size), 0.0f ) );
    	particlevartex[1] = verticesparticle.GetVertex( SetVector( -(object->size),  (object->size), 0.0f ) );
    	particlevartex[2] = verticesparticle.GetVertex( SetVector(  (object->size),  (object->size), 0.0f ) );
    	particlevartex[3] = verticesparticle.GetVertex( SetVector(  (object->size), -(object->size), 0.0f ) );
    	
    	glBindTexture( GL_TEXTURE_2D, texture );
        
        	glBegin( GL_QUADS );
        		glTexCoord2f( texcoord[0][0], texcoord[1][0] );
                	glVertex3fv( &(particlevartex[0]+(object->possition))[0] );
        		glTexCoord2f( texcoord[0][0], texcoord[1][1] );
                	glVertex3fv( &(particlevartex[1]+(object->possition))[0] );
        		glTexCoord2f( texcoord[0][1], texcoord[1][1] );
                	glVertex3fv( &(particlevartex[2]+(object->possition))[0] );
        		glTexCoord2f( texcoord[0][1], texcoord[1][0] );
                	glVertex3fv( &(particlevartex[3]+(object->possition))[0] );
        	glEnd();
        
    	verticesparticle.RotateZ( -(object -> rotate) );
    	object = object -> next;
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
