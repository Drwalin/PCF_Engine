


inline unsigned int Collision::ModelTriangle( PhysicModelStatic * model, TrianglePX * tri, float time )
{
	switch( model -> type )
	{
	case PXMODEL_AABB:
		AABBTriangle( ((AABB*)(model -> object)), tri, time );
	case PXMODEL_OBB:
	//	OBBTriangle( ((OBB*)(model -> object)), tri, time );
	case PXMODEL_Sphere:
		SphereTriangle( ((Sphere*)(model -> object)), tri, time );
	}
}


