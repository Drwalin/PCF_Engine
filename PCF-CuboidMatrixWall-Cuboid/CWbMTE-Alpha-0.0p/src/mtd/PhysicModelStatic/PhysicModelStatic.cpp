
/*
	switch( type )
	{
	case PXMODEL_AABB:
		
		break;
	case PXMODEL_OBB:
		
		break;
	case PXMODEL_Sphere:
		
		break;
	}
*/

inline float PhysicModelStatic::GetMass()
{
	switch( type )
	{
	case PXMODEL_AABB:
		return ((AABB*)(object))->mass;
	case PXMODEL_OBB:
		return ((OBB*)(object))->mass;
	case PXMODEL_Sphere:
		return ((Sphere*)(object))->mass;
	}
}

inline Vector PhysicModelStatic::GetMin()
{
	switch( type )
	{
	case PXMODEL_AABB:
		return ((AABB*)(object))->pos;
	case PXMODEL_OBB:
		return ((OBB*)(object))->pos;	// -
	case PXMODEL_Sphere:
		return (((Sphere*)(object))->pos) - SetVector( ((Sphere*)(object))->radian, ((Sphere*)(object))->radian, ((Sphere*)(object))->radian );
	}
}

inline Vector PhysicModelStatic::GetMax()
{
	switch( type )
	{
	case PXMODEL_AABB:
		return ( ((AABB*)(object))->pos + ((AABB*)(object))->size );
	case PXMODEL_OBB:
		return ( ((OBB*)(object))->pos + ((OBB*)(object))->size );	// -
	case PXMODEL_Sphere:
		return ( (((Sphere*)(object))->pos) + SetVector( ((Sphere*)(object))->radian, ((Sphere*)(object))->radian, ((Sphere*)(object))->radian ) );
	}
}

inline float PhysicModelStatic::GetMinX()
{
	switch( type )
	{
	case PXMODEL_AABB:
		return ((AABB*)(object))->pos[0];
	case PXMODEL_OBB:
		return ( ((OBB*)(object))->pos[0] - ((OBB*)(object))->size.Lenght() );	// -
	case PXMODEL_Sphere:
		return  ((((Sphere*)(object))->pos) - SetVector( ((Sphere*)(object))->radian, ((Sphere*)(object))->radian, ((Sphere*)(object))->radian ) )[0];
	}
}

inline float PhysicModelStatic::GetMinY()
{
	switch( type )
	{
	case PXMODEL_AABB:
		return ((AABB*)(object))->pos[1];
	case PXMODEL_OBB:
		return ( ((OBB*)(object))->pos[1] - ((OBB*)(object))->size.Lenght() );	// -
	case PXMODEL_Sphere:
		return ( (((Sphere*)(object))->pos) - SetVector( ((Sphere*)(object))->radian, ((Sphere*)(object))->radian, ((Sphere*)(object))->radian ) )[1];
	}
}

inline float PhysicModelStatic::GetMinZ()
{
	switch( type )
	{
	case PXMODEL_AABB:
		return ((AABB*)(object))->pos[2];
	case PXMODEL_OBB:
		return ( ((OBB*)(object))->pos[2] - ((OBB*)(object))->size.Lenght() );	// -
	case PXMODEL_Sphere:
		return ( (((Sphere*)(object))->pos) - SetVector( ((Sphere*)(object))->radian, ((Sphere*)(object))->radian, ((Sphere*)(object))->radian ) )[2];
	}
}

inline float PhysicModelStatic::GetMaxX()
{
	switch( type )
	{
	case PXMODEL_AABB:
		return ( ((AABB*)(object))->pos + ((AABB*)(object))->size )[0];
	case PXMODEL_OBB:
		return ( ((OBB*)(object))->pos[0] + ((OBB*)(object))->size.Lenght() );	// -
	case PXMODEL_Sphere:
		return ( (((Sphere*)(object))->pos) + SetVector( ((Sphere*)(object))->radian, ((Sphere*)(object))->radian, ((Sphere*)(object))->radian ) )[0];
	}
}

inline float PhysicModelStatic::GetMaxY()
{
	switch( type )
	{
	case PXMODEL_AABB:
		return ( ((AABB*)(object))->pos + ((AABB*)(object))->size )[1];
	case PXMODEL_OBB:
		return ( ((OBB*)(object))->pos[1] + ((OBB*)(object))->size.Lenght() );	// -
	case PXMODEL_Sphere:
		return ( (((Sphere*)(object))->pos) + SetVector( ((Sphere*)(object))->radian, ((Sphere*)(object))->radian, ((Sphere*)(object))->radian ) )[1];
	}
}

