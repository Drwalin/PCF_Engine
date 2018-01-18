


#include"LoadModel.cpp"
#include"Draw.cpp"



inline void StaticGraphicModel::Init( char * modelpath, char * texturepath, int type )
{
	VBO.SetTexture( texturepath, type );
	LoadModel( modelpath );
	VBO.Generate();
}



StaticGraphicModel::StaticGraphicModel()
{
	loaded = false;
	name = NULL;
}

StaticGraphicModel::~StaticGraphicModel()
{
	loaded = false;
	if( name != NULL )
		delete[] name;
}


