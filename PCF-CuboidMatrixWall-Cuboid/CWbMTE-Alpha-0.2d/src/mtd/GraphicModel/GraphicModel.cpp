


#include"LoadModel.cpp"
#include"Draw.cpp"



inline void GraphicModel::Init( char * modelpath, char * texturepath, int type )
{
	VBO.SetTexture( texturepath, type );
	LoadModel( modelpath );
	VBO.Generate();
}



GraphicModel::GraphicModel()
{
	loaded = false;
}

GraphicModel::~GraphicModel()
{
	loaded = false;
}


