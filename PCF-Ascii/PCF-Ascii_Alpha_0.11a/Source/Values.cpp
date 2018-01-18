
float anglexz=0;
float angley=0;
Vector move;


vector < ALLEGRO_BITMAP * > buildingstextures;
vector < ALLEGRO_BITMAP * > npcstextures;
//vector < ALLEGRO_BITMAP * > textures;

float xmousemovedisplay=0;

ALLEGRO_BITMAP * background;
ALLEGRO_BITMAP * desktop;

int pixelmovex=0;
int pixelmovey=0;

int windowx=800;
int windowy=600;

vector < Buildings > buildings;
vector < NPCs > npcs;
Player player;

Map map;



char logo01[] = "           .-;+$XHHHX$+;-.           ";
char logo02[] = "        ,;X@@@@@@:\":@@@@@@X/,        ";
char logo03[] = "      =$@@@@@@@$`   `$@@@@@@@X:      ";
char logo04[] = "    -X@@@@@@@@\"`     `\"@@@@@@@@X=    ";
char logo05[] = "   /@@@@@@@@@`         `@@@@@@@@@+   ";
char logo06[] = "  %@@@@@@@@@'        ,+ '@@@@@@@@@$  ";
char logo07[] = " +@@@@@@@@&  _,,._  ,&'   &@@@@@@@@% ";
char logo08[] = "-@@@@@@@@+  +@*``\"% @:     +@@@@@@@@=";
char logo09[] = "=@@@@@@@=  (&.    ;X<       =@@@@@@@=";
char logo10[] = "%@@@@@@\"`   `@+,_.@ %.      `\"@@@@@@$";
char logo11[] = "=@@@@@:`      '\"*\"  :X_,+    `:@@@@@:";
char logo12[] = " +@@@&'              `\"\"`    '&@@@X\" ";
char logo13[] = "  $@+-.,_                  _,.-+@$.  ";
char logo14[] = "   +@@@@@@&%+-,.,_ _,.,-+%&@@@@@@+   ";
char logo15[] = "    =X@@@@@@@@@@@@@@@@@@@@@@@@@X=    ";
char logo16[] = "      :$@@@@@@@@@@@@@@@@@@@@@$:      ";
char logo17[] = "        ,;$@@@@@@@@@@@@@@@X/-        ";
char logo18[] = "           .-;+$XHHHX$+;-.           ";




float hmap[100][100];/* =
    {
        { 0, 1, 2, 3, 4, 3, 2, 1, 0, 0   },
        { 1, 2, 3, 4, 5, 4, 3, 2, 1, 0   },
        { 2, 3, 4, 5, 6, 5, 4, 3, 2, 0.5 },
        { 3, 4, 5, 6, 7, 6, 5, 4, 3, 1   },
        { 4, 5, 6, 7, 7, 7, 6, 5, 4, 1.5 },
        { 4, 5, 6, 7, 7, 7, 6, 5, 4, 1.5 },
        { 3, 4, 5, 6, 7, 6, 5, 4, 3, 1   },
        { 2, 3, 4, 5, 6, 5, 4, 3, 2, 0.5 },
        { 1, 2, 3, 4, 5, 4, 3, 2, 1, 0   },
        { 0, 1, 2, 3, 4, 3, 2, 1, 0, 0   }
    };*/








