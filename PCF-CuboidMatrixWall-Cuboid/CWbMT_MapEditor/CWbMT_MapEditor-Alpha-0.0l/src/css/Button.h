


class Button
{
public:
	int x,y;
	int wx, wy;
	EDITOR_OPTIONS_ENABLED option_enabling;
	RENDER_OPTIONS_ENABLED other_option;
	ALLEGRO_BITMAP * texture_on;
	ALLEGRO_BITMAP * texture_off;
	
	inline void Draw();
	
	inline bool IsPointInside( int srcx, int srcy );
	
	Button();
};


