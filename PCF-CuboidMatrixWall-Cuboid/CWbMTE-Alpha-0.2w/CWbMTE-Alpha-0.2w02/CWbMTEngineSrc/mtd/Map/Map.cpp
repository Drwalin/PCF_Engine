


#include"Draw.cpp"

#include"UpdateColliders.cpp"
#include"Update.cpp"

#include"RayCollision.cpp"



Map::Map()
{
	
	NumberOfChunks[0] = 128;
	NumberOfChunks[1] = 128;
	maximumnumberofcolliders[0] = NumberOfChunks[0] * X_COLLIDERS_NUMBER;
	maximumnumberofcolliders[0] = NumberOfChunks[1] * Z_COLLIDERS_NUMBER;
	
	triPHYS.resize( 0 );
	
	staticobject.resize( 0 );
	
	int CameraObject = 1;
	
	Gravity = -9.81f;
	AirResistance = 0.0f;
	
	
	lightnings = NULL;
	NumberOfLightnings = 0;
}

Map::~Map()
{
	
	
	
	triPHYS.resize( 0 );
	
	staticobject.resize( 0 );
	
	int CameraObject = 0;
	
	Gravity = 0.0f;
	AirResistance = 0.0f;
	
	graphicObjects.resize( 0 );
}

