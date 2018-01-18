


inline bool Button::IsPointInside( int srcx, int srcy )
{
	if( srcx > x && srcy > srcy && srcx < x+wx && srcy < y+wy )
		return true;
	return false;
}


Button::Button()
{
	x = 0;
	y = 0;
	wx = 0;
	wy = 0;
}


