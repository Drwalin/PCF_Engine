

inline unsigned int Collision::AABBTriangle( PhysicModelStatic * object, TrianglePX * tri, float time )
{
	int i;
	Vector pointfast;
	
	Vector begin = object -> pos;
	Vector end = begin + object -> size;
	
	if( ((tri->min) <= end) && ((tri->max) >= begin) )
	{
		{
			float p1dot = ((object->MaxWithVector(tri->normal))-(tri->vertex[0])).Dot(tri->normal);
			float p2dot = ((object->MaxWithVector(0.0f-tri->normal))-(tri->vertex[0])).Dot(tri->normal);
			if( ( ( p1dot <= 0.0f && p2dot <= 0.0f ) || ( p1dot >= 0.0f && p2dot >= 0.0f ) ) )
				return COLLISION_NO;
			Vector backObjectBarycentric = object -> bpos + ( object -> size * 0.5f );
			p1dot = (backObjectBarycentric-(tri->vertex[0])).Dot(tri->normal);
			if( p1dot < 0.0f )
				return COLLISION_NO;
		}
		
		object->contact.AddDirection( tri -> normal );
		
		{
			if( RayAABB( tri->vertex[0], tri->vertex[1], object, &pointfast ) )
				object->contact.AddPoint( pointfast );
			if( RayAABB( tri->vertex[1], tri->vertex[2], object, &pointfast ) )
				object->contact.AddPoint( pointfast );
			if( RayAABB( tri->vertex[2], tri->vertex[0], object, &pointfast ) )
				object->contact.AddPoint( pointfast );
			if( RayAABB( tri->vertex[1], tri->vertex[0], object, &pointfast ) )
				object->contact.AddPoint( pointfast );
			if( RayAABB( tri->vertex[2], tri->vertex[1], object, &pointfast ) )
				object->contact.AddPoint( pointfast );
			if( RayAABB( tri->vertex[0], tri->vertex[2], object, &pointfast ) )
				object->contact.AddPoint( pointfast );
			if( tri->vertex[0] <= end && tri->vertex[0] >= begin )
				object->contact.AddPoint( tri->vertex[0] );
			if( tri->vertex[1] <= end && tri->vertex[1] >= begin )
				object->contact.AddPoint( tri->vertex[1] );
			if( tri->vertex[2] <= end && tri->vertex[2] >= begin )
				object->contact.AddPoint( tri->vertex[2] );
		}
		
		Vector vertex[2][2][2];
		bool vertexpos[2][2][2];
		
		vertex[0][0][0] = object->GetVertex(0);
		vertex[1][0][0] = object->GetVertex(1);
		vertex[1][0][1] = object->GetVertex(2);
		vertex[0][0][1] = object->GetVertex(3);
		vertex[0][1][0] = object->GetVertex(4);
		vertex[1][1][0] = object->GetVertex(5);
		vertex[1][1][1] = object->GetVertex(6);
		vertex[0][1][1] = object->GetVertex(7);
		vertexpos[0][0][0] = ( ((vertex[0][0][0] - tri->vertex[0]).Dot( tri->normal )) < 0.0f ) ? false : true;
		vertexpos[0][0][1] = ( ((vertex[0][0][1] - tri->vertex[0]).Dot( tri->normal )) < 0.0f ) ? false : true;
		vertexpos[0][1][0] = ( ((vertex[0][1][0] - tri->vertex[0]).Dot( tri->normal )) < 0.0f ) ? false : true;
		vertexpos[0][1][1] = ( ((vertex[0][1][1] - tri->vertex[0]).Dot( tri->normal )) < 0.0f ) ? false : true;
		vertexpos[1][0][0] = ( ((vertex[1][0][0] - tri->vertex[0]).Dot( tri->normal )) < 0.0f ) ? false : true;
		vertexpos[1][0][1] = ( ((vertex[1][0][1] - tri->vertex[0]).Dot( tri->normal )) < 0.0f ) ? false : true;
		vertexpos[1][1][0] = ( ((vertex[1][1][0] - tri->vertex[0]).Dot( tri->normal )) < 0.0f ) ? false : true;
		vertexpos[1][1][1] = ( ((vertex[1][1][1] - tri->vertex[0]).Dot( tri->normal )) < 0.0f ) ? false : true;
		
		Vector fastVec;
		int x_, y_, z_;
		
		bool boolShit;
		
		for( x_ = 0; x_ < 2; ++x_ )
		{	
			for( y_ = 0; y_ < 2; ++y_ )
			{
				for( z_ = 0; z_ < 2; ++z_ )
				{
					if( x_ == 0 )
					{
						boolShit = tri -> PointIn( vertex[x_+1][y_][z_], vertex[x_][y_][z_], &fastVec );
						if( boolShit == true )
							object->contact.AddPoint( fastVec );
					}
					if( y_ == 0 )
					{
						boolShit = tri -> PointIn( vertex[x_][y_+1][z_], vertex[x_][y_][z_], &fastVec );
						if( boolShit == true )
							object->contact.AddPoint( fastVec );
					}
					if( z_ == 0 )
					{
						boolShit = tri -> PointIn( vertex[x_][y_][z_+1], vertex[x_][y_][z_], &fastVec );
						if( boolShit == true )
							object->contact.AddPoint( fastVec );
					}
				}
			}
		}
		
		if( object -> contact.points.back().size() == 0 )
		{
			object -> contact.direction.resize( object -> contact.direction.size() - 1 );
			object -> contact.points.resize( object -> contact.points.size() - 1 );
		}
		
		return COLLISION_IS;
	}
	return COLLISION_NO;
}


