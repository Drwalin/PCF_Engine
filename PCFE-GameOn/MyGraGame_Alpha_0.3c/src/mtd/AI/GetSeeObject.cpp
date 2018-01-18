


inline bool AI::AmISeeObject( PhysicModelStatic * src )
{
	TrianglePX * triangle;
	PhysicModelStatic * object;
	
	Vector direction;
	direction = src -> GetBarycentricDraw() - parent -> object -> GetEyePos();
	direction.Normalize();
	
	VMatrix matrix;
	matrix.InitEmpty();
	matrix.RotateY( (parent -> object -> see[0]+90.0f) );
	matrix.RotateX( -(parent -> object -> see[1]) );
	
	float cosAngle = direction.Dot( matrix.GetVertex( SetVector( 0.0f, 0.0f, 1.0f ) ) );
	
	if( abs( acos(cosAngle) * 180.0f / float(M_PI) ) < 45.0f )
	{
		GameInstance->engine.SegmentCollision( parent -> object -> GetEyePos(), parent -> object -> GetEyePos() + direction * seeRange, &object, &triangle, parent -> object, SIGHT );
		if( object == src )
			return true;
	}
	
	return false;
}

inline Player * AI::GetSeeEnemy()
{
	int i;
	for( i = 0; i < GameInstance -> object.size(); ++i )
	{
		if( GameInstance -> object[i] -> IsPlayer() )
		{
			if( GameInstance -> object[i] -> player -> team > 0 && GameInstance -> object[i] -> player -> team != parent -> team )
			{
				if( AmISeeObject( GameInstance -> object[i] -> player -> object ) == true )
				{
					return GameInstance -> object[i] -> player;
				}
			}
		}
	}
	return NULL;
}

inline Player * AI::GetSeeFriend()
{
	int i;
	for( i = 0; i < GameInstance -> object.size(); ++i )
	{
		if( GameInstance -> object[i] -> IsPlayer() )
		{
			if( GameInstance -> object[i] -> player -> team > 0 && GameInstance -> object[i] -> player -> team == parent -> team && GameInstance -> object[i] -> player -> ai == NULL )
			{
				if( AmISeeObject( GameInstance -> object[i] -> player -> object ) == true )
				{
					return GameInstance -> object[i] -> player;
				}
			}
		}
	}
	return NULL;
}


