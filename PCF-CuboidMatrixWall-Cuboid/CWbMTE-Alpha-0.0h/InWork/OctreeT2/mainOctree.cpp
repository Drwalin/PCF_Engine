
#include<cmath>
#include<cstdarg>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<iostream>
#include<limits>
#include<string>
#include<vector>

#include<conio.h>

using namespace std;

#include"..\..\src\lib\VMatrix\VMatrix.cpp"

#include"Octree.h"
#include"Octree.cpp"

class Data
{
public:
	Vector pos;
	Vector size;
	int a;
	inline void Load()
	{
		printf( "\n Pozycja: " );
		cin >> pos[0];
		cin >> pos[1];
		cin >> pos[2];
		printf( "\n Rozmiar: " );
		cin >> size[0];
		cin >> size[1];
		cin >> size[2];
		printf( "\n Zmienna Int: " );
		cin >> a;
		printf( "done\n" );
	}
	inline void Print()
	{
		printf( "\n %i ", a );
	}
};

unsigned long long int iloscnarysowanych = 0;

inline void PrintOctree( Octree * octree )
{
	if( octree -> next != NULL )
	{
		PrintOctree( (octree -> next) );
		PrintOctree( (octree -> next) + 1 );
		PrintOctree( (octree -> next) + 2 );
		PrintOctree( (octree -> next) + 3 );
		PrintOctree( (octree -> next) + 4 );
		PrintOctree( (octree -> next) + 5 );
		PrintOctree( (octree -> next) + 6 );
		PrintOctree( (octree -> next) + 7 );
	}
	
	printf( "\n\n" );
	
	for( int i = 0; i < (octree -> items).size(); i++ )
	{
		printf( " %7.7i", ((Data*)((octree->items)[i])) -> a );
		iloscnarysowanych++;
	}
}

int main()
{
	OperateOctree octree;
	
	if( octree.octree != NULL )
		octree.octree = new Octree;
	
	octree.size.Set( 100.0f, 20.0f, 100.0f );
	octree.offset.Set( -50.0f, -10.0f, -50.0f );
	octree.maxChildren = 2;
	
	vector < Data > obj;
	Data fast;
	
	/*
	for( float x = -80.0f; x < 98.0f; x ++ )
	{
		for( float y = -10.0f; y < 70.0f; y ++ )
		{
			for( float z = -90.0f; z < 80.0f; z ++ )
			{
				fast.pos.Set( x, y, x );
				fast.size.Set( 1.0f, 1.0f, 1.0f );
				fast.a = obj.size()+1;
				obj.push_back( fast );
				octree.SetAt( obj[ obj.size()-1 ].pos, obj[ obj.size()-1 ].pos+obj[ obj.size()-1 ].size, (void*)(&obj[ obj.size()-1 ]) );
				
				fast.pos.Set( x+5.0f, y, x+5.0f );
				fast.size.Set( 5.0f, 1.0f, 5.0f );
				fast.a = obj.size()+1;
				obj.push_back( fast );
				octree.SetAt( obj[ obj.size()-1 ].pos, obj[ obj.size()-1 ].pos+obj[ obj.size()-1 ].size, (void*)(&obj[ obj.size()-1 ]) );
				
				fast.pos.Set( x+10.0f, y, x+10.0f );
				fast.size.Set( 10.0f, 1.0f, 10.0f );
				fast.a = obj.size()+1;
				obj.push_back( fast );
				octree.SetAt( obj[ obj.size()-1 ].pos, obj[ obj.size()-1 ].pos+obj[ obj.size()-1 ].size, (void*)(&obj[ obj.size()-1 ]) );
			}
		}
	}
	
	for( float x = -50.0f; x < 38.0f; x ++ )
	{
		for( float y = -10.0f; y < 8.0f; y ++ )
		{
			for( float z = -50.0f; z < 38.0f; z ++ )
			{
				fast.pos.Set( x, y, x );
				fast.size.Set( 1.0f, 1.0f, 1.0f );
				fast.a = obj.size()+1;
				obj.push_back( fast );
				octree.SetAt( obj[ obj.size()-1 ].pos, obj[ obj.size()-1 ].pos+obj[ obj.size()-1 ].size, (void*)(&obj[ obj.size()-1 ]) );
				
				fast.pos.Set( x+5.0f, y, x+5.0f );
				fast.size.Set( 5.0f, 1.0f, 5.0f );
				fast.a = obj.size()+1;
				obj.push_back( fast );
				octree.SetAt( obj[ obj.size()-1 ].pos, obj[ obj.size()-1 ].pos+obj[ obj.size()-1 ].size, (void*)(&obj[ obj.size()-1 ]) );
			}
		}
	}
	*/
	
	
	
	
	
	for( float x = -9.0f; x < 8.0f; x ++ )
	{
		for( float y = -9.0f; y < 8.0f; y ++ )
		{
			for( float z = -9.0f; z < 8.0f; z ++ )
			{
				fast.pos.Set( x, y, x );
				fast.size.Set( 1.0f, 1.0f, 1.0f );
				fast.a = obj.size()+1;
				obj.push_back( fast );
				octree.SetAt( obj[ obj.size()-1 ].pos, obj[ obj.size()-1 ].pos+obj[ obj.size()-1 ].size, (void*)(&obj[ obj.size()-1 ]) );
			}
		}
	}
	
	
	printf( "\n  Objects Created: %i", obj.size() );
	
	while( 1 )
	{
		printf( "\n 'L' - wczytaj, 'Q' - wyswietl:\n" );
		switch( getch() )
		{
		case 'L':
			fast.Load();
			obj.push_back( fast );
			octree.SetAt( obj[ obj.size()-1 ].pos, obj[ obj.size()-1 ].pos+obj[ obj.size()-1 ].size, (void*)&obj[ obj.size()-1 ] );
			break;
			
		case 'Q':
			
			printf( "\n\n\n" );
			
			PrintOctree( octree.octree );
			
			printf( "\n\n\n : %i\n", (int)iloscnarysowanych );
			
			/*
			float sizex = 100.0f/48.0f, sizey = 20.0f/28.0f, sizez = 100.0f/48.0f;
			for( float x = -50.0f; x < 50.0f; x += sizex )
			{
				for( float y = -10.0f; y < 10.0f; y += sizey )
				{
					for( float z = -50.0f; z < 50.0f; z += sizez )
					{
						int elemnumber;
						void ** tab = octree.GetFrom( SetVector( x, y, z ), SetVector( x, y, z ), &elemnumber );
						for( int i = 0; i < elemnumber; i++ )
						{
							((Data*)(*(tab+i))) -> Print();
						}
						delete[] tab;
					}
				}
			}
			*/
			
			break;
		}
	}
	return 0;
}

