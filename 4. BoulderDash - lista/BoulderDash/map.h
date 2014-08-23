
extern void editionMenu();
extern void menu();
extern bool loadMap();
extern void saveMap();
extern void clearMapScreen();
extern void clearQuaterMapScreen();
extern bool getFileName(char fileName[20]);
extern void editMainLoop();

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

void deleteMap()
{
	for(int i = 0; i < mapHeight; ++i)
	{
		delete []map [i];
	}

	delete []map;
}

void drawGameMap()
{
	for(int y = 0; y < mapHeight; ++y)
	{
		for(int x = 0; x < mapWidth; ++x)
		{
			setBlackConsoleTextAttribute(x + 1, y + 1);
			std::cout << map[y][x];
		}
	}
}

void drawGameBar()
{
	setPosition(2, 21);
	std::cout << "z[" << wallChar << "] -wall";

	setPosition(15, 21);
	std::cout << "x[" << hashChar << "] -ground";

	setPosition(30, 21);
	std::cout << "c[" << diamondChar << "] -diamond";

	setPosition(47, 21);
	std::cout << "v[" << stoneChar << "] -stone";

	setPosition(63, 21);
	std::cout << "SPACE[ ] -free";

	setPosition(2, 23);
	std::cout << "F1 -clear";

	setPosition(15, 23);
	std::cout << "F2 -save map";

	setPosition(31, 23);
	std::cout << "ESC -back";

	setPosition(50, 23);
	std::cout << "m[" << monsterChar << "] -monster";
}

void editFillMap()
{
	char w = wallChar;
	char h = hashChar;
	char p = playerChar;

	char newEditMap[mapHeight][mapWidth] = {
		{ w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w },
		{ w , p , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , w },
		{ w , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , w },
		{ w , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , w },
		{ w , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , w },
		{ w , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , w },
		{ w , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , w },
		{ w , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , w },
		{ w , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , w },
		{ w , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , w },
		{ w , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , w },
		{ w , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , w },
		{ w , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , w },
		{ w , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , w },
		{ w , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , w },
		{ w , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , w },
		{ w , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , w },
		{ w , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , h , w },
		{ w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w , w }
	};

	for(int y = 0; y < mapHeight; ++y)
	{
		for(int x = 0; x < mapWidth; ++x)
		{
			map[y][x] = newEditMap[y][x];
		}
	}
}

void editDrawMap()
{
	for(int y = 0; y < mapHeight; ++y)
	{
		for(int x = 0; x < mapWidth; ++x)
		{
			setPosition(x + 1, y + 1);
			std::cout << map[y][x];
		}
	}

	drawGameBar();
}

void editInitPlayer()
{
	editPlayer.position.x = 1;
	editPlayer.position.y = 1;
}

void editMarkPlayer()
{
	setWhiteConsoleTextAttribute((int)editPlayer.position.x + 1, (int)editPlayer.position.y + 1);

	std::cout << map[(int)editPlayer.position.y][(int)editPlayer.position.x];;
}

void editUnmarkPlayer()
{
	setBlackConsoleTextAttribute((int)editPlayer.position.x + 1, (int)editPlayer.position.y + 1);

	std::cout << map[(int)editPlayer.position.y][(int)editPlayer.position.x];
}

void editConditionMap()
{
	if(((int)editPlayer.position.y + 1) == mapHeight)
	{
		editPlayer.position.y = editPlayer.position.y - 1;
	}

	if(((int)editPlayer.position.y) < 1)
	{
		editPlayer.position.y = editPlayer.position.y + 1;
	}

	if(((int)editPlayer.position.x + 1) == mapWidth)
	{
		editPlayer.position.x = editPlayer.position.x - 1;
	}

	if(((int)editPlayer.position.x) < 1)
	{
		editPlayer.position.x = editPlayer.position.x + 1;
	}
}

void editMainLoop()
{
	editInitPlayer();
	editMarkPlayer();

	char key;

	while(true)
	{
		if(_kbhit())
		{
			editUnmarkPlayer();
			
			key = _getch();

			switch(key)
			{
				case 72:
					editPlayer.position.x += 0;
					editPlayer.position.y += -1;
					break;

				case 80:
					editPlayer.position.x += 0;
					editPlayer.position.y += 1;
					break;

				case 75:
					editPlayer.position.x += -1;
					editPlayer.position.y += 0;
					break;

				case 77:
					editPlayer.position.x += 1;
					editPlayer.position.y += 0;
					break;

				case 'z':
					map[(int)editPlayer.position.y][(int)editPlayer.position.x] = wallChar;
					break;

				case 'x':
					map[(int)editPlayer.position.y][(int)editPlayer.position.x] = hashChar;
					break;

				case 'c':
					map[(int)editPlayer.position.y][(int)editPlayer.position.x] = diamondChar;
					break;

				case 'v':
					map[(int)editPlayer.position.y][(int)editPlayer.position.x] = stoneChar;
					break;

				case 'm':
					map[(int)editPlayer.position.y][(int)editPlayer.position.x] = monsterChar;
					break;

				case 0x20: // space
					map[(int)editPlayer.position.y][(int)editPlayer.position.x] = ' ';
					break;

				case 59: // F1
					clearMapScreen();
					editFillMap();
					editDrawMap();
					editInitPlayer();
					break;

				case 60: // F2
					clearMapScreen();
					saveMap();
					editDrawMap();
					editInitPlayer();
					break;

				case 27:
					return;
			}
			editConditionMap();
			editMarkPlayer();
		}
	}
}

void editNewMap()
{
	editFillMap();

	clearQuaterMapScreen();

	editDrawMap();

	editMainLoop();
}

void editMap()
{
	clearQuaterMapScreen();

	if((loadMap()) == false)
	{
		clearQuaterMapScreen();
		return;
	}

	clearQuaterMapScreen();
	editDrawMap();

	editMainLoop();
}

