





class Models
{
public:
    vector < Vertex >       vertices;
    vector < unsigned int > id_texture;
    vector < Texture >      textures;
    
    int type; // 0 - nie rysuj, 1-punkty, 2-linie, 3-trójk¹ty, 4-czworok¹ty ...
    
    NameLine128 name;
    
    int LoadInit( NameLine128 name ){return 1;};   // -
    int Init();                         // -
    int Load( NameLine128 name );       // -
    
    Models();                           // +
};
