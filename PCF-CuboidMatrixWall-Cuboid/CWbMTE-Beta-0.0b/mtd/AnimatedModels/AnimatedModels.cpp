


#include"Load.cpp"
#include"Draw.cpp"

AnimatedGraphicModel::AnimatedGraphicModel()
{
	name = NULL;
}

AnimatedGraphicModel::~AnimatedGraphicModel()
{
	if( name != NULL )
		delete[] name;
	texture.Delete();
	frame.resize( 0 );
}


