




#include"UpdateColliders.cpp"






#include"Update.cpp"

void Map::Draw()
{
	glRotatef( -staticobject[0].see[1], 1.0f, 0.0f, 0.0f );
	glRotatef( -(staticobject[0].see[0]-90.0f), 0.0f, 1.0f, 0.0f );
	glTranslatef( -(staticobject[0].pos[0]+(staticobject[0].aabb[0].size[0]*0.5f)), -(staticobject[0].pos[1]+(staticobject[0].aabb[0].size[1]*0.9f)), -(staticobject[0].pos[2]+(staticobject[0].aabb[0].size[2]*0.5f)) );
	
	glColor3f( 1.0f, 1.0f, 1.0f );
	glEnable( GL_TEXTURE_2D );
	glDepthFunc( GL_LESS );
	
	texture[0].Bind();
	
	glBegin( GL_TRIANGLES );
	
	for( int i = 0; i < triTEXT.size(); i++ )
	{
		triTEXT[i].Draw();
	}
	
	glEnd();
	
	
    glDisable( GL_BLEND );
    glDisable( GL_TEXTURE_2D );
    
	glLineWidth(10.0);
	
	glBegin( GL_LINES );
		
		glColor3ub( 255, 255, 255 );
		
		glVertex3fv( &( ( staticobject[0].aabb[0].GetVertex(0) + staticobject[0].pos )[0] ) );
		glVertex3fv( &( ( staticobject[0].aabb[0].GetVertex(1) + staticobject[0].pos )[0] ) );
		
		glVertex3fv( &( ( staticobject[0].aabb[0].GetVertex(1) + staticobject[0].pos )[0] ) );
		glVertex3fv( &( ( staticobject[0].aabb[0].GetVertex(2) + staticobject[0].pos )[0] ) );
		
		glVertex3fv( &( ( staticobject[0].aabb[0].GetVertex(2) + staticobject[0].pos )[0] ) );
		glVertex3fv( &( ( staticobject[0].aabb[0].GetVertex(3) + staticobject[0].pos )[0] ) );
		
		glVertex3fv( &( ( staticobject[0].aabb[0].GetVertex(3) + staticobject[0].pos )[0] ) );
		glVertex3fv( &( ( staticobject[0].aabb[0].GetVertex(0) + staticobject[0].pos )[0] ) );
		
		glVertex3fv( &( ( staticobject[0].aabb[0].GetVertex(4) + staticobject[0].pos )[0] ) );
		glVertex3fv( &( ( staticobject[0].aabb[0].GetVertex(5) + staticobject[0].pos )[0] ) );
		
		glVertex3fv( &( ( staticobject[0].aabb[0].GetVertex(5) + staticobject[0].pos )[0] ) );
		glVertex3fv( &( ( staticobject[0].aabb[0].GetVertex(6) + staticobject[0].pos )[0] ) );
		
		glVertex3fv( &( ( staticobject[0].aabb[0].GetVertex(6) + staticobject[0].pos )[0] ) );
		glVertex3fv( &( ( staticobject[0].aabb[0].GetVertex(7) + staticobject[0].pos )[0] ) );
		
		glVertex3fv( &( ( staticobject[0].aabb[0].GetVertex(7) + staticobject[0].pos )[0] ) );
		glVertex3fv( &( ( staticobject[0].aabb[0].GetVertex(4) + staticobject[0].pos )[0] ) );
		
		glVertex3fv( &( ( staticobject[0].aabb[0].GetVertex(0) + staticobject[0].pos )[0] ) );
		glVertex3fv( &( ( staticobject[0].aabb[0].GetVertex(4) + staticobject[0].pos )[0] ) );
		
		glVertex3fv( &( ( staticobject[0].aabb[0].GetVertex(1) + staticobject[0].pos )[0] ) );
		glVertex3fv( &( ( staticobject[0].aabb[0].GetVertex(5) + staticobject[0].pos )[0] ) );
		
		glVertex3fv( &( ( staticobject[0].aabb[0].GetVertex(2) + staticobject[0].pos )[0] ) );
		glVertex3fv( &( ( staticobject[0].aabb[0].GetVertex(6) + staticobject[0].pos )[0] ) );
		
		glVertex3fv( &( ( staticobject[0].aabb[0].GetVertex(3) + staticobject[0].pos )[0] ) );
		glVertex3fv( &( ( staticobject[0].aabb[0].GetVertex(7) + staticobject[0].pos )[0] ) );
		
	glEnd();
	
    glEnable( GL_BLEND );
    glEnable( GL_TEXTURE_2D );
	
	for( int i = 0; i < engineInstantiation->GraphicModels.size(); i++ )
	{
		glTranslatef( 0.0f, -30.0f, 0.0f );
		engineInstantiation->GraphicModels[i].Draw( SetVector( 10.0f, 10.0f, 10.0f ) );
	}
	
	
	glLoadIdentity();
}

