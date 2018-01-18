


class Sounds
{
    class _Sample   // klasa jednego dŸwiêku
    {
        ALLEGRO_SAMPLE * sample;
        NameLine128 name;
    };
    
    vector < _Sample > sound;   // dynamiczny kontener dŸwiêków
    
    inline unsigned int FoundId( char * namesound );
    
    inline int LoadSound( char * namefile, char * foundname );  // -
        // namefile - nazwa pliku do wczytania do pamiêci, foundname - nazwa pliku zamiast indeksowania
        // zwraca 0 w przypadku braku pliku
    
    inline int PlaySound( unsigned int id, float * pos1, float * pos2, float * directionversor, float lenght ); // -
        // id - iterator do tablicy, pos1 - pozycja s³uchacza, pos2 - pozycja wydawania dŸwiêku, directionversor - kierunek patrzenia s³uchacza, lenght - odleg³oœæ uszu od siebie
        // zwraca 0 w przypadku braku pliku
    
    inline int PlaySound( char * namesound, float * pos1, float * pos2, float * directionversor, float lenght );    // -
        // namesound - nazwa dŸwiêku do odtworzenia, pos1 - pozycja s³uchacza, pos2 - pozycja wydawania dŸwiêku, directionversor - kierunek patrzenia s³uchacza, lenght - odleg³oœæ uszu od siebie
        // zwraca 0 w przypadku braku pliku
    
    inline int PlaySound( char * namesound, float strenght, float balance, float height );  // -
        // namesound - nazwa dŸwiêku do odtworzenia, strenght - g³oœnoœæ (od 0.0f do 1.0f), balance - balans lewe/prawe ucho (od -1.0f do 1.0f), height - wysokoœæ ( 1.0f )
        // zwraca 0 w przypadku braku pliku
    
    inline int PlaySound( char * namesound, float strenght );   // -
        // namesound - nazwa dŸwiêku do odtworzenia, strenght - g³oœnoœæ
        // zwraca 0 w przypadku braku pliku
    
    inline void StopPlaying( char * namesound );     // -
        // namesound - nazwa dŸwiêku do zatrzymania
    
    Sounds();
    ~Sounds();
};
