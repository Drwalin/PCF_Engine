
#ifndef MAP_H
#define MAP_H

class Map
{
public:
	vector < TrianglePX > triPHYS;
	vector < VBOtextured > vbotex;
	vector < VBOcolored > vbocol;
	vector < StaticGraphicModel * > graphicMapModels;
	
	PointParticle particles;
	Lightning * lightnings;
	int NumberOfLightnings;
	
    vector < PhysicModelStatic * > staticobject;
	
	int CameraObject;
	
	float Gravity;
	float AirResistance;
	
    int maximumnumberoftrianglescolliders[2];
    int maximumnumberofobjectcolliders[2];
	
    ColliderTerrain ** colliderter;
    ColliderObjects ** colliderobj;
    ColliderObjects colliderobjectout;
    float moveColliderTerrain[2];
    float moveColliderObject[2];
    float sizeColliderTerrain[2];
    float sizeColliderObject[2];
	
	bool updateVBOs;
	
	inline void UpdateForces( float FrameTime );
	inline void UpdateObjectsCollisions( float FrameTime, int begin, int end );
	inline void UpdateAllObjectsCollisions( float FrameTime );
	
	inline void UpdateObjectColliders();
	inline void UpdateTerrainColliders();
	
	inline void Update( float FrameTime );
	
	inline void Draw( float FrameTime );
	
	inline int  SegmentCollision( Vector p1, Vector p2, PhysicModelStatic ** object, TrianglePX ** triangle, PhysicModelStatic * decludingobject, unsigned int rayTypeSrc );
	inline bool SegmentCollideObject( Vector begin, Vector end, PhysicModelStatic ** object, PhysicModelStatic * decludingobject );
	
	inline void DestroyColliders();
	
	Map();
	~Map();
};

#endif
