


class Texture
{
private:
	unsigned int width;
	unsigned int height;
	unsigned char * bitmapData;
	unsigned int texture;
	
public:
	char * name;
	inline int LoadInit( char * name );
	inline int LoadInit( char * src, int type );
	inline unsigned int GetID();
	inline void Bind();
	inline void Delete();
	
	//	Coordinates from left down corner
	inline void GetPixel( unsigned int x, unsigned int y, unsigned char & r, unsigned char & g, unsigned char & b, unsigned char & a );
	inline void SetPixel( unsigned int x, unsigned int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a );
	
	Texture();
	~Texture();
};


