

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

// Physic threads:
#define PXTHREAD_CLEAR ((unsigned char)0)
#define PXTHREAD_INWORK ((unsigned char)1)
//#define PXTHREAD_ORDERBEGINWORK ((unsigned char)2)
//#define PXTHREAD_WORKENDED ((unsigned char)4)
//#define PXTHREAD_ERROR ((unsigned char)8)



