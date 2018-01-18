


class ONEPointParticle
{
public:
	Vector pos;
	Vector vel;
	Vector accelerate;
	float randomization;
	unsigned char r, g, b;
	float LifeTime;			// in seconds
	
	inline void Update( float time );
	
	ONEPointParticle();
	~ONEPointParticle();
};

class PointParticle
{
private:
	vector < ONEPointParticle > particle;
	
public:
	inline void Update( float time );
	inline void AddParticle( Vector origin, float originrandomization, Vector vel, Vector accelerate, float randomization, unsigned char r,unsigned char g, unsigned char b, unsigned char rrand,unsigned char grand, unsigned char brand, float lifetime, float randomizationlifetime, int count );
	inline void Draw();
	
	PointParticle();
	~PointParticle();
};


