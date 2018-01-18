


#include"LoadModel.cpp"
#include"Draw.cpp"



inline void StaticGraphicModel::Init( char * modelpath, unsigned int texture, Vector scale )
{
	LoadModel( modelpath, scale );
	int i;
	for( i = 0; i < VBO.size(); ++i )
	{
		VBO[i].Generate();
	}
}



inline void StaticGraphicModel::Init( char * modelpath, unsigned int texture )
{
	LoadModel( modelpath );
	int i;
	for( i = 0; i < VBO.size(); ++i )
	{
		VBO[i].Generate();
	}
}


inline void StaticGraphicModel::Delete()
{
	int i;
	for( i = 0; i < VBO.size(); ++i )
		VBO[i].Delete();
	loaded = false;
	if( name != NULL )
		delete[] name;
	name = NULL;
}

StaticGraphicModel::StaticGraphicModel()
{
	loaded = false;
	name = NULL;
}

StaticGraphicModel::~StaticGraphicModel()
{
	loaded = false;
}


