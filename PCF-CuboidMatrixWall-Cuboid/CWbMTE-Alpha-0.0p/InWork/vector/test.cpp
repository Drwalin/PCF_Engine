#include<cstdio>
#include<conio.h>

#include"vector.cpp"
//#include<vector>
using namespace std;


int main()
{
	vector < int > tab;
	const int a = 5;
	tab.resize( a );
	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 3;
	tab[3] = 4;
	tab[4] = 5;
	
	tab.push_back( 7 );
	tab.insert( tab.begin()+5, 6 );
	
	int i;
	
	for( i = 0; i < tab.size(); i++ )
	{
		printf( " %i", tab[i] );
	}
	
	tab.erase( tab.begin()+3 );
	printf( "\n" );
	for( i = 0; i < tab.size(); i++ )
	{
		printf( " %i", tab[i] );
	}
	
	getch();
	return 0;
}
