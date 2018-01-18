


inline void * Octree::operator[] ( const int id )
{
	return (void*)(*(items+id));
}

inline void Octree::AddItem( void * src )
{
	int i;
	void ** fast = new void*[size+1];
	for( i = 0; i < size; i++ )
	{
		*(fast+i) = *(items+i);
	}
	delete[] items;
	*(fast+size) = src;
	items = fast;
	fast = NULL;
	size++;
}

inline void Octree::SetItem( int id, void * src )
{
	*(items+id) = src;
}

inline void Octree::Resize( int src )
{
	int i;
	void ** fast = new void*[size+1];
	for( i = 0; i < size; i++ )
	{
		*(fast+i) = *(items+i);
	}
	delete[] items;
	items = fast;
	fast = NULL;
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
	if( items != NULL )
		delete[] items;
	size = 0;
}


Octree::Octree()
{
	items = NULL;
	next = NULL;
	size = 0;
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
	
	Octree * actual_octree = octree;
	
	for( ; actuallevel < maxChildren-1; actuallevel++ )
	{
		if( actual_octree == NULL )
		{
			printf( "i" );
			return;
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
		
////		cout << "\n ZAKONCZENIE POLICZENIA IDBEGIN I IDEND";
		
		if( idbegin != idend || (actuallevel>=(maxChildren-1)) )
			break;
////		cout << " -:- ";
		
		if( actual_octree -> next == NULL )
			actual_octree -> CreateChildrens();
		
		actual_octree = ( (actual_octree -> next) + idbegin );
		
		/*
		if( actual_octree -> next != NULL )
		{
			actual_octree = (Octree*)( (actual_octree -> next) + idbegin );
		}
		else if( actuallevel < (maxChildren-1) )
		{
			actual_octree -> CreateChildrens();
			cout << " -:- ";
			actual_octree = (Octree*)( (actual_octree -> next) + idbegin );
		}
		*/
		
////		cout << " ------ ZAKONCZENIE LICZENIA KOLEJNEGO OCTREE";
	}
////	cout << "\n DODAWANIE W ODPOWIEDNIM MIEJSCU ITEMU";
	actual_octree -> AddItem( src );
	//printf( "a" );
	return;
}

















inline void ** OperateOctree::GetFrom( Vector begin, Vector end, int * elemnumber )
{
	int i = 0;
	void ** fast = NULL;
	void ** tab = NULL;
	
	*elemnumber = 0;
	
	begin = begin - offset;
	end = end - offset;
	
	if( begin < 0.0f || !(end < size) )
	{
		*elemnumber = octree_out.size;
		
		fast = new void*[*elemnumber];
		for( i = 0; i < *elemnumber; i++ )
		{
			*(fast+i) = *((octree_out.items)+i);
		}
		
		return fast;
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
		
		fast = new void*[*elemnumber+(actual_octree->size)];
		for( i = 0; i < *elemnumber; i++ )
		{
			*(fast+i) = *(tab+i);
		}
		if( tab != NULL )
			delete[] tab;
		for( i = 0; i < (actual_octree->size); i++ )
		{
			*(fast+(*elemnumber)+i-1) = *((actual_octree->items)+i);
		}
		*elemnumber+=(actual_octree->size);
		tab = fast;
		
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


