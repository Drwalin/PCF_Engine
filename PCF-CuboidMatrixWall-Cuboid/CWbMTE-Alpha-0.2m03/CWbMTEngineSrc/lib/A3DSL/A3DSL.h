


class SoundsA3D
{
public:
    class _Sample   // klasa jednego d�wi�ku
    {
    public:
        ALLEGRO_SAMPLE * sample;
        NameLine128 name;
    };
    
    vector < _Sample > sound;   // dynamiczny kontener d�wi�k�w
    
    inline int FoundId( char * namesound );            // +
        // namesound - nazwa szukanego d�wi�ku
        // zwraca iterator do kontenera d�wi�k�w ( -1 oznacza brak pliku o danej nazwie )
    
    inline int LoadSound( char * namefile, char * foundname );  // +
        // namefile - nazwa pliku do wczytania do pami�ci, foundname - nazwa pliku , kt�r� mo�na poda� zamiast indeksu do kontenera
        // zwraca -1 w przypadku braku pliku
    
    inline int PlaySound( int id, float * pos1, float * pos2, float * directionversor, float lenght, float maxdistance ); // -
        // id - iterator do tablicy, pos1 - pozycja s�uchacza, pos2 - pozycja wydawania d�wi�ku, directionversor - kierunek patrzenia s�uchacza, lenght - odleg�o�� uszu od siebie, maxdistance - maxymalna odleg�o�� od s�uchacza, aby d�wi�k by� s�yszalny
        // zwraca -1 w przypadku braku pliku
    
    inline int PlaySound( char * namesound, float * pos1, float * pos2, float * directionversor, float lenght, float maxdistance );    // +
        // namesound - nazwa d�wi�ku do odtworzenia, pos1 - pozycja s�uchacza, pos2 - pozycja wydawania d�wi�ku, directionversor - kierunek patrzenia s�uchacza, lenght - odleg�o�� uszu od siebie, maxdistance - maxymalna odleg�o�� od s�uchacza, aby d�wi�k by� s�yszalny
        // zwraca -1 w przypadku braku pliku
    
    inline int PlaySound( char * namesound, float strenght, float balance, float height );  // +
        // namesound - nazwa d�wi�ku do odtworzenia, strenght - g�o�no�� (od 0.0f do 1.0f), balance - balans lewe/prawe ucho (od -1.0f do 1.0f), height - wysoko�� ( 1.0f )
        // zwraca -1 w przypadku braku pliku
    
    inline int PlaySound( int id, float strenght );   // +
        // id - iterator do kontenera d�wi�k�w, strenght - g�o�no��
        // zwraca -1 w przypadku braku pliku
    
    inline int PlaySound( char * namesound, float strenght );   // +
        // namesound - nazwa d�wi�ku do odtworzenia, strenght - g�o�no��
        // zwraca -1 w przypadku braku pliku
    
    inline void StopPlaying( char * namesound );     // -
        // namesound - nazwa d�wi�ku do zatrzymania
    
    SoundsA3D(){}   // -
    ~SoundsA3D(){}  // -
};
