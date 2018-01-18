


void LoadMap()
{
	GameInstance->engine.DestroyWorld();
	GameInstance->engine.AddGraphicModelAsMap( "..\\Media\\StaticModels\\Glock311.obj", GameInstance -> engine.TextureId( "Glock311" ) );
	GameInstance->engine.AddGraphicModelAsMap( "..\\Media\\StaticModels\\maptest.obj", GameInstance -> engine.TextureId( "auvBG" ) );
	GameInstance->LoadObjAsPhysic( "..\\Media\\StaticModels\\maptest.obj" );
	GameInstance->engine.UpdateWorld();
}


