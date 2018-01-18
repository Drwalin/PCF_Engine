


class PhysicModelStatic
{
public:
	
	float see[2];
	float seeaspect;
	
	bool CollisionUse;
	bool Draw;
	bool MoveUse;
	
	int type;
	void * object;
	
	GraphicModel * model;
	
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
	
	PhysicModelStatic();
	~PhysicModelStatic();
};
