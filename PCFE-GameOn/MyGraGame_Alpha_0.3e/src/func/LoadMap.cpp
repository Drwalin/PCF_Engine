


void LoadMap()
{
	GameInstance -> LoadMap( "..\\Media\\Maps\\testMap.map" );
	
	float distance = 30.0f;
	
	scanf( "%f", &distance );
	
	GameInstance -> engine.AddVBO( GameInstance -> engine.TextureId( "textmodel" ) );
	GameInstance -> engine.AddVertexToLastVBO( distance, -1000, -1000, 0, 0 );
	GameInstance -> engine.AddVertexToLastVBO( distance, -1000, 1000, 0, 1 );
	GameInstance -> engine.AddVertexToLastVBO( distance, 1000, 1000, 1, 1 );
	GameInstance -> engine.CreateTriangleWithLastThreeVertices();
	GameInstance -> engine.AddVertexToLastVBO( distance, -1000, -1000, 0, 0 );
	GameInstance -> engine.AddVertexToLastVBO( distance, 1000, -1000, 1, 0 );
	GameInstance -> engine.AddVertexToLastVBO( distance, 1000, 1000, 1, 1 );
	GameInstance -> engine.CreateTriangleWithLastThreeVertices();
	
	GameInstance -> engine.UpdateWorld();
}


