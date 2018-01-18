


class SeeAspect
{
public:
	
	// window settings:
	int x, y;
	int wx, wy;
	bool activate;
	inline bool IsPointInside( int srcx, int srcy );
	
	// draw data:
	float mx, my;
	float scale;
	int drawaxis;
	ALLEGRO_BITMAP * texture;
	
	Window3D * win;
		
	inline void GetPoint( float srcx, float srcy, int * dstx, int * dsty );
	inline void GetPoint( int srcx, int srcy, float * dstx, float * dsty );
	
	inline void Draw();
	
	SeeAspect();
};


