


inline unsigned int Collision::ModelModel( PhysicModelStatic * model1, PhysicModelStatic * model2, float time )
{
	unsigned int dst = 0;
	int i, j;
	for( i = 0; i < model1->aabb.size(); i++ )
	{
		for( j = 0; j < model2->aabb.size(); j++ )
		{
			AABBAABB( &(model1->aabb[i]), &(model1->pos), &(model2->aabb[j]), &(model2->pos), time );
		}
		for( j = 0; j < model2->obb.size(); j++ )
		{
//			AABBOBB( &(model1->aabb[i]), &(model1->pos), &(model2->obb[j]), &(model2->pos), time );
		}
		for( j = 0; j < model2->sphere.size(); j++ )
		{
//			AABBSphere( &(model1->aabb[i]), &(model1->pos), &(model2->sphere[j]), &(model2->pos), time );
		}
	}
	
	for( i = 0; i < model1->obb.size(); i++ )
	{
		for( j = 0; j < model2->obb.size(); j++ )
		{
//			OBBOBB( &(model1->obb[i]), &(model1->pos), &(model2->obb[j]), &(model2->pos), time );
		}
		for( j = 0; j < model2->sphere.size(); j++ )
		{
//			OBBSphere( &(model1->obb[i]), &(model1->pos), &(model2->sphere[j]), &(model2->pos), time );
		}
	}
	
	for( i = 0; i < model1->sphere.size(); i++ )
	{
		for( j = 0; j < model2->sphere.size(); j++ )
		{
//			SphereSphere( &(model1->sphere[i]), &(model1->pos), &(model2->sphere[j]), &(model2->pos), time );
		}
	}
}


