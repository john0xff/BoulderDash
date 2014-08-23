
extern void editionMenu();
extern void menu();
extern bool loadMap();
extern void saveMap();
extern void clearMapScreen();
extern void clearQuaterMapScreen();
extern void editBar();
extern bool getFileName(char fileName[20]);
extern void editMainLoop();

void fillNewMap()
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

void editBar()
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

void drawNewMap()
{
	for(int y = 0; y < mapHeight; ++y)
	{
		for(int x = 0; x < mapWidth; ++x)
		{
			setPosition(x + 1, y + 1);
			std::cout << map[y][x];
		}
	}

	editBar();
}

void editInitMapPlayer()
{
	editPlayer.position.x = 1;
	editPlayer.position.y = 1;
}

void editMarkPlayer()
{
	char tmp = map[(int)editPlayer.position.y][(int)editPlayer.position.x];

	SetConsoleTextAttribute(output, backgroundColorWHITE | foregroundColorGOLD);
	setPosition((int)editPlayer.position.x + 1, (int)editPlayer.position.y + 1);
	std::cout << tmp;
}

void editUnmarkPlayer()
{
	SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
	setPosition((int)editPlayer.position.x + 1, (int)editPlayer.position.y + 1);
	std::cout << map[(int)editPlayer.position.y][(int)editPlayer.position.x];
}

void editionConditionMap()
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
	editInitMapPlayer();
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
					fillNewMap();
					drawNewMap();
					editInitMapPlayer();
					break;

				case 60: // F2
					clearMapScreen();
					saveMap();
					drawNewMap();
					editInitMapPlayer();
					break;

				case 27:
					return;
			}
			editionConditionMap();
			editMarkPlayer();
		}
	}
}

void newMapLoop()
{
	fillNewMap();

	clearQuaterMapScreen();

	drawNewMap();

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
	drawNewMap();

	editMainLoop();
}

void frameMapEditor()
{
	std::cout << 
		"o--------------------------------=MAP EDITOR=----------------------------------o"
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
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"o------------------------------------------------------------------------------o";

	setPosition(0, 0);
}

void subFrameMapEditor()
{
	setPosition(2, 1);
	std::cout << "o-------------o\n";

	for(int i = 2; i < 7; ++i)
	{
		setPosition(2, i);
		std::cout << "|             |\n";
	}

	setPosition(2, 7);
	std::cout << "o-------------o\n";
		
	setPosition(0, 0);
}

void clearMapScreen()
{
	for(int y = 1; y < mapHeight + 5; ++y)
	{
		for(int x = 1; x < mapWidth + 1; ++x)
		{
			setPosition(x, y);
			std::cout << " ";
		}
	}
}

void clearQuaterMapScreen()
{
	for(int y = 1; y < mapHeight / 2; ++y)
	{
		for(int x = 1; x < mapWidth / 2; ++x)
		{
			setPosition(x, y);
			std::cout << " ";
		}
	}
}