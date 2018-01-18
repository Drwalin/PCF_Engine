


#include"LoadModel.cpp"
#include"Draw.cpp"



inline void StaticGraphicModel::Init( char * modelpath, unsigned int texture, Vector scale )
{
	VBO.SetTexture( texture );
	LoadModel( modelpath, scale );
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


