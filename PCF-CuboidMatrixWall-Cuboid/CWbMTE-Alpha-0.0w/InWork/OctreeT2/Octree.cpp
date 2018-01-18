


inline void * Octree::operator[] ( const int id )
{
	return items[id];
}

inline void Octree::AddItem( void * src )
{
	items.push_back( src );
}

inline void Octree::SetItem( int id, void * src )
{
	items[id] = src;
}

inline void Octree::CreateChildrens()
{
	if( next == NULL )
		next = new Octree[8];
}

inline void Octree::DeleteChildrens()
{
	if( next != NULL )
	{
		next -> DeleteChildrens();
		(next+1) -> DeleteChildrens();
		(next+1) -> ~Octree();
		(next+2) -> DeleteChildrens();
		(next+2) -> ~Octree();
		(next+3) -> DeleteChildrens();
		(next+3) -> ~Octree();
		(next+4) -> DeleteChildrens();
		(next+4) -> ~Octree();
		(next+5) -> DeleteChildrens();
		(next+5) -> ~Octree();
		(next+6) -> DeleteChildrens();
		(next+6) -> ~Octree();
		(next+7) -> DeleteChildrens();
		(next+7) -> ~Octree();
		delete[] next;
	}
	items.resize( 0 );
}


Octree::Octree()
{
	next = NULL;
}

Octree::~Octree()
{
	DeleteChildrens();
}



// OPERATE OCTREE:



inline void OperateOctree::SetAt( Vector begin, Vector end, void * src )
{
	begin = begin - offset;
	end = end - offset;
	
	if( begin < 0.0f || !(end < size) )
	{
		octree_out.AddItem( src );
		return;
	}
	
	int actuallevel = 0;
	int idbegin = 0;
	int idend = 0;
	
	Vector size_next = size;
	
	if( octree == NULL )
	{
		octree = new Octree;
	}
	
	Octree * actual_octree = octree;
	
	for( ; actuallevel < maxChildren-1; actuallevel++ )
	{
		if( actual_octree == NULL )
		{
			printf( "i" );
			return;
		}
		
		size_next *= 0.5f;
		idbegin = 0;
		idend = 0;
		
		if( begin[0] >= size_next[0] )
		{
			idbegin += 1;
			begin[0] -= size_next[0];
		}
		
		if( begin[1] >= size_next[1] )
		{
			idbegin += 2;
			begin[1] -= size_next[1];
		}
		
		if( begin[2] >= size_next[2] )
		{
			idbegin += 4;
			begin[2] -= size_next[2];
		}
		
		
		
		if( end[0] >= size_next[0] )
		{
			idend += 1;
			end[0] -= size_next[0];
		}
		
		if( end[1] >= size_next[1] )
		{
			idend += 2;
			end[1] -= size_next[1];
		}
		
		if( end[2] >= size_next[2] )
		{
			idend += 4;
			end[2] -= size_next[2];
		}
		
		if( idbegin != idend || (actuallevel>=(maxChildren-1)) )
			break;
		
		if( actual_octree -> next == NULL )
			actual_octree -> CreateChildrens();
		
		actual_octree = ( (actual_octree -> next) + idbegin );
	}
	
	actual_octree -> AddItem( src );
	return;
}




inline vector < void * > OperateOctree::GetFrom( Vector begin, Vector end )
{
	int i = 0;
	vector < void * > tab;
	
	begin = begin - offset;
	end = end - offset;
	
	if( begin < 0.0f || !(end < size) )
	{
		tab = octree_out.items;
		return tab;
	}
	
	int actuallevel = 0;
	int idbegin = 0;
	int idend = 0;
	
	Vector size_next = size;
	
	Octree * actual_octree = octree;
	
	for( ; actuallevel < maxChildren-1; actuallevel++ )
	{
		if( actual_octree == NULL )
			break;
		
		for( int i = 0; i < (actual_octree -> items).size(); i++ )
		{
			tab.push_back( (actual_octree -> items)[i] );
		}
		
		size_next = size_next * 0.5f;
		idbegin = 0;
		idend = 0;
		
		if( begin[0] >= size_next[0] )
		{
			idbegin += 1;
			begin[0] -= size_next[0];
		}
		
		if( begin[1] >= size_next[1] )
		{
			idbegin += 2;
			begin[1] -= size_next[1];
		}
		
		if( begin[2] >= size_next[2] )
		{
			idbegin += 4;
			begin[2] -= size_next[2];
		}
		
		
		
		if( end[0] >= size_next[0] )
		{
			idend += 1;
			end[0] -= size_next[0];
		}
		
		if( end[1] >= size_next[1] )
		{
			idend += 2;
			end[1] -= size_next[1];
		}
		
		if( end[2] >= size_next[2] )
		{
			idend += 4;
			end[2] -= size_next[2];
		}
		
		if( idbegin != idend || ( actuallevel >= (maxChildren-1) ) )
			break;
		
		if( actual_octree -> next == NULL )
			break;
		
		actual_octree = ( (actual_octree -> next) + idbegin );
	}
	return tab;
}



inline void OperateOctree::Clear()
{
	octree -> DeleteChildrens();
	
	octree_out.DeleteChildrens();
}

OperateOctree::OperateOctree()
{
	octree = new Octree;
	offset[0] = 0.0f;
	offset[1] = 0.0f;
	offset[2] = 0.0f;
	size[0] = 10.0f;
	size[1] = 10.0f;
	size[2] = 10.0f;
	maxChildren = 10;
}

OperateOctree::~OperateOctree()
{
	if( octree != NULL )
	{
		octree -> DeleteChildrens();
		delete octree;
	}
	offset[0] = 0.0f;
	offset[1] = 0.0f;
	offset[2] = 0.0f;
	size[0] = 0.0f;
	size[1] = 0.0f;
	size[2] = 0.0f;
	maxChildren = 0;
}


