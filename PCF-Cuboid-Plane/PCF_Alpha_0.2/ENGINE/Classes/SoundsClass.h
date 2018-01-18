


class Sounds
{
    class _Sample   // klasa jednego d�wi�ku
    {
        ALLEGRO_SAMPLE * sample;
        NameLine128 name;
    };
    
    vector < _Sample > sound;   // dynamiczny kontener d�wi�k�w
    
    inline unsigned int FoundId( char * namesound );
    
    inline int LoadSound( char * namefile, char * foundname );  // -
        // namefile - nazwa pliku do wczytania do pami�ci, foundname - nazwa pliku zamiast indeksowania
        // zwraca 0 w przypadku braku pliku
    
    inline int PlaySound( unsigned int id, float * pos1, float * pos2, float * directionversor, float lenght ); // -
        // id - iterator do tablicy, pos1 - pozycja s�uchacza, pos2 - pozycja wydawania d�wi�ku, directionversor - kierunek patrzenia s�uchacza, lenght - odleg�o�� uszu od siebie
        // zwraca 0 w przypadku braku pliku
    
    inline int PlaySound( char * namesound, float * pos1, float * pos2, float * directionversor, float lenght );    // -
        // namesound - nazwa d�wi�ku do odtworzenia, pos1 - pozycja s�uchacza, pos2 - pozycja wydawania d�wi�ku, directionversor - kierunek patrzenia s�uchacza, lenght - odleg�o�� uszu od siebie
        // zwraca 0 w przypadku braku pliku
    
    inline int PlaySound( char * namesound, float strenght, float balance, float height );  // -
        // namesound - nazwa d�wi�ku do odtworzenia, strenght - g�o�no�� (od 0.0f do 1.0f), balance - balans lewe/prawe ucho (od -1.0f do 1.0f), height - wysoko�� ( 1.0f )
        // zwraca 0 w przypadku braku pliku
    
    inline int PlaySound( char * namesound, float strenght );   // -
        // namesound - nazwa d�wi�ku do odtworzenia, strenght - g�o�no��
        // zwraca 0 w przypadku braku pliku
    
    inline void StopPlaying( char * namesound );     // -
        // namesound - nazwa d�wi�ku do zatrzymania
    
    Sounds();
    ~Sounds();
};
