


int CollidePoint( int x, int y, SeeAspect *wind )
{
	int i;
	float x_, y_;
	int _x, _y;
	int dst = -1;
	
	float m_x = mouse.x-wind->x;
	float m_y = mouse.y-wind->y;
	
	if( wind -> win != NULL )
	{
		float ex, ey, l = -1.0f;
		int fx, fy;
		for( i = 0; i < vertex.size(); i++ )
		{
			if( wind->win->points[i][2] > l )
			{
				wind->GetPoint( wind->win->points[i][0], wind->win->points[i][1], &fx, &fy );
				if( abs(fx-m_x) < 8 && abs(fy-m_y) < 8 )
				{
					l = wind->win->points[i][2];
					dst = i;
				}
			}
		}
		return dst;
	}
	else
	{
		for( i = 0; i < vertex.size(); i++ )
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