inline float PhysicModelStatic::GetMaxZ()
{
	switch( type )
	{
	case PXMODEL_AABB:
		return ( ((AABB*)(object))->pos + ((AABB*)(object))->size )[2];
	case PXMODEL_OBB:
		return ( ((OBB*)(object))->pos[2] + ((OBB*)(object))->size.Lenght() );	// -
	case PXMODEL_Sphere:
		return ( (((Sphere*)(object))->pos) + SetVector( ((Sphere*)(object))->radian, ((Sphere*)(object))->radian, ((Sphere*)(object))->radian ) )[2];
	}
}



inline void PhysicModelStatic::UpdatePossition( float time )
{
	switch( type )
	{
	case PXMODEL_AABB:
		((AABB*)(object))->bpos = ((AABB*)(object))->pos;
		((AABB*)(object))->pos += ((AABB*)(object))->vel * time;
		break;
	case PXMODEL_OBB:
		((OBB*)(object))->bpos = ((OBB*)(object))->pos;
		((OBB*)(object))->pos += ((OBB*)(object))->vel * time;
		((OBB*)(object))->rotate *= ((OBB*)(object))->rotatespeed;
		break;
	case PXMODEL_Sphere:
		((Sphere*)(object))->bpos = ((Sphere*)(object))->pos;
		((Sphere*)(object))->pos += ((Sphere*)(object))->vel * time;
		break;
	}
}

inline void PhysicModelStatic::UpdateVelocity( float time )
{
	switch( type )
	{
	case PXMODEL_AABB:
		((AABB*)(object))->vel += ((AABB*)(object))->force * time / ((AABB*)(object))->mass;
		((AABB*)(object))->vel += ((AABB*)(object))->resistanceforce * time / ((AABB*)(object))->mass;
		break;
	case PXMODEL_OBB:
		((OBB*)(object))->vel += ((OBB*)(object))->force * time / ((OBB*)(object))->mass;
		((OBB*)(object))->vel += ((OBB*)(object))->resistanceforce * time / ((OBB*)(object))->mass;
		break;
	case PXMODEL_Sphere:
		((Sphere*)(object))->vel += ((Sphere*)(object))->force * time / ((Sphere*)(object))->mass;
		((Sphere*)(object))->vel += ((Sphere*)(object))->resistanceforce * time / ((Sphere*)(object))->mass;
		break;
	}
}

inline void PhysicModelStatic::IdentityForce()
{
	switch( type )
	{
	case PXMODEL_AABB:
		((AABB*)(object))->force.Set( 0.0f, 0.0f, 0.0f );
		((AABB*)(object))->resistanceforce.Set( 0.0f, 0.0f, 0.0f );
		((AABB*)(object))->CollisionDown = false;
		((AABB*)(object))->CollisionUp = false;
		((AABB*)(object))->CollisionSide = false;
		break;
	case PXMODEL_OBB:
		((OBB*)(object))->force.Set( 0.0f, 0.0f, 0.0f );
		((OBB*)(object))->resistanceforce.Set( 0.0f, 0.0f, 0.0f );
		((OBB*)(object))->rotatespeed.InitEmpty();
		break;
	case PXMODEL_Sphere:
		((Sphere*)(object))->force.Set( 0.0f, 0.0f, 0.0f );
		((Sphere*)(object))->resistanceforce.Set( 0.0f, 0.0f, 0.0f );
		break;
	}
}



PhysicModelStatic::PhysicModelStatic()
{
	object = NULL;
	type = PXMODEL_NONE;
	
	see[0] = 0.0f;
	see[1] = 0.0f;
	seeaspect = 90.0f;
	
	CollisionUse = true;
	Draw = false;
	MoveUse = true;
	
	model = NULL;
}

PhysicModelStatic::~PhysicModelStatic()
{
	see[0] = 0.0f;
	see[1] = 0.0f;
	seeaspect = 0.0f;
	
	CollisionUse = false;
	Draw = false;
	MoveUse = false;
	
	model = NULL;
	
	if( object != NULL )
	{
		switch( type )
		{
		case PXMODEL_AABB:
			delete ((AABB*)(object));
			break;
		case PXMODEL_OBB:
			delete ((OBB*)(object));
			break;
		case PXMODEL_Sphere:
			delete ((Sphere*)(object));
			break;
		}
		object = NULL;
	}
	
	type = 0;
}


