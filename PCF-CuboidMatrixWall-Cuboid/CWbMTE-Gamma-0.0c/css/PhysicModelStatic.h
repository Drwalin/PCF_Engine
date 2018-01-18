
#ifndef PHYSIC_MODEL_STATIC_H
#define PHYSIC_MODEL_STATIC_H

class PhysicModelStatic
{
public:
	Vector bpos;
	Vector pos;
	Vector size;        // size object (x,y,z) without rotation
	Vector vel;
	Vector force;
	
	float rotatehead;
	
	float mass;
	
	bool CollisionDown;
	bool CollisionUp;
	bool CollisionSide;
	
	Vector min;
	Vector max;
	
	float see[2];
	float seeaspect;
	
	vector < unsigned int > rayType;
	
	bool TerrainCollisionUse;
	bool RayCollisionUse;
	bool ObjectsCollisionUse;
	bool Draw;
	bool MoveUse;
	
	float GraphicModelScale;
	StaticGraphicModel * model;
	void * GameLogicObject;
	
	int MainVectorId;
	
	Contact contact;
	
	inline void ReactAfterCollisionDetection();
	
	inline Vector GetVertex( int id );
	
	inline Vector MaxWithVector( Vector dst );
	inline Vector ClosesPoint( Vector dst );
	
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
	
	inline void AddRayType( unsigned int src );
	inline bool CheckRayType( unsigned int src );
	
	PhysicModelStatic();
	~PhysicModelStatic();
};

#endif
