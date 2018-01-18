

/*
class LightningVertex
{
public:
	Vector vertex;
	float width;
	float collor[3];
	vector<LightningVertex> childs;
};
*/
inline void LightningVertex::DrawChilds( int number, bool begin )
{
	if( begin == false )
	{
			glVertex3fv( &(vertex[0]) );
		glEnd();
	}
	if( number >= 1 )
	{
		int i;
		for( i = 0; i < childs.size(); i++ )
		{
			glLineWidth( width );
			glColor3fv( collor );
			glBegin( GL_LINES );
			glVertex3fv( &(vertex[0]) );
			childs[i].DrawChilds( number-1, false );
		}
	}
}

LightningVertex::LightningVertex()
{
	vertex.Set( 0.0f, 0.0f, 0.0f );
	width = 3.0f;
	collor[0] = 1.0f;
	collor[1] = 1.0f;
	collor[2] = 1.0f;
}

LightningVertex::~LightningVertex()
{
	vertex.Set( 0.0f, 0.0f, 0.0f );
	width = 0.0f;
	collor[0] = 0.0f;
	collor[1] = 0.0f;
	collor[2] = 0.0f;
	childs.resize( 0 );
}




/*
class Lightning
{
private:
	int segments;
	float goingTime;
	float EndingTime;
	
	float actualTime;
	LightningVertex vertex;
};*/

inline void Lightning::Draw()
{
	printf( "dwadaaf f" );
	vertex.DrawChilds( int(float(segments+1)*actualTime/goingTime), true );
}

inline void Lightning::Update( float FrameTime )
{
	actualTime += FrameTime;
//	if( EndingTime < actualTime )
//		~Lightning();
}

inline void Lightning::Set( Vector begin_, Vector end_, float beginWidth_, float EndWidth_, float r1_, float g1_, float b1_, float r2_, float g2_, float b2_, int segments_, float branch_, float branchDensity_, float beginTime, float endTime )
{
	//return;
	segments = segments_;
	Vector points[segments+1];
	int i;
	{
		Vector direction = end_ - begin_;
		float lenght = direction.Lenght();
		direction = direction / lenght;
		for( i = 0; i <= segments; i++ )
		{
			points[i] = begin_ + (direction * float(i) / float(segments));
		}
	}
	for( i = 1; i < segments; i++ )
	{
		points[i] = points[i] + SetVector( branch_ * float((rand()%10000)-5000)/5000.0f, branch_ * float((rand()%10000)-5000)/5000.0f, branch_ * float((rand()%10000)-5000)/5000.0f );
	}
	LightningVertex * vert;
	vert = &(this->vertex);
	LightningVertex * fadwadadadwdst;
	LightningVertex fgvgjhjybhjvghtydt;
	for( i = 0; i <= segments; i++ )
	{
		vert -> vertex = points[i];
		vert -> width = ((beginWidth_-EndWidth_) * float(i) / float(segments)) + EndWidth_;
		vert -> collor[0] = ((r1_-r2_) * float(i) / float(segments)) + r2_;
		vert -> collor[1] = ((g1_-g2_) * float(i) / float(segments)) + g2_;
		vert -> collor[2] = ((b1_-b2_) * float(i) / float(segments)) + b2_;
		if( i < segments )
		{
			vert -> childs.push_back( fgvgjhjybhjvghtydt );
			//(vert -> childs).resize( 1 );
			vert = &((vert -> childs)[0]);;
		}
	}
	printf( "adda" );
}

Lightning::Lightning()
{
	segments = 20;
	goingTime = 1.0f;
	EndingTime = 0.0f;
	actualTime = 0.0f;
}

Lightning::~Lightning()
{
	segments = 0;
	goingTime = 0.0f;
	EndingTime = 0.0f;
	actualTime = 0.0f;
}


