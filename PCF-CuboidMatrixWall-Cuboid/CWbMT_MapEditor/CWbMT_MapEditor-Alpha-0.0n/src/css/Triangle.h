


class Triangle
{
public:
	int indices[3];
	Vector normal;
	float reverse_normal;
	
	inline Vector GetBeginNormal();
	inline bool IsTherePoint( int id );
	inline void NegateNormal();
	inline void CalcNormal();
	
	Triangle();
};


class Indices
{
public:
	inline int& operator[]( int id );
	inline int size();
};


