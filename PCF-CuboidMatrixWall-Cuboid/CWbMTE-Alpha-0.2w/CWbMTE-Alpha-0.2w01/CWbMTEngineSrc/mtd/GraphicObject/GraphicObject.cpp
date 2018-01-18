


inline void GraphicObject::Draw()
{
	if( model == NULL )
		return;
	
//	glTexEnvf( GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE );
	
	glTranslatef( pos[0], pos[1]+(scale*0.49f), pos[2] );
	glRotatef(  rotate[1], 0.0f, 1.0f, 0.0f );
	
	glScalef( scale, scale, scale );
	model -> Draw();
	glScalef( 1.0f/scale, 1.0f/scale, 1.0f/scale );
	
	glRotatef( -rotate[1], 0.0f, 1.0f, 0.0f );
	glTranslatef( -pos[0], -pos[1]-(scale*0.49f), -pos[2] );
}

inline void GraphicObject::SetModel( StaticGraphicModel * src )
{
	model = src;
}

inline void GraphicObject::SetScale( float src )
{
	scale = src;
}

inline void GraphicObject::SetPos( Vector src )
{
	pos = src;
}

inline void GraphicObject::SetRotate( float s1, float s2, float s3 )
{
	rotate.Set( s1, s2, s3 );
}

GraphicObject::GraphicObject()
{
	model = NULL;
	pos.Set( 0.0f, 0.0f, 0.0f );
	scale = 0.5f;
	rotate.Set( 0.0f, 0.0f, 0.0f );
}

GraphicObject::~GraphicObject()
{
	model = NULL;
	pos.Set( 0.0f, 0.0f, 0.0f );
	scale = 0.5f;
	rotate.Set( 0.0f, 0.0f, 0.0f );
}


