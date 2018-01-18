


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
	if( win != NULL )
	{
		*dstx = int( ( (float(wx)/2.0f) * srcx / 1.1917f ) + (float(wx)/2.0f) );
		*dsty = wy - int( (float(wy)/2.0f) + ( (float(wy)/2.0f) * srcy / (1.1917f*float(wy)/float(wx)) ) );
	}
	else
	{
		*dstx = int((srcx-mx)*scale);
		*dsty = wy-int((srcy-my)*scale);
	}
}

inline void SeeAspect::GetPoint( int srcx, int srcy, float * dstx, float * dsty )
{
	if( win != NULL )
	{
		*dstx = (((2.0f * float(srcy))/float(wx))-1.0f) * 1.1917f;
		*dsty = (1.1917f*float(wy)/float(wx))*( 1.0f-( 2.0f*float(srcy)/float(wy) ) );
	}
	else
	{
		*dstx = (float(srcx)/scale)+mx;
		*dsty = (float(wy-srcy)/scale)+my;
	}
}


inline void SeeAspect::Draw()
{
	if( texture == NULL )
		texture = al_create_bitmap( wx, wy );
	al_set_target_bitmap( texture );
	al_clear_to_color( al_map_rgb( 0, 0, 0 ) );
	
	
	if( win != NULL )
	{
		int i, _x, _y, bx, by, ex, ey;
		win -> Update( 0.0f, 0.0f, SetVector( 0.0f, 0.0f, 0.0f ) );
		for( i = 0; i < vertex.size(); i++ )
		{
			win -> AddPoint( vertex[i].pos );
			
			if( win->points[i][2] > 0.1f )
			{
				GetPoint( win->points[i][0], win->points[i][1], &_x, &_y );
				if( RENDER_OPTION[USE_CONNECTING_POINTS] == true )
				{
					int j;
					for( j = 0; j < ConnectedPoints.size(); j++ )
					{
						if( i == ConnectedPoints[j] )
						{
							DrawPoint( _x, _y, 12, 255, 0, 0 );
							break;
						}
					}
				}
				if( ActivatedVertex == i )
					DrawPoint( _x, _y, 7, 255, 255, 0 );
				else
					DrawPoint( _x, _y, 5, 255, 255, 255 );
			}
		}
		
		
		for( i = 0; i+2 < indices.size(); i += 3 )
		{
//			GetPoint( win->points[i][0], win->points[i][1], &_x, &_y );
			
			if( win->points[indices[i]][2] > 0.1f && win->points[indices[i+1]][2] > 0.1f && win->points[indices[i+2]][2] > 0.1f )
			{
				GetPoint( win->points[indices[i]  ][0], win->points[indices[i]  ][1], &bx, &by );
				GetPoint( win->points[indices[i+1]][0], win->points[indices[i+1]][1], &ex, &ey );
				al_draw_line( bx, by, ex, ey, al_map_rgb( 255, 255, 255 ), 1 );
				GetPoint( win->points[indices[i]  ][0], win->points[indices[i]  ][1], &bx, &by );
				GetPoint( win->points[indices[i+2]][0], win->points[indices[i+2]][1], &ex, &ey );
				al_draw_line( bx, by, ex, ey, al_map_rgb( 255, 255, 255 ), 1 );
				GetPoint( win->points[indices[i+2]][0], win->points[indices[i+2]][1], &bx, &by );
				GetPoint( win->points[indices[i+1]][0], win->points[indices[i+1]][1], &ex, &ey );
				al_draw_line( bx, by, ex, ey, al_map_rgb( 255, 255, 255 ), 1 );
			}
		}
		
		if( RENDER_OPTION[DRAW_NORMALS] == true )
		{
			Vector fast_vec;
			for( i = 0; i < triangles.size(); i++ )
			{
				fast_vec = triangles[i].GetBeginNormal();
				win->AddPoint( fast_vec );
				win->AddPoint( fast_vec + triangles[i].normal );
				GetPoint( win->points[win->points.size()-2][0], win->points[win->points.size()-2][1], &bx, &by );
				GetPoint( win->points[win->points.size()-1][0], win->points[win->points.size()-1][1], &ex, &ey );
				if( win->points[win->points.size()-2][2] > 0.1f && win->points[win->points.size()-1][2] > 0.1f )
					al_draw_line( bx, by, ex, ey, al_map_rgb( 255, 0, 255 ), 1 );
				win->points.resize( win->points.size()-2 );
			}
		}
		
		win -> AddPoint( SetVector( 0.0f, 0.0f, 0.0f ) );
		win -> AddPoint( SetVector( 100.0f, 0.0f, 0.0f ) );
		win -> AddPoint( SetVector( 0.0f, 100.0f, 0.0f ) );
		win -> AddPoint( SetVector( 0.0f, 0.0f, 100.0f ) );
		
		if( win->points[win->points.size()-4][2] > 0.1f )
		{
			if( win->points[win->points.size()-3][2] > 0.1f )
			{
				GetPoint( win->points[win->points.size()-4][0], win->points[win->points.size()-4][1], &bx, &by );
				GetPoint( win->points[win->points.size()-3][0], win->points[win->points.size()-3][1], &ex, &ey );
				al_draw_line( bx, by, ex, ey, al_map_rgb( 255, 0, 0 ), 1 );
			}
			if( win->points[win->points.size()-2][2] > 0.1f )
			{
				GetPoint( win->points[win->points.size()-4][0], win->points[win->points.size()-4][1], &bx, &by );
				GetPoint( win->points[win->points.size()-2][0], win->points[win->points.size()-2][1], &ex, &ey );
				al_draw_line( bx, by, ex, ey, al_map_rgb( 0, 255, 0 ), 1 );
			}
			if( win->points[win->points.size()-1][2] > 0.1f )
			{
				GetPoint( win->points[win->points.size()-4][0], win->points[win->points.size()-4][1], &bx, &by );
				GetPoint( win->points[win->points.size()-1][0], win->points[win->points.size()-1][1], &ex, &ey );
				al_draw_line( bx, by, ex, ey, al_map_rgb( 0, 0, 255 ), 1 );
			}
		}
		
		win->points.resize( win->points.size()-4 );
		
		al_draw_rectangle( 1, 1, wx, wy, al_map_rgb( 128, 128, 128 ), 3 );
		return;
	}
	
	
	
	int _x, _y, i;
	{
		float x_, y_;
		{
			float ex, ey;
			if( RENDER_OPTION[DRAW_GRID] )
			{
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
			}
		}
		
		int ex, ey;
		
		GetPoint( 0.0f, 0.0f, &_x, &_y );
		GetPoint( 0.0f, 1000000.0f, &ex, &ey );
		al_draw_line( _x, -ey, ex, ey, al_map_rgb( 255, 0, 0 ), 2 );
		GetPoint( 1000000.0f, 0.0f, &ex, &ey );
		al_draw_line( -ex, _y, ex, ey, al_map_rgb( 255, 0, 0 ), 2 );
		
		
		
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
				x_ = vertex[i][2];
				y_ = vertex[i][1];
				break;
			}
			
			GetPoint( x_, y_, &_x, &_y );
			if( RENDER_OPTION[USE_CONNECTING_POINTS] == true )
			{
				int j;
				for( j = 0; j < ConnectedPoints.size(); j++ )
				{
					if( i == ConnectedPoints[j] )
					{
						DrawPoint( _x, _y, 12, 255, 0, 0 );
					}
				}
			}
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
				x_1 = vertex[indices[i]][2];
				y_1 = vertex[indices[i]][1];
				x_2 = vertex[indices[i+1]][2];
				y_2 = vertex[indices[i+1]][1];
				x_3 = vertex[indices[i+2]][2];
				y_3 = vertex[indices[i+2]][1];
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
	win = NULL;
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


