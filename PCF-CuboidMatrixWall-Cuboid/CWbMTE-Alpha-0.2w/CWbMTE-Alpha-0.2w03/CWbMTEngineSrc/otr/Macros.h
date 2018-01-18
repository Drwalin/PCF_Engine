

/*
    ENGINE MACROS
*/


enum Textures_ENUM
{
	TEXTURE_UNLOADED,
	TEXTURE_LOADED
};

enum Collision__ENUM
{
	COLLISION_IS,
	COLLISION_NO,
	COLLISION_WITH_TRIANGLE,
	COLLISION_WITH_OBJECT
};

#define X_COLLIDERS_NUMBER 16
#define Z_COLLIDERS_NUMBER 16
#define X_CHUNK_SIZE 128.0f
#define Z_CHUNK_SIZE 128.0f
#define X_COLLIDER_SIZE 8.0f
#define Z_COLLIDER_SIZE 8.0f


#define CWBMT_FRAMEINMS 1

// Physic threads:
#define PXTHREAD_CLEAR ((unsigned char)0)
#define PXTHREAD_INWORK ((unsigned char)1)



