
#ifndef COLLISION_H
#define COLLISION_H

class Collision
{
public:
	inline bool			RayTriangle( Vector p1, Vector p2, TrianglePX * tri );
	inline bool			RayTriangle( Vector p1, Vector p2, TrianglePX * tri, Vector * point );
	
	inline unsigned int RayAABB( Vector p0, Vector p1, PhysicModelStatic * object );
	inline unsigned int RayAABB( Vector p0, Vector p1, PhysicModelStatic * object, Vector * point );
	
	inline unsigned int AABBTriangle( PhysicModelStatic * object, TrianglePX * tri, float time );
	
	inline unsigned int AABBAABB( PhysicModelStatic * object1, PhysicModelStatic * object2, float time );
};

#endif
