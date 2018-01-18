


class Texture
{
private:
	BITMAPINFOHEADER bitmapInfoHeader;
	unsigned char * bitmapData;
	unsigned int texture;
	
public:
	inline int LoadInit( char * name );
	inline unsigned int GetID();
	inline void Bind();
	
	Texture();
	~Texture();
};


