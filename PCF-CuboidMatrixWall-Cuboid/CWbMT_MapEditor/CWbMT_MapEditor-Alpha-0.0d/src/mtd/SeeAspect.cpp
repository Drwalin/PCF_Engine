


inline bool SeeAspect::IsPointInside( int srcx, int srcy )
{
	if( srcx > x && srcy > y && srcx < x+wx && srcy < y+wy )
		return true;
	return false;
}


inline void DrawPoint( int x, int y, int size, unsigned char r, unsigned char g, unsigned char b )
{
	al_draw_filled_rectangle( x-(size/2), y-(size/2), x+(size/2), y+(size/2), al_map_rgb( r, g, b ) );
}


inline void SeeAspect::GetPoint( float srcx, float srcy, int * dstx, int * dsty )
{
	*dstx = int((srcx-mx)*scale);
	*dsty = wy-int((srcy-my)*scale);
}

inline void SeeAspect::GetPoint( int srcx, int srcy, float * dstx, float * dsty )
{
	*dstx = (float(srcx)/scale)+mx;
	*dsty = (float(wy-srcy)/scale)+my;
}


inline void SeeAspect::Draw()
{
	if( texture == NULL )
		texture = al_create_bitmap( wx, wy );
	al_set_target_bitmap( texture );
	
	al_clear_to_color( al_map_rgb( 0, 0, 0 ) );
	
	int _x, _y, i;
	{
		float x_, y_, ex, ey;
		
		GetPoint( 0, 0, &x_, &y_ );
		GetPoint( wx, wy, &ex, &ey );
		for( float nx = x_; nx <= ex; nx+=1.0f )
		{
			GetPoint( nx, 0.0f, &_x, &_y );
			al_draw_line( _x, 0, _x, wy, al_map_rgb( 0, 255, 0 ), 1 );
		}
		
		for( float ny = y_; ny >= ey; ny-=1.0f )
		{
			GetPoint( 0.0f, ny, &_x, &_y );
			al_draw_line( 0, _y, wx, _y, al_map_rgb( 0, 255, 0 ), 1 );
		}
		
		
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
			if( ActivatedVertex == i )
				DrawPoint( _x, _y, 7, 255, 255, 0 );
			else
				DrawPoint( _x, _y, 5, 255, 255, 255 );
		}
	}
	
	{
		float x_1, x_2, x_3, y_1, y_2, y_3;
		int bx, by, ex, ey;
		
		for( i = 0; i+2 < indices.size(); i+=3 )
		{
			switch( drawaxis )
			{
			case 1:
				x_1 = vertex[indices[i]][0];
				y_1 = vertex[indices[i]][1];
				x_2 = vertex[indices[i+1]][0];
				y_2 = vertex[indices[i+1]][1];
				x_3 = vertex[indices[i+2]][0];
				y_3 = vertex[indices[i+2]][1];
				break;
			case 2:
				x_1 = vertex[indices[i]][0];
				y_1 = vertex[indices[i]][2];
				x_2 = vertex[indices[i+1]][0];
				y_2 = vertex[indices[i+1]][2];
				x_3 = vertex[indices[i+2]][0];
				y_3 = vertex[indices[i+2]][2];
				break;
			case 3:
				x_1 = vertex[indices[i]][1];
				y_1 = vertex[indices[i]][2];
				x_2 = vertex[indices[i+1]][1];
				y_2 = vertex[indices[i+1]][2];
				x_3 = vertex[indices[i+2]][1];
				y_3 = vertex[indices[i+2]][2];
				break;
			}
			
			GetPoint( x_1, y_1, &bx, &by );
			GetPoint( x_2, y_2, &ex, &ey );
			al_draw_line( bx, by, ex, ey, al_map_rgb( 255, 255, 255 ), 1 );
			GetPoint( x_1, y_1, &bx, &by );
			GetPoint( x_3, y_3, &ex, &ey );
			al_draw_line( bx, by, ex, ey, al_map_rgb( 255, 255, 255 ), 1 );
			GetPoint( x_2, y_2, &bx, &by );
			GetPoint( x_3, y_3, &ex, &ey );
			al_draw_line( bx, by, ex, ey, al_map_rgb( 255, 255, 255 ), 1 );
		}
	}
	
	al_draw_rectangle( 1, 1, wx, wy, al_map_rgb( 128, 128, 128 ), 3 );
}



SeeAspect::SeeAspect()
{
	texture = NULL;
	mx = 0.0f;
	my = 0.0f;
	scale = 20.0f;
	drawaxis = 1;
	activate = false;
	x = 200;
	y = 384;
	wx = 312;
	wy = 384;
}


