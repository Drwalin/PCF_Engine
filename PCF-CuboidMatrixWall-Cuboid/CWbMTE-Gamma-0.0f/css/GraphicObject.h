
#ifndef GRAPHIC_OBJECT_H
#define GRAPHIC_OBJECT_H

class GraphicObject
{
public:
	StaticGraphicModel * model;
	Vector pos;
	float scale;
	Vector rotate;
	
	inline void Draw();
	inline void SetModel( StaticGraphicModel * src );
	inline void SetScale( float src );
	inline void SetPos( Vector src );
	inline void SetRotate( float s1, float s2, float s3 );
	
	GraphicObject();
	~GraphicObject();
};

#endif
