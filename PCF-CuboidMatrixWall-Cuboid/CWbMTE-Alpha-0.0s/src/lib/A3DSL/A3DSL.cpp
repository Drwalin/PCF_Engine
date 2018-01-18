
#include"SoundsA3D.h"



inline int SoundsA3D::LoadSound( char * namefile, char * foundname )
{
    al_reserve_samples(1);
    sound.resize( sound.size()+1 );
    sound[sound.size()-1].sample = al_load_sample( namefile );  // ³aduje dŸwiêk z pliku
    if( sound[sound.size()-1].sample != NULL )
    {
        sprintf( sound[sound.size()-1].name.name, "%s", foundname );
        return 1;
    }
    else
    {
    sound.resize( sound.size()-1 );
        return 0;
    }
}

inline int SoundsA3D::FoundId( char * namesound )
{
    for( unsigned int i = 0; i < sound.size(); i++ )
    {
        if( !strcmp( namesound, sound[i].name.name ) )
            return i;
    }
    return -1;
}

inline int SoundsA3D::PlaySound( char * namesound, float strenght )
{
    int id = FoundId( namesound );
    if( id < 0 || id >= sound.size() )
        return -1;
    
    int idsound = al_play_sample( sound[id].sample, strenght, 0.0f, 1.0f, ALLEGRO_PLAYMODE_ONCE, NULL );
    return idsound;
}

inline int SoundsA3D::PlaySound( char * namesound, float strenght, float balance, float height )
{
    int id = FoundId( namesound );
    if( id < 0 || id >= sound.size() )
        return -1;
    
    int idsound = al_play_sample( sound[id].sample, strenght, balance, height, ALLEGRO_PLAYMODE_ONCE, NULL );
    return idsound;
}

inline int SoundsA3D::PlaySound( char * namesound, float * pos1, float * pos2, float * directionversor, float lenght, float maxdistance )
{
    
    int id = FoundId( namesound );
    if( id < 0 || id >= sound.size() )
        return -1;
    int idsound = PlaySound( id, pos1, pos2, directionversor, lenght, maxdistance );
    return idsound;
    
}

inline int SoundsA3D::PlaySound( int id, float * pos1, float * pos2, float * directionversor, float lenght, float maxdistance )
{
    Vector head;            // pozycja g³owy
    Vector speaker;         // pozycja g³oœnika / punktu wydawania dŸwiêku
    Vector direction;       // wersor kierunku patrzenia
    Vector left, right;     // pozycja lewego i prawego ucha
    Vector ears;            // wersor kierunku do lewego ucha, od po³o¿enia g³owy
    float leftradian;       // odleg³osæ g³oœnika od lewego ucha
    float rightradian;      // odleg³osæ g³oœnika od prawego ucha
    float leftstr = 0.0f;   // g³oœnoœæ w lewym uchu
    float rightstr = 0.0f;  // g³oœnoœæ w prawym uchu
    float balance;          // balans g³oœnoœci
    float strenght;         // g³oœnoœæ ogólna
    head.Set( pos1[0], pos1[1], pos1[2] );
    speaker.Set( pos2[0], pos2[1], pos2[2] );
    direction.Set( directionversor[0], directionversor[1], directionversor[2] );
    
    ears = direction && (SetVector( 0.0f, 1.0f, 0.0f ));
    ears.Normalize();
    
    left  = (ears * (      lenght )) + head;
    right = (ears * ( 0.0f-lenght )) + head;
    
    leftradian  = ( left  - speaker ).Lenght();
    rightradian = ( right - speaker ).Lenght();
    
    if( leftradian < maxdistance  && leftradian  > 0.0f )
    {
        leftstr  = 1.0f - (leftradian  / maxdistance);
    }
    if( rightradian < maxdistance && rightradian > 0.0f )
    {
        rightstr = 1.0f / (rightradian / maxdistance);
    }
    
    strenght = ( leftstr + rightstr ) / 2.0f;
    balance =  rightstr - leftstr;
    
    int idsound = al_play_sample( sound[id].sample, strenght, balance, 1.0f, ALLEGRO_PLAYMODE_ONCE, NULL );
    return idsound;
}

inline int SoundsA3D::PlaySound( int id, float strenght )
{
    if( id < 0 || id >= sound.size() )
        return -1;
    
    int idsound = al_play_sample( sound[id].sample, strenght, 0.0f, 1.0f, ALLEGRO_PLAYMODE_ONCE, NULL );
    return idsound;
}








