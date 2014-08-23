
extern void gameFrame();

void findMonster(Monster &monster, std::vector<Monster> &monsterMovement)
{
	for(int y = 0; y < mapHeight; ++y)
	{
		for(int x = 0; x < mapWidth; ++x)
		{
			if(map[y][x] == '@')
			{
				monster.position.x = x;
				monster.position.y = y;
				monster.direction.x = 0.3;
				monster.direction.y = 0;

				monsterMovement.push_back(monster);
			}
		}
	}
}

void findStone(Stone &stone, std::vector<Stone> &stoneMovement)
{
	for(int y = 0; y < mapHeight; ++y)
	{
		for(int x = 0; x < mapWidth; ++x)
		{
			if(map[y][x] == stoneChar)
			{
				stone.position.x = x;
				stone.position.y = y;

				stoneMovement.push_back(stone);
			}
		}
	}
}

void findDiamond(Diamond &diamond, std::vector<Diamond> &diamondMovement)
{
	for(int y = 0; y < mapHeight; ++y)
	{
		for(int x = 0; x < mapWidth; ++x)
		{
			if(map[y][x] == diamondChar)
			{
				diamond.position.x = x;
				diamond.position.y = y;

				diamondMovement.push_back(diamond);
			}
		}
	}
}

void drawGameMap()
{
	for(int y = 0; y < mapHeight; ++y)
	{
		for(int x = 0; x < mapWidth; ++x)
		{
			setPosition(x + 1, y + 1);
			std::cout << map[y][x];
		}
	}
}

bool gameMap()
{
	clearQuaterMapScreen();
	
	if((loadMap()) == false)
	{
		clearQuaterMapScreen();
		return false;
	}
	
	clearQuaterMapScreen();
	drawGameMap();

	return true;
}

void deleteMap()
{
	for(int i = 0; i < mapHeight; ++i)
	{
		delete []map [i];
	}

	delete []map;
}

void gameLoop()
{
	diamondPoints = 0;
	moves = 0;

	system("cls");
	gameFrame();

	if((gameMap()) == false)
		return;

	Monster monster;
	::std::vector<Monster> monsterMovement;
	findMonster(monster, monsterMovement);

	Stone stone;
	::std::vector<Stone> stoneMovement;
	findStone(stone, stoneMovement);

	Diamond diamond;
	::std::vector<Diamond> diamondMovement;
	findDiamond(diamond, diamondMovement);

	initPlayer();
	markPlayer();

	int counter = 0;

	while(true)
	{
		if(playerMove() == false)
			break;

		SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
		setPosition(14, 21);
		std::cout << diamondPoints;

		SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
		setPosition(14, 22);
		std::cout << moves;

		SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
		setPosition(14, 23);
		std::cout << points;

		addPoints(diamond);

		//for(std::vector<Diamond>::iterator i = diamondMovement.begin(); i != diamondMovement.end(); i++){
		///////////-----------------------------		
		//	}


		if(counter == 100){
			for(std::vector<Monster>::iterator i = monsterMovement.begin(); i != monsterMovement.end(); i++){
				monsterMove(*i);
			}

			for(std::vector<Stone>::iterator i = stoneMovement.begin(); i != stoneMovement.end(); i++){
				stoneMove(*i);
			}

			for(std::vector<Diamond>::iterator i = diamondMovement.begin(); i != diamondMovement.end(); i++){
				diamondMove(*i);
			}

			counter = 0;
		}

		counter++;

		Sleep(1);
	}
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