


#include"LoadModel.cpp"
#include"Draw.cpp"



GraphicModel::GraphicModel()
{
	texture = NULL;
	
	name = NULL;
	loaded = false;
	
	scale = NULL;
	VertexSize = 0;
	
	data = NULL;
	DataSize = 0;
}

GraphicModel::~GraphicModel()
{
	if( texture != NULL )
		delete[] texture;
	texture = NULL;
	
	if( name != NULL )
		delete[] name;
	name = NULL;
	
	loaded = false;
	
	if( scale != NULL )
		delete[] scale;
	scale = NULL;
	VertexSize = 0;
	
	if( data != NULL )
		delete[] data;
	data = NULL;
	
	DataSize = 0;
}
