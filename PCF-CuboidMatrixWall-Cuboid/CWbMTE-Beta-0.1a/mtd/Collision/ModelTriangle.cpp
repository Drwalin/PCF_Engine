


inline unsigned int Collision::ModelTriangle( PhysicModelStatic * model, TrianglePX * tri, float time )
{
	int i = 0;
	for( i = 0; i < model -> aabb.size(); i++ )
	{
		AABBTriangle( &(model -> aabb[i]), &(model -> pos), tri, time );
	}
	for( i = 0; i < model -> obb.size(); i++ )
	{
	//	OBBTriangle( &(model -> obb[i]), &(model -> pos), tri, time );
	}
	for( i = 0; i < model -> sphere.size(); i++ )
	{
		SphereTriangle( &(model -> sphere[i]), &(model -> pos), tri, time );
	}
}


