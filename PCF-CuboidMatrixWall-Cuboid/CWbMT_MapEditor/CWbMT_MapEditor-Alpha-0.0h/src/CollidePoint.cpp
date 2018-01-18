


int CollidePoint( int x, int y, SeeAspect *wind )
{
	int i;
	float x_, y_;
	int _x, _y;
	for( i = 0; i < vertex.size(); i++ )
	{
		if( wind -> win != NULL )
		{
			
		}
		else
		{
			switch( wind -> drawaxis )
			{
			case 1:
				x_ = vertex[i][0];
				y_ = vertex[i][1];
				break;
			case 2:
				x_ = vertex[i][0];
				y_ = vertex[i][2];
				break;
			case 3:
				x_ = vertex[i][2];
				y_ = vertex[i][1];
				break;	
			}
			wind->GetPoint( x_, y_, &_x, &_y );
			if( abs(_x-(x-(wind->x))) < 8 && abs(_y-(y-(wind->y))) < 8 )
				return i;
		}
	}
	return -1;
}


