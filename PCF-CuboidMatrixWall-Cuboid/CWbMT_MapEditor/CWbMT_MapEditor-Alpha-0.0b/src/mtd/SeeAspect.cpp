


inline void DrawPoint( int x, int y, int size, unsigned char r, unsigned char g, unsigned char b )
{
	al_draw_rectangle( x-(size/2), y-(size/2), x+(size/2), y+(size/2), al_map_rgb( r, g, b ), 1 );
}


inline void SeeAspect::GetPoint( float srcx, float srcy, int * dstx, int * dsty )
{
	*dstx = int((srcx-mx)*scale);
	*dsty = int((-srcy-my)*scale);
}

inline void SeeAspect::GetPoint( int srcx, int srcy, float * dstx, float * dsty )
{
	*dstx = float(srcx+mx)/scale;
	*dsty = float(-srcy+my)/scale;
}


inline void SeeAspect::Draw()
{
	al_set_target_bitmap( texture );
	
	int _x, _y, i;
	float x_, y_;
	
	for( i = 0; i < vertex.size(); i++ )
	{
		switch( drawaxis )
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
			x_ = vertex[i][1];
			y_ = vertex[i][2];
			break;
		}
		
		GetPoint( x_, y_, &_x, &_y );
		DrawPoint( _x, _y, 3, 32, 32, 32 );
	}
}



SeeAspect::SeeAspect()
{
	texture = al_create_bitmap( 312, 384 );
	mx = 0.0f;
	my = 0.0f;
	scale = 1.0f;
	drawaxis = 1;
	activate = false;
	x = 200;
	y = 384;
	wx = 312;
	wy = 384;
}


