
extern void clearMapScreen();

void initPlayer()
{
	player.position.x = 2;
	player.position.y = 2;
}

void markPlayer(char** &_loadedMap)
{
	_loadedMap[(int)player.position.y][(int)player.position.x] = playerChar;

	SetConsoleTextAttribute(output, backgroundColorWHITE | foregroundColorGOLD);
	setPosition((int)player.position.x + 1, (int)player.position.y + 1);
	std::cout << _loadedMap[(int)player.position.y][(int)player.position.x];
}

void unmarkPlayer(char** &_loadedMap)
{
	_loadedMap[(int)player.position.y][(int)player.position.x] = spaceChar;

	SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
	setPosition((int)player.position.x + 1, (int)player.position.y + 1);
	std::cout << _loadedMap[(int)player.position.y][(int)player.position.x];
}

void playerCheckCondition()
{
	if(player.position.x <= 1)
	{
		player.position.x = 1;
	}

	if(player.position.y <= 1)
	{
		player.position.y = 1;
	}

	if(player.position.y >= newMapHeight - 2)
	{
		player.position.y = newMapHeight - 2;
	}

	if(player.position.x >= newMapWidth -2)
	{
		player.position.x = newMapWidth - 2;
	}
}

bool playerMove(char** &_loadedMap)
{
	char key;

	if(_kbhit())
	{
		unmarkPlayer(_loadedMap);

		key = _getch();

		switch(key)
		{
			case 72:
				player.position.x += 0;
				player.position.y += -1;
				break;

			case 80:
				player.position.x += 0;
				player.position.y += 1;
				break;

			case 75:
				player.position.x += -1;
				player.position.y += 0;
				break;

			case 77:
				player.position.x += 1;
				player.position.y += 0;
				break;

			case 27:
				system("cls");
				return false;
				break;
		}

		playerCheckCondition();
		markPlayer(_loadedMap);
	}

	return true;
}