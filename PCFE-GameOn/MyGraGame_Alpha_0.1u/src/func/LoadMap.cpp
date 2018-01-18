


void LoadMap()
{
	GameInstance -> engine.DestroyWorld();
	GameInstance -> LoadMap( "..\\Media\\Maps\\testMap.map" );
	GameInstance -> engine.UpdateWorld();
}


