

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
	COLLISION_NO
};

// Physic threads:
#define PXTHREAD_CLEAR ((unsigned char)0)
#define PXTHREAD_INWORK ((unsigned char)1)
//#define PXTHREAD_ORDERBEGINWORK ((unsigned char)2)
//#define PXTHREAD_WORKENDED ((unsigned char)4)
//#define PXTHREAD_ERROR ((unsigned char)8)

enum PhysicModels_ENUM
{
	PXMODEL_NONE,
	PXMODEL_AABB,
	PXMODEL_OBB,
	PXMODEL_Sphere
};

