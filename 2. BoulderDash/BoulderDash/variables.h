
static const char monsterChar = 64; // @
static const char playerChar = 1;
static const char n = 8;
static const char q = 219; // white field
static const char stoneChar = 254; // stone
static const char wallChar = 177; // wall
static const char diamondChar = 4; // diamond
static const char hashChar = 35; // hash - ground
static const char spaceChar = 32; // space - free 

const int mapHeight = 19;
const int mapWidth = 78;

const int backgroundColorWHITE = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
const int backgroundColorBLACK = 0;
const int foregroundColorGOLD = FOREGROUND_RED | FOREGROUND_GREEN;
const int foregroundColorWHITE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;

HANDLE output = GetStdHandle( STD_OUTPUT_HANDLE );

void setPosition(int x, int y) 
{ 
    COORD pos = {x, y};
    SetConsoleCursorPosition(output, pos);
}

struct Vector2D
{
	double x;
	double y;
};

struct Monster
{
	Vector2D position;
	Vector2D direction;
};

struct Stone
{
	Vector2D position;
};

struct Diamond
{
	Vector2D position;
};

struct Player 
{
	Vector2D position;
};


Player player;
Player editPlayer;
static int diamondPoints;
static int moves;
static int points = diamondPoints * 2 + moves;

char** map;

void createMap()
{
	map = new char*[mapHeight];

	for(int y = 0; y < mapHeight; ++y)
	{
		map[y] = new char[mapWidth];

		for(int x = 0; x < mapWidth; ++x)
		{
			map[y][x] = NULL;
		}
	}
}