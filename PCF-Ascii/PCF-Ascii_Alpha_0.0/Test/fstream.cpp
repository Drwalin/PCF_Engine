#include<fstream>
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    fstream file;
    file.open( "getch.exe", ios::in );
    file.seekg( 0, file.end ); int wielkosc=file.tellg();
    file.seekg(0);
    
    cout<<wielkosc;
    
    getch();
    
    
    file.close();
    return 0;
}




