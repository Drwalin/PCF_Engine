


#include"Draw.cpp"

#include"UpdateColliders.cpp"
#include"Update.cpp"

#include"RayCollision.cpp"



Map::Map()
{
	maxiumumnumberoftrianglescolliders[0] = 14;
	maxiumumnumberoftrianglescolliders[1] = 14;
	maxiumumnumberofobjectcolliders[0] = 64;
	maxiumumnumberofobjectcolliders[1] = 64;
	
	colliderter = NULL;
	colliderobj = NULL;
	moveColliderTerrain[0] = 0.0f;
	moveColliderTerrain[1] = 0.0f;
	moveColliderObject[0] = 0.0f;
	moveColliderObject[1] = 0.0f;
	sizeColliderTerrain[0] = 0.0f;
	sizeColliderTerrain[1] = 0.0f;
	sizeColliderObject[0] = 0.0f;
	sizeColliderObject[1] = 0.0f;
	
	texture.resize( 0 );
	
	triPHYS.resize( 0 );
	triTEXT.resize( 0 );
	
	staticobject.resize( 0 );
	
	int CameraObject = 1;
	
	Gravity = -9.81f;
	AirResistance = 0.0f;
	
	
	lightnings = NULL;
	NumberOfLightnings = 0;
}

Map::~Map()
{
	maxiumumnumberoftrianglescolliders[0] = 0;
	maxiumumnumberoftrianglescolliders[1] = 0;
	maxiumumnumberofobjectcolliders[0] = 0;
	maxiumumnumberofobjectcolliders[1] = 0;
	
	if( colliderobj != NULL )
	{
		if( *colliderobj != NULL )
		{
			for( int x = 0; x < maxiumumnumberofobjectcolliders[0]; x++ )
			{
				delete[] *(colliderobj+x);
			}
			delete[] colliderobj;
		}
	}
	
	moveColliderTerrain[0] = 0.0f;
	moveColliderTerrain[1] = 0.0f;
	moveColliderObject[0] = 0.0f;
	moveColliderObject[1] = 0.0f;
	sizeColliderTerrain[0] = 0.0f;
	sizeColliderTerrain[1] = 0.0f;
	sizeColliderObject[0] = 0.0f;
	sizeColliderObject[1] = 0.0f;
	
	texture.resize( 0 );
	
	triPHYS.resize( 0 );
	triTEXT.resize( 0 );
	
	staticobject.resize( 0 );
	
	int CameraObject = 0;
	
	Gravity = 0.0f;
	AirResistance = 0.0f;
}

