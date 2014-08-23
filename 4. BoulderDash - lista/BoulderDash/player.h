
extern void clearMapScreen();

void initPlayer()
{
	player.position.x = 1;
	player.position.y = 1;
}

void markPlayer()
{
	setWhiteConsoleTextAttribute((int)player.position.x + 1, (int)player.position.y + 1);

	map[(int)player.position.y][(int)player.position.x] = playerChar;
	std::cout << map[(int)player.position.y][(int)player.position.x];
}

void unmarkPlayer()
{
	setBlackConsoleTextAttribute((int)player.position.x + 1, (int)player.position.y + 1);

	map[(int)player.position.y][(int)player.position.x] = spaceChar;
	std::cout << map[(int)player.position.y][(int)player.position.x];
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

	if(player.position.y >= mapHeight - 2)
	{
		player.position.y = mapHeight - 2;
	}

	if(player.position.x >= mapWidth -2)
	{
		player.position.x = mapWidth - 2;
	}
}

void objectCondition(char key)
{
	if((map[(int)player.position.y][(int)player.position.x]) == stoneChar)
	{
		switch(key)
		{
			case 72:
				player.position.x -= 0;
				player.position.y -= -1;
				break;

			case 80:
				player.position.x -= 0;
				player.position.y -= 1;
				break;

			case 75:
				player.position.x -= -1;
				player.position.y -= 0;
				break;

			case 77:
				player.position.x -= 1;
				player.position.y -= 0;
				break;
		}
	}
}

void addPoints()
{
	setBlackConsoleTextAttribute(14, 21);
	std::cout << diamondPoints;

	setBlackConsoleTextAttribute(14, 22);
	std::cout << moves;

	setBlackConsoleTextAttribute(14, 23);
	std::cout << points;

	setBlackConsoleTextAttribute(24, 21);
	std::cout << map[(int)player.position.y][(int)player.position.x];

	setBlackConsoleTextAttribute(24, 22);
	std::cout << "y" << " " << "x";

	setBlackConsoleTextAttribute(24, 23);
	std::cout << (int)player.position.y << " " << (int)player.position.x;

}

bool playerMove()
{
	char key;

	if(_kbhit())
	{
		unmarkPlayer();

		key = _getch();

		switch(key)
		{
			case 72:
				player.position.x += 0;
				player.position.y += -1;
				++moves;
				break;

			case 80:
				player.position.x += 0;
				player.position.y += 1;
				++moves;
				break;

			case 75:
				player.position.x += -1;
				player.position.y += 0;
				++moves;
				break;

			case 77:
				player.position.x += 1;
				player.position.y += 0;
				++moves;
				break;

			case 27:
				system("cls");
				return false;
				break;
		}

		addPoints();
		objectCondition(key);
		
		playerCheckCondition();
		markPlayer();
	}

	return true;
}