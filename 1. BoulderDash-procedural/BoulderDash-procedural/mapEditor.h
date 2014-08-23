
extern void editionMenu();
extern void menu();
extern bool loadMap(char** &_loadedMap);
extern void saveMap(char** _newMap);
extern void clearMapScreen();
extern void clearQuaterMapScreen();
extern void editBar();
extern bool getFileName(char fileName[20]);
extern void editMainLoop(char** _newMap);

char** newMap()
{
	char w = wallChar;
	char h = hashChar;
	char p = playerChar;

	char editMap[newMapHeight][newMapWidth] = {
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

	char** _newMap = new char*[newMapHeight];

	for(int y = 0; y < newMapHeight; ++y)
	{
		_newMap[y] = new char[newMapWidth];

		for(int x = 0; x < newMapWidth; ++x)
		{
			_newMap[y][x] = editMap[y][x];
		}
	}

	return _newMap;
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

void drawNewMap(char** _newMap)
{
	for(int y = 0; y < newMapHeight; ++y)
	{
		for(int x = 0; x < newMapWidth; ++x)
		{
			setPosition(x + 1, y + 1);
			std::cout << _newMap[y][x];
		}
	}

	editBar();
}

void editInitMapPlayer()
{
	editPlayer.position.x = 1;
	editPlayer.position.y = 1;
}

void editMarkPlayer(char** _newMap)
{
	char tmp = _newMap[(int)editPlayer.position.y][(int)editPlayer.position.x];

	SetConsoleTextAttribute(output, backgroundColorWHITE | foregroundColorGOLD);
	setPosition((int)editPlayer.position.x + 1, (int)editPlayer.position.y + 1);
	std::cout << tmp;
}

void editUnmarkPlayer(char** _newMap)
{
	SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
	setPosition((int)editPlayer.position.x + 1, (int)editPlayer.position.y + 1);
	std::cout << _newMap[(int)editPlayer.position.y][(int)editPlayer.position.x];
}

void editionConditionMap()
{
	if(((int)editPlayer.position.y + 1) == newMapHeight)
	{
		editPlayer.position.y = editPlayer.position.y - 1;
	}

	if(((int)editPlayer.position.y) < 1)
	{
		editPlayer.position.y = editPlayer.position.y + 1;
	}

	if(((int)editPlayer.position.x + 1) == newMapWidth)
	{
		editPlayer.position.x = editPlayer.position.x - 1;
	}

	if(((int)editPlayer.position.x) < 1)
	{
		editPlayer.position.x = editPlayer.position.x + 1;
	}
}

void editMainLoop(char** _newMap)
{
	editInitMapPlayer();
	editMarkPlayer(_newMap);

	char key;

	while(true)
	{
		if(_kbhit())
		{
			editUnmarkPlayer(_newMap);
			
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
					_newMap[(int)editPlayer.position.y][(int)editPlayer.position.x] = wallChar;
					break;

				case 'x':
					_newMap[(int)editPlayer.position.y][(int)editPlayer.position.x] = hashChar;
					break;

				case 'c':
					_newMap[(int)editPlayer.position.y][(int)editPlayer.position.x] = diamondChar;
					break;

				case 'v':
					_newMap[(int)editPlayer.position.y][(int)editPlayer.position.x] = stoneChar;
					break;

				case 'm':
					_newMap[(int)editPlayer.position.y][(int)editPlayer.position.x] = monsterChar;
					break;

				case 0x20: // space
					_newMap[(int)editPlayer.position.y][(int)editPlayer.position.x] = ' ';
					break;

				case 59: // F1
					clearMapScreen();
					_newMap = newMap();
					drawNewMap(_newMap);
					editInitMapPlayer();
					break;

				case 60: // F2
					clearMapScreen();
					saveMap(_newMap);
					drawNewMap(_newMap);
					editInitMapPlayer();
					break;

				case 27:
					return;
			}
			editionConditionMap();
			editMarkPlayer(_newMap);
		}
	}
}

void newMapLoop()
{
	char** _newMap = newMap();

	drawNewMap(_newMap);

	editMainLoop(_newMap);
}

void createMap2D(char** &_loadedMap)
{
	_loadedMap = new char*[newMapHeight];;

	for(int y = 0; y < newMapHeight; ++y)
	{
		_loadedMap[y] = new char[newMapWidth];
	}
}


void editMap()
{
	clearQuaterMapScreen();
	char** _loadedMap;

	createMap2D(_loadedMap);
	if((loadMap(_loadedMap)) == false)
	{
		clearQuaterMapScreen();
		return;
	}

	clearQuaterMapScreen();
	drawNewMap(_loadedMap);

	editMainLoop(_loadedMap);
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
	for(int y = 1; y < newMapHeight + 5; ++y)
	{
		for(int x = 1; x < newMapWidth + 1; ++x)
		{
			setPosition(x, y);
			std::cout << " ";
		}
	}
}

void clearQuaterMapScreen()
{
	for(int y = 1; y < newMapHeight / 2; ++y)
	{
		for(int x = 1; x < newMapWidth / 2; ++x)
		{
			setPosition(x, y);
			std::cout << " ";
		}
	}
}