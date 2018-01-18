


#include"Draw.cpp"

#include"UpdateColliders.cpp"
#include"Update.cpp"

#include"RayCollision.cpp"



Map::Map()
{
	maximumnumberoftrianglescolliders[0] = 14;
	maximumnumberoftrianglescolliders[1] = 14;
	maximumnumberofobjectcolliders[0] = 64;
	maximumnumberofobjectcolliders[1] = 64;
	
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
	maximumnumberoftrianglescolliders[0] = 0;
	maximumnumberoftrianglescolliders[1] = 0;
	maximumnumberofobjectcolliders[0] = 0;
	maximumnumberofobjectcolliders[1] = 0;
	
	if( colliderobj != NULL )
	{
		if( *colliderobj != NULL )
		{
			for( int x = 0; x < maximumnumberofobjectcolliders[0]; x++ )
			{
				delete[] *(colliderobj+x);
			}
			delete[] colliderobj;
		}
	}
	
	if( colliderter != NULL )
	{
		for( int x = 0; x < maximumnumberoftrianglescolliders[0]; x++ )
		{
			if( *colliderter != NULL )
			{
				delete[] *(colliderobj+x);
			}
		}
		delete[] colliderobj;
	}
	
	moveColliderTerrain[0] = 0.0f;
	moveColliderTerrain[1] = 0.0f;
	moveColliderObject[0] = 0.0f;
	moveColliderObject[1] = 0.0f;
	sizeColliderTerrain[0] = 0.0f;
	sizeColliderTerrain[1] = 0.0f;
	sizeColliderObject[0] = 0.0f;
	sizeColliderObject[1] = 0.0f;
	
	triPHYS.resize( 0 );
	
	staticobject.resize( 0 );
	
	int CameraObject = 0;
	
	Gravity = 0.0f;
	AirResistance = 0.0f;
	
	graphicObjects.resize( 0 );
}

