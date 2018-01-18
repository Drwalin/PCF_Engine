


#include"LoadModel.cpp"
#include"Draw.cpp"



inline void GraphicModel::Init( char * texturename )
{
	VBO.SetTexture( texturename );
	VBO.Generate();
}



GraphicModel::GraphicModel()
{
	name = NULL;
	loaded = false;
}

GraphicModel::~GraphicModel()
{
	if( name != NULL )
		delete[] name;
	loaded = false;
}


