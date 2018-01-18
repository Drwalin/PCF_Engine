


class SoundsA3D
{
public:
    class _Sample   // klasa jednego dŸwiêku
    {
    public:
        ALLEGRO_SAMPLE * sample;
        NameLine128 name;
    };
    
    vector < _Sample > sound;   // dynamiczny kontener dŸwiêków
    
    inline int FoundId( char * namesound );            // +
        // namesound - nazwa szukanego dŸwiêku
        // zwraca iterator do kontenera dŸwiêków ( -1 oznacza brak pliku o danej nazwie )
    
    inline int LoadSound( char * namefile, char * foundname );  // +
        // namefile - nazwa pliku do wczytania do pamiêci, foundname - nazwa pliku , któr¹ mo¿na podaæ zamiast indeksu do kontenera
        // zwraca -1 w przypadku braku pliku
    
    inline int PlaySound( int id, float * pos1, float * pos2, float * directionversor, float lenght, float maxdistance ); // -
        // id - iterator do tablicy, pos1 - pozycja s³uchacza, pos2 - pozycja wydawania dŸwiêku, directionversor - kierunek patrzenia s³uchacza, lenght - odleg³oœæ uszu od siebie, maxdistance - maxymalna odleg³oœæ od s³uchacza, aby dŸwiêk by³ s³yszalny
        // zwraca -1 w przypadku braku pliku
    
    inline int PlaySound( char * namesound, float * pos1, float * pos2, float * directionversor, float lenght, float maxdistance );    // +
        // namesound - nazwa dŸwiêku do odtworzenia, pos1 - pozycja s³uchacza, pos2 - pozycja wydawania dŸwiêku, directionversor - kierunek patrzenia s³uchacza, lenght - odleg³oœæ uszu od siebie, maxdistance - maxymalna odleg³oœæ od s³uchacza, aby dŸwiêk by³ s³yszalny
        // zwraca -1 w przypadku braku pliku
    
    inline int PlaySound( char * namesound, float strenght, float balance, float height );  // +
        // namesound - nazwa dŸwiêku do odtworzenia, strenght - g³oœnoœæ (od 0.0f do 1.0f), balance - balans lewe/prawe ucho (od -1.0f do 1.0f), height - wysokoœæ ( 1.0f )
        // zwraca -1 w przypadku braku pliku
    
    inline int PlaySound( int id, float strenght );   // +
        // id - iterator do kontenera dŸwiêków, strenght - g³oœnoœæ
        // zwraca -1 w przypadku braku pliku
    
    inline int PlaySound( char * namesound, float strenght );   // +
        // namesound - nazwa dŸwiêku do odtworzenia, strenght - g³oœnoœæ
        // zwraca -1 w przypadku braku pliku
    
    inline void StopPlaying( char * namesound );     // -
        // namesound - nazwa dŸwiêku do zatrzymania
    
    SoundsA3D(){}   // -
    ~SoundsA3D(){}  // -
};
