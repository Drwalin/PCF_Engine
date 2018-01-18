


#include"..\\octreeBase\\octree.h"

template < class Type, int Childrens = 10 >
class OctreeLeveled
{
public:
	Vector offset;
	Octree<vector<Type>* > * octree[Childrens];
	vector <Type> out;
	
//    o(1,2,3) = 3.1416;      /* Put pi in (1,2,3). */
//    o.erase(1,2,3);         /* Erase that node. */
	
	// Basics methods:
	
	inline void Clear()
	{
		int i;
		for( i=0; i<Childrens; i++ )
		{
			if( octree[i] != NULL )
			{
				octree[i] -> DestructorOctree();
			}
		}
	}
	
	inline void Init( const Vector offset_ )
	{
//		OctreeLeveled();
		offset = offset_;
//		Clear();
	}
	
	// Add method:
	
	inline void Add( const Vector begin__, const Vector end__, const Type src )
	{
		
		Vector begin_ = begin__ - offset;
		Vector end_ = end__ - offset;
		
		unsigned int begin[3] = { int(begin_[0]), int(begin_[1]), int(begin_[2]) };
		unsigned int end[3] = { int(end_[0]), int(end_[1]), int(end_[2]) };
		
//		Vector obsize = end - begin;
		Vector size = SetVector( 1<<(Childrens-1), 1<<(Childrens-1), 1<<(Childrens-1) );
		
		if( !(end_ < size) || !( SetVector( 0.0f, 0.0f, 0.0f ) < begin_) )
		{
			out.push_back( src );
			return;
		}
		else
		{
			int i = Childrens-1;
			while( begin[0] != end[0] )
			{
				begin[0] >>= 1;
				end[0] >>= 1;
				i--;
			}
			int j = Childrens-1;
			while( begin[1] != end[1] )
			{
				begin[1] >>= 1;
				end[1] >>= 1;
				j--;
			}
			int k = Childrens-1;
			while( begin[2] != end[2] )
			{
				begin[2] >>= 1;
				end[2] >>= 1;
				k--;
			}
			
			if( Min( i, j, k ) < 0 )
			{
				out.push_back( src );
				return;
			}
			else
			{
				while( i > Min( i, j, k) )
				{
					begin[0] >>= 1;
					end[0] >>= 1;
					i--;
				}
				while( j > Min( i, j, k) )
				{
					begin[1] >>= 1;
					end[1] >>= 1;
					j--;
				}
				while( k > Min( i, j, k) )
				{
					begin[2] >>= 1;
					end[2] >>= 1;
					k--;
				}
				printf( "Adding :-: " );///////////////////////////////////////////////////////////
				
				//vector <Type> FastV = ((octree[i]))->operator()(begin[0],begin[1],begin[2]);
				//FastV.push_back( src );
				//octree[i] -> set( begin[0], begin[1], begin[2], FastV );
				if( ((octree[i])->operator()(begin[0],begin[1],begin[2])) == octree[i]->emptyValue() )
				{
					((octree[i])->operator()(begin[0],begin[1],begin[2])) = new vector<Type>;
					((octree[i])->operator()(begin[0],begin[1],begin[2])) -> push_back( src );
				}
				else
				{
					((octree[i])->operator()(begin[0],begin[1],begin[2])) -> push_back( src );
				}
				//(((octree[i]))->at(begin[0],begin[1],begin[2])).push_back( src );
				
				printf( "AddDone :-: " );///////////////////////////////////////////////////////////
				return;
			}
		}
	}
	
	// Get methods:
	
	inline vector<Type> GetUpper( const Vector begin__, const Vector end__ )
	{
		
	}
	
	inline vector<Type> GetLower( const Vector begin__, const Vector end__ )
	{
		
	}
	
