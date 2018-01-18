


void ScreenWrite( char * word );
void ScreenGoTo( unsigned int x, unsigned int y );
void ScreenClear();
void ScreenDraw();
void ScreenLetterDraw( unsigned int x, unsigned int y, char symbol );
void ScreenLoadTextures();

char buffor[80][45];
unsigned int index[2];
//unsigned int index;


//char texturefiles[96][16];
BITMAPINFOHEADER ScreenbitmapInfoHeader[96];
unsigned char * ScreenbitmapData[96];
unsigned int Screentexture[96];


