


#define G_MODEL_COLOR 0
#define G_MODEL_NEXT_VERTEX 1
#define G_MODEL_TEXTURE 2

#define G_MODEL_BEGIN_TRIANGLE 3
#define G_MODEL_BEGIN_QUAD 4
#define G_MODEL_BEGIN_POLYGON 5

#define G_MODEL_END 6



inline void GraphicModel::Draw()
{
	VBO.Draw();
	
	
	/*
	int i = 0;
	int NumberOfVertex = ((int)VertexSize)*3;
	float * vertex = new float[NumberOfVertex];
	
	for( i = 0; i < NumberOfVertex; i++ )	// calc vertexes
		*(vertex+i) = size[i%3] * ((float)(scale[i])) / 256.0f;
	
	for( i = 0; i < DataSize; i++ )
	{
		switch( (int)(*(data+i)) )		// check what 
		{
		case G_MODEL_COLOR:
			glColor3ubv( (GLubyte*)(data+i+1) );
			i += 4;
			break;
		
		case G_MODEL_TEXTURE:
			( (Texture*) (texture+((int)(*(data+i+1)))) ) -> Bind();
			i++;
			break;
		
		case G_MODEL_BEGIN_TRIANGLE:
			glBegin( GL_TRIANGLES );
			break;
		
		case G_MODEL_BEGIN_QUAD:
			glBegin( GL_QUADS );
			break;
		
		case G_MODEL_BEGIN_POLYGON:
			glBegin( GL_POLYGON );
			break;
		
		case G_MODEL_NEXT_VERTEX:
			glTexCoord2f( ((float)(*(data+i+2)))/256.0f, ((float)(*(data+i+3)))/256.0f );
			glVertex3fv( (vertex+(((int)(*(data+i+1)))*3)) );
			i += 4;
			break;
		
		case G_MODEL_END:
			glEnd();
			break;
		
		default:
			continue;
		}
	}
	delete[] vertex;
	*/
}


#undef G_MODEL_COLOR
#undef G_MODEL_NEXT_VERTEX
#undef G_MODEL_TEXTURE

#undef G_MODEL_BEGIN_TRIANGLE
#undef G_MODEL_BEGIN_QUAD
#undef G_MODEL_BEGIN_POLYGON

#undef G_MODEL_END

