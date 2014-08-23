
extern void clearMapScreen();

void initPlayer()
{
	player.position.x = 2;
	player.position.y = 2;
}

void markPlayer()
{
	map[(int)player.position.y][(int)player.position.x] = playerChar;

	SetConsoleTextAttribute(output, backgroundColorWHITE | foregroundColorGOLD);
	setPosition((int)player.position.x + 1, (int)player.position.y + 1);
	std::cout << map[(int)player.position.y][(int)player.position.x];
}

void unmarkPlayer()
{
	map[(int)player.position.y][(int)player.position.x] = spaceChar;

	SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
	setPosition((int)player.position.x + 1, (int)player.position.y + 1);
	std::cout << map[(int)player.position.y][(int)player.position.x];
}

void playerCheckCondition()
{
	if(player.position.x <= 1){
		player.position.x = 1;
	}
	else if(player.position.y <= 1){
		player.position.y = 1;
	}
	else if(player.position.y >= mapHeight - 2){
		player.position.y = mapHeight - 2;
	}
	else if(player.position.x >= mapWidth -2){
		player.position.x = mapWidth - 2;
	}
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

		playerCheckCondition();
		markPlayer();
	}

	return true;
}