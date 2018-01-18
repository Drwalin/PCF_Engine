


template < class type >
class Octree
{
public:
	vector < type > items;
	
	Octree * next;
	
	inline type& operator[] ( int id )
	{
		if( id >= items.size() )
		{
			if( items.size() == 0 )
			{
				items.resize( 1 );
			}
			return items[0];
		}
		return items[id];
	}
	
	inline void AddItem( type src )
	{
		items.push_back( src );
	}
	
	inline void CreateChildrens()
	{
		if( next == NULL )
			next = new Octree<type>[8];
	}
	
	inline void DeleteChildrens()
	{
		if( next != NULL )
		{
			next -> DeleteChildrens();
			next -> ~Octree();
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
	
	inline vector <type> GetObjects()
	{
		vector <type> tab = items;
		if( next != NULL )
		{
			vector <type> fast1 = next -> GetObjects();
			vector <type> fast2 = (next+1) -> GetObjects();
			vector <type> fast3 = (next+2) -> GetObjects();
			vector <type> fast4 = (next+3) -> GetObjects();
			vector <type> fast5 = (next+4) -> GetObjects();
			vector <type> fast6 = (next+5) -> GetObjects();
			vector <type> fast7 = (next+6) -> GetObjects();
			vector <type> fast8 = (next+7) -> GetObjects();
			int  i,  j =   tab.size(),
					a1 = fast1.size(),
					a2 = fast2.size(),
					a3 = fast3.size(),
					a4 = fast4.size(),
					a5 = fast5.size(),
					a6 = fast6.size(),
					a7 = fast7.size(),
					a8 = fast8.size();
			
			tab.resize( j+a1+a2+a3+a4+a5+a6+a7+a8 );
			
			for( i = 0; i < a1; i++ )
				tab[j+i] = fast1[i];
			j += a1;
			
			for( i = 0; i < a2; i++ )
				tab[j+i] = fast2[i];
			j += a2;
			
			for( i = 0; i < a3; i++ )
				tab[j+i] = fast3[i];
			j += a3;
			
			for( i = 0; i < a4; i++ )
				tab[j+i] = fast4[i];
			j += a4;
			
			for( i = 0; i < a5; i++ )
				tab[j+i] = fast5[i];
			j += a5;
			
			for( i = 0; i < a6; i++ )
				tab[j+i] = fast6[i];
			j += a6;
			
			for( i = 0; i < a7; i++ )
				tab[j+i] = fast7[i];
			j += a7;
			
			for( i = 0; i < a8; i++ )
				tab[j+i] = fast8[i];
		}
		return tab;
	}
	
	Octree()
	{
		next = NULL;
	}
	
	~Octree()
	{
		DeleteChildrens();
	}
};


template < class type >
class OperateOctree
{
public:
	Octree < type > * octree;
	Octree < type > octree_out;
	Vector offset;
	Vector size;
	int maxChildren;
	
	inline void SetInfo( Vector offset_, Vector size_, int maxChildrens_ )
	{
		offset = offset_;
		size = size_;
		maxChildren = maxChildrens_;
	}
	
	inline void SetAt( Vector begin, Vector end, type src )
	{
		begin = begin - offset;
		end = end - offset;
		
		if( begin < 0.0f || (end >= size) )
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
			octree = new Octree<type>;
		}
		
		Octree<type> * actual_octree = octree;
		
		for( ; actuallevel < maxChildren; actuallevel++ )
		{
			if( actual_octree == NULL )
			{
				printf( "\nERROR_OCTREE:_NULL\n" );
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
			
			if( idbegin != idend || (actuallevel>=maxChildren) )
				break;
			
			if( actual_octree -> next == NULL )
				actual_octree -> CreateChildrens();
			
			actual_octree = ( (actual_octree -> next) + idbegin );
		}
		
		actual_octree -> AddItem( src );
		return;
	}
	
	inline vector < type > UpperGetFrom( Vector begin, Vector end )
	{
		int i = 0, j = 0;
		vector < type > tab;
		
		begin = begin - offset;
		end = end - offset;
		
		tab = octree_out.items;
		if( begin < 0.0f || !(end < size) )
		{
			return tab;
		}
		
		tab = octree -> items;
		
		int actuallevel = 0;
		int idbegin = 0;
		int idend = 0;
		
		Vector size_next = size;
		
		Octree<type> * actual_octree = octree;
		
		for( ; actuallevel < maxChildren; actuallevel++ )
		{
			if( actual_octree == NULL )
				break;
			
			j = tab.size();
			tab.resize( tab.size()+(actual_octree -> items).size() );
			for( int i = 0; i < (actual_octree -> items).size(); i++ )
			{
				tab[j+i] = (actual_octree -> items)[i];
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
			
			if( idbegin != idend || ( actuallevel >= maxChildren ) )
				break;
			
			if( actual_octree -> next == NULL )
				break;
			
			actual_octree = ( (actual_octree -> next) + idbegin );
		}
		return tab;
	}
	
	inline vector < type > GetFrom( Vector begin, Vector end )
	{
		int i, j;
		vector < type > tab;
		
		begin = begin - offset;
		end = end - offset;
		
		tab = octree_out.items;
		if( begin < 0.0f || !(end < size) )
		{
//			return tab;
		}
		
		int actuallevel;
		int idbegin;
		int idend;
		
		Vector size_next = size;
		
		Octree<type> * actual_octree = octree;
		
		for( ; actuallevel < maxChildren; actuallevel++ )
		{
			if( actual_octree == NULL )
				break;
			
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
			
			if( idbegin != idend || ( actuallevel >= maxChildren ) || actual_octree -> next == NULL )
			{
				vector <type> fast = actual_octree -> GetObjects();
				j = tab.size();
				tab.resize( j+fast.size() );
				for( i = 0; i < fast.size(); i++ )
					tab[j+i] = fast[i];
				break;
			}
			
			j = tab.size();
			tab.resize( j+(actual_octree -> items).size() );
			for( i = 0; i < (actual_octree -> items).size(); i++ )
			{
				tab[j+i] = (actual_octree -> items)[i];
			}
			
			actual_octree = ( (actual_octree -> next) + idbegin );
		}
		return tab;
	}
	
	inline void Clear()
	{
		if( octree != NULL )
			octree -> DeleteChildrens();
		
		octree_out.DeleteChildrens();
	}
	
	OperateOctree()
	{
		octree = new Octree<type>;
		offset[0] = -5.0f;
		offset[1] = -5.0f;
		offset[2] = -5.0f;
		size[0] = 10.0f;
		size[1] = 10.0f;
		size[2] = 10.0f;
		maxChildren = 10;
	}
	
	~OperateOctree()
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
};