	inline vector<Type> Get( const Vector begin__, const Vector end__ )
	{
		Vector begin_ = begin__ - offset;
		Vector end_ = end__ - offset;
		
		vector <Type> dst;
		
		unsigned int begin[3] = { int(begin_[0]), int(begin_[1]), int(begin_[2]) };
		unsigned int end[3] = { int(end_[0]), int(end_[1]), int(end_[2]) };
		
//		Vector obsize = end - begin;
		Vector size = SetVector( 1<<(Childrens-1), 1<<(Childrens-1), 1<<(Childrens-1) );
		
		if( !(end_ < size) || !(SetVector( 0.0f, 0.0f, 0.0f ) < begin_) )
		{
			return out;
		}
		else
		{
			int i = Childrens-1;
			while( begin[0] != end[0] )
			{
				begin[0] >>= 1;
				end[0] >>= 1;
				i--;
			}
			int j = Childrens-1;
			while( begin[1] != end[1] )
			{
				begin[1] >>= 1;
				end[1] >>= 1;
				j--;
			}
			int k = Childrens-1;
			while( begin[2] != end[2] )
			{
				begin[2] >>= 1;
				end[2] >>= 1;
				k--;
			}
			
			if( Min( i, j, k ) < 0 )
			{
				return out;
			}
			else
			{
				while( i > Min( i, j, k) )
				{
					begin[0] >>= 1;
					end[0] >>= 1;
					i--;
				}
				while( j > Min( i, j, k) )
				{
					begin[1] >>= 1;
					end[1] >>= 1;
					j--;
				}
				while( k > Min( i, j, k) )
				{
					begin[2] >>= 1;
					end[2] >>= 1;
					k--;
				}
				
				
				int a1,a2,a3;
				int l;
				// Get upper items:
					
					l = i-1;
					while( l > 0 )
					{
						if( ((octree[l])->at(begin[0]>>l,begin[1]>>l,begin[2]>>l)) != octree[i]->emptyValue() )
						{
							a1 = dst.size();
							a2 = ((octree[l])->at(begin[0]>>l,begin[1]>>l,begin[2]>>l))->size();
							for( a3 = 0; a3 < a2; a3++ )
								dst[a1+a3] = ((octree[l])->at(begin[0]>>l,begin[1]>>l,begin[2]>>l))->operator[](a3);
						}
						l--;
					}
					
				// Get lower (with actual) items:
					
					l = i;
					int fasti[3];
					end[0]++;
					end[1]++;
					end[2]++;
					while( l < Childrens )
					{
						for( fasti[0] = begin[0]; fasti[0] < end[0]; fasti[0]++ )
						{
							for( fasti[1] = begin[1]; fasti[1] < end[1]; fasti[1]++ )
							{
								for( fasti[2] = begin[2]; fasti[2] < end[2]; fasti[2]++ )
								{
									if( ((octree[l])->at(fasti[0],fasti[1],fasti[2])) != octree[i]->emptyValue() )
									{
										a1 = dst.size();
										a2 = ((octree[l])->at(fasti[0],fasti[1],fasti[2]))->size();
										for( a3 = 0; a3 < a2; a3++ )
											dst[a1+a3] = ((octree[l])->at(fasti[0],fasti[1],fasti[2]))->operator[](a3);
									}
								}
							}
						}
						
						end[0] <<= 1;
						end[1] <<= 1;
						end[2] <<= 1;
						begin[0] <<= 1;
						begin[1] <<= 1;
						begin[2] <<= 1;
						
						l++;
					}
				return dst;
			}
		}
	}
	
	// Constructor:
	
	OctreeLeveled()
	{
		int i;
		for( i=0; i<Childrens; i++ )
		{
			if( octree[i] == NULL )		octree[i] = new Octree<vector<Type>* >( 1<<i );
		}
	}
	
	// Destructor:
	
	~OctreeLeveled()
	{
//		Clear();
		int i,x,y,z;
		for( i=0; i<Childrens; i++ )
		{
			if( octree[i] != NULL )
			{
				for( x=0; x<(1<<i); x++ )
				{
					for( x=0; x<(1<<i); x++ )
					{
						for( x=0; x<(1<<i); x++ )
						{
							if( octree[i]->at(x,y,z) != octree[i]->emptyValue() )
							{
								delete[] octree[i]->at(x,y,z);
							}
						}
					}
				}
				delete[] octree[i];
			}
		}
	}
};


