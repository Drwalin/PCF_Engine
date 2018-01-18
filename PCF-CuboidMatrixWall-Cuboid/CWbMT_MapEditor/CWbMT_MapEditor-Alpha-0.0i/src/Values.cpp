


ALLEGRO_BITMAP * background;
ALLEGRO_BITMAP * desktop;

int pixelmovex=0;
int pixelmovey=0;

int windowx=800;
int windowy=600;

//Map map;

vector < Vector > vertex;
vector < unsigned int > indices;
vector < Button > button;

vector < SeeAspect > window;

int ActivatedVertex = -1;
int ActivatedWindow = -1;
EDITOR_OPTIONS_ENABLED ActivatedEditorOption = NONE_OPTION;

bool RENDER_OPTION[3];
vector < int > ConnectedPoints;

