
extern void gameFrame();

void findMonster(Monster &monster, std::vector<Monster> &monsterMovement, char** &_loadedMap)
{
	for(int y = 0; y < newMapHeight; ++y)
	{
		for(int x = 0; x < newMapWidth; ++x)
		{
			if(_loadedMap[y][x] == '@')
			{
				monster.position.x = x;
				monster.position.y = y;
				monster.direction.x = 0.5;
				monster.direction.y = 0;

				monsterMovement.push_back(monster);
			}
		}
	}
}

void drawGameMap(char** &_loadedMap)
{
	for(int y = 0; y < newMapHeight; ++y)
	{
		for(int x = 0; x < newMapWidth; ++x)
		{
			setPosition(x + 1, y + 1);
			std::cout << _loadedMap[y][x];
		}
	}
}

bool gameMap(char** &_loadedMap)
{
	clearQuaterMapScreen();
	
	createMap2D(_loadedMap);

	if((loadMap(_loadedMap)) == false)
	{
		clearQuaterMapScreen();
		return false;
	}
	
	clearQuaterMapScreen();
	drawGameMap(_loadedMap);

	return true;
}

void deleteMap(char** &_loadedMap)
{
	for(int i = 0; i < newMapHeight; ++i)
	{
		delete []_loadedMap [i];
	}

	delete []_loadedMap;
}

void gameLoop()
{
	system("cls");
	gameFrame();

	char** _loadedMap;

	if((gameMap(_loadedMap)) == false)
		return;

	Monster monster;
	std::vector<Monster> monsterMovement;
	
	findMonster(monster, monsterMovement, _loadedMap);

	initPlayer();
	markPlayer(_loadedMap);

	while(true)
	{
		playerMove(_loadedMap);

        for(std::vector<Monster>::iterator i = monsterMovement.begin(); i != monsterMovement.end(); i++)
        {
			(*i) = monsterMove(*i, _loadedMap);
        }

		Sleep(50);

		if(playerMove(_loadedMap) == false)
			break;
	}

	deleteMap(_loadedMap);
}

void drawMainFrame()
{
	std::cout << 
		"o------------------------------------------------------------------------------o"
		"|      ______     ________   __    __   __        _____     ______   _____     |"
		"|     / ___  |   / ____  /  / /   / /  / /       / ___ |   / ____/  / ___ |    |"
		"|    / /__/ /   / /   / /  / /   / /  / /       / /  / /  / /__    / /__/ /    |"
		"|   / ___  /   / /   / /  / /   / /  / /       / /  / /  / ___/   / __   /     |"
		"|  / /__/  |  / /___/ /  / /___/ /  / /____   / /__/ /  / /___   / /  | \\      |"
		"| /_______/  /_______/  /_______/  /______/  /______/  /_____/  /_/   |_|      |"
		"|                                     ______     ________   ______    __    __ |"
		"|                                    / ___  |   / ____  /  / ____/   / /   / / |"
		"|                                   / /   / /  / /___/ /  / /___    / /___/ /  |"
		"|                                  / /   / /  / ____  /  |____  |  / ____  /   |"
		"|                                 / /___/ /  / /   / /  _____/ /  / /   / /    |"
		"|                                /_______/  /_/   /_/  /______/  /_/   /_/     |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"o------------------------------------------------------------------------------o";

	setPosition(0, 0);
}

void miniMenu()
{
	setPosition(10, 15);
	std::cout << "o----=MENU=-----o\n";

	for(int i = 16; i < 21; ++i)
	{
		setPosition(10, i);
		std::cout << "|               |\n";
	}

	setPosition(10, 21);
	std::cout << "o---------------o\n";
		

	setPosition(0, 0);
}

void gameFrame()
{
	std::cout << 
		"o-------------------------------=BOULDER DASH=---------------------------------o"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"o---------------------o--------------------------------------------------------o"
		"| DIAMONDS:           |                                                        |"
		"| MOVES:              |                                                        |"
		"| POINTS:             |                                                        |"
		"o---------------------o--------------------------------------------------------o";

	setPosition(0, 0);
}