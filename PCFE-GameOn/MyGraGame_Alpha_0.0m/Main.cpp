


/*
	Free Assets:
	https://www.gametextures.com/shop/?orderby=date
	http://opengameart.org/content/urban-texture-pack-from-gametexturescom
	
	Free Models:
	https://clara.io/library?query=female&gameCheck=true&public=true&page=9&perPage=24
	
	
*/

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
using namespace std;

#include"..\..\PCF-CuboidMatrixWall-Cuboid\CWbMTE-Beta-0.1i\LibIncluder.c"
//#include"..\..\PCF-CuboidMatrixWall-Cuboid\CWbMTE-Beta-0.1i\Engine.cpp"

/*
    Game source code:
*/

#include"src\lib\ConvertMSDNKeyCode.cpp"
#include"src\lib\Keyboards.cpp"
#include"src\lib\PerlinNoise2.cpp"
#include"src\lib\ScriptsDLL.cpp"

#include"src\Definer.h"
#include"src\css\Player.h"

#include"src\css\Game.h"

#include"src\GlobalValue.cpp"

#include"src\func\Commands.cpp"

#include"src\mtd\Game.cpp"
#include"src\mtd\Player.cpp"



#include"src\func\KeyboardFunction.cpp"
#include"src\func\GUIFunction.cpp"


__cdecl void GameThreadTestLoadingMap( void * args )
{
	while(1)
	{
		if( keyboardobiect.downkeypressed[ 'U' ] )
		{
			GameInstantiation->engine.PauseAll();
			printf( "\n    Threads Stopped" );
			
			int BegginingTime = clock();
			
			GameInstantiation->engine.DestroyWorld();
			
			printf( "\n    Generate map" );
			GenerateMap___New();
			
			printf( "\n    Updating VBOs and terrain" );
			GameInstantiation->engine.UpdateWorld();
			printf( "\n    Terrain ans VBOs updated" );
			
			printf( "\n\n     Loading new map and updating time [ms]: %i\n\n", (int)(clock()-BegginingTime) );
			
			GameInstantiation->engine.ContinueAll();
			printf( "\n    Threads Working" );
		}
		
		Sleep( 1 );
	}
	
	_endthread();
}

#include"src\GameMain.cpp"