Map::Map()
{
	maxiumumnumberoftrianglescolliders[0] = 14;
	maxiumumnumberoftrianglescolliders[1] = 14;
	maxiumumnumberofobjectcolliders[0] = 64;
	maxiumumnumberofobjectcolliders[1] = 64;
	
	colliderter.Init( SetVector( -100.0f, -100.0f, -100.0f ) );
	colliderobj = NULL;
	moveColliderTerrain[0] = 0.0f;
	moveColliderTerrain[1] = 0.0f;
	moveColliderObject[0] = 0.0f;
	moveColliderObject[1] = 0.0f;
	sizeColliderTerrain[0] = 0.0f;
	sizeColliderTerrain[1] = 0.0f;
	sizeColliderObject[0] = 0.0f;
	sizeColliderObject[1] = 0.0f;
	
	texture.resize( 0 );
	model.resize( 0 );
	
	triPHYS.resize( 0 );
	triTEXT.resize( 0 );
	triSTRIP.resize( 0 );
	
	staticobject.resize( 0 );
	
	//ParticlesSystem.particle = NULL;
	
	int CameraObject = 1;
	
	Gravity = -9.81f;
	AirResistance = 0.0f;
}

Map::~Map()
{
	maxiumumnumberoftrianglescolliders[0] = 0;
	maxiumumnumberoftrianglescolliders[1] = 0;
	maxiumumnumberofobjectcolliders[0] = 0;
	maxiumumnumberofobjectcolliders[1] = 0;
	
	/*if( colliderter != NULL )
	{
		if( *colliderter != NULL )
		{
			for( int x = 0; x < maxiumumnumberoftrianglescolliders[0]; x++ )
			{
				delete[] *(colliderter+x);
			}
			delete[] colliderter;
		}
	}*/
	
	if( colliderobj != NULL )
	{
		if( *colliderobj != NULL )
		{
			for( int x = 0; x < maxiumumnumberofobjectcolliders[0]; x++ )
			{
				delete[] *(colliderobj+x);
			}
			delete[] colliderobj;
		}
	}
	
	moveColliderTerrain[0] = 0.0f;
	moveColliderTerrain[1] = 0.0f;
	moveColliderObject[0] = 0.0f;
	moveColliderObject[1] = 0.0f;
	sizeColliderTerrain[0] = 0.0f;
	sizeColliderTerrain[1] = 0.0f;
	sizeColliderObject[0] = 0.0f;
	sizeColliderObject[1] = 0.0f;
	
	texture.resize( 0 );
	model.resize( 0 );
	
	triPHYS.resize( 0 );
	triTEXT.resize( 0 );
	triSTRIP.resize( 0 );
	
	staticobject.resize( 0 );
	
	//if( ParticlesSystem.particle != NULL )
	//	delete[] ParticlesSystem.particle;
	
	int CameraObject = 0;
	
	Gravity = 0.0f;
	AirResistance = 0.0f;
}

