
#ifndef CONTACT_H
#define CONTACT_H

class Contact
{
	vector < vector < Vector > > points;
	vector < Vector > direction;
	
public:
	inline void AddPoint( Vector point );
	inline void AddDirection( Vector dir );
	
	inline Vector GetFaceBarycentic( const int id );
	
	inline Vector GetMediumDirection();
	
	inline bool WasIntersection();
	
	inline void Clear();
	
	Contact();
	~Contact();
	
	friend class SoundSampleSources;
	friend class OneSample;
	friend class SoundEngine;
	friend class Texture;
	friend class VBOvertexColored;
	friend class VBOcolored;
	friend class VBOvertexTexture;
	friend class VBOtextured;
	friend class ONEPointParticle;
	friend class PointParticle;
	friend class LightningVertex;
	friend class Lightning;
	friend class TrianglePX;
	friend class StaticGraphicModel;
	friend class PhysicModelStatic;
	friend class Collision;
	friend class ColliderTerrain;
	friend class ColliderObjects;
	friend class Map;
	friend class Engine;
};

#endif
