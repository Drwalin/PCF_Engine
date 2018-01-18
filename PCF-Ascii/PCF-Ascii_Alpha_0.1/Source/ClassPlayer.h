

class Player
{
public:
    float x;
    float y;
    float bx;
    float by;
    float sx;
    float sy;
    float width;
    float height;
    
    vector < ALLEGRO_BITMAP * > textures;
    
    void Update( float time );
};
