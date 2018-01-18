


class Collision
{
public:
	
	inline unsigned int AABBTriangle( AABB * object, Vector offset1, TrianglePX * tri, float time );							// +/-
	inline unsigned int OBBTriangle( OBB * object, Vector offset1, TrianglePX * tri, float time );							// -
	inline unsigned int SphereTriangle( Sphere * object, Vector offset1, TrianglePX * tri, float time );						// +/-
	
	inline unsigned int AABBAABB( AABB * object1, Vector offset1, AABB * object2, Vector offset2, float time );				// -/.../...
	inline unsigned int AABBOBB( AABB * object1, Vector offset1, OBB * object2, Vector offset2, float time );				// -
	inline unsigned int AABBSphere( AABB * object1, Vector offset1, Sphere * object2, Vector offset2, float time );			// -/.../...
	
	inline unsigned int OBBOBB( OBB * object1, Vector offset1, OBB * object2, Vector offset2, float time );					// -
	inline unsigned int OBBSphere( OBB * object1, Vector offset1, Sphere * object2, Vector offset2, float time );			// -
	
	inline unsigned int SphereSphere( Sphere * object1, Vector offset1, Sphere * object2, Vector offset2, float time );		// -/.../...
	
	inline unsigned int ModelTriangle( PhysicModelStatic * model, TrianglePX * tri, float time );								// +/...
	
	inline unsigned int ModelAABB( PhysicModelStatic * model, AABB * object, Vector offset2, float time );					// -/.../...
	inline unsigned int ModelOBB( PhysicModelStatic * model, OBB * object, Vector offset2, float time );					// -
	inline unsigned int ModelSphere( PhysicModelStatic * model, Sphere * object, Vector offset2, float time );				// -/.../...
	
	inline unsigned int ModelModel( PhysicModelStatic * model1, PhysicModelStatic * model2, float time );					// -/.../...
};


