


class PhysicModelStatic
{
public://private:
	
	Vector bpos;
	Vector pos;
	Vector vel;
	Vector force;
	Vector resistanceforce;
	
	Vector min;
	Vector max;
	
	float see[2];
	float seeaspect;
	
	bool CollisionUse;
	bool Draw;
	bool MoveUse;
	
	vector < AABB > aabb;
	vector < OBB > obb;
	vector < Sphere > sphere;
	
	StaticGraphicModel * model;
	void * GameLogicObject;
	
	int MainVectorId;
	
//public:
	inline float GetMass();
	inline Vector GetMin();
	inline Vector GetMax();
	inline float GetMinX();
	inline float GetMinY();
	inline float GetMinZ();
	inline float GetMaxX();
	inline float GetMaxY();
	inline float GetMaxZ();
	
	inline void UpdatePossition( float time );
	inline void UpdateVelocity( float time );
	inline void IdentityForce();
	inline void IdentityCollisions();
	
	inline void SetGameLogicObject( void * src );
	inline void * GetGameLogicObject();
	
	PhysicModelStatic();
	~PhysicModelStatic();
};
