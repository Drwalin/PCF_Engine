
#define OBJTRI triangle[id_triangle]

inline bool Map::IfVectorPointCrossTriangle( Vector src1, Vector src2, unsigned int id_triangle, Vector * dst )      // sprawdza czy odcinek (np. krawêdŸ obiektu) ma punkt wspólny  z trójk¹tem
{
    Vector move_vector, move_versor, point_cross_triangle, _fast;
    float _t_, normal_move_versor,
          _01_, _12_, _02_,
          _p0_, _p1_, _p2_,
          _P_, _P01_, _P12_, _P02_;
    
    move_vector.CreateVector( src1, src2 );
    move_versor = move_vector.Versor();
    
    normal_move_versor = (OBJTRI.normal[0]*move_versor[0]) + (OBJTRI.normal[1]*move_versor[1]) + (OBJTRI.normal[2]*move_versor[2]);
    
    if( normal_move_versor == 0.0f )
    {
        return false;
    }
                    
    _t_ = ( -OBJTRI.det - (OBJTRI.normal[0]*src1[0]) - (OBJTRI.normal[1]*src1[1]) - (OBJTRI.normal[2]*src1[2]) )
          /
          ( normal_move_versor );
          
    if( _t_ < 0.0f || _t_ > move_vector.Lenght() )
    {
        return false;
    }
    
    point_cross_triangle = ( ( move_versor * _t_ ) + src1 );
                    
    _fast.CreateVector( OBJTRI.tri[0], OBJTRI.tri[1] );
    _01_ = _fast.Lenght();
    _fast.CreateVector( OBJTRI.tri[1], OBJTRI.tri[2] );
    _12_ = _fast.Lenght();
    _fast.CreateVector( OBJTRI.tri[0], OBJTRI.tri[2] );
    _02_ = _fast.Lenght();
    _fast.CreateVector( OBJTRI.tri[0], point_cross_triangle );
    _p0_ = _fast.Lenght();
    _fast.CreateVector( OBJTRI.tri[1], point_cross_triangle );
    _p1_ = _fast.Lenght();
    _fast.CreateVector( OBJTRI.tri[2], point_cross_triangle );
    _p2_ = _fast.Lenght();
                    
    _P_ = 0.25f * sqrt( 
                          ( ((_01_+_12_)*(_01_+_12_)) - (_02_*_02_) )
                          *
                          ( (_02_*_02_) - ((_01_-_12_)*(_01_-_12_)) ) );
    
    _P01_ = 0.25f * sqrt( 
                          ( ((_01_+_p0_)*(_01_+_p0_)) - (_p1_*_p1_) )
                          *
                          ( (_p1_*_p1_) - ((_01_-_p0_)*(_01_-_p0_)) ) );
    
    _P12_ = 0.25f * sqrt( 
                          ( ((_12_+_p2_)*(_12_+_p2_)) - (_p1_*_p1_) )
                          *
                          ( (_p1_*_p1_) - ((_12_-_p2_)*(_12_-_p2_)) ) );
    
    _P02_ = 0.25f * sqrt( 
                          ( ((_02_+_p0_)*(_02_+_p0_)) - (_p2_*_p2_) )
                          *
                          ( (_p2_*_p2_) - ((_02_-_p0_)*(_02_-_p0_)) ) );
    
    if( ( _P_ + DISCERPANCY_TRIANGLES_AREA ) >= ( _P01_ + _P12_ + _P02_ ) )
    {
        (*dst) = point_cross_triangle;
        return true;
    }
    else
    {
        return false;
    }
    
}

#undef OBJTRI
