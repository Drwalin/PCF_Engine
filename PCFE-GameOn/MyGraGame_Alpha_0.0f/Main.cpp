


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

#include"src\lib\GetSthFromString.cpp"

//#include"..\..\PCF-CuboidMatrixWall-Cuboid\CWbMTE-Beta-0.1c\LibIncluder.c"
#include"..\..\PCF-CuboidMatrixWall-Cuboid\CWbMTE-Beta-0.1c\Engine.cpp"

/*
    Game source code:
*/

//#include"src\lib\GetSthFromString.cpp"
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
			printf( "\n\n    Threads Stopped" );
			GameInstantiation->engine.DestroyWorld();
			
			printf( "\n\n    Generate map" );
			GenerateMap___New();
			printf( " . . ." );
//			GameInstantiation->engine.map.UpdateObjectColliders();
			printf( "\n\n    End map generating" );
			GameInstantiation->engine.ContinueAll();
			printf( "\n\n    Threads Working" );
		}
		
		Sleep( 3 );
	}
	
	_endthread();
}

#include"src\GameMain.cpp"


