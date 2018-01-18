


class Chunk
{
public:
	vector < TrianglePX > triPHYS;
	vector < GraphicObject > graphicObjects;
	ColliderTerrain ** colliderter;
	ColliderObjects ** colliderobj;
	VBOtextured vbotex;
	VBOcolored vbocol;
	
	int x;
	int z;
	
	inline void Draw( Vector * cameraSrc );
	
	inline void ClearObjectCollider();
	
	inline void GenerateColliders();
	inline void GenerateDrawing();
	inline void Delete();
	
	Chunk();
	~Chunk();
};


