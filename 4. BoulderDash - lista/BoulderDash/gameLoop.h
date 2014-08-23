
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
				monster.direction.x = 0.7;
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

void findDiamond(std::list<Diamond *> &diamondMovement)
{
	for(int y = 0; y < mapHeight; ++y)
	{
		for(int x = 0; x < mapWidth; ++x)
		{
			if(map[y][x] == diamondChar)
			{
				Diamond *diamond = new Diamond();

				diamond->position.x = x;
				diamond->position.y = y;

				diamondMovement.push_back(diamond);
			}
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

	//Diamond diamond;
	::std::list<Diamond *> diamondMovement;
	findDiamond(diamondMovement);

	initPlayer();
	markPlayer();

	int counter = 0;
	int ttt = 0;

	while(true)
	{
		if(playerMove() == false)
			break;


		if(counter == 500)
		{
			for(std::vector<Monster>::iterator i = monsterMovement.begin(); i != monsterMovement.end(); i++)
			{
				monsterMove(*i);
			}

			for(std::vector<Stone>::iterator i = stoneMovement.begin(); i != stoneMovement.end(); i++)
			{
				stoneMove(*i);
			}

			Diamond *removedDiamond = NULL;

			for(std::list<Diamond *>::iterator i = diamondMovement.begin(); i != diamondMovement.end(); i++)
			{
				if(diamondMove(*i))
					removedDiamond = *i;
			}

			if(removedDiamond != NULL)
				diamondMovement.remove(removedDiamond);

			counter = 0;
		}

		++counter;

		Sleep(1);
	}
}

