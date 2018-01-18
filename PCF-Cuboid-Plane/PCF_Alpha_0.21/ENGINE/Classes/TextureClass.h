



class Texture
{
public:
    NameLine128 texturefile;
    BITMAPINFOHEADER bitmapInfoHeader;
    unsigned char * bitmapData;
    unsigned int texture;
    
    int LoadInit( NameLine128 name );   // +
    int Init();                         // -
    int Load( NameLine128 name );       // -
    
    Texture();                          // +
};
