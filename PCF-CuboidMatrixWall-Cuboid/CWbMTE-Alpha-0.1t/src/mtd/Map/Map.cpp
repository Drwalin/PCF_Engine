




#include"UpdateColliders.cpp"




#include"RayCollision.cpp"

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
	
	
//	glBegin( GL_TRIANGLES );
//	for( int i = 0; i < triTEXT.size(); i++ )
//	{
//		triTEXT[i].Draw();
//	}
//	glEnd();
	
	int i;
	for( i = 0; i < vbotex.size(); i++ )
		vbotex[i].Draw();
	for( i = 0; i < vbocol.size(); i++ )
		vbocol[i].Draw();
	
    /*
	glDisable( GL_BLEND );
    glDisable( GL_TEXTURE_2D );
    
    glColor3f( 0.5f, 0.5f, 0.5f );
    glLineWidth( 1.0f );
    glBegin( GL_LINES );
    for( int x = 0; x < maxiumumnumberoftrianglescolliders[0]; x+=1 )
    {
    	for( int z = 0; z < maxiumumnumberoftrianglescolliders[1]; z+=1 )
	    {
			for( int i = 0; i < colliderter[x][z].tri.size(); i++ )
			{
				glVertex3fv( &((colliderter[x][z].tri[i]->vertex[0])[0]) );
				glVertex3fv( &((colliderter[x][z].tri[i]->vertex[1])[0]) );
				glVertex3fv( &((colliderter[x][z].tri[i]->vertex[1])[0]) );
				glVertex3fv( &((colliderter[x][z].tri[i]->vertex[2])[0]) );
				glVertex3fv( &((colliderter[x][z].tri[i]->vertex[2])[0]) );
				glVertex3fv( &((colliderter[x][z].tri[i]->vertex[0])[0]) );
			}
		}
	}
	glEnd();
	*/
	
	
    
    
    TrianglePX * triangle;
    PhysicModelStatic * object;
	
	{
		engineInstantiation->map.staticobject[1].see[0] += 0.1f;
		
		VMatrix matrix;
		matrix.InitEmpty();
		matrix.RotateY( (engineInstantiation->map.staticobject[1].see[0]+90.0f) );
		matrix.RotateX( -(engineInstantiation->map.staticobject[1].see[1]) );
		engineInstantiation->SegmentCollision(
							engineInstantiation->map.staticobject[1].pos+(engineInstantiation->map.staticobject[1].aabb[0].size*SetVector(0.5f,0.8f,0.5f)),
							engineInstantiation->map.staticobject[1].pos+(engineInstantiation->map.staticobject[1].aabb[0].size*SetVector(0.5f,0.8f,0.5f)) + matrix.GetVertex( SetVector( 0.0f, 0.0f, 20.0f ) ),
							&object, &triangle, &(engineInstantiation->map.staticobject[1]) );
		glDepthFunc( GL_LESS );
		glLineWidth( 5.0f );
		glBegin( GL_LINES );
			glColor3f( 1.0f, 0.1f, 0.1f );
			glVertex3fv( &( ( engineInstantiation->map.staticobject[1].pos+(engineInstantiation->map.staticobject[1].aabb[0].size*SetVector(0.5f,0.8f,0.5f)) )[0] ) );
			glVertex3fv( &( ( engineInstantiation->map.staticobject[1].pos+(engineInstantiation->map.staticobject[1].aabb[0].size*SetVector(0.5f,0.8f,0.5f)) + matrix.GetVertex( SetVector( 0.0f, 0.0f, 20.0f ) ) )[0] ) );
		glEnd();
		
		
		
		
		
		matrix.InitEmpty();
		matrix.RotateY( (engineInstantiation->map.staticobject[0].see[0]+90.0f) );
		matrix.RotateX( -(engineInstantiation->map.staticobject[0].see[1]) );
		engineInstantiation->SegmentCollision(
							engineInstantiation->map.staticobject[0].pos+(engineInstantiation->map.staticobject[0].aabb[0].size*SetVector(0.5f,0.9f,0.5f)),
							engineInstantiation->map.staticobject[0].pos+(engineInstantiation->map.staticobject[0].aabb[0].size*SetVector(0.5f,0.9f,0.5f)) + matrix.GetVertex( SetVector( 0.0f, 0.0f, 50.0f ) ),
							&object, &triangle, &(engineInstantiation->map.staticobject[0]) );
	/*	glDepthFunc( GL_LESS );
		glLineWidth( 5.0f );
		glBegin( GL_LINES );
			glColor3f( 1.0f, 0.1f, 0.1f );
			glVertex3fv( &( ( engineInstantiation->map.staticobject[0].pos+(engineInstantiation->map.staticobject[0].aabb[0].size*SetVector(0.5f,0.9f,0.5f)) )[0] ) );
			glVertex3fv( &( ( engineInstantiation->map.staticobject[0].pos+(engineInstantiation->map.staticobject[0].aabb[0].size*SetVector(0.5f,0.9f,0.5f)) + matrix.GetVertex( SetVector( 0.0f, 0.0f, 20.0f ) ) )[0] ) );
		glEnd();*/
	}
	
	
	if( triangle != NULL )
	{
//		printf( "\n %i", triangle );
		glLineWidth( 45.0f );
		glColor3f( 1.0f, 0.2f, 0.2f );
		glBegin( GL_LINE_LOOP );
			glVertex3fv( &((triangle->vertex[0])[0]) );
			glVertex3fv( &((triangle->vertex[1])[0]) );
			glVertex3fv( &((triangle->vertex[2])[0]) );
		glEnd();
	}
	
	
	glEnable( GL_BLEND );
	glEnable( GL_TEXTURE_2D );
	
	
	particles.Draw();
	
	
	glDisable( GL_BLEND );
	glDisable( GL_TEXTURE_2D );

	glLineWidth(10.0);
	
	glDepthFunc( GL_LESS );
	
	glBegin( GL_LINES );
		
		
		for( i = 0; i < staticobject.size(); i++ )
		{
			glColor3ub( 255, 255, 255 );
			
			if( object != NULL )
				if( staticobject[i].pos == object->pos )
					glColor3ub( 255, 35, 35 );
		
			glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(0) + staticobject[i].pos )[0] ) );
			glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(1) + staticobject[i].pos )[0] ) );
			
			glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(1) + staticobject[i].pos )[0] ) );
			glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(2) + staticobject[i].pos )[0] ) );
			
			glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(2) + staticobject[i].pos )[0] ) );
			glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(3) + staticobject[i].pos )[0] ) );
			
			glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(3) + staticobject[i].pos )[0] ) );
			glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(0) + staticobject[i].pos )[0] ) );
			
			glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(4) + staticobject[i].pos )[0] ) );
			glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(5) + staticobject[i].pos )[0] ) );
			
			glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(5) + staticobject[i].pos )[0] ) );
			glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(6) + staticobject[i].pos )[0] ) );
			
			glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(6) + staticobject[i].pos )[0] ) );
			glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(7) + staticobject[i].pos )[0] ) );
			
			glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(7) + staticobject[i].pos )[0] ) );
			glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(4) + staticobject[i].pos )[0] ) );
			
			glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(0) + staticobject[i].pos )[0] ) );
			glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(4) + staticobject[i].pos )[0] ) );
			
			glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(1) + staticobject[i].pos )[0] ) );
			glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(5) + staticobject[i].pos )[0] ) );
			
			glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(2) + staticobject[i].pos )[0] ) );
			glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(6) + staticobject[i].pos )[0] ) );
			
			glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(3) + staticobject[i].pos )[0] ) );
			glVertex3fv( &( ( staticobject[i].aabb[0].GetVertex(7) + staticobject[i].pos )[0] ) );
		}
		
	glEnd();
	
    glEnable( GL_BLEND );
    glEnable( GL_TEXTURE_2D );
	
	
	
	for( i = 0; i < engineInstantiation->GraphicModels.size(); i++ )
	{
		glTranslatef( 0.0f, 50.0f, 0.0f );
		engineInstantiation->GraphicModels[i].Draw();
		glTranslatef( 0.0f, -50.0f, 0.0f );
	}
	
	glDepthFunc( GL_ALWAYS );
	
	glLoadIdentity();
}

Map::Map()
{
	maxiumumnumberoftrianglescolliders[0] = 14;
	maxiumumnumberoftrianglescolliders[1] = 14;
	maxiumumnumberofobjectcolliders[0] = 64;
	maxiumumnumberofobjectcolliders[1] = 64;
	
	colliderter = NULL;
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

