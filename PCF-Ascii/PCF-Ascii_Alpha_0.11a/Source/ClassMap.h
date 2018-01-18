


class Map
{
public:
    unsigned int blocks[XMAPSIZE][YMAPSIZE];
    unsigned int npc[XMAPSIZE][YMAPSIZE];
    ALLEGRO_BITMAP * background;
    
    void Init();
    
    void Draw();
    
    Map(){}
};

