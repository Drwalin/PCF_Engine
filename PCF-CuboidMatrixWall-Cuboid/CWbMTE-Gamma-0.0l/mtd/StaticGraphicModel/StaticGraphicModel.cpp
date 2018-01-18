


#include"LoadModel.cpp"
#include"Draw.cpp"



inline void StaticGraphicModel::Init( char * modelpath, unsigned int texture, Vector scale )
{
	VBO.SetTexture( texture );
	LoadModel( modelpath, scale );
	VBO.Generate();
}



inline void StaticGraphicModel::Init( char * modelpath, unsigned int texture )
{
	VBO.SetTexture( texture );
	LoadModel( modelpath );
	VBO.Generate();
}


inline void StaticGraphicModel::Delete()
{
	VBO.Delete();
	loaded = false;
	if( name != NULL )
		delete[] name;
}

StaticGraphicModel::StaticGraphicModel()
{
	loaded = false;
	name = NULL;
}

StaticGraphicModel::~StaticGraphicModel()
{
	loaded = false;
//	if( name != NULL )
//		delete[] name;
}


