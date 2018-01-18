


class Collision
{
public:
	
	inline unsigned int RayAABB( Vector p0, Vector p1, AABB * object );											// +
	
	inline unsigned int AABBTriangle( AABB * object, TrianglePX * tri, float time );							// +/-
	inline unsigned int OBBTriangle( OBB * object, TrianglePX * tri, float time );								// -
	inline unsigned int SphereTriangle( Sphere * object, TrianglePX * tri, float time );						// +/-
	inline unsigned int MobTriangle( NPC * object, TrianglePX * tri, float time );								// ...
	
	inline unsigned int AABBAABB( AABB * object1, AABB * object2, float time );									// -/.../...
	inline unsigned int AABBOBB( AABB * object1, OBB * object2, float time );									// -
	inline unsigned int AABBSphere( AABB * object1, Sphere * object2, float time );								// -/.../...
	
	inline unsigned int OBBOBB( OBB * object1, OBB * object2, float time );										// -
	inline unsigned int OBBSphere( OBB * object1, Sphere * object2, float time );								// -
	
	inline unsigned int SphereSphere( Sphere * object1, Sphere * object2, float time );							// -/.../...
	
	inline unsigned int ModelTriangle( PhysicModelStatic * model, TrianglePX * tri, float time );				// +/...
	
	inline unsigned int ModelAABB( PhysicModelStatic * model, AABB * object, float time );						// -/.../...
	inline unsigned int ModelOBB( PhysicModelStatic * model, OBB * object, float time );						// -
	inline unsigned int ModelSphere( PhysicModelStatic * model, Sphere * object, float time );					// -/.../...
	
	inline unsigned int ModelModel( PhysicModelStatic * model1, PhysicModelStatic * model2, float time );		// -/.../...
};


