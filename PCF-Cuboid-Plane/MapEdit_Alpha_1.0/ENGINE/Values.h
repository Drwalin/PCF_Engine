

//vector< vector< EngineColliderTrigger > > trigger;
EngineColliderTrigger trigger[XTRIGGER][ZTRIGGER];

vector< EngineGraphicModel > objectmodel;
vector< EngineObject > object;

EngineMap map;

vector< EngineGraphicModel > environmentmodel;
vector< EngineEnvironmentModel > environment;   //np. trawa, rosliny... (obiekty bez fizyki)


vector< EngineHumanoidGraphicModel > humanoid;
vector< EngineCubeGraphicModel > cubes;


unsigned int draw_object_id = 0;

/*
vector < CharName > texturefiles;
vector < BITMAPINFOHEADER > bitmapInfoHeader;
vector < unsigned char * > bitmapData;
vector < unsigned int > texture;
*/


float resize[3]={1.0f,1.0f,1.0f};
unsigned texture=0;
WallsVoid wallsave[5] = { FloorFunction, WallFunction, TriangleFunction, Ramp1Function, Ramp2Function };
WallsVoid walldraw[5] = { FloorFunctionDraw, WallFunctionDraw, TriangleFunctionDraw, Ramp1FunctionDraw, Ramp2FunctionDraw };
unsigned int wallprinter = 0;
