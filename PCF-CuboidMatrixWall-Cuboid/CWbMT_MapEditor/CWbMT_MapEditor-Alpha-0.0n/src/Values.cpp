


ALLEGRO_BITMAP * background;
ALLEGRO_BITMAP * desktop;
ALLEGRO_BITMAP * FullMapTexture;

int pixelmovex=0;
int pixelmovey=0;

int windowx=800;
int windowy=600;

//Map map;

vector < Vertex > vertex;
vector < Triangle > triangles;
vector < Button > button;

Indices indices;

vector < SeeAspect > window;

int ActivatedVertex = -1;
int ActivatedWindow = -1;
EDITOR_OPTIONS_ENABLED ActivatedEditorOption = NONE_OPTION;

bool RENDER_OPTION[4] = { false, false , false, true};
vector < int > ConnectedPoints;

