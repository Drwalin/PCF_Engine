#include<iostream>
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<vector>
using namespace std;

class Name
{
public:
    char name[256];
};

int main()
{
    fstream file;
    
    char getlinefast[1024];
    vector < Name > name;
    
    system( "dir > dupa.txt" );
    
    
    
    file.open( "dupa.txt", ios::in );   
    file.seekg( 0, file.end ); int wielkosc = file.tellg();
    file.seekg( 0 );
    
    cout << wielkosc;
    
    file.getline( getlinefast, 1024 );
    file.getline( getlinefast, 1024 );
    file.getline( getlinefast, 1024 );
    file.getline( getlinefast, 1024 );
    
    while( file.tellg() <  wielkosc )
    {
        name.resize( name.size()+1 );
        file >> getlinefast;
        file >> getlinefast;
        file >> getlinefast;
        file.getline( name[ name.size()-1 ].name, 256 );
    }
    name.resize( name.size()-2 );
    
    for( int i = 0; i < name.size(); i++ )
    {
        cout<<endl<<name[i].name;
    }
    
    
    
    
    
    getch();
    file.close();
    return 0;
}
