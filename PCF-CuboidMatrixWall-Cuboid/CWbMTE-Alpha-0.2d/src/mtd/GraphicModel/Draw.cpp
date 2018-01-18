


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
}


#undef G_MODEL_COLOR
#undef G_MODEL_NEXT_VERTEX
#undef G_MODEL_TEXTURE

#undef G_MODEL_BEGIN_TRIANGLE
#undef G_MODEL_BEGIN_QUAD
#undef G_MODEL_BEGIN_POLYGON

#undef G_MODEL_END

