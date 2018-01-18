


template < class type >
class vector
{
private:
	type ** data;
	int number;
	
public:
	vector()
	{
		data = NULL;
		number = 0;
	}
	
	~vector()
	{
		if( data != NULL )
		{
			int i;
			for( i = 0; i < number; i++ )
			{
				delete *(data+i);
			}
			delete[] data;
			number = 0;
		}
	}
	
	inline int begin()
	{
		return 0;
	}
	
	inline void insert( const int &pos, const type &src )
	{
		type ** fasttab = new type*[number+1];
		int i;
		for( i = 0; i < pos; i++ )
		{
			*(fasttab+i) = *(data+i);
		}
		*(fasttab+i) = new type;
		**(fasttab+i) = src;
		for( ; i < number; i++ )
		{
			*(fasttab+i+1) = *(data+i);
		}
		if( data != NULL )
			delete[] data;
		data = fasttab;
		fasttab = NULL;
		number++;
	}
	
	inline void push_back( const type &src )
	{
		insert( number, src );
	}
	
	inline void resize( const int &dstsize )
	{
		if( dstsize > number )
		{
			type ** fasttab = new type*[dstsize];
			int i;
			for( i = 0; i < number; i++ )
			{
				*(fasttab+i) = *(data+i);
			}
			for( ; i < dstsize; i++ )
			{
				*(fasttab+i) = new type;
			}
			if( data != NULL )
				delete[] data;
			data = fasttab;
			number++;
		}
		else if( dstsize < number )
		{
			type ** fasttab = new type*[dstsize];
			int i;
			for( i = 0; i < dstsize; i++ )
			{
				*(fasttab+i) = *(data+i);
			}
			for( ; i < number; i++ )
			{
				delete *(fasttab+i);
			}
			if( data != NULL )
				delete[] data;
			data = fasttab;
			number++;
		}
		number = dstsize;
	}
	
	inline void erase( const int &pos )
	{
		if( pos < number )
		{
			type ** fasttab = new type*[number-1];
			int i;
			for( i = 0; i < pos; i++ )
			{
				*(fasttab+i) = *(data+i);
			}
			number--;
			for( ; i < number; i++ )
			{
				*(fasttab+i) = *(data+i+1);
			}
			if( data != NULL )
				delete[] data;
			data = fasttab;
			fasttab = NULL;
		}
	}
	
	inline int size()
	{
		return number;
	}
	
	inline type& operator[]( const int &pos )
	{
		return **(data+pos);
	}
};


